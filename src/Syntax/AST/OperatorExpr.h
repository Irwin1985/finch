#pragma once

#include <iostream>
#include <memory>

#include "Macros.h"
#include "Expr.h"
#include "IExprVisitor.h"
#include "Ref.h"
#include "String.h"

namespace Finch
{
    using std::ostream;
    
    // AST node for a binary message send: "obj + arg"
    class OperatorExpr : public Expr
    {
    public:
        OperatorExpr(Ref<Expr> receiver, String op, Ref<Expr> arg)
        :   mReceiver(receiver),
            mOperator(op),
            mArg(arg)
        {}
        
        Ref<Expr> Receiver() const { return mReceiver; }
        String    Operator() const { return mOperator; }
        Ref<Expr> Argument() const { return mArg; }
        
        virtual void Trace(ostream & stream) const
        {
            stream << mReceiver << " " << mOperator << " " << mArg;
        }
            
        EXPRESSION_VISITOR

    private:
        // the object receiving the message
        Ref<Expr> mReceiver;
        
        // the name of the operator
        String mOperator;
        
        // the argument being passed
        Ref<Expr> mArg;
    };
}