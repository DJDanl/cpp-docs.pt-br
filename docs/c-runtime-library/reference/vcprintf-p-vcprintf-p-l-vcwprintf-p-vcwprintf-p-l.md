---
title: _vcprintf_p, _vcprintf_p_l, _vcwprintf_p, _vcwprintf_p_l
ms.date: 11/04/2016
apiname:
- _vcprintf_p
- _vcwprintf_p_l
- _vcprintf_p_l
- _vcwprintf_p
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
- vcwprintf_p
- vcprintf_p_l
- _vcprintf_p
- _vcprintf_p_l
- vcwprintf_p_l
- vcprintf_p
- _vcwprintf_p
- _vcwprintf_p_l
helpviewer_keywords:
- _vtcprintf_p_l function
- vcprintf_p_l function
- _vcprintf_p_l function
- vtcprintf_p_l function
- vcprintf_p function
- _vcwprintf_p function
- _vcprintf_p function
- vcwprintf_p function
- vcwprintf_p_l function
- vtcprintf_p function
- _vcwprintf_p_l function
- _vtcprintf_p function
ms.assetid: 611024cc-90e7-41db-8e85-145ca95012b1
ms.openlocfilehash: 59e601d5cd03d58fe2d1725ba509a9fa3b2f3422
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62364877"
---
# <a name="vcprintfp-vcprintfpl-vcwprintfp-vcwprintfpl"></a>_vcprintf_p, _vcprintf_p_l, _vcwprintf_p, _vcwprintf_p_l

Grava a saída formatada no console usando um ponteiro para uma lista de argumentos e dá suporte a parâmetros posicionais na cadeia de caracteres de formato.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _vcprintf_p(
   const char* format,
   va_list argptr
);
int _vcprintf_p_l(
   const char* format,
   locale_t locale,
   va_list argptr
);
int _vcwprintf_p(
   const wchar_t* format,
   va_list argptr
);
int _vcwprintf_p_l(
   const wchar_t* format,
   locale_t locale,
   va_list argptr
);
```

### <a name="parameters"></a>Parâmetros

*format*<br/>
A especificação do formato.

*argptr*<br/>
Um ponteiro para uma lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor de retorno

O número de caracteres gravados ou um valor negativo se ocorrer erro de saída. Se *formato* for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e -1 será retornado.

## <a name="remarks"></a>Comentários

Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, usa o **putch** função para formatar e gravar os dados fornecidos no console. (**vcwprintf_p** usa **putwch** em vez de **putch**. **vcwprintf_p** é a versão de caractere largo de **vcprintf_p**. Uma cadeia de caracteres largos é usada como argumento.)

As versões dessas funções que têm o **l** sufixo são idênticas, exceto por usarem o parâmetro de localidade passado em vez da localidade atual.

Cada *argumento* (se houver) é convertido e gerado de acordo com a especificação de formato correspondente em *formato*. A especificação de formato dá suporte a parâmetros posicionais para que você possa especificar a ordem na qual os argumentos são usados na cadeia de caracteres de formato. Para obter mais informações, consulte [Parâmetros posicionais printf_p](../../c-runtime-library/printf-p-positional-parameters.md).

Essas funções não traduzem caracteres de alimentação de linha em combinações CR-LF (retorno de carro-alimentação de linha) quando eles são a saída.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/desktop/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

Essas funções validam o ponteiro de entrada e a cadeia de caracteres de formato. Se *formato* ou *argumento* está **nulo**, ou se a cadeia de caracteres de formato contiver caracteres de formatação inválidos, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e defina **errno** à **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_vtcprintf_p**|**_vcprintf_p**|**_vcprintf_p**|**_vcwprintf_p**|
|**_vtcprintf_p_l**|**_vcprintf_p_l**|**_vcprintf_p_l**|**_vcwprintf_p_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_vcprintf_p**, **_vcprintf_p_l**|\<conio.h> e \<stdarg.h>|
|**_vcwprintf_p**, **_vcwprintf_p_l**|\<conio.h> e \<stdarg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_vcprintf_p.c
// compile with: /c
#include <conio.h>
#include <stdarg.h>

// An error formatting function that's used to print to the console.
int eprintf(const char* format, ...)
{
   va_list args;
   va_start(args, format);
   int result = _vcprintf_p(format, args);
   va_end(args);
   return result;
}

int main()
{
   int n = eprintf("parameter 2 = %2$d; parameter 1 = %1$s\r\n",
      "one", 222);
   _cprintf_s("%d characters printed\r\n");
}
```

```Output
parameter 2 = 222; parameter 1 = one
38 characters printed
```

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_cprintf, _cprintf_l, _cwprintf, _cwprintf_l](cprintf-cprintf-l-cwprintf-cwprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
[Parâmetros posicionais printf_p](../../c-runtime-library/printf-p-positional-parameters.md)<br/>
