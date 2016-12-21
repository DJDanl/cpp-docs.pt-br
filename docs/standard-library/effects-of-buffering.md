---
title: "Efeitos do buffer | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "buffers, efeitos do buffer"
  - "armazenamento em buffer, efeitos de"
ms.assetid: 5d544812-e95e-4f28-b15a-edef3f3414fd
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Efeitos do buffer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo a seguir mostra os efeitos do buffer. Você pode esperar o programa para imprimir `please wait`, aguarde 5 segundos e, em seguida, continuar. Ele não necessariamente funcionará dessa forma, no entanto, porque a saída é armazenada em buffer.  
  
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
  
 Para fazer com que o programa funcione logicamente, o `cout` objeto deve esvaziar próprio quando a mensagem é exibida. Para liberar uma `ostream` de objeto, enviá\-lo a `flush` manipulador:  
  
```  
cout << "Please wait..." << flush;  
```  
  
 Esta etapa libera o buffer, garantindo que imprime a mensagem antes do tempo de espera. Você também pode usar o `endl` manipulador, que libera o buffer e gera uma retorno de carro e alimentação de linha, ou você pode usar o `cin` objeto. Esse objeto \(com o `cerr` ou `clog` objetos\) geralmente é vinculado ao `cout` objeto. Assim, qualquer uso de `cin` \(ou a `cerr` ou `clog` objetos\) libera o `cout` objeto.  
  
## Consulte também  
 [Fluxos de Saída](../standard-library/output-streams.md)