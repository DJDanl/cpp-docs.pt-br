---
title: Erro do compilador C2059
ms.date: 03/26/2019
f1_keywords:
- C2059
helpviewer_keywords:
- C2059
ms.assetid: 2be4eb39-3f37-4b32-8e8d-75835e07c78a
ms.openlocfilehash: 1d51d4c7873d43a655dc11fa8e0fa297b8a69bff
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74735938"
---
# <a name="compiler-error-c2059"></a>Erro do compilador C2059

erro de sintaxe: ' token '

O token causou um erro de sintaxe.

O exemplo a seguir gera uma mensagem de erro para a linha que declara `j`.

```cpp
// C2059e.cpp
// compile with: /c
// C2143 expected
// Error caused by the incorrect use of '*'.
   int j*; // C2059
```

Para determinar a causa do erro, examine não apenas a linha listada na mensagem de erro, mas também as linhas acima dela. Se examinar as linhas não produzir nenhuma pista sobre o problema, tente comentar a linha listada na mensagem de erro e, talvez, várias linhas acima dela.

Se a mensagem de erro ocorrer em um símbolo que segue imediatamente uma variável `typedef`, verifique se a variável está definida no código-fonte.

C2059 é gerado quando um nome de símbolo de pré-processador é usado novamente como um identificador. No exemplo a seguir, o compilador vê `DIGITS.ONE` como o número 1, que não é válido como um nome de elemento de enumeração:

```cpp
#define ONE 1

enum class DIGITS {
    ZERO,
    ONE // error C2059
};
```

Você poderá obter C2059 se um símbolo for avaliado como Nothing, como pode ocorrer quando o símbolo **/d** **=** for usado para compilar.

```cpp
// C2059a.cpp
// compile with: /DTEST=
#include <stdio.h>

int main() {
   #ifdef TEST
      printf_s("\nTEST defined %d", TEST);   // C2059
   #else
      printf_s("\nTEST not defined");
   #endif
}
```

Outro caso em que o C2059 pode ocorrer é quando você compila um aplicativo que especifica uma estrutura nos argumentos padrão para uma função. O valor padrão para um argumento deve ser uma expressão. Uma lista de inicializadores — por exemplo, uma que costumava inicializar uma estrutura — não é uma expressão.  Para resolver esse problema, defina um construtor para executar a inicialização necessária.

O exemplo a seguir gera C2059:

```cpp
// C2059b.cpp
// compile with: /c
struct ag_type {
   int a;
   float b;
   // Uncomment the following line to resolve.
   // ag_type(int aa, float bb) : a(aa), b(bb) {}
};

void func(ag_type arg = {5, 7.0});   // C2059
void func(ag_type arg = ag_type(5, 7.0));   // OK
```

C2059 pode ocorrer para uma conversão mal formada.

O exemplo a seguir gera C2059:

```cpp
// C2059c.cpp
// compile with: /clr
using namespace System;
ref class From {};
ref class To : public From {};

int main() {
   From^ refbase = gcnew To();
   To^ refTo = safe_cast<To^>(From^);   // C2059
   To^ refTo2 = safe_cast<To^>(refbase);   // OK
}
```

C2059 também pode ocorrer se você tentar criar um nome de namespace que contenha um ponto.

O exemplo a seguir gera C2059:

```cpp
// C2059d.cpp
// compile with: /c
namespace A.B {}   // C2059

// OK
namespace A  {
   namespace B {}
}
```

C2059 pode ocorrer quando um operador que pode qualificar um nome (`::`, `->`e `.`) deve ser seguido pela palavra-chave `template`, conforme mostrado neste exemplo:

```cpp
template <typename T> struct Allocator {
    template <typename U> struct Rebind {
        typedef Allocator<U> Other;
    };
};

template <typename X, typename AY> struct Container {
    typedef typename AY::Rebind<X>::Other AX; // error C2059
};
```

Por padrão, C++ pressupõe que `AY::Rebind` não é um modelo; Portanto, a `<` a seguir é interpretada como um sinal de menor que.  Você deve dizer explicitamente ao compilador que `Rebind` é um modelo para que ele possa analisar corretamente o colchete angular. Para corrigir esse erro, use a palavra-chave `template` no nome do tipo dependente, como mostrado aqui:

```cpp
template <typename T> struct Allocator {
    template <typename U> struct Rebind {
        typedef Allocator<U> Other;
    };
};

template <typename X, typename AY> struct Container {
    typedef typename AY::template Rebind<X>::Other AX; // correct
};
```
