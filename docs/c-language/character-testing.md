---
title: "Teste de caractere | Microsoft Docs"
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
  - "C"
ms.assetid: 376ba061-bae3-427e-9569-33fa5949a199
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Teste de caractere
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 4.3.1** Os conjuntos de caracteres testados pelas funções `isalnum`, `isalpha`, `iscntrl`, `islower`, `isprint` e `isupper`  
  
 A lista a seguir descreve essas funções como são implementadas pelo compilador Microsoft C.  
  
|Função|Testes para|  
|------------|-----------------|  
|`isalnum`|Caracteres 0 – 9, A–Z, a–z ASCII 48–57, 65–90, 97–122|  
|`isalpha`|Caracteres A–Z, a–z ASCII 65–90, 97–122|  
|`iscntrl`|ASCII 0 –31, 127|  
|`islower`|Caracteres a–z ASCII 97–122|  
|`isprint`|Caracteres A–Z, a–z, 0 – 9, pontuação, espaço ASCII 32–126|  
|`isupper`|Caracteres A–Z ASCII 65–90|  
  
## Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)