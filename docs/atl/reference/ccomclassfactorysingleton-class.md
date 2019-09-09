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
ms.openlocfilehash: 71705d02140f0392a9ce023c64e7b4125c14443f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497399"
---
# <a name="ccomclassfactorysingleton-class"></a>Classe CComClassFactorySingleton

Essa classe deriva de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class CComClassFactorySingleton : public CComClassFactory
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe.

`CComClassFactorySingleton`deriva de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada para o `CreateInstance` método simplesmente consulta esse objeto para um ponteiro de interface.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactorySingleton::CreateInstance](#createinstance)|Consultas `m_spObj` para um ponteiro de interface.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactorySingleton::m_spObj](#m_spobj)|O objeto [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) construído por `CComClassFactorySingleton`.|

## <a name="remarks"></a>Comentários

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara `CComClassFactory` como a fábrica de classes padrão. Para usar `CComClassFactorySingleton`, especifique a macro [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) na definição de classe do seu objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/ccomclassfactorysingleton-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory`

[CComClassFactory](../../atl/reference/ccomclassfactory-class.md)

`CComClassFactorySingleton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="createinstance"></a>CComClassFactorySingleton:: CreateInstance

Chama `QueryInterface` o [m_spObj](#m_spobj) para recuperar um ponteiro de interface.

```
STDMETHOD(CreateInstance)(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
no Se o objeto estiver sendo criado como parte de uma agregação, *pUnkOuter* deverá ser o desconhecido como externo. Caso contrário, *pUnkOuter* deverá ser nulo.

*riid*<br/>
no O IID da interface solicitada. Se *pUnkOuter* for não nulo, *riid* deverá ser `IID_IUnknown`.

*ppvObj*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="m_spobj"></a>  CComClassFactorySingleton::m_spObj

O objeto [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) construído por `CComClassFactorySingleton`.

```
CComPtr<IUnknown> m_spObj;
```

### <a name="remarks"></a>Comentários

Cada chamada para o método [CreateInstance](#createinstance) simplesmente consulta esse objeto em busca de um ponteiro de interface.

Observe que a forma atual de `m_spObj` apresenta uma alteração significativa da maneira que `CComClassFactorySingleton` funcionou em versões anteriores do ATL. Em versões anteriores, `CComClassFactorySingleton` o objeto foi criado ao mesmo tempo que a fábrica de classes, durante a inicialização do servidor. No Visual C++.NET 2003 e posterior, o objeto é criado lentamente, na primeira solicitação. Essa alteração pode causar erros em programas que dependem da inicialização antecipada.

## <a name="see-also"></a>Consulte também

[IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory)<br/>
[Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)<br/>
[Classe CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
