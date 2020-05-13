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
ms.openlocfilehash: c641f150b6f029facffa62f7b47c7da32138735e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371297"
---
# <a name="modulemethodreleasenotifier-class"></a>Classe Module::MethodReleaseNotifier

Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro para um método.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
class MethodReleaseNotifier : public ReleaseNotifier;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do objeto cuja função de membro é o manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                                                 | Descrição
---------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------
[Módulo::MétodoReleaseNotifier::MethodReleaseNotifier](#methodreleasenotifier-methodreleasenotifier) | Inicia uma nova instância da classe `Module::MethodReleaseNotifier`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                   | Descrição
---------------------------------------------------------------------- | -------------------------------------------------------------------------------------------
[Módulo::MétodoReleaseNotifier::Invocar](#methodreleasenotifier-invoke) | Chama o manipulador de `Module::MethodReleaseNotifier` eventos associado ao objeto atual.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                                                    | Descrição
----------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------
[Módulo::MétodoReleaseNotifier::method_](#methodreleasenotifier-method) | Segura um ponteiro para o `Module::MethodReleaseNotifier` manipulador de eventos para o objeto atual.
[Módulo::MétodoReleaseNotifier::object_](#methodreleasenotifier-object) | Segura um ponteiro para o objeto cuja função `Module::MethodReleaseNotifier` de membro é o manipulador de eventos do objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ReleaseNotifier`

`MethodReleaseNotifier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="modulemethodreleasenotifierinvoke"></a><a name="methodreleasenotifier-invoke"></a>Módulo::MétodoReleaseNotifier::Invocar

Chama o manipulador de `Module::MethodReleaseNotifier` eventos associado ao objeto atual.

```cpp
void Invoke();
```

## <a name="modulemethodreleasenotifiermethod_"></a><a name="methodreleasenotifier-method"></a>Módulo::MétodoReleaseNotifier::method_

Segura um ponteiro para o `Module::MethodReleaseNotifier` manipulador de eventos para o objeto atual.

```cpp
void (T::* method_)();
```

## <a name="modulemethodreleasenotifiermethodreleasenotifier"></a><a name="methodreleasenotifier-methodreleasenotifier"></a>Módulo::MétodoReleaseNotifier::MethodReleaseNotifier

Inicia uma nova instância da classe `Module::MethodReleaseNotifier`.

```cpp
MethodReleaseNotifier(
   _In_ T* object,
   _In_ void (T::* method)(),
   bool release) throw() :
            ReleaseNotifier(release), object_(object),
            method_(method);
```

### <a name="parameters"></a>Parâmetros

*Objeto*<br/>
Um objeto cuja função de membro é um manipulador de eventos.

*Método*<br/>
A função membro do *objeto* parâmetro que é o manipulador de eventos.

*Lançamento*<br/>
Especificar `true` para ativar a chamada do módulo [subjacente::ReleaseNotifier::Release()](module-releasenotifier-class.md#releasenotifier-release) method; caso contrário, `false`especifique .

## <a name="modulemethodreleasenotifierobject_"></a><a name="methodreleasenotifier-object"></a>Módulo::MétodoReleaseNotifier::object_

Segura um ponteiro para o objeto cuja função `Module::MethodReleaseNotifier` de membro é o manipulador de eventos do objeto atual.

```cpp
T* object_;
```
