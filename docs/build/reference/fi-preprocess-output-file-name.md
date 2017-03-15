---
title: "/Fi (pr&#233;-processar nome do arquivo de sa&#237;da) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/Fi"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Fi (C++)"
  - "Opção de compilador Fi (C++)"
  - "Opção de compilador -Fi (C++)"
  - "pré-processando arquivos de saída, nome do arquivo"
ms.assetid: 6d0ba983-a8b7-41ec-84f5-b4688ef8efee
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Fi (pr&#233;-processar nome do arquivo de sa&#237;da)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o nome do arquivo de saída no qual a opção do compilador de [\/P \(pré\-processar em um arquivo\)](../../build/reference/p-preprocess-to-a-file.md) grava a saída pré\-processados.  
  
## Sintaxe  
  
```  
/Fipathname  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`pathname`|O nome e o caminho do arquivo de saída gerado pela opção do compilador de **\/P** .|  
  
## Comentários  
 Use a opção do compilador de **\/Fi** em combinação com a opção do compilador de **\/P** .  
  
 Se você especificar apenas um caminho para o parâmetro de `pathname` , o nome de arquivo de origem é usado como o nome de arquivo de saída pré\-processados.  O parâmetro de `pathname` não requer uma extensão de nome de arquivo específico.  No entanto, uma extensão de “.i” é usada se você não especificar uma extensão de nome de arquivo.  
  
## Exemplo  
 A linha de comando a seguir preprocesses PROGRAM.cpp, preserva comentários, adiciona políticas de [\#line](../Topic/%23line%20Directive%20\(C-C++\).md) , e grava o resultado no arquivo de MYPROCESS.i.  
  
```  
CL /P /FiMYPROCESS.I PROGRAM.CPP  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [\/P \(pré\-processar em um arquivo\)](../../build/reference/p-preprocess-to-a-file.md)   
 [Especificando o nome de caminho](../Topic/Specifying%20the%20Pathname.md)