---
title: _cprintf, _cprintf_l, _cwprintf, _cwprintf_l
ms.date: 11/04/2016
apiname:
- _cwprintf_l
- _cprintf_l
- _cwprintf
- _cprintf
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
- _cwprintf
- cwprintf
- tcprintf
- _tcprintf
- _cprintf
- cwprintf_l
- tcprintf_l
- _tcprintf_l
- cprintf_l
- _cprintf_l
- _cwprintf_l
helpviewer_keywords:
- _cprintf_l function
- _cwprintf_l function
- cwprintf function
- cprintf_l function
- characters, printing to console
- printing characters to console
- _tcprintf_l function
- tcprintf function
- _tcprintf function
- tcprintf_l function
- _cwprintf function
- cwprintf_l function
- _cprintf function
ms.assetid: 67ffefd4-45b3-4be0-9833-d8d26ac7c4e2
ms.openlocfilehash: ce1913012ee37b19e15602daaa4eea042a69a3de
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50534037"
---
# <a name="cprintf-cprintfl-cwprintf-cwprintfl"></a>_cprintf, _cprintf_l, _cwprintf, _cwprintf_l

Formata e imprime no console. Versões mais seguras estão disponíveis; consulte [_cprintf_s, _cprintf_s_l, _cwprintf_s, _cwprintf_s_l](cprintf-s-cprintf-s-l-cwprintf-s-cwprintf-s-l.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _cprintf(
   const char * format [, argument_list]
);
int _cprintf_l(
   const char * format,
   locale_t locale [, argument_list]
);
int _cwprintf(
   const wchar * format [, argument_list]
);
int _cwprintf_l(
   const wchar * format,
   locale_t locale [, argument_list]
);
```

### <a name="parameters"></a>Parâmetros

*format*<br/>
Cadeia de caracteres de controle de formato.

*argument_list*<br/>
Parâmetros opcionais para a cadeia de caracteres de formato.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

O número de caracteres impressos.

## <a name="remarks"></a>Comentários

Essas funções formatam e imprimem uma série de caracteres e valores diretamente no console, usando o **putch** função (**putwch** para **cwprintf**) para caracteres de saída . Cada argumento na *argument_list* (se houver) é convertido e gerado de acordo com a especificação de formato correspondente em *formato*. O *formato* argumento usa o [formatar a sintaxe de especificação de funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md). Ao contrário do **fprintf**, **printf**, e **sprintf** funções, nem **cprintf** nem **cwprintf**converte caracteres de alimentação de linha em combinações de retorno-alimentação de linha (CR-LF) do carro durante a geração.

Uma distinção importante é que **cwprintf** exibe caracteres Unicode quando usado no Windows. Diferentemente **cprintf**, **cwprintf** usa as configurações atuais de localidade do console.

As versões dessas funções com o **l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade atual.

**cprintf** valida o *formato* parâmetro. Se *formato* for um ponteiro nulo, a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará -1 e definirá **errno** à **EINVAL**.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tcprintf**|**_cprintf**|**_cprintf**|**_cwprintf**|
|**tcprintf_l**|**_cprintf_l**|**_cprintf_l**|**_cwprintf_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**cprintf**, **cprintf_l**|\<conio.h>|
|**cwprintf**, **cwprintf_l**|\<conio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_cprintf.c
// compile with: /c
// This program displays some variables to the console.

#include <conio.h>

int main( void )
{
    int         i = -16,
                h = 29;
    unsigned    u = 62511;
    char        c = 'A';
    char        s[] = "Test";

    // Note that console output does not translate \n as
    // standard output does. Use \r\n instead.
    //
    _cprintf( "%d  %.4x  %u  %c %s\r\n", i, h, u, c, s );
}
```

```Output
-16  001d  62511  A Test
```

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_cscanf, _cscanf_l, _cwscanf, _cwscanf_l](cscanf-cscanf-l-cwscanf-cwscanf-l.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[vfprintf, _vfprintf_l, vfwprintf, _vfwprintf_l](vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)<br/>
[_cprintf_s, _cprintf_s_l, _cwprintf_s, _cwprintf_s_l](cprintf-s-cprintf-s-l-cwprintf-s-cwprintf-s-l.md)<br/>
[_cprintf_p, _cprintf_p_l, _cwprintf_p, _cwprintf_p_l](cprintf-p-cprintf-p-l-cwprintf-p-cwprintf-p-l.md)<br/>
[Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)<br/>
