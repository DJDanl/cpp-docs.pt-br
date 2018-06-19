---
title: scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- wscanf_s
- _wscanf_s_l
- scanf_s
- _scanf_s_l
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
- wscanf_s
- _tscanf_s_l
- _wscanf_s_l
- scanf_s
- _tscanf_s
- _scanf_s_l
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cd8abf72b67c060bd6016b7e784ded5a30801ca6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32415207"
---
# <a name="scanfs-scanfsl-wscanfs-wscanfsl"></a>scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l

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

Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor de retorno é **EOF** para um erro, ou se o caractere de final de arquivo ou o caractere de final de cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se *formato* é um **nulo** ponteiro, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **scanf_s** e **wscanf_s** retornar **EOF** e defina **errno** para **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **scanf_s** função lê dados do fluxo de entrada padrão **stdin** e grava os dados no local que é determinado pelo *argumento*. Cada *argumento* deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo na *formato*. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

**wscanf_s** é uma versão de caractere largo de **scanf_s**; o *formato* argumento **wscanf_s** é uma cadeia de caracteres largos. **wscanf_s** e **scanf_s** tenham comportamento idêntico, se o fluxo está aberto no modo de ANSI. **scanf_s** atualmente não dá suporte a entrada de um fluxo UNICODE.

As versões dessas funções que têm o **_l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade que é transmitido em vez da localidade do thread atual.

Ao contrário de **scanf** e **wscanf**, **scanf_s** e **wscanf_s** exigem o tamanho do buffer seja especificado para todos os parâmetros de tipo deentrada**c**, **C**, **s**, **S**, ou conjuntos de controle que são incluídos na cadeia de caracteres **[]**. O tamanho do buffer em caracteres é passado como um parâmetro adicional imediatamente após o ponteiro para o buffer ou variável. Por exemplo, se você estiver lendo uma cadeia de caracteres, o tamanho do buffer para essa cadeia de caracteres será passado conforme demonstrado a seguir:

```C
char s[10];
scanf_s("%9s", s, (unsigned)_countof(s)); // buffer size is 10, width specification is 9
```

O tamanho do buffer inclui o nulo de terminação. Você pode usar um campo de especificação de largura para garantir que o token lido caiba no buffer. Se nenhum campo de especificação de largura for usado e o token lido for muito grande para caber no buffer, nada será gravado no buffer.

> [!NOTE]
> O parâmetro de tamanho é do tipo **sem sinal**, não **size_t**. Use uma conversão estática para converter um **size_t** valor **sem sinal** configurações de compilação para 64 bits.

O exemplo a seguir mostra que o parâmetro de tamanho do buffer descreve o número máximo de caracteres, não de bytes. Na chamada para **wscanf_s**, a largura de caractere que é indicada pelo tipo de buffer não coincide com a largura de caractere que é indicada pelo especificador de formato.

```C
wchar_t ws[10];
wscanf_s(L"%9S", ws, (unsigned)_countof(ws));
```

O **S** especificador de formato indica o uso da largura de caractere que é "a largura padrão que é compatível com a função oposto". A largura do caractere é de um byte, mas a função dá suporte a caracteres de dois bytes. Este exemplo lê uma cadeia de caracteres de até 9 caracteres com um byte de largura e coloca-os em um buffer de caracteres com dois bytes de largura. Os caracteres são tratados como valores de byte único; os dois primeiros caracteres são armazenados em `ws[0]`, os próximos dois são armazenados em `ws[1]` e assim por diante.

No caso de caracteres, um único caractere pode ser lido como demonstrado a seguir:

```C
char c;
scanf_s("%c", &c, 1);
```

Quando vários caracteres para cadeias de caracteres terminadas em não nulo são lidos, inteiros são usados como a especificação de largura e o tamanho do buffer.

```C
char c[4];
scanf_s("%4c", &c, (unsigned)_countof(c)); // not null terminated
```

Para obter mais informações, consulte [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tscanf_s**|**scanf_s**|**scanf_s**|**wscanf_s**|
|**tscanf_s_l**|**_scanf_s_l**|**_scanf_s_l**|**_wscanf_s_l**|

Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**scanf_s**, **scanf_s_l**|\<stdio.h>|
|**wscanf_s**, **wscanf_s_l**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console, **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
