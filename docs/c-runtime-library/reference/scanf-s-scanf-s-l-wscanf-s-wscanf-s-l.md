---
title: scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l
ms.date: 03/26/2019
api_name:
- wscanf_s
- _wscanf_s_l
- scanf_s
- _scanf_s_l
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
- wscanf_s
- _tscanf_s_l
- _wscanf_s_l
- scanf_s
- _tscanf_s
- _scanf_s_l
helpviewer_keywords:
- reading data [C++], from input streams
- buffers [C++], buffer overruns
- _scanf_s_l function
- _wscanf_s_l function
- tscanf_s_l function
- tscanf_s function
- scanf_s function
- data [C++], reading from input stream
- wscanf_s function
- _tscanf_s_l function
- _tscanf_s function
- scanf_s_l function
- formatted data [C++], from input streams
- wscanf_s_l function
- buffers [C++], avoiding overruns
ms.assetid: 42cafcf7-52d6-404a-80e4-b056a7faf2e5
ms.openlocfilehash: e869f9e0d4fa87c87878ffea987e4b6d85a75616
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948869"
---
# <a name="scanf_s-_scanf_s_l-wscanf_s-_wscanf_s_l"></a>scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l

Lê dados formatados do fluxo de entrada padrão. Essas versões de [scanf, _scanf_l, wscanf, _wscanf_l](scanf-scanf-l-wscanf-wscanf-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
int scanf_s(
   const char *format [,
   argument]...
);
int _scanf_s_l(
   const char *format,
   locale_t locale [,
   argument]...
);
int wscanf_s(
   const wchar_t *format [,
   argument]...
);
int _wscanf_s_l(
   const wchar_t *format,
   locale_t locale [,
   argument]...
);
```

### <a name="parameters"></a>Parâmetros

*format*<br/>
Cadeia de caracteres de controle de formato.

*argument*<br/>
Argumentos opcionais.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Retorna o número de campos convertidos e atribuídos com êxito. O valor de retorno não inclui campos que foram lidos, mas não atribuídos. Um valor de retorno de 0 indica que nenhum campo foi atribuído. O valor de retorno é **EOF** para um erro, ou se o caractere de fim de arquivo ou o caractere de fim de cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se *Format* for um ponteiro **NULL** , o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **scanf_s** e **wscanf_s** retornará **EOF** e definir **errno** como **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **scanf_s** lê dados do fluxo de entrada padrão, **stdin**, e grava-os em *argumento*. Cada *argumento* deve ser um ponteiro para um tipo de variável que corresponde ao especificador de tipo no *formato*. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

**wscanf_s** é uma versão de caractere largo do **scanf_s**; o argumento *Format* para **wscanf_s** é uma cadeia de caracteres largos. **wscanf_s** e **scanf_s** se comportam de forma idêntica se o fluxo é aberto no modo ANSI. Atualmente, o **scanf_s** não dá suporte à entrada de um fluxo Unicode.

As versões dessas funções que têm o sufixo **_L** são idênticas, exceto que usam o parâmetro *locale* em vez da localidade do thread atual.

Ao contrário de **scanf** e **wscanf**, **scanf_s** e **wscanf_s** exigem que você especifique tamanhos de buffer para alguns parâmetros. Especifique os tamanhos para todos os parâmetros **c**, **c**, **s**, **s**ou String Control Set **[]** . O tamanho do buffer em caracteres é passado como um parâmetro adicional. Ele segue imediatamente o ponteiro para o buffer ou a variável. Por exemplo, se você estiver lendo uma cadeia de caracteres, o tamanho do buffer dessa cadeia de caracteres será passado da seguinte maneira:

```C
char s[10];
scanf_s("%9s", s, (unsigned)_countof(s)); // buffer size is 10, width specification is 9
```

O tamanho do buffer inclui o terminal nulo. Você pode usar um campo de especificação de largura para garantir que o token que é lido caiba no buffer. Quando um token é grande demais para caber, nada é gravado no buffer, a menos que haja uma especificação de largura.

> [!NOTE]
> O parâmetro de tamanho é do tipo não **assinado**, não **size_t**. Use uma conversão estática para converter um valor **size_t** para **não assinado** para configurações de Build de 64 bits.

O parâmetro tamanho do buffer descreve o número máximo de caracteres, não bytes. Neste exemplo, a largura do tipo de buffer não corresponde à largura do especificador de formato.

```C
wchar_t ws[10];
wscanf_s(L"%9S", ws, (unsigned)_countof(ws));
```

O especificador de formato **S** significa usar a largura de caractere que é "oposta" à largura padrão com suporte da função. A largura do caractere é de um único byte, mas a função dá suporte a caracteres de byte duplo. Este exemplo lê em uma cadeia de caracteres de até nove personagens de byte único e os coloca em um buffer de caracteres de byte duplo. Os caracteres são tratados como valores de byte único; os dois primeiros caracteres são armazenados em `ws[0]`, os próximos dois são armazenados em `ws[1]` e assim por diante.

Este exemplo lê um único caractere:

```C
char c;
scanf_s("%c", &c, 1);
```

Quando são lidos vários caracteres para seqüências não terminadas em nulo, os inteiros são usados tanto para a especificação de largura quanto para o tamanho do buffer.

```C
char c[4];
scanf_s("%4c", c, (unsigned)_countof(c)); // not null terminated
```

Para obter mais informações, consulte [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tscanf_s**|**scanf_s**|**scanf_s**|**wscanf_s**|
|**_tscanf_s_l**|**_scanf_s_l**|**_scanf_s_l**|**_wscanf_s_l**|

Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**scanf_s**, **_scanf_s_l**|\<stdio.h>|
|**wscanf_s**, **_wscanf_s_l**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). O fluxo padrão de **stdin**, **stdout**e **stderr** deve ser redirecionado antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_scanf_s.c
// This program uses the scanf_s and wscanf_s functions
// to read formatted input.

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   int      i,
            result;
   float    fp;
   char     c,
            s[80];
   wchar_t  wc,
            ws[80];

   result = scanf_s( "%d %f %c %C %s %S", &i, &fp, &c, 1,
                     &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws) );
   printf( "The number of fields input is %d\n", result );
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c,
           wc, s, ws);
   result = wscanf_s( L"%d %f %hc %lc %S %ls", &i, &fp, &c, 2,
                      &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws) );
   wprintf( L"The number of fields input is %d\n", result );
   wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp,
            c, wc, s, ws);
}
```

Este programa produz a seguinte saída quando recebe essa entrada:

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[fscanf, _fscanf_l, fwscanf, _fwscanf_l](fscanf-fscanf-l-fwscanf-fwscanf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[sscanf, _sscanf_l, swscanf, _swscanf_l](sscanf-sscanf-l-swscanf-swscanf-l.md)<br/>
