---
title: Classe CD2DBitmapBrush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush::CD2DBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush::Attach
- AFXRENDERTARGET/CD2DBitmapBrush::Create
- AFXRENDERTARGET/CD2DBitmapBrush::Destroy
- AFXRENDERTARGET/CD2DBitmapBrush::Detach
- AFXRENDERTARGET/CD2DBitmapBrush::Get
- AFXRENDERTARGET/CD2DBitmapBrush::GetBitmap
- AFXRENDERTARGET/CD2DBitmapBrush::GetExtendModeX
- AFXRENDERTARGET/CD2DBitmapBrush::GetExtendModeY
- AFXRENDERTARGET/CD2DBitmapBrush::GetInterpolationMode
- AFXRENDERTARGET/CD2DBitmapBrush::SetBitmap
- AFXRENDERTARGET/CD2DBitmapBrush::SetExtendModeX
- AFXRENDERTARGET/CD2DBitmapBrush::SetExtendModeY
- AFXRENDERTARGET/CD2DBitmapBrush::SetInterpolationMode
- AFXRENDERTARGET/CD2DBitmapBrush::CommonInit
- AFXRENDERTARGET/CD2DBitmapBrush::m_pBitmap
- AFXRENDERTARGET/CD2DBitmapBrush::m_pBitmapBrush
- AFXRENDERTARGET/CD2DBitmapBrush::m_pBitmapBrushProperties
dev_langs:
- C++
helpviewer_keywords:
- CD2DBitmapBrush [MFC], CD2DBitmapBrush
- CD2DBitmapBrush [MFC], Attach
- CD2DBitmapBrush [MFC], Create
- CD2DBitmapBrush [MFC], Destroy
- CD2DBitmapBrush [MFC], Detach
- CD2DBitmapBrush [MFC], Get
- CD2DBitmapBrush [MFC], GetBitmap
- CD2DBitmapBrush [MFC], GetExtendModeX
- CD2DBitmapBrush [MFC], GetExtendModeY
- CD2DBitmapBrush [MFC], GetInterpolationMode
- CD2DBitmapBrush [MFC], SetBitmap
- CD2DBitmapBrush [MFC], SetExtendModeX
- CD2DBitmapBrush [MFC], SetExtendModeY
- CD2DBitmapBrush [MFC], SetInterpolationMode
- CD2DBitmapBrush [MFC], CommonInit
- CD2DBitmapBrush [MFC], m_pBitmap
- CD2DBitmapBrush [MFC], m_pBitmapBrush
- CD2DBitmapBrush [MFC], m_pBitmapBrushProperties
ms.assetid: 46ebbe34-66e0-44c8-af1d-d129e851de5e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d8fb0833fc82895f1f32fb5c93a6e6519bfe119c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cd2dbitmapbrush-class"></a>Classe CD2DBitmapBrush
Um wrapper para ID2D1BitmapBrush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DBitmapBrush : public CD2DBrush;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBitmapBrush::CD2DBitmapBrush](#cd2dbitmapbrush)|Sobrecarregado. Constrói um objeto CD2DBitmapBrush do arquivo.|  
|[CD2DBitmapBrush:: ~ CD2DBitmapBrush](#dtor)|O destruidor. Chamado quando um objeto de pincel D2D bitmap está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBitmapBrush::Attach](#attach)|Conexões existentes de interface de recurso para o objeto|  
|[CD2DBitmapBrush::Create](#create)|Cria um CD2DBitmapBrush. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DBitmapBrush::Destroy](#destroy)|Destrói um objeto CD2DBitmapBrush. (Substitui [CD2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|  
|[CD2DBitmapBrush::Detach](#detach)|Desanexa a interface do recurso do objeto|  
|[CD2DBitmapBrush::Get](#get)|Interface de ID2D1BitmapBrush retorna|  
|[CD2DBitmapBrush::GetBitmap](#getbitmap)|Obtém a fonte de bitmap que usa esse pincel para desenhar|  
|[CD2DBitmapBrush::GetExtendModeX](#getextendmodex)|Obtém o método pelo qual o pincel blocos horizontalmente as áreas que vão além de bitmap|  
|[CD2DBitmapBrush::GetExtendModeY](#getextendmodey)|Obtém o método pelo qual o pincel blocos verticalmente as áreas que vão além de bitmap|  
|[CD2DBitmapBrush::GetInterpolationMode](#getinterpolationmode)|Obtém o método de interpolação usado quando o bitmap de pincel é dimensionado ou girado|  
|[CD2DBitmapBrush::SetBitmap](#setbitmap)|Especifica a fonte de bitmap que usa esse pincel para desenhar|  
|[CD2DBitmapBrush::SetExtendModeX](#setextendmodex)|Especifica como o pincel blocos horizontalmente as áreas que vão além de bitmap|  
|[CD2DBitmapBrush::SetExtendModeY](#setextendmodey)|Especifica como o pincel blocos verticalmente as áreas que vão além de bitmap|  
|[CD2DBitmapBrush::SetInterpolationMode](#setinterpolationmode)|Especifica o modo de interpolação usado quando o bitmap de pincel é dimensionado ou girado|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBitmapBrush::CommonInit](#commoninit)|Inicializa o objeto|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBitmapBrush::Operator ID2D1BitmapBrush *](#operator_id2d1bitmapbrush_star)|Interface de ID2D1BitmapBrush retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBitmapBrush::m_pBitmap](#m_pbitmap)|Armazena um ponteiro para um objeto CD2DBitmap.|  
|[CD2DBitmapBrush::m_pBitmapBrush](#m_pbitmapbrush)|Armazena um ponteiro para um objeto ID2D1BitmapBrush.|  
|[CD2DBitmapBrush::m_pBitmapBrushProperties](#m_pbitmapbrushproperties)|Propriedades do pincel de bitmap.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
 `CD2DBitmapBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="dtor"></a>  CD2DBitmapBrush:: ~ CD2DBitmapBrush  
 O destruidor. Chamado quando um objeto de pincel D2D bitmap está sendo destruído.  
  
```  
virtual ~CD2DBitmapBrush();
```  
  
##  <a name="attach"></a>  CD2DBitmapBrush::Attach  
 Conexões existentes de interface de recurso para o objeto  
  
```  
void Attach(ID2D1BitmapBrush* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recurso existente. Não pode ser NULL  
  
##  <a name="cd2dbitmapbrush"></a>  CD2DBitmapBrush::CD2DBitmapBrush  
 Constrói um objeto CD2DBitmapBrush.  
  
```  
CD2DBitmapBrush(
    CRenderTarget* pParentTarget,  
    D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties = NULL,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);

 
CD2DBitmapBrush(
    CRenderTarget* pParentTarget,  
    UINT uiResID,  
    LPCTSTR lpszType = NULL,  
    CD2DSizeU sizeDest = CD2DSizeU(0, 0), 
    D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties = NULL,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);

 
CD2DBitmapBrush(
    CRenderTarget* pParentTarget,  
    LPCTSTR lpszImagePath,  
    CD2DSizeU sizeDest = CD2DSizeU(0, 0), 
    D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties = NULL,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `pBitmapBrushProperties`  
 Um ponteiro para os modos de estender e o modo de interpolação de um pincel de bitmap.  
  
 `pBrushProperties`  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 `bAutoDestroy`  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
 `uiResID`  
 O número de identificação de recurso do recurso.  
  
 `lpszType`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o tipo de recurso.  
  
 `sizeDest`  
 Tamanho do destino do bitmap.  
  
 `lpszImagePath`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo.  
  
##  <a name="commoninit"></a>  CD2DBitmapBrush::CommonInit  
 Inicializa o objeto  
  
```  
void CommonInit(D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBitmapBrushProperties`  
 Um ponteiro para as propriedades de pincel de bitmap.  
  
##  <a name="create"></a>  CD2DBitmapBrush::Create  
 Cria um CD2DBitmapBrush.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>  CD2DBitmapBrush::Destroy  
 Destrói um objeto CD2DBitmapBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>  CD2DBitmapBrush::Detach  
 Desanexa a interface do recurso do objeto  
  
```  
ID2D1BitmapBrush* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface de recursos separado.  
  
##  <a name="get"></a>  CD2DBitmapBrush::Get  
 Interface de ID2D1BitmapBrush retorna  
  
```  
ID2D1BitmapBrush* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1BitmapBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getbitmap"></a>  CD2DBitmapBrush::GetBitmap  
 Obtém a fonte de bitmap que usa esse pincel para desenhar  
  
```  
CD2DBitmap* GetBitmap();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um objeto de CD2DBitmap ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getextendmodex"></a>  CD2DBitmapBrush::GetExtendModeX  
 Obtém o método pelo qual o pincel blocos horizontalmente as áreas que vão além de bitmap  
  
```  
D2D1_EXTEND_MODE GetExtendModeX() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que especifica como o pincel blocos horizontalmente as áreas que vão além de bitmap  
  
##  <a name="getextendmodey"></a>  CD2DBitmapBrush::GetExtendModeY  
 Obtém o método pelo qual o pincel blocos verticalmente as áreas que vão além de bitmap  
  
```  
D2D1_EXTEND_MODE GetExtendModeY() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que especifica como o pincel blocos verticalmente as áreas que vão além de bitmap  
  
##  <a name="getinterpolationmode"></a>  CD2DBitmapBrush::GetInterpolationMode  
 Obtém o método de interpolação usado quando o bitmap de pincel é dimensionado ou girado  
  
```  
D2D1_BITMAP_INTERPOLATION_MODE GetInterpolationMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O método de interpolação usado quando o bitmap de pincel é dimensionado ou girado  
  
##  <a name="m_pbitmap"></a>  CD2DBitmapBrush::m_pBitmap  
 Armazena um ponteiro para um objeto CD2DBitmap.  
  
```  
CD2DBitmap* m_pBitmap;  
```  
  
##  <a name="m_pbitmapbrush"></a>  CD2DBitmapBrush::m_pBitmapBrush  
 Armazena um ponteiro para um objeto ID2D1BitmapBrush.  
  
```  
ID2D1BitmapBrush* m_pBitmapBrush;  
```  
  
##  <a name="m_pbitmapbrushproperties"></a>  CD2DBitmapBrush::m_pBitmapBrushProperties  
 Propriedades do pincel de bitmap.  
  
```  
D2D1_BITMAP_BRUSH_PROPERTIES* m_pBitmapBrushProperties;  
```  
  
##  <a name="operator_id2d1bitmapbrush_star"></a>  CD2DBitmapBrush::Operator ID2D1BitmapBrush *  
 Interface de ID2D1BitmapBrush retorna  
  
```  
operator ID2D1BitmapBrush*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1BitmapBrush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="setbitmap"></a>  CD2DBitmapBrush::SetBitmap  
 Especifica a fonte de bitmap que usa esse pincel para desenhar  
  
```  
void SetBitmap(CD2DBitmap* pBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBitmap`  
 A fonte de bitmap usada por pincel  
  
##  <a name="setextendmodex"></a>  CD2DBitmapBrush::SetExtendModeX  
 Especifica como o pincel blocos horizontalmente as áreas que vão além de bitmap  
  
```  
void SetExtendModeX(D2D1_EXTEND_MODE extendModeX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `extendModeX`  
 Um valor que especifica como o pincel blocos horizontalmente as áreas que vão além de bitmap  
  
##  <a name="setextendmodey"></a>  CD2DBitmapBrush::SetExtendModeY  
 Especifica como o pincel blocos verticalmente as áreas que vão além de bitmap  
  
```  
void SetExtendModeY(D2D1_EXTEND_MODE extendModeY);
```  
  
### <a name="parameters"></a>Parâmetros  
 `extendModeY`  
 Um valor que especifica como o pincel blocos verticalmente as áreas que vão além de bitmap  
  
##  <a name="setinterpolationmode"></a>  CD2DBitmapBrush::SetInterpolationMode  
 Especifica o modo de interpolação usado quando o bitmap de pincel é dimensionado ou girado  
  
```  
void SetInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE interpolationMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `interpolationMode`  
 O modo de interpolação usado quando o bitmap de pincel é dimensionado ou girado  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
