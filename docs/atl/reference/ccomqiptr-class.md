---
title: Classe CComQIPtr
ms.date: 11/04/2016
f1_keywords:
- CComQIPtr
- ATLCOMCLI/ATL::CComQIPtr
- ATLCOMCLI/ATL::CComQIPtr::CComQIPtr
helpviewer_keywords:
- CComQIPtr class
ms.assetid: 969cacb5-05b6-4af4-b683-24911d70242d
ms.openlocfilehash: 2b1d8b92fbc5e95a5061956bafc4922d249a6f18
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327425"
---
# <a name="ccomqiptr-class"></a>Classe CComQIPtr

Uma classe de ponteiro inteligente para gerenciar ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<class T, const IID* piid= &__uuidof(T)>
class CComQIPtr: public CComPtr<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

*Piid*<br/>
Um ponteiro para o IID de *T*.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComQIPtr::CComQIPtr](#ccomqiptr)|Construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComQIPtr::operador =](#operator_eq)|Atribui um ponteiro ao ponteiro do membro.|

## <a name="remarks"></a>Comentários

O ATL usa `CComQIPtr` e o [CComPtr](../../atl/reference/ccomptr-class.md) para gerenciar ponteiros de interface COM, ambos derivados do [CComPtrBase](../../atl/reference/ccomptrbase-class.md). Ambas as classes realizam contagem automática de referência através de chamadas para `AddRef` e `Release`. Operadores sobrecarregados lidam com operações de ponteiros.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Ccomptrbase](../../atl/reference/ccomptrbase-class.md)

[Ccomptr](../../atl/reference/ccomptr-class.md)

`CComQIPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli.h

## <a name="ccomqiptrccomqiptr"></a><a name="ccomqiptr"></a>CComQIPtr::CComQIPtr

O construtor.

```
CComQIPtr() throw();
CComQIPtr(T* lp) throw();
CComQIPtr(IUnknown* lp) throw();
CComQIPtr(const CComQIPtr<T, piid>& lp) throw();
```

### <a name="parameters"></a>Parâmetros

*Lp*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

*Piid*<br/>
Um ponteiro para o IID de *T*.

## <a name="ccomqiptroperator-"></a><a name="operator_eq"></a>CComQIPtr::operador =

O operador de atribuição.

```
T* operator= (T* lp) throw();
T* operator= (const CComQIPtr<T, piid>& lp) throw();
T* operator= (IUnknown* lp) throw();
```

### <a name="parameters"></a>Parâmetros

*Lp*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

*Piid*<br/>
Um ponteiro para o IID de *T*.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `CComQIPtr` para o objeto atualizado.

## <a name="see-also"></a>Confira também

[CComPtr::CComPtr](../../atl/reference/ccomptr-class.md#ccomptr)<br/>
[CComQIPtr::CComQIPtr](#ccomqiptr)<br/>
[Classe CComPtrBase](../../atl/reference/ccomptrbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)
