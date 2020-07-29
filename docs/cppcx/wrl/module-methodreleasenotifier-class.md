---
title: Classe Module::MethodReleaseNotifier
ms.date: 09/17/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::MethodReleaseNotifier
- module/Microsoft::WRL::Module::MethodReleaseNotifier::Invoke
- module/Microsoft::WRL::Module::MethodReleaseNotifier::method_
- module/Microsoft::WRL::Module::MethodReleaseNotifier::MethodReleaseNotifier
- module/Microsoft::WRL::Module::MethodReleaseNotifier::object_
helpviewer_keywords:
- Microsoft::WRL::Module::MethodReleaseNotifier class
- Microsoft::WRL::Module::MethodReleaseNotifier::Invoke method
- Microsoft::WRL::Module::MethodReleaseNotifier::method_ data member
- Microsoft::WRL::Module::MethodReleaseNotifier::MethodReleaseNotifier, constructor
- Microsoft::WRL::Module::MethodReleaseNotifier::object_ data member
ms.assetid: 5c2902be-964b-488f-9f1c-adf504995cbc
ms.openlocfilehash: 5b0e5766fda878acb1fdc54a79ce162444eb06de
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225716"
---
# <a name="modulemethodreleasenotifier-class"></a>Classe Module::MethodReleaseNotifier

Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro para um método.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
class MethodReleaseNotifier : public ReleaseNotifier;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo do objeto cuja função de membro é o manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                                                 | Descrição
---------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------
[Módulo:: MethodReleaseNotifier:: MethodReleaseNotifier](#methodreleasenotifier-methodreleasenotifier) | Inicializa uma nova instância da classe `Module::MethodReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                   | Descrição
---------------------------------------------------------------------- | -------------------------------------------------------------------------------------------
[Módulo:: MethodReleaseNotifier:: Invoke](#methodreleasenotifier-invoke) | Chama o manipulador de eventos associado ao `Module::MethodReleaseNotifier` objeto atual.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                                                    | Descrição
----------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------
[Módulo:: MethodReleaseNotifier:: method_](#methodreleasenotifier-method) | Mantém um ponteiro para o manipulador de eventos para o `Module::MethodReleaseNotifier` objeto atual.
[Módulo:: MethodReleaseNotifier:: object_](#methodreleasenotifier-object) | Mantém um ponteiro para o objeto cuja função de membro é o manipulador de eventos do `Module::MethodReleaseNotifier` objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

`MethodReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="modulemethodreleasenotifierinvoke"></a><a name="methodreleasenotifier-invoke"></a>Módulo:: MethodReleaseNotifier:: Invoke

Chama o manipulador de eventos associado ao `Module::MethodReleaseNotifier` objeto atual.

```cpp
void Invoke();
```

## <a name="modulemethodreleasenotifiermethod_"></a><a name="methodreleasenotifier-method"></a>Módulo:: MethodReleaseNotifier:: method_

Mantém um ponteiro para o manipulador de eventos para o `Module::MethodReleaseNotifier` objeto atual.

```cpp
void (T::* method_)();
```

## <a name="modulemethodreleasenotifiermethodreleasenotifier"></a><a name="methodreleasenotifier-methodreleasenotifier"></a>Módulo:: MethodReleaseNotifier:: MethodReleaseNotifier

Inicializa uma nova instância da classe `Module::MethodReleaseNotifier`.

```cpp
MethodReleaseNotifier(
   _In_ T* object,
   _In_ void (T::* method)(),
   bool release) throw() :
            ReleaseNotifier(release), object_(object),
            method_(method);
```

### <a name="parameters"></a>parâmetros

*object*<br/>
Um objeto cuja função de membro é um manipulador de eventos.

*forma*<br/>
A função de membro do *objeto* de parâmetro que é o manipulador de eventos.

*liberar*<br/>
Especifique **`true`** para habilitar a chamada do método de [módulo subjacente:: ReleaseNotifier:: Release ()](module-releasenotifier-class.md#releasenotifier-release) ; caso contrário, especifique **`false`** .

## <a name="modulemethodreleasenotifierobject_"></a><a name="methodreleasenotifier-object"></a>Módulo:: MethodReleaseNotifier:: object_

Mantém um ponteiro para o objeto cuja função de membro é o manipulador de eventos do `Module::MethodReleaseNotifier` objeto atual.

```cpp
T* object_;
```
