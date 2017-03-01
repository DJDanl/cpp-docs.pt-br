---
title: "Compilador aviso (nível 1) C4683 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4683
dev_langs:
- C++
helpviewer_keywords:
- C4683
ms.assetid: e6e77364-dba1-46dd-ae1d-03da23070bce
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d26c44549540db2ae16269d107054d969b38fe4c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4683"></a>Compilador C4683 de aviso (nível 1)
**'**   
 ***função* ': origem do evento tem um 'out'-parâmetro; tenha cuidado ao conectar vários manipuladores de eventos**  
  
 Se mais de um coletor de eventos está escutando em uma fonte de evento COM, o valor de um parâmetro de saída pode ser ignorado.  
  
 Lembre-se de que um vazamento de memória ocorra na seguinte situação:  
  
1.  Se um método tem um parâmetro de saída internamente alocada, por exemplo um BSTR *.  
  
2.  Se o evento tiver mais de um manipulador (é um evento multicast)  
  
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
