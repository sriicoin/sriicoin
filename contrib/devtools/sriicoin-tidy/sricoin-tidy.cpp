// Copyright (c) 2023 Sriicoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "nontrivial-threadlocal.h"

#include <clang-tidy/ClangTidyModule.h>

class SriicoinModule final : public clang::tidy::ClangTidyModule
{
public:
    void addCheckFactories(clang::tidy::ClangTidyCheckFactories& CheckFactories) override
    {
        CheckFactories.registerCheck<sriicoin::NonTrivialThreadLocal>("sriicoin-nontrivial-threadlocal");
    }
};

static clang::tidy::ClangTidyModuleRegistry::Add<SriicoinModule>
    X("sriicoin-module", "Adds sriicoin checks.");

volatile int SriicoinModuleAnchorSource = 0;
