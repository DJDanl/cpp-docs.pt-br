---
title: Classe releasenotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::ReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- ReleaseNotifier class
ms.assetid: 17249cd1-4d88-42e3-8146-da9e942d12bd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 97c998f7e0814c5acae55dd3e9b747faed0242e1
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40016217"
---
# <a name="modulereleasenotifier-class"></a>Classe Module::ReleaseNotifier
Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class ReleaseNotifier;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Destruidor Module::ReleaseNotifier::~ReleaseNotifier](../windows/module-releasenotifier-tilde-releasenotifier-destructor.md)|Realiza o desligamento da instância atual do **releasenotifier** classe.|  
|[Construtor Module::ReleaseNotifier::ReleaseNotifier](../windows/module-releasenotifier-releasenotifier-constructor.md)|Inicializa uma nova instância dos **releasenotifier** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Module::ReleaseNotifier::Invoke](../windows/module-releasenotifier-invoke-method.md)|Quando implementado, chama um manipulador de eventos quando o último objeto em um módulo é liberado.|  
|[Module::ReleaseNotifier::Release](../windows/module-releasenotifier-release.md)|Exclui o atual **releasenotifier** se o objeto for construído com um parâmetro de objeto **verdadeiro**.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ReleaseNotifier`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)