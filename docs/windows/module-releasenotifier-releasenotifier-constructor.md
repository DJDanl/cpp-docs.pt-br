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
ms.openlocfilehash: f4ab2d5d03516147acda38ea2133d7445695de80
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42598782"
---
# <a name="modulereleasenotifierreleasenotifier-constructor"></a>Construtor Module::ReleaseNotifier::ReleaseNotifier

Inicializa uma nova instância dos **releasenotifier** classe.

## <a name="syntax"></a>Sintaxe

```cpp
ReleaseNotifier(bool release) throw();
```

### <a name="parameters"></a>Parâmetros

*release*  
**Verdadeiro** para excluir essa instância quando o `Release` método é chamado; **falsos** não excluir esta instância.

## <a name="exceptions"></a>Exceções

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)