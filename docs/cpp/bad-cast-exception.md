---
title: Exceção bad_cast
ms.date: 11/04/2016
f1_keywords:
- bad_cast
- bad_cast_cpp
helpviewer_keywords:
- exceptions [C++], bad_cast
- bad_cast keyword [C++]
ms.assetid: 31eae1e7-d8d5-40a0-9fef-64a6a4fc9021
ms.openlocfilehash: b40f64671e7c259b7dc04b31a11d20d0fc76c5c4
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68242387"
---
# <a name="badcast-exception"></a>Exceção bad_cast

O **bad_cast** exceção é lançada pela **dynamic_cast** operador como o resultado de uma falha na conversão em um tipo de referência.

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

O código a seguir contém um exemplo de uma falha na **dynamic_cast** que gera a **bad_cast** exceção.

```cpp
// expre_bad_cast_Exception.cpp
// compile with: /EHsc /GR
#include <typeinfo.h>
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

A exceção é lançada porque o objeto que está sendo convertido (uma forma) não é derivado do tipo convertido especificado (círculo). Para evitar a exceção, adicione estas declarações a `main`:

```cpp
Circle circle_instance;
Circle& ref_circle = circle_instance;
```

Em seguida, inverta o sentido da conversão na **tente** bloquear da seguinte maneira:

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

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Um operador de atribuição que atribui um `bad_cast` objeto para outro.|

## <a name="bad_cast"></a> bad_cast

O construtor para objetos do tipo `bad_cast`.

```cpp
bad_cast(const char * _Message = "bad cast");
bad_cast(const bad_cast &);
```

## <a name="op_eq"></a> operador =

Um operador de atribuição que atribui um `bad_cast` objeto para outro.

```cpp
bad_cast& operator=(const bad_cast&) noexcept;
```

## <a name="what"></a> o que

```cpp
const char* what() const noexcept override;
```

## <a name="see-also"></a>Consulte também

[Operador dynamic_cast](../cpp/dynamic-cast-operator.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)