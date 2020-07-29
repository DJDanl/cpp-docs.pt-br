---
title: Exceção bad_cast
ms.date: 10/04/2019
f1_keywords:
- bad_cast
- bad_cast_cpp
helpviewer_keywords:
- exceptions [C++], bad_cast
- bad_cast keyword [C++]
ms.assetid: 31eae1e7-d8d5-40a0-9fef-64a6a4fc9021
ms.openlocfilehash: 2efe5be5e44751831a56b29cfc629df2d21843f7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229175"
---
# <a name="bad_cast-exception"></a>Exceção bad_cast

A exceção **bad_cast** é gerada pelo **`dynamic_cast`** operador como o resultado de uma conversão com falha para um tipo de referência.

## <a name="syntax"></a>Sintaxe

```
catch (bad_cast)
   statement
```

## <a name="remarks"></a>Comentários

A interface para **bad_cast** é:

```cpp
class bad_cast : public exception
```

O código a seguir contém um exemplo de um falha **`dynamic_cast`** que gera a exceção **bad_cast** .

```cpp
// expre_bad_cast_Exception.cpp
// compile with: /EHsc /GR
#include <typeinfo>
#include <iostream>

class Shape {
public:
   virtual void virtualfunc() const {}
};

class Circle: public Shape {
public:
   virtual void virtualfunc() const {}
};

using namespace std;
int main() {
   Shape shape_instance;
   Shape& ref_shape = shape_instance;
   try {
      Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
   }
   catch (bad_cast b) {
      cout << "Caught: " << b.what();
   }
}
```

A exceção é gerada porque o objeto que está sendo convertido (uma forma) não é derivado do tipo de conversão especificado (Circle). Para evitar a exceção, adicione estas declarações a `main`:

```cpp
Circle circle_instance;
Circle& ref_circle = circle_instance;
```

Em seguida, inverta a noção da conversão no **`try`** bloco da seguinte maneira:

```cpp
Shape& ref_shape = dynamic_cast<Shape&>(ref_circle);
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[bad_cast](#bad_cast)|O construtor para objetos do tipo `bad_cast`.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[acontece](#what)|TBD|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador =](#op_eq)|Um operador de atribuição que atribui um `bad_cast` objeto a outro.|

## <a name="bad_cast"></a><a name="bad_cast"></a>bad_cast

O construtor para objetos do tipo `bad_cast`.

```cpp
bad_cast(const char * _Message = "bad cast");
bad_cast(const bad_cast &);
```

## <a name="operator"></a><a name="op_eq"></a>operador =

Um operador de atribuição que atribui um `bad_cast` objeto a outro.

```cpp
bad_cast& operator=(const bad_cast&) noexcept;
```

## <a name="what"></a><a name="what"></a>acontece

```cpp
const char* what() const noexcept override;
```

## <a name="see-also"></a>Confira também

[Operador de dynamic_cast](../cpp/dynamic-cast-operator.md)\
[Palavras-chave](../cpp/keywords-cpp.md)\
[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)
