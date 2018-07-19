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
ms.openlocfilehash: 53f4deb0bfe9439011f75cd22d0d52b74dae9c1f
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38959719"
---
# <a name="steadyclock-struct"></a>Struct steady_clock

Representa uma *constante* relógio.

## <a name="syntax"></a>Sintaxe

```cpp
struct steady_clock;
```

## <a name="remarks"></a>Comentários

No Windows, `steady_clock` encapsula a `QueryPerformanceCounter` função.

Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now`. Um relógio será *estável* se ele for *monotônico* e se o tempo entre os tiques do relógio for constante.

`high_resolution_clock` é um typedef para `steady_clock`.

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`steady_clock::duration`|Um sinônimo de `nanoseconds`, definida em \<chrono >.|
|`steady_clock::period`|Um sinônimo de `nano`, definida em \<taxa >.|
|`steady_clock::rep`|Um sinônimo de **longo** **longo**, o tipo que é usado para representar o número de tiques do relógio na instanciação independente de `duration`.|
|`steady_clock::time_point`|Um sinônimo de `chrono::time_point<steady_clock>`.|

## <a name="public-functions"></a>Funções públicas

|Função|Descrição|
|--------------|-----------------|
|`now`|Retorna a hora atual como um `time_point` valor.|

## <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|`steady_clock::is_steady`|Mantém **verdadeira**. Um `steady_clock` é *steady*.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<chrono >

**Namespace:** std::chrono

## <a name="see-also"></a>Consulte também

- [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
- [\<chrono>](../standard-library/chrono.md)
- [Estrutura system_clock](../standard-library/system-clock-structure.md)
