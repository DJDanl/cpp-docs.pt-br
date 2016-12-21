---
title: "M&#233;todo ActivationFactory::GetTrustLevel | Microsoft Docs"
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
  - "module/Microsoft::WRL::ActivationFactory::GetTrustLevel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetTrustLevel"
ms.assetid: 31547ae6-d2ab-4039-923c-154d53fb1a8b
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ActivationFactory::GetTrustLevel
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o nível de confiança do objeto que o ActivationFactory atual cria uma instância do.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   GetTrustLevel  
)(_Out_ TrustLevel* trustLvl);  
```  
  
#### Parâmetros  
 `trustLvl`  
 Quando esta operação concluir, o nível de confiança da classe de tempo de execução que o ActivationFactory cria uma instância do.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um erro de asserção é emitido e `trustLvl` é definido como FullTrust.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ActivationFactory](../windows/activationfactory-class.md)