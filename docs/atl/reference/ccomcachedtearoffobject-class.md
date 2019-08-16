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
ms.openlocfilehash: d993a349d38342bda30a83dfdbe25577953799b3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497543"
---
# <a name="ccomcachedtearoffobject-class"></a>Classe CComCachedTearOffObject

Essa classe implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para uma interface de divisão.

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

*presente*<br/>
Sua classe retirada, derivada de `CComTearOffObjectBase` e as interfaces às quais você deseja que o objeto destacável dê suporte.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::CComCachedTearOffObject](#ccomcachedtearoffobject)|O construtor.|
|[CComCachedTearOffObject::~CComCachedTearOffObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::AddRef](#addref)|Incrementa a contagem de referência para um `CComCachedTearOffObject` objeto.|
|[CComCachedTearOffObject::FinalConstruct](#finalconstruct)|Chama o `m_contained::FinalConstruct` (o método da classe destacável).|
|[CComCachedTearOffObject::FinalRelease](#finalrelease)|Chama o `m_contained::FinalRelease` (o método da classe destacável).|
|[CComCachedTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para o `IUnknown` `CComCachedTearOffObject` do objeto ou para a interface solicitada na sua classe destacável (a classe `contained`).|
|[CComCachedTearOffObject::Release](#release)|Decrementa a contagem de referência para um `CComCachedTearOffObject` objeto e destrói-o se a contagem de referência for 0.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCachedTearOffObject::m_contained](#m_contained)|Um `CComContainedObject` objeto derivado de sua classe destacável (a classe `contained`).|

## <a name="remarks"></a>Comentários

`CComCachedTearOffObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para uma interface de divisão. Essa classe é diferente de `CComTearOffObject` no que `CComCachedTearOffObject` tem sua própria `IUnknown`, separada do objeto do `IUnknown` proprietário (o proprietário é o objeto para o qual a redivisão está sendo criada). `CComCachedTearOffObject`mantém sua própria contagem de referência em `IUnknown` seu e se exclui quando sua contagem de referência é zero. No entanto, se você consultar qualquer uma de suas interfaces retiradas, a contagem de referência do objeto `IUnknown` do proprietário será incrementada.

Se o `CComCachedTearOffObject` objeto que está implementando a remontagem já tiver sido instanciado e a interface de redistribuição for consultada novamente, o `CComCachedTearOffObject` mesmo objeto será reutilizado. Por outro lado, se uma interface retirada implementada `CComTearOffObject` por um for novamente consultado por meio do objeto proprietário `CComTearOffObject` , outra será instanciada.

A classe Owner deve implementar `FinalRelease` e chamar `Release` no cache `IUnknown` para o `CComCachedTearOffObject`, o que diminuirá sua contagem de referência. Isso fará com `CComCachedTearOffObject`que `FinalRelease` o seja chamado e exclua a redivisão.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComCachedTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="addref"></a>  CComCachedTearOffObject::AddRef

Incrementa a contagem de referência do `CComCachedTearOffObject` objeto em 1.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico e teste.

##  <a name="ccomcachedtearoffobject"></a>  CComCachedTearOffObject::CComCachedTearOffObject

O construtor.

```
CComCachedTearOffObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
no Ponteiro para o `IUnknown` `CComCachedTearOffObject`do.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro, [m_contained](#m_contained).

##  <a name="dtor"></a>  CComCachedTearOffObject::~CComCachedTearOffObject

O destruidor.

```
~CComCachedTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [FinalRelease](#finalrelease).

##  <a name="finalconstruct"></a>  CComCachedTearOffObject::FinalConstruct

Chamadas `m_contained::FinalConstruct` para criar `m_contained`, o `CComContainedObject` objeto>usado`contained`para acessar a interface implementada por sua classe destacável. < 

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="finalrelease"></a>  CComCachedTearOffObject::FinalRelease

Chama `m_contained::FinalRelease` gratuitamente `m_contained`, o objeto>`CComContainedObject`. <  `contained`

```
void FinalRelease();
```

##  <a name="m_contained"></a>  CComCachedTearOffObject::m_contained

Um objeto [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) derivado de sua classe destacável.

```
CcomContainedObject <contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*presente*<br/>
no Sua classe retirada, derivada de `CComTearOffObjectBase` e as interfaces às quais você deseja que o objeto destacável dê suporte.

### <a name="remarks"></a>Comentários

Os métodos `m_contained` herdados são usados para acessar a interface retirada em sua classe destacável por meio do `QueryInterface`objeto retirado em cache, `FinalConstruct`e `FinalRelease`.

##  <a name="queryinterface"></a>  CComCachedTearOffObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
no O GUID da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *IID*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a interface solicitada `IUnknown`for, retornará um ponteiro para `CComCachedTearOffObject`o próprio `IUnknown` e incrementará a contagem de referência. Caso contrário, o consulta a interface na sua classe destacável usando o método [InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) herdado `CComObjectRootEx`de.

##  <a name="release"></a>  CComCachedTearOffObject::Release

Decrementa a contagem de referência em 1 e, se a contagem de referência for 0, excluirá o `CComCachedTearOffObject` objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações não depuradas, sempre retorna 0. Em compilações de depuração, retorna um valor que pode ser útil para diagnóstico ou teste.

## <a name="see-also"></a>Consulte também

[Classe CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
