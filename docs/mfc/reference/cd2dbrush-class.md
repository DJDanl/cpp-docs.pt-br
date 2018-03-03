---
title: Classe CD2DBrush | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DBrush
- AFXRENDERTARGET/CD2DBrush
- AFXRENDERTARGET/CD2DBrush::CD2DBrush
- AFXRENDERTARGET/CD2DBrush::Attach
- AFXRENDERTARGET/CD2DBrush::Destroy
- AFXRENDERTARGET/CD2DBrush::Detach
- AFXRENDERTARGET/CD2DBrush::Get
- AFXRENDERTARGET/CD2DBrush::GetOpacity
- AFXRENDERTARGET/CD2DBrush::GetTransform
- AFXRENDERTARGET/CD2DBrush::IsValid
- AFXRENDERTARGET/CD2DBrush::SetOpacity
- AFXRENDERTARGET/CD2DBrush::SetTransform
- AFXRENDERTARGET/CD2DBrush::m_pBrush
- AFXRENDERTARGET/CD2DBrush::m_pBrushProperties
dev_langs:
- C++
helpviewer_keywords:
- CD2DBrush [MFC], CD2DBrush
- CD2DBrush [MFC], Attach
- CD2DBrush [MFC], Destroy
- CD2DBrush [MFC], Detach
- CD2DBrush [MFC], Get
- CD2DBrush [MFC], GetOpacity
- CD2DBrush [MFC], GetTransform
- CD2DBrush [MFC], IsValid
- CD2DBrush [MFC], SetOpacity
- CD2DBrush [MFC], SetTransform
- CD2DBrush [MFC], m_pBrush
- CD2DBrush [MFC], m_pBrushProperties
ms.assetid: 0d2c0857-2261-48a8-8ee0-a88cbf08499a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aeacfecbc97942432b9bf19b23bf8a4cabe0a616
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cd2dbrush-class"></a>Classe CD2DBrush
Um wrapper para ID2D1Brush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DBrush : public CD2DResource;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBrush::CD2DBrush](#cd2dbrush)|Constrói um objeto CD2DBrush.|  
|[CD2DBrush:: ~ CD2DBrush](#_dtorcd2dbrush)|O destruidor. Chamado quando um objeto de pincel D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBrush::Attach](#attach)|Conexões existentes de interface de recurso para o objeto|  
|[CD2DBrush::Destroy](#destroy)|Destrói um objeto CD2DBrush. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|  
|[CD2DBrush::Detach](#detach)|Desanexa a interface do recurso do objeto|  
|[CD2DBrush::Get](#get)|Interface de ID2D1Brush retorna|  
|[CD2DBrush::GetOpacity](#getopacity)|Obtém o grau de opacidade desse pincel|  
|[CD2DBrush::GetTransform](#gettransform)|Obtém a transformação atual do destino de renderização|  
|[CD2DBrush::IsValid](#isvalid)|Verifica a validade do recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|  
|[CD2DBrush::SetOpacity](#setopacity)|Define o grau de opacidade desse pincel|  
|[CD2DBrush::SetTransform](#settransform)|Aplica-se a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrerem no espaço de transformados|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBrush::Operator ID2D1Brush *](#operator_id2d1brush_star)|Interface de ID2D1Brush retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DBrush::m_pBrush](#m_pbrush)|Armazena um ponteiro para um objeto ID2D1Brush.|  
|[CD2DBrush::m_pBrushProperties](#m_pbrushproperties)|Propriedades de pincel.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 `CD2DBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dbrush"></a>CD2DBrush:: ~ CD2DBrush  
 O destruidor. Chamado quando um objeto de pincel D2D está sendo destruído.  
  
```  
virtual ~CD2DBrush();
```  
  
##  <a name="attach"></a>CD2DBrush::Attach  
 Conexões existentes de interface de recurso para o objeto  
  
```  
void Attach(ID2D1Brush* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recurso existente. Não pode ser NULL  
  
##  <a name="cd2dbrush"></a>CD2DBrush::CD2DBrush  
 Constrói um objeto CD2DBrush.  
  
```  
CD2DBrush(
    CRenderTarget* pParentTarget,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `pBrushProperties`  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 `bAutoDestroy`  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="destroy"></a>CD2DBrush::Destroy  
 Destrói um objeto CD2DBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>CD2DBrush::Detach  
 Desanexa a interface do recurso do objeto  
  
```  
ID2D1Brush* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface de recursos separado.  
  
##  <a name="get"></a>CD2DBrush::Get  
 Interface de ID2D1Brush retorna  
  
```  
ID2D1Brush* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1Brush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getopacity"></a>CD2DBrush::GetOpacity  
 Obtém o grau de opacidade desse pincel  
  
```  
FLOAT GetOpacity() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor entre zero e 1 que indica a opacidade do pincel. Esse valor é um multiplicador de constante que linearmente dimensiona o valor de todos os pixels para preencher o pincel alfa. Os valores de opacidade são fixados no intervalo de 0 a 1 antes que eles são multiplicados juntos  
  
##  <a name="gettransform"></a>CD2DBrush::GetTransform  
 Obtém a transformação atual do destino de renderização  
  
```  
void GetTransform(D2D1_MATRIX_3X2_F* transform) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `transform`  
 Quando isso retorna, contém a transformação atual do destino de renderização. Esse parâmetro é passado não inicializado  
  
##  <a name="isvalid"></a>CD2DBrush::IsValid  
 Verificações de validade de recurso  
  
```  
virtual BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="m_pbrush"></a>CD2DBrush::m_pBrush  
 Armazena um ponteiro para um objeto ID2D1Brush.  
  
```  
ID2D1Brush* m_pBrush;  
```  
  
##  <a name="m_pbrushproperties"></a>CD2DBrush::m_pBrushProperties  
 Propriedades de pincel.  
  
```  
CD2DBrushProperties* m_pBrushProperties;  
```  
  
##  <a name="operator_id2d1brush_star"></a>CD2DBrush::Operator ID2D1Brush *  
 Interface de ID2D1Brush retorna  
  
```  
operator ID2D1Brush*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1Brush ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="setopacity"></a>CD2DBrush::SetOpacity  
 Define o grau de opacidade desse pincel  
  
```  
void SetOpacity(FLOAT opacity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `opacity`  
 Um valor entre zero e 1 que indica a opacidade do pincel. Esse valor é um multiplicador de constante que linearmente dimensiona o valor de todos os pixels para preencher o pincel alfa. Os valores de opacidade são fixados no intervalo de 0 a 1 antes que eles são multiplicados juntos  
  
##  <a name="settransform"></a>CD2DBrush::SetTransform  
 Aplica-se a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrerem no espaço de transformados  
  
```  
void SetTransform(const D2D1_MATRIX_3X2_F* transform);
```  
  
### <a name="parameters"></a>Parâmetros  
 `transform`  
 A transformação a ser aplicada para o destino de renderização  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
