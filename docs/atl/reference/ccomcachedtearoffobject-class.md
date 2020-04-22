---
title: CComCachedTearOffObject Class
ms.date: 11/04/2016
f1_keywords:
- CComCachedTearOffObject
- ATLCOM/ATL::CComCachedTearOffObject
- ATLCOM/ATL::CComCachedTearOffObject::CComCachedTearOffObject
- ATLCOM/ATL::CComCachedTearOffObject::AddRef
- ATLCOM/ATL::CComCachedTearOffObject::FinalConstruct
- ATLCOM/ATL::CComCachedTearOffObject::FinalRelease
- ATLCOM/ATL::CComCachedTearOffObject::QueryInterface
- ATLCOM/ATL::CComCachedTearOffObject::Release
- ATLCOM/ATL::CComCachedTearOffObject::m_contained
helpviewer_keywords:
- cache, ATL cached tear-off objects
- CComCachedTearOffObject class
ms.assetid: ae19507d-a1de-4dbc-a988-da9f75a50c95
ms.openlocfilehash: 019b90c932de144d05fbf05f3ca339f4e5d6edd1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748094"
---
# <a name="ccomcachedtearoffobject-class"></a>CComCachedTearOffObject Class

Esta classe implementa [o IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para uma interface de tear-off.

## <a name="syntax"></a>Sintaxe

```
template
<class contained>
class CComCachedTearOffObject : public
    IUnknown,
public CComObjectRootEx<contained
::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*Contido*<br/>
Sua classe de tear-off, derivada `CComTearOffObjectBase` e das interfaces que você deseja que seu objeto tear-off suporte.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObjeto::CComCachedTearOffObject](#ccomcachedtearoffobject)|O construtor.|
|[CComCachedTearOffObject::~CComCachedTearOffObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::AddRef](#addref)|Incrementa a contagem `CComCachedTearOffObject` de referência para um objeto.|
|[CComCachedTearOffObject::FinalConstruct](#finalconstruct)|Chama `m_contained::FinalConstruct` o método (a classe tear-off).|
|[CComCachedTearOffObject::FinalRelease](#finalrelease)|Chama `m_contained::FinalRelease` o método (a classe tear-off).|
|[CComCachedTearOffObject:QueryInterface](#queryinterface)|Retorna um ponteiro `IUnknown` para `CComCachedTearOffObject` o objeto ou para a interface solicitada em `contained`sua classe tear-off (a classe ).|
|[CComCachedTearOffObject::Lançamento](#release)|Decreta a contagem de `CComCachedTearOffObject` referência para um objeto e destrói-a se a contagem de referência for 0.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObjeto::m_contained](#m_contained)|Um `CComContainedObject` objeto derivado de sua classe de `contained`tear-off (a classe ).|

## <a name="remarks"></a>Comentários

`CComCachedTearOffObject`implementa [iUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para uma interface de tear-off. Esta classe difere `CComTearOffObject` daquela `CComCachedTearOffObject` que `IUnknown`tem a sua própria, `IUnknown` separada da do objeto proprietário (o proprietário é o objeto para o qual o tear-off está sendo criado). `CComCachedTearOffObject`mantém sua própria `IUnknown` contagem de referência na sua e se exclui uma vez que sua contagem de referência é zero. No entanto, se você consultar qualquer uma de suas interfaces de `IUnknown` tear-off, a contagem de referência do objeto proprietário será incrementada.

Se `CComCachedTearOffObject` o objeto que implementa o tear-off já estiver instanciado e a interface `CComCachedTearOffObject` de tear-off for consultada novamente, o mesmo objeto será reutilizado. Em contraste, se uma interface de `CComTearOffObject` ruptura implementada por um for novamente `CComTearOffObject` questionada por meio do objeto proprietário, outra será instanciada.

A classe proprietário `FinalRelease` deve `Release` implementar e `IUnknown` chamar `CComCachedTearOffObject`o cache para o , o que diminuirá sua contagem de referência. Isso vai `CComCachedTearOffObject`fazer `FinalRelease` com que seja chamado e apague o rasgo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComCachedTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomcachedtearoffobjectaddref"></a><a name="addref"></a>CComCachedTearOffObject::AddRef

Incrementa a contagem `CComCachedTearOffObject` de referência do objeto por 1.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos e testes.

## <a name="ccomcachedtearoffobjectccomcachedtearoffobject"></a><a name="ccomcachedtearoffobject"></a>CComCachedTearOffObjeto::CComCachedTearOffObject

O construtor.

```
CComCachedTearOffObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
[em] Ponteiro para `IUnknown` o `CComCachedTearOffObject`do .

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro, [m_contained](#m_contained).

## <a name="ccomcachedtearoffobjectccomcachedtearoffobject"></a><a name="dtor"></a>CComCachedTearOffObject::~CComCachedTearOffObject

O destruidor.

```
~CComCachedTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [Deliberação Final](#finalrelease).

## <a name="ccomcachedtearoffobjectfinalconstruct"></a><a name="finalconstruct"></a>CComCachedTearOffObject::FinalConstruct

Chamadas `m_contained::FinalConstruct` para `m_contained`criar `CComContainedObject` <  `contained` , o objeto> usado para acessar a interface implementada pela sua classe tear-off.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomcachedtearoffobjectfinalrelease"></a><a name="finalrelease"></a>CComCachedTearOffObject::FinalRelease

Chamadas `m_contained::FinalRelease` `m_contained`gratuitas, `CComContainedObject` <  `contained` o objeto>.

```cpp
void FinalRelease();
```

## <a name="ccomcachedtearoffobjectm_contained"></a><a name="m_contained"></a>CComCachedTearOffObjeto::m_contained

Um objeto [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) derivado de sua classe de tear-off.

```
CcomContainedObject <contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*Contido*<br/>
[em] Sua classe de tear-off, derivada `CComTearOffObjectBase` e das interfaces que você deseja que seu objeto tear-off suporte.

### <a name="remarks"></a>Comentários

Os `m_contained` métodos herdados são usados para acessar a interface de tear-off em sua `QueryInterface` `FinalConstruct`classe `FinalRelease`tear-off através do objeto de tear-off armazenado em cache, e .

## <a name="ccomcachedtearoffobjectqueryinterface"></a><a name="queryinterface"></a>CComCachedTearOffObject:QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a interface `IUnknown`solicitada for, retorne `CComCachedTearOffObject`um `IUnknown` ponteiro para o próprio 'e incremente a contagem de referências. Caso contrário, consultas para a interface em sua classe tear-off usando `CComObjectRootEx`o método [InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) herdado de .

## <a name="ccomcachedtearoffobjectrelease"></a><a name="release"></a>CComCachedTearOffObject::Lançamento

Diminui a contagem de referência por 1 e, se a `CComCachedTearOffObject` contagem de referência for 0, exclui o objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Em construções não-depuradas, sempre retorna 0. Nas compilações de depuração, retorna um valor que pode ser útil para diagnósticos ou testes.

## <a name="see-also"></a>Confira também

[Classe Ccomtearoffobject](../../atl/reference/ccomtearoffobject-class.md)<br/>
[Classe CcomObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
