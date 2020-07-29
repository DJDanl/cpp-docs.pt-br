---
title: Classe Platform::STAThreadAttribute
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Platform
- COLLECTION/Platform::Platform::STAThreadAttribute constructor 1
- COLLECTION/Platform::Platform::STAThreadAttribute::Equals
- COLLECTION/Platform::Platform::STAThreadAttribute::GetHashCode
- COLLECTION/Platform::Platform::STAThreadAttribute::ToString
helpviewer_keywords:
- Platform::STAThreadAttribute Class
ms.assetid: f97960fc-e673-4d9e-910a-54c8415411c4
ms.openlocfilehash: 6a8220d8cddca29e621b21fc56966efdb42cb32e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213015"
---
# <a name="platformstathreadattribute-class"></a>Classe Platform::STAThreadAttribute

Indica que o modelo de threading para um aplicativo é STA (Single-Threaded Apartment).

## <a name="syntax"></a>Sintaxe

```
public ref class STAThreadAttribute sealed : Attribute
```

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor STAThreadAttribute 1](#ctor)|Inicializa uma nova instância da classe.|

### <a name="public-methods"></a>Métodos públicos

O atributo STAThreadAttribute herda da [classe Platform:: Object](../cppcx/platform-object-class.md). STAThreadAttribute também sobrecarrega ou possui os seguintes membros:

|Nome|Descrição|
|----------|-----------------|
|[STAThreadAttribute::Equals](#equals)|Determina se o objeto especificado é igual ao objeto atual.|
|[STAThreadAttribute::GetHashCode](#gethashcode)|Retorna o código hash para a instância.|
|[STAThreadAttribute::ToString](#tostring)|Retorna uma cadeia de caracteres que representa o objeto atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Platform`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform

## <a name="stathreadattribute-constructor"></a><a name="ctor"></a> STAThreadAttribute constructor

Inicializa uma nova instância da classe STAThreadAttribute.

### <a name="syntax"></a>Sintaxe

```cpp
public:STAThreadAttribute();
```

## <a name="stathreadattributeequals"></a><a name="equals"></a>STAThreadAttribute:: Equals

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

## <a name="stathreadattributegethashcode"></a><a name="gethashcode"></a>STAThreadAttribute:: GetHashCode

Retorna o código hash para a instância.

### <a name="syntax"></a>Sintaxe

```cpp
public:int GetHashCode();
```

### <a name="return-value"></a>Valor retornado

O código hash para essa instância.

## <a name="stathreadattributetostring"></a><a name="tostring"></a>STAThreadAttribute:: ToString

Retorna uma cadeia de caracteres que representa o objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
public:String^ ToString();
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que representa o objeto atual.

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)
