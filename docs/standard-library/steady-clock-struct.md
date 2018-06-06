---
title: Struct steady_clock | Microsoft Docs
ms.custom: ''
ms.date: 05/22/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- chrono/std::chrono::steady_clock
dev_langs:
- C++
ms.assetid: 970d12ec-fc80-4391-a2f7-b57b2aec668d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5445379597c4fefcd657303a05c33b6509d54d2e
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34569892"
---
# <a name="steadyclock-struct"></a>Struct steady_clock

Representa um *constante* relógio.

## <a name="syntax"></a>Sintaxe

```cpp
struct steady_clock;
```

## <a name="remarks"></a>Comentários

No Windows, `steady_clock` encapsula o `QueryPerformanceCounter` função.

Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now`. Um relógio será *estável* se ele for *monotônico* e se o tempo entre os tiques do relógio for constante.

`high_resolution_clock` é um typedef para `steady_clock`.

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`steady_clock::duration`|Um sinônimo para `nanoseconds`, definido em \<chrono >.|
|`steady_clock::period`|Um sinônimo para `nano`, definido em \<taxa >.|
|`steady_clock::rep`|Um sinônimo para **longo** **longo**, o tipo que é usado para representar o número de tiques do relógio na instanciação independente de `duration`.|
|`steady_clock::time_point`|Um sinônimo de `chrono::time_point<steady_clock>`.|

## <a name="public-functions"></a>Funções públicas

|Função|Descrição|
|--------------|-----------------|
|`now`|Retorna a hora atual como uma `time_point` valor.|

## <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|`steady_clock::is_steady`|Contém `true`. Um `steady_clock` é *steady*.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<chrono >

**Namespace:** std::chrono

## <a name="see-also"></a>Consulte também

- [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
- [\<chrono>](../standard-library/chrono.md)
- [Estrutura system_clock](../standard-library/system-clock-structure.md)
