---
title: Classe CD2DResource | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxrendertarget/CD2DResource
- CD2DResource
dev_langs:
- C++
helpviewer_keywords:
- CD2DResource class
ms.assetid: 34e3ee18-aab6-4c39-9294-de869e1f7820
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b5a357a3653e2126de85b21efddca881c6c43a09
ms.lasthandoff: 02/25/2017

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
|[CD2DResource:: ~ CD2DResource](#cd2dresource__~cd2dresource)|O destruidor. Chamado quando um objeto de recurso D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DResource::Create](#create)|Cria um CD2DResource.|  
|[CD2DResource::Destroy](#destroy)|Destrói um objeto CD2DResource.|  
|[CD2DResource::IsValid](#isvalid)|Verificações de validade de recursos|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DResource::IsAutoDestroy](#isautodestroy)|Seleção automática destruir o sinalizador.|  
|[CD2DResource::ReCreate](#recreate)|Cria um CD2DResource novamente.|  
  
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
  
##  <a name="a-namedtorcd2dresourcea--cd2dresourcecd2dresource"></a><a name="_dtorcd2dresource"></a>CD2DResource:: ~ CD2DResource  
 O destruidor. Chamado quando um objeto de recurso D2D está sendo destruído.  
  
```  
virtual ~CD2DResource();
```  
  
##  <a name="a-namecd2dresourcea--cd2dresourcecd2dresource"></a><a name="cd2dresource"></a>CD2DResource::CD2DResource  
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
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="a-namecreatea--cd2dresourcecreate"></a><a name="create"></a>CD2DResource::Create  
 Cria um CD2DResource.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="a-namedestroya--cd2dresourcedestroy"></a><a name="destroy"></a>CD2DResource::Destroy  
 Destrói um objeto CD2DResource.  
  
```  
virtual void Destroy() = 0;  
```  
  
##  <a name="a-nameisautodestroya--cd2dresourceisautodestroy"></a><a name="isautodestroy"></a>CD2DResource::IsAutoDestroy  
 Seleção automática destruir o sinalizador.  
  
```  
BOOL IsAutoDestroy() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o objeto será destruído pelo seu proprietário; Caso contrário, FALSE.  
  
##  <a name="a-nameisvalida--cd2dresourceisvalid"></a><a name="isvalid"></a>CD2DResource::IsValid  
 Verificações de validade de recursos  
  
```  
virtual BOOL IsValid() const = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="a-namembisautodestroya--cd2dresourcembisautodestroy"></a><a name="m_bisautodestroy"></a>CD2DResource::m_bIsAutoDestroy  
 Recurso será destoyed pelo proprietário (CRenderTarget)  
  
```  
BOOL m_bIsAutoDestroy;  
```  
  
##  <a name="a-namempparenttargeta--cd2dresourcempparenttarget"></a><a name="m_pparenttarget"></a>CD2DResource::m_pParentTarget  
 Ponteiro para o pai CRenderTarget)  
  
```  
CRenderTarget* m_pParentTarget;  
```  
  
##  <a name="a-namerecreatea--cd2dresourcerecreate"></a><a name="recreate"></a>CD2DResource::ReCreate  
 Cria um CD2DResource novamente.  
  
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

