---
title: "Diretiva #error (C/C++) | Microsoft Docs"
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
  - "#error"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #error"
  - "diretiva error (diretiva #error)"
  - "pré-processador, Diretivas ()"
ms.assetid: d550a802-ff19-4347-9597-688935d23b2b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretiva #error (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A política `#error` emite uma mensagem de erro especificada pelo usuário em tempo de compilação e finaliza a compilação.  
  
## Sintaxe  
  
```  
#error token-string  
```  
  
## Comentários  
 A mensagem de erro que esta política emite inclui o parâmetro *token\-string*.  O parâmetro `token-string` não está sujeito à expansão macro.  Essa política é mais útil durante o pré\-processamento para notificar o desenvolvedor de uma inconsistência do programa ou de uma violação de restrição.  O exemplo a seguir demonstra o processamento do erro durante pré\-processamento:  
  
```  
#if !defined(__cplusplus)  
#error C++ compiler required.  
#endif  
```  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)