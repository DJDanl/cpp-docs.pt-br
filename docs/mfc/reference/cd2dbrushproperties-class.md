---
title: Classe CD2DBrushProperties | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DBrushProperties
- AFXRENDERTARGET/CD2DBrushProperties
- AFXRENDERTARGET/CD2DBrushProperties::CD2DBrushProperties
- AFXRENDERTARGET/CD2DBrushProperties::CommonInit
dev_langs:
- C++
helpviewer_keywords:
- CD2DBrushProperties [MFC], CD2DBrushProperties
- CD2DBrushProperties [MFC], CommonInit
ms.assetid: c77d717f-0a16-4d74-b2ce-0ae1766ed6f9
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: ce10f805968b31f0d3a832891c1e0e378277b626
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cd2dbrushproperties-class"></a>Classe CD2DBrushProperties
Um wrapper para `D2D1_BRUSH_PROPERTIES`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DBrushProperties : public D2D1_BRUSH_PROPERTIES;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBrushProperties::CD2DBrushProperties](#cd2dbrushproperties)|Sobrecarregado. Cria um `CD2D_BRUSH_PROPERTIES` estrutura|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBrushProperties::CommonInit](#commoninit)|Inicializa o objeto|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_BRUSH_PROPERTIES`  
  
 `CD2DBrushProperties`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dbrushproperties"></a>CD2DBrushProperties::CD2DBrushProperties  
 Cria uma estrutura de CD2D_BRUSH_PROPERTIES  
  
```  
CD2DBrushProperties();  
CD2DBrushProperties(FLOAT _opacity);

 
CD2DBrushProperties(
    D2D1_MATRIX_3X2_F _transform,  
    FLOAT _opacity = 1.);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_opacity`  
 A opacidade de base do pincel. O valor padrão é 1.0.  
  
 `_transform`  
 A transformação a ser aplicada ao Pincel  
  
##  <a name="commoninit"></a>CD2DBrushProperties::CommonInit  
 Inicializa o objeto  
  
```  
void CommonInit();
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

