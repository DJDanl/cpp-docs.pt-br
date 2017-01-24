---
title: "Naked (C) | Microsoft Docs"
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
  - "código de epílogo"
  - "palavra-chave naked [C]"
  - "palavra-chave naked [C], atributo de classe de armazenamento"
  - "código de prólogo"
ms.assetid: 23b1209b-93ba-46ad-a60f-2327c1933eaf
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Naked (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 O atributo de classe de armazenamento naked é uma extensão específica da Microsoft na linguagem C.  O compilador gera um código sem código de prólogo e de epílogo para funções declaradas com o atributo de classe de armazenamento naked.  As funções naked são úteis quando você precisa escrever suas próprias sequências de código de prólogo\/epílogo usando o código de assembler embutido.  As funções naked são úteis para escrever drivers para dispositivo virtuais.  
  
 Para obter informações específicas sobre como usar o atributo naked, consulte [Funções naked](../c-language/naked-functions.md).  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)