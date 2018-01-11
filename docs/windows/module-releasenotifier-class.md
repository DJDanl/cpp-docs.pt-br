---
title: Classe releasenotifier | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::ReleaseNotifier
dev_langs: C++
helpviewer_keywords: ReleaseNotifier class
ms.assetid: 17249cd1-4d88-42e3-8146-da9e942d12bd
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: eb640f146109363a8025818b3ec560c250029914
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulereleasenotifier-class"></a>Classe Module::ReleaseNotifier
Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class ReleaseNotifier;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Destruidor Module::ReleaseNotifier::~ReleaseNotifier](../windows/module-releasenotifier-tilde-releasenotifier-destructor.md)|Deinitializes a instância atual da classe releasenotifier.|  
|[Construtor Module::ReleaseNotifier::ReleaseNotifier](../windows/module-releasenotifier-releasenotifier-constructor.md)|Inicializa uma nova instância da classe releasenotifier.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Module::ReleaseNotifier::Invoke](../windows/module-releasenotifier-invoke-method.md)|Quando implementada, chama um manipulador de eventos quando o último objeto em um módulo é liberado.|  
|[Module::ReleaseNotifier::Release](../windows/module-releasenotifier-release.md)|Exclui o objeto Module atual se o objeto foi criado com um parâmetro de `true`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ReleaseNotifier`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)