---
title: Classe genericreleasenotifier | Microsoft Docs
ms.custom: ''
ms.date: 09/17/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GenericReleaseNotifier
- module/Microsoft::WRL::Module::GenericReleaseNotifier::callback_
- module/Microsoft::WRL::Module::GenericReleaseNotifier::GenericReleaseNotifier
- module/Microsoft::WRL::Module::GenericReleaseNotifier::Invoke
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Module::GenericReleaseNotifier class
- Microsoft::WRL::Module::GenericReleaseNotifier::callback_ data member
- Microsoft::WRL::Module::GenericReleaseNotifier::GenericReleaseNotifier, constructor
- Microsoft::WRL::Module::GenericReleaseNotifier::Invoke method
ms.assetid: 244a8fbe-f89b-409b-aa65-db3e37f9b125
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 18aeac7767fbd4c1688b202670a812e5738ef62f
ms.sourcegitcommit: 338e1ddc2f3869d92ba4b73599d35374cf1d5b69
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/20/2018
ms.locfileid: "46494420"
---
# <a name="modulegenericreleasenotifier-class"></a>Classe Module::GenericReleaseNotifier

Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado em um lambda, functor ou ponteiro para função.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
class GenericReleaseNotifier : public ReleaseNotifier;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de membro de dados que contém o local do manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                                                                     | Descrição
-------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------
[Module::GenericReleaseNotifier::GenericReleaseNotifier](#genericreleasenotifier-genericreleasenotifier) | Inicializa uma nova instância da classe `Module::GenericReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                     | Descrição
------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------
[Module:: genericreleasenotifier:: Invoke](#genericreleasenotifier-invoke) | Chama o manipulador de eventos associado ao atual `Module::GenericReleaseNotifier` objeto.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                                                                          | Descrição
----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------
[Module::GenericReleaseNotifier::callback_](#genericreleasenotifier-callback) | Mantém o lambda, functor ou manipulador de eventos de ponteiro para função associados ao atual `Module::GenericReleaseNotifier` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

`GenericReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="genericreleasenotifier-callback"></a>Module::GenericReleaseNotifier::callback_

Mantém o lambda, functor ou manipulador de eventos de ponteiro para função associados ao atual `Module::GenericReleaseNotifier` objeto.

```cpp
T callback_;
```

## <a name="genericreleasenotifier-genericreleasenotifier"></a>Module::GenericReleaseNotifier::GenericReleaseNotifier

Inicializa uma nova instância da classe `Module::GenericReleaseNotifier`.

```cpp
GenericReleaseNotifier(
   T callback,
   bool release
) throw() : ReleaseNotifier(release), callback_(callback);
```

### <a name="parameters"></a>Parâmetros

*retorno de chamada*  
Um lambda, functor ou manipulador de eventos de ponteiro para função que pode ser chamado com o operador de parênteses (`()`).

*release*  
Especificar `true` para habilitar a chamada subjacente [Module:: ReleaseNotifier::Release()](../windows/module-releasenotifier-release.md) método; caso contrário, especifique `false`.

## <a name="genericreleasenotifier-invoke"></a>Module:: genericreleasenotifier:: Invoke

Chama o manipulador de eventos associado ao atual `Module::GenericReleaseNotifier` objeto.

```cpp
void Invoke();
```
