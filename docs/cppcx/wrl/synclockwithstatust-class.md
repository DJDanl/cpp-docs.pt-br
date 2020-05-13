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
ms.openlocfilehash: 77bcb8336e4650de7ed01a067fa1bdd7ec0ba3e8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374273"
---
# <a name="synclockwithstatust-class"></a>Classe SyncLockWithStatusT

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename SyncTraits>
class SyncLockWithStatusT : public SyncLockT<SyncTraits>;
```

### <a name="parameters"></a>Parâmetros

*SyncTraits*<br/>
Um tipo que pode ter propriedade exclusiva ou compartilhada de um recurso.

## <a name="remarks"></a>Comentários

Representa um tipo que pode ter propriedade exclusiva ou compartilhada de um recurso.

A `SyncLockWithStatusT` classe é usada para implementar as classes [Mutex](mutex-class.md) e [Semaphore.](semaphore-class.md)

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                             | Descrição
---------------------------------------------------------------- | --------------------------------------------------------------
[sincronizaçãocomstatusT::synclockwithstatust](#synclockwithstatust) | Inicia uma nova instância da classe `SyncLockWithStatusT`.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                                                             | Descrição
---------------------------------------------------------------- | --------------------------------------------------------------
[sincronizaçãocomstatusT::synclockwithstatust](#synclockwithstatust) | Inicia uma nova instância da classe `SyncLockWithStatusT`.

### <a name="public-methods"></a>Métodos públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------
[sincronizaçãocomstatusT::obter status](#getstatus) | Recupera o status de `SyncLockWithStatusT` espera do objeto atual.
[synclockwithstatust::islocked](#islocked)   | Indica se `SyncLockWithStatusT` o objeto atual possui um recurso; ou seja, `SyncLockWithStatusT` o objeto está *bloqueado.*

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                    | Descrição
--------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------
[sincronizaçãoComstatusT::status_](#status) | Mantém o resultado da operação de espera subjacente após uma `SyncLockWithStatusT` operação de bloqueio em um objeto baseado no objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SyncLockT`

`SyncLockWithStatusT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::Details

## <a name="synclockwithstatustgetstatus"></a><a name="getstatus"></a>sincronizaçãocomstatusT::obter status

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
DWORD GetStatus() const;
```

### <a name="return-value"></a>Valor retornado

O resultado de uma operação de espera `SyncLockWithStatusT` no objeto que se baseia na classe, como um [Mutex](mutex-class.md) ou [Semaphore](semaphore-class.md). Zero (0) indica que a operação de espera retornou o estado sinalizado; caso contrário, outro estado ocorreu, como o valor de tempo decorrido.

### <a name="remarks"></a>Comentários

Recupera o status de `SyncLockWithStatusT` espera do objeto atual.

A função GetStatus() recupera o valor do membro de dados [status_](#status) subjacente. Quando um objeto `SyncLockWithStatusT` baseado na classe executa uma operação de bloqueio, o objeto primeiro espera que o objeto fique disponível. O resultado dessa operação de `status_` espera é armazenado no membro de dados. Os valores `status_` possíveis do membro de dados são os valores de retorno da operação de espera. Para obter mais informações, consulte `WaitForSingleObjectEx()` os valores de retorno da função na Biblioteca MSDN.

## <a name="synclockwithstatustislocked"></a><a name="islocked"></a>synclockwithstatust::islocked

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool IsLocked() const;
```

### <a name="remarks"></a>Comentários

Indica se `SyncLockWithStatusT` o objeto atual possui um recurso; ou seja, `SyncLockWithStatusT` o objeto está *bloqueado.*

### <a name="return-value"></a>Valor retornado

**verdade** se `SyncLockWithStatusT` o objeto está bloqueado; caso contrário, **falso**.

## <a name="synclockwithstatuststatus_"></a><a name="status"></a>sincronizaçãoComstatusT::status_

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
DWORD status_;
```

### <a name="remarks"></a>Comentários

Mantém o resultado da operação de espera subjacente após uma `SyncLockWithStatusT` operação de bloqueio em um objeto baseado no objeto atual.

## <a name="synclockwithstatustsynclockwithstatust"></a><a name="synclockwithstatust"></a>sincronizaçãocomstatusT::synclockwithstatust

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
SyncLockWithStatusT(
   _Inout_ SyncLockWithStatusT&& other
);

explicit SyncLockWithStatusT(
   typename SyncTraits::Type sync,
   DWORD status
);
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Uma referência de valor `SyncLockWithStatusT` a outro objeto.

*Sincronização*<br/>
Uma referência `SyncLockWithStatusT` a outro objeto.

*status*<br/>
O valor do [status_](#status) membro dos dados do *outro* parâmetro ou do parâmetro *de sincronização.*

### <a name="remarks"></a>Comentários

Inicia uma nova instância da classe `SyncLockWithStatusT`.

O primeiro construtor inicializa `SyncLockWithStatusT` o objeto `SyncLockWithStatusT` atual de outro especificado por parâmetro `SyncLockWithStatusT` *outro*, e então invalida o outro objeto. O segundo construtor `protected`é , e `SyncLockWithStatusT` inicia o objeto atual para um estado inválido.
