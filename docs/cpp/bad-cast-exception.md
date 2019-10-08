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
ms.openlocfilehash: 7384394fb53c6aa4bc009a903ba0ed22bf0ed0d6
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998778"
---
# <a name="bad_cast-exception"></a>Exceção bad_cast

A exceção **bad_cast** é gerada pelo operador **dynamic_cast** como o resultado de uma conversão com falha para um tipo de referência.

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

O código a seguir contém um exemplo de um **dynamic_cast** com falha que gera a exceção **bad_cast** .

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

Em seguida, inverta a noção da conversão no bloco **try** da seguinte maneira:

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
|[what](#what)|TBD|

### <a name="operators"></a>Operadores

|Operator|Descrição|
|-|-|
|[operator=](#op_eq)|Um operador de atribuição que atribui um objeto `bad_cast` a outro.|

## <a name="bad_cast"></a>bad_cast

O construtor para objetos do tipo `bad_cast`.

```cpp
bad_cast(const char * _Message = "bad cast");
bad_cast(const bad_cast &);
```

## <a name="op_eq"></a>operador =

Um operador de atribuição que atribui um objeto `bad_cast` a outro.

```cpp
bad_cast& operator=(const bad_cast&) noexcept;
```

## <a name="what"></a>acontece

```cpp
const char* what() const noexcept override;
```

## <a name="see-also"></a>Consulte também

[Operador dynamic_cast](../cpp/dynamic-cast-operator.md)\
[Palavras-chave](../cpp/keywords-cpp.md)\
[Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)
