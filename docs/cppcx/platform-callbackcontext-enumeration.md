---
title: Enumeração Platform::CallbackContext
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::CallbackContext
helpviewer_keywords:
- Platform::CallbackContext Enumeration
ms.assetid: 60e0c7cb-5d8f-482a-bdca-ca9335ae4899
ms.openlocfilehash: 7f4e020ab0b1e377456c27d3b4666e15b5a4f7a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50441348"
---
# <a name="platformcallbackcontext-enumeration"></a>Enumeração Platform::CallbackContext

Especifica o contexto do thread no qual uma função de retorno de chamada (manipulador de eventos) é executada.

## <a name="syntax"></a>Sintaxe

```cpp
enum class CallbackContext {};
```

### <a name="members"></a>Membros

|Type Code|Descrição|
|---------------|-----------------|
|Qualquer|A função de retorno de chamada pode ser executada em qualquer contexto de thread.|
|Same|A função de retorno de chamada pode ser executada apenas no contexto de thread que iniciou a operação assíncrona.|

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd