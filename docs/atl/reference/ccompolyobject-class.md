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
ms.openlocfilehash: deed29b5fb80ea8bbd06b3d50f45e38740b1619f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497147"
---
# <a name="ccompolyobject-class"></a>Classe CComPolyObject

Essa classe implementa `IUnknown` para um objeto agregado ou não agregado.

## <a name="syntax"></a>Sintaxe

```
template<class contained>
class CComPolyObject : public IUnknown,
      public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*presente*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de quaisquer outras interfaces às quais você deseja dar suporte no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::CComPolyObject](#ccompolyobject)|O construtor.|
|[CComPolyObject::~CComPolyObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::AddRef](#addref)|Incrementa a contagem de referência do objeto.|
|[CComPolyObject::CreateInstance](#createinstance)|Auto-estática Permite que você crie um novo objeto **CComPolyObject <** `contained` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).|
|[CComPolyObject::FinalConstruct](#finalconstruct)|Executa a inicialização final `m_contained`do.|
|[CComPolyObject::FinalRelease](#finalrelease)|Executa a destruição final `m_contained`do.|
|[CComPolyObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComPolyObject::Release](#release)|Decrementa a contagem de referência do objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::m_contained](#m_contained)|Delega `IUnknown` chamadas para a externa desconhecida se o objeto for agregado ou para o `IUnknown` do objeto se o objeto não for agregado.|

## <a name="remarks"></a>Comentários

`CComPolyObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado ou não agregado.

Quando uma instância do `CComPolyObject` é criada, o valor da externa Unknown é verificado. Se for NULL, `IUnknown` será implementado para um objeto não agregado. Se o desconhecido externo não for nulo, `IUnknown` será implementado para um objeto agregado.

A vantagem de usar `CComPolyObject` o é que você evita ter [CComAggObject](../../atl/reference/ccomaggobject-class.md) e [CComObject](../../atl/reference/ccomobject-class.md) em seu módulo para lidar com os casos agregados e não agregados. Um único `CComPolyObject` objeto trata ambos os casos. Isso significa que apenas uma cópia da vtable e uma cópia das funções existem no seu módulo. Se a vtable for grande, isso poderá diminuir substancialmente o tamanho do módulo. No entanto, se a vtable for pequena `CComPolyObject` , o uso do pode resultar em um tamanho de módulo ligeiramente maior porque ele não é otimizado para um objeto agregado ou `CComAggObject` não `CComObject`agregado, como são e.

Se a macro DECLARE_POLY_AGGREGATABLE for especificada na definição de classe do seu objeto `CComPolyObject` , será usada para criar seu objeto. DECLARE_POLY_AGGREGATABLE será declarado automaticamente se você usar o assistente de projeto do ATL para criar um controle total ou controle do Internet Explorer.

Se for agregado, `CComPolyObject` o objeto terá seu `IUnknown`próprio, separado `IUnknown`do objeto externo e manterá sua própria contagem de referência. `CComPolyObject`usa [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) para delegar para o desconhecido externo.

Para obter mais informações sobre agregação, consulte o artigo [Fundamentals de objetos com ATL](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComPolyObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="addref"></a>  CComPolyObject::AddRef

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

##  <a name="ccompolyobject"></a>  CComPolyObject::CComPolyObject

O construtor.

```
CComPolyObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
no Um ponteiro para o desconhecido externo se o objeto for agregado, ou NULL se o objeto não for agregado.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro de dados, [m_contained](#m_contained), e incrementa a contagem de bloqueios de módulo.

O destruidor decrementa a contagem de bloqueios de módulo.

##  <a name="dtor"></a>  CComPolyObject::~CComPolyObject

O destruidor.

```
~CComPolyObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama [FinalRelease](#finalrelease)e decrementa a contagem de bloqueios de módulo.

##  <a name="createinstance"></a>  CComPolyObject::CreateInstance

Permite que você crie um novo objeto **CComPolyObject <** `contained` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(
    LPUNKNOWN pUnkOuter,
    CComPolyObject<contained>** pp);
```

### <a name="parameters"></a>Parâmetros

*pp*<br/>
fora Um ponteiro para um ponteiro de **<** `contained` **>** CComPolyObject. Se `CreateInstance` não for bem-sucedida, *PP* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem de referência igual a zero, `AddRef` portanto, chame imediatamente `Release` e, em seguida, use para liberar a referência no ponteiro do objeto quando terminar.

Se você não precisar de acesso direto ao objeto, mas ainda quiser criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass:: CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

##  <a name="finalconstruct"></a>  CComPolyObject::FinalConstruct

Chamado durante os estágios finais da construção do objeto, esse método executa qualquer inicialização final no membro de dados [m_contained](#m_contained) .

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="finalrelease"></a>  CComPolyObject::FinalRelease

Chamado durante a destruição de objeto, esse método libera o membro de dados [m_contained](#m_contained) .

```
void FinalRelease();
```

##  <a name="m_contained"></a>  CComPolyObject::m_contained

Um objeto [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) derivado de sua classe.

```
CComContainedObject<contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*presente*<br/>
no Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de quaisquer outras interfaces às quais você deseja dar suporte no objeto.

### <a name="remarks"></a>Comentários

`IUnknown`as chamadas `IUnknown` serão delegadas ao externo desconhecido se o objeto for agregado ou ao desse objeto se o objeto não for agregado. `m_contained`

##  <a name="queryinterface"></a>  CComPolyObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Q*<br/>
A interface COM.

*iid*<br/>
no O identificador da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado pelo *IID*. Se o objeto não oferecer suporte a essa interface, *ppvObject* será definido como NULL.

*pp*<br/>
fora Um ponteiro para a interface identificada `__uuidof(Q)`por.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Para um objeto agregado, se a interface solicitada `IUnknown`for `QueryInterface` , retorna um ponteiro para o próprio `IUnknown` objeto agregado e incrementa a contagem de referência. Caso contrário, esse método consulta a interface por meio `CComContainedObject` do membro de dados, [m_contained](#m_contained).

##  <a name="release"></a>  CComPolyObject::Release

Decrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações de `Release` depuração, retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações não depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[DECLARE_POLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_poly_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
