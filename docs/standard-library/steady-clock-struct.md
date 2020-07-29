---
title: Struct steady_clock
ms.date: 05/22/2018
f1_keywords:
- chrono/std::chrono::steady_clock
ms.assetid: 970d12ec-fc80-4391-a2f7-b57b2aec668d
ms.openlocfilehash: d21d5c2ed7ed667333007f3bd12d13f47b868380
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217396"
---
# <a name="steady_clock-struct"></a>Struct steady_clock

Representa um relógio *constante* .

## <a name="syntax"></a>Sintaxe

```cpp
struct steady_clock;
```

## <a name="remarks"></a>Comentários

No Windows, `steady_clock` o encapsula a `QueryPerformanceCounter` função.

Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now`. Um relógio será *estável* se ele for *monotônico* e se o tempo entre os tiques do relógio for constante.

`high_resolution_clock`é um typedef para `steady_clock` .

### <a name="public-typedefs"></a>TYPEDEFs públicos

|Nome|Descrição|
|----------|-----------------|
|`steady_clock::duration`|Um sinônimo para `nanoseconds` , definido em \<chrono> .|
|`steady_clock::period`|Um sinônimo para `nano` , definido em \<ratio> .|
|`steady_clock::rep`|Um sinônimo para **`long long`** , o tipo que é usado para representar o número de tiques de relógio na instanciação contida de `duration` .|
|`steady_clock::time_point`|Um sinônimo de `chrono::time_point<steady_clock>`.|

## <a name="public-functions"></a>Funções públicas

|Função|Descrição|
|--------------|-----------------|
|`now`|Retorna a hora atual como um `time_point` valor.|

## <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|`steady_clock::is_steady`|Contém **`true`** . Um `steady_clock` é *steady*.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<chrono>

**Namespace:** std::chrono

## <a name="see-also"></a>Confira também

- [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
- [\<chrono>](../standard-library/chrono.md)
- [Estrutura system_clock](../standard-library/system-clock-structure.md)
