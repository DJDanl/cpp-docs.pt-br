---
title: Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::MethodReleaseNotifier::MethodReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- MethodReleaseNotifier, constructor
ms.assetid: 762e2ca4-0a92-49de-9ff5-d3efa0f067c0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 608a885eb446860cca43e5fabd19597d7611e633
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386816"
---
# <a name="modulemethodreleasenotifiermethodreleasenotifier-constructor"></a>Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier

Inicializa uma nova instância dos **methodreleasenotifier** classe.

## <a name="syntax"></a>Sintaxe

```cpp
MethodReleaseNotifier(
   _In_ T* object,
   _In_ void (T::* method)(),
   bool release) throw() :
            ReleaseNotifier(release), object_(object),
            method_(method);
```

### <a name="parameters"></a>Parâmetros

*object*<br/>
Um objeto cuja função de membro é um manipulador de eventos.

*Método*<br/>
A função de membro do parâmetro *objeto* que é o manipulador de eventos.

*release*<br/>
Especificar **verdadeira** para habilitar a chamada subjacente [Module:: ReleaseNotifier::Release()](../windows/module-releasenotifier-release.md) método; caso contrário, especifique **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module::MethodReleaseNotifier](../windows/module-methodreleasenotifier-class.md)