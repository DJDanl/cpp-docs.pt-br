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
ms.openlocfilehash: 85ef287a905abc7b3151628c0f5dc29b9050b187
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62246709"
---
# <a name="ccomclassfactory-class"></a>Classe CComClassFactory

Essa classe implementa a [IClassFactory](/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface.

## <a name="syntax"></a>Sintaxe

```
class CComClassFactory
    : public IClassFactory,
      public CComObjectRootEx<CComGlobalsThreadModel>
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComClassFactory::CreateInstance](#createinstance)|Cria um objeto do CLSID especificado.|
|[CComClassFactory::LockServer](#lockserver)|Bloqueia a fábrica de classes na memória.|

## <a name="remarks"></a>Comentários

`CComClassFactory` implementa o [IClassFactory](/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface, que contém métodos para criação de um objeto de um CLSID particular, bem como a fábrica de classes na memória para permitir que os novos objetos sejam criadas mais rapidamente o bloqueio. `IClassFactory` deve ser implementado para cada classe que você registre-se no registro do sistema e que você atribuir um CLSID.

Objetos ATL normalmente adquirem uma fábrica de classes derivando [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara `CComClassFactory` porque a fábrica de classe padrão. Para substituir esse padrão, especifique um dos `DECLARE_CLASSFACTORY` *XXX* macros em sua definição de classe. Por exemplo, o [DECLARE_CLASSFACTORY_EX](aggregation-and-class-factory-macros.md#declare_classfactory_ex) macro usa a classe especificada para a fábrica de classes:

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/ccomclassfactory-class_1.h)]

A definição de classe acima Especifica que `CMyClassFactory` será usado como a fábrica de classes padrão do objeto. `CMyClassFactory` deve ser derivado de `CComClassFactory` e substituir `CreateInstance`.

ATL fornece três outras macros que declaram uma fábrica de classes:

- [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) usa [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md), que controla a criação por meio de uma licença.

- [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria objetos em vários apartments.

- [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói um único [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="createinstance"></a>  CComClassFactory::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.

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

##  <a name="lockserver"></a>  CComClassFactory::LockServer

Incrementa e decrementa a módulo contagem de bloqueio, chamando `_Module::Lock` e `_Module::Unlock`, respectivamente.

```
STDMETHOD(LockServer)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*fLock*<br/>
[in] Se for TRUE, a contagem de bloqueio é aumentada. Caso contrário, a contagem de bloqueio é reduzida.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

`_Module` refere-se à instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou a uma classe derivada.

Chamar `LockServer` permite que um cliente retenham uma fábrica de classes para que vários objetos podem ser criados rapidamente.

## <a name="see-also"></a>Consulte também

[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
