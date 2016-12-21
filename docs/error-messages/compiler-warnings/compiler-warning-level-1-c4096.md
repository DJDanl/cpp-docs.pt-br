---
title: "Aviso do compilador (n&#237;vel 1) C4096 | Microsoft Docs"
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
  - "C4096"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4096"
ms.assetid: abf3cca2-2f21-45d8-b025-6b513b00681e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4096
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“a”: a interface não é uma interface COM; não será emitido a IDL  
  
 Uma definição de interface que você possa ter planejado como uma interface COM não foi definida como uma interface COM e em virtude disso não será emitida para o arquivo de IDL.  
  
 Consulte [Atributos de interface](../../windows/interface-attributes.md) para os atributos de uma lista que indicam que uma interface é uma interface COM.  
  
 O seguinte exemplo gera C4096:  
  
```  
// C4096.cpp  
// compile with: /W1 /LD  
#include "windows.h"  
[module(name="xx")];  
  
// [object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface a  
{  
};  
  
[coclass, uuid("00000000-0000-0000-0000-000000000002")]  
struct b : a  
{  
};   // C4096, remove coclass or uncomment object  
```