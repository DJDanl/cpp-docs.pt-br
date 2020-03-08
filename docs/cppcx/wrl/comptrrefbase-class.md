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
ms.openlocfilehash: df4e2aa1ce650fd5b1f04baf2f7c4cd2fb4cff93
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865815"
---
# <a name="comptrrefbase-class"></a>Classe ComPtrRefBase

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtrRefBase;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo [ComPtr\<t >](comptr-class.md) ou um tipo derivado dele, não meramente a interface representada pelo `ComPtr`.

## <a name="remarks"></a>Comentários

Representa a classe base para a classe [ComPtrRef](comptrref-class.md) .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

{1&gt;Nome&lt;1}            | Descrição
--------------- | -------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo de parâmetro de modelo *T*.

### <a name="public-operators"></a>Operadores públicos

{1&gt;Nome&lt;1}                                                                       | Descrição
-------------------------------------------------------------------------- | -----------------------------------------------------------------------------------------------------
[ComPtrRefBase:: Operator IInspectable * *](#operator-iinspectable-star-star) | Converte o membro de dados de [ptr_](#ptr) atual em um ponteiro para ponteiro para a interface `IInspectable`.
[ComPtrRefBase:: Operator IUnknown * *](#operator-iunknown-star-star)         | Converte o membro de dados de [ptr_](#ptr) atual em um ponteiro para ponteiro para a interface `IUnknown`.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

{1&gt;Nome&lt;1}                        | Descrição
--------------------------- | ----------------------------------------------------------------
[ComPtrRefBase::p tr_](#ptr) | Ponteiro para o tipo especificado pelo parâmetro de modelo atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="operator-iinspectable-star-star"></a>Operador ComPtrRefBase:: Operator IInspectable\*\*

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator IInspectable**() const;
```

### <a name="remarks"></a>Comentários

Converte o membro de dados de [ptr_](#ptr) atual em um ponteiro para ponteiro para a interface `IInspectable`.

Um erro será emitido se a `ComPtrRefBase` atual não derivar de `IInspectable`.

Essa conversão só estará disponível se `__WRL_CLASSIC_COM__` estiver definida.

## <a name="operator-iunknown-star-star"></a>Operador ComPtrRefBase:: Operator IUnknown * *

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator IUnknown**() const;
```

### <a name="remarks"></a>Comentários

Converte o membro de dados de [ptr_](#ptr) atual em um ponteiro para ponteiro para a interface `IUnknown`.

Um erro será emitido se a `ComPtrRefBase` atual não derivar de `IUnknown`.

## <a name="ptr"></a>ComPtrRefBase::p tr_

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
T* ptr_;
```

### <a name="remarks"></a>Comentários

Ponteiro para o tipo especificado pelo parâmetro de modelo atual. `ptr_` é o membro de dados protegidos.
