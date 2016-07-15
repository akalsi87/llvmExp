/**
 * \file main.cpp
 * \date Jul 14, 2016
 */

#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS

#include "llvm/AsmParser/Parser.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

llvm::SMDiagnostic SM_DIAG;
llvm::LLVMContext CTXT;

int main(int argc, char** argv)
{
    auto mod = llvm::parseAssemblyFile(argv[1], SM_DIAG, CTXT);
    mod->dump();
    return 0;
}
