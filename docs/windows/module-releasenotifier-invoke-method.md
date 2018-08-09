---
title: 'Module:: releasenotifier:: invocar método | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::ReleaseNotifier::Invoke
dev_langs:
- C++
helpviewer_keywords:
- Invoke method
ms.assetid: f62686fe-74bf-482b-a46b-6a3c09b80e7e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 48e488188ed040d29ef70f273991d1df9cf1d63e
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014595"
---
# <a name="modulereleasenotifierinvoke-method"></a>Método Module::ReleaseNotifier::Invoke
Quando implementado, chama um manipulador de eventos quando o último objeto em um módulo é liberado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
virtual void Invoke() = 0;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)