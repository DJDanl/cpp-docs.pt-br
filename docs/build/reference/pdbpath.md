---
title: "/PDBPATH | Microsoft Docs"
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
  - "/pdbpath"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos .pdb, caminho"
  - "Opção /PDBPATH (dumpbin)"
  - "arquivos PDB, caminho"
  - "opção dumpbin PDBPATH"
  - "opção dumpbin -PDBPATH"
ms.assetid: ccf67dcd-0b23-4250-ad47-06c48acbe82b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /PDBPATH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/PDBPATH[:VERBOSE] filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 O nome do arquivo .dll ou .exe para a qual você deseja localizar o arquivo .pdb de correspondência.  
  
 DETAILED \(opcional\)  
 Informa todos os diretórios onde foi feita uma tentativa de localizar o arquivo .pdb.  
  
## Comentários  
 \/PDBPATH pesquisará o computador com os mesmos caminhos que o depurador procurararia por um arquivo .pdb e reportará que, se houver, os arquivos .pdb correspondessem ao arquivo especificado no *nome de arquivo*.  
  
 Ao usar o depurador do Visual Studio, é possível apresentar um problema devido ao fato de que o depurador está usando um arquivo .pdb para uma versão diferente do arquivo que está sendo depurado.  
  
 \/PDBPATH pesquisará em arquivos .pdb com os caminhos:  
  
-   Verifique o local onde o executável reside.  
  
-   Verifique o local PDB gravado no executável.  Este normalmente é o local na imagem vinculada foi.  
  
-   Verifique ao longo do caminho de pesquisa configurado no Visual Studio IDE.  
  
-   Verifique ao longo dos caminhos em variáveis de ambiente de \_NT\_SYMBOL\_PATH e de \_NT\_ALT\_SYMBOL\_PATH.  
  
-   Fazer check\-in do diretório do Windows.  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)   
 [\/PDBALTPATH \(usar caminho de PDB alternativo\)](../../build/reference/pdbaltpath-use-alternate-pdb-path.md)