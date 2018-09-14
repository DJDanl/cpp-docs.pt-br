---
title: Compilador aviso (nível 3) C4839 | Microsoft Docs
ms.date: 09/13/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4839
dev_langs:
- C++
helpviewer_keywords:
- C4839
ms.assetid: f4f99066-9258-4330-81a8-f4a75a1d95ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 14a79c6abb118fb173382be87ebda4316545c65a
ms.sourcegitcommit: 87d317ac62620c606464d860aaa9e375a91f4c99
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2018
ms.locfileid: "45601399"
---
# <a name="compiler-warning-level-3-c4839"></a>Compilador aviso (nível 3) C4839

> uso não padrão da classe*tipo*' como um argumento para uma função variadic

Classes ou estruturas que são passadas para uma função variadic como `printf` devem ser facilmente copiados. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

Esse aviso é disponível partir do Visual Studio 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4839:

```cpp
// C4839.cpp
// compile by using: cl /EHsc /W3 C4839.cpp
#include <atomic>
#include <memory>
#include <stdio.h>

int main()
{
    std::atomic<int> i(0);
    printf("%i\n", i); // error C4839: non-standard use of class 'std::atomic<int>'
                        // as an argument to a variadic function
                        // note: the constructor and destructor will not be called;
                        // a bitwise copy of the class will be passed as the argument
                        // error C2280: 'std::atomic<int>::atomic(const std::atomic<int> &)':
                        // attempting to reference a deleted function
}
```

Para corrigir o erro, é possível chamar uma função membro que retorna um tipo facilmente copiado,

```cpp
    std::atomic<int> i(0);
    printf("%i\n", i.load());
```

Para cadeias de caracteres criadas e gerenciadas usando `CStringW`, fornecido `operator LPCWSTR()` deve ser usado para converter um `CStringW` objeto para o ponteiro do C esperado pela cadeia de caracteres de formato.

```cpp
    CStringW str1;
    CStringW str2;
    // ...
    str1.Format("%s", static_cast<LPCWSTR>(str2));
```