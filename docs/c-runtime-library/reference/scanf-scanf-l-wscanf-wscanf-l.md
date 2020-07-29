---
title: scanf, _scanf_l, wscanf, _wscanf_l
ms.date: 10/21/2019
api_name:
- _wscanf_l
- scanf
- _scanf_l
- wscanf
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
- _tscanf
- _scanf_l
- wscanf
- _wscanf_l
- scanf
- _tscanf_l
helpviewer_keywords:
- tscanf_l function
- _tscanf_l function
- reading data [C++], from input streams
- _tscanf function
- data [C++], reading from input stream
- scanf_l function
- scanf function
- wscanf function
- _scanf_l function
- tscanf function
- formatted data [C++], from input streams
- wscanf_l function
- _wscanf_l function
ms.assetid: 73eac607-117f-4be4-9ff0-4afd9cf3c848
ms.openlocfilehash: 62f97c901bc7e6dc34a2db6ad80193cc4aaa986a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231345"
---
# <a name="scanf-_scanf_l-wscanf-_wscanf_l"></a>scanf, _scanf_l, wscanf, _wscanf_l

Lê dados formatados do fluxo de entrada padrão. Versões mais seguras dessas funções estão disponíveis; consulte [scanf_s, scanf_s_l, wscanf_s, wscanf_s_l](scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md).

> [!NOTE]
> No Visual Studio 2015 `printf` , a `scanf` família e as funções foram declaradas como **`inline`** e movidas para os `<stdio.h>` `<conio.h>` cabeçalhos e. Se você estiver migrando um código mais antigo, poderá ver *LNK2019* em conexão com essas funções. Para obter mais informações, consulte [Visual C++ histórico de alterações 2003-2015](../../porting/visual-cpp-change-history-2003-2015.md#stdio_and_conio).

## <a name="syntax"></a>Sintaxe

```C
int scanf(
   const char *format [,
   argument]...
);
int _scanf_l(
   const char *format,
   locale_t locale [,
   argument]...
);
int wscanf(
   const wchar_t *format [,
   argument]...
);
int _wscanf_l(
   const wchar_t *format,
   locale_t locale [,
   argument]...
);
```

### <a name="parameters"></a>parâmetros

*format*<br/>
Cadeia de caracteres de controle de formato.

*argument*<br/>
Argumentos opcionais.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído.

Se *Format* for um ponteiro **NULL** , o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornam **EOF** e definem **errno** como **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **scanf** lê dados do fluxo de entrada do **stdin** padrão e grava os dados no local fornecido pelo *argumento*. Cada *argumento* deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo no *formato*. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

> [!IMPORTANT]
> Ao ler uma cadeia de caracteres com **scanf**, sempre especifique uma largura para o formato **% s** (por exemplo, **"% 32s"** em vez de **"% s"**); caso contrário, a entrada formatada incorretamente poderá facilmente causar uma saturação do buffer. Como alternativa, considere o uso de [scanf_s, scanf_s_l, wscanf_s, wscanf_s_l](scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md) ou [fgets](fgets-fgetws.md).

**wscanf** é uma versão de caractere largo do **scanf**; o argumento *Format* para **wscanf** é uma cadeia de caracteres largos. **wscanf** e **scanf** se comportam de forma idêntica se o fluxo é aberto no modo ANSI. Atualmente, o **scanf** não dá suporte à entrada de um fluxo Unicode.

As versões dessas funções com o sufixo **_L** são idênticas, exceto pelo fato de que usam o parâmetro Locale passado em vez da localidade do thread atual.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tscanf**|**scanf**|**scanf**|**wscanf**|
|**_tscanf_l**|**_scanf_l**|**_scanf_l**|**_wscanf_l**|

Para obter mais informações, consulte [Campos de especificação de formato – funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**scanf**, **_scanf_l**|\<stdio.h>|
|**wscanf**, **_wscanf_l**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão associados ao console, **stdin**, **stdout**e **stderr**devem ser redirecionados antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_scanf.c
// compile with: /W3
// This program uses the scanf and wscanf functions
// to read formatted input.

#include <stdio.h>

int main( void )
{
   int   i, result;
   float fp;
   char  c, s[81];
   wchar_t wc, ws[81];
   result = scanf( "%d %f %c %C %80s %80S", &i, &fp, &c, &wc, s, ws ); // C4996
   // Note: scanf and wscanf are deprecated; consider using scanf_s and wscanf_s
   printf( "The number of fields input is %d\n", result );
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);
   result = wscanf( L"%d %f %hc %lc %80S %80ls", &i, &fp, &c, &wc, s, ws ); // C4996
   wprintf( L"The number of fields input is %d\n", result );
   wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);
}
```

```Input
71 98.6 h z Byte characters
36 92.3 y n Wide characters
```

```Output
The number of fields input is 6
The contents are: 71 98.599998 h z Byte characters
The number of fields input is 6
The contents are: 36 92.300003 y n Wide characters
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[fscanf, _fscanf_l, fwscanf, _fwscanf_l](fscanf-fscanf-l-fwscanf-fwscanf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \_ _swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[sscanf, _sscanf_l, swscanf, _swscanf_l](sscanf-sscanf-l-swscanf-swscanf-l.md)<br/>
