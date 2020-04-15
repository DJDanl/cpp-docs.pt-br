---
title: Classe CcomObjectGlobal
ms.date: 11/04/2016
f1_keywords:
- CComObjectGlobal
- ATLCOM/ATL::CComObjectGlobal
- ATLCOM/ATL::CComObjectGlobal::CComObjectGlobal
- ATLCOM/ATL::CComObjectGlobal::AddRef
- ATLCOM/ATL::CComObjectGlobal::QueryInterface
- ATLCOM/ATL::CComObjectGlobal::Release
- ATLCOM/ATL::CComObjectGlobal::m_hResFinalConstruct
helpviewer_keywords:
- CComObjectGlobal class
ms.assetid: 79bdee55-66e4-4536-b5b3-bdf09f78b9a6
ms.openlocfilehash: 9a784584179186cdf1e63c1ec43cad4d59391ec3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327629"
---
# <a name="ccomobjectglobal-class"></a>Classe CcomObjectGlobal

Esta classe gerencia uma contagem de `Base` referência no módulo que contém seu objeto.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComObjectGlobal : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de qualquer outra interface que você deseja suportar no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CcomObjectGlobal::CComObjectGlobal](#ccomobjectglobal)|O construtor.|
|[CcomObjectGlobal::~CComObjectGlobal](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CcomObjectGlobal::Addref](#addref)|Implementa um `AddRef`global.|
|[CComObjectGlobal::QueryInterface](#queryinterface)|Implementa um `QueryInterface`global.|
|[CComObjectGlobal::Lançamento](#release)|Implementa um `Release`global.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectGlobal::m_hResFinalConstruct](#m_hresfinalconstruct)|Contém o HRESULT devolvido durante `CComObjectGlobal` a construção do objeto.|

## <a name="remarks"></a>Comentários

`CComObjectGlobal`gerencia uma contagem de referência `Base` no módulo que contém seu objeto. `CComObjectGlobal`garante que seu objeto não será excluído enquanto o módulo não for liberado. Seu objeto só será removido quando a contagem de referência em todo o módulo for zerada.

Por exemplo, `CComObjectGlobal`usando , uma fábrica de classe pode conter um objeto global comum que é compartilhado por todos os seus clientes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObjectGlobal`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomobjectglobaladdref"></a><a name="addref"></a>CcomObjectGlobal::Addref

Incrementa a contagem de referência do objeto por 1.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos e testes.

### <a name="remarks"></a>Comentários

Por `AddRef` padrão, `_Module::Lock`chamadas `_Module` , onde está a instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou uma classe derivada dele.

## <a name="ccomobjectglobalccomobjectglobal"></a><a name="ccomobjectglobal"></a>CcomObjectGlobal::CComObjectGlobal

O construtor. Chama `FinalConstruct` e, em `HRESULT` seguida, `FinalConstruct`define [m_hResFinalConstruct](#m_hresfinalconstruct) para o devolvido por .

```
CComObjectGlobal(void* = NULL));
```

### <a name="remarks"></a>Comentários

Se você não tiver derivado sua classe base do [CComObjectRoot,](../../atl/reference/ccomobjectroot-class.md)você deve fornecer seu próprio `FinalConstruct` método. O destruidor chama `FinalRelease`.

## <a name="ccomobjectglobalccomobjectglobal"></a><a name="dtor"></a>CcomObjectGlobal::~CComObjectGlobal

O destruidor.

```
CComObjectGlobal();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [Deliberação Final](ccomobjectrootex-class.md#finalrelease).

## <a name="ccomobjectglobalm_hresfinalconstruct"></a><a name="m_hresfinalconstruct"></a>CComObjectGlobal::m_hResFinalConstruct

Contém o HRESULT `FinalConstruct` da chamada `CComObjectGlobal` durante a construção do objeto.

```
HRESULT m_hResFinalConstruct;
```

## <a name="ccomobjectglobalqueryinterface"></a><a name="queryinterface"></a>CComObjectGlobal::QueryInterface

Recupera um ponteiro para o ponteiro de interface solicitado.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por iid ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`QueryInterface` somente lida com interfaces na tabela de mapa COM.

## <a name="ccomobjectglobalrelease"></a><a name="release"></a>CComObjectGlobal::Lançamento

Diminui a contagem de referência do objeto por 1.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Nas compilações de `Release` depuração, retorna um valor que pode ser útil para diagnósticos e testes. Em construções não-depuradas, `Release` sempre retorna 0.

### <a name="remarks"></a>Comentários

Por `Release` padrão, `_Module::Unlock`chamadas `_Module` , onde está a instância global do [CComModule](../../atl/reference/ccommodule-class.md) ou uma classe derivada dele.

## <a name="see-also"></a>Confira também

[Classe CComObjectStack](../../atl/reference/ccomobjectstack-class.md)<br/>
[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
