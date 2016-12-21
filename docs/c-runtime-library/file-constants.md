---
title: "Constantes de arquivo | Microsoft Docs"
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
  - "_O_EXCL"
  - "_O_RDWR"
  - "_O_APPEND"
  - "_O_RDONLY"
  - "_O_TRUNC"
  - "_O_CREAT"
  - "_O_WRONLY"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _O_APPEND"
  - "Constante _O_CREAT"
  - "Constante _O_EXCL"
  - "Constante _O_RDONLY"
  - "Constante _O_RDWR"
  - "Constante _O_TRUNC"
  - "Constante _O_WRONLY"
  - "Constante O_APPEND"
  - "Constante O_CREAT"
  - "Constante O_EXCL"
  - "Constante O_RDONLY"
  - "Constante O_RDWR"
  - "Constante O_TRUNC"
  - "Constante O_WRONLY"
ms.assetid: c8fa5548-9ac2-4217-801d-eb45e86f2fa4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <fcntl.h>  
  
```  
  
## Comentários  
 A expressão de inteiro formada de uma ou mais dessas constantes determina o tipo de operações de leitura ou gravação permitidas.  É formada combinando uma ou mais constantes com uma constante de tradução\- modo.  
  
 As constantes de arquivo são os seguintes:  
  
 `_O_APPEND`  
 Reposicionar o ponteiro de arquivo ao final do arquivo antes de cada operação de gravação.  
  
 `_O_CREAT`  
 Cria e abre um novo arquivo para gravação; isto não tem nenhum efeito se o arquivo especificado pelo *nome de arquivo* existe.  
  
 `_O_EXCL`  
 Retorna um valor de erro se o arquivo especificado pelo *nome de arquivo* existe.  Se aplica somente quando usado com `_O_CREAT`.  
  
 `_O_RDONLY`  
 Abre o arquivo para somente leitura; se esse sinalizador for fornecido, ou `_O_RDWR` ou `_O_WRONLY` podem ser dados.  
  
 `_O_RDWR`  
 Abre o arquivo para leitura e gravação; se esse sinalizador for fornecido, ou `_O_RDONLY` ou `_O_WRONLY` podem ser dados.  
  
 `_O_TRUNC`  
 Abre e trunca um arquivo existente ao comprimento zero; o arquivo deve ter permissão de gravação.  O conteúdo do arquivo são destruídos.  Se esse sinalizador for fornecido, você não pode especificar `_O_RDONLY`.  
  
 `_O_WRONLY`  
 Abre o arquivo para gravação; somente se esse sinalizador for fornecido, ou `_O_RDONLY` ou `_O_RDWR` podem ser dados.  
  
## Consulte também  
 [\_open, \_wopen](../c-runtime-library/reference/open-wopen.md)   
 [\_sopen, \_wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)