---
title: "va_arg, va_copy, va_end, va_start | Microsoft Docs"
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
  - "va_arg"
  - "va_end"
  - "va_copy"
  - "va_start"
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
apitype: "DLLExport"
f1_keywords: 
  - "va_arg"
  - "va_start"
  - "va_list"
  - "va_alist"
  - "va_dcl"
  - "va_copy"
  - "va_end"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "listas de argumentos variáveis, acessando"
  - "Macro va_start"
  - "Macro va_arg"
  - "Macro va_end"
  - "listas de argumentos de argumentos [C++]"
  - "Macro va_list"
  - "Macro va_dcl"
  - "Macro va_alist"
  - "Macro va_copy"
ms.assetid: a700dbbd-bfe5-4077-87b6-3a07af74a907
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# va_arg, va_copy, va_end, va_start
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Listas de argumentos de variável de acessos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      type va_arg(  
   va_list arg_ptr,  
   type   
);void va_copy(  
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
);  // (Pre-ANSI C89 standardization version)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 Tipo de argumento a ser recuperado.  
  
 `arg_ptr`  
 Ponteiro para a lista de argumentos.  
  
 `dest`  
 Ponteiro para a lista de argumentos para inicializar a partir de `src`  
  
 `src`  
 Ponteiro para a lista inicializado de argumentos para copiar `dest`.  
  
 `prev_param`  
 Parâmetro que precede o primeiro argumento opcional.  
  
## <a name="return-value"></a>Valor de retorno  
 `va_arg` Retorna o argumento atual. `va_copy`, `va_start` e `va_end` não retornam valores.  
  
## <a name="remarks"></a>Comentários  
 O `va_arg`, `va_copy`, `va_end`, e `va_start` macros fornecem uma maneira portátil para acessar os argumentos para uma função quando a função aceita um número variável de argumentos. Há duas versões das macros: as macros definidas em STDARG. H está de acordo com o ISO C99 padrão; as macros definidas em VARARGS. H são substituídos, mas são mantidos para fins de compatibilidade com código escrito antes do C89 ANSI padrão.  
  
 Essas macros pressupõem que a função usa um número fixo de argumentos necessários, seguido por um número variável de argumentos opcionais. Os argumentos necessários são declarados como parâmetros comuns para a função e podem ser acessados através de nomes de parâmetro. Os argumentos opcionais são acessados por meio de macros em STDARG. H (ou VARARGS. H para código escrito antes do padrão ANSI C89), que define um ponteiro para o primeiro argumento opcional na lista de argumentos, recupera os argumentos da lista e redefine o ponteiro quando o argumento processamento é concluído.  
  
 C padrão macros, definidas em STDARG. H, são usadas da seguinte maneira:  
  
-   `va_start` define `arg_ptr` para o primeiro argumento opcional na lista de argumentos passado para a função. O argumento `arg_ptr` deve ter o `va_list` tipo. O argumento `prev_param` é o nome do parâmetro obrigatório que precede o primeiro argumento opcional na lista de argumentos. Se `prev_param` é declarado com a classe de armazenamento do registro, comportamento da macro será indefinido. `va_start` deve ser usado antes de `va_arg` é usada pela primeira vez.  
  
-   `va_arg` recupera um valor de `type` do local que é fornecido por `arg_ptr`, e incrementos `arg_ptr` para apontar para o próximo argumento na lista usando o tamanho de `type` para determinar onde começa o próximo argumento. `va_arg` pode ser usado várias vezes na função para recuperar argumentos da lista.  
  
-   `va_copy` faz uma cópia de uma lista de argumentos em seu estado atual. O `src` parâmetro já deve ser inicializado com `va_start`; pode ter sido atualizado com `va_arg` chama, mas não deve ter sido redefinido com `va_end`. O próximo argumento que é recuperado por `va_arg` de `dest` é o mesmo que o próximo argumento que é recuperado de `src`.  
  
-   Depois que todos os argumentos forem recuperados, `va_end` redefine o ponteiro para **NULO**. `va_end` deve ser chamado em cada lista de argumentos é inicializada com `va_start` ou `va_copy` antes da função retorna.  
  
> [!NOTE]
>  As macros em VARARGS. H foram preteridos e são mantidos somente para compatibilidade com o código que foi gravado antes do padrão ANSI C89 com versões anteriores. Em outros casos, use as macros em STDARGS. H.  
  
 Quando eles são compilados usando [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md), programas que usam essas macros podem gerar resultados inesperados devido às diferenças entre sistemas de tipo nativo e do common language runtime (CLR). Considere este programa:  
  
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
}  
  
int main()  
{  
    testit(0, 0xFFFFFFFF); // 1st problem: 0xffffffff is not an int  
    testit(1, NULL);       // 2nd problem: NULL is not a char*  
}  
```  
  
 Observe que `testit` espera que seu segundo parâmetro seja um `int` ou um `char*`. Os argumentos sendo passados são 0xffffffff (um `unsigned int`, e não um `int`) e `NULL` (na verdade, um `int`, e não um `char*`). Quando o programa é compilado para código nativo, ele produz esta saída:  
  
```Output  
-1  
  
(null)  
```  
  
 No entanto, quando o programa é compilado usando **/clr: puro**, a incompatibilidade de tipo de fazê-lo gerar uma exceção. A solução é usar conversões:  
  
```  
int main()  
{  
   testit( 0, (int)0xFFFFFFFF ); // cast unsigned to int  
   testit( 1, (char*)NULL );     // cast int to char*  
}  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< stdio > e \< stdarg. h >  
  
 **Cabeçalho preterido:** \< varargs >  
  
## <a name="libraries"></a>Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [Classe System::ParamArrayAttribute](https://msdn.microsoft.com/en-us/library/system.paramarrayattribute.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Acesso a argumento](../../c-runtime-library/argument-access.md)   
 [vfprintf, vfprintf_l, vfwprintf, vfwprintf_l](../../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)