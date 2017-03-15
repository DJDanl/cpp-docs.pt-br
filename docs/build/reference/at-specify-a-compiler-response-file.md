---
title: "@ (especificar um arquivo de resposta do compilador) | Microsoft Docs"
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
  - "@"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador @"
  - "Compilador cl.exe, especificando arquivos de resposta"
  - "arquivos de resposta, compilador C/C++"
ms.assetid: 400fffee-909d-4f60-bf76-45833e822685
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# @ (especificar um arquivo de resposta do compilador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica um arquivo de resposta do compilador.  
  
## Sintaxe  
  
```  
@response_file  
```  
  
## Arguments  
 `response_file`  
 Um arquivo de texto que contém comandos do compilador.  
  
## Comentários  
 Um arquivo de resposta pode conter todos os comandos que você especifica na linha de comando.  Isso pode ser útil se os argumentos de linha de comando excede 127 caracteres.  
  
 Não é possível especificar a opção de **@** do arquivo de resposta.  Isto é, um arquivo de resposta não pode inserir outro arquivo de resposta.  
  
 Na linha de comando você pode especificar quantas opções de arquivo de resposta \(por exemplo, `@respfile.1 @respfile.2`\) desejar.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
-   Um arquivo de resposta não pode ser especificada dentro do ambiente de desenvolvimento e deve ser especificado na linha de comando.  
  
### Para definir essa opção do compilador via programação  
  
-   Essa opção de compilador não pode ser modificada programaticamente.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)