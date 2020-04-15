---
title: Classe CComPolyObject
ms.date: 11/04/2016
f1_keywords:
- CComPolyObject
- ATLCOM/ATL::CComPolyObject
- ATLCOM/ATL::CComPolyObject::CComPolyObject
- ATLCOM/ATL::CComPolyObject::AddRef
- ATLCOM/ATL::CComPolyObject::CreateInstance
- ATLCOM/ATL::CComPolyObject::FinalConstruct
- ATLCOM/ATL::CComPolyObject::FinalRelease
- ATLCOM/ATL::CComPolyObject::QueryInterface
- ATLCOM/ATL::CComPolyObject::Release
- ATLCOM/ATL::CComPolyObject::m_contained
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComPolyObject class
ms.assetid: eaf67c18-e855-48ca-9b15-f1df3106121b
ms.openlocfilehash: e30afef455db5f83afca8ff9e515f39f015c3b8a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327567"
---
# <a name="ccompolyobject-class"></a>Classe CComPolyObject

Esta classe `IUnknown` implementa para um objeto agregado ou não agregado.

## <a name="syntax"></a>Sintaxe

```
template<class contained>
class CComPolyObject : public IUnknown,
      public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*Contido*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de quaisquer outras interfaces que você deseja suportar no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Ccompolyobject::CCompolyobject](#ccompolyobject)|O construtor.|
|[Ccompolyobject::~CCompolyobject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCompolyobject::Addref](#addref)|Incrementa a contagem de referência do objeto.|
|[CComPolyObject::CreateInstance](#createinstance)|(Estática) Permite criar um novo objeto `contained` **>** **de<CComPolyObject** sem a sobrecarga do [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).|
|[Ccompolyobject::FinalConstruct](#finalconstruct)|Realiza a inicialização final de `m_contained`.|
|[CCompolyobject::Finalrelease](#finalrelease)|Realiza a `m_contained`destruição final de .|
|[CComPolyObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CCompolyObject::liberação](#release)|Decreta a contagem de referência do objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::m_contained](#m_contained)|Os `IUnknown` delegados ligam para o desconhecido externo `IUnknown` se o objeto está agregado ou para o objeto se o objeto não estiver agregado.|

## <a name="remarks"></a>Comentários

`CComPolyObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado ou não agregado.

Quando uma `CComPolyObject` instância é criada, o valor do desconhecido externo é verificado. Se for NULO, `IUnknown` é implementado para um objeto não agregado. Se o desconhecido externo `IUnknown` não for NULO, é implementado para um objeto agregado.

A vantagem `CComPolyObject` de usar é que você evita ter [CComAggObject](../../atl/reference/ccomaggobject-class.md) e [CComObject](../../atl/reference/ccomobject-class.md) em seu módulo para lidar com os casos agregados e não agregados. Um `CComPolyObject` único objeto lida com ambos os casos. Isso significa que apenas uma cópia do vtable e uma cópia das funções existem em seu módulo. Se o seu vtable for grande, isso pode diminuir substancialmente o tamanho do seu módulo. No entanto, se o `CComPolyObject` seu vtable for pequeno, o uso pode resultar em um tamanho de `CComAggObject` módulo `CComObject`ligeiramente maior, porque não é otimizado para um objeto agregado ou não agregado, como são e .

Se a DECLARE_POLY_AGGREGATABLE macro for especificada na `CComPolyObject` definição de classe do objeto, será usada para criar seu objeto. DECLARE_POLY_AGGREGATABLE serão automaticamente declarados se você usar o Assistente de Projeto ATL para criar um controle total ou controle do Internet Explorer.

Se agregado, `CComPolyObject` o objeto `IUnknown`tem seu próprio , `IUnknown`separado do objeto externo , e mantém sua própria contagem de referência. `CComPolyObject`usa [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) para delegar ao desconhecido externo.

Para obter mais informações sobre agregação, consulte o artigo [Fundamentos de Objetos ATL COM](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComPolyObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccompolyobjectaddref"></a><a name="addref"></a>CCompolyobject::Addref

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

## <a name="ccompolyobjectccompolyobject"></a><a name="ccompolyobject"></a>Ccompolyobject::CCompolyobject

O construtor.

```
CComPolyObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
[em] Um ponteiro para o desconhecido externo se o objeto deve ser agregado ou NULO se o objeto não estiver agregado.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro de dados, [m_contained](#m_contained)e incrementa a contagem de bloqueio do módulo.

O destructor decreta a contagem de bloqueio do módulo.

## <a name="ccompolyobjectccompolyobject"></a><a name="dtor"></a>Ccompolyobject::~CCompolyobject

O destruidor.

```
~CComPolyObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama [FinalRelease](#finalrelease)e decreta a contagem de bloqueio do módulo.

## <a name="ccompolyobjectcreateinstance"></a><a name="createinstance"></a>CComPolyObject::CreateInstance

Permite criar um novo objeto `contained` **>** **de<CComPolyObject** sem a sobrecarga do [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(
    LPUNKNOWN pUnkOuter,
    CComPolyObject<contained>** pp);
```

### <a name="parameters"></a>Parâmetros

*Pp*<br/>
[fora] Um ponteiro para um `contained` **>** ponteiro **de<CComPolyObject.** Se `CreateInstance` não for bem sucedido, *pp* é definido como NULO.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem `AddRef` de referência de `Release` zero, então chame imediatamente, em seguida, use para liberar a referência no ponteiro do objeto quando você terminar.

Se você não precisar de acesso direto ao objeto, mas ainda quiser `CoCreateInstance`criar um novo objeto sem a sobrecarga de , use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

## <a name="ccompolyobjectfinalconstruct"></a><a name="finalconstruct"></a>Ccompolyobject::FinalConstruct

Chamado durante as fases finais de construção de objetos, este método realiza qualquer inicialização final no [m_contained](#m_contained) membro de dados.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccompolyobjectfinalrelease"></a><a name="finalrelease"></a>CCompolyobject::Finalrelease

Chamado durante a destruição de objetos, este método libera o membro de dados [m_contained.](#m_contained)

```
void FinalRelease();
```

## <a name="ccompolyobjectm_contained"></a><a name="m_contained"></a>CComPolyObject::m_contained

Um objeto [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) derivado de sua classe.

```
CComContainedObject<contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*Contido*<br/>
[em] Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de quaisquer outras interfaces que você deseja suportar no objeto.

### <a name="remarks"></a>Comentários

`IUnknown`as `m_contained` chamadas são delegadas ao desconhecido externo se o `IUnknown` objeto estiver agregado ou ao deste objeto se o objeto não estiver agregado.

## <a name="ccompolyobjectqueryinterface"></a><a name="queryinterface"></a>CComPolyObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Q*<br/>
A interface COM.

*Iid*<br/>
[em] O identificador da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*. Se o objeto não suportar essa interface, *ppvObject* será definido como NULL.

*Pp*<br/>
[fora] Um ponteiro para a `__uuidof(Q)`interface identificado por .

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Para um objeto agregado, se a `IUnknown` `QueryInterface` interface solicitada for, retorne um `IUnknown` ponteiro para o próprio objeto agregado e incrementa a contagem de referência. Caso contrário, este método consulta a `CComContainedObject` interface através do membro de dados, [m_contained](#m_contained).

## <a name="ccompolyobjectrelease"></a><a name="release"></a>CCompolyObject::liberação

Decreta a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Nas compilações de `Release` depuração, retorna um valor que pode ser útil para diagnósticos ou testes. Em construções não `Release` depuradas, sempre retorna 0.

## <a name="see-also"></a>Confira também

[Classe CcomObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[DECLARE_POLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_poly_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
