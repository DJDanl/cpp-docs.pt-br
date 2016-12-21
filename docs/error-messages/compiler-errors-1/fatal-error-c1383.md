---
title: "Erro fatal C1383 | Microsoft Docs"
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
  - "C1383"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1383"
ms.assetid: ca224d14-d687-4fd6-80c2-8b82f28924ea
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1383
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

opção de compilador \/GL é incompatível com a versão instalada do common language runtime  
  
 C1383 ocorre quando você estiver usando uma versão anterior do common language runtime com um compilador mais recente e, quando você compila com **\/clr** e **\/GL.**  
  
 Para resolver, não use **\/GL** com **\/clr** ou instale a versão do common language runtime fornecido com seu compilador.  
  
 Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) e [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md).