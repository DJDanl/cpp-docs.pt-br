---
title: atexit
ms.date: 11/04/2016
apiname:
- atexit
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
- atexit
helpviewer_keywords:
- processing, at exit
- atexit function
ms.assetid: 92c156d2-8052-4e58-96dc-00128baac6f9
ms.openlocfilehash: 48f0fbfa1f3350f73899fcdbb3bf7922f1c6174d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62341581"
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

**atexit** retorna 0 se for bem-sucedido ou um valor diferente de zero se ocorrer um erro.

## <a name="remarks"></a>Comentários

O **atexit** função é passada para o endereço de uma função *func* a ser chamado quando o programa for encerrado normalmente. Chamadas sucessivas à **atexit** criam um registro das funções que são executadas no último a entrar, primeiro a sair (UEPS) ordem. As funções passadas para **atexit** não pode receber parâmetros. **atexit** e **OnExit** usam o heap para conter o registro das funções. Assim, o número de funções que podem ser registradas é limitado apenas pela memória de heap.

O código a **atexit** função não deve conter nenhuma dependência de nenhuma DLL que poderia já ter sido descarregada quando o **atexit** função é chamada.

Para gerar um aplicativo compatível com ANSI, use o padrão ANSI **atexit** função (em vez de semelhantes **OnExit** função).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**atexit**|\<stdlib.h>|

## <a name="example"></a>Exemplo

Esse programa envia quatro funções para a pilha de funções seja executado quando **atexit** é chamado. Quando o programa é encerrado, esses programas são executados no esquema último a entrar, primeiro a sair.

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
