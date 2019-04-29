---
title: vscanf_s, vwscanf_s
ms.date: 11/04/2016
apiname:
- vscanf_s
- vwscanf_s
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
- _vtscanf_s
- vscanf_s
- vwscanf_s
ms.assetid: 23a1c383-5b01-4887-93ce-534a1e38ed93
ms.openlocfilehash: 90100a5fbc03371a11f437acc12562d9ccf957f9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62364864"
---
# <a name="vscanfs-vwscanfs"></a>vscanf_s, vwscanf_s

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

### <a name="parameters"></a>Parâmetros

*format*<br/>
Cadeia de caracteres de controle de formato.

*arglist*<br/>
Lista de argumentos variáveis.

## <a name="return-value"></a>Valor de retorno

Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor retornado será **EOF** para um erro, ou se o caractere de fim-de-arquivo ou o caractere de fim da cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se *formato* é um **nulo** ponteiro, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **vscanf_s** e **vwscanf_s** retornar **EOF** e defina **errno** para **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **vscanf_s** função lê dados de fluxo de entrada padrão **stdin** e grava os dados nos locais fornecidos pela *arglist* lista de argumentos. Cada argumento na lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em *formato*. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

**vwscanf_s** é uma versão de caractere largo de **vscanf_s**; o *formato* argumento **vwscanf_s** é uma cadeia de caracteres largos. **vwscanf_s** e **vscanf_s** terão comportamento idêntico se o fluxo for aberto no modo ANSI. **vscanf_s** não dá suporte a entrada de um fluxo UNICODE.

Diferentemente **vscanf** e **vwscanf**, **vscanf_s** e **vwscanf_s** exigem que o tamanho do buffer seja especificado para todos os parâmetros de tipo de entrada **c**, **C**, **s**, **S**, ou conjuntos de controle que são incluídos na cadeia de caracteres **[]**. O tamanho do buffer em caracteres é passado como um parâmetro adicional imediatamente após o ponteiro para o buffer ou variável. O tamanho do buffer em caracteres para um **wchar_t** cadeia de caracteres não é igual ao tamanho em bytes.

O tamanho do buffer inclui o nulo de terminação. Você pode usar um campo de especificação de largura para garantir que o token lido caiba no buffer. Se nenhum campo de especificação de largura for usado e o token lido for muito grande para caber no buffer, nada será gravado no buffer.

> [!NOTE]
> O *tamanho* parâmetro é do tipo **unsigned**, e não **size_t**.

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

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[scanf, _scanf_l, wscanf, _wscanf_l](scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)<br/>
[vscanf, vwscanf](vscanf-vwscanf.md)<br/>
