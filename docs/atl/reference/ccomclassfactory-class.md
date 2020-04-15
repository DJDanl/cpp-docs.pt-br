---
title: Classe CComClassFactory
ms.date: 11/04/2016
f1_keywords:
- CComClassFactory
- ATLCOM/ATL::CComClassFactory
- ATLCOM/ATL::CComClassFactory::CreateInstance
- ATLCOM/ATL::CComClassFactory::LockServer
helpviewer_keywords:
- CComClassFactory class
ms.assetid: e56dacf7-d5c4-4c42-aef4-a86d91981a1b
ms.openlocfilehash: 041575339906b83488697f1db5a7f8b08b53070e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321031"
---
# <a name="ccomclassfactory-class"></a>Classe CComClassFactory

Esta classe implementa a interface [IClassFactory.](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory)

## <a name="syntax"></a>Sintaxe

```
class CComClassFactory
    : public IClassFactory,
      public CComObjectRootEx<CComGlobalsThreadModel>
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactory::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|
|[CComClassFactory::LockServer](#lockserver)|Bloqueia a fábrica de classe na memória.|

## <a name="remarks"></a>Comentários

`CComClassFactory`implementa a interface [IClassFactory,](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) que contém métodos para criar um objeto de um CLSID específico, bem como bloquear a fábrica de classe na memória para permitir que novos objetos sejam criados mais rapidamente. `IClassFactory`deve ser implementado para cada classe que você se registrar no registro do sistema e para o qual você atribui um CLSID.

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory)macro `CComClassFactory` , que declara como a fábrica de classe padrão. Para substituir esse padrão, especifique uma das `DECLARE_CLASSFACTORY`macros *XXX* na definição de classe. Por exemplo, a [macro DECLARE_CLASSFACTORY_EX](aggregation-and-class-factory-macros.md#declare_classfactory_ex) usa a classe especificada para a fábrica de classes:

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/ccomclassfactory-class_1.h)]

A definição de classe `CMyClassFactory` acima especifica que será usada como fábrica de classe padrão do objeto. `CMyClassFactory`deve derivar `CComClassFactory` e `CreateInstance`substituir .

A ATL fornece três outras macros que declaram uma fábrica de classe:

- [DECLARE_CLASSFACTORY2.](aggregation-and-class-factory-macros.md#declare_classfactory2) Usa [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md), que controla a criação através de uma licença.

- [DECLARE_CLASSFACTORY_AUTO_THREAD DECLARE_CLASSFACTORY_AUTO_THREAD.](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) Usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria objetos em vários apartamentos.

- [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) Usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói um único objeto [CComObjectGlobal.](../../atl/reference/ccomobjectglobal-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomclassfactorycreateinstance"></a><a name="createinstance"></a>CComClassFactory::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para este objeto.

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

## <a name="ccomclassfactorylockserver"></a><a name="lockserver"></a>CComClassFactory::LockServer

Incrementa e diminui a contagem de `_Module::Lock` `_Module::Unlock`bloqueio do módulo por chamada e, respectivamente.

```
STDMETHOD(LockServer)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*Rebanho*<br/>
[em] Se TRUE, a contagem de bloqueios é incrementada; caso contrário, a contagem de bloqueios é decrementada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`_Module`refere-se à instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou de uma classe derivada dele.

A `LockServer` chamada permite que um cliente se mantenha em uma fábrica de classes para que vários objetos possam ser criados rapidamente.

## <a name="see-also"></a>Confira também

[Classe CcomObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Ccomglobalsthreadmodel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
