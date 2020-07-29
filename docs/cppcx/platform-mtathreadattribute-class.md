---
title: Classe Platform::MTAThreadAttribute
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::MTAThreadAttribute::Equals
- VCCORLIB/Platform::MTAThreadAttribute::GetHashCode
- VCCORLIB/Platform::MTAThreadAttribute::ToString
helpviewer_keywords:
- Platform::MTAThreadAttribute Class
ms.assetid: bfc546a7-4333-4407-85b4-4721565e1f44
ms.openlocfilehash: 700eeae226be48c1f6659d621f2f5c0ed397bb7f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213041"
---
# <a name="platformmtathreadattribute-class"></a>Classe Platform::MTAThreadAttribute

Indica que o modelo de threading COM para um aplicativo é MTA (Multi-Threaded Apartment).

## <a name="syntax"></a>Sintaxe

```
public ref class MTAThreadAttribute sealed : Attribute
```

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|Construtor do [Construtor 1 do MTAThreadAttribute](#ctor)|Inicializa uma nova instância da classe.|

### <a name="public-methods"></a>Métodos públicos

O atributo MTAThreadAttribute herda da [classe Platform:: Object](../cppcx/platform-object-class.md). O MTAThreadAttribute também sobrecarrega ou tem os seguintes membros:

|Nome|Descrição|
|----------|-----------------|
|[MTAThreadAttribute::Equals](#equals)|Determina se o objeto especificado é igual ao objeto atual.|
|[MTAThreadAttribute::GetHashCode](#gethashcode)|Retorna o código hash para a instância.|
|[MTAThreadAttribute::ToString](#tostring)|Retorna uma cadeia de caracteres que representa o objeto atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Platform`

### <a name="requirements"></a>Requisitos

**Metadados:** Platform. winmd

**Namespace:** Platform

## <a name="mtathreadattribute-constructor"></a><a name="ctor"></a>Construtor MTAThreadAttribute

Inicializa uma nova instância da classe MTAThreadAttribute.

### <a name="syntax"></a>Sintaxe

```cpp
public:MTAThreadAttribute();
```

## <a name="mtathreadattributeequals"></a><a name="equals"></a>MTAThreadAttribute:: Equals

Determina se o objeto especificado é igual ao objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
public:virtual override bool Equals( Object^ obj );
```

### <a name="parameters"></a>parâmetros

*obj*<br/>
O objeto a comparar.

### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos forem iguais; caso contrário, **`false`** .

## <a name="mtathreadattributegethashcode"></a><a name="gethashcode"></a>MTAThreadAttribute:: GetHashCode

Retorna o código hash para a instância.

### <a name="syntax"></a>Sintaxe

```cpp
public:int GetHashCode();
```

### <a name="return-value"></a>Valor retornado

O código hash para essa instância.

## <a name="mtathreadattributetostring"></a><a name="tostring"></a>MTAThreadAttribute:: ToString

Retorna uma cadeia de caracteres que representa o objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
public:String^ ToString();
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que representa o objeto atual.

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)
