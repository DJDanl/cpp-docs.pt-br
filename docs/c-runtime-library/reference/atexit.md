---
title: atexit
ms.date: 11/04/2016
api_name:
- atexit
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
- atexit
helpviewer_keywords:
- processing, at exit
- atexit function
ms.assetid: 92c156d2-8052-4e58-96dc-00128baac6f9
ms.openlocfilehash: b91e6dad81f006b0b94ac17a940e840386f6d2b1
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939654"
---
# <a name="atexit"></a>atexit

Processa a função especificada na saída.

## <a name="syntax"></a>Sintaxe

```C
int atexit(
   void (__cdecl *func )( void )
);
```

### <a name="parameters"></a>Parâmetros

*func*<br/>
Função a ser chamada.

## <a name="return-value"></a>Valor de retorno

**atexit** retornará 0 se for bem-sucedido ou um valor diferente de zero se ocorrer um erro.

## <a name="remarks"></a>Comentários

A função **atexit** é passada para o endereço de uma função *Func* a ser chamada quando o programa é encerrado normalmente. Chamadas sucessivas para **atexit** criam um registro de funções que são executadas na ordem de UEPS (último a entrar, primeiro a sair). As funções passadas para **atexit** não podem usar parâmetros. **atexit** e **_onexit** usam o heap para manter o registro de funções. Assim, o número de funções que podem ser registradas é limitado apenas pela memória de heap.

O código na função **atexit** não deve conter nenhuma dependência em qualquer DLL que já possa ter sido descarregada quando a função **atexit** for chamada.

Para gerar um aplicativo em conformidade com ANSI, use a função **atexit** padrão ANSI (em vez da função **_onexit** semelhante).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**atexit**|\<stdlib.h>|

## <a name="example"></a>Exemplo

Esse programa envia quatro funções para a pilha de funções a serem executadas quando **atexit** é chamado. Quando o programa é encerrado, esses programas são executados no esquema último a entrar, primeiro a sair.

```C
// crt_atexit.c
#include <stdlib.h>
#include <stdio.h>

void fn1( void ), fn2( void ), fn3( void ), fn4( void );

int main( void )
{
   atexit( fn1 );
   atexit( fn2 );
   atexit( fn3 );
   atexit( fn4 );
   printf( "This is executed first.\n" );
}

void fn1()
{
   printf( "next.\n" );
}

void fn2()
{
   printf( "executed " );
}

void fn3()
{
   printf( "is " );
}

void fn4()
{
   printf( "This " );
}
```

```Output
This is executed first.
This is executed next.
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
