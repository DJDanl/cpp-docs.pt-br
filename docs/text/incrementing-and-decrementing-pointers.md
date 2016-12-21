---
title: "Incrementando e decrementando ponteiros | Microsoft Docs"
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
  - "decrementando ponteiros"
  - "incrementando ponteiros"
  - "MBCS [C++], ponteiros"
  - "ponteiros [C++], caracteres multibyte"
ms.assetid: 0872b4a0-e2bd-4004-8319-070efb76f2fd
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Incrementando e decrementando ponteiros
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as dicas a seguir:  
  
-   Ponto inicial para os bytes, não em bytes finais.  Geralmente é unsafe ter um ponteiro para um byte final.  Geralmente é mais seguro analisar uma cadeia de caracteres para frente em vez de em contrário.  
  
-   Há um incremento do ponteiro\/as funções e macros diminuição disponíveis para mover sobre um caractere inteiro:  
  
    ```  
    sz1++;  
    ```  
  
     se torna:  
  
    ```  
    sz1 = _mbsinc( sz1 );  
    ```  
  
     As funções de `_mbsinc` e de incremento `_mbsdec` corretamente e diminui em unidades de `character` , independentemente do tamanho de caractere.  
  
-   Para reduzir, é necessário um ponteiro para o início da cadeia de caracteres, como a seguir:  
  
    ```  
    sz2--;  
    ```  
  
     se torna:  
  
    ```  
    sz2 = _mbsdec( sz2Head, sz2 );  
    ```  
  
     Como alternativa, o ponteiro principal poderá ser a um caractere válido na cadeia de caracteres, de modo que:  
  
    ```  
    sz2Head < sz2  
    ```  
  
     Você deve ter um ponteiro para um byte inicial válida conhecido.  
  
-   Talvez você queira manter um ponteiro para o caractere anterior para chamadas mais rápidos a `_mbsdec`.  
  
## Consulte também  
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)   
 [Índices de byte](../text/byte-indices.md)