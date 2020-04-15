---
title: Classe CComObject
ms.date: 11/04/2016
f1_keywords:
- CComObject
- ATLCOM/ATL::CComObject
- ATLCOM/ATL::CComObject::CComObject
- ATLCOM/ATL::CComObject::AddRef
- ATLCOM/ATL::CComObject::CreateInstance
- ATLCOM/ATL::CComObject::QueryInterface
- ATLCOM/ATL::CComObject::Release
helpviewer_keywords:
- CComObject class
ms.assetid: e2b6433b-6349-4749-b4bc-acbd7a22c8b0
ms.openlocfilehash: de6ffb45fe5c6f73ab656d5c6185b70d9f5edd38
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327640"
---
# <a name="ccomobject-class"></a>Classe CComObject

Esta classe `IUnknown` implementa para um objeto não agregado.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de quaisquer outras interfaces que você deseja suportar no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObject::CComObject](#ccomobject)|O construtor.|
|[CComObject::~CComObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObject::Addref](#addref)|Incrementa a contagem de referência no objeto.|
|[CComObject::CreateInstance](#createinstance)|(Estática) Cria um `CComObject` novo objeto.|
|[CComObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComObject::Lançamento](#release)|Decreta a contagem de referência no objeto.|

## <a name="remarks"></a>Comentários

`CComObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto não agregado. No entanto, `AddRef`chamadas `Release` para `QueryInterface`, `CComObjectRootEx`e são delegadas para .

Para obter mais `CComObject`informações sobre como usar, consulte o artigo [Fundamentos de Objetos ATL COM](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomobjectaddref"></a><a name="addref"></a>CComObject::Addref

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Esta função retorna a nova contagem de referência incrementada no objeto. Este valor pode ser útil para diagnósticos ou testes.

## <a name="ccomobjectccomobject"></a><a name="ccomobject"></a>CComObject::CComObject

O construtor incrementa a contagem de bloqueios do módulo.

```
CComObject(void* = NULL);
```

### <a name="parameters"></a>Parâmetros

<em>void\*</em><br/>
[em] Este parâmetro não nomeado não é usado. Existe para simetria com `CComXXXObjectXXX` outros construtores.

### <a name="remarks"></a>Comentários

O destruidor decreta-o.

Se `CComObject`um objeto derivado for construído com sucesso usando o **novo** operador, a contagem inicial de referência será de 0. Para definir a contagem de referência para o valor adequado (1), faça uma chamada para a função [AddRef.](#addref)

## <a name="ccomobjectccomobject"></a><a name="dtor"></a>CComObject::~CComObject

O destruidor.

```
CComObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama [FinalRelease](ccomobjectrootex-class.md#finalrelease)e decreta a contagem de bloqueio do módulo.

## <a name="ccomobjectcreateinstance"></a><a name="createinstance"></a>CComObject::CreateInstance

Esta função estática permite criar um novo objeto **CComObject<,** `Base` **>** sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(CComObject<Base>** pp);
```

### <a name="parameters"></a>Parâmetros

*Pp*<br/>
[fora] Um ponteiro para um ponteiro `Base` **>** **de<CComObject.** Se `CreateInstance` não for bem sucedido, *pp* é definido como NULO.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem `AddRef` de referência de `Release` zero, então chame imediatamente, em seguida, use para liberar a referência no ponteiro do objeto quando você terminar.

Se você não precisar de acesso direto ao objeto, mas ainda `CoCreateInstance`quiser criar um novo objeto sem a sobrecarga de , use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#38](../../atl/codesnippet/cpp/ccomobject-class_1.h)]

[!code-cpp[NVC_ATL_COM#39](../../atl/codesnippet/cpp/ccomobject-class_2.cpp)]

## <a name="ccomobjectqueryinterface"></a><a name="queryinterface"></a>CComObject::QueryInterface

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

## <a name="ccomobjectrelease"></a><a name="release"></a>CComObject::Lançamento

Decreta a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Esta função retorna a nova contagem de referência decretada no objeto. Nas compilações de depuração, o valor de retorno pode ser útil para diagnósticos ou testes. Em construções não-depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Confira também

[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)<br/>
[DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
