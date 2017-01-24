---
title: "Erro fatal C1067 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1067"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1067"
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1067
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: o limite 64K no tamanho de um registro de tipo foi excedido  
  
 Esse erro pode ocorrer se um símbolo tem um nome decorado que excede 247 caracteres.  Para resolver, encurte o nome de símbolo.  
  
 Quando o compilador gerenciar informações de depuração, emite os registros de tipo para definir os tipos encontrados no código\-fonte.  Por exemplo, os registros de tipo incluem estruturas simples e listas de argumento de funções.  Alguns desses registros de classificação podem ser grandes listas.  
  
 Há um limite 64K no tamanho de qualquer registro do tipo.  Se o limite for excedido uniforme neste erro ocorrerá.  
  
 C1067 também pode ocorrer se houver muitos símbolos com nomes longos ou se uma classe, uma estrutura, ou uma união têm muitos membros.