---
title: Efeitos do buffer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- buffers, effects of buffering
- buffering, effects of
ms.assetid: 5d544812-e95e-4f28-b15a-edef3f3414fd
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d888b6d16e0a71168e0615d89bbd1d03c51afad8
ms.lasthandoff: 02/25/2017

---
# <a name="effects-of-buffering"></a>Efeitos do buffer
O exemplo a seguir mostra os efeitos do buffer. Você pode esperar o programa imprimir `please wait`, aguardar 5 segundos e, em seguida, continuar. No entanto, ele não necessariamente funcionará dessa forma porque a saída é armazenada em buffer.  
  
```  
// effects_buffering.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <time.h>  
using namespace std;  
  
int main( )  
{  
   time_t tm = time( NULL ) + 5;  
   cout << "Please wait...";  
   while ( time( NULL ) < tm )  
      ;  
   cout << "\nAll done" << endl;  
}  
```  
  
 Para fazer com que o programa funcione logicamente, o objeto `cout` deve se esvaziar quando a mensagem for exibida. Para liberar um objeto `ostream`, envie-o ao manipulador `flush`:  
  
```  
cout <<"Please wait..." <<flush;  
```  
  
 Esta etapa libera o buffer, garantindo que a mensagem seja impressa antes da espera. Você também pode usar o manipulador `endl`, que libera o buffer e gera um retorno de carro–avanço de linha ou você pode usar o objeto `cin`. Esse objeto (com os objetos `cerr` ou `clog`) geralmente é vinculado ao objeto `cout`. Assim, qualquer uso de `cin` (ou dos objetos `cerr` ou `clog`) libera o objeto `cout`.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de saída](../standard-library/output-streams.md)


