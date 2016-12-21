---
title: "_status87, _statusfp, _statusfp2 | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_statusfp2"
  - "_statusfp"
  - "_status87"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_statusfp2"
  - "_statusfp"
  - "statusfp2"
  - "_status87"
  - "status87"
  - "statusfp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "funções de ponto flutuante, obtendo palavra de status"
  - "números de ponto flutuante, palavra de status"
  - "Função status87"
  - "palavra de status, obtendo ponto flutuante"
  - "Função statusfp"
  - "Função _statusfp"
  - "Função _statusfp2"
  - "Função statusfp2"
  - "Função _status87"
  - "funções de ponto flutuante"
  - "palavra de status"
ms.assetid: 7ef963fa-b1fb-429d-94d6-fbf282ab7432
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _status87, _statusfp, _statusfp2
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém a palavra status de ponto flutuante.  
  
## Sintaxe  
  
```  
unsigned int _status87( void );  
unsigned int _statusfp( void );  
void _statusfp2(unsigned int *px86, unsigned int *pSSE2)  
```  
  
#### Parâmetros  
 `px86`  
 Esse endereço é preenchido com a palavra status para a unidade de ponto flutuante x87.  
  
 `pSSE2`  
 Esse endereço é preenchido com a palavra status para a unidade de ponto flutuante SSE2.  
  
## Valor de retorno  
 Para `_status87` e `_statusfp`, os bits no valor retornado indicam o status do ponto flutuante.  Consulte o arquivo de inclusão FLOAT.H para obter uma definição dos bits que são retornados por `_statusfp`.  Muitas funções da biblioteca de matemática alteram a palavras de status de ponto flutuante, com resultados imprevisíveis.  A otimização pode reorganizar, combinar, e eliminar operações de ponto flutuante ao redor de chamadas a `_status87`, a `_statusfp`, e as funções relacionadas.  Use a opção do compilador de [\/Od \(desabilitar\)](../../build/reference/od-disable-debug.md) ou a política de pragma de [fenv\_access](../../preprocessor/fenv-access.md) evitar as otimizações que reorganizam operações de ponto flutuante.  Os valores de retorno de `_clearfp` e de `_statusfp`, e também os parâmetros de retorno de `_statusfp2`, são mais confiáveis se menos operações de ponto flutuante são executadas entre estados conhecidos de palavras de status de ponto flutuante.  
  
## Comentários  
 A função `_statusfp` obtém a palavra de status do ponto flutuante.  A palavra status é uma combinação do status do processador de ponto flutuante e outras condições detectadas pelo manipulador de exceção do ponto flutuante, por exemplo, estouro e estouro negativo de pilha do ponto flutuante.  As exceções sem máscara são verificadas antes que o conteúdo da palavra status seja retornado.  Isso significa que o chamador é informado de exceções pendentes.  Nas plataformas x86, `_statusfp` retorna uma combinação do status do ponto flutuante do x87 e SSE2.  Em plataformas x64, o status retornado é baseado no estado MXCSR do SSE.  Em plataformas ARM, a função `_statusfp` retorna o status do registro FPSCR.  
  
 `_statusfp` é uma versão portátil independente de plataforma de `_status87`.  É idêntico a `_status87` em plataformas Intel \(x86\) e também é suportado pelas plataformas x64 e ARM.  Para garantir que o código de ponto flutuante seja portátil para todas as arquiteturas, use `_statusfp`.  Se você está definido somente as plataformas x86 como destino, você pode usar `_status87` ou `_statusfp`.  
  
 Recomendamos `_statusfp2` para os chip \(como Pentium IV\) que têm um processador x87 e SSE2 de ponto flutuante.  Para `_statusfp2`, os endereços são preenchidos usando a palavra de status de ponto flutuante para o processador de ponto flutuante x87 ou SSE2.  Para um chip que suporta os processadores x87 e SSE2 de ponto flutuante, EM\_AMBIGUOUS é definido para 1 se `_statusfp` ou `_controlfp` forem usados e a ação era ambígua porque podia se referir à palavra de status de ponto flutuante do x87 ou SSE2.  A função `_statusfp2` tem suporte somente nas plataformas x86.  
  
 Estas funções não são úteis para [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) ou a compilação de `/clr:pure` como Common Language Runtime \(CLR\) oferece suporte apenas a precisão de ponto flutuante padrão.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_status87`, `_statusfp`, `_statusfp2`|\<float.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
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
  
  **0x00000000 \= Status \- espaço livre**  
**Status \= 0x00000003 \- incorreto, estouro negativo**  
**Status \= 0x00080003 \- incorreto, estouro negativo, denormal**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_clear87, \_clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md)