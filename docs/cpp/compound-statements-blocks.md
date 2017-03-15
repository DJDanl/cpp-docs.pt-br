---
title: "Instru&#231;&#245;es compostas (blocos) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "}"
  - "{"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "blocos, sobre blocos"
  - "instruções compostas"
ms.assetid: 23855939-7430-498e-8936-0c70055ea701
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es compostas (blocos)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma instrução composta consiste em zero ou mais instruções entre chaves \(**{}**\).  Uma instrução composta pode ser usada em qualquer lugar em que uma instrução é esperada.  As instruções compostas são comumente chamadas de "blocos".  
  
## Sintaxe  
  
```  
  
{ [ statement-list ] }  
```  
  
## Comentários  
 O exemplo a seguir usa uma instrução composta como a parte *statement* da instrução **if** \(consulte [A instrução If](../cpp/if-else-statement-cpp.md) para obter detalhes sobre a sintaxe\):  
  
```  
if( Amount > 100 )  
{  
    cout << "Amount was too large to handle\n";  
    Alert();  
}  
else  
    Balance -= Amount;  
```  
  
> [!NOTE]
>  Como uma declaração é uma instrução, uma declaração pode ser uma das instruções de *statement\-list*.  Portanto, os nomes declarados em uma instrução composta, mas não declarados explicitamente como estáticos, têm escopo e vida útil locais \(para objetos\).  Consulte [Escopo](../cpp/scope-visual-cpp.md) para obter detalhes sobre o tratamento de nomes com escopo local.  
  
## Consulte também  
 [Visão geral de instruções C\+\+](../cpp/overview-of-cpp-statements.md)