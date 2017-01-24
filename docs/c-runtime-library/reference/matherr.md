---
title: "_matherr | Microsoft Docs"
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
  - "_matherr"
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
  - "_matherr"
  - "matherr"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _matherr"
  - "Função matherr"
ms.assetid: b600d66e-165a-4608-a856-8fb418d46760
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _matherr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Trata erros de matemática.  
  
## Sintaxe  
  
```  
  
      int _matherr(  
   struct _exception *except   
);  
```  
  
#### Parâmetros  
 *exceto*  
 Ponteiro para a estrutura que contém informações de erro.  
  
## Valor de retorno  
 o \_**matherr** retorna 0 para indicar um erro ou um valor diferente de zero para indicar êxito.  Se o \_**matherr** retorna 0, uma mensagem de erro poderá ser exibida e `errno` é definido como um valor de erro adequado.  Se o \_**matherr** retorna um valor diferente de zero, nenhuma mensagem de erro será exibida e `errno` permanecerá inalterado.  
  
 Para obter mais informações sobre códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Os erros de processos da função de**matherr** \_gerados pela funções de ponto flutuante da biblioteca de matemática.  \_**matherr** inicial de controle esses quando um erro é detectado.  
  
 Para o tratamento de erro especial, você pode fornecer uma definição diferente \_**matherr**.  Se você usar a versão dinamicamente vinculada da biblioteca de tempo de execução C \(Msvcr90.dll\), você pode substituir a rotina padrão de**matherr** \_em um executável do cliente com uma versão definido pelo usuário.  No entanto, não é possível substituir a rotina padrão de `_matherr` em um cliente de DLL de Msvcr90.dll.  
  
 Quando ocorre um erro em uma rotina de matemática, \_**matherr** é chamado com um ponteiro para uma estrutura de tipo de **\_exception** \(definida em Math.h\) como um argumento.  A estrutura de **\_exception** contém os seguintes elementos.  
  
 **int type**  
 Tipo de exceção.  
  
 **char \*name**  
 Nome da função no qual ocorreu o erro.  
  
 **double arg1**, **arg2**  
 Primeiro e segundo \(se houver\) argumentos para a função.  
  
 **double retval**  
 Valor a ser retornado pela função.  
  
 **type** especifica o tipo de erro matemática.  É um dos valores a seguir, definido em Math.h.  
  
 `_DOMAIN`  
 Erro de domínio de argumentos.  
  
 `_SING`  
 Singularidade de argumentos.  
  
 `_OVERFLOW`  
 Erro de intervalo de estouro.  
  
 `_PLOSS`  
 Perda de significância parcial.  
  
 `_TLOSS`  
 Perda de significado geral.  
  
 `_UNDERFLOW`  
 O resultado é muito pequeno para ser representado. \(Essa condição não tem suporte no momento.\)  
  
 O membro da estrutura **name** é um ponteiro para uma cadeia de caracteres com terminação nula que contém o nome da função que provocou o erro.  Os membros da estrutura **arg1** e **arg2** especificam os valores que provocou o erro. \(Apenas se um argumento for fornecido, é armazenado em **arg1**.\)  
  
 O valor de retorno padrão para o determinado erro é **retval**.  Se você alterar o valor de retorno, deve especificar se realmente ocorreu um erro.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_matherr`|\<math.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_matherr.c  
/* illustrates writing an error routine for math   
 * functions. The error function must be:  
 *      _matherr  
 */  
  
#include <math.h>  
#include <string.h>  
#include <stdio.h>  
  
int main()  
{  
    /* Do several math operations that cause errors. The _matherr  
     * routine handles _DOMAIN errors, but lets the system handle  
     * other errors normally.  
     */  
    printf( "log( -2.0 ) = %e\n", log( -2.0 ) );  
    printf( "log10( -5.0 ) = %e\n", log10( -5.0 ) );  
    printf( "log( 0.0 ) = %e\n", log( 0.0 ) );  
}  
  
/* Handle several math errors caused by passing a negative argument  
 * to log or log10 (_DOMAIN errors). When this happens, _matherr  
 * returns the natural or base-10 logarithm of the absolute value  
 * of the argument and suppresses the usual error message.  
 */  
int _matherr( struct _exception *except )  
{  
    /* Handle _DOMAIN errors for log or log10. */  
    if( except->type == _DOMAIN )  
    {  
        if( strcmp( except->name, "log" ) == 0 )  
        {  
            except->retval = log( -(except->arg1) );  
            printf( "Special: using absolute value: %s: _DOMAIN "  
                     "error\n", except->name );  
            return 1;  
        }  
        else if( strcmp( except->name, "log10" ) == 0 )  
        {  
            except->retval = log10( -(except->arg1) );  
            printf( "Special: using absolute value: %s: _DOMAIN "  
                     "error\n", except->name );  
            return 1;  
        }  
    }  
    printf( "Normal: " );  
    return 0;    /* Else use the default actions */  
}  
```  
  
## Saída  
  
```  
Special: using absolute value: log: _DOMAIN error  
log( -2.0 ) = 6.931472e-001  
Special: using absolute value: log10: _DOMAIN error  
log10( -5.0 ) = 6.989700e-001  
Normal: log( 0.0 ) = -1.#INF00e+000  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Duplo longo](../../misc/long-double.md)