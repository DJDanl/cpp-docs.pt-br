---
title: Enumerações do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::access_type
- amp/Concurrency::queuing_mode
ms.assetid: 4c87457e-184f-4992-81ab-ca75e7d524ab
ms.openlocfilehash: adfc1743d887f2a670111eff31cf4653d2df1bee
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326069"
---
# <a name="concurrency-namespace-enums-amp"></a>Enumerações do namespace de simultaneidade (AMP)

|||
|-|-|
|[Enumeração access_type](#access_type)|[Enumeração queuing_mode](#queuing_mode)|

##  <a name="access_type"></a>  Enumeração access_type

Tipo de enumeração usado para denotar vários tipos de acesso a dados.

```
enum access_type;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`access_type_auto`|Escolher automaticamente o melhor `access_type` para o acelerador.|
|`access_type_none`|Dedicado. A alocação só está acessível no Acelerador e não na CPU.|
|`access_type_read`|Compartilhado. A alocação é acessível no Acelerador e é legível na CPU.|
|`access_type_read_write`|Compartilhado. A alocação é acessível no Acelerador e é gravável na CPU.|
|`access_type_write`|Compartilhado. A alocação é acessível no Acelerador e é legível e gravável na CPU.|

##  <a name="queuing_mode"></a>  queuing_mode Enumeration

Especifica os modos de enfileiramento de mensagens que são suportados no acelerador.

```
enum queuing_mode;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`queuing_mode_immediate`|Um modo de fila que especifica que todos os comandos, por exemplo, [função (C++ AMP) parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each), são enviadas para o dispositivo do acelerador correspondente assim que eles retornarem ao chamador.|
|`queuing_mode_automatic`|Um modo de fila que especifica os comandos serão enfileirados em uma fila de comando que corresponde do [accelerator_view](accelerator-view-class.md) objeto. Os comandos são enviados para o dispositivo quando [accelerator_view:: Flush](accelerator-view-class.md#flush) é chamado.|

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
