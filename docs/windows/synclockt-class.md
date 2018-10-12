---
title: Classe SyncLockT | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::IsLocked
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::sync_
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::SyncLockT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::~SyncLockT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::Unlock
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Details::SyncLockT class
- Microsoft::WRL::Wrappers::Details::SyncLockT::IsLocked method
- Microsoft::WRL::Wrappers::Details::SyncLockT::sync_ data member
- Microsoft::WRL::Wrappers::Details::SyncLockT::SyncLockT, constructor
- Microsoft::WRL::Wrappers::Details::SyncLockT::~SyncLockT, destructor
- Microsoft::WRL::Wrappers::Details::SyncLockT::Unlock method
ms.assetid: a967f6f7-3555-43d1-b210-2bb65d63d15e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 66aa9c3a8ab0f5ae9fb5219b090ec5c9e3755203
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49162094"
---
# <a name="synclockt-class"></a>Classe SyncLockT

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename SyncTraits>
class SyncLockT;
```

### <a name="parameters"></a>Parâmetros

*SyncTraits*<br/>
O tipo que pode assumir a propriedade de um recurso.

## <a name="remarks"></a>Comentários

Representa um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.

O `SyncLockT` classe é usada, por exemplo, para ajudar a implementar o [SRWLock](../windows/srwlock-class.md) classe.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                      | Descrição
----------------------------------------- | ----------------------------------------------------
[Synclockt:: Synclockt](#synclockt)        | Inicializa uma nova instância da classe `SyncLockT`.
[SyncLockT:: ~ SyncLockT](#tilde-synclockt) | Realiza o desligamento de uma instância da `SyncLockT` classe.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                               | Descrição
---------------------------------- | ----------------------------------------------------
[Synclockt:: Synclockt](#synclockt) | Inicializa uma nova instância da classe `SyncLockT`.

### <a name="public-methods"></a>Métodos públicos

Nome                             | Descrição
-------------------------------- | --------------------------------------------------------------------------------------------------------------
[Synclockt:: Islocked](#islocked) | Indica se o atual `SyncLockT` objeto possui um recurso, ou seja, o `SyncLockT` objeto é *bloqueado*.
[Synclockt:: Unlock](#unlock)     | Libera o controle do recurso mantido por atual `SyncLockT` do objeto, se houver.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                      | Descrição
------------------------- | -------------------------------------------------------------------
[SyncLockT::sync_](#sync) | Contém o recurso subjacente representado pela `SyncLockT` classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SyncLockT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="tilde-synclockt"></a>SyncLockT:: ~ SyncLockT

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
~SyncLockT();
```

### <a name="remarks"></a>Comentários

Realiza o desligamento de uma instância da `SyncLockT` classe.

Este destruidor também desbloqueia atual `SyncLockT` instância.

## <a name="islocked"></a>Synclockt:: Islocked

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool IsLocked() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o `SyncLockT` objeto estiver bloqueada; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Indica se o atual `SyncLockT` objeto possui um recurso, ou seja, o `SyncLockT` objeto é *bloqueado*.

## <a name="sync"></a>SyncLockT::sync_

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
typename SyncTraits::Type sync_;
```

### <a name="remarks"></a>Comentários

Contém o recurso subjacente representado pela `SyncLockT` classe.

## <a name="synclockt"></a>Synclockt:: Synclockt

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
SyncLockT(
   _Inout_ SyncLockT&& other
);

explicit SyncLockT(
   typename SyncTraits::Type sync = SyncTraits::GetInvalidValue()  
);
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Uma referência rvalue para outro `SyncLockT` objeto.

*sync*<br/>
Uma referência a outro `SyncLockWithStatusT` objeto.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `SyncLockT`.

O primeiro construtor inicializa o atual `SyncLockT` objeto de outro `SyncLockT` objeto especificado pelo parâmetro *outras*e, em seguida, invalida o outro `SyncLockT` objeto. É o segundo construtor `protected`e a inicializa atual `SyncLockT` objeto para um estado inválido.

## <a name="unlock"></a>Synclockt:: Unlock

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
void Unlock();
```

### <a name="remarks"></a>Comentários

Libera o controle do recurso mantido por atual `SyncLockT` do objeto, se houver.
