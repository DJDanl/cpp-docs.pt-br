---
title: fflush
ms.date: 4/2/2020
api_name:
- fflush
- _o_fflush
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fflush
helpviewer_keywords:
- streams, flushing
- flushing
- fflush function
ms.assetid: 8bbc753f-dc74-4e77-b563-74da2835e92b
ms.openlocfilehash: c5208c86484e1d9478f3879d91b32d57ba7c4a3a
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82912894"
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

## <a name="return-value"></a>Valor retornado

**fflush** retornará 0 se o buffer tiver sido liberado com êxito. O valor 0 também é retornado em casos em que o fluxo especificado não tem nenhum buffer ou está aberto para acesso somente leitura. Um valor de retorno de **EOF** indica um erro.

> [!NOTE]
> Se **fflush** retornar **EOF**, os dados poderão ter sido perdidos devido a uma falha de gravação. Ao configurar um manipulador de erro crítico, é mais seguro ativar o buffer com a função **setvbuf** ou usar rotinas de e/s de nível baixo, como **_open**, **_close**e **_write** em vez das funções de e/s de fluxo.

## <a name="remarks"></a>Comentários

A função **fflush** libera o *fluxo*de fluxo. Se o fluxo foi aberto no modo de gravação ou se ele foi aberto no modo de atualização e a última operação foi uma gravação, o conteúdo do buffer de fluxo é gravado no arquivo subjacente ou o dispositivo e o buffer são descartados. Se o fluxo tiver sido aberto no modo de leitura ou se o fluxo não tiver buffer, a chamada para **fflush** não terá efeito e qualquer buffer será retido. Uma chamada para **fflush** nega o efeito de qualquer chamada anterior ao **ungetc** para o fluxo. O fluxo permanecerá aberto após a chamada.

Se o *fluxo* for **nulo**, o comportamento será o mesmo que uma chamada para **fflush** em cada fluxo aberto. Todos os fluxos abertos no modo de gravação e todos os fluxos abertos no modo de atualização em que a última operação foi uma gravação são liberados. A chamada não tem efeito em outros fluxos.

Normalmente, esses buffers são mantidos pelo sistema operacional, que determina o momento ideal para gravar os dados automaticamente no disco: quando um buffer estiver cheio, quando um fluxo for fechado ou quando um programa for encerrado normalmente sem fechar fluxos. O recurso de confirmar no disco da biblioteca em tempo de execução permite assegurar que dados críticos sejam gravados diretamente no disco em vez de em buffers do sistema operacional. Sem reescrever um programa existente, você pode habilitar esse recurso vinculando os arquivos de objeto do programa com COMMODE.OBJ. No arquivo executável resultante, as chamadas para **_flushall** gravam o conteúdo de todos os buffers em disco. Somente **_flushall** e **fflush** são afetados por COMMODE. obj.

Para obter informações sobre como controlar o recurso de confirmação em disco, consulte [E/S de fluxo](../../c-runtime-library/stream-i-o.md), [fopen](fopen-wfopen.md) e [_fdopen](fdopen-wfdopen.md).

Essa função bloqueia o thread de chamada e, portanto, é thread-safe. Para uma versão sem bloqueio, consulte **_fflush_nolock**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fflush**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fflush.c
// Compile with: cl /W4 crt_fflush.c
// This sample gets a number from the user, then writes it to a file.
// It ensures the write isn't lost on crash by calling fflush.
#include <stdio.h>

int * crash_the_program = 0;

int main(void)
{
    FILE * my_file;
    errno_t err = fopen_s(&my_file, "myfile.txt", "w");
    if (my_file && !err)
    {
        printf("Write a number: ");

        int my_number = 0;
        scanf_s("%d", &my_number);

        fprintf(my_file, "User selected %d\n", my_number);

        // Write data to a file immediately instead of buffering.
        fflush(my_file);

        if (my_number == 5)
        {
            // Without using fflush, no data was written to the file
            // prior to the crash, so the data is lost.
            *crash_the_program = 5;
        }

        // Normally, fflush is not needed as closing the file will write the buffer.
        // Note that files are automatically closed and flushed during normal termination.
        fclose(my_file);
    }
    return 0;
}
```

```Input
5
```

```myfile.txt
User selected 5
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_flushall](flushall.md)<br/>
[setvbuf](setvbuf.md)<br/>
