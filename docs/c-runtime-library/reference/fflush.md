---
title: fflush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- fflush
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- fflush
dev_langs:
- C++
helpviewer_keywords:
- streams, flushing
- flushing
- fflush function
ms.assetid: 8bbc753f-dc74-4e77-b563-74da2835e92b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 72f0812e713d0d474363dcc5f79cc11eddb46020
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32401159"
---
# <a name="fflush"></a>fflush

Libera um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int fflush(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fflush** retorna 0 se o buffer foi liberado com êxito. O valor 0 também é retornado em casos em que o fluxo especificado não tem nenhum buffer ou está aberto para acesso somente leitura. Um valor de retorno **EOF** indica um erro.

> [!NOTE]
> Se **fflush** retorna **EOF**, dados podem ter sido perdidos devido a uma falha de gravação. Ao configurar um manipulador de erro crítico, é mais seguro desativar o buffer com o **setvbuf** função ou usar rotinas de e/s de baixo nível como **abrir**, **echar**, e **Write** em vez de funções de fluxo de e/s.

## <a name="remarks"></a>Comentários

O **fflush** função libera o fluxo *fluxo*. Se o fluxo foi aberto no modo de gravação ou se ele foi aberto no modo de atualização e a última operação foi uma gravação, o conteúdo do buffer de fluxo é gravado no arquivo subjacente ou o dispositivo e o buffer são descartados. Se o fluxo foi aberto no modo de leitura, ou se o fluxo não tem nenhum buffer, a chamada para **fflush** não tem nenhum efeito e qualquer buffer é mantido. Uma chamada para **fflush** nega o efeito de qualquer chamada anterior para **ungetc** para o fluxo. O fluxo permanecerá aberto após a chamada.

Se *fluxo* é **nulo**, o comportamento é o mesmo que uma chamada para **fflush** em cada fluxo aberto. Todos os fluxos abertos no modo de gravação e todos os fluxos abertos no modo de atualização em que a última operação foi uma gravação são liberados. A chamada não tem efeito em outros fluxos.

Normalmente, esses buffers são mantidos pelo sistema operacional, que determina o momento ideal para gravar os dados automaticamente no disco: quando um buffer estiver cheio, quando um fluxo for fechado ou quando um programa for encerrado normalmente sem fechar fluxos. O recurso de confirmar no disco da biblioteca em tempo de execução permite assegurar que dados críticos sejam gravados diretamente no disco em vez de em buffers do sistema operacional. Sem reescrever um programa existente, você pode habilitar esse recurso vinculando os arquivos de objeto do programa com COMMODE.OBJ. No arquivo executável resultante, chamadas para **flushall** gravar o conteúdo de todos os buffers para o disco. Somente **flushall** e **fflush** são afetados por COMMODE.OBJ.

Para obter informações sobre como controlar o recurso de confirmação em disco, consulte [E/S de fluxo](../../c-runtime-library/stream-i-o.md), [fopen](fopen-wfopen.md) e [_fdopen](fdopen-wfdopen.md).

Essa função bloqueia o thread de chamada e, portanto, é thread-safe. Para obter uma versão de não bloqueio, consulte **fflush_nolock**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fflush**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fflush.c
#include <stdio.h>
#include <conio.h>

int main( void )
{
   int integer;
   char string[81];

   // Read each word as a string.
   printf( "Enter a sentence of four words with scanf: " );
   for( integer = 0; integer < 4; integer++ )
   {
      scanf_s( "%s", string, sizeof(string) );
      printf( "%s\n", string );
   }

   // You must flush the input buffer before using gets.
   // fflush on input stream is an extension to the C standard
   fflush( stdin );
   printf( "Enter the same sentence with gets: " );
   gets_s( string, sizeof(string) );
   printf( "%s\n", string );
}
```

```Output

      This is a test
This is a test

```

```Output

      This is a test
This is a testEnter a sentence of four words with scanf: This is a test
This
is
a
test
Enter the same sentence with gets: This is a test
This is a test
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_flushall](flushall.md)<br/>
[setvbuf](setvbuf.md)<br/>
