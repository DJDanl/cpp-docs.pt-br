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
ms.openlocfilehash: 9f05e83c8d0a1fd68fce3228dea9cfeab6183c96
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321165"
---
# <a name="ccomaggobject-class"></a>Classe CComAggObject

Esta classe implementa a interface [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado. Por definição, um objeto agregado está contido dentro de um objeto externo. A `CComAggObject` classe é semelhante à [Classe CComObject,](../../atl/reference/ccomobject-class.md)exceto que expõe uma interface diretamente acessível a clientes externos.

## <a name="syntax"></a>Sintaxe

```
template<class contained>
class CComAggObject : public IUnknown,
   public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*Contido*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de quaisquer outras interfaces que você deseja suportar no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::CComAggObject](#ccomaggobject)|O construtor.|
|[CComAggObject::~CComAggObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::AddRef](#addref)|Incrementa a contagem de referência no objeto agregado.|
|[CComAggObject::CreateInstance](#createinstance)|Esta função estática permite criar um novo objeto **CComAggObject<** `contained` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).|
|[CComAggObject::FinalConstruct](#finalconstruct)|Realiza a inicialização final de `m_contained`.|
|[CComAggObject::FinalRelease](#finalrelease)|Realiza a `m_contained`destruição final de .|
|[CComAggObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComAggObject::Liberação](#release)|Decreta a contagem de referência no objeto agregado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::m_contained](#m_contained)|Os `IUnknown` delegados ligam para o desconhecido.|

## <a name="remarks"></a>Comentários

`CComAggObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado. `CComAggObject`tem sua `IUnknown` própria interface, separada da `IUnknown` interface do objeto externo, e mantém sua própria contagem de referência.

Para obter mais informações sobre agregação, consulte o artigo [Fundamentos de Objetos ATL COM](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComAggObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomaggobjectaddref"></a><a name="addref"></a>CComAggObject::AddRef

Incrementa a contagem de referência no objeto agregado.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

## <a name="ccomaggobjectccomaggobject"></a><a name="ccomaggobject"></a>CComAggObject::CComAggObject

O construtor.

```
CComAggObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
[em] O desconhecido exterior.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro, [m_contained](#m_contained)e incrementa a contagem de bloqueiodo módulo.

O destructor decreta a contagem de bloqueio do módulo.

## <a name="ccomaggobjectccomaggobject"></a><a name="dtor"></a>CComAggObject::~CComAggObject

O destruidor.

```
~CComAggObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama [FinalRelease](#finalrelease)e decreta a contagem de bloqueio do módulo.

## <a name="ccomaggobjectcreateinstance"></a><a name="createinstance"></a>CComAggObject::CreateInstance

Esta função estática permite criar um novo objeto **CComAggObject<** `contained` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(
    LPUNKNOWN pUnkOuter,
    CComAggObject<contained>** pp);
```

### <a name="parameters"></a>Parâmetros

*Pp*<br/>
[fora] Um ponteiro para um **\<CComAggObject**<em>continha</em> **>** ponteiro. Se `CreateInstance` não for bem sucedido, *pp* é definido como NULO.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem `AddRef` de referência de `Release` zero, então chame imediatamente, em seguida, use para liberar a referência no ponteiro do objeto quando você terminar.

Se você não precisar de acesso direto ao objeto, mas ainda `CoCreateInstance`quiser criar um novo objeto sem a sobrecarga de , use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

## <a name="ccomaggobjectfinalconstruct"></a><a name="finalconstruct"></a>CComAggObject::FinalConstruct

Chamado durante as fases finais de construção de objetos, este método realiza qualquer inicialização final no [membro m_contained.](#m_contained)

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomaggobjectfinalrelease"></a><a name="finalrelease"></a>CComAggObject::FinalRelease

Chamado durante a destruição de objetos, este método liberta o [membro m_contained.](#m_contained)

```
void FinalRelease();
```

## <a name="ccomaggobjectm_contained"></a><a name="m_contained"></a>CComAggObject::m_contained

Um objeto [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) derivado de sua classe.

```
CComContainedObject<contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*Contido*<br/>
[em] Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de quaisquer outras interfaces que você deseja suportar no objeto.

### <a name="remarks"></a>Comentários

Todas `IUnknown` as `m_contained` chamadas são delegadas para o desconhecido exterior.

## <a name="ccomaggobjectqueryinterface"></a><a name="queryinterface"></a>CComAggObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O identificador da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*. Se o objeto não suportar essa interface, *ppvObject* será definido como NULL.

*Pp*<br/>
[fora] Um ponteiro para o ponteiro `Q`de interface identificado por tipo . Se o objeto não suportar essa interface, *pp* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a interface `IUnknown`solicitada `QueryInterface` for, retorne um ponteiro para `IUnknown` o próprio objeto agregado e incrementa a contagem de referência. Caso contrário, este método consulta a `CComContainedObject` interface através do membro, [m_contained](#m_contained).

## <a name="ccomaggobjectrelease"></a><a name="release"></a>CComAggObject::Liberação

Decreta a contagem de referência no objeto agregado.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Nas compilações de `Release` depuração, retorna um valor que pode ser útil para diagnósticos ou testes. Em construções não-depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Confira também

[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)<br/>
[Declare_only_aggregatable](aggregation-and-class-factory-macros.md#declare_only_aggregatable)<br/>
[DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
