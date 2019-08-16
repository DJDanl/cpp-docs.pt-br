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
ms.openlocfilehash: 73879a73a48290e19d2a27307884953129826df7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497484"
---
# <a name="ccomclassfactoryautothread-class"></a>Classe CComClassFactoryAutoThread

Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) e permite que os objetos sejam criados em vários Apartments.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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

`CComClassFactoryAutoThread`é semelhante a [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que os objetos sejam criados em vários Apartments. Para aproveitar esse suporte, derive seu módulo EXE de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. Para usar `CComClassFactoryAutoThread`, especifique a macro [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) na definição de classe do seu objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/ccomclassfactoryautothread-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IClassFactory`

`CComClassFactoryAutoThread`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

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
no Se o objeto estiver sendo criado como parte de uma agregação, *pUnkOuter* deverá ser o desconhecido como externo. Caso contrário, *pUnkOuter* deverá ser nulo.

*riid*<br/>
no O IID da interface solicitada. Se *pUnkOuter* for não nulo, *riid* deverá ser `IID_IUnknown`.

*ppvObj*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se o módulo deriva de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md), `CreateInstance` primeiro seleciona um thread para criar o objeto no apartamento associado.

##  <a name="lockserver"></a>  CComClassFactoryAutoThread::LockServer

Incrementa e decrementa a contagem de bloqueios de módulo chamando `_Module::Lock` e `_Module::Unlock`, respectivamente.

```
STDMETHODIMP LockServer(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*fLock*<br/>
no Se for TRUE, a contagem de bloqueios será incrementada; caso contrário, a contagem de bloqueios será diminuída.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Ao usar `CComClassFactoryAutoThread`, `_Module` normalmente refere-se à instância global de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

A `LockServer` chamada permite que um cliente mantenha em uma fábrica de classes para que vários objetos possam ser criados rapidamente.

## <a name="see-also"></a>Consulte também

[IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory)<br/>
[Classe CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)<br/>
[Classe CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
