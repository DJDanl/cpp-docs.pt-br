---
title: fgets, fgetws
ms.date: 07/11/2018
apiname:
- fgets
- fgetws
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
- _fgetts
- fgetws
- fgets
helpviewer_keywords:
- _fgetts function
- streams, getting strings from
- streams, reading from
- fgets function
- fgetws function
- fgetts function
ms.assetid: ad549bb5-df98-4ccd-a53f-95114e60c4fc
ms.openlocfilehash: 16dfb7cb0401083960669a735a976fbcd4ad4081
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50489554"
---
# <a name="fgets-fgetws"></a>fgets, fgetws

Obter uma cadeia de caracteres de um fluxo.

## <a name="syntax"></a>Sintaxe

```C
char *fgets(
   char *str,
   int numChars,
   FILE *stream
);
wchar_t *fgetws(
   wchar_t *str,
   int numChars,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Local de armazenamento de dados.

*numChars*<br/>
O número máximo de caracteres a serem lidos.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna *str*. **NULO** é retornado para indicar um erro ou uma condição de fim-de-arquivo. Use **feof** ou **ferror** para determinar se ocorreu um erro. Se *str* ou *fluxo* é um ponteiro nulo, ou *numChars* é menor que ou igual a zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e a função retornará **nulo**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

O **fgets** função lê uma cadeia de caracteres de entrada *fluxo* argumento e o armazena na *str*. **fgets** lê caracteres da posição atual do fluxo para e incluindo o primeiro caractere de nova linha ao final do fluxo, ou até que o número de caracteres lidos é igual a *numChars* - 1, o que vier primeiro. O resultado armazenado em *str* é acrescentado com um caractere nulo. O caractere de nova linha, se lido, é incluído na cadeia de caracteres.

**fgetws** é uma versão de caractere largo de **fgets**.

**fgetws** lê o argumento de caractere largo *str* como uma cadeia de caracteres multibyte ou uma cadeia de caracteres largos dependendo *fluxo* é aberto no modo de texto ou binário, respectivamente. Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**fgetts**|**fgets**|**fgets**|**fgetws**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fgets**|\<stdio.h>|
|**fgetws**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fgets.c
// This program uses fgets to display
// the first line from a file.

#include <stdio.h>

int main( void )
{
   FILE *stream;
   char line[100];

   if( fopen_s( &stream, "crt_fgets.txt", "r" ) == 0 )
   {
      if( fgets( line, 100, stream ) == NULL)
         printf( "fgets error\numChars" );
      else
         printf( "%s", line);
      fclose( stream );
   }
}
```

### <a name="input-crtfgetstxt"></a>Entrada: crt_fgets.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Line one.
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fputs, fputws](fputs-fputws.md)<br/>
[gets, _getws](../../c-runtime-library/gets-getws.md)<br/>
[puts, _putws](puts-putws.md)<br/>
