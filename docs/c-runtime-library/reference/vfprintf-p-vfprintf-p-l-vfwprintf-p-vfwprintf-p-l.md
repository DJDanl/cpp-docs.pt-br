---
title: _vfprintf_p, _vfprintf_p_l, _vfwprintf_p, _vfwprintf_p_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _vfprintf_p
- _vfwprintf_p
- _vfprintf_p_l
- _vfwprintf_p_l
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
- _vfwprintf_p_l
- _vfprintf_p
- vfwprintf_p_l
- vfwprintf_p
- vfprintf_p_l
- _vfwprintf_p
- _vftprintf_p
- _vfprintf_p_l
- vfprintf_p
dev_langs:
- C++
helpviewer_keywords:
- vfprintf_p_l function
- _vftprintf_p_l function
- _vfprintf_p function
- vfprintf_p function
- vftprintf_p_l function
- _vfprintf_p_l function
- _vftprintf_p function
- _vfwprintf_p_l function
- vfwprintf_p_l function
- _vfwprintf_p function
- vftprintf_p function
- formatted text [C++]
- vfwprintf_p function
ms.assetid: 4d4a0914-4175-4b65-9ca1-037c4ef29147
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0433cdccf053b4a995a4560faee0e254c92285d1
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="vfprintfp-vfprintfpl-vfwprintfp-vfwprintfpl"></a>_vfprintf_p, _vfprintf_p_l, _vfwprintf_p, _vfwprintf_p_l

Grave saída formatada usando um ponteiro para uma lista de argumentos, com a capacidade de especificar a ordem em que os argumentos são usados na cadeia de caracteres de formato.

## <a name="syntax"></a>Sintaxe

```C
int _vfprintf_p(
   FILE *stream,
   const char *format,
   va_list argptr
);
int _vfprintf_p_l(
   FILE *stream,
   const char *format,
   locale_t locale,
   va_list argptr
);
int _vfwprintf_p(
   FILE *stream,
   const wchar_t *format,
   va_list argptr
);
int _vfwprintf_p_l(
   FILE *stream,
   const wchar_t *format,
   locale_t locale,
   va_list argptr
);
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*format*<br/>
Especificação de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor de retorno

**vfprintf_p** e **vfwprintf_p** retornar o número de caracteres gravados, não incluindo o caractere null de terminação ou um valor negativo se ocorrer um erro de saída.

## <a name="remarks"></a>Comentários

Cada uma dessas funções usa um ponteiro para uma lista de argumentos, em seguida, formata e escreve os dados fornecidos para *fluxo*. Essas funções diferem do **_vfprint_s** e **_vfwprint_s** versões somente em que eles oferecem suporte a parâmetros posicionais. Para obter mais informações, consulte [Parâmetros posicionais printf_p](../../c-runtime-library/printf-p-positional-parameters.md).

**vfwprintf_p** é a versão de caractere largo de **vprintf_p**; as duas funções se comportam de forma idêntica se o fluxo está aberto no modo de ANSI. **vprintf_p** atualmente não suportam a saída em um fluxo UNICODE.

As versões dessas funções com o **_l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).

Se qualquer um dos *fluxo* ou *formato* é um ponteiro nulo, ou se a cadeia de caracteres de formato contém caracteres inválidos de formatação, o manipulador de parâmetro inválido é invocado, conforme descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, retornam -1, as funções e defina **errno** para **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**vftprintf_p**|**_vfprintf_p**|**_vfprintf_p**|**_vfwprintf_p**|
|**vftprintf_p_l**|**_vfprintf_p_l**|**_vfprintf_p_l**|**_vfwprintf_p_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**vfprintf_p**, **vfprintf_p_l**|\<stdio.h> e \<stdarg.h>|\<varargs.h>*|
|**vfwprintf_p**, **vfwprintf_p_l**|\<stdio.h> ou \<wchar.h> e \<stdarg.h>|\<varargs.h>*|

\* Necessário para compatibilidade com UNIX V.

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
[Parâmetros posicionais printf_p](../../c-runtime-library/printf-p-positional-parameters.md)<br/>
[_fprintf_p, _fprintf_p_l, _fwprintf_p, _fwprintf_p_l](fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)<br/>
[_vsprintf_p, _vsprintf_p_l, _vswprintf_p, _vswprintf_p_l](vsprintf-p-vsprintf-p-l-vswprintf-p-vswprintf-p-l.md)<br/>
[_sprintf_p, _sprintf_p_l, _swprintf_p, _swprintf_p_l](sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)<br/>
