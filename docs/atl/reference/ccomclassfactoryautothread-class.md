---
title: Classe CComClassFactoryAutoThread | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CComClassFactoryAutoThread
- ATL.CComClassFactoryAutoThread
- CComClassFactoryAutoThread
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: fcc5671fc136b061bf3e8109999ac91d302d3d3b
ms.lasthandoff: 02/25/2017

---
# <a name="ccomclassfactoryautothread-class"></a>Classe CComClassFactoryAutoThread
Essa classe implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) interface e permite que os objetos a serem criados em vários apartments.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
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
|[CComClassFactoryAutoThread::LockServer](#lockserver)|Bloqueia a fábrica de classes na memória.|  
  
## <a name="remarks"></a>Comentários  
 `CComClassFactoryAutoThread`é semelhante ao [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que os objetos a serem criados em vários apartments. Para aproveitar esse suporte, derivar seu módulo EXE de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  
  
 Objetos ATL normalmente adquirem uma fábrica de classes, derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](http://msdn.microsoft.com/library/51a6b925-07c0-4d3a-9174-0b8c808975e4), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. Usar `CComClassFactoryAutoThread`, especifique o [DECLARE_CLASSFACTORY_AUTO_THREAD](http://msdn.microsoft.com/library/19d7105e-03e8-4412-9f5e-5384c8a5e18f) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM N º&9;](../../atl/codesnippet/cpp/ccomclassfactoryautothread-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IClassFactory`  
  
 `CComClassFactoryAutoThread`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-namecreateinstancea--ccomclassfactoryautothreadcreateinstance"></a><a name="createinstance"></a>CComClassFactoryAutoThread::CreateInstance  
 Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.  
  
```
STDMETHODIMP CreateInstance(
    LPUNKNOWN pUnkOuter,
    REFIID riid,
    void** ppvObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkOuter`  
 [in] Se o objeto está sendo criado como parte de uma agregação, em seguida, `pUnkOuter` deve ser o externo desconhecido. Caso contrário, `pUnkOuter` deve ser **nulo**.  
  
 `riid`  
 [in] O IID da interface solicitada. Se `pUnkOuter` não **nulo**, `riid` deve ser **IID_IUnknown**.  
  
 `ppvObj`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo `riid`. Se o objeto não oferece suporte a essa interface, `ppvObj` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Se o módulo é derivado de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), `CreateInstance` primeiro seleciona um thread para criar o objeto no apartment associado.  
  
##  <a name="a-namelockservera--ccomclassfactoryautothreadlockserver"></a><a name="lockserver"></a>CComClassFactoryAutoThread::LockServer  
 Incrementa e decrementa o bloqueio de módulo contar chamando **_Module::Lock** e **_Module::Unlock**, respectivamente.  
  
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

