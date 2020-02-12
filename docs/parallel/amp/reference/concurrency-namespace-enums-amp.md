---
title: Enumerações do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::access_type
- amp/Concurrency::queuing_mode
ms.assetid: 4c87457e-184f-4992-81ab-ca75e7d524ab
ms.openlocfilehash: a4feb2f98fc288fa79c0f9d81e4ed882027eddf8
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126938"
---
# <a name="concurrency-namespace-enums-amp"></a>Enumerações do namespace de simultaneidade (AMP)

|||
|-|-|
|[Enumeração de access_type](#access_type)|[Enumeração de queuing_mode](#queuing_mode)|

## <a name="access_type"></a>Enumeração de access_type

Tipo de enumeração usado para denotar os vários tipos de acesso aos dados.

```cpp
enum access_type;
```

### <a name="values"></a>Valores

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`access_type_auto`|Escolha automaticamente o melhor `access_type` para o acelerador.|
|`access_type_none`|Especializada. A alocação só pode ser acessada no acelerador e não na CPU.|
|`access_type_read`|Compartilhado. A alocação pode ser acessada no acelerador e pode ser lida na CPU.|
|`access_type_read_write`|Compartilhado. A alocação pode ser acessada no acelerador e pode ser gravada na CPU.|
|`access_type_write`|Compartilhado. A alocação é acessível no acelerador e é legível e gravável na CPU.|

## <a name="queuing_mode"></a>Enumeração de queuing_mode

Especifica os modos de enfileiramento com suporte no acelerador.

```cpp
enum queuing_mode;
```

### <a name="values"></a>Valores

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`queuing_mode_immediate`|Um modo de enfileiramento que especifica que todos os comandos, por exemplo, [Parallel_for_each function (C++ amp)](concurrency-namespace-functions-amp.md#parallel_for_each), são enviados para o dispositivo acelerador correspondente assim que retornam ao chamador.|
|`queuing_mode_automatic`|Um modo de enfileiramento que especifica que os comandos sejam colocados em fila em uma fila de comandos que corresponde ao objeto [accelerator_view](accelerator-view-class.md) . Os comandos são enviados para o dispositivo quando [accelerator_view:: flush](accelerator-view-class.md#flush) é chamado.|

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
