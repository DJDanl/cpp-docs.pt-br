---
title: Aviso do compilador (nível 3) C4839
ms.date: 09/13/2018
f1_keywords:
- C4839
helpviewer_keywords:
- C4839
ms.assetid: f4f99066-9258-4330-81a8-f4a75a1d95ee
ms.openlocfilehash: 2c238dc16359583bf55f7590d2ce7c0363d66df7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198569"
---
# <a name="compiler-warning-level-3-c4839"></a>Aviso do compilador (nível 3) C4839

> uso não padrão da classe '*Type*' como um argumento para uma função Variadic

Classes ou estruturas que são passadas para uma função Variadic como `printf` devem ser trivialmente copiáveis. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

Esse aviso está disponível a partir do Visual Studio 2017.

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

Para cadeias de caracteres criadas e gerenciadas usando `CStringW`, o `operator LPCWSTR()` fornecido deve ser usado para converter um objeto `CStringW` para o ponteiro C esperado pela cadeia de caracteres de formato.

```cpp
    CStringW str1;
    CStringW str2;
    // ...
    str1.Format("%s", static_cast<LPCWSTR>(str2));
```
