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
ms.openlocfilehash: 8b05284104f9d2e5e7704bceaee6f8adf9a33aac
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497653"
---
# <a name="ccomaggobject-class"></a>Classe CComAggObject

Essa classe implementa a interface [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado. Por definição, um objeto agregado está contido em um objeto externo. A `CComAggObject` classe é semelhante à [classe CComObject](../../atl/reference/ccomobject-class.md), exceto pelo fato de que ela expõe uma interface que está diretamente acessível a clientes externos.

## <a name="syntax"></a>Sintaxe

```
template<class contained>
class CComAggObject : public IUnknown,
   public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*presente*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de quaisquer outras interfaces às quais você deseja dar suporte no objeto.

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
|[CComAggObject::CreateInstance](#createinstance)|Essa função estática permite que você crie um novo objeto **CComAggObject <** `contained` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).|
|[CComAggObject::FinalConstruct](#finalconstruct)|Executa a inicialização final `m_contained`do.|
|[CComAggObject::FinalRelease](#finalrelease)|Executa a destruição final `m_contained`do.|
|[CComAggObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComAggObject::Release](#release)|Decrementa a contagem de referência no objeto agregado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAggObject::m_contained](#m_contained)|Delega `IUnknown` chamadas para a externa desconhecidas.|

## <a name="remarks"></a>Comentários

`CComAggObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado. `CComAggObject`tem sua própria `IUnknown` interface, separada da interface do `IUnknown` objeto externo e mantém sua própria contagem de referência.

Para obter mais informações sobre agregação, consulte o artigo [Fundamentals de objetos com ATL](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComAggObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

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
no O desconhecido externo.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro, [m_contained](#m_contained), e incrementa a contagem de bloqueios de módulo.

O destruidor decrementa a contagem de bloqueios de módulo.

##  <a name="dtor"></a>CComAggObject:: ~ CComAggObject

O destruidor.

```
~CComAggObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama [FinalRelease](#finalrelease)e decrementa a contagem de bloqueios de módulo.

##  <a name="createinstance"></a>  CComAggObject::CreateInstance

Essa função estática permite que você crie um novo objeto **CComAggObject <** `contained` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(
    LPUNKNOWN pUnkOuter,
    CComAggObject<contained>** pp);
```

### <a name="parameters"></a>Parâmetros

*pp*<br/>
fora Um ponteiro para um ponteiro<em>contido</em> **>** **CComAggObject\<** . Se `CreateInstance` não for bem-sucedida, *PP* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem de referência igual a zero, `AddRef` portanto, chame imediatamente `Release` e, em seguida, use para liberar a referência no ponteiro do objeto quando terminar.

Se você não precisar de acesso direto ao objeto, mas ainda quiser criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass:: CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

##  <a name="finalconstruct"></a>  CComAggObject::FinalConstruct

Chamado durante os estágios finais da construção do objeto, esse método executa qualquer inicialização final no membro [m_contained](#m_contained) .

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="finalrelease"></a>  CComAggObject::FinalRelease

Chamado durante a destruição de objeto, esse método libera o membro [m_contained](#m_contained) .

```
void FinalRelease();
```

##  <a name="m_contained"></a>  CComAggObject::m_contained

Um objeto [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) derivado de sua classe.

```
CComContainedObject<contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*presente*<br/>
no Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de quaisquer outras interfaces às quais você deseja dar suporte no objeto.

### <a name="remarks"></a>Comentários

Todas `IUnknown` as chamadas `m_contained` por meio são delegadas para o desconhecido externo.

##  <a name="queryinterface"></a>  CComAggObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
no O identificador da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado pelo *IID*. Se o objeto não oferecer suporte a essa interface, *ppvObject* será definido como NULL.

*pp*<br/>
fora Um ponteiro para o ponteiro de interface identificado pelo `Q`tipo. Se o objeto não oferecer suporte a essa interface, *PP* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se a interface solicitada `IUnknown`for `QueryInterface` , retornará um ponteiro para o próprio `IUnknown` objeto agregado e incrementará a contagem de referência. Caso contrário, esse método consultará a interface por `CComContainedObject` meio do membro, [m_contained](#m_contained).

##  <a name="release"></a>  CComAggObject::Release

Decrementa a contagem de referência no objeto agregado.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações de `Release` depuração, retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações não depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)<br/>
[DECLARE_ONLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_only_aggregatable)<br/>
[DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
