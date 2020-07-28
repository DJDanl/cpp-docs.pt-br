---
title: Erro do compilador C2143
ms.date: 11/04/2016
f1_keywords:
- C2143
helpviewer_keywords:
- C2143
ms.assetid: 1d8d1456-e031-4965-9240-09a6e33ba81c
ms.openlocfilehash: 310083a650f842c6c0f0912efe1ceddb66c4fd6f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214744"
---
# <a name="compiler-error-c2143"></a>Erro do compilador C2143

erro de sintaxe: ' token1 ' ausente antes de ' token2 '

O compilador esperava um token específico (ou seja, um elemento de linguagem diferente de espaço em branco) e encontrou outro token em vez disso.

Verifique a [referência da linguagem C++](../../cpp/cpp-language-reference.md) para determinar onde o código está sintaticamente incorreto. Como o compilador pode relatar esse erro depois de encontrar a linha que causa o problema, verifique várias linhas de código que precedem o erro.

O C2143 pode ocorrer em situações diferentes.

Isso pode ocorrer quando um operador que pode qualificar um nome ( `::` , `->` e `.` ) deve ser seguido pela palavra-chave **`template`** , como neste exemplo:

```cpp
class MyClass
{
    template<class Ty, typename PropTy>
    struct PutFuncType : public Ty::PutFuncType<Ty, PropTy> // error C2143
    {
    };
};
```

Por padrão, o C++ pressupõe que `Ty::PutFuncType` não seja um modelo; portanto, o seguinte `<` é interpretado como um sinal de menor que.  Você deve dizer explicitamente ao compilador que `PutFuncType` é um modelo para que ele possa analisar corretamente o colchete angular. Para corrigir esse erro, use a **`template`** palavra-chave no nome do tipo dependente, como mostrado aqui:

```cpp
class MyClass
{
    template<class Ty, typename PropTy>
    struct PutFuncType : public Ty::template PutFuncType<Ty, PropTy> // correct
    {
    };
};
```

C2143 pode ocorrer quando **/CLR** é usado e uma **`using`** diretiva tem um erro de sintaxe:

```cpp
// C2143a.cpp
// compile with: /clr /c
using namespace System.Reflection;   // C2143
using namespace System::Reflection;
```

Ele também pode ocorrer quando você está tentando compilar um arquivo de código-fonte usando a sintaxe CLR sem usar também o **/CLR**:

```cpp
// C2143b.cpp
ref struct A {   // C2143 error compile with /clr
   void Test() {}
};

int main() {
   A a;
   a.Test();
}
```

O primeiro caractere que não seja espaço em branco que segue uma **`if`** instrução deve ser um parêntese esquerdo. O compilador não pode converter nada mais:

```cpp
// C2143c.cpp
int main() {
   int j = 0;

   // OK
   if (j < 25)
      ;

   if (j < 25)   // C2143
}
```

C2143 pode ocorrer quando uma chave de fechamento, um parêntese ou um ponto e vírgula está ausente na linha em que o erro é detectado ou em uma das linhas acima:

```cpp
// C2143d.cpp
// compile with: /c
class X {
   int member1;
   int member2   // C2143
} x;
```

Ou quando há uma marca inválida em uma declaração de classe:

```cpp
// C2143e.cpp
class X {
   int member;
} x;

class + {};   // C2143 + is an invalid tag name
class ValidName {};   // OK
```

Ou quando um rótulo não está anexado a uma instrução. Se você precisar inserir um rótulo por si só, por exemplo, no final de uma instrução composta, anexe-a a uma instrução NULL:

```cpp
// C2143f.cpp
// compile with: /c
void func1() {
   // OK
   end1:
      ;

   end2:   // C2143
}
```

O erro pode ocorrer quando uma chamada não qualificada é feita a um tipo na biblioteca C++ Standard:

```cpp
// C2143g.cpp
// compile with: /EHsc /c
#include <vector>
static vector<char> bad;   // C2143
static std::vector<char> good;   // OK
```

Ou há uma **`typename`** palavra-chave ausente:

```cpp
// C2143h.cpp
template <typename T>
struct X {
   struct Y {
      int i;
   };
   Y memFunc();
};
template <typename T>
X<T>::Y X<T>::memFunc() {   // C2143
// try the following line instead
// typename X<T>::Y X<T>::memFunc() {
   return Y();
}
```

Ou se você tentar definir uma instanciação explícita:

```cpp
// C2143i.cpp
// compile with: /EHsc /c
// template definition
template <class T>
void PrintType(T i, T j) {}

template void PrintType(float i, float j){}   // C2143
template void PrintType(float i, float j);   // OK
```

Em um programa C, as variáveis devem ser declaradas no início da função e não podem ser declaradas depois que a função executa instruções de não declaração.

```C
// C2143j.c
int main()
{
    int i = 0;
    i++;
    int j = 0; // C2143
}
```
