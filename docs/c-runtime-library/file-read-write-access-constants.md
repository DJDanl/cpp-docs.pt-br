---
title: "Constantes de acesso de leitura/grava&#231;&#227;o de arquivo | Microsoft Docs"
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
  - "c.constants.file"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "constantes de acesso para leitura/gravação de arquivo"
  - "constantes [C++], atributos de arquivo"
  - "constantes de acesso de leitura/gravação de arquivo"
  - "constantes de acesso de leitura/gravação"
  - "constantes de acesso de gravação"
ms.assetid: 56cd1d22-39a5-4fcf-bea2-7046d249e8ee
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de acesso de leitura/grava&#231;&#227;o de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <stdio.h>  
```  
  
## Comentários  
 Essas constantes especificam o tipo de acesso \(“a”, “r”,” ou “w\) solicitado para o arquivo.  [modo de conversão](../c-runtime-library/file-translation-constants.md) \(“b” ou “t”\) e [modo de confirmação\-à\- disco](../Topic/Commit-To-Disk%20Constants.md) \(“c” ou “n”\) podem ser especificados com o tipo de acesso.  
  
 Os tipos de acesso são descritos abaixo.  
  
 **"a"**  
 Abre gravando no final do arquivo \(adicionar\); cria o arquivo primeiro se não existir.  Todas as operações de gravação ocorrem no final do arquivo.  Embora o ponteiro de arquivo pode ser reposicionado usando `fseek` ou **rewind**, sempre é movido de volta ao final do arquivo antes que qualquer operação de gravação foi executada.  
  
 **"a\+"**  
 Mesmo que acima, mas também permite ao ler.  
  
 **"r"**  
 Abre para leitura.  Se o arquivo não existir ou não for encontrado, a chamada para abrir o arquivo falhará.  
  
 **"r\+"**  
 Abre para leitura e gravação.  Se o arquivo não existir ou não for encontrado, a chamada para abrir o arquivo falhará.  
  
 **"w"**  
 Abre um arquivo vazio para gravação.  Se o arquivo determinado existir, seu conteúdo será destruído.  
  
 **"w\+"**  
 Abre um arquivo vazio para a leitura e gravação.  Se o arquivo determinado existir, seu conteúdo será destruído.  
  
 Quando o “r\+”, “w\+ o tipo”,” ou “a\+ forem especificados, a leitura e gravação são permitidas \(o arquivo é aberto para “atualização”\).  No entanto, quando você alternar entre a leitura e a gravação, deve haver `fflush`de intervenção, `fsetpos`, `fseek`, ou uma operação de **rewind** .  A posição atual pode ser especificado para a operação de `fsetpos` ou de `fseek` .  
  
## Consulte também  
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [fopen, \_wfopen](../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, \_wfreopen](../c-runtime-library/reference/freopen-wfreopen.md)   
 [\_fsopen, \_wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)   
 [\_popen, \_wpopen](../c-runtime-library/reference/popen-wpopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)