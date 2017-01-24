---
title: "remainder, remainderf, remainderl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "remainderl"
  - "remainder"
  - "remainderf"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-math-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "remainderf"
  - "remainder"
  - "remainderl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "remainderf"
  - "remainderl"
  - "restante"
ms.assetid: 5f721fb3-8b78-4597-9bc0-ca9bcd1f1d0e
caps.latest.revision: 8
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# remainder, remainderf, remainderl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Computa o restante do quociente de dois valores de ponto flutuante, arredondado para o valor integral o mais próximo.  
  
## Sintaxe  
  
```  
double remainder(   
   double numer,  
   double denom  
);  
float remainder(   
   float numer,  
   float denom  
); /* C++ only */  
long double remainder(   
   long double numer,  
   long double denom  
); /* C++ only */  
float remainderf(   
   float numer,  
   float denom  
);  
long double remainderl(   
   long double numer,  
   long double denom  
);  
  
```  
  
#### Parâmetros  
 `numer`  
 O numerador.  
  
 `denom`  
 O denominador.  
  
## Valor de retorno  
 O restante de ponto flutuante de `x` \/ `y`.  Se o valor de `y` for 0,0, `remainder` retornará um NaN silencioso.  Para obter informações sobre a representação de um NaN quieto pela família `printf`, consulte [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
## Comentários  
 A função de `remainder` calcula o resto de ponto flutuante `r` de  `x`\/`y` de modo que `x` \= `n` \* `y` \+ `r`, onde `n` é o inteiro mais próximo valor na `x`\/`y` e é sempre que `n` mesmo &#124; `n` \- `x` \/ `y` &#124; \= 1\/2.  Quando `r` \= 0, `r` tenha o mesmo sinal de `x`.  
  
 Como o C\+\+ permite a sobrecarga, você pode chamar as sobrecargas de `remainder` que levam e retornam valores `float` ou `long double`.  Em um programa em C, `remainder` sempre obterá dois doubles e retornará um double.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`remainder`, `remainderf`, `remainderl`|\<math.h\>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```c  
// crt_remainder.c  
// This program displays a floating-point remainder.  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double w = -10.0, x = 3.0, z;  
  
   z = remainder(w, x);  
   printf("The remainder of %.2f / %.2f is %f\n", w, x, z);  
}  
```  
  
  **O restante de \-10,00\/3,00 é \-1,000000**   
## Equivalência do .NET Framework  
 [System::Math::IEEERemainder](https://msdn.microsoft.com/en-us/library/system.math.ieeeremainder.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldiv, lldiv](../Topic/ldiv,%20lldiv.md)   
 [imaxdiv](../../c-runtime-library/reference/imaxdiv.md)   
 [fmod, fmodf](../Topic/fmod,%20fmodf.md)   
 [remquo, remquof, remquol](../Topic/remquo,%20remquof,%20remquol.md)