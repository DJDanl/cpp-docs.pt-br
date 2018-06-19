---
title: _vscprintf_p, _vscprintf_p_l, _vscwprintf_p, _vscwprintf_p_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _vscprintf_p_l
- _vscprintf_p
- _vscwprintf_p_l
- _vscwprintf_p
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
- _vscprintf_p
- _vscprintf_p_l
- vscwprintf_p
- vscprintf_p
- vscwprintf_p_l
- _vscwprintf_p_l
- vscprintf_p_l
- _vscwprintf_p
dev_langs:
- C++
helpviewer_keywords:
- vscprintf_p function
- _vsctprintf_p_l function
- vscwprintf_p_l function
- _vscwprintf_p_l function
- _vscprintf_p function
- vsctprintf_p function
- _vscprintf_p_l function
- _vscwprintf_p function
- vscwprintf_p function
- vsctprintf_p_l function
- _vsctprintf_p function
- vscprintf_p_l function
ms.assetid: 5da920b3-8652-4ee9-b19e-5aac3ace9d03
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2da945addb975404a5ea6d1805a8f0abf5d5b9eb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32412899"
---
# <a name="vscprintfp-vscprintfpl-vscwprintfp-vscwprintfpl"></a>_vscprintf_p, _vscprintf_p_l, _vscwprintf_p, _vscwprintf_p_l

Retorna o número de caracteres na cadeia de caracteres formatada usando um ponteiro para uma lista de argumentos, com a capacidade de especificar a ordem na qual os argumentos são usados.

## <a name="syntax"></a>Sintaxe

```C
int _vscprintf_p(
   const char *format,
   va_list argptr
);
int _vscprintf_p _l(
   const char *format,
   locale_t locale,
   va_list argptr
);
int _vscwprintf_p (
   const wchar_t *format,
   va_list argptr
);
int _vscwprintf_p _l(
   const wchar_t *format,
   locale_t locale,
   va_list argptr
);
```

### <a name="parameters"></a>Parâmetros

*format*<br/>
Cadeia de caracteres de controle de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor de retorno

**vscprintf_p** retorna o número de caracteres que será gerado se a cadeia de caracteres apontada pela lista de argumentos foi impresso ou enviado para um arquivo ou os códigos de buffer usando a formatação especificada. O valor retornado não inclui o caractere nulo de terminação. **vscwprintf_p** executa a mesma função para caracteres largos.

## <a name="remarks"></a>Comentários

Essas funções são diferentes de **vscprintf** e **vscwprintf** apenas se eles oferecem suporte a capacidade de especificar a ordem em que os argumentos são usados. Para obter mais informações, consulte [Parâmetros posicionais printf_p](../../c-runtime-library/printf-p-positional-parameters.md).

As versões dessas funções com o **_l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.

Se *formato* é um ponteiro nulo, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, retornam -1, as funções e defina **errno** para **EINVAL**.

> [!IMPORTANT]
> Certifique-se de que se *formato* é uma cadeia de caracteres definida pelo usuário, ele é terminado em null e tem o número correto e o tipo de parâmetros. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**vsctprintf_p**|**_vscprintf_p**|**_vscprintf_p**|**_vscwprintf_p**|
|**vsctprintf_p_l**|**_vscprintf_p_l**|**_vscprintf_p_l**|**_vscwprintf_p_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**vscprintf_p**, **vscprintf_p_l**|\<stdio.h>|
|**vscwprintf_p**, **vscwprintf_p_l**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [vsprintf](vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md).

## <a name="see-also"></a>Consulte também

[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[_scprintf_p, _scprintf_p_l, _scwprintf_p, _scwprintf_p_l](scprintf-p-scprintf-p-l-scwprintf-p-scwprintf-p-l.md)<br/>
[_vscprintf, _vscprintf_l, _vscwprintf, _vscwprintf_l](vscprintf-vscprintf-l-vscwprintf-vscwprintf-l.md)<br/>
