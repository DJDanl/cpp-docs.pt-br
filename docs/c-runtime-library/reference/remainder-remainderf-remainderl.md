---
title: remainder, remainderf, remainderl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- remainderl
- remainder
- remainderf
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- remainderf
- remainder
- remainderl
dev_langs: C++
helpviewer_keywords:
- remainderf
- remainderl
- remainder
ms.assetid: 5f721fb3-8b78-4597-9bc0-ca9bcd1f1d0e
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a0da3e4a6e785b73ebf2bfb8a529581d52dcfe2d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="remainder-remainderf-remainderl"></a>remainder, remainderf, remainderl
Calcula o restante do quociente de dois valores de ponto flutuantes, arredondados para o valor integral mais próximo.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `numer`  
 O numerador.  
  
 `denom`  
 O denominador.  
  
## <a name="return-value"></a>Valor de retorno  
 O restante do ponto flutuante de `x` / `y`. Se o valor de `y` for 0,0, `remainder` retornará um NaN silencioso. Para obter informações sobre representação de um NaN silencioso pela família `printf`, consulte [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
## <a name="remarks"></a>Comentários  
 A função `remainder` calcula o restante do ponto flutuante `r` de `x` / `y` que `x` = `n` * `y` + `r`, em que `n` é o inteiro mais próximo em valor a `x` / `y` e `n` é o mesmo sempre que &#124; `n` - `x` / `y` &#124; = 1/2. Quando `r` = 0, `r` tem o mesmo sinal que `x`.  
  
 Como C++ permite sobrecargas, é possível chamar sobrecargas de `remainder` e que utilizam e retornam valores de `float` ou `long double`. Em um programa C, `remainder` sempre usa dois duplos e retorna um duplo.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`remainder`, `remainderf`, `remainderl`|\<math.h>|  
  
 Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```C  
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
  
```Output  
The remainder of -10.00 / 3.00 is -1.000000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldiv, lldiv](../../c-runtime-library/reference/ldiv-lldiv.md)   
 [imaxdiv](../../c-runtime-library/reference/imaxdiv.md)   
 [fmod, fmodf](../../c-runtime-library/reference/fmod-fmodf.md)   
 [remquo, remquof, remquol](../../c-runtime-library/reference/remquo-remquof-remquol.md)