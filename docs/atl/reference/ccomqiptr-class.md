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
ms.openlocfilehash: 64716d945ffbc6802ec23fb47523464246065192
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57298809"
---
# <a name="ccomqiptr-class"></a>Classe CComQIPtr

Uma classe de ponteiro inteligente para gerenciar os ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<class T, const IID* piid= &__uuidof(T)>
class CComQIPtr: public CComPtr<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

*piid*<br/>
Um ponteiro para o IID da *T*.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComQIPtr::CComQIPtr](#ccomqiptr)|Construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComQIPtr::operator =](#operator_eq)|Atribui um ponteiro para o ponteiro de membro.|

## <a name="remarks"></a>Comentários

Usa o ATL `CComQIPtr` e [CComPtr](../../atl/reference/ccomptr-class.md) para gerenciar os ponteiros de interface COM, sendo que ambos derivam [CComPtrBase](../../atl/reference/ccomptrbase-class.md). Ambas as classes executam por meio de chamadas para de contagem de referência automática `AddRef` e `Release`. Operadores sobrecarregados lidar com operações de ponteiro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComPtrBase](../../atl/reference/ccomptrbase-class.md)

[CComPtr](../../atl/reference/ccomptr-class.md)

`CComQIPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="ccomqiptr"></a>  CComQIPtr::CComQIPtr

O construtor.

```
CComQIPtr() throw();
CComQIPtr(T* lp) throw();
CComQIPtr(IUnknown* lp) throw();
CComQIPtr(const CComQIPtr<T, piid>& lp) throw();
```

### <a name="parameters"></a>Parâmetros

*lp*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

*piid*<br/>
Um ponteiro para o IID da *T*.

##  <a name="operator_eq"></a>  CComQIPtr::operator =

O operador de atribuição.

```
T* operator= (T* lp) throw();
T* operator= (const CComQIPtr<T, piid>& lp) throw();
T* operator= (IUnknown* lp) throw();
```

### <a name="parameters"></a>Parâmetros

*lp*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

*piid*<br/>
Um ponteiro para o IID da *T*.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a atualização `CComQIPtr` objeto.

## <a name="see-also"></a>Consulte também

[CComPtr::CComPtr](../../atl/reference/ccomptr-class.md#ccomptr)<br/>
[CComQIPtr::CComQIPtr](#ccomqiptr)<br/>
[Classe CComPtrBase](../../atl/reference/ccomptrbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)
