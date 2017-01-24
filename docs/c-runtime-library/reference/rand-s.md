---
title: "rand_s | Microsoft Docs"
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
  - "rand_s"
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
  - "api-ms-win-crt-utility-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "rand_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "números aleatórios criptograficamente seguros"
  - "gerando números pseudoaleatórios"
  - "números, gerando pseudoaleatórios"
  - "números, pseudoaleatórios"
  - "números pseudoaleatórios"
  - "Função rand_s"
  - "números aleatórios, criptograficamente seguros"
  - "números aleatórios, gerando"
ms.assetid: d6a0be60-997d-4904-8411-8aea6839cc94
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# rand_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencie um número pseudoaleatório.  Uma versão de [rand](../Topic/rand.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t rand_s(   unsigned int* randomValue);  
```  
  
## Valor de retorno  
 Zero se bem\-sucedido, caso contrário, um código de erro.  Se o ponteiro `randomValue` de entrada for um ponteiro nulo, a função invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função retornará `EINVAL` e definirá `errno` como `EINVAL`.  Se a função falhar por qualquer outro motivo, \*`randomValue` será definido como 0.  
  
## Comentários  
 A função de `rand_s` pseudoaleatório grava um inteiro no intervalo de 0 a `UINT_MAX` ao ponteiro de entrada.  A função de `rand_s` usa o sistema operacional para gerar números aleatórios criptograficamente seguros.  Não usa a semente gerada pela função de [srand](../../c-runtime-library/reference/srand.md) , nem afeta a sequência de números aleatórios usada por `rand`.  
  
 A função de `rand_s` requer que `_CRT_RAND_S` constante seja definido antes da instrução de inclusão para que a função seja declarada, como no exemplo a seguir:  
  
```  
#define _CRT_RAND_S  
#include <stdlib.h>  
```  
  
 `rand_s` depende de [RtlGenRandom](http://msdn.microsoft.com/library/windows/desktop/aa387694) API, disponível somente no Windows XP e posterior.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`rand_s`|\<stdlib.h\>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_rand_s.c  
// This program illustrates how to generate random  
// integer or floating point numbers in a specified range.  
  
// Remembering to define _CRT_RAND_S prior  
// to inclusion statement.  
#define _CRT_RAND_S  
  
#include <stdlib.h>  
#include <stdio.h>  
#include <limits.h>  
  
int main( void )  
{  
    int             i;  
    unsigned int    number;  
    double          max = 100.0;  
    errno_t         err;  
  
    // Display 10 random integers in the range [ 1,10 ].  
    for( i = 0; i < 10;i++ )  
    {  
        err = rand_s( &number );  
        if (err != 0)  
        {  
            printf_s("The rand_s function failed!\n");  
        }  
        printf_s( "  %u\n", (unsigned int) ((double)number /  
                       ((double) UINT_MAX + 1 ) * 10.0) + 1);  
    }  
  
    printf_s("\n");  
  
    // Display 10 random doubles in [0, max).  
    for (i = 0; i < 10;i++ )  
    {  
        err = rand_s( &number );  
        if (err != 0)  
        {  
            printf_s("The rand_s function failed!\n");  
        }  
        printf_s( "  %g\n", (double) number /   
                          ((double) UINT_MAX + 1) * max );  
    }  
}  
```  
  
## Saída de Exemplo  
  
```  
10  
4  
5  
2  
8  
2  
5  
6  
1  
1  
  
32.6617  
29.4471  
11.5413  
6.41924  
20.711  
60.2878  
61.0094  
20.1222  
80.9192  
65.0712  
```  
  
## Equivalência do .NET Framework  
 [Classe de System::Random](https://msdn.microsoft.com/en-us/library/system.random.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [srand](../../c-runtime-library/reference/srand.md)