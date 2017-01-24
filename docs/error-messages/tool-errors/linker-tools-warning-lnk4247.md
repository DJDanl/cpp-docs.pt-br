---
title: "Aviso LNK4247 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4247"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4247"
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4247 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o ponto de entrada “decorated\_function\_name” já tiver um atributo de thread; “atributo” ignorado  
  
 Um ponto de entrada, especificado com [\/ENTRY \(símbolo do ponto de entrada\)](../../build/reference/entry-entry-point-symbol.md), tinha um atributo de threading, mas [\/CLRTHREADATTRIBUTE \(definir atributo de thread CLR\)](../../build/reference/clrthreadattribute-set-clr-thread-attribute.md) também foi especificado, com o modelo de threading diferente.  
  
 O vinculador ignorado o valor especificado com a \/CLRTHREADATTRIBUTE.  
  
 Para resolver esse aviso:  
  
-   Remover \/CLRTHREADATTRIBUTE de sua compilação.  
  
-   Remover o atributo do arquivo de origem.  
  
-   Remover o atributo de origem e \/CLRTHREADATTRIBUTE da construção, e aceite o modelo de threading padrão de CLR.  
  
-   Alterar o valor passado para \/CLRTHREADATTRIBUTE, de modo que, concorde com o atributo na origem.  
  
-   Alterar o atributo na origem, de modo que, concordar com o valor passado para a \/CLRTHREADATTRIBUTE.  
  
 O exemplo LNK4247 gerencia  
  
```  
// LNK4247.cpp  
// compile with: /clr /c  
// post-build command: link /CLRTHREADATTRIBUTE:STA LNK4247.obj /entry:functionTitle /SUBSYSTEM:Console  
 [System::MTAThreadAttribute]  
void functionTitle (){}  
```