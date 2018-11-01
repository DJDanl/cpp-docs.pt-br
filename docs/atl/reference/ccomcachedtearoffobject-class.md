---
title: Classe CComCachedTearOffObject
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
ms.openlocfilehash: 009bc1e20693a9e45490c58ea29ff9d28b6aa6ea
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582706"
---
# <a name="ccomcachedtearoffobject-class"></a>Classe CComCachedTearOffObject

Essa classe implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) para uma interface destacáveis.

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

*contido*<br/>
Sua classe destacável, derivada de `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacáveis para dar suporte.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::CComCachedTearOffObject](#ccomcachedtearoffobject)|O construtor.|
|[CComCachedTearOffObject:: ~ CComCachedTearOffObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::AddRef](#addref)|Incrementa a contagem de referência para um `CComCachedTearOffObject` objeto.|
|[CComCachedTearOffObject::FinalConstruct](#finalconstruct)|Chamadas a `m_contained::FinalConstruct` (o destacáveis método classe).|
|[CComCachedTearOffObject::FinalRelease](#finalrelease)|Chamadas a `m_contained::FinalRelease` (o destacáveis método classe).|
|[CComCachedTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para o `IUnknown` do `CComCachedTearOffObject` objeto, ou para a interface solicitada em sua classe destacáveis (a classe `contained`).|
|[CComCachedTearOffObject::Release](#release)|Diminui a contagem de referência para um `CComCachedTearOffObject` de objeto e destrói-se a contagem de referência é 0.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::m_contained](#m_contained)|Um `CComContainedObject` objeto derivado da sua classe destacáveis (a classe `contained`).|

## <a name="remarks"></a>Comentários

`CComCachedTearOffObject` implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) para uma interface destacáveis. Essa classe difere `CComTearOffObject` em que `CComCachedTearOffObject` tem seu próprio `IUnknown`separado do objeto proprietário `IUnknown` (o proprietário é o objeto para o qual o destacável está sendo criado). `CComCachedTearOffObject` mantém seu próprio contagem de referência em seu `IUnknown` e excluir a próprio quando sua contagem de referência é zero. No entanto, se você consultar para qualquer um dos seus destacáveis interfaces, a contagem de referência de objeto do proprietário `IUnknown` será incrementado.

Se o `CComCachedTearOffObject` implementar o destacáveis já é instanciado e a interface destacável é consultada para novamente, o mesmo objeto `CComCachedTearOffObject` objeto é reutilizado. Por outro lado, se uma interface destacáveis implementada por um `CComTearOffObject` será novamente consultada para, por meio do objeto proprietário, outro `CComTearOffObject` será instanciada.

A classe de proprietário deve implementar `FinalRelease` e chame `Release` em cache no `IUnknown` para o `CComCachedTearOffObject`, que irá diminuir sua contagem de referência. Isso fará com que `CComCachedTearOffObject`do `FinalRelease` para ser chamado e excluir o destacáveis.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComCachedTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="addref"></a>  CComCachedTearOffObject::AddRef

Incrementa a contagem de referência do `CComCachedTearOffObject` objeto por 1.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser úteis para diagnóstico e teste.

##  <a name="ccomcachedtearoffobject"></a>  CComCachedTearOffObject::CComCachedTearOffObject

O construtor.

```
CComCachedTearOffObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
[in] Ponteiro para o `IUnknown` do `CComCachedTearOffObject`.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro, [m_contained](#m_contained).

##  <a name="dtor"></a>  CComCachedTearOffObject:: ~ CComCachedTearOffObject

O destruidor.

```
~CComCachedTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [FinalRelease](#finalrelease).

##  <a name="finalconstruct"></a>  CComCachedTearOffObject::FinalConstruct

Chamadas `m_contained::FinalConstruct` criem `m_contained`, o `CComContainedObject` <  `contained`> objeto usado para acessar a interface implementada por sua classe destacáveis.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="finalrelease"></a>  CComCachedTearOffObject::FinalRelease

Chamadas `m_contained::FinalRelease` liberar `m_contained`, o `CComContainedObject` <  `contained`> objeto.

```
void FinalRelease();
```

##  <a name="m_contained"></a>  CComCachedTearOffObject::m_contained

Um [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da sua classe destacáveis.

```
CcomContainedObject <contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*contido*<br/>
[in] Sua classe destacável, derivada de `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacáveis para dar suporte.

### <a name="remarks"></a>Comentários

Os métodos `m_contained` herda são usadas para acessar a interface destacáveis em sua classe destacáveis por meio do cache destacáveis do objeto `QueryInterface`, `FinalConstruct`, e `FinalRelease`.

##  <a name="queryinterface"></a>  CComCachedTearOffObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
[in] O GUID da interface que está sendo solicitado.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo *iid*, ou nulo se a interface não foi encontrada.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se for a interface solicitada `IUnknown`, retorna um ponteiro para o `CComCachedTearOffObject`do próprio `IUnknown` e incrementa a contagem de referência. Caso contrário, a consulta para a interface na classe destacáveis usando o [InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) método herdado do `CComObjectRootEx`.

##  <a name="release"></a>  CComCachedTearOffObject::Release

Diminui a contagem de referência em 1 e, se a contagem de referência for 0, exclui o `CComCachedTearOffObject` objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações sem depuração, sempre retorna 0. Em compilações de depuração, retorna um valor que pode ser úteis para diagnóstico ou teste.

## <a name="see-also"></a>Consulte também

[Classe CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
