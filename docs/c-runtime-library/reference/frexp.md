---
title: frexp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- frexp
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
- frexp
- _frexpl
dev_langs:
- C++
helpviewer_keywords:
- _frexpl function
- mantissas, floating-point variables
- frexpl function
- exponent, floating-point numbers
- frexp function
- floating-point functions, mantissa and exponent
ms.assetid: 9b020f2e-3967-45ec-a6a8-d467a071aa55
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 02eab6e7912a69a6189568d9a5530ace88d8430b
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="frexp"></a>frexp
Obtém a mantissa e expoente de um número de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double frexp(  
   double x,  
   int *expptr   
);  
float frexp(  
   float x,  
   int * expptr  
);  // C++ only  
long double frexp(  
   long double x,  
   int * expptr  
);  // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
 `expptr`  
 Ponteiro para o expoente inteiro armazenado.  
  
## <a name="return-value"></a>Valor de retorno  
 `frexp` retorna a mantissa. Se `x` for 0, a função retornará 0 para a mantissa e para o expoente. Se `expptr` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função define `errno` como `EINVAL` e retorna 0.  
  
## <a name="remarks"></a>Comentários  
 O `frexp` função divide o valor de ponto flutuante (`x`) em um mantissa (`m`) e um expoente (`n`), de modo que o valor absoluto de `m` é maior que ou igual a 0,5 e menor que 1.0 e `x`  =  `m`* 2<sup>n</sup>. O expoente inteiro `n` é armazenado no local apontado por `expptr`.  
  
 C++ permite sobrecargas, de modo que você pode chamar sobrecargas de `frexp`. Em um programa C, `frexp` sempre usa um double e um inteiro e retorna um double.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`frexp`|\<math.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_frexp.c  
// This program calculates frexp( 16.4, &n )  
// then displays y and n.  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x, y;  
   int n;  
  
   x = 16.4;  
   y = frexp( x, &n );  
   printf( "frexp( %f, &n ) = %f, n = %d\n", x, y, n );  
}  
```  
  
```Output  
frexp( 16.400000, &n ) = 0.512500, n = 5  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldexp](../../c-runtime-library/reference/ldexp.md)   
 [modf, modff, modfl](../../c-runtime-library/reference/modf-modff-modfl.md)