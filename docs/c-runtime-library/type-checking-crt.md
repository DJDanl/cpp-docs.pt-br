---
title: "Verifica&#231;&#227;o de tipo (CRT) | Microsoft Docs"
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
  - "c.types"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "verificando tipo"
  - "verificação de tipo"
  - "funções de argumentos variáveis"
ms.assetid: 1ba7590b-d1c0-4636-b6a0-e231395abdad
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Verifica&#231;&#227;o de tipo (CRT)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O compilador executa verificação de tipo limitada em funções que podem fazer um número variável de argumentos, como segue:  
  
|Chamada de função|Argumentos de tipo verificados|  
|-----------------------|------------------------------------|  
|`_cprintf_s`, `_cscanf_s`, `printf_s`, `scanf_s`|Primeiro argumento \(cadeia de formato\)|  
|`fprintf_s`, `fscanf_s`, `sprintf_s`, `sscanf_s`|Primeiros dois argumentos \(arquivo ou buffer e cadeia de formato\)|  
|`_snprintf_s`|Primeiros três argumentos \(arquivo ou buffer, count, e cadeia de formato\)|  
|`_open`|Primeiros dois argumentos \(caminho e sinalizador de `_open` \)|  
|`_sopen_s`|Primeiros três argumentos \(caminho, sinalizador de `_open` , e compartilhar o modo\)|  
|`_execl`, `_execle`, `_execlp`, `_execlpe`|Primeiros dois argumentos \(caminho e ponteiro do primeiro argumento\)|  
|`_spawnl`, `_spawnle`, `_spawnlp`, `_spawnlpe`|Primeiros três argumentos \(sinalizador de modo, caminho, e primeiro ponteiro de argumento\)|  
  
 O compilador executa a mesma verificação de tipo limitada em contraparte de ampla caractere dessas funções.  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)