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
ms.openlocfilehash: 8300ec484bdb58919ce8e450b706dd07c275ceee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363682"
---
# <a name="platformobject-class"></a>Classe Platform::Object

Fornece comportamento comum para classes de ref e structs de ref em aplicativos do Windows Runtime. Todas as instâncias de classe e estrutura ref podem ser convertidas implicitamente em Platform::Object^ e podem substituir o método virtual ToString.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class Object : Object
```

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Object::Object](#ctor)|Inicializa uma nova instância da classe Object.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Object::Equals](#equals)|Determina se o objeto especificado é igual ao objeto atual.|
|[Object::GetHashCode](#gethashcode)|Retorna o código hash desta instância.|
|[Object::ReferenceEquals](#referenceequals)|Determina se as instâncias de Object especificadas são a mesma instância.|
|[ToString](#tostring)|Retorna uma cadeia de caracteres que representa o objeto atual. Pode ser substituído.|
|[GetType](#gettype)|Obtém um [Platform::Type](../cppcx/platform-type-class.md) que descreve a instância atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Object`

`Object`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** vccorlib.h

**Namespace:** Platform

## <a name="objectequals-method"></a><a name="equals"></a>Objeto::Equals Method

Determina se o objeto especificado é igual ao objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
bool Equals(
    Object^ obj
)
```

### <a name="parameters"></a>Parâmetros

*obj*<br/>
O objeto a comparar.

### <a name="return-value"></a>Valor retornado

**verdade** se os objetos são iguais, caso contrário **falso**.

## <a name="objectgethashcode-method"></a><a name="gethashcode"></a>Objeto::GetHashCode Method

Retorna o valor de identidade `IUnknown`* para essa instância se for um objeto COM, ou um valor de hash calculado se não for um objeto COM.

### <a name="syntax"></a>Sintaxe

```cpp
public:int GetHashCode();
```

### <a name="return-value"></a>Valor retornado

Valor numérico que identifica esse objeto de forma exclusiva.

### <a name="remarks"></a>Comentários

Você pode usar GetHashCode para criar chaves para objetos em mapas. Você pode comparar códigos hash usando [Object::Equals](#equals). Se o caminho do código for extremamente crítico e `GetHashCode` e `Equals` não forem suficientemente rápidos, você poderá passar para a camada COM subjacente e fazer comparações do ponteiro `IUnknown` nativo.

## <a name="objectgettype-method"></a><a name="gettype"></a>objeto::Método gettype

Retorna uma [plataforma::Digite](../cppcx/platform-type-class.md) um objeto que descreve o tipo de tempo de execução de um objeto.

### <a name="syntax"></a>Sintaxe

```cpp
Object::GetType();
```

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Uma [plataforma::Digite](../cppcx/platform-type-class.md) um objeto que descreve o tipo de tempo de execução do objeto.

### <a name="remarks"></a>Comentários

O [tipo estático::GetTypeCode](../cppcx/platform-type-class.md#gettypecode) pode ser usado para obter uma [plataforma::Valor de enumeração TypeCode](../cppcx/platform-typecode-enumeration.md) que representa o tipo atual. Isso é mais útil para tipos internos. O código de tipo para qualquer classe de ref além [de Plataforma::String](../cppcx/platform-string-class.md) is Object (1).

A classe [Windows::UI::Xaml::Interop::TypeName](/uwp/api/windows.ui.xaml.interop.typename) é usada nas APIs do Windows como uma maneira independente de passar informações de tipo entre componentes e aplicativos do Windows. A[Plataforma T::Type Class](../cppcx/platform-type-class.md) tem operadores para converter entre `Type` e `TypeName`.

Use o operador [digitado](../extensions/typeid-cpp-component-extensions.md) para retornar um `Platform::Type` objeto para um nome de classe, por exemplo, ao navegar entre páginas XAML:

```
rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
```

## <a name="objectobject-constructor"></a><a name="ctor"></a>Objeto::Construtor de objetos

Inicializa uma nova instância da classe Object.

### <a name="syntax"></a>Sintaxe

```cpp
public:Object();
```

## <a name="objectreferenceequals-method"></a><a name="referenceequals"></a>Objeto::ReferênciaEquals Method

Determina se as instâncias de Object especificadas são a mesma instância.

### <a name="syntax"></a>Sintaxe

```cpp
public:static bool ReferenceEquals(  Object^ obj1,   Object^ obj2);
```

### <a name="parameters"></a>Parâmetros

*obj1*<br/>
O primeiro objeto a comparar.

*obj2*<br/>
O segundo objeto a comparar.

### <a name="return-value"></a>Valor retornado

**verdade** se os dois objetos são os mesmos; caso contrário, **falso**.

## <a name="objecttostring-method-ccx"></a><a name="tostring"></a>Objeto::Método de corda (C++/CX)

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

[Espaço de nome da plataforma](platform-namespace-c-cx.md)<br/>
[Plataforma::Classe de tipo](platform-type-class.md)<br/>
[Sistema de tipo](type-system-c-cx.md)
