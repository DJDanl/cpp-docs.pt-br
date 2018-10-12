---
title: Classe releasenotifier | Microsoft Docs
ms.custom: ''
ms.date: 09/17/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::ReleaseNotifier
- module/Microsoft::WRL::Module::ReleaseNotifier::~ReleaseNotifier
- module/Microsoft::WRL::Module::ReleaseNotifier::Invoke
- module/Microsoft::WRL::Module::ReleaseNotifier::Release
- module/Microsoft::WRL::Module::ReleaseNotifier::ReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Module::ReleaseNotifier class
- Microsoft::WRL::Module::ReleaseNotifier::~ReleaseNotifier, destructor
- Microsoft::WRL::Module::ReleaseNotifier::Invoke method
- Microsoft::WRL::Module::ReleaseNotifier::Release method
- Microsoft::WRL::Module::ReleaseNotifier::ReleaseNotifier, constructor
ms.assetid: 17249cd1-4d88-42e3-8146-da9e942d12bd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e2dae7809a5926fa93626fa33148d444fe12807b
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161886"
---
# <a name="modulereleasenotifier-class"></a>Classe Module::ReleaseNotifier

Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

## <a name="syntax"></a>Sintaxe

```cpp
class ReleaseNotifier;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                                                | Descrição
----------------------------------------------------------------------------------- | --------------------------------------------------------------------------
[Module:: releasenotifier:: ~ ReleaseNotifier](#releasenotifier-tilde-releasenotifier) | A instância atual do realiza o desligamento de `Module::ReleaseNotifier` classe.
[Module::ReleaseNotifier::ReleaseNotifier](#releasenotifier-releasenotifier)        | Inicializa uma nova instância da classe `Module::ReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------
[Module:: releasenotifier:: Invoke](#releasenotifier-invoke)   | Quando implementado, chama um manipulador de eventos quando o último objeto em um módulo é liberado.
[Module::ReleaseNotifier::Release](#releasenotifier-release) | Exclui o atual `Module::ReleaseNotifier` se o objeto for construído com um parâmetro de objeto **verdadeiro**.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="releasenotifier-tilde-releasenotifier"></a>Module:: releasenotifier:: ~ ReleaseNotifier

A instância atual do realiza o desligamento de `Module::ReleaseNotifier` classe.

```cpp
WRL_NOTHROW virtual ~ReleaseNotifier();
```

## <a name="releasenotifier-invoke"></a>Module:: releasenotifier:: Invoke

Quando implementado, chama um manipulador de eventos quando o último objeto em um módulo é liberado.

```cpp
virtual void Invoke() = 0;
```

## <a name="releasenotifier-release"></a>Module::ReleaseNotifier::Release

Exclui o atual `Module::ReleaseNotifier` se o objeto for construído com um parâmetro de objeto **verdadeiro**.

```cpp
void Release() throw();
```

## <a name="releasenotifier-releasenotifier"></a>Module::ReleaseNotifier::ReleaseNotifier

Inicializa uma nova instância da classe `Module::ReleaseNotifier`.

```cpp
ReleaseNotifier(bool release) throw();
```

### <a name="parameters"></a>Parâmetros

*release*  
`true` Para excluir essa instância quando o `Release` método é chamado; `false` não excluir esta instância.
