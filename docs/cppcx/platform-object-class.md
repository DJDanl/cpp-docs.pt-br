---
title: Classe Platform::Object
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Object::Object
- VCCORLIB/Platform::Object::Equals
- VCCORLIB/Platform::Object::GetHashCode
- VCCORLIB/Platform::Object::ReferenceEquals
- VCCORLIB/Platform::ToString
- VCCORLIB/Platform::GetType
helpviewer_keywords:
- Object class
ms.assetid: 709e84a8-0bff-471b-bc14-63e424080b5a
ms.openlocfilehash: 77313f8c4dcc87fa9de852afe2d60e614f8fc3a3
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418345"
---
# <a name="platformobject-class"></a>Classe Platform::Object

Fornece comportamento comum para classes ref e structs de referência em aplicativos Windows Runtime. Todas as instâncias de classe e estrutura ref podem ser convertidas implicitamente em Platform::Object^ e podem substituir o método virtual ToString.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class Object : Object
```

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Objeto:: objeto](#ctor)|Inicializa uma nova instância da classe Object.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Objeto:: Equals](#equals)|Determina se o objeto especificado é igual ao objeto atual.|
|[Objeto:: GetHashCode](#gethashcode)|Retorna o código hash desta instância.|
|[Objeto:: ReferenceEquals](#referenceequals)|Determina se as instâncias de Object especificadas são a mesma instância.|
|[ToString](#tostring)|Retorna uma cadeia de caracteres que representa o objeto atual. Pode ser substituído.|
|[GetType](#gettype)|Obtém um [Platform::Type](../cppcx/platform-type-class.md) que descreve a instância atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Object`

`Object`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** vccorlib.h

**Namespace:** Platform

## <a name="equals"></a>Método Object:: Equals

Determina se o objeto especificado é igual ao objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
bool Equals(
    Object^ obj
)
```

### <a name="parameters"></a>parâmetros

*obj*<br/>
O objeto a comparar.

### <a name="return-value"></a>Valor retornado

**true** se os objetos forem iguais, caso contrário, **false**.

## <a name="gethashcode"></a>Método Object:: GetHashCode

Retorna o valor de identidade `IUnknown`* para essa instância se for um objeto COM, ou um valor de hash calculado se não for um objeto COM.

### <a name="syntax"></a>Sintaxe

```cpp
public:int GetHashCode();
```

### <a name="return-value"></a>Valor retornado

Valor numérico que identifica esse objeto de forma exclusiva.

### <a name="remarks"></a>Comentários

Você pode usar GetHashCode para criar chaves para objetos em mapas. Você pode comparar os códigos de hash usando [Object:: Equals](#equals). Se o caminho do código for extremamente crítico e `GetHashCode` e `Equals` não forem suficientemente rápidos, você poderá passar para a camada COM subjacente e fazer comparações do ponteiro `IUnknown` nativo.

## <a name="gettype"></a>Método Object:: GetType

Retorna um objeto [Platform:: Type](../cppcx/platform-type-class.md) que descreve o tipo de tempo de execução de um objeto.

### <a name="syntax"></a>Sintaxe

```cpp
Object::GetType();
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Um objeto [Platform:: Type](../cppcx/platform-type-class.md) que descreve o tipo de tempo de execução do objeto.

### <a name="remarks"></a>Comentários

O [tipo estático:: GetTypeCode](../cppcx/platform-type-class.md#gettypecode) pode ser usado para obter um valor de [Enumeração Platform:: TypeCode](../cppcx/platform-typecode-enumeration.md) que representa o tipo atual. Isso é mais útil para tipos internos. O código de tipo para qualquer classe ref além de [Platform:: String](../cppcx/platform-string-class.md) é Object (1).

A classe [Windows:: UI:: XAML:: Interop:: TypeName](/uwp/api/windows.ui.xaml.interop.typename) é usada nas APIs do Windows como uma maneira independente de linguagem de passar informações de tipo entre componentes e aplicativos do Windows. A[classe T Platform:: Type](../cppcx/platform-type-class.md) tem operadores para conversão entre `Type` e `TypeName`.

Use o operador [typeid](../extensions/typeid-cpp-component-extensions.md) para retornar um objeto `Platform::Type` para um nome de classe, por exemplo, ao navegar entre páginas XAML:

```
rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
```

## <a name="ctor"></a>Construtor Object:: Object

Inicializa uma nova instância da classe Object.

### <a name="syntax"></a>Sintaxe

```cpp
public:Object();
```

## <a name="referenceequals"></a>Método Object:: ReferenceEquals

Determina se as instâncias de Object especificadas são a mesma instância.

### <a name="syntax"></a>Sintaxe

```cpp
public:static bool ReferenceEquals(  Object^ obj1,   Object^ obj2);
```

### <a name="parameters"></a>parâmetros

*Obj1*<br/>
O primeiro objeto a comparar.

*obj2*<br/>
O segundo objeto a comparar.

### <a name="return-value"></a>Valor retornado

**true** se os dois objetos forem os mesmos; caso contrário, **false**.

## <a name="tostring"></a>Método Object:: ToString (C++/CX)

Retorna uma cadeia de caracteres que representa o objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
public:
virtual String^ ToString();
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que representa o objeto atual. Você pode substituir esse método para fornecer uma mensagem de cadeia de caracteres personalizada em sua classe ref ou struct:

```cpp
public ref class Tree sealed
{
public:
    Tree(){}
    virtual Platform::String^ ToString() override
    {
      return "I’m a Tree";
    };
};
```

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)<br/>
[Classe Platform::Type](platform-type-class.md)<br/>
[Sistema de tipos](type-system-c-cx.md)
