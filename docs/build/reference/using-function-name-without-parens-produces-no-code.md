---
title: "Usando o nome da função sem () não produz código | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: functions [C++], without parentheses
ms.assetid: edf4a177-a160-44aa-8436-e077b5b27809
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 79f360bffa4938098b4b37dd2260596c70669d12
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="using-function-name-without--produces-no-code"></a>O uso do nome de função sem () não produz código
Quando um nome de função declarado em seu programa for usado sem parênteses, o compilador não produz código. Isso ocorre independentemente de estarem ou não a função usa parâmetros porque o compilador calcula o endereço de função; No entanto, como o operador de chamada de função "()" não está presente, não é feita nenhuma chamada. Esse resultado é semelhante ao seguinte:  
  
```  
// compile with /Wall to generate a warning  
int a;  
a;      // no code generated here either  
```  
  
 No Visual C++, usar o mesmo nível de aviso 4 não gera nenhuma saída de diagnóstica. Nenhum aviso é emitido; Nenhum código será produzido.  
  
 O código de exemplo a seguir compila (com um aviso) e links corretamente sem erros, mas não produz código na referência a `funcn( )`. Para que isso funcione corretamente, adicione o operador de chamada de função "()".  
  
```  
#include <stdio.h>  
void funcn();  
  
int main() {  
   funcn;      /* missing function call operator;   
                  call will fail.  Use funcn() */  
   }  
  
void funcn() {  
   printf("\nHello World\n");  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Otimizando seu código](../../build/reference/optimizing-your-code.md)