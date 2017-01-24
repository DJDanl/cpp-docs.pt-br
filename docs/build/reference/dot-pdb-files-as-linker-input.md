---
title: "Arquivos .Pdb como entrada de vinculador | Microsoft Docs"
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
  - "arquivos .pdb, como entrada de vinculador"
  - "arquivos PDB, como entrada de vinculador"
ms.assetid: c1071478-2369-4b03-9df8-71761cf82f3b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos .Pdb como entrada de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O objeto \(\) .obj arquivos criado com a opção \/Zi contém o nome de um base de dados \(PDB\) do programa.  Você não especificar o nome de arquivo PDB do objeto ao vinculador; O LINK usa o nome inserido para localizar o PDB se necessário.  Isso também se aplica a objetos debuggable contidos em uma biblioteca; o PDB para uma biblioteca debuggable deve estar disponível para o vinculador junto com a biblioteca.  
  
 O LINK também usa um PDB para manter informações de depuração para o arquivo ou o arquivo .dll.  O PDB de programa é um arquivo de saída e um arquivo de entrada, porque o LINK atualiza o PDB quando recria o programa.  
  
## Consulte também  
 [Arquivos de entrada LINK](../../build/reference/link-input-files.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)