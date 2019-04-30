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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62398635"
---
# <a name="comptrrefbase-class"></a>Classe ComPtrRefBase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtrRefBase;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um [ComPtr\<T >](comptr-class.md) tipo ou um tipo derivado dele, não simplesmente a interface representada pelo `ComPtr`.

## <a name="remarks"></a>Comentários

Representa a classe base para o [ComPtrRef](comptrref-class.md) classe.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome            | Descrição
--------------- | -------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo de parâmetro de modelo *T*.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                       | Descrição
-------------------------------------------------------------------------- | -----------------------------------------------------------------------------------------------------
[Comptrrefbase:: Operator IInspectable * *](#operator-iinspectable-star-star) | Converte o atual [PTR _](#ptr) membro de dados para um ponteiro-para-um-ponteiro-para o `IInspectable` interface.
[Comptrrefbase:: Operator IUnknown * *](#operator-iunknown-star-star)         | Converte o atual [PTR _](#ptr) membro de dados para um ponteiro-para-um-ponteiro-para o `IUnknown` interface.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------------------------------
[ComPtrRefBase::ptr_](#ptr) | Ponteiro para o tipo especificado pelo parâmetro de modelo atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="operator-iinspectable-star-star"></a>Comptrrefbase:: Operator IInspectable\* \* operador

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator IInspectable**() const;
```

### <a name="remarks"></a>Comentários

Converte o atual [PTR _](#ptr) membro de dados para um ponteiro-para-um-ponteiro-para o `IInspectable` interface.

Um erro será emitido se o atual `ComPtrRefBase` não deriva de `IInspectable`.

Essa conversão está disponível somente se `__WRL_CLASSIC_COM__` está definido.

## <a name="operator-iunknown-star-star"></a>Comptrrefbase:: Operator IUnknown * * operador

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator IUnknown**() const;
```

### <a name="remarks"></a>Comentários

Converte o atual [PTR _](#ptr) membro de dados para um ponteiro-para-um-ponteiro-para o `IUnknown` interface.

Um erro será emitido se o atual `ComPtrRefBase` não deriva de `IUnknown`.

## <a name="ptr"></a>ComPtrRefBase::ptr_

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
T* ptr_;
```

### <a name="remarks"></a>Comentários

Ponteiro para o tipo especificado pelo parâmetro de modelo atual. `ptr_` é o membro de dados protegidos.
