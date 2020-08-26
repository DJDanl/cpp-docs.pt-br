---
title: Funções globais de conversão de pixel-HIMETRIC
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::AtlHiMetricToPixel
- atlwin/ATL::AtlPixelToHiMetric
ms.assetid: ecb1b1b2-7e9d-4fbc-a855-16252d2d794c
ms.openlocfilehash: e71dccbccbe43ea7df3b6a7005da138a8e31aeb3
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834681"
---
# <a name="pixelhimetric-conversion-global-functions"></a>Funções globais de conversão de pixel/HIMETRIC

Essas funções fornecem suporte para a conversão de e para unidades de pixel e HIMETRIC.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|Nome|Descrição|
|-|-|
|[AtlHiMetricToPixel](#atlhimetrictopixel)|Converte as unidades HIMETRIC (cada unidade é 0, 1 milímetro) em pixels.|
|[AtlPixelToHiMetric](#atlpixeltohimetric)|Converte pixels em unidades HIMETRIC (cada unidade é 0, 1 milímetro).|

## <a name="atlhimetrictopixel"></a><a name="atlhimetrictopixel"></a> AtlHiMetricToPixel

Converte o tamanho de um objeto em unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro) em um tamanho em pixels no dispositivo da tela.

```
extern void AtlHiMetricToPixel(
    const SIZEL* lpSizeInHiMetric,
    LPSIZEL lpSizeInPix);
```

### <a name="parameters"></a>parâmetros

*lpSizeInHiMetric*<br/>
no Ponteiro para o tamanho do objeto em unidades HIMETRIC.

*lpSizeInPix*<br/>
fora Ponteiro para onde o tamanho do objeto em pixels deve ser retornado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#49](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

## <a name="atlpixeltohimetric"></a><a name="atlpixeltohimetric"></a> AtlPixelToHiMetric

Converte o tamanho de um objeto em pixels no dispositivo da tela em um tamanho em unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro).

```
extern void AtlPixelToHiMetric(
    const SIZEL* lpSizeInPix,
    LPSIZEL lpSizeInHiMetric);
```

### <a name="parameters"></a>parâmetros

*lpSizeInPix*<br/>
no Ponteiro para o tamanho do objeto em pixels.

*lpSizeInHiMetric*<br/>
fora Ponteiro para onde o tamanho do objeto em unidades HIMETRIC deve ser retornado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#51](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
