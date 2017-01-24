---
title: "Extraindo um membro da biblioteca | Microsoft Docs"
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
  - "Lib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /EXTRACT (gerenciador de biblioteca)"
  - "opção de gerenciador de biblioteca EXTRACT"
  - "opção de gerenciador de biblioteca -EXTRACT"
  - "extraindo membros de biblioteca"
  - "LIB [C++], extraindo membros de biblioteca"
  - "bibliotecas, extraindo membros"
ms.assetid: a2c5c2a1-9b7e-489a-a9a4-1dec694e1fc5
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Extraindo um membro da biblioteca
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar o LIB para criar um arquivo do objeto \(.obj\) que contém uma cópia de um membro existente de uma biblioteca.  Para extrair uma cópia de um membro, use a seguinte sintaxe:  
  
```  
LIB library /EXTRACT:member /OUT:objectfile  
```  
  
 Este comando cria um arquivo de .obj chamado *objectfile* que contém uma cópia de `member`*de uma biblioteca*.  O nome de `member` diferencia maiúsculas de minúsculas.  Você pode extrair apenas um membro em um único comando.  A opção \/OUT for necessária; não há nenhum nome de saída padrão.  Se um arquivo chamado *objectfile* já existe no diretório especificado \(ou no diretório atual, se nenhum diretório é especificado com *objectfile*\), *o objectfile* extraído substituir o arquivo existente.  
  
## Consulte também  
 [Referência LIB](../../build/reference/lib-reference.md)