#pragma once

#include <iostream>

#include "CodeBlock.h"
#include "Macros.h"
#include "Object.h"
#include "Ref.h"
#include "Scope.h"
#include "Stack.h"

namespace Finch
{
    /*
    class Environment;
    class Expr;
    class Interpreter;
    
    // A single bytecode execution thread in the interpreter. A Fiber has a
    // virtual callstack and is responsible for executing bytecode. In other
    // words, it's where stuff actually happens.
    class Fiber
    {
    public:
        Fiber(Interpreter & interpreter, Ref<Object> block);
        
        bool IsRunning() const { return mIsRunning && !IsDone(); }
        
        bool IsDone() const;

        Ref<Object> Execute();
        
        Interpreter & GetInterpreter() { return mInterpreter; }
        Environment & GetEnvironment() { return mEnvironment; }

        void Pause() { mIsRunning = false; }
        
        // Pushes the given value onto the operand stack.
        void Push(Ref<Object> object);
        void PushNil();
        void PushBool(bool value);
        void PushNumber(double value);
        void PushString(const String & value);
        
        void CallMethod(Ref<Object> self,
                        Ref<Object> blockObj,
                        const Array<Ref<Object> > & args);
        
        // Pushes the given block onto the call stack.
        void CallBlock(Ref<Object> blockObj,
                       const Array<Ref<Object> > & args);
        
        // Displays a runtime error to the user.
        void Error(const String & message);
        
        // Gets the current number of stack frames on the callstack. Used as a
        // diagnostic to ensure that tail call optimization is working.
        int GetCallstackDepth() const;
        
    private:
        // A single stack frame on the virtual callstack.
        struct CallFrame
        {
            // The instruction pointer. Stores the index of the current bytecode instruction in the
            // block of code for this frame.
            int address;
            
            // The local variable scope.
            Ref<Scope> scope;
            
            // The block of code being executed by this frame.
            Ref<Object> block;
            
            // The current receiver.
            Ref<Object> receiver;
            
            // The number of operands on the operand stack when this call frame
            // was started. If we do a non-local return out of this frame, we
            // use this to restore the stack to its proper size.
            int numOperands;
            
            CallFrame()
            :   address(0),
                scope(),
                block(),
                receiver(),
                numOperands()
            {}
            
            CallFrame(Ref<Scope> scope, Ref<Object> block, Ref<Object> receiver,
                      int numOperands)
            :   address(0),
                scope(scope),
                block(block),
                receiver(receiver),
                numOperands(numOperands)
            {}
            
            // Gets the code object for this frame.
            const BlockObject & Block() const { return *(block->AsBlock()); }
        };
        
        void        SendMessage(int message, int numArgs);
        Ref<Object> Self();
        Ref<Scope>  CurrentScope() { return mCallStack.Peek().scope; }
        
        void PushOperand(Ref<Object> object);
        Ref<Object> PopOperand();
        
        bool mIsRunning;
        
        Interpreter & mInterpreter;
        Environment & mEnvironment;
        Stack<Ref<Object> > mOperands; 
        Stack<CallFrame>    mCallStack;
        
        // Object literals that are currently being evaluated.
        Stack<Ref<Object> > mObjects;
        
        NO_COPY(Fiber);
    };
     */
}

