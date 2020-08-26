---
title: Enumerações do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::access_type
- amp/Concurrency::queuing_mode
ms.assetid: 4c87457e-184f-4992-81ab-ca75e7d524ab
ms.openlocfilehash: 3dbb8f265706f7a4c369c80d3050cd1bfd2f5acb
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845088"
---
# <a name="concurrency-namespace-enums-amp"></a>Enumerações do namespace de simultaneidade (AMP)

[Enumeração de access_type](#access_type)\
[Enumeração queuing_mode](#queuing_mode)

## <a name="access_type-enumeration"></a><a name="access_type"></a> Enumeração de access_type

Tipo de enumeração usado para denotar os vários tipos de acesso aos dados.

```cpp
enum access_type;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`access_type_auto`|Escolha automaticamente o melhor `access_type` para o acelerador.|
|`access_type_none`|Especializada. A alocação só pode ser acessada no acelerador e não na CPU.|
|`access_type_read`|Compartilhado. A alocação pode ser acessada no acelerador e pode ser lida na CPU.|
|`access_type_read_write`|Compartilhado. A alocação pode ser acessada no acelerador e pode ser gravada na CPU.|
|`access_type_write`|Compartilhado. A alocação é acessível no acelerador e é legível e gravável na CPU.|

## <a name="queuing_mode-enumeration"></a><a name="queuing_mode"></a> Enumeração de queuing_mode

Especifica os modos de enfileiramento com suporte no acelerador.

```cpp
enum queuing_mode;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`queuing_mode_immediate`|Um modo de enfileiramento que especifica que qualquer comando, por exemplo, [Parallel_for_each function (C++ amp)](concurrency-namespace-functions-amp.md#parallel_for_each), seja enviado para o dispositivo acelerador correspondente assim que retornar ao chamador.|
|`queuing_mode_automatic`|Um modo de enfileiramento que especifica que os comandos sejam colocados em fila em uma fila de comandos que corresponde ao objeto [accelerator_view](accelerator-view-class.md) . Os comandos são enviados para o dispositivo quando [accelerator_view:: flush](accelerator-view-class.md#flush) é chamado.|

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
