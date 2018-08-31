---
title: va_arg, va_copy, va_end, va_start | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c33c8dbfe55008c084daf8f6b9f4700f13281012
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43195423"
---
# <a name="vaarg-vacopy-vaend-vastart"></a>va_arg, va_copy, va_end, va_start

Acessa listas de argumentos variáveis.

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*type*<br/>
Tipo de argumento a ser recuperado.

*arg_ptr*<br/>
Ponteiro para a lista de argumentos.

*dest*<br/>
Ponteiro para a lista de argumentos a ser inicializado no *src*

*src*<br/>
Ponteiro para a lista inicializada de argumentos para copiar *dest*.

*prev_param*<br/>
Parâmetro que precede o primeiro argumento opcional.

## <a name="return-value"></a>Valor de retorno

**va_arg** retorna o argumento atual. **va_copy**, **va_start** e **va_end** não retornam valores.

## <a name="remarks"></a>Comentários

O **va_arg**, **va_copy**, **va_end**, e **va_start** macros fornecem uma maneira portátil para acessar os argumentos para uma função quando o função usa um número variável de argumentos. Há duas versões das macros: as macros definidas em STDARG.H estão em conformidade com a norma ISO C99; as macros definidas em VARARGS.H foram preteridas, mas são mantidas para fins de compatibilidade com código gravado antes da norma ANSI C89.

Essas macros pressupõem que a função usa um número fixo de argumentos necessários, seguido por um número variável de argumentos opcionais. Os argumentos necessários são declarados como parâmetros comuns para a função e podem ser acessados por meio dos nomes de parâmetro. Os argumentos opcionais são acessados por meio das macros em STDARG.H (ou VARARGS.H para código gravado antes da norma ANSI C89), que define um ponteiro para o primeiro argumento opcional na lista de argumentos, recupera os argumentos da lista e redefine o ponteiro quando o processamento do argumento é concluído.

As macros do padrão C, definidas em STDARG.H, são usadas da seguinte maneira:

- **va_start** define *arg_ptr* para o primeiro argumento opcional na lista de argumentos que é passado para a função. O argumento *arg_ptr* deve ter o **va_list** tipo. O argumento *prev_param* é o nome do parâmetro necessário que precede imediatamente o primeiro argumento opcional na lista de argumentos. Se *prev_param* é declarado com a classe de armazenamento de registro, o comportamento da macro será indefinido. **va_start** devem ser usados antes **va_arg** é usado pela primeira vez.

- **va_arg** recupera um valor de *tipo* partir do local fornecido por *arg_ptr*e incrementos *arg_ptr* para apontar para o próximo argumento na lista por usando o tamanho de *tipo* para determinar onde começa o próximo argumento. **va_arg** pode ser usado qualquer número de vezes na função para recuperar argumentos da lista.

- **va_copy** faz uma cópia de uma lista de argumentos em seu estado atual. O *src* já deve estar inicializado com o parâmetro **va_start**; ele foi atualizado com **va_arg** chama, mas não deve ter sido redefinido com **va_end** . O próximo argumento que é recuperado por **va_arg** partir *dest* é o mesmo que o próximo argumento recuperado do *src*.

- Depois que todos os argumentos forem recuperados, **va_end** redefine o ponteiro para **nulo**. **va_end** deve ser chamado em cada lista de argumentos é inicializada com **va_start** ou **va_copy** antes que a função retorna.

> [!NOTE]
> As macros em VARARGS.H foram preteridas e são mantidas somente para compatibilidade com versões anteriores do código gravado antes da norma ANSI C89 com. Em outros casos, use as macros em STDARGS.H.

Quando compilados com a [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md), os programas que utilizam essas macros podem gerar resultados inesperados por causa das diferenças entre sistemas do tipo nativo e Common Language Runtime (CLR). Considere este programa:

```C
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

Observe que **testit** espera que seu segundo parâmetro seja uma **int** ou uma **char**<strong>\*</strong>. Os argumentos sendo passados são 0xffffffff (um **sem sinal** **int**, e não um **int**) e **nulo** (na verdade, um **int**, e não uma **char**<strong>\*</strong>). Quando o programa é compilado para código nativo, ele produz esta saída:

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

```C
// crt_va.c
// Compile with: cl /W3 /Tc crt_va.c
// The program below illustrates passing a variable
// number of arguments using the following macros:
//      va_start            va_arg              va_copy
//      va_end              va_list

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

```Output
Deviation is: 0.816497
Deviation is: 2.236068
Deviation is: 0.000000
```

## <a name="see-also"></a>Consulte também

[Acesso a argumento](../../c-runtime-library/argument-access.md)<br/>
[vfprintf, _vfprintf_l, vfwprintf, _vfwprintf_l](vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)<br/>
