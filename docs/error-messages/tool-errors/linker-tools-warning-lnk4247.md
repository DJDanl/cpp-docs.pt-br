---
title: Aviso LNK4247 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4247
dev_langs:
- C++
helpviewer_keywords:
- LNK4247
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6096bbfba9c60d8ed28aa660d078cd155f0316a3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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