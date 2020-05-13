---
title: Classe CcomobjectnoLock
ms.date: 11/04/2016
f1_keywords:
- CComObjectNoLock
- ATLCOM/ATL::CComObjectNoLock
- ATLCOM/ATL::CComObjectNoLock::CComObjectNoLock
- ATLCOM/ATL::CComObjectNoLock::AddRef
- ATLCOM/ATL::CComObjectNoLock::QueryInterface
- ATLCOM/ATL::CComObjectNoLock::Release
helpviewer_keywords:
- CComObjectNoLock class
ms.assetid: 288c6506-7da8-4127-8d58-7f4bd779539a
ms.openlocfilehash: c190f495e284e98b27a6c6dc2099a8dfc4b1693d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327610"
---
# <a name="ccomobjectnolock-class"></a>Classe CcomobjectnoLock

Esta classe `IUnknown` implementa para um objeto não agregado, mas não incrementa a contagem de bloqueio do módulo no construtor.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComObjectNoLock : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de qualquer outra interface que você deseja suportar no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Ccomobjectnolock::CcomobjectNolock](#ccomobjectnolock)|Construtor.|
|[Ccomobjectnolock::~CcomobjectNolock](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Ccomobjectnolock::Addref](#addref)|Incrementa a contagem de referência no objeto.|
|[CComObjectNoLock::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada.|
|[Ccomobjectnolock::lançamento](#release)|Decreta a contagem de referência no objeto.|

## <a name="remarks"></a>Comentários

`CComObjectNoLock`é semelhante ao [CComObject](../../atl/reference/ccomobject-class.md) na qual implementa [o IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto não agregado; no `CComObjectNoLock` entanto, não incrementa a contagem de bloqueio do módulo no construtor.

A ATL usa `CComObjectNoLock` internamente para fábricas de classe. Em geral, você não usará esta classe diretamente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObjectNoLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomobjectnolockaddref"></a><a name="addref"></a>Ccomobjectnolock::Addref

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

## <a name="ccomobjectnolockccomobjectnolock"></a><a name="ccomobjectnolock"></a>Ccomobjectnolock::CcomobjectNolock

O construtor. Ao contrário [do CComObject,](../../atl/reference/ccomobject-class.md)não incrementa a contagem de bloqueios do módulo.

```
CComObjectNoLock(void* = NULL);
```

### <a name="parameters"></a>Parâmetros

<em>void\*</em><br/>
[em] Este parâmetro não nomeado não é usado. Existe para simetria com `CComXXXObjectXXX` outros construtores.

## <a name="ccomobjectnolockccomobjectnolock"></a><a name="dtor"></a>Ccomobjectnolock::~CcomobjectNolock

O destruidor.

```
~CComObjectNoLock();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [Deliberação Final](ccomobjectrootex-class.md#finalrelease).

## <a name="ccomobjectnolockqueryinterface"></a><a name="queryinterface"></a>CComObjectNoLock::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O identificador da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*. Se o objeto não suportar essa interface, *ppvObject* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomobjectnolockrelease"></a><a name="release"></a>Ccomobjectnolock::lançamento

Decreta a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Nas compilações de `Release` depuração, retorna um valor que pode ser útil para diagnósticos ou testes. Em construções não-depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
