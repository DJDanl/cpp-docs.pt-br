---
title: Classe CComObjectStack
ms.date: 11/04/2016
f1_keywords:
- CComObjectStack
- ATLCOM/ATL::CComObjectStack
- ATLCOM/ATL::CComObjectStack::CComObjectStack
- ATLCOM/ATL::CComObjectStack::AddRef
- ATLCOM/ATL::CComObjectStack::QueryInterface
- ATLCOM/ATL::CComObjectStack::Release
- ATLCOM/ATL::CComObjectStack::m_hResFinalConstruct
helpviewer_keywords:
- CComObjectStack class
ms.assetid: 3da72c40-c834-45f6-bb76-6ac204028d80
ms.openlocfilehash: 8c3fd56635da8b80c84f6151009586b7bd2b4341
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327581"
---
# <a name="ccomobjectstack-class"></a>Classe CComObjectStack

Esta classe cria um objeto COM temporário e fornece-lhe uma implementação esquelética de `IUnknown`.

## <a name="syntax"></a>Sintaxe

```
template <class  Base>
class CComObjectStack : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de qualquer outra interface que você deseja suportar no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectStack::CComObjectStack](#ccomobjectstack)|O construtor.|
|[CComObjectStack::~CComObjectStack](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectStack::Addref](#addref)|Retorna zero. No modo de `_ASSERTE`depuração, chamadas .|
|[CComObjectStack::QueryInterface](#queryinterface)|Retorna E_NOINTERFACE. No modo de `_ASSERTE`depuração, chamadas .|
|[CComObjectStack::versão](#release)|Retorna zero. No modo de `_ASSERTE`depuração, chamadas . ~|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectStack::m_hResFinalConstruct](#m_hresfinalconstruct)|Contém o HRESULT devolvido durante `CComObjectStack` a construção do objeto.|

## <a name="remarks"></a>Comentários

`CComObjectStack`é usado para criar um objeto COM temporário e `IUnknown`fornecer ao objeto uma implementação esquelética de . Normalmente, o objeto é usado como uma variável local dentro de uma função (ou seja, empurrado para a pilha). Uma vez que o objeto é destruído quando a função termina, a contagem de referência não é realizada para aumentar a eficiência.

O exemplo a seguir mostra como criar um objeto COM usado dentro de uma função:

[!code-cpp[NVC_ATL_COM#42](../../atl/codesnippet/cpp/ccomobjectstack-class_1.cpp)]

O objeto `Tempobj` temporário é empurrado para a pilha e desaparece automaticamente quando a função termina.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObjectStack`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomobjectstackaddref"></a><a name="addref"></a>CComObjectStack::Addref

Retorna zero.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Retorna zero.

### <a name="remarks"></a>Comentários

No modo de `_ASSERTE`depuração, chamadas .

## <a name="ccomobjectstackccomobjectstack"></a><a name="ccomobjectstack"></a>CComObjectStack::CComObjectStack

O construtor.

```
CComObjectStack(void* = NULL);
```

### <a name="remarks"></a>Comentários

Chama `FinalConstruct` e, [m_hResFinalConstruct](#m_hresfinalconstruct) em seguida, define `FinalConstruct`m_hResFinalConstruct para o HRESULT retornado por . Se você não tiver derivado sua classe base do [CComObjectRoot,](../../atl/reference/ccomobjectroot-class.md)você deve fornecer seu próprio `FinalConstruct` método. O destruidor chama `FinalRelease`.

## <a name="ccomobjectstackccomobjectstack"></a><a name="dtor"></a>CComObjectStack::~CComObjectStack

O destruidor.

```
CComObjectStack();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [Deliberação Final](ccomobjectrootex-class.md#finalrelease).

## <a name="ccomobjectstackm_hresfinalconstruct"></a><a name="m_hresfinalconstruct"></a>CComObjectStack::m_hResFinalConstruct

Contém o HRESULT retornado de `FinalConstruct` `CComObjectStack` chamada durante a construção do objeto.

```
HRESULT    m_hResFinalConstruct;
```

## <a name="ccomobjectstackqueryinterface"></a><a name="queryinterface"></a>CComObjectStack::QueryInterface

Retorna E_NOINTERFACE.

```
HRESULT    QueryInterface(REFIID, void**);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOINTERFACE.

### <a name="remarks"></a>Comentários

No modo de `_ASSERTE`depuração, chamadas .

## <a name="ccomobjectstackrelease"></a><a name="release"></a>CComObjectStack::versão

Retorna zero.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Retorna zero.

### <a name="remarks"></a>Comentários

No modo de `_ASSERTE`depuração, chamadas .

## <a name="see-also"></a>Confira também

[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CcomObjectGlobal](../../atl/reference/ccomobjectglobal-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
