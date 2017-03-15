---
title: "Enumera&#231;&#227;o RuntimeClassType | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::RuntimeClassType"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Enumeração RuntimeClassType"
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#227;o RuntimeClassType
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o tipo de instância de [RuntimeClass](../windows/runtimeclass-class.md) com suporte.  
  
## Sintaxe  
  
```  
enum RuntimeClassType;  
```  
  
## Membros  
  
### Valores  
  
|Nome|Descrição|  
|----------|---------------|  
|`ClassicCom`|Uma classe de tempo de execução do COM o clássico.|  
|`Delegate`|Equivalente a **ClassicCom**.|  
|`InhibitFtmBase`|Suporte de `FtmBase` de desabilita quando `__WRL_CONFIGURATION_LEGACY__` não está definido.|  
|`InhibitWeakReference`|Suporte fraco de referência do desabilita.|  
|`WinRt`|Uma classe de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .|  
|`WinRtClassicComMix`|Uma combinação de `WinRt` e de `ClassicCom`.|  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)