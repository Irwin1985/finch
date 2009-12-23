#pragma once

#include "Macros.h"
#include "Ref.h"
#include "Token.h"
#include "ITokenSource.h"

namespace Finch
{
    class ILineReader;
    
    // The Finch lexer. Reads a series of lines from an ILineReader and splits
    // them into Tokens.
    class Lexer : public ITokenSource
    {
    public:
        Lexer(ILineReader * reader)
        :   mReader(reader),
            mState(LEX_NEED_LINE),
            mIndex(0),
            mTokenStart(0)
        {}
        
        // Lexes and returns the next full Token read from the source. If the
        // ILineReader is out of lines, this will return an EOF Token.
        virtual Ref<Token> ReadToken();
        
    private:
        enum State
        {
            LEX_NEED_LINE,
            LEX_DEFAULT,
            LEX_IN_MINUS,
            LEX_IN_NUMBER,
            LEX_IN_NAME,
            LEX_IN_OPERATOR,
            LEX_IN_STRING,
            LEX_IN_COMMENT,
            LEX_AT_END_OF_LINE,
            LEX_DONE
        };
        
        void StartLine();
        
        Ref<Token> SingleToken(TokenType type);
        void       StartToken(State state, bool skipFirstChar = false);
        Ref<Token> TextToken(bool condition, bool isKeyword, TokenType type);
        
        Ref<Token> EmitNumber(TokenType type);
        Ref<Token> EmitText(TokenType type);

        bool IsAlpha(char c) const;
        bool IsDigit(char c) const;
        bool IsOperator(char c) const;
        bool IsSpace(char c) const;
        bool IsNull(char c) const;
        
        ILineReader * mReader;
        State         mState;
        
        String        mLine;
        int           mIndex;
        int           mTokenStart;
        
        NO_COPY(Lexer)
    };
}