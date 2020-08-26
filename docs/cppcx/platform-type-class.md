---
title: Classe Platform::Type
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Type::GetTypeCode
- VCCORLIB/Platform::Type::FullName
helpviewer_keywords:
- Platform::Type Class
ms.assetid: d6b03f1e-b240-49b9-a08e-53a460030475
ms.openlocfilehash: f94e1b37cf198f92d49efc793753892c1b138d69
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846557"
---
# <a name="platformtype-class"></a>Classe Platform::Type

Contém informações de tempo de execução sobre um tipo, especificamente um nome de cadeia de caracteres e um typecode. Obtido com a chamada de [Object:: GetType](../cppcx/platform-object-class.md#gettype) em qualquer objeto ou usando o operador [typeid](../extensions/typeid-cpp-component-extensions.md) em um nome de classe ou struct.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class Platform::Type :
    Platform::Object, Platform::Details::IEquatable,
    Platform::Details::IPrintable
```

### <a name="remarks"></a>Comentários

A `Type` classe é útil em aplicativos que devem processar o processamento direto usando **`if`** uma **`switch`** instrução or que ramifica com base no tipo de tempo de execução de um objeto. O código de tipo que descreve a categoria de um tipo é recuperado usando a função de membro [Type:: GetTypeCode](#gettypecode) .

## <a name="public-methods"></a>Métodos públicos

| Nome | Descrição |
|--|--|
| [Método Type::GetTypeCode](#gettypecode) | Retorna um valor de [Enumeração Platform::TypeCode](../cppcx/platform-typecode-enumeration.md) para o objeto. |
| [Método Type:: ToString](#tostring) | Retorna o nome do tipo conforme especificado em seus metadados. |

## <a name="public-properties"></a>Propriedades públicas

| Nome | Descrição |
|--|--|
| [Tipo:: FullName](#fullname) | Retorna uma [Classe Platform::String](../cppcx/platform-string-class.md)^ que representa o nome totalmente qualificado do tipo e usa . (ponto) como um separador, não:: (dois-pontos duplo) — por exemplo, `MyNamespace.MyClass` . |

## <a name="conversion-operators"></a>Operadores de conversão

| Nome | Descrição |
|--|--|
| [Tipo de operador ^](../cppcx/operator-type-hat.md) | Permite a conversão de `Windows::UI::Xaml::Interop::TypeName` em `Platform::Type`. |
| [operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md) | Permite a conversão de `Platform::Type` em `Windows::UI::Xaml::Interop::TypeName`. |

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** Platform. winmd

## <a name="typefullname-property"></a><a name="fullname"></a> Propriedade Type:: FullName

Recupera o nome totalmente qualificado do tipo atual no formulário `Namespace.Type` .

### <a name="syntax"></a>Sintaxe

```cpp
String^ FullName();
```

### <a name="return-value"></a>Valor retornado

O nome do tipo.

### <a name="example"></a>Exemplo

```cpp
//  namespace is TestApp
MainPage::MainPage()
{
    InitializeComponent();
    Type^ t = this->GetType();
    auto s = t->FullName; // returns "TestApp.MainPage"
    auto s2 = t->ToString(); //also returns "TestApp.MainPage"
}
```

## <a name="typegettypecode-method"></a><a name="gettypecode"></a> Método Type:: GetTypeCode

Recupera uma categoria de tipo numérico de tipos internos.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::TypeCode GetTypeCode();
```

### <a name="return-value"></a>Valor retornado

Um dos valores enumerados de Platform::TypeCode.

### <a name="remarks"></a>Comentários

O equivalente do método de membro GetTypeCode () é a **`typeid`** propriedade.

## <a name="typetostring-method"></a><a name="tostring"></a> Método Type:: ToString

Recupera o nome do tipo.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::String^ ToString();
```

### <a name="return-value"></a>Valor retornado

Um nome do tipo conforme especificado em seus metadados.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
