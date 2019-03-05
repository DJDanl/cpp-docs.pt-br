---
title: Classe CComAggObject
ms.date: 11/04/2016
f1_keywords:
- CComAggObject
- ATLCOM/ATL::CComAggObject
- ATLCOM/ATL::CComAggObject::CComAggObject
- ATLCOM/ATL::CComAggObject::AddRef
- ATLCOM/ATL::CComAggObject::CreateInstance
- ATLCOM/ATL::CComAggObject::FinalConstruct
- ATLCOM/ATL::CComAggObject::FinalRelease
- ATLCOM/ATL::CComAggObject::QueryInterface
- ATLCOM/ATL::CComAggObject::Release
- ATLCOM/ATL::CComAggObject::m_contained
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComAggObject class
ms.assetid: 7aa90d69-d399-477b-880d-e2cdf0ef7881
ms.openlocfilehash: 52cdddb1d922ca21e24122422ca14d9c12d13a83
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57301656"
---
# <a name="ccomaggobject-class"></a>Classe CComAggObject

Essa classe implementa a [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface para um objeto agregado. Por definição, um objeto agregado está contido dentro de um objeto externo. O `CComAggObject` classe é semelhante ao [classe CComObject](../../atl/reference/ccomobject-class.md), exceto que ele expõe uma interface que é diretamente acessível para clientes externos.

## <a name="syntax"></a>Sintaxe

```
template<class contained>
class CComAggObject : public IUnknown,
   public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*contained*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como de outras interfaces que você deseja oferecer suporte no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::CComAggObject](#ccomaggobject)|O construtor.|
|[CComAggObject::~CComAggObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::AddRef](#addref)|Incrementa a contagem de referência no objeto agregado.|
|[CComAggObject::CreateInstance](#createinstance)|A função estática permite que você crie uma nova **CComAggObject <** `contained` **>** objeto sem a sobrecarga de [CoCreateInstance](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).|
|[CComAggObject::FinalConstruct](#finalconstruct)|Executa a inicialização final de `m_contained`.|
|[CComAggObject::FinalRelease](#finalrelease)|Executa a destruição de final de `m_contained`.|
|[CComAggObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComAggObject::Release](#release)|Diminui a contagem de referência no objeto agregado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::m_contained](#m_contained)|Delegados `IUnknown` chamadas para o externo desconhecido.|

## <a name="remarks"></a>Comentários

`CComAggObject` implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) para um objeto agregado. `CComAggObject` tem seu próprio `IUnknown` interface, separado do que o objeto externo `IUnknown` de interface e mantém seu próprio contagem de referência.

Para obter mais informações sobre agregação, consulte o artigo [conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComAggObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="addref"></a>  CComAggObject::AddRef

Incrementa a contagem de referência no objeto agregado.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

##  <a name="ccomaggobject"></a>  CComAggObject::CComAggObject

O construtor.

```
CComAggObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
[in] O externo desconhecido.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro, [m_contained](#m_contained)e incrementa a contagem de bloqueios do módulo.

O destruidor decrementa a módulo contagem de bloqueio.

##  <a name="dtor"></a>  CComAggObject::~CComAggObject

O destruidor.

```
~CComAggObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chamadas [FinalRelease](#finalrelease), e diminui a contagem de bloqueio de módulo.

##  <a name="createinstance"></a>  CComAggObject::CreateInstance

A função estática permite que você crie uma nova **CComAggObject <** `contained` **>** objeto sem a sobrecarga de [CoCreateInstance](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(
    LPUNKNOWN pUnkOuter,
    CComAggObject<contained>** pp);
```

### <a name="parameters"></a>Parâmetros

*pp*<br/>
[out] Um ponteiro para um **CComAggObject\<**<em>contido</em> **>** ponteiro. Se `CreateInstance` não for bem-sucedida, *pp* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem de referência de zero, portanto, chame `AddRef` imediatamente, em seguida, use `Release` para liberar a referência no ponteiro de objeto quando você terminar.

Se você não precisa de acesso direto ao objeto, mas ainda quiser criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

##  <a name="finalconstruct"></a>  CComAggObject::FinalConstruct

Chamado durante os estágios finais da construção do objeto, este método executa qualquer inicialização final sobre o [m_contained](#m_contained) membro.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="finalrelease"></a>  CComAggObject::FinalRelease

Chamado durante a destruição de objeto, esse método libera o [m_contained](#m_contained) membro.

```
void FinalRelease();
```

##  <a name="m_contained"></a>  CComAggObject::m_contained

Um [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da sua classe.

```
CComContainedObject<contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*contained*<br/>
[in] Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como de outras interfaces que você deseja oferecer suporte no objeto.

### <a name="remarks"></a>Comentários

Todos os `IUnknown` chama por meio de `m_contained` são delegadas ao externo desconhecido.

##  <a name="queryinterface"></a>  CComAggObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O identificador da interface que está sendo solicitado.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo *iid*. Se o objeto não dá suporte a essa interface, *ppvObject* é definido como NULL.

*pp*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo tipo `Q`. Se o objeto não dá suporte a essa interface, *pp* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se for a interface solicitada `IUnknown`, `QueryInterface` retorna um ponteiro para o objeto agregado próprio `IUnknown` e incrementa a contagem de referência. Caso contrário, este método consulta para a interface por meio de `CComContainedObject` membro, [m_contained](#m_contained).

##  <a name="release"></a>  CComAggObject::Release

Diminui a contagem de referência no objeto agregado.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações de depuração, `Release` retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações sem depuração, `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)<br/>
[DECLARE_ONLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_only_aggregatable)<br/>
[DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
