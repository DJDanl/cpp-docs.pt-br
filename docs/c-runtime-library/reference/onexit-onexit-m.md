---
title: _onexit, _onexit_m
ms.date: 11/04/2016
api_name:
- _onexit
- _onexit_m
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
- _onexit
- onexit_m
- onexit
- _onexit_m
helpviewer_keywords:
- onexit function
- registry, registering exit routines
- _onexit_m function
- onexit_m function
- _onexit function
- registering exit routines
- registering to be called on exit
ms.assetid: 45743298-0e2f-46cf-966d-1ca44babb443
ms.openlocfilehash: 9afcd729f19f11b82e8f24c2b7fcf9ec40990deb
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951341"
---
# <a name="_onexit-_onexit_m"></a>_onexit, _onexit_m

Registra uma rotina a ser chamada na hora de saída.

## <a name="syntax"></a>Sintaxe

```C
_onexit_t _onexit(
   _onexit_t function
);
_onexit_t_m _onexit_m(
   _onexit_t_m function
);
```

### <a name="parameters"></a>Parâmetros

*function*<br/>
Ponteiro para uma função a ser chamada na saída.

## <a name="return-value"></a>Valor de retorno

**_onexit** retornará um ponteiro para a função se for bem-sucedido ou **nulo** se não houver espaço para armazenar o ponteiro de função.

## <a name="remarks"></a>Comentários

A função **_onexit** recebe o endereço de uma função (*função*) a ser chamada quando o programa é encerrado normalmente. Chamadas sucessivas para **_onexit** criar um registro de funções que são executadas na ordem UEPS (último a entrar, primeiro a sair). As funções passadas para **_onexit** não podem usar parâmetros.

No caso de **_onexit** ser chamado de dentro de uma dll, as rotinas registradas com **_onexit** são executadas no descarregamento de uma DLL depois que **DllMain** é chamado com DLL_PROCESS_DETACH.

**_onexit** é uma extensão da Microsoft. Para fins de portabilidade ANSI, use [atexit](atexit.md). A versão **_onexit_m** da função é para uso de modo misto.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_onexit**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_onexit.c

#include <stdlib.h>
#include <stdio.h>

/* Prototypes */
int fn1(void), fn2(void), fn3(void), fn4 (void);

int main( void )
{
   _onexit( fn1 );
   _onexit( fn2 );
   _onexit( fn3 );
   _onexit( fn4 );
   printf( "This is executed first.\n" );
}

int fn1()
{
   printf( "next.\n" );
   return 0;
}

int fn2()
{
   printf( "executed " );
   return 0;
}

int fn3()
{
   printf( "is " );
   return 0;
}

int fn4()
{
   printf( "This " );
   return 0;
}
```

### <a name="output"></a>Saída

```Output
This is executed first.
This is executed next.
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[atexit](atexit.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[__dllonexit](../../c-runtime-library/dllonexit.md)<br/>
