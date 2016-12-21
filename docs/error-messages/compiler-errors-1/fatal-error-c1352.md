---
title: "Erro fatal C1352 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C1352"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1352"
ms.assetid: d044e8b0-b6ef-4d57-8eb5-6254071be707
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1352
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

MSIL inválido ou corrompido na função 'function' do módulo 'arquivo'  
  
 Um. netmodule foi passado para o compilador, mas o compilador detectou danos no arquivo.  Peça à pessoa que produziu a. netmodule investigar.  
  
 O compilador não verifica arquivos. netmodule para todos os tipos de corrupção.  No entanto, ele, verifique todos os caminhos de controle em uma função contêm uma instrução return.  
  
 Para obter mais informações, consulte [arquivos. netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md).