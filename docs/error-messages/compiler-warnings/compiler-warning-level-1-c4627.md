---
title: Compilador aviso (nível 1) C4627
ms.date: 09/09/2018
f1_keywords:
- C4627
helpviewer_keywords:
- C4627
ms.assetid: 8840f3e6-b496-423a-8635-eb55d5f854a2
ms.openlocfilehash: e833141020de1aef51a1ea3823dea86b024e077d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50542383"
---
# <a name="compiler-warning-level-1-c4627"></a>Compilador aviso (nível 1) C4627

> '*header_file*': ignorado ao procurar o uso de cabeçalho pré-compilado

Se o arquivo de origem atual tem o [/Yu \(arquivo de cabeçalho pré-compilado do uso)](../../build/reference/yu-use-precompiled-header-file.md) opção conjunto, em seguida, o compilador ignora tudo no arquivo antes que o cabeçalho pré-compilado está incluído. Aviso **C4627** é gerado no Visual Studio 2015 e versões anteriores se *header_file* está incluído para que o arquivo de cabeçalho pré-compilado, e se o cabeçalho pré-compilado também não incluem *header_file*.

## <a name="example"></a>Exemplo

Este exemplo demonstra como o erro pode ocorrer e mostra como corrigi-lo:

```cpp
// c4627.cpp
#include <iostream>       // C4627 - iostream not included by pch.h
#include "pch.h"          // precompiled header file that does not include iostream
// #include <iostream>    // To fix, move the iostream header include here from above
int main()
{
    std::cout << "std::cout is defined!\n";
}
```

## <a name="see-also"></a>Consulte também

[Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)
