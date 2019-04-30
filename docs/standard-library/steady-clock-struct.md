---
title: Struct steady_clock
ms.date: 05/22/2018
f1_keywords:
- chrono/std::chrono::steady_clock
ms.assetid: 970d12ec-fc80-4391-a2f7-b57b2aec668d
ms.openlocfilehash: 19e9f5c4dcfc7306b989605894e9a0787e0920ff
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412391"
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
