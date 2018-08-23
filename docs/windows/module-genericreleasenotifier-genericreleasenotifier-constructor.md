---
title: Construtor Module::GenericReleaseNotifier::GenericReleaseNotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GenericReleaseNotifier::GenericReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- GenericReleaseNotifier, constructor
ms.assetid: feb5b687-a4b0-4809-9022-8f292181b7a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 98bcc3d3fcaf7aea3b2632cacb1ff38eedb868b8
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612306"
---
# <a name="modulegenericreleasenotifiergenericreleasenotifier-constructor"></a>Construtor Module::GenericReleaseNotifier::GenericReleaseNotifier

Inicializa uma nova instância dos **genericreleasenotifier** classe.

## <a name="syntax"></a>Sintaxe

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
Especificar **verdadeira** para habilitar a chamada subjacente [Module:: ReleaseNotifier::Release()](../windows/module-releasenotifier-release.md) método; caso contrário, especifique **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module::GenericReleaseNotifier](../windows/module-genericreleasenotifier-class.md)