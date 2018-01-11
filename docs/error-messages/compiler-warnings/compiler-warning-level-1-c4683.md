---
title: "Compilador (nível 1) de aviso C4683 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4683
dev_langs: C++
helpviewer_keywords: C4683
ms.assetid: e6e77364-dba1-46dd-ae1d-03da23070bce
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e0a8ca498a3c95a1b37229f6ac973cf74a8e28ff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4683"></a>Compilador C4683 de aviso (nível 1)
**'**   
 ***função* ': fonte de eventos possui um 'out'-parâmetro; tome cuidado ao capturar vários manipuladores de eventos**  
  
 Se mais de um coletor de eventos está escutando a uma fonte de evento de COM, o valor de um parâmetro de saída pode ser ignorado.  
  
 Lembre-se de que um vazamento de memória ocorrerá na seguinte situação:  
  
1.  Se um método tem um parâmetro de saída internamente alocada, por exemplo um BSTR *.  
  
2.  Se o evento tem mais de um manipulador (é um evento de multicast)  
  
 O motivo para o vazamento é que o parâmetro de saída será definido por mais de um manipulador, mas retornado para o site de chamada somente pelo último manipulador.  
  
 O exemplo a seguir gera C4683:  
  
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