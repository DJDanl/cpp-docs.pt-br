---
title: "Estrutura VerifyInterfaceHelper | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::Details::VerifyInterfaceHelper"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura VerifyInterfaceHelper"
ms.assetid: ea95b641-199a-4fdf-964b-186b40cb3ba7
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura VerifyInterfaceHelper
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   bool isWinRTInterface,  
   typename I  
>  
struct VerifyInterfaceHelper;  
  
template <  
   typename I  
>  
struct VerifyInterfaceHelper<false, I>;  
```  
  
#### Parâmetros  
 `I`  
 Uma interface a ser verificado.  
  
 `isWinRTInterface`  
  
## Comentários  
 Verifica se a interface especificada pelo parâmetro do modelo atende a determinados requisitos.  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método VerifyInterfaceHelper::Verify](../windows/verifyinterfacehelper-verify-method.md)||  
  
## Hierarquia de Herança  
 `VerifyInterfaceHelper`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)