---
title: Classe Module::ReleaseNotifier
ms.date: 09/17/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::ReleaseNotifier
- module/Microsoft::WRL::Module::ReleaseNotifier::~ReleaseNotifier
- module/Microsoft::WRL::Module::ReleaseNotifier::Invoke
- module/Microsoft::WRL::Module::ReleaseNotifier::Release
- module/Microsoft::WRL::Module::ReleaseNotifier::ReleaseNotifier
helpviewer_keywords:
- Microsoft::WRL::Module::ReleaseNotifier class
- Microsoft::WRL::Module::ReleaseNotifier::~ReleaseNotifier, destructor
- Microsoft::WRL::Module::ReleaseNotifier::Invoke method
- Microsoft::WRL::Module::ReleaseNotifier::Release method
- Microsoft::WRL::Module::ReleaseNotifier::ReleaseNotifier, constructor
ms.assetid: 17249cd1-4d88-42e3-8146-da9e942d12bd
ms.openlocfilehash: 5fc1b8965bf8bf2f86dd30f2195fa825f85f6d7e
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418282"
---
# <a name="modulereleasenotifier-class"></a>Classe Module::ReleaseNotifier

Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

## <a name="syntax"></a>Sintaxe

```cpp
class ReleaseNotifier;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                                | DESCRIÇÃO
----------------------------------------------------------------------------------- | --------------------------------------------------------------------------
[Módulo:: ReleaseNotifier:: ~ ReleaseNotifier](#releasenotifier-tilde-releasenotifier) | Desinicializa a instância atual da classe `Module::ReleaseNotifier`.
[Módulo:: ReleaseNotifier:: ReleaseNotifier](#releasenotifier-releasenotifier)        | Inicia uma nova instância da classe `Module::ReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | DESCRIÇÃO
------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------
[Módulo:: ReleaseNotifier:: Invoke](#releasenotifier-invoke)   | Quando implementada, o chama um manipulador de eventos quando o último objeto em um módulo é liberado.
[Module::ReleaseNotifier::Release](#releasenotifier-release) | Exclui o objeto de `Module::ReleaseNotifier` atual se o objeto foi construído com um parâmetro de **true**.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="releasenotifier-tilde-releasenotifier"></a>Módulo:: ReleaseNotifier:: ~ ReleaseNotifier

Desinicializa a instância atual da classe `Module::ReleaseNotifier`.

```cpp
WRL_NOTHROW virtual ~ReleaseNotifier();
```

## <a name="releasenotifier-invoke"></a>Módulo:: ReleaseNotifier:: Invoke

Quando implementada, o chama um manipulador de eventos quando o último objeto em um módulo é liberado.

```cpp
virtual void Invoke() = 0;
```

## <a name="releasenotifier-release"></a>Módulo:: ReleaseNotifier:: versão

Exclui o objeto de `Module::ReleaseNotifier` atual se o objeto foi construído com um parâmetro de **true**.

```cpp
void Release() throw();
```

## <a name="releasenotifier-releasenotifier"></a>Módulo:: ReleaseNotifier:: ReleaseNotifier

Inicia uma nova instância da classe `Module::ReleaseNotifier`.

```cpp
ReleaseNotifier(bool release) throw();
```

### <a name="parameters"></a>parâmetros

*release*<br/>
`true` excluir essa instância quando o método `Release` for chamado; `false` não excluir esta instância.
