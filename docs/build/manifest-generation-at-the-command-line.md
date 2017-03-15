---
title: "Gera&#231;&#227;o de manifesto na linha de comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ferramenta de manifesto (mt.exe)"
  - "manifestos [C++]"
ms.assetid: fc2ff255-82b1-4c44-af76-8405c5850292
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Gera&#231;&#227;o de manifesto na linha de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao criar aplicativos C\/C\+\+ de linha de comando que usa o nmake ou ferramentas semelhantes, o manifesto é gerado depois que o vinculador processar todos os arquivos de objeto e compilou binário final.  O vinculador coleta informações de assembly armazenada em arquivos de objeto e combina essas informações em um arquivo de manifesto final.  Por padrão o vinculador gerará um arquivo denominado \<binary\_name\>.\<extension\>.manifest para descrever o binário final.  O vinculador não digitar um arquivo de manifesto em binários e só pode gerar um manifesto como um arquivo externo.  Há várias maneiras de inserir um manifesto no final binário, como o uso de [Ferramenta manifesta \(mt.exe\)](http://msdn.microsoft.com/library/aa375649) ou criar o manifesto em um arquivo de recursos.  É importante ter em mente que as regras específicas precisam ser seguidas ao inserir um manifesto binário no final para habilitar recursos como vincular, assinar, e edição e incrementais para continuar.  Esses e outras opções são discutidos em [Como inserir um manifesto em um aplicativo do C\/C\+\+](../build/how-to-embed-a-manifest-inside-a-c-cpp-application.md) ao criar a linha de comando.  
  
## Consulte também  
 [Manifestos](http://msdn.microsoft.com/library/aa375365)   
 [\/INCREMENTAL \(vincular de maneira incremental\)](../build/reference/incremental-link-incrementally.md)   
 [Assemblies de nome forte \(assinatura de assembly\)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md)   
 [Editar e continuar](../Topic/Edit%20and%20Continue.md)   
 [Noções básicas sobre geração de manifesto para programas do C\/C\+\+](../Topic/Understanding%20Manifest%20Generation%20for%20C-C++%20Programs.md)