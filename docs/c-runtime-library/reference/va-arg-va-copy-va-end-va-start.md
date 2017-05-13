---
title: va_arg, va_copy, va_end, va_start | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- va_arg
- va_end
- va_copy
- va_start
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
apitype: DLLExport
f1_keywords:
- va_arg
- va_start
- va_list
- va_alist
- va_dcl
- va_copy
- va_end
dev_langs:
- C++
helpviewer_keywords:
- variable argument lists, accessing
- va_start macro
- va_arg macro
- va_end macro
- arguments [C++], argument lists
- va_list macro
- va_dcl macro
- va_alist macro
- va_copy macro
ms.assetid: a700dbbd-bfe5-4077-87b6-3a07af74a907
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 1b8ddbc48b00a037ae20632f4cd396e8e0ff2722
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="vaarg-vacopy-vaend-vastart"></a>va_arg, va_copy, va_end, va_start
Acessa listas de argumentos variáveis.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
type va_arg(  
   va_list arg_ptr,  
   type   
);
void va_copy(  
   va_list dest,  
   va_list src  
); // (ISO C99 and later)  
void va_end(  
   va_list arg_ptr   
);  
void va_start(  
   va_list arg_ptr,  
   prev_param   
); // (ANSI C89 and later)  
void va_start(  
   arg_ptr   
);  // (deprecated Pre-ANSI C89 standardization version)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 Tipo de argumento a ser recuperado.  
  
 `arg_ptr`  
 Ponteiro para a lista de argumentos.  
  
 `dest`  
 Ponteiro para a lista de argumentos a ser inicializada de `src`  
  
 `src`  
 Ponteiro para a lista inicializada de argumentos a ser copiada para `dest`.  
  
 `prev_param`  
 Parâmetro que precede o primeiro argumento opcional.  
  
## <a name="return-value"></a>Valor de retorno  
 `va_arg` retorna o argumento atual. `va_copy`, `va_start` e `va_end` não retornam valores.  
  
## <a name="remarks"></a>Comentários  
 As macros `va_arg`, `va_copy`, `va_end` e `va_start` fornecem uma maneira portátil de acessar os argumentos de uma função quando ela aceita uma quantidade variável de argumentos. Há duas versões das macros: as macros definidas em STDARG.H estão em conformidade com a norma ISO C99; as macros definidas em VARARGS.H foram preteridas, mas são mantidas para fins de compatibilidade com código gravado antes da norma ANSI C89.  
  
 Essas macros pressupõem que a função usa um número fixo de argumentos necessários, seguido por um número variável de argumentos opcionais. Os argumentos necessários são declarados como parâmetros comuns para a função e podem ser acessados por meio dos nomes de parâmetro. Os argumentos opcionais são acessados por meio das macros em STDARG.H (ou VARARGS.H para código gravado antes da norma ANSI C89), que define um ponteiro para o primeiro argumento opcional na lista de argumentos, recupera os argumentos da lista e redefine o ponteiro quando o processamento do argumento é concluído.  
  
 As macros do padrão C, definidas em STDARG.H, são usadas da seguinte maneira:  
  
-   `va_start` define `arg_ptr` como o primeiro argumento opcional na lista de argumentos passada à função. O argumento `arg_ptr` deve ter o tipo `va_list`. O argumento `prev_param` é o nome do parâmetro necessário imediatamente anterior ao primeiro argumento opcional na lista de argumentos. Se `prev_param` for declarado com a classe de armazenamento do registro, comportamento da macro será indefinido. `va_start` deve ser usado antes de `va_arg` ser usado pela primeira vez.  
  
-   `va_arg` recupera um valor de `type` do local fornecido por `arg_ptr` e incrementa `arg_ptr` para apontar o próximo argumento da lista usando o tamanho de `type` para determinar o local em que o próximo argumento se inicia. `va_arg` pode ser usado várias vezes na função para recuperar argumentos da lista.  
  
-   `va_copy` faz uma cópia de uma lista de argumentos em seu estado atual. O parâmetro `src` já deve estar inicializado com `va_start`; ele pode ter sido atualizado com chamadas `va_arg`, mas não pode ter sido redefinido com `va_end`. O próximo argumento recuperado por `va_arg` de `dest` é o mesmo que o próximo argumento recuperado de `src`.  
  
-   Após a recuperação de todos os argumentos, `va_end` redefine o ponteiro para **NULO**. `va_end` deve ser chamado em cada lista de argumentos inicializada com `va_start` ou `va_copy` antes de retornar a função.  
  
> [!NOTE]
>  As macros em VARARGS.H foram preteridas e são mantidas somente para compatibilidade com versões anteriores do código gravado antes da norma ANSI C89 com. Em outros casos, use as macros em STDARGS.H.  
  
 Quando compilados com a [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md), os programas que utilizam essas macros podem gerar resultados inesperados por causa das diferenças entre sistemas do tipo nativo e Common Language Runtime (CLR). Considere este programa:  
  
```  
#include <stdio.h>  
#include <stdarg.h>  
  
void testit (int i, ...)  
{  
    va_list argptr;  
    va_start(argptr, i);  
  
    if (i == 0)  
    {  
        int n = va_arg(argptr, int);  
        printf("%d\n", n);  
    }  
    else  
    {  
        char *s = va_arg(argptr, char*);  
        printf("%s\n", s);  
    }  

    va_end(argptr);  
}  
  
int main()  
{  
    testit(0, 0xFFFFFFFF); // 1st problem: 0xffffffff is not an int  
    testit(1, NULL);       // 2nd problem: NULL is not a char*  
}  
```  
  
 Observe que `testit` espera que seu segundo parâmetro seja um `int` ou `char*`. Os argumentos passados são 0xffffffff (um `unsigned int` e não um `int`) e `NULL` (na verdade, um `int` e não um `char*`). Quando o programa é compilado para código nativo, ele produz esta saída:  
  
```Output  
-1  
  
(null)  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<stdio.h> e \<stdarg.h>  
  
 **Cabeçalho Preterido:** \<varargs.h>  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_va.c  
/* Compile with: cl /W3 /Tc crt_va.c  
 * The program below illustrates passing a variable  
 * number of arguments using the following macros:  
 *      va_start            va_arg              va_copy  
 *      va_end              va_list  
 */  
  
#include <stdio.h>  
#include <stdarg.h>  
#include <math.h>  
  
double deviation(int first, ...);  
  
int main( void )  
{  
    /* Call with 3 integers (-1 is used as terminator). */  
    printf("Deviation is: %f\n", deviation(2, 3, 4, -1 ));  
  
    /* Call with 4 integers. */  
    printf("Deviation is: %f\n", deviation(5, 7, 9, 11, -1));  
  
    /* Call with just -1 terminator. */  
    printf("Deviation is: %f\n", deviation(-1));  
}  
  
/* Returns the standard deviation of a variable list of integers. */  
double deviation(int first, ...)  
{  
    int count = 0, i = first;  
    double mean = 0.0, sum = 0.0;  
    va_list marker;  
    va_list copy;  
  
    va_start(marker, first);     /* Initialize variable arguments. */  
    va_copy(copy, marker);       /* Copy list for the second pass */  
    while (i != -1)  
    {  
        sum += i;  
        count++;  
        i = va_arg(marker, int);  
    }  
    va_end(marker);              /* Reset variable argument list. */  
    mean = sum ? (sum / count) : 0.0;  
  
    i = first;                  /* reset to calculate deviation */  
    sum = 0.0;  
    while (i != -1)  
    {  
        sum += (i - mean)*(i - mean);  
        i = va_arg(copy, int);  
    }  
    va_end(copy);               /* Reset copy of argument list. */  
    return count ? sqrt(sum / count) : 0.0;  
}  
  
```  
  
## <a name="output"></a>Saída  
  
```Output  
Deviation is: 0.816497  
Deviation is: 2.236068  
Deviation is: 0.000000  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso a argumento](../../c-runtime-library/argument-access.md)   
 [vfprintf, _vfprintf_l, vfwprintf, _vfwprintf_l](../../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)
