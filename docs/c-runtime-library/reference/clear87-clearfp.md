---
title: _clear87, _clearfp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _clearfp
- _clear87
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- clearfp
- _clearfp
- _clear87
- clear87
dev_langs:
- C++
helpviewer_keywords:
- clearing floating point status word
- clearfp function
- _clear87 function
- _clearfp function
- clear87 function
ms.assetid: 72d24a70-7688-4793-ae09-c96d33fcca52
caps.latest.revision: 17
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
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 7c7659bb52594678538ea2701174c070ace41d70
ms.lasthandoff: 02/25/2017

---
# <a name="clear87-clearfp"></a>_clear87, _clearfp
Obtém e limpa a palavra de status de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned int _clear87( void );  
unsigned int _clearfp( void );  
```  
  
## <a name="return-value"></a>Valor retornado  
 Os bits no valor retornado indicam o status do ponto flutuante antes da chamada para `_clear87` ou `_clearfp`. Para obter uma definição completa dos bits retornados por `_clear87`, consulte Float.h. Muitas das funções de biblioteca de matemática modificam a palavra de status 8087/80287, com resultados imprevisíveis. Valores de retorno de `_clear87` e `_status87` tornam-se mais confiáveis conforme menos operações de ponto flutuantes são executadas entre estados conhecidos da palavra de status de ponto flutuante.  
  
## <a name="remarks"></a>Comentários  
 A função `_clear87` limpa os sinalizadores de exceção na palavra de status de ponto flutuante, define o bit ocupado como 0 e retorna a palavra de status. A palavra de status de ponto flutuante é uma combinação da palavra de status 8087/80287 e outras condições detectadas pelo manipulador de exceção 8087/80287, como estouro e estouro negativo de pilha de ponto flutuante.  
  
 `_clearfp` é uma versão portátil independente de plataforma da rotina `_clear87`. É idêntico a `_clear87` em plataformas Intel (x86) e também tem suporte nas plataformas x64 e ARM. Para garantir que seu código de ponto flutuante seja portátil para x64 e ARM, use `_clearfp`. Se você tiver apenas plataformas x86 como destino, poderá usar `_clear87` ou `_clearfp`.  
  
 Essas funções são substituídas durante a compilação com [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime suporta apenas a precisão de ponto flutuante padrão.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_clear87`|\<float.h>|  
|`_clearfp`|\<float.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_clear87.c  
// compile with: /Od  
  
// This program creates various floating-point   
// problems, then uses _clear87 to report on these problems.  
// Compile this program with Optimizations disabled (/Od).   
// Otherwise the optimizer will remove the code associated with   
// the unused floating-point values.  
//  
  
#include <stdio.h>  
#include <float.h>  
  
int main( void )  
{  
   double a = 1e-40, b;  
   float x, y;  
  
   printf( "Status: %.4x - clear\n", _clear87()  );  
  
   // Store into y is inexact and underflows:  
   y = a;  
   printf( "Status: %.4x - inexact, underflow\n", _clear87() );  
  
   // y is denormal:   
   b = y;  
   printf( "Status: %.4x - denormal\n", _clear87() );  
}  
```  
  
```Output  
Status: 0000 - clear  
Status: 0003 - inexact, underflow  
Status: 80000 - denormal  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md)   
 [_status87, _statusfp, _statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)
