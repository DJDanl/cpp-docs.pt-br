---
title: "Aviso do compilador (n&#237;vel 1) C4683 | Microsoft Docs"
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
  - "C4683"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4683"
ms.assetid: e6e77364-dba1-46dd-ae1d-03da23070bce
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4683
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**'**   
 ***function* ': event source has an 'out'\-parameter; exercise caution when hooking multiple event handlers**  
  
 Se mais de um coletor de eventos está escutando a COM uma origem de evento, o valor de um parâmetro de saída pode ser ignorado.  
  
 Observe que um vazamento de memória ocorrerá na situação seguinte:  
  
1.  Se um método possui um parâmetro de saída que é atribuído internamente por exemplo, um BSTR \*.  
  
2.  Se o evento tem mais de um manipulador \(é um evento multicast\)  
  
 A razão para o escape é que o parâmetro de saída será definido por mais de um manipulador, mas retornado para o site de chamada somente pelo manipulador a última vez.  
  
 O seguinte exemplo gera C4683:  
  
```  
// C4683.cpp  
// compile with: /W1 /LD  
#define _ATL_ATTRIBUTES 1  
#include "atlbase.h"  
#include "atlcom.h"  
  
[ module(name="xx") ];  
  
[ object ]  
__interface I {  
   HRESULT f([out] int* pi);  
   // try the following line instead  
   // HRESULT f(int* pi);  
};  
  
[ coclass, event_source(com) ]  
struct E {  
   __event __interface I;   // C4683  
};  
```