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
ms.openlocfilehash: 7463a2518e6ec5cc84f59db05cfaf60e43eb9fde
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322089"
---
# <a name="platformtype-class"></a>Classe Platform::Type

Contém informações de tempo de execução sobre um tipo, especificamente um nome de cadeia de caracteres e um typecode. Obtido chamando [Object::GetType](../cppcx/platform-object-class.md#gettype) em qualquer objeto ou usando o operador [digitado](../extensions/typeid-cpp-component-extensions.md) em uma classe ou nome de estrutura.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class Platform::Type :
    Platform::Object, Platform::Details::IEquatable,
    Platform::Details::IPrintable
```

### <a name="remarks"></a>Comentários

A classe `Type` é útil em aplicativos que devem direcionar o processamento usando uma instrução `if` ou `switch` que se ramifica de acordo com o tipo de tempo de execução de um objeto. O código de tipo que descreve a categoria de um tipo é recuperado usando a função [Tipo::Membro GetTypeCode.](#gettypecode)

## <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|[Método Type::GetTypeCode](#gettypecode)|Retorna um valor de [Enumeração Platform::TypeCode](../cppcx/platform-typecode-enumeration.md) para o objeto.|
|[Tipo::Método tostring](#tostring)|Retorna o nome do tipo conforme especificado em seus metadados.|

## <a name="public-properties"></a>Propriedades públicas

|||
|-|-|
|[Tipo::FullName](#fullname)|Retorna uma [Classe Platform::String](../cppcx/platform-string-class.md)^ que representa o nome totalmente qualificado do tipo e usa . (ponto) como separador, não :: (cólon duplo)— por exemplo, `MyNamespace.MyClass`.|

## <a name="conversion-operators"></a>Operadores de conversão

|||
|-|-|
|[tipo de operador^](../cppcx/operator-type-hat.md)|Permite a conversão de `Windows::UI::Xaml::Interop::TypeName` em `Platform::Type`.|
|[operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md)|Permite a conversão de `Platform::Type` em `Windows::UI::Xaml::Interop::TypeName`.|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="typefullname-property"></a><a name="fullname"></a>Tipo::Propriedade FullName

Recupera o nome totalmente qualificado do tipo `Namespace.Type`atual no formulário .

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

## <a name="typegettypecode-method"></a><a name="gettypecode"></a>Tipo::Método GetTypeCode

Recupera uma categoria de tipo numérico de tipos internos.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::TypeCode GetTypeCode();
```

### <a name="return-value"></a>Valor retornado

Um dos valores enumerados de Platform::TypeCode.

### <a name="remarks"></a>Comentários

O equivalente do método membro GetTypeCode() é a propriedade `typeid`.

## <a name="typetostring-method"></a><a name="tostring"></a>Tipo::Método tostring

Recupera um nome do tipo.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::String^ ToString();
```

### <a name="return-value"></a>Valor retornado

Um nome do tipo especificado em seus metadados.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
