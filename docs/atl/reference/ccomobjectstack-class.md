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
ms.openlocfilehash: 19fd226e617e4cdb1bba8a113b8984c36bf28d59
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62259580"
---
# <a name="ccomobjectstack-class"></a>Classe CComObjectStack

Essa classe cria um objeto COM temporário e a fornece com uma implementação de esqueleto da `IUnknown`.

## <a name="syntax"></a>Sintaxe

```
template <class  Base>
class CComObjectStack : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como qualquer outra interface para o qual você deseja dar suporte no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectStack::CComObjectStack](#ccomobjectstack)|O construtor.|
|[CComObjectStack::~CComObjectStack](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectStack::AddRef](#addref)|Retorna zero. No modo de depuração, chamadas `_ASSERTE`.|
|[CComObjectStack::QueryInterface](#queryinterface)|Retorna E_NOINTERFACE. No modo de depuração, chamadas `_ASSERTE`.|
|[CComObjectStack::Release](#release)|Retorna zero. No modo de depuração, chamadas `_ASSERTE`. ~|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectStack::m_hResFinalConstruct](#m_hresfinalconstruct)|Contém o HRESULT retornado durante a construção do `CComObjectStack` objeto.|

## <a name="remarks"></a>Comentários

`CComObjectStack` é usado para criar um objeto COM temporário e fornecer o objeto de uma implementação de esqueleto de `IUnknown`. Normalmente, o objeto é usado como uma variável local dentro de uma função (isto é, inserida na pilha). Uma vez que o objeto é destruído quando a função for concluída, a contagem de referência não é executada para aumentar a eficiência.

O exemplo a seguir mostra como criar um objeto COM usado dentro de uma função:

[!code-cpp[NVC_ATL_COM#42](../../atl/codesnippet/cpp/ccomobjectstack-class_1.cpp)]

O objeto temporário `Tempobj` é enviado para a pilha e automaticamente desaparece quando a função for concluída.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObjectStack`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="addref"></a>  CComObjectStack::AddRef

Retorna zero.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Retorna zero.

### <a name="remarks"></a>Comentários

No modo de depuração, chamadas `_ASSERTE`.

##  <a name="ccomobjectstack"></a>  CComObjectStack::CComObjectStack

O construtor.

```
CComObjectStack(void* = NULL);
```

### <a name="remarks"></a>Comentários

Chamadas `FinalConstruct` e, em seguida, define [m_hResFinalConstruct](#m_hresfinalconstruct) para o HRESULT retornado pela `FinalConstruct`. Se você não tiver derivadas sua classe base a partir [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md), você deve fornecer seu próprio `FinalConstruct` método. O destruidor chama `FinalRelease`.

##  <a name="dtor"></a>  CComObjectStack::~CComObjectStack

O destruidor.

```
CComObjectStack();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [FinalRelease](ccomobjectrootex-class.md#finalrelease).

##  <a name="m_hresfinalconstruct"></a>  CComObjectStack::m_hResFinalConstruct

Contém o HRESULT retornado ao chamar `FinalConstruct` durante a construção do `CComObjectStack` objeto.

```
HRESULT    m_hResFinalConstruct;
```

##  <a name="queryinterface"></a>  CComObjectStack::QueryInterface

Retorna E_NOINTERFACE.

```
HRESULT    QueryInterface(REFIID, void**);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOINTERFACE.

### <a name="remarks"></a>Comentários

No modo de depuração, chamadas `_ASSERTE`.

##  <a name="release"></a>  CComObjectStack::Release

Retorna zero.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Retorna zero.

### <a name="remarks"></a>Comentários

No modo de depuração, chamadas `_ASSERTE`.

## <a name="see-also"></a>Consulte também

[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
