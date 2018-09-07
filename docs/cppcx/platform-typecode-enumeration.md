---
title: 'Enumeração Platform:: TypeCode | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::TypeCode
dev_langs:
- C++
helpviewer_keywords:
- Platform::TypeCode Enumeration
ms.assetid: 93c1305f-eb16-4bec-aead-f88d9518b4cf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb19a922655a77a2f7a2b5806c9b721f17e028f8
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44104167"
---
# <a name="platformtypecode-enumeration"></a>Enumeração Platform::TypeCode

Especifica uma categoria numérica que representa um tipo interno.

## <a name="syntax"></a>Sintaxe

```cpp
enum class TypeCode {};
```

### <a name="members"></a>Membros

|Type Code|Descrição|
|---------------|-----------------|
|Boolean|Um tipo Platform::Boolean.|
|Char16|Um tipo default::char16.|
|DateTime|Um tipo DateTime.|
|Decimal|Um tipo numérico.|
|Duplo|Um tipo default::float64.|
|Vazio|Void|
|Int16|Um tipo default::int16.|
|Int32|Um tipo default::int32.|
|Int64|Um tipo default::int64.|
|Int8|Um tipo default::int8.|
|Objeto|Um tipo Platform::Object.|
|Simples|Um tipo default::float32.|
|Cadeia de Caracteres|Um tipo Platform::String.|
|UInt16|Um tipo default::uint16.|
|UInt32|Um tipo default::uint32.|
|UInt64|Um tipo default::uint64.|
|UInt8|Um tipo default::uint8.|

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd