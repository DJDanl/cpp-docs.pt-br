---
title: Classe CComCachedTearOffObject | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComCachedTearOffObject
- ATLCOM/ATL::CComCachedTearOffObject
- ATLCOM/ATL::CComCachedTearOffObject::CComCachedTearOffObject
- ATLCOM/ATL::CComCachedTearOffObject::AddRef
- ATLCOM/ATL::CComCachedTearOffObject::FinalConstruct
- ATLCOM/ATL::CComCachedTearOffObject::FinalRelease
- ATLCOM/ATL::CComCachedTearOffObject::QueryInterface
- ATLCOM/ATL::CComCachedTearOffObject::Release
- ATLCOM/ATL::CComCachedTearOffObject::m_contained
dev_langs: C++
helpviewer_keywords:
- cache, ATL cached tear-off objects
- CComCachedTearOffObject class
ms.assetid: ae19507d-a1de-4dbc-a988-da9f75a50c95
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c2d8f1c7308946e7c125cbc3450b328e52236823
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
 Sua classe destacável derivado `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacável para dar suporte.  
  
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
|[CComCachedTearOffObject::FinalConstruct](#finalconstruct)|Chama o `m_contained::FinalConstruct` (método de classe destacável).|  
|[CComCachedTearOffObject::FinalRelease](#finalrelease)|Chama o `m_contained::FinalRelease` (método de classe destacável).|  
|[CComCachedTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para o `IUnknown` do `CComCachedTearOffObject` objeto, ou para a interface solicitada em sua classe destacável (a classe `contained`).|  
|[CComCachedTearOffObject::Release](#release)|Diminui a contagem de referência para um `CComCachedTearOffObject` de objeto e destrói-se a contagem de referência é 0.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCachedTearOffObject::m_contained](#m_contained)|Um `CComContainedObject` objeto derivado da classe destacável (a classe `contained`).|  
  
## <a name="remarks"></a>Comentários  
 `CComCachedTearOffObject`implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para uma interface destacável. Essa classe é diferente do `CComTearOffObject` que `CComCachedTearOffObject` tem seu próprio **IUnknown**separado do objeto proprietário **IUnknown** (o proprietário é o objeto para o qual o destacável está sendo criado). `CComCachedTearOffObject`mantém sua própria referência contagem em sua **IUnknown** e é excluída quando sua contagem de referência é zero. No entanto, se você consultar para qualquer um dos seu Destacável interfaces, a contagem de referência de objeto do proprietário **IUnknown** será incrementado.  
  
 Se o `CComCachedTearOffObject` implementar o destacável já é instanciada e a interface destacável é consultada para novamente, o mesmo objeto `CComCachedTearOffObject` objeto é reutilizado. Por outro lado, se uma interface destacável implementado por um `CComTearOffObject` é consultada novamente para através do objeto proprietário, outro `CComTearOffObject` serão instanciados.  
  
 Proprietário classe deve implementar `FinalRelease` e chame **versão** em cache no **IUnknown** para o `CComCachedTearOffObject`, que irá diminuir a contagem de referência. Isso fará com que `CComCachedTearOffObject`do `FinalRelease` para ser chamado e excluir o destacável.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComCachedTearOffObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="addref"></a>CComCachedTearOffObject::AddRef  
 Incrementa a contagem de referência de `CComCachedTearOffObject` objeto por 1.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para diagnóstico e de teste.  
  
##  <a name="ccomcachedtearoffobject"></a>CComCachedTearOffObject::CComCachedTearOffObject  
 O construtor.  
  
```
CComCachedTearOffObject(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 [in] Ponteiro para o **IUnknown** do `CComCachedTearOffObject`.  
  
### <a name="remarks"></a>Comentários  
 Inicializa o `CComContainedObject` membro, [m_contained](#m_contained).  
  
##  <a name="dtor"></a>CComCachedTearOffObject:: ~ CComCachedTearOffObject  
 O destruidor.  
  
```
~CComCachedTearOffObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados e chamadas [FinalRelease](#finalrelease).  
  
##  <a name="finalconstruct"></a>CComCachedTearOffObject::FinalConstruct  
 Chamadas **m_contained::FinalConstruct** criar `m_contained`, o `CComContainedObject` <  `contained`> objeto usado para acessar a interface implementada pela classe destacável.  
  
```
HRESULT FinalConstruct();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="finalrelease"></a>CComCachedTearOffObject::FinalRelease  
 Chamadas **m_contained::FinalRelease** para liberar `m_contained`, o `CComContainedObject` <  `contained`> objeto.  
  
```
void FinalRelease();
```  
  
##  <a name="m_contained"></a>CComCachedTearOffObject::m_contained  
 Um [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da classe destacável.  
  
```
CcomContainedObject <contained> m_contained;
```     
  
### <a name="parameters"></a>Parâmetros  
 `contained`  
 [in] Sua classe destacável derivado `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacável para dar suporte.  
  
### <a name="remarks"></a>Comentários  
 Os métodos `m_contained` herda são usadas para acessar a interface destacável em sua classe destacável por meio do objeto armazenado em cache destacável `QueryInterface`, `FinalConstruct`, e `FinalRelease`.  
  
##  <a name="queryinterface"></a>CComCachedTearOffObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] O GUID da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface identificado por `iid`, ou **nulo** se a interface não foi encontrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Se a interface solicitada é **IUnknown**, retorna um ponteiro para o `CComCachedTearOffObject`do próprio **IUnknown** e incrementa a contagem de referência. Caso contrário, a consulta para a interface em sua classe destacável usando o [InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) método herdado do `CComObjectRootEx`.  

  
##  <a name="release"></a>CComCachedTearOffObject::Release  
 Diminui a contagem de referência em 1 e, se a contagem de referência for 0, exclui o `CComCachedTearOffObject` objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração não, sempre retorna 0. Compilações de depuração, retorna um valor que pode ser útil para um diagnóstico ou teste.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
