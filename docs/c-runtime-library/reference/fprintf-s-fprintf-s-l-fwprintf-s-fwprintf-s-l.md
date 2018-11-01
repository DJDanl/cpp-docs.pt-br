---
title: fprintf_s, _fprintf_s_l, fwprintf_s, _fwprintf_s_l
ms.date: 11/04/2016
apiname:
- _fprintf_s_l
- fwprintf_s
- fprintf_s
- _fwprintf_s_l
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
- _ftprintf_s
- fprintf_s
- fwprintf_s
helpviewer_keywords:
- ftprintf_s_l function
- ftprintf_s function
- _fprintf_s_l function
- _ftprintf_s function
- _ftprintf_s_l function
- fwprintf_s_l function
- fwprintf_s function
- fprintf_s_l function
- fprintf_s function
- _fwprintf_s_l function
- print formatted data to streams
ms.assetid: 16067c3c-69ce-472a-8272-9aadf1f5beed
ms.openlocfilehash: 05886dc4ce7de771749f157913a222b6b01a5c5a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50639420"
---
# <a name="fprintfs-fprintfsl-fwprintfs-fwprintfsl"></a>fprintf_s, _fprintf_s_l, fwprintf_s, _fwprintf_s_l

Imprimir dados formatados em um fluxo. Essas são versões de [fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
int fprintf_s(
   FILE *stream,
   const char *format [,
   argument_list ]
);
int _fprintf_s_l(
   FILE *stream,
   const char *format,
   locale_t locale [,
   argument_list ]
);
int fwprintf_s(
   FILE *stream,
   const wchar_t *format [,
   argument_list ]
);
int _fwprintf_s_l(
   FILE *stream,
   const wchar_t *format,
   locale_t locale [,
   argument_list ]
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*format*<br/>
Cadeia de caracteres de controle de formato.

*argument_list*<br/>
Argumentos opcionais para a cadeia de caracteres de formato.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**fprintf_s** retorna o número de bytes gravados. **fwprintf_s** retorna o número de caracteres largos gravados. Cada uma dessas funções retorna um valor negativo quando ocorre um erro de saída.

## <a name="remarks"></a>Comentários

**fprintf_s** formata e imprime uma série de caracteres e valores para a saída *fluxo*. Cada argumento na *argument_list* (se houver) é convertido e gerado de acordo com a especificação de formato correspondente em *formato*. O *formato* argumento usa o [formatar a sintaxe de especificação de funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

**fwprintf_s** é uma versão de caractere largo de **fprintf_s**; na **fwprintf_s**, *formato* é uma cadeia de caracteres largos. Essas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **fprintf_s** atualmente, não suporta a saída em um fluxo UNICODE.

As versões dessas funções com o **l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade atual.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário.

Assim como as versões não seguras (consulte [fprintf, fprintf_l, fwprintf, fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)), essas funções validam seus parâmetros e invocam o manipulador de parâmetro inválido, conforme descrito em [devalidaçãodeparâmetro](../../c-runtime-library/parameter-validation.md), se qualquer um dos *stream* ou *formato* for um ponteiro nulo. A cadeia de caracteres de formato em si também é validada. Se houver algum especificador de formatação desconhecido ou mal formado, essas funções gerarão a exceção de parâmetro inválido. Em todos os casos, se a execução puder continuar, essas funções retornarão -1 e defina **errno** à **EINVAL**. Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**ftprintf_s**|**fprintf_s**|**fprintf_s**|**fwprintf_s**|
|**ftprintf_s_l**|**_fprintf_s_l**|**_fprintf_s_l**|**_fwprintf_s_l**|

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fprintf_s**, **fprintf_s_l**|\<stdio.h>|
|**fwprintf_s**, **fwprintf_s_l**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fprintf_s.c
// This program uses fprintf_s to format various
// data and print it to the file named FPRINTF_S.OUT. It
// then displays FPRINTF_S.OUT on the screen using the system
// function to invoke the operating-system TYPE command.

#include <stdio.h>
#include <process.h>

FILE *stream;

int main( void )
{
   int    i = 10;
   double fp = 1.5;
   char   s[] = "this is a string";
   char   c = '\n';

   fopen_s( &stream, "fprintf_s.out", "w" );
   fprintf_s( stream, "%s%c", s, c );
   fprintf_s( stream, "%d\n", i );
   fprintf_s( stream, "%f\n", fp );
   fclose( stream );
   system( "type fprintf_s.out" );
}
```

```Output
this is a string
10
1.500000
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_cprintf, _cprintf_l, _cwprintf, _cwprintf_l](cprintf-cprintf-l-cwprintf-cwprintf-l.md)<br/>
[fscanf, _fscanf_l, fwscanf, _fwscanf_l](fscanf-fscanf-l-fwscanf-fwscanf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
