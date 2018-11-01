---
title: _onexit, _onexit_m
ms.date: 11/04/2016
apiname:
- _onexit
- _onexit_m
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
ms.openlocfilehash: c190f777032904802f771bab9fc323ba305ff32e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50609593"
---
# <a name="onexit-onexitm"></a>_onexit, _onexit_m

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

**OnExit** retorna um ponteiro para a função se for bem-sucedido ou **nulo** se não houver nenhum espaço para armazenar o ponteiro de função.

## <a name="remarks"></a>Comentários

O **OnExit** função é passada para o endereço de uma função (*função*) a ser chamado quando o programa for encerrado normalmente. Chamadas sucessivas à **OnExit** criam um registro das funções que são executadas na ordem UEPS (último-no-primeiro a sair). As funções passadas para **OnExit** não pode receber parâmetros.

No caso de quando **OnExit** é chamado de dentro de uma DLL, rotinas registradas com **OnExit** descarregamento de execução em uma DLL após **DllMain** é chamado com DLL_PROCESS_DETACH.

**OnExit** é uma extensão da Microsoft. Para fins de portabilidade ANSI, use [atexit](atexit.md). O **onexit_m** versão da função é para uso de modo misto.

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
