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
ms.openlocfilehash: ea136ac0312b78519fe2d8ea88ace4d8b0d69946
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178412"
---
# <a name="__if_exists-statement"></a>Instrução __if_exists

A instrução **__if_exists** testa se o identificador especificado existe. Se o identificador especificado existir, o bloco de instrução especificado é executado.

## <a name="syntax"></a>Sintaxe

```
__if_exists ( identifier ) {
statements
};
```

#### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*identifier*|O identificador cuja existência você deseja testar.|
|*instruções*|Uma ou mais instruções para executar se o *identificador* existir.|

## <a name="remarks"></a>Comentários

> [!CAUTION]
>  Para obter os resultados mais confiáveis, use a instrução **__if_exists** sob as restrições a seguir.

- Aplique a instrução **__if_exists** apenas a tipos simples, não a modelos.

- Aplique a instrução **__if_exists** aos identificadores dentro ou fora de uma classe. Não aplique a instrução **__if_exists** a variáveis locais.

- Use a instrução **__if_exists** apenas no corpo de uma função. Fora do corpo de uma função, a instrução **__if_exists** pode testar apenas tipos totalmente definidos.

- Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.

O complemento para a instrução **__if_exists** é a instrução [__if_not_exists](../cpp/if-not-exists-statement.md) .

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

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução __if_not_exists](../cpp/if-not-exists-statement.md)
