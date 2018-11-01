---
title: Funções globais de conversão de pixel-HIMETRIC
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::AtlHiMetricToPixel
- atlwin/ATL::AtlPixelToHiMetric
ms.assetid: ecb1b1b2-7e9d-4fbc-a855-16252d2d794c
ms.openlocfilehash: 95b3b9c6ba4e5d25a9f07f72f9479121a223ad00
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50529097"
---
# <a name="pixelhimetric-conversion-global-functions"></a>Funções globais de conversão de pixel/HIMETRIC

Essas funções dão suporte para converter entre pixels e unidades HIMETRIC.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no tempo de execução do Windows.

|||
|-|-|
|[AtlHiMetricToPixel](#atlhimetrictopixel)|Converte unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro) em pixels.|
|[AtlPixelToHiMetric](#atlpixeltohimetric)|Converte pixels em unidades HIMETRIC (cada unidade é corresponde a 0,01 milímetro).|

##  <a name="atlhimetrictopixel"></a>  AtlHiMetricToPixel

Converte o tamanho de um objeto em unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro) em um tamanho em pixels no dispositivo da tela.

```
extern void AtlHiMetricToPixel(
    const SIZEL* lpSizeInHiMetric,
    LPSIZEL lpSizeInPix);
```

### <a name="parameters"></a>Parâmetros

*lpSizeInHiMetric*<br/>
[in] Ponteiro para o tamanho do objeto em unidades HIMETRIC.

*lpSizeInPix*<br/>
[out] Ponteiro para onde o tamanho do objeto em pixels a serem retornados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#49](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="atlpixeltohimetric"></a>  AtlPixelToHiMetric

Converte o tamanho de um objeto em pixels no dispositivo da tela em um tamanho em unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro).

```
extern void AtlPixelToHiMetric(
    const SIZEL* lpSizeInPix,
    LPSIZEL lpSizeInHiMetric);
```

### <a name="parameters"></a>Parâmetros

*lpSizeInPix*<br/>
[in] Ponteiro para o tamanho do objeto em pixels.

*lpSizeInHiMetric*<br/>
[out] Ponteiro para onde o tamanho do objeto em unidades HIMETRIC a ser retornado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#51](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
