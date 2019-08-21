---
title: Aviso do compilador C4984
ms.date: 08/19/2019
f1_keywords:
- C4984
helpviewer_keywords:
- C4984
ms.openlocfilehash: 91ae30018c7de633d8ba23d538b301ad4bbac984
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69632900"
---
# <a name="compiler-warning-c4984"></a>Aviso do compilador C4984

> ' If constexpr ' é uma extensão de linguagem C++ 17

## <a name="remarks"></a>Comentários

O compilador encontrou uma `if constexpr` expressão no código compilado usando o padrão c++ 14 padrão. Essa expressão é especificada a partir do padrão C++ 17. Se você precisar de compatibilidade com C++ 11 ou C++ 14, essa expressão não será portátil.

O C4984 é emitido como um erro por padrão, mas é suppressible. Para habilitar essa expressão compilando seu código como C++ 17, use [/std: c++ 17 ou/std: C + + Latest](../../build/reference/std-specify-language-standard-version.md). Para usar a `if constexpr` expressão no código compilado para c++ 14 como uma extensão da Microsoft, você pode suprimir, desabilitar ou alterar o nível de aviso da mensagem de erro. Você pode usar [/wd4984](../../build/reference/compiler-option-warning-level.md) para desabilitar o C4984 ou __/w__*N*__4984__ para habilitá-lo como um aviso de nível *N* em vez de um erro. Ou use [#pragma Aviso (suprimir: 4984)](../../preprocessor/warning.md) antes da linha que causa o aviso no arquivo de origem.

Esse aviso está disponível a partir do Visual Studio 2017 versão 15,3. Para obter informações sobre como desabilitar avisos introduzidos em uma versão específica do compilador ou posterior, consulte [avisos do compilador por versão do compilador](compiler-warnings-by-compiler-version.md).

## <a name="example"></a>Exemplo

Este exemplo gera C4984 e mostra maneiras de corrigi-lo:

```cpp
// C4984.cpp
// compile with: cl /EHsc C4984.cpp
#include <iostream>

int main()
{
    constexpr bool compile_time = true;
    // Uncomment the following line or use /std:c++17 to fix
    // #pragma warning(suppress:4984)
    if constexpr (compile_time)
    {
        std::cout << "compile_time is true";
    }
    else
    {
        std::cout << "compile_time is false";
    }
}
```
