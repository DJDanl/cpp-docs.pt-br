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
ms.openlocfilehash: 25fbb23ee7ecb7e55377aed74effe8bfa43a1597
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218358"
---
# <a name="modulereleasenotifier-class"></a>Classe Module::ReleaseNotifier

Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

## <a name="syntax"></a>Sintaxe

```cpp
class ReleaseNotifier;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                                | Descrição
----------------------------------------------------------------------------------- | --------------------------------------------------------------------------
[Módulo:: ReleaseNotifier:: ~ ReleaseNotifier](#releasenotifier-tilde-releasenotifier) | Desinicializa a instância atual da `Module::ReleaseNotifier` classe.
[Módulo:: ReleaseNotifier:: ReleaseNotifier](#releasenotifier-releasenotifier)        | Inicializa uma nova instância da classe `Module::ReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------
[Módulo:: ReleaseNotifier:: Invoke](#releasenotifier-invoke)   | Quando implementada, o chama um manipulador de eventos quando o último objeto em um módulo é liberado.
[Module::ReleaseNotifier::Release](#releasenotifier-release) | Excluirá o `Module::ReleaseNotifier` objeto atual se o objeto tiver sido construído com um parâmetro de **`true`** .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="modulereleasenotifierreleasenotifier"></a><a name="releasenotifier-tilde-releasenotifier"></a>Módulo:: ReleaseNotifier:: ~ ReleaseNotifier

Desinicializa a instância atual da `Module::ReleaseNotifier` classe.

```cpp
WRL_NOTHROW virtual ~ReleaseNotifier();
```

## <a name="modulereleasenotifierinvoke"></a><a name="releasenotifier-invoke"></a>Módulo:: ReleaseNotifier:: Invoke

Quando implementada, o chama um manipulador de eventos quando o último objeto em um módulo é liberado.

```cpp
virtual void Invoke() = 0;
```

## <a name="modulereleasenotifierrelease"></a><a name="releasenotifier-release"></a>Módulo:: ReleaseNotifier:: versão

Excluirá o `Module::ReleaseNotifier` objeto atual se o objeto tiver sido construído com um parâmetro de **`true`** .

```cpp
void Release() throw();
```

## <a name="modulereleasenotifierreleasenotifier"></a><a name="releasenotifier-releasenotifier"></a>Módulo:: ReleaseNotifier:: ReleaseNotifier

Inicializa uma nova instância da classe `Module::ReleaseNotifier`.

```cpp
ReleaseNotifier(bool release) throw();
```

### <a name="parameters"></a>parâmetros

*liberar*<br/>
**`true`** para excluir essa instância quando o `Release` método for chamado; **`false`** para não excluir esta instância.
