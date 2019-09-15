---
title: _matherr
ms.date: 04/05/2018
api_name:
- _matherr
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _matherr
- matherr
helpviewer_keywords:
- _matherr function
- matherr function
ms.assetid: b600d66e-165a-4608-a856-8fb418d46760
ms.openlocfilehash: 340e3b8562e1f0f564810bc63cf6bd2e87ffdf63
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952767"
---
# <a name="_matherr"></a>_matherr

Manipula erros matemáticos.

## <a name="syntax"></a>Sintaxe

```C
int _matherr( struct _exception * except );
```

### <a name="parameters"></a>Parâmetros

*except*<br/>
Ponteiro para a estrutura que contém informações de erro.

## <a name="return-value"></a>Valor de retorno

**_matherr** retorna 0 para indicar um erro ou um valor diferente de zero para indicar êxito. Se **_matherr** retornar 0, uma mensagem de erro poderá ser exibida e **errno** será definido como um valor de erro apropriado. Se **_matherr** retornar um valor diferente de zero, nenhuma mensagem de erro será exibida e **errno** permanecerá inalterado.

Para obter mais informações sobre esses códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_matherr** processa erros gerados pelas funções de ponto flutuante da biblioteca de matemática. Essas funções chamam **_matherr** quando um erro é detectado.

Para tratamento de erro especial, você pode fornecer uma definição diferente de **_matherr**. Se você usar a versão vinculada dinamicamente da biblioteca de tempo de execução do C (CRT), poderá substituir a rotina **_matherr** padrão em um executável de cliente por uma versão definida pelo usuário. No entanto, você não pode substituir a rotina **_matherr** padrão em um cliente DLL da dll do CRT.

Quando ocorre um erro em uma rotina matemática, **_matherr** é chamado com um ponteiro para uma estrutura de tipo **_exception** (definida \<em Math. h >) como um argumento. A estrutura **_exception** contém os seguintes elementos.

```C
struct _exception
{
    int    type;   // exception type - see below
    char*  name;   // name of function where error occurred
    double arg1;   // first argument to function
    double arg2;   // second argument (if any) to function
    double retval; // value to be returned by function
};
```

O membro de **tipo** especifica o tipo de erro matemático. É um dos seguintes valores, definidos em \<Math. h >:

|Macro|Significado|
|-|-|
| **_DOMAIN** | Erro de domínio de argumento |
| **_SING** | Singularidade de argumento |
| **_OVERFLOW** | Erro de intervalo de estouro |
| **_PLOSS** | Perda parcial de significância |
| **_TLOSS** | Perda total de significância |
| **_UNDERFLOW** | O resultado é muito pequeno para ser representado. (Não há suporte para essa condição no momento.) |

O membro da estrutura **name** é um ponteiro de uma cadeia de caracteres terminada com caractere nulo, que contém o nome da função que causou o erro. Os membros da estrutura **arg1** e **arg2** especificam os valores que causaram o erro. Se apenas um argumento for fornecido, ele será armazenado em **arg1**.

O valor retornado padrão para o erro especificado é **retval**. Se você alterar o valor retornado, ele deverá especificar se realmente ocorreu um erro.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_matherr**|\<math.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

```Output
Special: using absolute value: log: _DOMAIN error
log( -2.0 ) = 6.931472e-01
Special: using absolute value: log10: _DOMAIN error
log10( -5.0 ) = 6.989700e-01
Normal: log( 0.0 ) = -inf
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
