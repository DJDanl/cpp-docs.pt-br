---
title: "Funções globais de conversão de pixel DÉCIMOS | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: ecb1b1b2-7e9d-4fbc-a855-16252d2d794c
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: efb7e7da896aea4e377225f4c1e2c9948e635705
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="pixelhimetric-conversion-global-functions"></a>Funções de conversão de pixel/DÉCIMOS Global
Essas funções fornecem suporte para a conversão entre pixels e DÉCIMOS de milímetros.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlHiMetricToPixel](#atlhimetrictopixel)|Converte unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro) em pixels.|  
|[AtlPixelToHiMetric](#atlpixeltohimetric)|Converte pixels em unidades HIMETRIC (cada unidade é corresponde a 0,01 milímetro).|  
  
##  <a name="atlhimetrictopixel"></a>AtlHiMetricToPixel  
 Converte o tamanho de um objeto em unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro) em um tamanho em pixels no dispositivo da tela.  
  
 
```
extern void AtlHiMetricToPixel(
  const SIZEL* lpSizeInHiMetric, 
  LPSIZEL lpSizeInPix);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSizeInHiMetric`  
 [in] Ponteiro para o tamanho do objeto em DÉCIMOS de milímetros.  
  
 `lpSizeInPix`  
 [out] Ponteiro para onde o tamanho do objeto em pixels é a ser retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&49;](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_1.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="atlpixeltohimetric"></a>AtlPixelToHiMetric  
 Converte o tamanho de um objeto em pixels no dispositivo da tela em um tamanho em unidades HIMETRIC (cada unidade corresponde a 0,01 milímetro).  
  
```
extern void AtlPixelToHiMetric(
    const SIZEL* lpSizeInPix, 
    LPSIZEL lpSizeInHiMetric);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSizeInPix`  
 [in] Ponteiro para o tamanho do objeto em pixels.  
  
 `lpSizeInHiMetric`  
 [out] Ponteiro para onde o tamanho do objeto em unidades HIMETRIC é a ser retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&#51;](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_2.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

