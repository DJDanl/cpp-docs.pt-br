---
title: "Constantes de atributo do arquivo | Microsoft Docs"
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
  - "A_HIDDEN"
  - "_A_NORMAL"
  - "_A_SUBDIR"
  - "_A_RDONLY"
  - "A_NORMAL"
  - "A_SUBDIR"
  - "_A_SYSTEM"
  - "c.constants.file"
  - "_A_HIDDEN"
  - "A_RDONLY"
  - "_A_ARCH"
  - "A_ARCH"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _A_ARCH"
  - "Constante _A_HIDDEN"
  - "Constante _A_NORMAL"
  - "Constante _A_RDONLY"
  - "Constante _A_SUBDIR"
  - "Constante _A_SYSTEM"
  - "constantes [C++], atributos de arquivo"
  - "constantes de atributo de arquivo [C++]"
  - "Arquivos  [C++], constantes de atributo de arquivo"
ms.assetid: 8dc8ccb9-99f5-446b-876c-7ebecc2f764f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de atributo do arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <io.h>  
```  
  
## Comentários  
 Essas constantes especificam atributos atuais do arquivo ou diretório especificado pela função.  
  
 Os atributos são representados por seguintes constantes manifestas:  
  
 `_A_ARCH`  
 Arquivo morto.  Defina sempre que o arquivo for alterado, e limpo pelo comando BACKUP.  Valor: 0x20  
  
 `_A_HIDDEN`  
 Arquivo oculto.  Consultado não normalmente com o comando de DIR, a menos que a opção \/AH é usada.  Retorna informações sobre arquivos normais bem como arquivos com esse atributo.  Valor: 0x02  
  
 `_A_NORMAL`  
 Normal.  Arquivo pode ser lida ou gravada sem à restrição.  Valor: 0x00  
  
 `_A_RDONLY`  
 Somente leitura.  Arquivo não pode ser aberto para gravação, e um arquivo com o mesmo nome não pode ser criado.  Valor: 0x01  
  
 `_A_SUBDIR`  
 Subdiretório.  Valor: 0x10  
  
 `_A_SYSTEM`  
 Sistema de arquivos  Consultado não normalmente com o comando de DIR, a menos que a opção \/AS é usada.  Valor: 0x04  
  
 Várias constantes podem ser combinadas pelo operador OR \(&#124;\).  
  
## Consulte também  
 [Funções de pesquisa de nome de arquivo](../c-runtime-library/filename-search-functions.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)