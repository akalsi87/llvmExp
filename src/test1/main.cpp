/**
 * \file main.cpp
 * \date Jul 14, 2016
 */

#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS

#include "llvm/AsmParser/Parser.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

#include <iostream>

llvm::SMDiagnostic SM_DIAG;
llvm::LLVMContext CTXT;

int main(int argc, char** argv)
{
    std::string s;
    llvm::raw_string_ostream strm(s);

    auto mod = llvm::parseAssemblyFile(argv[1], SM_DIAG, CTXT);

    if (!mod)
    {
        SM_DIAG.print(argv[0], llvm::errs());
        std::cerr << strm.str() << std::endl;
        return 1;
    }

    if (llvm::verifyModule(*mod))
    {
        llvm::verifyModule(*mod, &strm);
        std::cerr << strm.str() << std::endl;
        return 1;
    }

    mod->print(strm, nullptr);
    std::cout << strm.str() << std::endl;

    return 0;
}
