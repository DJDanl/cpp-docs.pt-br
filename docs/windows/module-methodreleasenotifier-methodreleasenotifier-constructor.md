---
title: "Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Module::MethodReleaseNotifier::MethodReleaseNotifier"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MethodReleaseNotifier, o construtor"
ms.assetid: 762e2ca4-0a92-49de-9ff5-d3efa0f067c0
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe de Module::MethodReleaseNotifier.  
  
## Sintaxe  
  
```  
  
MethodReleaseNotifier(  
   _In_ T* object,   
   _In_ void (T::* method)(),   
   bool release) throw() :  
            ReleaseNotifier(release), object_(object),   
            method_(method);  
```  
  
#### Parâmetros  
 `object`  
 Um objeto cuja função de membro é um manipulador de eventos.  
  
 `method`  
 A função de membro do parâmetro `object` que é o manipulador de eventos.  
  
 `release`  
 Especifique `true` para habilitar chamar o método subjacente de [Module::ReleaseNotifier::Release \(\)](../windows/module-releasenotifier-release.md) ; caso contrário, especifique `false`.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe Module::MethodReleaseNotifier](../Topic/Module::MethodReleaseNotifier%20Class.md)