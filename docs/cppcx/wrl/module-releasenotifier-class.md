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
ms.openlocfilehash: f314d09c443d0d284e3a821b5c879bfb74baf812
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371282"
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
[Módulo::Divulgação Notificador::~Divulgação Notific](#releasenotifier-tilde-releasenotifier) | Desinicializa a instância `Module::ReleaseNotifier` atual da classe.
[Módulo::Divulgação:Divulgação::Divulgação de lançamento](#releasenotifier-releasenotifier)        | Inicia uma nova instância da classe `Module::ReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------
[Módulo::ReleaseNotifier::Invocar](#releasenotifier-invoke)   | Quando implementado, chama um manipulador de eventos quando o último objeto em um módulo é liberado.
[Module::ReleaseNotifier::Release](#releasenotifier-release) | Exclui o `Module::ReleaseNotifier` objeto atual se o objeto foi construído com um parâmetro de **verdade**.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="modulereleasenotifierreleasenotifier"></a><a name="releasenotifier-tilde-releasenotifier"></a>Módulo::Divulgação Notificador::~Divulgação Notific

Desinicializa a instância `Module::ReleaseNotifier` atual da classe.

```cpp
WRL_NOTHROW virtual ~ReleaseNotifier();
```

## <a name="modulereleasenotifierinvoke"></a><a name="releasenotifier-invoke"></a>Módulo::ReleaseNotifier::Invocar

Quando implementado, chama um manipulador de eventos quando o último objeto em um módulo é liberado.

```cpp
virtual void Invoke() = 0;
```

## <a name="modulereleasenotifierrelease"></a><a name="releasenotifier-release"></a>Módulo::Divulgação Notificador::Lançamento

Exclui o `Module::ReleaseNotifier` objeto atual se o objeto foi construído com um parâmetro de **verdade**.

```cpp
void Release() throw();
```

## <a name="modulereleasenotifierreleasenotifier"></a><a name="releasenotifier-releasenotifier"></a>Módulo::Divulgação:Divulgação::Divulgação de lançamento

Inicia uma nova instância da classe `Module::ReleaseNotifier`.

```cpp
ReleaseNotifier(bool release) throw();
```

### <a name="parameters"></a>Parâmetros

*Lançamento*<br/>
`true`para excluir esta `Release` instância quando o método é chamado; `false` para não excluir esta instância.
