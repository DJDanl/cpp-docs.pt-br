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
ms.openlocfilehash: 93dca0500971f0bcfdefd017457e02bf6a033660
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39608463"
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