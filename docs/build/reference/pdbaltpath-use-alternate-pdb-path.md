---
title: "/PDBALTPATH (usar caminho de PDB alternativo) | Microsoft Docs"
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
  - "/pdbaltpath"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos .pdb, caminho"
  - "Opção /PDBALTPATH (dumpbin)"
  - "arquivos PDB, caminho"
  - "opção dumpbin PDBALTPATH"
  - "opção dumpbin -PDBALTPATH"
ms.assetid: 72e200aa-e2c3-4ad8-b687-25528da1aaaf
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /PDBALTPATH (usar caminho de PDB alternativo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/PDBALTPATH:pdb_file_name  
```  
  
## Comentários  
 onde:  
  
 *pdb\_file\_name*  
 O caminho e o nome de arquivo para o arquivo .pdb.  
  
## Comentários  
 Use essa opção para oferecer um local alternativo para o arquivo Program Database \(.pdb\) em um arquivo binário compilado.  Normalmente, o vinculador registra o local do arquivo .pdb nos binários que o reproduzem.  Você pode usar essa opção para oferecer um caminho e o nome de arquivo diferentes para o arquivo .pdb.  As informações fornecidas com \/PDBALTPATH não alteram o local ou o nome do arquivo .pdb real; o que muda são as informações que o vinculador grava no arquivo binário.  Isso faz com que seja possível fornecer um caminho independente da estrutura do arquivo do computador da compilação.  Dois usos comuns dessa opção são: oferecer um caminho de rede ou um arquivo sem informações de caminho.  
  
 O valor de *pdb\_file\_name* pode ser uma cadeia de caracteres arbitrária, uma variável de ambiente ou **%\_PDB%**.  O vinculador expandirá uma variável de ambiente, como **%SystemRoot%**, para seu valor.  O vinculador define as variáveis de ambiente **%\_PDB%** e **%\_EXT%**.  **%\_PDB%** expande para o nome de arquivo do arquivo .pdb real sem nenhuma informação de caminho, e **%\_EXT%** é a extensão do executável gerado.  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)   
 [\/PDBPATH](../../build/reference/pdbpath.md)