---
title: Enumerações do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::access_type
- amp/Concurrency::queuing_mode
ms.assetid: 4c87457e-184f-4992-81ab-ca75e7d524ab
ms.openlocfilehash: 2467db27ad36dfcda31dfb5bb45067ada5470d07
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376326"
---
# <a name="concurrency-namespace-enums-amp"></a>Enumerações do namespace de simultaneidade (AMP)

|||
|-|-|
|[Enumeração access_type](#access_type)|[Enumeração queuing_mode](#queuing_mode)|

## <a name="access_type-enumeration"></a><a name="access_type"></a>enumeração access_type

Tipo de enumeração usado para denotar os vários tipos de acesso aos dados.

```cpp
enum access_type;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`access_type_auto`|Escolha automaticamente o `access_type` melhor para o acelerador.|
|`access_type_none`|Dedicado. A alocação só é acessível no acelerador e não na CPU.|
|`access_type_read`|Compartilhado. A alocação é acessível no acelerador e é legível na CPU.|
|`access_type_read_write`|Compartilhado. A alocação é acessível no acelerador e pode ser escrita na CPU.|
|`access_type_write`|Compartilhado. A alocação é acessível no acelerador e é legível e gravável na CPU.|

## <a name="queuing_mode-enumeration"></a><a name="queuing_mode"></a>Enumeração queuing_mode

Especifica os modos de fila que são suportados no acelerador.

```cpp
enum queuing_mode;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`queuing_mode_immediate`|Um modo de fila que especifica que quaisquer comandos, por exemplo, [parallel_for_each Função (C++ AMP)](concurrency-namespace-functions-amp.md#parallel_for_each)são enviados para o dispositivo do acelerador correspondente assim que retornarem ao chamador.|
|`queuing_mode_automatic`|Um modo de fila que especifica que os comandos estão enfileirados em uma fila de comandos que corresponde ao objeto [accelerator_view.](accelerator-view-class.md) Os comandos são enviados para o dispositivo quando [accelerator_view::flush](accelerator-view-class.md#flush) é chamado.|

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
