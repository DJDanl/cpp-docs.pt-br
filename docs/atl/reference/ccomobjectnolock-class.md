---
title: Classe CComObjectNoLock
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
ms.openlocfilehash: 9253c7495f4d13ed6ce609988251d8abd09592ad
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497029"
---
# <a name="ccomobjectnolock-class"></a>Classe CComObjectNoLock

Essa classe implementa `IUnknown` para um objeto não agregado, mas não incrementa a contagem de bloqueios do módulo no construtor.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComObjectNoLock : public Base
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de qualquer outra interface à qual você deseja dar suporte no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectNoLock::CComObjectNoLock](#ccomobjectnolock)|Construtor.|
|[CComObjectNoLock::~CComObjectNoLock](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComObjectNoLock::AddRef](#addref)|Incrementa a contagem de referência no objeto.|
|[CComObjectNoLock::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada.|
|[CComObjectNoLock::Release](#release)|Decrementa a contagem de referência no objeto.|

## <a name="remarks"></a>Comentários

`CComObjectNoLock`é semelhante a [CComObject](../../atl/reference/ccomobject-class.md) , pois implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto não agregado; no entanto, `CComObjectNoLock` o não incrementa a contagem de bloqueios do módulo no construtor.

A ATL `CComObjectNoLock` usa internamente para fábricas de classes. Em geral, você não usará essa classe diretamente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComObjectNoLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="addref"></a>  CComObjectNoLock::AddRef

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

##  <a name="ccomobjectnolock"></a>  CComObjectNoLock::CComObjectNoLock

O construtor. Ao contrário de [CComObject](../../atl/reference/ccomobject-class.md), o não incrementa a contagem de bloqueios de módulo.

```
CComObjectNoLock(void* = NULL);
```

### <a name="parameters"></a>Parâmetros

<em>void\*</em><br/>
no Esse parâmetro sem nome não é usado. Ele existe para simetria com outros `CComXXXObjectXXX` construtores.

##  <a name="dtor"></a>  CComObjectNoLock::~CComObjectNoLock

O destruidor.

```
~CComObjectNoLock();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados e chama [FinalRelease](ccomobjectrootex-class.md#finalrelease).

##  <a name="queryinterface"></a>  CComObjectNoLock::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
no O identificador da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado pelo *IID*. Se o objeto não oferecer suporte a essa interface, *ppvObject* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="release"></a>  CComObjectNoLock::Release

Decrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações de `Release` depuração, retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações não depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
