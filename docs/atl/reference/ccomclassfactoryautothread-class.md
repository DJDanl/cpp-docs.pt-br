---
title: Classe CComClassFactoryAutoThread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComClassFactoryAutoThread
- ATLCOM/ATL::CComClassFactoryAutoThread
- ATLCOM/ATL::CComClassFactoryAutoThread::CreateInstance
- ATLCOM/ATL::CComClassFactoryAutoThread::LockServer
dev_langs:
- C++
helpviewer_keywords:
- CComClassFactoryAutoThread class
ms.assetid: 22008042-533f-4dd9-bf7e-191ee571f9a1
caps.latest.revision: 21
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: 88728e6fccc4aea6e8a1f0bbb2811ed299dd4ad9
ms.lasthandoff: 03/31/2017

---
# <a name="ccomclassfactoryautothread-class"></a>Classe CComClassFactoryAutoThread
Essa classe implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) de interface e permite que os objetos a serem criados em vários apartments.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComClassFactoryAutoThread 
   : public IClassFactory, 
     public CComObjectRootEx<CComGlobalsThreadModel>
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComClassFactoryAutoThread::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|  
|[CComClassFactoryAutoThread::LockServer](#lockserver)|Bloqueia a fábrica de classe na memória.|  
  
## <a name="remarks"></a>Comentários  
 `CComClassFactoryAutoThread`é semelhante a [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que os objetos a serem criados em vários apartments. Para aproveitar esse suporte, derivam o seu módulo EXE de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  
  
 Objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para usar `CComClassFactoryAutoThread`, especifique o [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM 9](../../atl/codesnippet/cpp/ccomclassfactoryautothread-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IClassFactory`  
  
 `CComClassFactoryAutoThread`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="createinstance"></a>CComClassFactoryAutoThread::CreateInstance  
 Cria um objeto com o CLSID especificado e recupera um ponteiro de interface para este objeto.  
  
```
STDMETHODIMP CreateInstance(
    LPUNKNOWN pUnkOuter,
    REFIID riid,
    void** ppvObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkOuter`  
 [in] Se o objeto está sendo criado como parte de uma agregação, em seguida, `pUnkOuter` deve ser externo desconhecido. Caso contrário, `pUnkOuter` devem ser **nulo**.  
  
 `riid`  
 [in] O IID da interface solicitada. Se `pUnkOuter` é não - **nulo**, `riid` devem ser **IID_IUnknown**.  
  
 `ppvObj`  
 [out] Um ponteiro para o ponteiro de interface identificado por `riid`. Se o objeto não oferece suporte a essa interface, `ppvObj` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Se seu módulo deriva [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), `CreateInstance` primeiro seleciona um thread para criar o objeto no apartment associado.  
  
##  <a name="lockserver"></a>CComClassFactoryAutoThread::LockServer  
 Incrementa e diminui o bloqueio de módulo contagem chamando **_Module::Lock** e **_Module::Unlock**, respectivamente.  
  
```
STDMETHODIMP LockServer(BOOL fLock);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fLock`  
 [in] Se **TRUE**, a contagem de bloqueio é incrementado; caso contrário, a contagem de bloqueio é diminuída.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Ao usar `CComClassFactoryAutoThread`, **_Module** normalmente refere-se à instância global do [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  
  
 Chamando `LockServer` permite que um cliente mantenha uma fábrica de classes para que vários objetos podem ser criados rapidamente.  
  
## <a name="see-also"></a>Consulte também  
 [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364)   
 [Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)   
 [Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

