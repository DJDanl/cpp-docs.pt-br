---
title: Funções genéricas (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- functions [C++], generic
- generic methods
- generics [C++], functions
- methods [C++], generic
- generic functions
ms.assetid: 8e409364-58f9-4360-b486-e7d555e0c218
ms.openlocfilehash: 74e8cfe2b5b49a672b276400be75031626fd61c2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432384"
---
# <a name="generic-functions-ccli"></a>Funções genéricas (C++/CLI)

Uma função genérica é uma função que é declarada com parâmetros de tipo. Quando chamado, os tipos reais são usados em vez dos parâmetros de tipo.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="remarks"></a>Comentários

Esse recurso não se aplica a todas as plataformas.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

Não há suporte para esse recurso no tempo de execução do Windows.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

Uma função genérica é uma função que é declarada com parâmetros de tipo. Quando chamado, os tipos reais são usados em vez dos parâmetros de tipo.

### <a name="syntax"></a>Sintaxe

```cpp
[attributes] [modifiers]
return-type identifier<type-parameter identifier(s)>
[type-parameter-constraints clauses]

([formal-parameters])
{function-body}
```

### <a name="parameters"></a>Parâmetros

*Atributos*<br/>
(Opcional) Informações declarativas adicionais. Para obter mais informações sobre atributos e classes de atributos, consulte atributos.

*Modificadores*<br/>
(Opcional) Um modificador para a função, como estático.  **virtual** não é permitida porque métodos virtuais não podem ser genéricos.

*tipo de retorno*<br/>
O tipo retornado pelo método. Se o tipo de retorno é void, nenhum valor de retorno é necessário.

*identifier*<br/>
O nome da função.

*parâmetro de tipo identificador (es)*<br/>
Lista de identificadores separados por vírgulas.

*parâmetros formais*<br/>
(Opcional) Lista de parâmetros.

*tipo de parâmetro-restrições cláusulas*<br/>
Isso especifica restrições sobre os tipos que podem ser usados como argumentos de tipo e assume o formato especificado na [restrições em parâmetros de tipo genéricos (C + + c++ CLI)](../windows/constraints-on-generic-type-parameters-cpp-cli.md).

*corpo de função*<br/>
O corpo do método, que pode se referir a identificadores de parâmetro de tipo.

### <a name="remarks"></a>Comentários

Funções genéricas são funções declaradas com um parâmetro de tipo genérico. Eles podem ser métodos em uma classe ou struct ou autônomo funções. Uma única declaração genérica declara implicitamente uma família de funções que diferem apenas na substituição de um tipo real diferente para o parâmetro de tipo genérico.

Um construtor de classe ou struct não pode ser declarado com parâmetros de tipo genérico.

Quando chamado, o parâmetro de tipo genérico é substituído por um tipo real. O tipo real pode ser especificado explicitamente em colchetes angulares, usando uma sintaxe semelhante a uma chamada de função de modelo. Se for chamado sem os parâmetros de tipo, o compilador tentará deduzir o tipo real de parâmetros fornecidos na chamada de função. Se o argumento de tipo pretendida não pode ser deduzido dos parâmetros usados, o compilador relatará um erro.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra uma função genérica.

```cpp
// generics_generic_function_1.cpp
// compile with: /clr
generic <typename ItemType>
void G(int i) {}

ref struct A {
   generic <typename ItemType>
   void G(ItemType) {}

   generic <typename ItemType>
   static void H(int i) {}
};

int main() {
   A myObject;

   // generic function call
   myObject.G<int>(10);

   // generic function call with type parameters deduced
   myObject.G(10);

   // static generic function call
   A::H<int>(10);

   // global generic function call
   G<int>(10);
}
```

Funções genéricas podem ser sobrecarregadas com base na assinatura ou arity, o número de parâmetros de tipo em uma função. Além disso, funções genéricas podem ser sobrecarregadas com funções de não-genérica de mesmo nome, desde que as funções diferem em alguns parâmetros de tipo. Por exemplo, as funções a seguir podem ser sobrecarregadas:

```cpp
// generics_generic_function_2.cpp
// compile with: /clr /c
ref struct MyClass {
   void MyMythod(int i) {}

   generic <class T>
   void MyMythod(int i) {}

   generic <class T, class V>
   void MyMythod(int i) {}
};
```

O exemplo a seguir usa uma função genérica para localizar o primeiro elemento em uma matriz. Ele declara `MyClass`, que herda da classe base `MyBaseClass`. `MyClass` contém uma função genérica, `MyFunction`, que chama outra função genérica, `MyBaseClassFunction`, dentro da classe base. Na `main`, a função genérica, `MyFunction`, é chamado usando argumentos de tipo diferente.

```cpp
// generics_generic_function_3.cpp
// compile with: /clr
using namespace System;

ref class MyBaseClass {
protected:
   generic <class ItemType>
   ItemType MyBaseClassFunction(ItemType item) {
      return item;
   }
};

ref class MyClass: public MyBaseClass {
public:
   generic <class ItemType>
   ItemType MyFunction(ItemType item) {
      return MyBaseClass::MyBaseClassFunction<ItemType>(item);
   }
};

int main() {
   MyClass^ myObj = gcnew MyClass();

   // Call MyFunction using an int.
   Console::WriteLine("My function returned an int: {0}",
                           myObj->MyFunction<int>(2003));

   // Call MyFunction using a string.
   Console::WriteLine("My function returned a string: {0}",
   myObj->MyFunction<String^>("Hello generic functions!"));
}
```

```Output
My function returned an int: 2003
My function returned a string: Hello generic functions!
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)<br/>
[Genéricos](../windows/generics-cpp-component-extensions.md)
