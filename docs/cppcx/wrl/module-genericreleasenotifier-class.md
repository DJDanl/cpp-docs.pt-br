---
title: Classe Module::GenericReleaseNotifier
ms.date: 09/17/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GenericReleaseNotifier
- module/Microsoft::WRL::Module::GenericReleaseNotifier::callback_
- module/Microsoft::WRL::Module::GenericReleaseNotifier::GenericReleaseNotifier
- module/Microsoft::WRL::Module::GenericReleaseNotifier::Invoke
helpviewer_keywords:
- Microsoft::WRL::Module::GenericReleaseNotifier class
- Microsoft::WRL::Module::GenericReleaseNotifier::callback_ data member
- Microsoft::WRL::Module::GenericReleaseNotifier::GenericReleaseNotifier, constructor
- Microsoft::WRL::Module::GenericReleaseNotifier::Invoke method
ms.assetid: 244a8fbe-f89b-409b-aa65-db3e37f9b125
ms.openlocfilehash: e3cc8e33d596fb1d3ecc4a94fee7971a50ffe596
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371301"
---
# <a name="modulegenericreleasenotifier-class"></a>Classe Module::GenericReleaseNotifier

Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um lambda, functor ou pointer-to-function.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
class GenericReleaseNotifier : public ReleaseNotifier;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do membro de dados que contém a localização do manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                                                     | Descrição
-------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------
[Módulo::GenericReleaseNotifier::GenericReleaseNotifier](#genericreleasenotifier-genericreleasenotifier) | Inicia uma nova instância da classe `Module::GenericReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                     | Descrição
------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------
[Módulo::GenericReleaseNotifier::Invocar](#genericreleasenotifier-invoke) | Chama o manipulador de `Module::GenericReleaseNotifier` eventos associado ao objeto atual.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                                                          | Descrição
----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------
[Módulo:GenericReleaseNotifier::callback_](#genericreleasenotifier-callback) | Segura o manipulador de eventos lambda, functor ou pointer-to-function associado ao objeto atual. `Module::GenericReleaseNotifier`

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

`GenericReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="modulegenericreleasenotifiercallback_"></a><a name="genericreleasenotifier-callback"></a>Módulo:GenericReleaseNotifier::callback_

Segura o manipulador de eventos lambda, functor ou pointer-to-function associado ao objeto atual. `Module::GenericReleaseNotifier`

```cpp
T callback_;
```

## <a name="modulegenericreleasenotifiergenericreleasenotifier"></a><a name="genericreleasenotifier-genericreleasenotifier"></a>Módulo::GenericReleaseNotifier::GenericReleaseNotifier

Inicia uma nova instância da classe `Module::GenericReleaseNotifier`.

```cpp
GenericReleaseNotifier(
   T callback,
   bool release
) throw() : ReleaseNotifier(release), callback_(callback);
```

### <a name="parameters"></a>Parâmetros

*retorno de chamada*<br/>
Um manipulador de eventos lambda, functor ou pointer-to-function que pode ser`()`invocado com o operador de função entre parênteses ().

*Lançamento*<br/>
Especificar `true` para ativar a chamada do módulo [subjacente::ReleaseNotifier::Release()](module-releasenotifier-class.md#releasenotifier-release) method; caso contrário, `false`especifique .

## <a name="modulegenericreleasenotifierinvoke"></a><a name="genericreleasenotifier-invoke"></a>Módulo::GenericReleaseNotifier::Invocar

Chama o manipulador de `Module::GenericReleaseNotifier` eventos associado ao objeto atual.

```cpp
void Invoke();
```
