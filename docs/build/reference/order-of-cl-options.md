---
title: "Ordem de op&#231;&#245;es CL | Microsoft Docs"
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
  - "cl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, definindo opções"
ms.assetid: 300908ce-ae00-4b45-964b-e4e69ff6777b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Ordem de op&#231;&#245;es CL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As opções podem aparecer em qualquer lugar na linha de comando de CL, exceto a opção \/link, que deve acontecer por último.  O compilador começa com as opções especificadas em [Variável de ambiente de CL](../../build/reference/cl-environment-variables.md) e depois ler os arquivos de comando de processamento da linha de comando da esquerda para a direita — na ordem em que os encontra.  Cada opção se aplica a todos os arquivos na linha de comando.  Se o CL encontrar conflitantes opções, use a opção mais à direita.  
  
## Consulte também  
 [Sintaxe da linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)