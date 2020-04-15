---
title: Classe CComClassFactoryAutoThread
ms.date: 11/04/2016
f1_keywords:
- CComClassFactoryAutoThread
- ATLCOM/ATL::CComClassFactoryAutoThread
- ATLCOM/ATL::CComClassFactoryAutoThread::CreateInstance
- ATLCOM/ATL::CComClassFactoryAutoThread::LockServer
helpviewer_keywords:
- CComClassFactoryAutoThread class
ms.assetid: 22008042-533f-4dd9-bf7e-191ee571f9a1
ms.openlocfilehash: e997d92adfa9df46c82dacbd297db495b037c6e6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320911"
---
# <a name="ccomclassfactoryautothread-class"></a>Classe CComClassFactoryAutoThread

Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) e permite que objetos sejam criados em vários apartamentos.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComClassFactoryAutoThread
    : public IClassFactory,
      public CComObjectRootEx<CComGlobalsThreadModel>
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactory'SThread de auto-criação:Criaçãode ocorrência](#createinstance)|Cria um objeto do CLSID especificado.|
|[CComClassFactoryAutoThread::LockServer](#lockserver)|Bloqueia a fábrica de classe na memória.|

## <a name="remarks"></a>Comentários

`CComClassFactoryAutoThread`é semelhante ao [CComClassFactory,](../../atl/reference/ccomclassfactory-class.md)mas permite que objetos sejam criados em vários apartamentos. Para aproveitar esse suporte, obtenha seu módulo EXE do [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory)de macro , que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para `CComClassFactoryAutoThread`usar, especifique a [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/ccomclassfactoryautothread-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory`

`CComClassFactoryAutoThread`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomclassfactoryautothreadcreateinstance"></a><a name="createinstance"></a>CComClassFactory'SThread de auto-criação:Criaçãode ocorrência

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para este objeto.

```
STDMETHODIMP CreateInstance(
    LPUNKNOWN pUnkOuter,
    REFIID riid,
    void** ppvObj);
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

### <a name="remarks"></a>Comentários

Se o módulo derivar do [CComAutoThreadModule,](../../atl/reference/ccomautothreadmodule-class.md) `CreateInstance` primeiro selecione um segmento para criar o objeto no apartamento associado.

## <a name="ccomclassfactoryautothreadlockserver"></a><a name="lockserver"></a>CComClassFactoryAutoThread::LockServer

Incrementa e diminui a contagem de `_Module::Lock` `_Module::Unlock`bloqueio do módulo por chamada e, respectivamente.

```
STDMETHODIMP LockServer(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*Rebanho*<br/>
[em] Se TRUE, a contagem de bloqueios é incrementada; caso contrário, a contagem de bloqueios é decrementada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Ao `CComClassFactoryAutoThread`usar, `_Module` normalmente refere-se à instância global do [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

A `LockServer` chamada permite que um cliente se mantenha em uma fábrica de classes para que vários objetos possam ser criados rapidamente.

## <a name="see-also"></a>Confira também

[IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory)<br/>
[Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)<br/>
[Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)<br/>
[Classe CcomObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Ccomglobalsthreadmodel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
