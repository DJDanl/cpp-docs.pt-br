---
title: Classe CD2DResource | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DResource
- AFXRENDERTARGET/CD2DResource
- AFXRENDERTARGET/CD2DResource::CD2DResource
- AFXRENDERTARGET/CD2DResource::Create
- AFXRENDERTARGET/CD2DResource::Destroy
- AFXRENDERTARGET/CD2DResource::IsValid
- AFXRENDERTARGET/CD2DResource::IsAutoDestroy
- AFXRENDERTARGET/CD2DResource::ReCreate
- AFXRENDERTARGET/CD2DResource::m_bIsAutoDestroy
- AFXRENDERTARGET/CD2DResource::m_pParentTarget
dev_langs:
- C++
helpviewer_keywords:
- CD2DResource [MFC], CD2DResource
- CD2DResource [MFC], Create
- CD2DResource [MFC], Destroy
- CD2DResource [MFC], IsValid
- CD2DResource [MFC], IsAutoDestroy
- CD2DResource [MFC], ReCreate
- CD2DResource [MFC], m_bIsAutoDestroy
- CD2DResource [MFC], m_pParentTarget
ms.assetid: 34e3ee18-aab6-4c39-9294-de869e1f7820
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eed5b60954d05094db610a233968c9c7dd83c704
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33350935"
---
# <a name="cd2dresource-class"></a>Classe CD2DResource
Uma classe abstrata que fornece uma interface para criar e gerenciar recursos D2D como pincéis, camadas e textos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DResource : public CObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DResource::CD2DResource](#cd2dresource)|Constrói um objeto CD2DResource.|  
|[CD2DResource:: ~ CD2DResource](#cd2dresource__~cd2dresource)|O destruidor. Chamado quando um objeto de recursos D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DResource::Create](#create)|Cria um CD2DResource.|  
|[CD2DResource::Destroy](#destroy)|Destrói um objeto CD2DResource.|  
|[CD2DResource::IsValid](#isvalid)|Verificações de validade de recurso|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DResource::IsAutoDestroy](#isautodestroy)|Seleção automática destruir sinalizador.|  
|[CD2DResource::ReCreate](#recreate)|Recria um CD2DResource.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DResource::m_bIsAutoDestroy](#m_bisautodestroy)|Recurso será destoyed pelo proprietário (CRenderTarget)|  
|[CD2DResource::m_pParentTarget](#m_pparenttarget)|Ponteiro para o pai CRenderTarget)|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CD2DResource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dresource"></a>  CD2DResource:: ~ CD2DResource  
 O destruidor. Chamado quando um objeto de recursos D2D está sendo destruído.  
  
```  
virtual ~CD2DResource();
```  
  
##  <a name="cd2dresource"></a>  CD2DResource::CD2DResource  
 Constrói um objeto CD2DResource.  
  
```  
CD2DResource(
    CRenderTarget* pParentTarget,  
    BOOL bAutoDestroy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `bAutoDestroy`  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>  CD2DResource::Create  
 Cria um CD2DResource.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>  CD2DResource::Destroy  
 Destrói um objeto CD2DResource.  
  
```  
virtual void Destroy() = 0;  
```  
  
##  <a name="isautodestroy"></a>  CD2DResource::IsAutoDestroy  
 Seleção automática destruir sinalizador.  
  
```  
BOOL IsAutoDestroy() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o objeto será destruído por seu proprietário; Caso contrário, FALSE.  
  
##  <a name="isvalid"></a>  CD2DResource::IsValid  
 Verificações de validade de recurso  
  
```  
virtual BOOL IsValid() const = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="m_bisautodestroy"></a>  CD2DResource::m_bIsAutoDestroy  
 Recurso será destoyed pelo proprietário (CRenderTarget)  
  
```  
BOOL m_bIsAutoDestroy;  
```  
  
##  <a name="m_pparenttarget"></a>  CD2DResource::m_pParentTarget  
 Ponteiro para o pai CRenderTarget)  
  
```  
CRenderTarget* m_pParentTarget;  
```  
  
##  <a name="recreate"></a>  CD2DResource::ReCreate  
 Recria um CD2DResource.  
  
```  
virtual HRESULT ReCreate(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
