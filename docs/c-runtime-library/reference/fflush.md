---
title: fflush
ms.date: 11/04/2016
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
helpviewer_keywords:
- streams, flushing
- flushing
- fflush function
ms.assetid: 8bbc753f-dc74-4e77-b563-74da2835e92b
ms.openlocfilehash: d03d20ee5024915d0ca4c5a21db4159e8c4f876a
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51329105"
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

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fflush** retorna 0 se o buffer foi liberado com êxito. O valor 0 também é retornado em casos em que o fluxo especificado não tem nenhum buffer ou está aberto para acesso somente leitura. Um valor de retorno **EOF** indica um erro.

> [!NOTE]
> Se **fflush** retorna **EOF**, dados podem ter sido perdidos devido a uma falha de gravação. Ao configurar um manipulador de erro crítico, ele é mais seguro desativar o buffer com o **setvbuf** função ou usar rotinas de e/s de nível inferior, como **Open**, **Close**, e **Write** em vez das funções de e/s de fluxo.

## <a name="remarks"></a>Comentários

O **fflush** função libera o fluxo *fluxo*. Se o fluxo foi aberto no modo de gravação ou se ele foi aberto no modo de atualização e a última operação foi uma gravação, o conteúdo do buffer de fluxo é gravado no arquivo subjacente ou o dispositivo e o buffer são descartados. Se o fluxo foi aberto no modo de leitura, ou se o fluxo não tem nenhum buffer, a chamada para **fflush** não tem nenhum efeito e nenhum buffer é mantido. Uma chamada para **fflush** anula o efeito de qualquer chamada anterior a **ungetc** para o fluxo. O fluxo permanecerá aberto após a chamada.

Se *stream* é **nulo**, o comportamento é o mesmo que uma chamada para **fflush** em cada fluxo aberto. Todos os fluxos abertos no modo de gravação e todos os fluxos abertos no modo de atualização em que a última operação foi uma gravação são liberados. A chamada não tem efeito em outros fluxos.

Normalmente, esses buffers são mantidos pelo sistema operacional, que determina o momento ideal para gravar os dados automaticamente no disco: quando um buffer estiver cheio, quando um fluxo for fechado ou quando um programa for encerrado normalmente sem fechar fluxos. O recurso de confirmar no disco da biblioteca em tempo de execução permite assegurar que dados críticos sejam gravados diretamente no disco em vez de em buffers do sistema operacional. Sem reescrever um programa existente, você pode habilitar esse recurso vinculando os arquivos de objeto do programa com COMMODE.OBJ. No arquivo executável resultante, chamadas para **flushall** gravam o conteúdo de todos os buffers no disco. Somente **flushall** e **fflush** são afetados por commode.

Para obter informações sobre como controlar o recurso de confirmação em disco, consulte [E/S de fluxo](../../c-runtime-library/stream-i-o.md), [fopen](fopen-wfopen.md) e [_fdopen](fdopen-wfdopen.md).

Essa função bloqueia o thread de chamada e, portanto, é thread-safe. Para obter uma versão sem bloqueio, consulte **fflush_nolock**.

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

```Input
This is a test
This is a test
```

```Output
Enter a sentence of four words with scanf: This is a test
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
