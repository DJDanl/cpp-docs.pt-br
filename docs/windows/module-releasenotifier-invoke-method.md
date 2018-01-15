---
title: "Releasenotifier:: método Invoke | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::ReleaseNotifier::Invoke
dev_langs: C++
helpviewer_keywords: Invoke method
ms.assetid: f62686fe-74bf-482b-a46b-6a3c09b80e7e
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e2eff342264bf7866a4eb95147bca7ce41acb997
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulereleasenotifierinvoke-method"></a>Método Module::ReleaseNotifier::Invoke
Quando implementada, chama um manipulador de eventos quando o último objeto em um módulo é liberado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual void Invoke() = 0;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)