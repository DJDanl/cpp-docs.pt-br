---
title: vscanf_s, vwscanf_s
ms.date: 11/04/2016
api_name:
- vscanf_s
- vwscanf_s
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
- _vtscanf_s
- vscanf_s
- vwscanf_s
ms.assetid: 23a1c383-5b01-4887-93ce-534a1e38ed93
ms.openlocfilehash: 9fb58e38362d709ef6d203c5602aa32727efa763
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215095"
---
# <a name="vscanf_s-vwscanf_s"></a>vscanf_s, vwscanf_s

Lê dados formatados do fluxo de entrada padrão. Essas versões de [vscanf, vwscanf](vscanf-vwscanf.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
int vscanf_s(
   const char *format,
   va_list arglist
);
int vwscanf_s(
   const wchar_t *format,
   va_list arglist
);
```

### <a name="parameters"></a>parâmetros

*format*<br/>
Cadeia de caracteres de controle de formato.

*Arglist*<br/>
Lista de argumentos variáveis.

## <a name="return-value"></a>Valor retornado

Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor de retorno é **EOF** para um erro, ou se o caractere de fim de arquivo ou o caractere de fim de cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se *Format* for um ponteiro **NULL** , o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **vscanf_s** e **vwscanf_s** retornar **EOF** e definir **errno** como **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **vscanf_s** lê dados do fluxo de entrada do **stdin** padrão e grava os dados nos locais fornecidos pela lista de argumentos *Arglist* . Cada argumento na lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo no *formato*. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

**vwscanf_s** é uma versão de caractere largo do **vscanf_s**; o argumento de *formato* para **vwscanf_s** é uma cadeia de caracteres largos. **vwscanf_s** e **vscanf_s** se comportam de forma idêntica se o fluxo é aberto no modo ANSI. **vscanf_s** não dá suporte à entrada de um fluxo Unicode.

Ao contrário de **vscanf** e **vwscanf**, **vscanf_s** e **vwscanf_s** exigem que o tamanho do buffer seja especificado para todos os parâmetros de entrada do tipo **c**, **c**, **s**, **s**ou conjuntos de controles de cadeia de caracteres que estão entre **[]**. O tamanho do buffer em caracteres é passado como um parâmetro adicional imediatamente após o ponteiro para o buffer ou variável. O tamanho do buffer em caracteres para uma **`wchar_t`** cadeia de caracteres não é igual ao tamanho em bytes.

O tamanho do buffer inclui o nulo de terminação. Você pode usar um campo de especificação de largura para garantir que o token lido caiba no buffer. Se nenhum campo de especificação de largura for usado e o token lido for muito grande para caber no buffer, nada será gravado no buffer.

> [!NOTE]
> O parâmetro *size* é do tipo **`unsigned`** , não **size_t**.

Para obter mais informações, consulte [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_vtscanf_s**|**vscanf_s**|**vscanf_s**|**vwscanf_s**|

Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**vscanf_s**|\<stdio.h>|
|**wscanf_s**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão associados ao console, **stdin**, **stdout**e **stderr**devem ser redirecionados antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_vscanf_s.c
// compile with: /W3
// This program uses the vscanf_s and vwscanf_s functions
// to read formatted input.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int call_vscanf_s(char *format, ...)
{
    int result;
    va_list arglist;
    va_start(arglist, format);
    result = vscanf_s(format, arglist);
    va_end(arglist);
    return result;
}

int call_vwscanf_s(wchar_t *format, ...)
{
    int result;
    va_list arglist;
    va_start(arglist, format);
    result = vwscanf_s(format, arglist);
    va_end(arglist);
    return result;
}

int main( void )
{
    int   i, result;
    float fp;
    char  c, s[81];
    wchar_t wc, ws[81];
    result = call_vscanf_s("%d %f %c %C %s %S", &i, &fp, &c, 1,
                           &wc, 1, s, _countof(s), ws, _countof(ws) );
    printf( "The number of fields input is %d\n", result );
    printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);
    result = call_vwscanf_s(L"%d %f %hc %lc %S %ls", &i, &fp, &c, 2,
                            &wc, 1, s, _countof(s), ws, _countof(ws) );
    wprintf( L"The number of fields input is %d\n", result );
    wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);
}
```

Quando esse programa recebe a entrada no exemplo, ele produz esta saída:

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
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[scanf, _scanf_l, wscanf, _wscanf_l](scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)<br/>
[vscanf, vwscanf](vscanf-vwscanf.md)<br/>
