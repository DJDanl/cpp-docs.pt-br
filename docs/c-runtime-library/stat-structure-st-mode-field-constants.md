---
title: "Constantes de campo _stat estrutura st_mode | Microsoft Docs"
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
  - "S_IFCHR"
  - "S_IFDIR"
  - "_S_IWRITE"
  - "S_IFMT"
  - "_S_IFDIR"
  - "_S_IREAD"
  - "S_IEXEC"
  - "_S_IEXEC"
  - "_S_IFMT"
  - "S_IWRITE"
  - "S_IFREG"
  - "S_IREAD"
  - "_S_IFCHR"
  - "_S_IFREG"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _S_IEXEC"
  - "Constante _S_IFCHR"
  - "Constante _S_IFDIR"
  - "Constante _S_IFMT"
  - "Constante _S_IFREG"
  - "Constante _S_IREAD"
  - "Constante _S_IWRITE"
  - "Constante S_IEXEC"
  - "Constante S_IFCHR"
  - "Constante S_IFDIR"
  - "Constante S_IFMT"
  - "Constante S_IFREG"
  - "Constante S_IREAD"
  - "Constante S_IWRITE"
  - "Constantes de campo st_mode"
  - "Estrutura stat"
  - "Estrutura stat, constantes"
ms.assetid: fd462004-7563-4766-8443-30b0a86174b6
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de campo _stat estrutura st_mode
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <sys/stat.h>  
  
```  
  
## Comentários  
 Essas constantes são usadas para indicar o tipo de arquivo no campo de **st\_mode** de [estrutura de \_stat](../c-runtime-library/standard-types.md).  
  
 As constantes de máscara de bit são descritas abaixo:  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_S_IFMT`|Máscara do tipo de arquivo|  
|`_S_IFDIR`|Diretório|  
|`_S_IFCHR`|Especiais de caractere \(indica se um dispositivo conjunto\)|  
|`_S_IFREG`|Normal|  
|`_S_IREAD`|Permissão de leitura, proprietário|  
|`_S_IWRITE`|Permissão de gravação, o proprietário|  
|`_S_IEXEC`|Executar\/permissão de pesquisa, proprietário|  
  
## Consulte também  
 [Funções \_stat, \_wstat](../c-runtime-library/reference/stat-functions.md)   
 [\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [Tipos padrão](../c-runtime-library/standard-types.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)