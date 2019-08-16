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
ms.openlocfilehash: a2051932413d8658eb7cedb67ed0eab2077b599d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497142"
---
# <a name="ccomobject-class"></a>Classe CComObject

Essa classe implementa `IUnknown` para um objeto não agregado.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de quaisquer outras interfaces às quais você deseja dar suporte no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObject::CComObject](#ccomobject)|O construtor.|
|[CComObject::~CComObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObject::AddRef](#addref)|Incrementa a contagem de referência no objeto.|
|[CComObject::CreateInstance](#createinstance)|Auto-estática Cria um novo `CComObject` objeto.|
|[CComObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComObject::Release](#release)|Decrementa a contagem de referência no objeto.|

## <a name="remarks"></a>Comentários

`CComObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto não agregado. No entanto, `QueryInterface`as `AddRef`chamadas para `Release` , e são delegadas para `CComObjectRootEx`.

Para obter mais informações sobre `CComObject`como usar o, consulte o artigo [Fundamentals de objetos com ATL](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="addref"></a>  CComObject::AddRef

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Essa função retorna a nova contagem de referência incrementada no objeto. Esse valor pode ser útil para diagnóstico ou teste.

##  <a name="ccomobject"></a>  CComObject::CComObject

O Construtor incrementa a contagem de bloqueios de módulo.

```
CComObject(void* = NULL);
```

### <a name="parameters"></a>Parâmetros

<em>void\*</em><br/>
no Esse parâmetro sem nome não é usado. Ele existe para simetria com outros `CComXXXObjectXXX` construtores.

### <a name="remarks"></a>Comentários

O destruidor o decrementa.

Se um `CComObject`objeto derivado for construído com êxito usando o **novo** operador, a contagem de referência inicial será 0. Para definir a contagem de referência para o valor adequado (1), faça uma chamada para a função [AddRef](#addref) .

##  <a name="dtor"></a>CComObject:: ~ CComObject

O destruidor.

```
CComObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama [FinalRelease](ccomobjectrootex-class.md#finalrelease)e decrementa a contagem de bloqueios de módulo.

##  <a name="createinstance"></a>  CComObject::CreateInstance

Essa função estática permite que você crie um novo objeto de **<** `Base` **>** CComObject, sem a sobrecarga de [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(CComObject<Base>** pp);
```

### <a name="parameters"></a>Parâmetros

*pp*<br/>
fora Um ponteiro para um ponteiro de **<** `Base` **>** CComObject. Se `CreateInstance` não for bem-sucedida, *PP* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem de referência igual a zero, `AddRef` portanto, chame imediatamente `Release` e, em seguida, use para liberar a referência no ponteiro do objeto quando terminar.

Se você não precisar de acesso direto ao objeto, mas ainda quiser criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass:: CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#38](../../atl/codesnippet/cpp/ccomobject-class_1.h)]

[!code-cpp[NVC_ATL_COM#39](../../atl/codesnippet/cpp/ccomobject-class_2.cpp)]

##  <a name="queryinterface"></a>  CComObject::QueryInterface

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

##  <a name="release"></a>CComObject:: versão

Decrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Essa função retorna a nova contagem de referência decrementada no objeto. Em compilações de depuração, o valor de retorno pode ser útil para diagnóstico ou teste. Em compilações não depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)<br/>
[DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
