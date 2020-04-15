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
ms.openlocfilehash: ec860f7ef59b7d3289bf2e18fea0f0e064a7c8f9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320816"
---
# <a name="ccomclassfactorysingleton-class"></a>Classe CComClassFactorySingleton

Esta classe deriva do [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [o CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class CComClassFactorySingleton : public CComClassFactory
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe.

`CComClassFactorySingleton`deriva do [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [o CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada `CreateInstance` para o método simplesmente consulta este objeto para um ponteiro de interface.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactorySingleton::CriaçãoInstância](#createinstance)|Consultas `m_spObj` para um ponteiro de interface.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactorySingleton::m_spObj](#m_spobj)|O objeto [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) `CComClassFactorySingleton`construído por .|

## <a name="remarks"></a>Comentários

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory)macro `CComClassFactory` , que declara como a fábrica de classe padrão. Para `CComClassFactorySingleton`usar, especifique a [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/ccomclassfactorysingleton-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory`

[Ccomclassfactory](../../atl/reference/ccomclassfactory-class.md)

`CComClassFactorySingleton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomclassfactorysingletoncreateinstance"></a><a name="createinstance"></a>CComClassFactorySingleton::CriaçãoInstância

Chama `QueryInterface` através [de m_spObj](#m_spobj) para recuperar um ponteiro de interface.

```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*Punkouter*<br/>
[em] Se o objeto está sendo criado como parte de um agregado, então *pUnkOuter* deve ser o desconhecido externo. Caso contrário, *pUnkOuter* deve ser NULO.

*riid*<br/>
[em] O IID da interface solicitada. Se *pUnkOuter* não for NULA, `IID_IUnknown` *riid* deve ser .

*Ppvobj*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomclassfactorysingletonm_spobj"></a><a name="m_spobj"></a>CComClassFactorySingleton::m_spObj

O objeto [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) `CComClassFactorySingleton`construído por .

```
CComPtr<IUnknown> m_spObj;
```

### <a name="remarks"></a>Comentários

Cada chamada para o método [CreateInstance](#createinstance) simplesmente consulta este objeto para um ponteiro de interface.

Observe que a `m_spObj` forma atual de apresenta `CComClassFactorySingleton` uma mudança de ruptura em relação à forma como funcionou nas versões anteriores do ATL. Nas versões anteriores, o `CComClassFactorySingleton` objeto foi criado ao mesmo tempo que a fábrica de classes, durante a inicialização do servidor. No Visual C++.NET 2003 e posterior, o objeto é criado preguiçosamente, na primeira solicitação. Essa mudança pode causar erros em programas que dependem da inicialização precoce.

## <a name="see-also"></a>Confira também

[IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory)<br/>
[Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)<br/>
[Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)<br/>
[Classe CcomObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Ccomglobalsthreadmodel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
