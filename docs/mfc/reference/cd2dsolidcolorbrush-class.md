---
title: Classe CD2DSolidColorBrush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DSolidColorBrush
- AFXRENDERTARGET/CD2DSolidColorBrush
- AFXRENDERTARGET/CD2DSolidColorBrush::CD2DSolidColorBrush
- AFXRENDERTARGET/CD2DSolidColorBrush::Attach
- AFXRENDERTARGET/CD2DSolidColorBrush::Create
- AFXRENDERTARGET/CD2DSolidColorBrush::Destroy
- AFXRENDERTARGET/CD2DSolidColorBrush::Detach
- AFXRENDERTARGET/CD2DSolidColorBrush::Get
- AFXRENDERTARGET/CD2DSolidColorBrush::GetColor
- AFXRENDERTARGET/CD2DSolidColorBrush::SetColor
- AFXRENDERTARGET/CD2DSolidColorBrush::m_colorSolid
- AFXRENDERTARGET/CD2DSolidColorBrush::m_pSolidColorBrush
dev_langs:
- C++
helpviewer_keywords:
- CD2DSolidColorBrush [MFC], CD2DSolidColorBrush
- CD2DSolidColorBrush [MFC], Attach
- CD2DSolidColorBrush [MFC], Create
- CD2DSolidColorBrush [MFC], Destroy
- CD2DSolidColorBrush [MFC], Detach
- CD2DSolidColorBrush [MFC], Get
- CD2DSolidColorBrush [MFC], GetColor
- CD2DSolidColorBrush [MFC], SetColor
- CD2DSolidColorBrush [MFC], m_colorSolid
- CD2DSolidColorBrush [MFC], m_pSolidColorBrush
ms.assetid: d4506637-acce-4f74-8a9b-f0a45571a735
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9cf3f78624761b364bf192876cb8368c73507e86
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951569"
---
# <a name="cd2dsolidcolorbrush-class"></a>Classe CD2DSolidColorBrush
Um wrapper para ID2D1SolidColorBrush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DSolidColorBrush : public CD2DBrush;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSolidColorBrush::CD2DSolidColorBrush](#cd2dsolidcolorbrush)|Sobrecarregado. Constrói um objeto CD2DSolidColorBrush.|  
|[CD2DSolidColorBrush:: ~ CD2DSolidColorBrush](#cd2dsolidcolorbrush__~cd2dsolidcolorbrush)|O destruidor. Chamado quando um objeto de pincel sólido D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSolidColorBrush::Attach](#attach)|Conexões existentes de interface de recurso para o objeto|  
|[CD2DSolidColorBrush::Create](#create)|Cria um CD2DSolidColorBrush. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DSolidColorBrush::Destroy](#destroy)|Destrói um objeto CD2DSolidColorBrush. (Substitui [CD2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|  
|[CD2DSolidColorBrush::Detach](#detach)|Desanexa a interface do recurso do objeto|  
|[CD2DSolidColorBrush::Get](#get)|Interface de ID2D1SolidColorBrush retorna|  
|[CD2DSolidColorBrush::GetColor](#getcolor)|Recupera a cor do pincel de cor sólida|  
|[CD2DSolidColorBrush::SetColor](#setcolor)|Especifica a cor do pincel cor sólida|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSolidColorBrush::Operator ID2D1SolidColorBrush *](#operator_id2d1solidcolorbrush_star)|Interface de ID2D1SolidColorBrush retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSolidColorBrush::m_colorSolid](#m_colorsolid)|Pincel de cor sólida.|  
|[CD2DSolidColorBrush::m_pSolidColorBrush](#m_psolidcolorbrush)|Armazena um ponteiro para um objeto ID2D1SolidColorBrush.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
 [CD2DSolidColorBrush](../../mfc/reference/cd2dsolidcolorbrush-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dsolidcolorbrush"></a>  CD2DSolidColorBrush:: ~ CD2DSolidColorBrush  
 O destruidor. Chamado quando um objeto de pincel sólido D2D está sendo destruído.  
  
```  
virtual ~CD2DSolidColorBrush();
```  
  
##  <a name="attach"></a>  CD2DSolidColorBrush::Attach  
 Conexões existentes de interface de recurso para o objeto  
  
```  
void Attach(ID2D1SolidColorBrush* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pResource*  
 Interface de recurso existente. Não pode ser NULL  
  
##  <a name="cd2dsolidcolorbrush"></a>  CD2DSolidColorBrush::CD2DSolidColorBrush  
 Constrói um objeto CD2DSolidColorBrush.  
  
```  
CD2DSolidColorBrush(
    CRenderTarget* pParentTarget,  
    D2D1_COLOR_F color,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);

 
CD2DSolidColorBrush(
    CRenderTarget* pParentTarget,  
    COLORREF color,  
    int nAlpha = 255,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentTarget*  
 Um ponteiro para o destino de renderização.  
  
 *Cor*  
 Os valores de cor do pincel vermelhos, verdes, azuis e alfa.  
  
 *pBrushProperties*  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 *bAutoDestroy*  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
 *nAlpha*  
 A opacidade da cor do pincel.  
  
##  <a name="create"></a>  CD2DSolidColorBrush::Create  
 Cria um CD2DSolidColorBrush.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pRenderTarget*  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>  CD2DSolidColorBrush::Destroy  
 Destrói um objeto CD2DSolidColorBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>  CD2DSolidColorBrush::Detach  
 Desanexa a interface do recurso do objeto  
  
```  
ID2D1SolidColorBrush* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface de recursos separado.  
  
##  <a name="get"></a>  CD2DSolidColorBrush::Get  
 Interface de ID2D1SolidColorBrush retorna  
  
```  
ID2D1SolidColorBrush* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1SolidColorBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getcolor"></a>  CD2DSolidColorBrush::GetColor  
 Recupera a cor do pincel de cor sólida  
  
```  
D2D1_COLOR_F GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor do pincel cor sólida  
  
##  <a name="m_colorsolid"></a>  CD2DSolidColorBrush::m_colorSolid  
 Pincel de cor sólida.  
  
```  
D2D1_COLOR_F m_colorSolid;  
```  
  
##  <a name="m_psolidcolorbrush"></a>  CD2DSolidColorBrush::m_pSolidColorBrush  
 Armazena um ponteiro para um objeto ID2D1SolidColorBrush.  
  
```  
ID2D1SolidColorBrush* m_pSolidColorBrush;  
```  
  
##  <a name="operator_id2d1solidcolorbrush_star"></a>  CD2DSolidColorBrush::Operator ID2D1SolidColorBrush *  
 Interface de ID2D1SolidColorBrush retorna  
  
```  
operator ID2D1SolidColorBrush*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1SolidColorBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="setcolor"></a>  CD2DSolidColorBrush::SetColor  
 Especifica a cor do pincel cor sólida  
  
```  
void SetColor(D2D1_COLOR_F color);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Cor*  
 A cor do pincel cor sólida  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
