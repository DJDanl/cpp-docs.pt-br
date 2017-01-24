---
title: "Aviso do compilador (n&#237;vel 1) C4581 | Microsoft Docs"
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
  - "C4581"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4581"
ms.assetid: 598bcd87-257d-4eb3-94e4-15bb31aadc99
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4581
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

comportamento preterido: ““string1”” substituído com “string2” para processar o atributo  
  
 Esse erro pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: parâmetro que verifica os atributos do Visual C\+\+.  
  
 Em versões anteriores, os valores de atributo são aceitos se foram incluídos entre aspas.  Se o valor for uma enumeração, não deverá ser colocado entre aspas.  
  
## Exemplo  
 O exemplo a seguir produz C4581.  
  
```  
// C4581.cpp  
// compile with: /c /W1  
#include "unknwn.h"  
[object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IMyI : IUnknown {};  
  
[coclass, uuid(12345678-1111-2222-3333-123456789012), threading("free")]   // C4581  
// try the following line instead  
// [coclass, uuid(12345678-1111-2222-3333-123456789012), threading(free)]  
class CSample : public IMyI {};  
```