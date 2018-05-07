---
title: Compilador (nível 1) de aviso C4683 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4683
dev_langs:
- C++
helpviewer_keywords:
- C4683
ms.assetid: e6e77364-dba1-46dd-ae1d-03da23070bce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 418bf25d565c616d5bc4aaf58361c4f28df298ca
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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