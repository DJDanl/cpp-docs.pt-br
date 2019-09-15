---
title: _vcprintf_s, _vcprintf_s_l, _vcwprintf_s, _vcwprintf_s_l
ms.date: 11/04/2016
api_name:
- _vcprintf_s
- _vcprintf_s_l
- _vcwprintf_s
- _vcwprintf_s_l
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
- vcprintf_s
- vcwprintf_s_l
- _vcwprintf_s
- _vcwprintf_s_l
- _vcprintf_s_l
- _vtcprintf_s
- vcwprintf_s
- vcprintf_s_l
- _vcprintf_s
helpviewer_keywords:
- _vtcprintf_s_l function
- _vcwprintf_s_l function
- _vtcprintf_s function
- vtcprintf_s_l function
- vcprintf_s_l function
- _vcprintf_s function
- _vcwprintf_s function
- vcwprintf_s_l function
- vcwprintf_s function
- vcprintf_s function
- _vcprintf_s_l function
- vtcprintf_s function
- formatted text [C++]
ms.assetid: 5a46d45a-30db-45df-9850-455cbdac5636
ms.openlocfilehash: a6a3e94167adcc614a5de45a314fca25bdc9e1f2
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70945658"
---
# <a name="_vcprintf_s-_vcprintf_s_l-_vcwprintf_s-_vcwprintf_s_l"></a>_vcprintf_s, _vcprintf_s_l, _vcwprintf_s, _vcwprintf_s_l

Grava a saída formatada no console usando um ponteiro para uma lista de argumentos. Essas versões de [_vcprintf, _vcprintf_l, _vcwprintf, _vcwprintf_l](vcprintf-vcprintf-l-vcwprintf-vcwprintf-l.md) apresentam melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _vcprintf(
   const char* format,
   va_list argptr
);
int _vcprintf(
   const char* format,
   locale_t locale,
   va_list argptr
);
int _vcwprintf_s(
   const wchar_t* format,
   va_list argptr
);
int _vcwprintf_s_l(
   const wchar_t* format,
   locale_t locale,
   va_list argptr
);
```

### <a name="parameters"></a>Parâmetros

*format*<br/>
Especificação de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor de retorno

O número de caracteres gravados ou um valor negativo se ocorrer erro de saída.

Como as versões menos seguras dessas funções, se *Format* for um ponteiro NULL, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Além disso, ao contrário das versões menos seguras dessas funções, se *Format* não especificar um formato válido, uma exceção de parâmetro inválida será gerada. Se a execução tiver permissão para continuar, essas funções retornarão um código de erro e definirei **errno** para esse código de erro. O código de erro padrão será **EINVAL** se um valor mais específico não se aplicar.

## <a name="remarks"></a>Comentários

Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, formata e grava os dados determinados no console. **_vcwprintf_s** é a versão de caractere largo do **_vcprintf_s**. Uma cadeia de caracteres largos é usada como argumento.

As versões dessas funções que têm o sufixo **_L** são idênticas, exceto pelo fato de que usam o parâmetro Locale que é passado em vez da localidade atual.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_vtcprintf_s**|**_vcprintf_s**|**_vcprintf_s**|**_vcwprintf_s**|
|**_vtcprintf_s_l**|**_vcprintf_s_l**|**_vcprintf_s_l**|**_vcwprintf_s_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**_vcprintf_s**, **_vcprintf_s_l**|\<conio.h> e \<stdarg.h>|\<varargs.h>*|
|**_vcwprintf_s**, **_vcwprintf_s_l**|\<conio.h> ou \<wchar.h> e \<stdarg.h>|\<varargs.h>*|

\* Necessário para compatibilidade com UNIX V.

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_vcprintf_s.cpp
#include <conio.h>
#include <stdarg.h>

// An error formatting function used to print to the console.
int eprintf_s(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int result = _vcprintf_s(format, args);
    va_end(args);
    return result;
}

int main()
{
    eprintf_s("(%d:%d): Error %s%d : %s\n", 10, 23, "C", 2111,
              "<some error text>");
    eprintf_s("    (Related to symbol '%s' defined on line %d).\n",
              "<symbol>", 5 );
}
```

```Output
(10,23): Error C2111 : <some error text>
    (Related to symbol '<symbol>' defined on line 5).
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[_cprintf, _cprintf_l, _cwprintf, _cwprintf_l](cprintf-cprintf-l-cwprintf-cwprintf-l.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
