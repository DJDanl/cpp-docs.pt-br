---
title: Classe CComClassFactorySingleton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComClassFactorySingleton
- ATLCOM/ATL::CComClassFactorySingleton
- ATLCOM/ATL::CComClassFactorySingleton::CreateInstance
- ATLCOM/ATL::CComClassFactorySingleton::m_spObj
dev_langs:
- C++
helpviewer_keywords:
- CComClassFactorySingleton class
ms.assetid: debb983c-382b-487b-8d42-7ea26dc158b8
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 754a3abd02a4a09df3e36aa9aea75c400ef00761
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32360375"
---
# <a name="ccomclassfactorysingleton-class"></a>Classe CComClassFactorySingleton
Essa classe é derivada de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class CComClassFactorySingleton : public CComClassFactory
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe.  
  
 `CComClassFactorySingleton` deriva [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada para o `CreateInstance` método simplesmente consulta este objeto para um ponteiro de interface.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComClassFactorySingleton::CreateInstance](#createinstance)|Consultas `m_spObj` para um ponteiro de interface.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComClassFactorySingleton::m_spObj](#m_spobj)|O [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) objeto construído por `CComClassFactorySingleton`.|  
  
## <a name="remarks"></a>Comentários  
 Objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara `CComClassFactory` como a fábrica de classe padrão. Para usar `CComClassFactorySingleton`, especifique o [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/ccomclassfactorysingleton-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IClassFactory`  
  
 [CComClassFactory](../../atl/reference/ccomclassfactory-class.md)  
  
 `CComClassFactorySingleton`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="createinstance"></a>  CComClassFactorySingleton::CreateInstance  
 Chamadas `QueryInterface` por meio de [m_spObj](#m_spobj) para recuperar um ponteiro de interface.  
  
```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
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
  
##  <a name="m_spobj"></a>  CComClassFactorySingleton::m_spObj  
 O [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) objeto construído por `CComClassFactorySingleton`.  
  
```
CComPtr<IUnknown> m_spObj;
```  
  
### <a name="remarks"></a>Comentários  
 Cada chamada para o [CreateInstance](#createinstance) método simplesmente consulta este objeto para um ponteiro de interface.  
  
 Observe que o formulário atual de `m_spObj` apresenta uma alteração significativa desde a maneira que `CComClassFactorySingleton` trabalhado em versões anteriores do ATL Em versões anteriores a `CComClassFactorySingleton` objeto foi criado no mesmo momento que a fábrica de classes, durante a inicialização do servidor. No Visual C++ .NET 2003, o objeto é criado lentamente, na primeira solicitação. Essa alteração pode causar erros em programas que dependem de inicialização antecipada.  
  
## <a name="see-also"></a>Consulte também  
 [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364)   
 [Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)   
 [Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
