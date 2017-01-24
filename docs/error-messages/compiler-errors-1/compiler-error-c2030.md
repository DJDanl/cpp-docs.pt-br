---
title: "Erro do Compilador C2030 | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2030"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2030"
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2030
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

um destruidor com acessibilidade 'privada protegida' não pode ser membro de uma classe declarada 'lacrada'  
  
 Uma classe de tempo de execução do Windows declarados como `sealed` não pode ter um destruidor privado protegido.  Públicos destruidores não virtual privados e virtuais são permitidos somente em tipos lacrados.  Para obter mais informações, consulte [Classes e estruturas ref](../Topic/Ref%20classes%20and%20structs%20\(C++-CX\).md).  
  
 Para corrigir esse erro, altere a acessibilidade do destruidor.