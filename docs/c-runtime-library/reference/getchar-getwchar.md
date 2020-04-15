---
title: getchar, getwchar
ms.date: 4/2/2020
api_name:
- getchar
- getwchar
- _o_getchar
- _o_getwchar
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- getwchar
- GetChar
helpviewer_keywords:
- gettchar function
- characters, reading
- getwchar function
- _gettchar function
- standard input, reading from
ms.assetid: 19fda588-3e33-415c-bb60-dd73c028086a
ms.openlocfilehash: 4311b5b896a5a406ebe14f09e7bb525cb47951b9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344620"
---
# <a name="getchar-getwchar"></a>getchar, getwchar

Lê um caractere da entrada padrão.

## <a name="syntax"></a>Sintaxe

```C
int getchar();
wint_t getwchar();
```

## <a name="return-value"></a>Valor retornado

Retorna o caractere lido. Para indicar um erro de leitura ou condição de fim de arquivo, **getchar** retorna **EOF**e **getwchar** retorna **WEOF**. Para **getchar,** use **ferror** ou **feof** para verificar se há um erro ou para o fim do arquivo.

## <a name="remarks"></a>Comentários

Cada rotina lê um único caractere de **stdin** e incrementa o ponteiro de arquivo associado para apontar para o próximo caractere. **getchar** é o mesmo [que _fgetchar,](fgetc-fgetwc.md)mas é implementado como uma função e como uma macro.

Essas funções bloqueiam o thread de chamada e, portanto, são thread-safe. Para ver uma versão sem bloqueio, consulte [_getchar_nolock, _getwchar_nolock](getchar-nolock-getwchar-nolock.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_gettchar**|**Getchar**|**Getchar**|**getwchar**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Getchar**|\<stdio.h>|
|**getwchar**|\<stdio.h> ou \<wchar.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console, **stdin**, **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getchar.c
// Use getchar to read a line from stdin.

#include <stdio.h>

int main()
{
    char buffer[81];
    int i, ch;

    for (i = 0; (i < 80) && ((ch = getchar()) != EOF)
                         && (ch != '\n'); i++)
    {
        buffer[i] = (char) ch;
    }

    // Terminate string with a null character
    buffer[i] = '\0';
    printf( "Input was: %s\n", buffer);
}
```

```Output

This textInput was: This text
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
[fgetc, fgetwc](fgetc-fgetwc.md)<br/>
[_getch, _getwch](getch-getwch.md)<br/>
[putc, putwc](putc-putwc.md)<br/>
[ungetc, ungetwc](ungetc-ungetwc.md)<br/>
