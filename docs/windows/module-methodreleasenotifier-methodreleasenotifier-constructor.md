---
title: Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::MethodReleaseNotifier::MethodReleaseNotifier
dev_langs: C++
helpviewer_keywords: MethodReleaseNotifier, constructor
ms.assetid: 762e2ca4-0a92-49de-9ff5-d3efa0f067c0
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 045dd8dd0dbee58c0feea33bc7ce4f6cea30e591
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulemethodreleasenotifiermethodreleasenotifier-constructor"></a>Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier
Inicializa uma nova instância da classe methodreleasenotifier.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
MethodReleaseNotifier(  
   _In_ T* object,   
   _In_ void (T::* method)(),   
   bool release) throw() :  
            ReleaseNotifier(release), object_(object),   
            method_(method);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `object`  
 Um objeto cuja função de membro é um manipulador de eventos.  
  
 `method`  
 A função de membro do parâmetro `object` que é o manipulador de eventos.  
  
 `release`  
 Especifique `true` para habilitar a chamada subjacente [Module:: ReleaseNotifier::Release()](../windows/module-releasenotifier-release.md) método; caso contrário, especifique `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe Module::MethodReleaseNotifier](../windows/module-methodreleasenotifier-class.md)