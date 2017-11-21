---
title: "Funções globais de conversão de pixel HIMETRIC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlwin/ATL::AtlHiMetricToPixel
- atlwin/ATL::AtlPixelToHiMetric
dev_langs: C++
ms.assetid: ecb1b1b2-7e9d-4fbc-a855-16252d2d794c
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9b905631c2375793250248fafc32f1628dba9c28
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="pixelhimetric-conversion-global-functions"></a>Funções de conversão de pixel/HIMETRIC Global
Essas funções fornecem suporte para converter para e de pixel e DÉCIMOS de milímetros.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlHiMetricToPixel](#atlhimetrictopixel)|Converte DÉCIMOS de milímetros (cada unidade é milímetro 0,01) em pixels.|  
|[AtlPixelToHiMetric](#atlpixeltohimetric)|Converte pixels em DÉCIMOS de milímetros (cada unidade é milímetro 0,01).|  
  
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
 [!code-cpp[NVC_ATL_COM#49](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_1.cpp)]  

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
 [out] Ponteiro para onde o tamanho do objeto em DÉCIMOS de milímetros é a ser retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#51](../../atl/codesnippet/cpp/pixel-himetric-conversion-global-functions_2.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)
