---
title: "ML Error Messages | Microsoft Docs"
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
  - "vc.errors.ml"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MASM (Microsoft Macro Assembler), ML error messages"
ms.assetid: e7e164b3-6d65-4b5b-8925-bfbebc043523
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Error Messages
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As mensagens de erro geradas pelos componentes MASM se encaixam em três categorias:  
  
-   **Erros fatais.** Eles indicam um problema grave que impede que o utilitário de concluir seu processo normal.  
  
-   **Erros não fatais.** O utilitário pode concluir seu processo.  Se isso acontecer, seu resultado não provavelmente será o item desejado.  
  
-   **Avisos.** Essas mensagens indicam condições que podem impedi\-lo de obter os resultados desejados.  
  
 Todas as mensagens de erro levar da seguinte forma:  
  
```  
  
Utility: Filename (Line) : [Error_type} (Code): Message_text  
```  
  
 Onde:  
  
 `Utility`  
 O programa que enviou a mensagem de erro.  
  
 *Nome do arquivo*  
 O arquivo que contém a condição de geração de erro.  
  
 *Line*  
 A linha aproximada onde existe a condição de erro.  
  
 *Error\_type*  
 Erro fatal, erro ou aviso.  
  
 *Código*  
 O código de erro exclusivo 5 ou 6 dígitos.  
  
 `Message_text`  
 Uma descrição curta e geral a condição de erro.  
  
## Consulte também  
 [Microsoft Macro Assembler Reference](../../assembler/masm/microsoft-macro-assembler-reference.md)