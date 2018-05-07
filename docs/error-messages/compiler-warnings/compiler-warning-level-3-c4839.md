---
title: Compilador aviso (nível 3) C4839 | Microsoft Docs
ms.date: 10/25/2017
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
ms.openlocfilehash: b72289eef03c56356865b0b62a999c417da570a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4839"></a>Compilador C4839 de aviso (nível 4)

> uso não padrão da classe*tipo*' como um argumento para uma função variadic

No Visual Studio de 2017, classes ou estruturas que são passadas para um variadic função como `printf` deve ser copiado facilmente. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4839:

```cpp
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

    struct S {
        S(int i) : i(i) {}
        S(const S& other) : i(other.i) {}
        operator int() { return i; }
    private:
        int i;
    } s(0);
    printf("%i\n", s); // warning C4840 : non-portable use of class 'main::S'
                      // as an argument to a variadic function
}
```

Para corrigir o erro, é possível chamar uma função membro que retorna um tipo facilmente copiado,

```cpp
    std::atomic<int> i(0);
    printf("%i\n", i.load());
```

ou realiza uma conversão estática para converter o objeto antes de passá-lo:

```cpp
    struct S {/* as before */} s(0);
    printf("%i\n", static_cast<int>(s))
```

Cadeias de caracteres criadas e gerenciadas usando `CStringW`, fornecido `operator LPCWSTR()` deve ser usada para converter um `CStringW` objeto para o ponteiro de C esperado pela cadeia de caracteres de formato.

```cpp
    CStringW str1;
    CStringW str2;
    // ...
    str1.Format("%s", static_cast<LPCWSTR>(str2));
```