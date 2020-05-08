---
title: isascii, __isascii, iswascii
ms.date: 4/2/2020
api_name:
- iswascii
- __isascii
- _o_iswascii
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
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- iswascii
- istascii
- __isascii
- _istascii
- isascii
- ctype/isascii
- ctype/__isascii
- corecrt_wctype/iswascii
helpviewer_keywords:
- __isascii function
- _isascii function
- isascii function
- _istascii function
- istascii function
- iswascii function
ms.assetid: ba4325ad-7cb3-4fb9-b096-58906d67971a
ms.openlocfilehash: 3e04b85c9ce7519593802c21311315d534dce6a5
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919784"
---
# <a name="isascii-__isascii-iswascii"></a>isascii, __isascii, iswascii

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

*&*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retornará zero se **c** for uma representação específica de um caractere ASCII. **__isascii** retornará um valor diferente de zero se **c** for um caractere ASCII (no intervalo 0x00-0x7f). **iswascii** retornará um valor diferente de zero se **c** for uma representação de caractere largo de um caractere ASCII. Cada uma dessas rotinas retornará 0 se **c** não atender à condição de teste.

## <a name="remarks"></a>Comentários

Tanto **__isascii** quanto **iswascii** são implementadas como macros, a menos que a macro de pré-processador _CTYPE_DISABLE_MACROS seja definida.

Para compatibilidade com versões anteriores, **isascii** é implementado como uma macro somente se [&#95;&#95;stdc&#95;&#95;](../../preprocessor/predefined-macros.md) não estiver definido ou definido como 0; caso contrário, ele será indefinido.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_istascii**|**__isascii**|**__isascii**|**iswascii**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isascii**, **__isascii**|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|
|**iswascii**|C: \<wctype.h>, \<ctype.h> ou \<wchar.h><br /><br /> C++: \<cwctype>, \<cctype>, \<wctype.h>, \<ctype.h> ou \<wchar.h>|

As funções **isascii**, **__isascii** e **iswascii** são específicas da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
