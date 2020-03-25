---
title: Enumeração Platform::CallbackContext
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::CallbackContext
helpviewer_keywords:
- Platform::CallbackContext Enumeration
ms.assetid: 60e0c7cb-5d8f-482a-bdca-ca9335ae4899
ms.openlocfilehash: 1daa3988fcb985dab9d3083233a3703a20cc2fdb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214247"
---
# <a name="platformcallbackcontext-enumeration"></a>Enumeração Platform::CallbackContext

Especifica o contexto do thread no qual uma função de retorno de chamada (manipulador de eventos) é executada.

## <a name="syntax"></a>Sintaxe

```cpp
enum class CallbackContext {};
```

### <a name="members"></a>Membros

|Type Code|DESCRIÇÃO|
|---------------|-----------------|
|Qualquer|A função de retorno de chamada pode ser executada em qualquer contexto de thread.|
|Idêntico|A função de retorno de chamada pode ser executada apenas no contexto de thread que iniciou a operação assíncrona.|

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd
