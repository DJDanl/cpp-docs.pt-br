---
title: Classe CComCachedTearOffObject | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CComCachedTearOffObject
- ATL.CComCachedTearOffObject
- ATL.CComCachedTearOffObject<contained>
- CComCachedTearOffObject
- ATL::CComCachedTearOffObject<contained>
dev_langs:
- C++
helpviewer_keywords:
- cache, ATL cached tear-off objects
- CComCachedTearOffObject class
ms.assetid: ae19507d-a1de-4dbc-a988-da9f75a50c95
caps.latest.revision: 19
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 96f040c732c5545a9b8febb32fcb1636f0fe4a40
ms.lasthandoff: 02/25/2017

---
# <a name="ccomcachedtearoffobject-class"></a>Classe CComCachedTearOffObject
Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para uma interface destacável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template
 <class contained>
class CComCachedTearOffObject : public
    IUnknown,
public CComObjectRootEx<contained
 ::_ThreadModel::ThreadModelNoCS>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `contained`  
 A classe destacável derivada da `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacável para dar suporte.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCachedTearOffObject::CComCachedTearOffObject](#ccomcachedtearoffobject)|O construtor.|  
|[CComCachedTearOffObject:: ~ CComCachedTearOffObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCachedTearOffObject::AddRef](#addref)|Incrementa a contagem de referência para um `CComCachedTearOffObject` objeto.|  
|[CComCachedTearOffObject::FinalConstruct](#finalconstruct)|Chama o `m_contained::FinalConstruct` (o destacável método da classe).|  
|[CComCachedTearOffObject::FinalRelease](#finalrelease)|Chama o `m_contained::FinalRelease` (o destacável método da classe).|  
|[CComCachedTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para o `IUnknown` do `CComCachedTearOffObject` objeto, ou para a interface solicitada em sua classe destacável (classe `contained`).|  
|[CComCachedTearOffObject::Release](#release)|Diminui a contagem de referência para um `CComCachedTearOffObject` do objeto e destrói-se a contagem de referência é 0.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCachedTearOffObject::m_contained](#m_contained)|A `CComContainedObject` objeto derivado da classe destacável (classe `contained`).|  
  
## <a name="remarks"></a>Comentários  
 `CComCachedTearOffObject`implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para uma interface destacável. Essa classe é diferente do `CComTearOffObject` que `CComCachedTearOffObject` tem seu próprio **IUnknown**separado do objeto proprietário **IUnknown** (o proprietário é o objeto para o qual o destacável está sendo criado). `CComCachedTearOffObject`mantém sua própria referência contagem em seu **IUnknown** e é excluída depois que sua contagem de referência é zero. No entanto, se você consultar qualquer uma das sua destacável interfaces, a contagem de referência de objeto do proprietário **IUnknown** será incrementado.  
  
 Se o `CComCachedTearOffObject` implementar o destacável já é instanciada e a interface destacável é consultada para novamente, o mesmo objeto `CComCachedTearOffObject` objeto é reutilizado. Por outro lado, se uma interface destacável implementado por um `CComTearOffObject` é consultado novamente para por meio do objeto proprietário, outro `CComTearOffObject` será instanciado.  
  
 A classe do proprietário deve implementar `FinalRelease` e chamar **versão** em cache no **IUnknown** para o `CComCachedTearOffObject`, que irá diminuir sua contagem de referência. Isso fará com que `CComCachedTearOffObject`do `FinalRelease` para ser chamado e excluir o destacável.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComCachedTearOffObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-nameaddrefa--ccomcachedtearoffobjectaddref"></a><a name="addref"></a>CComCachedTearOffObject::AddRef  
 Incrementa a contagem de referência da `CComCachedTearOffObject` objeto por 1.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico e teste.  
  
##  <a name="a-nameccomcachedtearoffobjecta--ccomcachedtearoffobjectccomcachedtearoffobject"></a><a name="ccomcachedtearoffobject"></a>CComCachedTearOffObject::CComCachedTearOffObject  
 O construtor.  
  
```
CComCachedTearOffObject(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 [in] Ponteiro para o **IUnknown** do `CComCachedTearOffObject`.  
  
### <a name="remarks"></a>Comentários  
 Inicializa o `CComContainedObject` membro, [m_contained](#m_contained).  
  
##  <a name="a-namedtora--ccomcachedtearoffobjectccomcachedtearoffobject"></a><a name="dtor"></a>CComCachedTearOffObject:: ~ CComCachedTearOffObject  
 O destruidor.  
  
```
~CComCachedTearOffObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados e chamadas [FinalRelease](#finalrelease).  
  
##  <a name="a-namefinalconstructa--ccomcachedtearoffobjectfinalconstruct"></a><a name="finalconstruct"></a>CComCachedTearOffObject::FinalConstruct  
 Chamadas **m_contained::FinalConstruct** criar `m_contained`, o `CComContainedObject` <  `contained`> objeto usado para acessar a interface implementada pela sua classe destacável.  
  
```
HRESULT FinalConstruct();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namefinalreleasea--ccomcachedtearoffobjectfinalrelease"></a><a name="finalrelease"></a>CComCachedTearOffObject::FinalRelease  
 Chamadas **m_contained::FinalRelease** para liberar `m_contained`, o `CComContainedObject` <  `contained`> objeto.  
  
```
void FinalRelease();
```  
  
##  <a name="a-namemcontaineda--ccomcachedtearoffobjectmcontained"></a><a name="m_contained"></a>CComCachedTearOffObject::m_contained  
 A [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da classe destacável.  
  
```
CcomContainedObject <contained> m_contained;
```     
  
### <a name="parameters"></a>Parâmetros  
 `contained`  
 [in] A classe destacável derivada da `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacável para dar suporte.  
  
### <a name="remarks"></a>Comentários  
 Os métodos `m_contained` herda são usados para acessar a interface destacável em sua classe destacável através do objeto armazenado em cache destacável `QueryInterface`, `FinalConstruct`, e `FinalRelease`.  
  
##  <a name="a-namequeryinterfacea--ccomcachedtearoffobjectqueryinterface"></a><a name="queryinterface"></a>CComCachedTearOffObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] O GUID da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo `iid`, ou **nulo** se a interface não for encontrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Se a interface solicitada é **IUnknown**, retorna um ponteiro para o `CComCachedTearOffObject`do próprio **IUnknown** e incrementa a contagem de referência. Caso contrário, a consulta para a interface em sua classe destacável usando o [InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) método herdado do `CComObjectRootEx`.  

  
##  <a name="a-namereleasea--ccomcachedtearoffobjectrelease"></a><a name="release"></a>CComCachedTearOffObject::Release  
 Diminui a contagem de referência em 1 e, se a contagem de referência for 0, exclui o `CComCachedTearOffObject` objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração não, sempre retorna 0. Em compilações de depuração, retorna um valor que pode ser útil para o diagnóstico ou teste.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

