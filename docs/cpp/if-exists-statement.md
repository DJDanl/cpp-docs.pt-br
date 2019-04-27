---
title: Instrução __if_exists
ms.date: 11/04/2016
f1_keywords:
- __if_exists_cpp
helpviewer_keywords:
- identifiers, testing for existence
- symbols, testing for existence
- __if_exists keyword [C++]
ms.assetid: d3eb34b6-f3a9-4063-a286-b62a28c0c7fa
ms.openlocfilehash: 9d5a0b24bb08a9485b2d212058fa8f0bd82e5842
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62183668"
---
# <a name="ifexists-statement"></a>Instrução __if_exists

O **if_exists** instrução testa se o identificador especificado existe. Se o identificador especificado existir, o bloco de instrução especificado é executado.

## <a name="syntax"></a>Sintaxe

```
__if_exists ( identifier ) {
statements
};
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*identifier*|O identificador cuja existência você deseja testar.|
|*statements*|Um ou mais instruções a executar se *identificador* existe.|

## <a name="remarks"></a>Comentários

> [!CAUTION]
>  Para obter os resultados mais confiáveis, use o **if_exists** instrução sob as restrições a seguir.

- Aplicar a **if_exists** instrução apenas em tipos simples, e não por modelos.

- Aplicar a **if_exists** instrução para identificadores dentro ou fora de uma classe. Não se aplicam a **if_exists** instrução para variáveis locais.

- Use o **if_exists** instrução somente no corpo de uma função. Fora do corpo de uma função, o **if_exists** instrução pode testar apenas tipos totalmente definidos.

- Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.

O complemento para o **if_exists** instrução é a [if_not_exists](../cpp/if-not-exists-statement.md) instrução.

## <a name="example"></a>Exemplo

Observe que este exemplo usa modelos, o que não é recomendável.

```cpp
// the__if_exists_statement.cpp
// compile with: /EHsc
#include <iostream>

template<typename T>
class X : public T {
public:
   void Dump() {
      std::cout << "In X<T>::Dump()" << std::endl;

      __if_exists(T::Dump) {
         T::Dump();
      }

      __if_not_exists(T::Dump) {
         std::cout << "T::Dump does not exist" << std::endl;
      }
   }
};

class A {
public:
   void Dump() {
      std::cout << "In A::Dump()" << std::endl;
   }
};

class B {};

bool g_bFlag = true;

class C {
public:
   void f(int);
   void f(double);
};

int main() {
   X<A> x1;
   X<B> x2;

   x1.Dump();
   x2.Dump();

   __if_exists(::g_bFlag) {
      std::cout << "g_bFlag = " << g_bFlag << std::endl;
   }

   __if_exists(C::f) {
      std::cout << "C::f exists" << std::endl;
   }

   return 0;
}
```

## <a name="output"></a>Saída

```Output
In X<T>::Dump()
In A::Dump()
In X<T>::Dump()
T::Dump does not exist
g_bFlag = 1
C::f exists
```

## <a name="see-also"></a>Consulte também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução __if_not_exists](../cpp/if-not-exists-statement.md)