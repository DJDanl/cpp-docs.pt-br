---
title: _matherr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _matherr
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
- _matherr
- matherr
dev_langs: C++
helpviewer_keywords:
- _matherr function
- matherr function
ms.assetid: b600d66e-165a-4608-a856-8fb418d46760
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b1c7aa22479630605279b0d1364317d479bd1eac
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="matherr"></a>_matherr
Manipula erros matemáticos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int _matherr(  
   struct _exception *except   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *except*  
 Ponteiro para a estrutura que contém informações de erro.  
  
## <a name="return-value"></a>Valor de retorno  
 _**matherr** retorna 0 para indicar um erro ou um valor diferente de zero para indicar êxito. Se \_ **matherr** retornar 0, uma mensagem de erro poderá ser exibida e `errno` será definido como um valor de erro apropriado. Se \_ **matherr** retornar um valor diferente de zero, nenhuma mensagem de erro será exibida e `errno` permanecerá inalterado.  
  
 Para obter mais informações sobre esses códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função _**matherr** processa erros gerados pelas funções de ponto flutuante da biblioteca de matemática. Essas funções chamam \_ **matherr** quando um erro é detectado.  
  
 Para o tratamento de erro especial, você pode fornecer uma definição diferente de _**matherr**. Se usar a versão dinamicamente vinculada da biblioteca em tempo de execução de C (Msvcr90.dll), você poderá substituir a rotina padrão \_ **matherr** em um cliente executável por uma versão definida pelo usuário. No entanto, você não pode substituir a rotina padrão `_matherr` em um cliente DLL de Msvcr90.dll.  
  
 Quando ocorre um erro em uma rotina de matemática, _**matherr** é chamado com um ponteiro para uma estrutura de tipo **_exception** (definida em Math.h) como um argumento. A estrutura **_exception** contém os seguintes elementos.  
  
 **int type**  
 Tipo de exceção.  
  
 **char \*name**  
 Nome da função na qual o erro ocorreu.  
  
 **double arg1**, **arg2**  
 O primeiro e o segundo argumento (se houver) da função.  
  
 **double retval**  
 O valor a ser retornado pela função.  
  
 O elemento **type** especifica o tipo de erro matemático. É um dos valores a seguir, definidos em Math.h.  
  
 `_DOMAIN`  
 Erro de domínio do argumento.  
  
 `_SING`  
 Singularidade do argumento.  
  
 `_OVERFLOW`  
 Erro de intervalo de estouro.  
  
 `_PLOSS`  
 Perda parcial de significância.  
  
 `_TLOSS`  
 Perda total de significância.  
  
 `_UNDERFLOW`  
 O resultado é muito pequeno para ser representado. (Não há suporte para essa condição no momento.)  
  
 O membro da estrutura **name** é um ponteiro de uma cadeia de caracteres terminada com caractere nulo, que contém o nome da função que causou o erro. Os membros da estrutura **arg1** e **arg2** especificam os valores que causaram o erro. (Se apenas um argumento for dado, ele será armazenado em **arg1**.)  
  
 O valor retornado padrão para o erro especificado é **retval**. Se você alterar o valor retornado, ele deverá especificar se realmente ocorreu um erro.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_matherr`|\<math.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="output"></a>Saída  
  
```  
Special: using absolute value: log: _DOMAIN error  
log( -2.0 ) = 6.931472e-001  
Special: using absolute value: log10: _DOMAIN error  
log10( -5.0 ) = 6.989700e-001  
Normal: log( 0.0 ) = -1.#INF00e+000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   