---
title: 'Enumeração Platform:: callbackcontext | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::CallbackContext
dev_langs:
- C++
helpviewer_keywords:
- Platform::CallbackContext Enumeration
ms.assetid: 60e0c7cb-5d8f-482a-bdca-ca9335ae4899
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fe988a7dee7fb358d9454c06811d7baf2cd4ace0
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44101957"
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