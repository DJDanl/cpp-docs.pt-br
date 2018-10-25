---
title: Classe CComClassFactoryAutoThread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 84d0d149c00024fab0d29ffc05d60270cb26741b
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50054430"
---
# <a name="ccomclassfactoryautothread-class"></a>Classe CComClassFactoryAutoThread

Essa classe implementa a [IClassFactory](/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) de interface e permite que os objetos a serem criados em vários apartments.

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

`CComClassFactoryAutoThread` é semelhante à [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que os objetos a serem criados em vários apartments. Para tirar proveito desse suporte, derivar seu módulo EXE do [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

Objetos ATL normalmente adquirem uma fábrica de classes derivando [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) porque a fábrica de classe padrão. Para usar `CComClassFactoryAutoThread`, especifique o [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/ccomclassfactoryautothread-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory`

`CComClassFactoryAutoThread`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="createinstance"></a>  CComClassFactoryAutoThread::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.

```
STDMETHODIMP CreateInstance(
    LPUNKNOWN pUnkOuter,
    REFIID riid,
    void** ppvObj);
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

### <a name="remarks"></a>Comentários

Se seu módulo deriva [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), `CreateInstance` primeiro seleciona um thread para criar o objeto no apartment associado.

##  <a name="lockserver"></a>  CComClassFactoryAutoThread::LockServer

Incrementa e decrementa a módulo contagem de bloqueio, chamando `_Module::Lock` e `_Module::Unlock`, respectivamente.

```
STDMETHODIMP LockServer(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*Usam*<br/>
[in] Se for TRUE, a contagem de bloqueio é aumentada. Caso contrário, a contagem de bloqueio é reduzida.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Ao usar `CComClassFactoryAutoThread`, `_Module` geralmente se refere à instância global do [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

Chamar `LockServer` permite que um cliente retenham uma fábrica de classes para que vários objetos podem ser criados rapidamente.

## <a name="see-also"></a>Consulte também

[IClassFactory](/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory)<br/>
[Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)<br/>
[Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
