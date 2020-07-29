---
title: Classe SyncLockWithStatusT
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::IsLocked
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::status_
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::SyncLockWithStatusT
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT class
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus method
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::IsLocked method
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::status_ data member
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::SyncLockWithStatusT, constructor
ms.assetid: 4832fd93-0ac8-4168-9404-b43fefea7476
ms.openlocfilehash: 4b7dbe8ae1648e4185a9eb1e1142df4a3869aa2f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216538"
---
# <a name="synclockwithstatust-class"></a>Classe SyncLockWithStatusT

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename SyncTraits>
class SyncLockWithStatusT : public SyncLockT<SyncTraits>;
```

### <a name="parameters"></a>parâmetros

*SyncTraits*<br/>
Um tipo que pode assumir a propriedade exclusiva ou compartilhada de um recurso.

## <a name="remarks"></a>Comentários

Representa um tipo que pode assumir a propriedade exclusiva ou compartilhada de um recurso.

A `SyncLockWithStatusT` classe é usada para implementar as classes [mutex](mutex-class.md) e [Semaphore](semaphore-class.md) .

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                             | Descrição
---------------------------------------------------------------- | --------------------------------------------------------------
[SyncLockWithStatusT::SyncLockWithStatusT](#synclockwithstatust) | Inicializa uma nova instância da classe `SyncLockWithStatusT`.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                                                             | Descrição
---------------------------------------------------------------- | --------------------------------------------------------------
[SyncLockWithStatusT::SyncLockWithStatusT](#synclockwithstatust) | Inicializa uma nova instância da classe `SyncLockWithStatusT`.

### <a name="public-methods"></a>Métodos públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------
[SyncLockWithStatusT:: GetStatus](#getstatus) | Recupera o status de espera do `SyncLockWithStatusT` objeto atual.
[SyncLockWithStatusT:: IsLocked](#islocked)   | Indica se o `SyncLockWithStatusT` objeto atual possui um recurso; ou seja, o `SyncLockWithStatusT` objeto está *bloqueado*.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                    | Descrição
--------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------
[SyncLockWithStatusT:: status_](#status) | Mantém o resultado da operação de espera subjacente após uma operação de bloqueio em um objeto com base no `SyncLockWithStatusT` objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SyncLockT`

`SyncLockWithStatusT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers::D etalhes

## <a name="synclockwithstatustgetstatus"></a><a name="getstatus"></a>SyncLockWithStatusT:: GetStatus

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
DWORD GetStatus() const;
```

### <a name="return-value"></a>Valor retornado

O resultado de uma operação de espera no objeto que é baseado na `SyncLockWithStatusT` classe, como um [mutex](mutex-class.md) ou [semáforo](semaphore-class.md). Zero (0) indica que a operação de espera retornou o estado sinalizado; caso contrário, ocorrerá outro Estado, como o valor de tempo limite decorrido.

### <a name="remarks"></a>Comentários

Recupera o status de espera do `SyncLockWithStatusT` objeto atual.

A função GetStatus () recupera o valor do membro de dados de [status_](#status) subjacente. Quando um objeto com base na `SyncLockWithStatusT` classe executa uma operação de bloqueio, o objeto primeiro aguarda que o objeto fique disponível. O resultado dessa operação de espera é armazenado no `status_` membro de dados. Os valores possíveis do `status_` membro de dados são os valores de retorno da operação de espera. Para obter mais informações, consulte os valores de retorno da [`WaitForSingleObjectEx`](/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex) função.

## <a name="synclockwithstatustislocked"></a><a name="islocked"></a>SyncLockWithStatusT:: IsLocked

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool IsLocked() const;
```

### <a name="remarks"></a>Comentários

Indica se o `SyncLockWithStatusT` objeto atual possui um recurso; ou seja, o `SyncLockWithStatusT` objeto está *bloqueado*.

### <a name="return-value"></a>Valor retornado

**`true`** Se o `SyncLockWithStatusT` objeto estiver bloqueado; caso contrário, **`false`** .

## <a name="synclockwithstatuststatus_"></a><a name="status"></a>SyncLockWithStatusT:: status_

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
DWORD status_;
```

### <a name="remarks"></a>Comentários

Mantém o resultado da operação de espera subjacente após uma operação de bloqueio em um objeto com base no `SyncLockWithStatusT` objeto atual.

## <a name="synclockwithstatustsynclockwithstatust"></a><a name="synclockwithstatust"></a>SyncLockWithStatusT::SyncLockWithStatusT

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
SyncLockWithStatusT(
   _Inout_ SyncLockWithStatusT&& other
);

explicit SyncLockWithStatusT(
   typename SyncTraits::Type sync,
   DWORD status
);
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Uma referência de rvalue a outro `SyncLockWithStatusT` objeto.

*sincronizá*<br/>
Uma referência a outro `SyncLockWithStatusT` objeto.

*status*<br/>
O valor do membro de dados [status_](#status) do *outro* parâmetro ou do parâmetro de *sincronização* .

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `SyncLockWithStatusT`.

O primeiro construtor inicializa o `SyncLockWithStatusT` objeto atual de outro `SyncLockWithStatusT` especificado pelo parâmetro *outro*e, em seguida, invalida o outro `SyncLockWithStatusT` objeto. O segundo construtor é **`protected`** e inicializa o objeto atual `SyncLockWithStatusT` para um estado inválido.
