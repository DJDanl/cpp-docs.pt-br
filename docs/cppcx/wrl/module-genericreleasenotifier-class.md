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
ms.openlocfilehash: 7437f4e1f6874d4c708780a146e1761ac6d98305
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225729"
---
# <a name="modulegenericreleasenotifier-class"></a>Classe Module::GenericReleaseNotifier

Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por em um lambda, functor ou ponteiro para função.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
class GenericReleaseNotifier : public ReleaseNotifier;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo do membro de dados que contém o local do manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                                                     | Descrição
-------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------
[Módulo:: GenericReleaseNotifier:: GenericReleaseNotifier](#genericreleasenotifier-genericreleasenotifier) | Inicializa uma nova instância da classe `Module::GenericReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                     | Descrição
------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------
[Módulo:: GenericReleaseNotifier:: Invoke](#genericreleasenotifier-invoke) | Chama o manipulador de eventos associado ao `Module::GenericReleaseNotifier` objeto atual.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                                                          | Descrição
----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------
[Módulo:: GenericReleaseNotifier:: callback_](#genericreleasenotifier-callback) | Mantém o manipulador de eventos lambda, functor ou ponteiro para função associado ao `Module::GenericReleaseNotifier` objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

`GenericReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="modulegenericreleasenotifiercallback_"></a><a name="genericreleasenotifier-callback"></a>Módulo:: GenericReleaseNotifier:: callback_

Mantém o manipulador de eventos lambda, functor ou ponteiro para função associado ao `Module::GenericReleaseNotifier` objeto atual.

```cpp
T callback_;
```

## <a name="modulegenericreleasenotifiergenericreleasenotifier"></a><a name="genericreleasenotifier-genericreleasenotifier"></a>Módulo:: GenericReleaseNotifier:: GenericReleaseNotifier

Inicializa uma nova instância da classe `Module::GenericReleaseNotifier`.

```cpp
GenericReleaseNotifier(
   T callback,
   bool release
) throw() : ReleaseNotifier(release), callback_(callback);
```

### <a name="parameters"></a>parâmetros

*retorno de chamada*<br/>
Um manipulador de eventos lambda, functor ou ponteiro para função que pode ser invocado com o operador de função parêntesis ( `()` ).

*liberar*<br/>
Especifique **`true`** para habilitar a chamada do método de [módulo subjacente:: ReleaseNotifier:: Release ()](module-releasenotifier-class.md#releasenotifier-release) ; caso contrário, especifique **`false`** .

## <a name="modulegenericreleasenotifierinvoke"></a><a name="genericreleasenotifier-invoke"></a>Módulo:: GenericReleaseNotifier:: Invoke

Chama o manipulador de eventos associado ao `Module::GenericReleaseNotifier` objeto atual.

```cpp
void Invoke();
```
