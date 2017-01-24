---
title: "Operadores cast | Microsoft Docs"
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
  - "operadores cast"
  - "operadores [C++], cast"
  - "conversões de tipo, operadores"
  - "conversão de tipo, operadores cast"
ms.assetid: 43b90bbd-39ef-43e6-ae5d-e8a67a01de40
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores cast
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma conversão de tipo fornece um método para conversão explícita do tipo de um objeto em uma situação específica.  
  
## Sintaxe  
 *cast\-expression*:  
 *unary\-expression*  
  
 **\(**  *type\-name*  **\)**  *cast\-expression*  
  
 O compilador trata *cast\-expression* como tipo *type\-name* depois que uma conversão de tipo é feita.  As conversões podem ser usadas para converter objetos de qualquer tipo escalar em ou de qualquer outro tipo escalar.  As conversões de tipo explícito são restringidas pelas mesmas regras que determinam os efeitos de conversões implícitas, descritos em [Conversões de atribuição](../c-language/assignment-conversions.md).  As restrições adicionais de conversões podem resultar de tamanhos reais ou de representação de tipos específicos.  Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre tamanhos reais de tipos integrais.  Para obter mais informações sobre conversões de tipos, consulte [Conversões Type\-Cast](../c-language/type-cast-conversions.md).  
  
## Consulte também  
 [Operador cast: \(\)](../Topic/Cast%20Operator:%20\(\).md)