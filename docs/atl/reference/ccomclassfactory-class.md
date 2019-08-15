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
ms.openlocfilehash: 892153e47ac4e9dd45d5dfc01b76f1ce29d23938
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497447"
---
# <a name="ccomclassfactory-class"></a>Classe CComClassFactory

Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) .

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

`CComClassFactory`implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) , que contém métodos para criar um objeto de um CLSID específico, bem como bloquear a fábrica de classes na memória para permitir que novos objetos sejam criados mais rapidamente. `IClassFactory`deve ser implementado para cada classe que você registra no registro do sistema e para o qual você atribui um CLSID.

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory), que declara `CComClassFactory` como a fábrica de classes padrão. Para substituir esse padrão, especifique uma das `DECLARE_CLASSFACTORY`macros *xxx* na definição de sua classe. Por exemplo, a macro [DECLARE_CLASSFACTORY_EX](aggregation-and-class-factory-macros.md#declare_classfactory_ex) usa a classe especificada para a fábrica de classes:

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/ccomclassfactory-class_1.h)]

A definição de classe acima Especifica `CMyClassFactory` que será usada como a fábrica de classes padrão do objeto. `CMyClassFactory`deve derivar `CComClassFactory` de e `CreateInstance`substituir.

A ATL fornece três outras macros que declaram uma fábrica de classes:

- [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) Usa [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md), que controla a criação por meio de uma licença.

- [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) Usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria objetos em vários Apartments.

- [DECLARE_CLASSFACTORY_SINGLETON](aggregation-and-class-factory-macros.md#declare_classfactory_singleton) Usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói um único objeto [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="createinstance"></a>  CComClassFactory::CreateInstance

Cria um objeto do CLSID especificado e recupera um ponteiro de interface para esse objeto.

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

##  <a name="lockserver"></a>  CComClassFactory::LockServer

Incrementa e decrementa a contagem de bloqueios de módulo chamando `_Module::Lock` e `_Module::Unlock`, respectivamente.

```
STDMETHOD(LockServer)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*fLock*<br/>
no Se for TRUE, a contagem de bloqueios será incrementada; caso contrário, a contagem de bloqueios será diminuída.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`_Module`refere-se à instância global de [CComModule](../../atl/reference/ccommodule-class.md) ou a uma classe derivada dela.

A `LockServer` chamada permite que um cliente mantenha em uma fábrica de classes para que vários objetos possam ser criados rapidamente.

## <a name="see-also"></a>Consulte também

[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
