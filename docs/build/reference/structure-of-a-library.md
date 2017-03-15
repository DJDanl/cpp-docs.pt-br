---
title: "Estrutura de uma biblioteca | Microsoft Docs"
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
  - "bibliotecas, Estrutura "
ms.assetid: a5fda8e8-4a1b-4499-9095-0df935262ce4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura de uma biblioteca
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma biblioteca contém objetos de COFF.  Os objetos em uma biblioteca contêm as funções e os dados que podem ser referenciados externamente por outros objetos em um programa.  Um objeto em uma biblioteca as vezes é referenciado como um membro de biblioteca.  
  
 Você pode obter informações adicionais sobre o conteúdo da biblioteca executando a ferramenta de DUMPBIN com a opção do \/LINKERMEMBER.  Para obter mais informações sobre essa opção, consulte [Referência de DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
## Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)