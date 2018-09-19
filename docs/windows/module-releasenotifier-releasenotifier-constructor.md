---
title: Construtor Module::ReleaseNotifier::ReleaseNotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::ReleaseNotifier::ReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- ReleaseNotifier, constructor
ms.assetid: 889a3c9a-2366-44a1-ba7d-a59c1885e7f3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e43abd46ccfb150936ff435360611289f18a1270
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405015"
---
# <a name="modulereleasenotifierreleasenotifier-constructor"></a>Construtor Module::ReleaseNotifier::ReleaseNotifier

Inicializa uma nova instância dos **releasenotifier** classe.

## <a name="syntax"></a>Sintaxe

```cpp
ReleaseNotifier(bool release) throw();
```

### <a name="parameters"></a>Parâmetros

*release*<br/>
**Verdadeiro** para excluir essa instância quando o `Release` método é chamado; **falsos** não excluir esta instância.

## <a name="exceptions"></a>Exceções

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)