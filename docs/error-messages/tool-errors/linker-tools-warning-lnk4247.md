---
title: Aviso LNK4247 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4247
dev_langs: C++
helpviewer_keywords: LNK4247
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: fc0dc48befa5bc6b99fff7c3d76ebf9cd4b585b0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4247"></a>Aviso LNK4247 (Ferramentas de Vinculador)
ponto de entrada 'decorated_function_name' já tem um atributo de thread; 'attribute' ignorado  
  
 Um ponto de entrada especificado com [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md), tinha um atributo de thread, mas [/CLRTHREADATTRIBUTE (Definir Thread atributo CLR)](../../build/reference/clrthreadattribute-set-clr-thread-attribute.md) também foi especificado, com um modelo de threading diferente.  
  
 O vinculador ignorado o valor especificado com /CLRTHREADATTRIBUTE.  
  
 Para resolver este aviso:  
  
-   Remova /CLRTHREADATTRIBUTE de sua compilação.  
  
-   Remova o atributo do seu arquivo de código fonte.  
  
-   Remova os dois o atributo de origem e /CLRTHREADATTRIBUTE da sua compilação e aceitar o modelo de threading do CLR padrão.  
  
-   Altere o valor passado para /CLRTHREADATTRIBUTE, de modo que estão de acordo com o atributo de origem.  
  
-   Altere o atributo na fonte de modo que estão de acordo com o valor passado para /CLRTHREADATTRIBUTE.  
  
 O exemplo a seguir gera LNK4247  
  
```  
// LNK4247.cpp  
// compile with: /clr /c  
// post-build command: link /CLRTHREADATTRIBUTE:STA LNK4247.obj /entry:functionTitle /SUBSYSTEM:Console  
 [System::MTAThreadAttribute]  
void functionTitle (){}  
```