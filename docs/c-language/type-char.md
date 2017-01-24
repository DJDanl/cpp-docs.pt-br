---
title: "Tipo char | Microsoft Docs"
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
helpviewer_keywords: 
  - "palavra-chave char [C]"
  - "tipo char"
  - "palavra-chave char não assinada [C]"
ms.assetid: a5da0866-e780-4793-be87-15a8426e7ea0
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipo char
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo `char` é usado para armazenar o valor inteiro de um membro do conjunto de caracteres representável.  Esse valor inteiro é o código ASCII que corresponde ao caractere especificado.  
  
 **Específico da Microsoft**  
  
 Os valores de caracteres do tipo `unsigned char` têm um intervalo de 0 a 0xFF hexadecimal.  Um **signed char** tem o intervalo de 0x80 a 0x7F.  Esses intervalos podem ser traduzidos em de 0 a 255 decimal, e –128 a \+127 decimal, respectivamente.  A opção do compilador \/J altera o padrão de **signed** para `unsigned`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)