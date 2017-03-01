---
title: Classe CComObjectStack | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CComObjectStack
- ATL.CComObjectStack
- ATL::CComObjectStack<Base>
- ATL.CComObjectStack<Base>
- CComObjectStack
dev_langs:
- C++
helpviewer_keywords:
- CComObjectStack class
ms.assetid: 3da72c40-c834-45f6-bb76-6ac204028d80
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
ms.openlocfilehash: 0738eae13fdca5906596194016ce22812fbfcd36
ms.lasthandoff: 02/25/2017

---
# <a name="ccomobjectstack-class"></a>Classe CComObjectStack
Essa classe cria um objeto COM temporário e fornece uma implementação esqueleto de **IUnknown**.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class  Base>  
class CComObjectStack
 : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 Sua classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como qualquer outra interface para o qual você deseja oferecer suporte no objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObjectStack::CComObjectStack](#ccomobjectstack)|O construtor.|  
|[CComObjectStack:: ~ CComObjectStack](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObjectStack::AddRef](#addref)|Retorna zero. No modo de depuração, chama `_ASSERTE`.|  
|[CComObjectStack::QueryInterface](#queryinterface)|Retorna **E_NOINTERFACE**. No modo de depuração, chama `_ASSERTE`.|  
|[CComObjectStack::Release](#release)|Retorna zero. No modo de depuração, chama `_ASSERTE`. ~|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObjectStack::m_hResFinalConstruct](#m_hresfinalconstruct)|Contém o **HRESULT** retornado durante a construção do `CComObjectStack` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComObjectStack`é usado para criar um objeto COM temporário e fornecer o objeto uma implementação esqueleto de **IUnknown**. Normalmente, o objeto é usado como uma variável local dentro de uma função (isto é, inserida na pilha). Uma vez que o objeto é destruído quando a função for concluída, a contagem de referência não é executada para aumentar a eficiência.  
  
 O exemplo a seguir mostra como criar um objeto COM usado dentro de uma função:  
  
 [!code-cpp[NVC_ATL_COM&42;](../../atl/codesnippet/cpp/ccomobjectstack-class_1.cpp)]  
  
 O objeto temporário `Tempobj` é inserido na pilha e desaparece automaticamente quando a função é concluída.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComObjectStack`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-nameaddrefa--ccomobjectstackaddref"></a><a name="addref"></a>CComObjectStack::AddRef  
 Retorna zero.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna zero.  
  
### <a name="remarks"></a>Comentários  
 No modo de depuração, chama `_ASSERTE`.  
  
##  <a name="a-nameccomobjectstacka--ccomobjectstackccomobjectstack"></a><a name="ccomobjectstack"></a>CComObjectStack::CComObjectStack  
 O construtor.  
  
```
CComObjectStack(void* = NULL);
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas `FinalConstruct` e, em seguida, define [m_hResFinalConstruct](#m_hresfinalconstruct) para o `HRESULT` retornado por `FinalConstruct`. Se você não tiver derivado sua classe base da [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md), você deve fornecer seu próprio `FinalConstruct` método. O destruidor chama `FinalRelease`.  
  
##  <a name="a-namedtora--ccomobjectstackccomobjectstack"></a><a name="dtor"></a>CComObjectStack:: ~ CComObjectStack  
 O destruidor.  
  
```
CComObjectStack();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados e chamadas [FinalRelease](ccomobjectrootex-class.md#finalrelease).  
  
##  <a name="a-namemhresfinalconstructa--ccomobjectstackmhresfinalconstruct"></a><a name="m_hresfinalconstruct"></a>CComObjectStack::m_hResFinalConstruct  
 Contém o `HRESULT` retornado ao chamar `FinalConstruct` durante a construção do `CComObjectStack` objeto.  
  
```
HRESULT    m_hResFinalConstruct;
```  
  
##  <a name="a-namequeryinterfacea--ccomobjectstackqueryinterface"></a><a name="queryinterface"></a>CComObjectStack::QueryInterface  
 Retorna **E_NOINTERFACE**.  
  
```
HRESULT    QueryInterface(REFIID, void**)
 ;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOINTERFACE**.  
  
### <a name="remarks"></a>Comentários  
 No modo de depuração, chama `_ASSERTE`.  
  
##  <a name="a-namereleasea--ccomobjectstackrelease"></a><a name="release"></a>CComObjectStack::Release  
 Retorna zero.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna zero.  
  
### <a name="remarks"></a>Comentários  
 No modo de depuração, chama `_ASSERTE`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

