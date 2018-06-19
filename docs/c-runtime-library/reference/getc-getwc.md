---
title: getc, getwc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- getwc
- getc
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
- _gettc
- getwc
- _gettchar
- getc
dev_langs:
- C++
helpviewer_keywords:
- characters, reading
- _gettc function
- getwchar function
- streams, reading characters from
- reading characters from streams
- getc function
- getwc function
- gettc function
ms.assetid: 354ef514-d0c7-404b-92f5-995f6a834bb3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9a4908e8fa3343bb54191fe2494f738ff0edf887
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32404325"
---
# <a name="getc-getwc"></a>getc, getwc

Lê um caractere de um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int getc(
   FILE *stream
);
wint_t getwc(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Fluxo de entrada.

## <a name="return-value"></a>Valor de retorno

Retorna o caractere lido. Para indicar um erro de leitura ou uma condição de fim de arquivo, **getc** retorna **EOF**, e **getwc** retorna **WEOF**. Para **getc**, use **ferror** ou **feof** para verificar se um erro ou para o final do arquivo. Se *fluxo* é **nulo**, **getc** e **getwc** invocar o manipulador de parâmetro inválido, conforme descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **EOF** (ou **WEOF** para **getwc**) e defina **errno** para  **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Cada rotina lê um único caractere de um arquivo na posição atual e incrementa o ponteiro de arquivo associado (se definido) para apontar para o caractere seguinte. O arquivo está associado *fluxo*.

Essas funções bloqueiam o thread de chamada e, portanto, são thread-safe. Para ver uma versão sem bloqueio, consulte [_getc_nolock, _getwc_nolock](getc-nolock-getwc-nolock.md).

Veja comentários específicos sobre a rotina a seguir.

|Rotina|Comentários|
|-------------|-------------|
|**getc**|Mesmo que **fgetc**, mas implementado como uma função e como uma macro.|
|**getwc**|Versão de caractere largo de **getc**. Lê um caractere multibyte ou um caractere largo de acordo com se *fluxo* é aberto em modo de texto ou binário.|

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**gettc**|**getc**|**getc**|**getwc**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**getc**|\<stdio.h>|
|**getwc**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getc.c
// Use getc to read a line from a file.

#include <stdio.h>

int main()
{
    char buffer[81];
    int i, ch;
    FILE* fp;

    // Read a single line from the file "crt_getc.txt".

    fopen_s(&fp, "crt_getc.txt", "r");
    if (!fp)
    {
       printf("Failed to open file crt_getc.txt.\n");
       exit(1);
    }

    for (i = 0; (i < 80) && ((ch = getc(fp)) != EOF)
                         && (ch != '\n'); i++)
    {
        buffer[i] = (char) ch;
    }

    // Terminate string with a null character
    buffer[i] = '\0';
    printf( "Input was: %s\n", buffer);

    fclose(fp);
}
```

### <a name="input-crtgetctxt"></a>Entrada: crt_getc.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Input was: Line one.
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgetc, fgetwc](fgetc-fgetwc.md)<br/>
[_getch, _getwch](getch-getwch.md)<br/>
[putc, putwc](putc-putwc.md)<br/>
[ungetc, ungetwc](ungetc-ungetwc.md)<br/>
