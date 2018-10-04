---
title: Classe SyncLockWithStatusT | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::IsLocked
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::status_
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::SyncLockWithStatusT
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT class
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus method
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::IsLocked method
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::status_ data member
- Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::SyncLockWithStatusT, constructor
ms.assetid: 4832fd93-0ac8-4168-9404-b43fefea7476
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b7e59631592cd0bf9d147110e1a72d27d4bc781e
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789079"
---
# <a name="synclockwithstatust-class"></a>Classe SyncLockWithStatusT

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename SyncTraits>
class SyncLockWithStatusT : public SyncLockT<SyncTraits>;
```

### <a name="parameters"></a>Parâmetros

*SyncTraits*<br/>
Um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.

## <a name="remarks"></a>Comentários

Representa um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.

O `SyncLockWithStatusT` classe é usada para implementar o [Mutex](../windows/mutex-class1.md) e [semáforo](../windows/semaphore-class.md) classes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                             | Descrição
---------------------------------------------------------------- | --------------------------------------------------------------
[Synclockwithstatust:: Synclockwithstatust](#synclockwithstatust) | Inicializa uma nova instância da classe `SyncLockWithStatusT`.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                                                             | Descrição
---------------------------------------------------------------- | --------------------------------------------------------------
[Synclockwithstatust:: Synclockwithstatust](#synclockwithstatust) | Inicializa uma nova instância da classe `SyncLockWithStatusT`.

### <a name="public-methods"></a>Métodos públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------
[Synclockwithstatust:: getStatus](#getstatus) | Recupera o status de espera do atual `SyncLockWithStatusT` objeto.
[Synclockwithstatust:: Islocked](#islocked)   | Indica se o atual `SyncLockWithStatusT` objeto possui um recurso, ou seja, o `SyncLockWithStatusT` objeto é *bloqueado*.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                                    | Descrição
--------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------
[SyncLockWithStatusT::status_](#status) | Contém o resultado da operação de espera adjacente após uma operação de bloqueio em um objeto com base no atual `SyncLockWithStatusT` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SyncLockT`

`SyncLockWithStatusT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="getstatus"></a>Synclockwithstatust:: getStatus

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
DWORD GetStatus() const;
```

### <a name="return-value"></a>Valor de retorno

O resultado de uma operação de espera no objeto que se baseia o `SyncLockWithStatusT` classe, como um [Mutex](../windows/mutex-class1.md) ou [semáforo](../windows/semaphore-class.md). Zero (0) indica que a operação de espera retornado o estado sinalizado; Caso contrário, outro estado ocorreu, como o valor de tempo limite decorrido.

### <a name="remarks"></a>Comentários

Recupera o status de espera do atual `SyncLockWithStatusT` objeto.

A função getStatus () recupera o valor do subjacente [status _](#status) membro de dados. Quando um objeto com base no `SyncLockWithStatusT` classe executa uma operação de bloqueio, o objeto primeiro aguardará para o objeto se torne disponível. O resultado dessa operação de espera é armazenado no `status_` membro de dados. Os valores possíveis do `status_` membro de dados são os valores de retorno da operação de espera. Para obter mais informações, consulte os valores de retorno de `WaitForSingleObjectEx()` função na biblioteca MSDN.

## <a name="islocked"></a>Synclockwithstatust:: Islocked

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool IsLocked() const;
```

### <a name="remarks"></a>Comentários

Indica se o atual `SyncLockWithStatusT` objeto possui um recurso, ou seja, o `SyncLockWithStatusT` objeto é *bloqueado*.

### <a name="return-value"></a>Valor de retorno

`true` Se o `SyncLockWithStatusT` objeto estiver bloqueada; caso contrário, `false`.

## <a name="status"></a>SyncLockWithStatusT::status_

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
DWORD status_;
```

### <a name="remarks"></a>Comentários

Contém o resultado da operação de espera adjacente após uma operação de bloqueio em um objeto com base no atual `SyncLockWithStatusT` objeto.

## <a name="synclockwithstatust"></a>Synclockwithstatust:: Synclockwithstatust

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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

*other*<br/>
Uma referência rvalue para outro `SyncLockWithStatusT` objeto.

*sync*<br/>
Uma referência a outro `SyncLockWithStatusT` objeto.

*status*<br/>
O valor da [status _](#status) membro de dados a *outras* parâmetro ou o *sincronização* parâmetro.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `SyncLockWithStatusT`.

O primeiro construtor inicializa o atual `SyncLockWithStatusT` objeto de outro `SyncLockWithStatusT` especificado pelo parâmetro *outras*e, em seguida, invalida o outro `SyncLockWithStatusT` objeto. É o segundo construtor `protected`e a inicializa atual `SyncLockWithStatusT` objeto para um estado inválido.
