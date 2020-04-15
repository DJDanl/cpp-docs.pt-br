---
title: Classe ComPtrRefBase
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRefBase
- client/Microsoft::WRL::Details::ComPtrRefBase::operator IInspectable**
- client/Microsoft::WRL::Details::ComPtrRefBase::operator IUnknown**
- client/Microsoft::WRL::Details::ComPtrRefBase::ptr_
helpviewer_keywords:
- Microsoft::WRL::Details::ComPtrRefBase class
- Microsoft::WRL::Details::ComPtrRefBase::operator IInspectable** operator
- Microsoft::WRL::Details::ComPtrRefBase::operator IUnknown** operator
- Microsoft::WRL::Details::ComPtrRefBase::ptr_ data member
ms.assetid: 6d344c1a-cc13-4a3f-8a0d-f167ccb9348f
ms.openlocfilehash: 4f6dd6449cf8135ad14486d64cea95d8329e0014
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372614"
---
# <a name="comptrrefbase-class"></a>Classe ComPtrRefBase

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtrRefBase;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um [ComPtr\<T>](comptr-class.md) tipo ou um tipo derivado dele, não apenas a interface representada pelo . `ComPtr`

## <a name="remarks"></a>Comentários

Representa a classe base para a classe [ComPtrRef.](comptrref-class.md)

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome            | Descrição
--------------- | -------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo de parâmetro de modelo *T*.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                       | Descrição
-------------------------------------------------------------------------- | -----------------------------------------------------------------------------------------------------
[ComPtrRefBase:operador IInspectable**](#operator-iinspectable-star-star) | Lança o membro de dados [ptr_](#ptr) atual para um ponteiro-para-um-ponteiro-ponto para a `IInspectable` interface.
[ComPtrRefBase::operador IUnknown**](#operator-iunknown-star-star)         | Lança o membro de dados [ptr_](#ptr) atual para um ponteiro-para-um-ponteiro-ponto para a `IUnknown` interface.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------------------------------
[ComPtrRefBase::ptr_](#ptr) | Ponteiro para o tipo especificado pelo parâmetro de modelo atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="comptrrefbaseoperator-iinspectable-operator"></a><a name="operator-iinspectable-star-star"></a>ComPtrRefBase:operador IInspectable\* \*

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator IInspectable**() const;
```

### <a name="remarks"></a>Comentários

Lança o membro de dados [ptr_](#ptr) atual para um ponteiro-para-um-ponteiro-ponto para a `IInspectable` interface.

Um erro é emitido `ComPtrRefBase` se a corrente `IInspectable`não derivar de .

Este elenco só `__WRL_CLASSIC_COM__` está disponível se for definido.

## <a name="comptrrefbaseoperator-iunknown-operator"></a><a name="operator-iunknown-star-star"></a>ComPtrRefBase:operador IUnknown**

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator IUnknown**() const;
```

### <a name="remarks"></a>Comentários

Lança o membro de dados [ptr_](#ptr) atual para um ponteiro-para-um-ponteiro-ponto para a `IUnknown` interface.

Um erro é emitido `ComPtrRefBase` se a corrente `IUnknown`não derivar de .

## <a name="comptrrefbaseptr_"></a><a name="ptr"></a>ComPtrRefBase::ptr_

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
T* ptr_;
```

### <a name="remarks"></a>Comentários

Ponteiro para o tipo especificado pelo parâmetro de modelo atual. `ptr_`é o membro de dados protegido.
