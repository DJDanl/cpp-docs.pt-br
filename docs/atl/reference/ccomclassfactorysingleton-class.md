---
title: Classe CComClassFactorySingleton
ms.date: 11/04/2016
f1_keywords:
- CComClassFactorySingleton
- ATLCOM/ATL::CComClassFactorySingleton
- ATLCOM/ATL::CComClassFactorySingleton::CreateInstance
- ATLCOM/ATL::CComClassFactorySingleton::m_spObj
helpviewer_keywords:
- CComClassFactorySingleton class
ms.assetid: debb983c-382b-487b-8d42-7ea26dc158b8
ms.openlocfilehash: 480b4c2a6e052e8e0823b97b548fc5d07b55230f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57290385"
---
# <a name="ccomclassfactorysingleton-class"></a>Classe CComClassFactorySingleton

Essa classe deriva [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class CComClassFactorySingleton : public CComClassFactory
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe.

`CComClassFactorySingleton` deriva [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada para o `CreateInstance` método simplesmente consulta esse objeto para um ponteiro de interface.

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

Objetos ATL normalmente adquirem uma fábrica de classes derivando [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara `CComClassFactory` porque a fábrica de classe padrão. Para usar `CComClassFactorySingleton`, especifique o [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/ccomclassfactorysingleton-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory`

[CComClassFactory](../../atl/reference/ccomclassfactory-class.md)

`CComClassFactorySingleton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="createinstance"></a>  CComClassFactorySingleton::CreateInstance

Chamadas `QueryInterface` por meio [m_spObj](#m_spobj) para recuperar um ponteiro de interface.

```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
[in] Se o objeto está sendo criado como parte de uma agregação, em seguida *pUnkOuter* deve ser o externo desconhecido. Caso contrário, *pUnkOuter* deve ser NULL.

*riid*<br/>
[in] O IID da interface solicitada. Se *pUnkOuter* não for nulo, *riid* deve ser `IID_IUnknown`.

*ppvObj*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo *riid*. Se o objeto não dá suporte a essa interface, *ppvObj* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="m_spobj"></a>  CComClassFactorySingleton::m_spObj

O [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) objeto construído por `CComClassFactorySingleton`.

```
CComPtr<IUnknown> m_spObj;
```

### <a name="remarks"></a>Comentários

Cada chamada para o [CreateInstance](#createinstance) método simplesmente consulta esse objeto para um ponteiro de interface.

Observe que o formulário atual de `m_spObj` apresenta uma alteração significativa desde a maneira que `CComClassFactorySingleton` trabalhou nas versões anteriores do ATL. Nas versões anteriores a `CComClassFactorySingleton` objeto foi criado ao mesmo tempo que a fábrica de classes, durante a inicialização do servidor. No Visual C++ .NET 2003, o objeto é criado lentamente, na primeira solicitação. Essa alteração pode causar erros em programas que dependem de inicialização antecipada.

## <a name="see-also"></a>Consulte também

[IClassFactory](/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory)<br/>
[Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)<br/>
[Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
