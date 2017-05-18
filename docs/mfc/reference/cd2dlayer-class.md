---
title: Classe de CD2DLayer | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DLayer
- AFXRENDERTARGET/CD2DLayer
- AFXRENDERTARGET/CD2DLayer::CD2DLayer
- AFXRENDERTARGET/CD2DLayer::Attach
- AFXRENDERTARGET/CD2DLayer::Create
- AFXRENDERTARGET/CD2DLayer::Destroy
- AFXRENDERTARGET/CD2DLayer::Detach
- AFXRENDERTARGET/CD2DLayer::Get
- AFXRENDERTARGET/CD2DLayer::GetSize
- AFXRENDERTARGET/CD2DLayer::IsValid
- AFXRENDERTARGET/CD2DLayer::m_pLayer
dev_langs:
- C++
helpviewer_keywords:
- CD2DLayer class
ms.assetid: 2f96378e-66bb-40d1-9661-6afe324de3c1
caps.latest.revision: 18
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
ms.openlocfilehash: d0034c37da7fa61c10cf6c7662ba361de8313aa0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dlayer-class"></a>Classe de CD2DLayer
Um wrapper para ID2D1Layer.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DLayer : public CD2DResource;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLayer::CD2DLayer](#cd2dlayer)|Constrói um objeto CD2DLayer.|  
|[CD2DLayer:: ~ CD2DLayer](#_dtorcd2dlayer)|O destruidor. Chamado quando um objeto de camada D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLayer::Attach](#attach)|Conexões existentes de interface de recursos para o objeto|  
|[CD2DLayer::Create](#create)|Cria um CD2DLayer. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DLayer::Destroy](#destroy)|Destrói um objeto CD2DLayer. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|  
|[CD2DLayer::Detach](#detach)|Desconecta a interface do recurso do objeto|  
|[CD2DLayer::Get](#get)|Interface de ID2D1Layer retorna|  
|[CD2DLayer::GetSize](#getsize)|Retorna o tamanho do destino de renderização em pixels independentes de dispositivo|  
|[CD2DLayer::IsValid](#isvalid)|Verifica a validade do recurso (substituições [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLayer::Operator ID2D1Layer *](#operator_id2d1layer_star)|Interface de ID2D1Layer retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DLayer::m_pLayer](#m_player)|Armazena um ponteiro para um objeto ID2D1Layer.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 `CD2DLayer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dlayer"></a>CD2DLayer:: ~ CD2DLayer  
 O destruidor. Chamado quando um objeto de camada D2D está sendo destruído.  
  
```  
virtual ~CD2DLayer();
```  
  
##  <a name="attach"></a>CD2DLayer::Attach  
 Conexões existentes de interface de recursos para o objeto  
  
```  
void Attach(ID2D1Layer* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recursos existente. Não pode ser nulo  
  
##  <a name="cd2dlayer"></a>CD2DLayer::CD2DLayer  
 Constrói um objeto CD2DLayer.  
  
```  
CD2DLayer(
    CRenderTarget* pParentTarget,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `bAutoDestroy`  
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>CD2DLayer::Create  
 Cria um CD2DLayer.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>CD2DLayer::Destroy  
 Destrói um objeto CD2DLayer.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>CD2DLayer::Detach  
 Desconecta a interface do recurso do objeto  
  
```  
ID2D1Layer* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para interface de recursos separado.  
  
##  <a name="get"></a>CD2DLayer::Get  
 Interface de ID2D1Layer retorna  
  
```  
ID2D1Layer* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1Layer ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getsize"></a>CD2DLayer::GetSize  
 Retorna o tamanho do destino de renderização em pixels independentes de dispositivo  
  
```  
CD2DSizeF GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do destino de renderização em pixels independentes de dispositivo  
  
##  <a name="isvalid"></a>CD2DLayer::IsValid  
 Verificações de validade de recursos  
  
```  
virtual BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="m_player"></a>CD2DLayer::m_pLayer  
 Armazena um ponteiro para um objeto ID2D1Layer.  
  
```  
ID2D1Layer* m_pLayer;  
```  
  
##  <a name="operator_id2d1layer_star"></a>CD2DLayer::Operator ID2D1Layer *  
 Interface de ID2D1Layer retorna  
  
```  
operator ID2D1Layer* ();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1Layer ou NULL se o objeto ainda não foi inicializado.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

