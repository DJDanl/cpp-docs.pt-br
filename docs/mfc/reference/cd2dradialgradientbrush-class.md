---
title: Classe CD2DRadialGradientBrush | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush::CD2DRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush::Attach
- AFXRENDERTARGET/CD2DRadialGradientBrush::Create
- AFXRENDERTARGET/CD2DRadialGradientBrush::Destroy
- AFXRENDERTARGET/CD2DRadialGradientBrush::Detach
- AFXRENDERTARGET/CD2DRadialGradientBrush::Get
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetCenter
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetGradientOriginOffset
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetRadiusX
- AFXRENDERTARGET/CD2DRadialGradientBrush::GetRadiusY
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetCenter
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetGradientOriginOffset
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetRadiusX
- AFXRENDERTARGET/CD2DRadialGradientBrush::SetRadiusY
- AFXRENDERTARGET/CD2DRadialGradientBrush::m_pRadialGradientBrush
- AFXRENDERTARGET/CD2DRadialGradientBrush::m_RadialGradientBrushProperties
dev_langs:
- C++
helpviewer_keywords:
- CD2DRadialGradientBrush class
ms.assetid: 6c76d84a-d831-4ee2-96f1-82c1f5b0d6a9
caps.latest.revision: 17
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
ms.openlocfilehash: 8b3fd7f468745567969ba1f7e9d6871a9060582b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dradialgradientbrush-class"></a>Classe de CD2DRadialGradientBrush
Um wrapper para ID2D1RadialGradientBrush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DRadialGradientBrush : public CD2DGradientBrush;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRadialGradientBrush::CD2DRadialGradientBrush](#cd2dradialgradientbrush)|Constrói um objeto CD2DLinearGradientBrush.|  
|[CD2DRadialGradientBrush:: ~ CD2DRadialGradientBrush](#_dtorcd2dradialgradientbrush)|O destruidor. Chamado quando um objeto de pincel de gradiente radial D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRadialGradientBrush::Attach](#attach)|Conexões existentes de interface de recursos para o objeto|  
|[CD2DRadialGradientBrush::Create](#create)|Cria um CD2DRadialGradientBrush. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DRadialGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DRadialGradientBrush. (Substitui [CD2DGradientBrush::Destroy](../../mfc/reference/cd2dgradientbrush-class.md#destroy).)|  
|[CD2DRadialGradientBrush::Detach](#detach)|Desconecta a interface do recurso do objeto|  
|[CD2DRadialGradientBrush::Get](#get)|Interface de ID2D1RadialGradientBrush retorna|  
|[CD2DRadialGradientBrush::GetCenter](#getcenter)|Recupera o centro da elipse gradiente|  
|[CD2DRadialGradientBrush::GetGradientOriginOffset](#getgradientoriginoffset)|Recupera o deslocamento da origem gradiente em relação ao centro da elipse gradiente|  
|[CD2DRadialGradientBrush::GetRadiusX](#getradiusx)|Recupera o raio-x da elipse gradiente|  
|[CD2DRadialGradientBrush::GetRadiusY](#getradiusy)|Recupera o raio de y da elipse gradiente|  
|[CD2DRadialGradientBrush::SetCenter](#setcenter)|Especifica o centro da elipse gradiente no espaço de coordenadas do pincel|  
|[CD2DRadialGradientBrush::SetGradientOriginOffset](#setgradientoriginoffset)|Especifica o deslocamento da origem gradiente em relação ao centro da elipse gradiente|  
|[CD2DRadialGradientBrush::SetRadiusX](#setradiusx)|Especifica o raio-x da elipse gradiente, no espaço de coordenadas do pincel|  
|[CD2DRadialGradientBrush::SetRadiusY](#setradiusy)|Especifica o raio de y da elipse gradiente, no espaço de coordenadas do pincel|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRadialGradientBrush::Operator ID2D1RadialGradientBrush *](#operator_id2d1radialgradientbrush_star)|Interface de ID2D1RadialGradientBrush retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRadialGradientBrush::m_pRadialGradientBrush](#m_pradialgradientbrush)|Um ponteiro para um ID2D1RadialGradientBrush.|  
|[CD2DRadialGradientBrush::m_RadialGradientBrushProperties](#m_radialgradientbrushproperties)|O Centro de deslocamento da origem de gradiente e raios x e y raio do pincel gradação do.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
 [CD2DGradientBrush](../../mfc/reference/cd2dgradientbrush-class.md)  
  
 `CD2DRadialGradientBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dradialgradientbrush"></a>CD2DRadialGradientBrush:: ~ CD2DRadialGradientBrush  
 O destruidor. Chamado quando um objeto de pincel de gradiente radial D2D está sendo destruído.  
  
```  
virtual ~CD2DRadialGradientBrush();
```  
  
##  <a name="attach"></a>CD2DRadialGradientBrush::Attach  
 Conexões existentes de interface de recursos para o objeto  
  
```  
void Attach(ID2D1RadialGradientBrush* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recursos existente. Não pode ser nulo  
  
##  <a name="cd2dradialgradientbrush"></a>CD2DRadialGradientBrush::CD2DRadialGradientBrush  
 Constrói um objeto CD2DLinearGradientBrush.  
  
```  
CD2DRadialGradientBrush(
    CRenderTarget* pParentTarget,  
    const D2D1_GRADIENT_STOP* gradientStops,  
    UINT gradientStopsCount,  
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES RadialGradientBrushProperties,  
    D2D1_GAMMA colorInterpolationGamma = D2D1_GAMMA_2_2,  
    D2D1_EXTEND_MODE extendMode = D2D1_EXTEND_MODE_CLAMP,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `gradientStops`  
 Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.  
  
 `gradientStopsCount`  
 Um valor maior que ou igual a 1 que especifica o número de paradas de gradiente na matriz gradientStops.  
  
 `RadialGradientBrushProperties`  
 O Centro de deslocamento da origem de gradiente e raios x e y raio do pincel gradação do.  
  
 `colorInterpolationGamma`  
 O espaço no qual cor interpolação entre as paradas de gradiente é executada.  
  
 `extendMode`  
 O comportamento do gradiente fora do intervalo [0,1] de normalizado.  
  
 `pBrushProperties`  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 `bAutoDestroy`  
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>CD2DRadialGradientBrush::Create  
 Cria um CD2DRadialGradientBrush.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>CD2DRadialGradientBrush::Destroy  
 Destrói um objeto CD2DRadialGradientBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>CD2DRadialGradientBrush::Detach  
 Desconecta a interface do recurso do objeto  
  
```  
ID2D1RadialGradientBrush* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para interface de recursos separado.  
  
##  <a name="get"></a>CD2DRadialGradientBrush::Get  
 Interface de ID2D1RadialGradientBrush retorna  
  
```  
ID2D1RadialGradientBrush* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1RadialGradientBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getcenter"></a>CD2DRadialGradientBrush::GetCenter  
 Recupera o centro da elipse gradiente  
  
```  
CD2DPointF GetCenter() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O centro da elipse gradiente. Esse valor é expresso no espaço de coordenadas do pincel  
  
##  <a name="getgradientoriginoffset"></a>CD2DRadialGradientBrush::GetGradientOriginOffset  
 Recupera o deslocamento da origem gradiente em relação ao centro da elipse gradiente  
  
```  
CD2DPointF GetGradientOriginOffset() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O deslocamento da origem da gradação do centro da elipse gradiente. Esse valor é expresso no espaço de coordenadas do pincel  
  
##  <a name="getradiusx"></a>CD2DRadialGradientBrush::GetRadiusX  
 Recupera o raio-x da elipse gradiente  
  
```  
FLOAT GetRadiusX() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O raio x da elipse gradiente. Esse valor é expresso no espaço de coordenadas do pincel  
  
##  <a name="getradiusy"></a>CD2DRadialGradientBrush::GetRadiusY  
 Recupera o raio de y da elipse gradiente  
  
```  
FLOAT GetRadiusY() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O raio y da elipse gradiente. Esse valor é expresso no espaço de coordenadas do pincel  
  
##  <a name="m_pradialgradientbrush"></a>CD2DRadialGradientBrush::m_pRadialGradientBrush  
 Um ponteiro para um ID2D1RadialGradientBrush.  
  
```  
ID2D1RadialGradientBrush* m_pRadialGradientBrush;  
```  
  
##  <a name="m_radialgradientbrushproperties"></a>CD2DRadialGradientBrush::m_RadialGradientBrushProperties  
 O Centro de deslocamento da origem de gradiente e raios x e y raio do pincel gradação do.  
  
```  
D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES m_RadialGradientBrushProperties;  
```  
  
##  <a name="operator_id2d1radialgradientbrush_star"></a>CD2DRadialGradientBrush::Operator ID2D1RadialGradientBrush *  
 Interface de ID2D1RadialGradientBrush retorna  
  
```  
operator ID2D1RadialGradientBrush*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1RadialGradientBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="setcenter"></a>CD2DRadialGradientBrush::SetCenter  
 Especifica o centro da elipse gradiente no espaço de coordenadas do pincel  
  
```  
void SetCenter(CD2DPointF point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 O centro da elipse gradiente, no espaço de coordenadas do pincel  
  
##  <a name="setgradientoriginoffset"></a>CD2DRadialGradientBrush::SetGradientOriginOffset  
 Especifica o deslocamento da origem gradiente em relação ao centro da elipse gradiente  
  
```  
void SetGradientOriginOffset(CD2DPointF gradientOriginOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 `gradientOriginOffset`  
 O deslocamento da origem da gradação do centro da elipse gradiente  
  
##  <a name="setradiusx"></a>CD2DRadialGradientBrush::SetRadiusX  
 Especifica o raio-x da elipse gradiente, no espaço de coordenadas do pincel  
  
```  
void SetRadiusX(FLOAT radiusX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `radiusX`  
 O raio x da elipse gradiente. Esse valor é no espaço de coordenadas do pincel  
  
##  <a name="setradiusy"></a>CD2DRadialGradientBrush::SetRadiusY  
 Especifica o raio de y da elipse gradiente, no espaço de coordenadas do pincel  
  
```  
void SetRadiusY(FLOAT radiusY);
```  
  
### <a name="parameters"></a>Parâmetros  
 `radiusY`  
 O raio y da elipse gradiente. Esse valor é no espaço de coordenadas do pincel  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

