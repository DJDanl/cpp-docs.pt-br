---
title: _status87, _statusfp, _statusfp2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _statusfp2
- _statusfp
- _status87
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
- _statusfp2
- _statusfp
- statusfp2
- _status87
- status87
- statusfp
dev_langs:
- C++
helpviewer_keywords:
- floating-point functions, getting status word
- floating-point numbers, status word
- status87 function
- status word, getting floating point
- statusfp function
- _statusfp function
- _statusfp2 function
- statusfp2 function
- _status87 function
- floating-point functions
- status word
ms.assetid: 7ef963fa-b1fb-429d-94d6-fbf282ab7432
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 69a19aaa457ffc52c431a9ca1c3597a475a10994
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="status87-statusfp-statusfp2"></a>_status87, _statusfp, _statusfp2
Obtém a palavra de status de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned int _status87( void );  
unsigned int _statusfp( void );  
void _statusfp2(unsigned int *px86, unsigned int *pSSE2)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `px86`  
 Esse endereço é preenchido com a palavra de status para a unidade de ponto flutuante x87.  
  
 `pSSE2`  
 Esse endereço é preenchido com a palavra de status para a unidade de ponto flutuante SSE2.  
  
## <a name="return-value"></a>Valor de retorno  
 Para `_status87` e `_statusfp`, os bits no valor retornado indicam o status de ponto flutuante. Consulte o arquivo FLOAT.H incluído para obter uma definição dos bits retornados por `_statusfp`. Muitas funções de biblioteca de matemática modificam a palavra de status de ponto flutuante, com resultados imprevisíveis. A otimização pode reordenar, combinar e eliminar as operações de ponto flutuante em torno das chamadas para `_status87`, `_statusfp` e funções relacionadas. Use a opção do compilador [/Od (Desabilitar (Depurar))](../../build/reference/od-disable-debug.md) ou a diretiva pragma [fenv_access](../../preprocessor/fenv-access.md) para impedir otimizações que reordenem as operações de ponto flutuante. Valores retornados de `_clearfp` e `_statusfp` e também os parâmetros de retorno de `_statusfp2` serão mais confiáveis se houver menos operações de ponto flutuantes entre estados conhecidos da palavra de status de ponto flutuante.  
  
## <a name="remarks"></a>Comentários  
 A função `_statusfp` obtém a palavra de status de ponto flutuante. A palavra de status é uma combinação do status do processador de ponto flutuante e outras condições detectadas pelo manipulador de exceção de ponto flutuante – por exemplo, estouro positivo e negativo de pilha de ponto flutuante. Exceções sem máscara são verificadas antes de o conteúdo da palavra de status ser retornado. Isso significa que o chamador é informado sobre exceções pendentes. Em plataformas x86, `_statusfp` retorna uma combinação dos status de ponto flutuante SSE2 e x87. Em plataformas x64, o status retornado é baseado no status MXCSR do SSE. Em plataformas ARM, `_statusfp` retorna o status do registro FPSCR.  
  
 `_statusfp` é uma versão portátil e independente de plataforma de `_status87`. É idêntico a `_status87` em plataformas Intel (x86) e também tem suporte nas plataformas x64 e ARM. Para garantir que seu código de ponto flutuante seja portátil para todas as arquiteturas, use `_statusfp`. Se você tiver apenas plataformas x86 como destino, poderá usar `_status87` ou `_statusfp`.  
  
 Recomendamos `_statusfp2` para chips (como Pentium IV) que têm um ambos um processador de ponto flutuante x87 e um SSE2. Para `_statusfp2`, os endereços são preenchidos pelo uso da palavra de status de ponto flutuante tanto para o processador de ponto flutuante x87 quanto para o SSE2. Para um chip que dá suporte a processadores de ponto flutuante x87 e SSE2, EM_AMBIGUOUS é definido como 1 se `_statusfp` ou `_controlfp` é usado e a ação foi ambígua porque ela poderia se referir à palavra de status do ponto flutuante SSE2 ou x87. Só há suporte para a função `_statusfp2` em plataformas x86.  
  
 Essas funções não são úteis para [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime (CLR) suporta apenas a precisão de ponto flutuante padrão.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_status87`, `_statusfp`, `_statusfp2`|\<float.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_statusfp.c  
// Build by using: cl /W4 /Ox /nologo crt_statusfp.c  
// This program creates various floating-point errors and  
// then uses _statusfp to display messages that indicate these problems.  
  
#include <stdio.h>  
#include <float.h>  
#pragma fenv_access(on)  
  
double test( void )  
{  
   double a = 1e-40;  
   float b;  
   double c;  
  
   printf("Status = 0x%.8x - clear\n", _statusfp());  
  
   // Assignment into b is inexact & underflows:   
   b = (float)(a + 1e-40);  
   printf("Status = 0x%.8x - inexact, underflow\n", _statusfp());  
  
   // c is denormal:   
   c = b / 2.0;   
   printf("Status = 0x%.8x - inexact, underflow, denormal\n",   
            _statusfp());  
  
   // Clear floating point status:   
   _clearfp();  
   return c;  
}  
  
int main(void)  
{  
   return (int)test();  
}  
```  
  
```Output  
Status = 0x00000000 - clear  
Status = 0x00000003 - inexact, underflow  
Status = 0x00080003 - inexact, underflow, denormal  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_clear87, _clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md)
