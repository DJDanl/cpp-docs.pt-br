---
title: Classe CD2DLinearGradientBrush | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxrendertarget/CD2DLinearGradientBrush
- CD2DLinearGradientBrush
dev_langs:
- C++
helpviewer_keywords:
- CD2DLinearGradientBrush class
ms.assetid: d4be9ff9-0ea8-45e6-9b8d-f3bc5673cbac
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: dd288478a751d921cc4d9fcd9433e391275cee66
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dlineargradientbrush-class"></a>Classe CD2DLinearGradientBrush
Um wrapper para ID2D1LinearGradientBrush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DLinearGradientBrush : public CD2DGradientBrush;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLinearGradientBrush::CD2DLinearGradientBrush](#cd2dlineargradientbrush)|Constrói um objeto CD2DLinearGradientBrush.|  
|[CD2DLinearGradientBrush:: ~ CD2DLinearGradientBrush](#_dtorcd2dlineargradientbrush)|O destruidor. Chamado quando um objeto de pincel de gradiente linear D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLinearGradientBrush::Attach](#attach)|Conexões existentes de interface de recursos para o objeto|  
|[CD2DLinearGradientBrush::Create](#create)|Cria um CD2DLinearGradientBrush. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DLinearGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DLinearGradientBrush. (Substitui [CD2DGradientBrush::Destroy](../../mfc/reference/cd2dgradientbrush-class.md#destroy).)|  
|[CD2DLinearGradientBrush::Detach](#detach)|Desconecta a interface do recurso do objeto|  
|[CD2DLinearGradientBrush::Get](#get)|Interface de ID2D1LinearGradientBrush retorna|  
|[CD2DLinearGradientBrush::GetEndPoint](#getendpoint)|Recupera as coordenadas final do gradiente linear|  
|[CD2DLinearGradientBrush::GetStartPoint](#getstartpoint)|Recupera as coordenadas iniciais do gradiente linear|  
|[CD2DLinearGradientBrush::SetEndPoint](#setendpoint)|Define as coordenadas de final do gradiente linear no espaço de coordenadas do pincel|  
|[CD2DLinearGradientBrush::SetStartPoint](#setstartpoint)|Define as coordenadas iniciais do gradiente linear no espaço de coordenadas do pincel|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLinearGradientBrush::Operator ID2D1LinearGradientBrush *](#operator_id2d1lineargradientbrush_star)|Interface de ID2D1LinearGradientBrush retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLinearGradientBrush::m_LinearGradientBrushProperties](#m_lineargradientbrushproperties)|Os pontos inicial e final do gradiente.|  
|[CD2DLinearGradientBrush::m_pLinearGradientBrush](#m_plineargradientbrush)|Um ponteiro para um ID2D1LinearGradientBrush.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
 [CD2DGradientBrush](../../mfc/reference/cd2dgradientbrush-class.md)  
  
 `CD2DLinearGradientBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="a-namedtorcd2dlineargradientbrusha--cd2dlineargradientbrushcd2dlineargradientbrush"></a><a name="_dtorcd2dlineargradientbrush"></a>CD2DLinearGradientBrush:: ~ CD2DLinearGradientBrush  
 O destruidor. Chamado quando um objeto de pincel de gradiente linear D2D está sendo destruído.  
  
```  
virtual ~CD2DLinearGradientBrush();
```  
  
##  <a name="a-nameattacha--cd2dlineargradientbrushattach"></a><a name="attach"></a>CD2DLinearGradientBrush::Attach  
 Conexões existentes de interface de recursos para o objeto  
  
```  
void Attach(ID2D1LinearGradientBrush* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recursos existente. Não pode ser nulo  
  
##  <a name="a-namecd2dlineargradientbrusha--cd2dlineargradientbrushcd2dlineargradientbrush"></a><a name="cd2dlineargradientbrush"></a>CD2DLinearGradientBrush::CD2DLinearGradientBrush  
 Constrói um objeto CD2DLinearGradientBrush.  
  
```  
CD2DLinearGradientBrush(
    CRenderTarget* pParentTarget,  
    const D2D1_GRADIENT_STOP* gradientStops,  
    UINT gradientStopsCount,  
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES LinearGradientBrushProperties,  
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
  
 `LinearGradientBrushProperties`  
 Os pontos inicial e final do gradiente.  
  
 `colorInterpolationGamma`  
 O espaço no qual cor interpolação entre as paradas de gradiente é executada.  
  
 `extendMode`  
 O comportamento do gradiente fora do intervalo [0,1] de normalizado.  
  
 `pBrushProperties`  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 `bAutoDestroy`  
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="a-namecreatea--cd2dlineargradientbrushcreate"></a><a name="create"></a>CD2DLinearGradientBrush::Create  
 Cria um CD2DLinearGradientBrush.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="a-namedestroya--cd2dlineargradientbrushdestroy"></a><a name="destroy"></a>CD2DLinearGradientBrush::Destroy  
 Destrói um objeto CD2DLinearGradientBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="a-namedetacha--cd2dlineargradientbrushdetach"></a><a name="detach"></a>CD2DLinearGradientBrush::Detach  
 Desconecta a interface do recurso do objeto  
  
```  
ID2D1LinearGradientBrush* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para interface de recursos separado.  
  
##  <a name="a-namegeta--cd2dlineargradientbrushget"></a><a name="get"></a>CD2DLinearGradientBrush::Get  
 Interface de ID2D1LinearGradientBrush retorna  
  
```  
ID2D1LinearGradientBrush* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1LinearGradientBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namegetendpointa--cd2dlineargradientbrushgetendpoint"></a><a name="getendpoint"></a>CD2DLinearGradientBrush::GetEndPoint  
 Recupera as coordenadas final do gradiente linear  
  
```  
CD2DPointF GetEndPoint() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas bidimensionais final do gradiente linear, no espaço de coordenadas do pincel  
  
##  <a name="a-namegetstartpointa--cd2dlineargradientbrushgetstartpoint"></a><a name="getstartpoint"></a>CD2DLinearGradientBrush::GetStartPoint  
 Recupera as coordenadas iniciais do gradiente linear  
  
```  
CD2DPointF GetStartPoint() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas bidimensionais partidas do gradiente linear, no espaço de coordenadas do pincel  
  
##  <a name="a-namemlineargradientbrushpropertiesa--cd2dlineargradientbrushmlineargradientbrushproperties"></a><a name="m_lineargradientbrushproperties"></a>CD2DLinearGradientBrush::m_LinearGradientBrushProperties  
 Os pontos inicial e final do gradiente.  
  
```  
D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES m_LinearGradientBrushProperties;  
```  
  
##  <a name="a-namemplineargradientbrusha--cd2dlineargradientbrushmplineargradientbrush"></a><a name="m_plineargradientbrush"></a>CD2DLinearGradientBrush::m_pLinearGradientBrush  
 Um ponteiro para um ID2D1LinearGradientBrush.  
  
```  
ID2D1LinearGradientBrush* m_pLinearGradientBrush;  
```  
  
##  <a name="a-nameoperatorid2d1lineargradientbrushstara--cd2dlineargradientbrushoperator-id2d1lineargradientbrush"></a><a name="operator_id2d1lineargradientbrush_star"></a>CD2DLinearGradientBrush::Operator ID2D1LinearGradientBrush *  
 Interface de ID2D1LinearGradientBrush retorna  
  
```  
operator ID2D1LinearGradientBrush*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1LinearGradientBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namesetendpointa--cd2dlineargradientbrushsetendpoint"></a><a name="setendpoint"></a>CD2DLinearGradientBrush::SetEndPoint  
 Define as coordenadas de final do gradiente linear no espaço de coordenadas do pincel  
  
```  
void SetEndPoint(CD2DPointF point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 As coordenadas bidimensionais final do gradiente linear, no espaço de coordenadas do pincel  
  
##  <a name="a-namesetstartpointa--cd2dlineargradientbrushsetstartpoint"></a><a name="setstartpoint"></a>CD2DLinearGradientBrush::SetStartPoint  
 Define as coordenadas iniciais do gradiente linear no espaço de coordenadas do pincel  
  
```  
void SetStartPoint(CD2DPointF point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 As coordenadas bidimensionais partidas do gradiente linear, no espaço de coordenadas do pincel  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

