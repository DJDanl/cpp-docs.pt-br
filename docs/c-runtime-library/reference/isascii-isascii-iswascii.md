---
title: isascii, __isascii, iswascii | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- iswascii
- __isascii
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- iswascii
- istascii
- __isascii
- _istascii
- isascii
- ctype/isascii
- ctype/__isascii
- corecrt_wctype/iswascii
dev_langs:
- C++
helpviewer_keywords:
- __isascii function
- _isascii function
- isascii function
- _istascii function
- istascii function
- iswascii function
ms.assetid: ba4325ad-7cb3-4fb9-b096-58906d67971a
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4876ad6e206894fb55c3f4279e80bd55886d415d
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="isascii-isascii-iswascii"></a>isascii, __isascii, iswascii

Determina se um dado caractere é um caractere ASCII.

## <a name="syntax"></a>Sintaxe

```C
int __isascii(
   int c
);
int iswascii(
   wint_t c
);

#define isascii __isascii
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor de retorno

Cada essas rotinas retornará zero se **c** é uma representação específica de um caractere ASCII. **isascii** retorna um valor diferente de zero se **c** é um caractere ASCII (no intervalo 0x00 - 0x7F). **iswascii** retorna um valor diferente de zero se **c** é uma representação de caractere largo de um caractere ASCII. Cada uma dessas rotinas retornará 0 se **c** não satisfaz a condição de teste.

## <a name="remarks"></a>Comentários

Ambos **isascii** e **iswascii** são implementados como macros, a menos que o macro pré-processador _CTYPE_DISABLE_MACROS está definido.

Para compatibilidade com versões anteriores, **isascii** é implementado como uma macro somente [ &#95; &#95;STDC&#95; &#95; ](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, será indefinido.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**istascii**|**__isascii**|**__isascii**|**iswascii**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isascii**, **isascii**|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|
|**iswascii**|C: \<wctype.h>, \<ctype.h> ou \<wchar.h><br /><br /> C++: \<cwctype>, \<cctype>, \<wctype.h>, \<ctype.h> ou \<wchar.h>|

O **isascii**, **isascii** e **iswascii** funções são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
