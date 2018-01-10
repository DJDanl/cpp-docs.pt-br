---
title: isascii, __isascii, iswascii | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs: C++
helpviewer_keywords:
- __isascii function
- _isascii function
- isascii function
- _istascii function
- istascii function
- iswascii function
ms.assetid: ba4325ad-7cb3-4fb9-b096-58906d67971a
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3858955a1409842d80439401d6c689c06f6c86f3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

*c*  
Inteiro a ser testado.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas retornará um valor diferente de zero se `c` for uma representação específica de um caractere ASCII. `__isascii`Retorna um valor diferente de zero se `c` é um caractere ASCII (no intervalo 0x00 - 0x7F). `iswascii` retornará um valor diferente de zero se `c` for uma representação de caractere largo de um caractere ASCII. Cada uma dessas rotinas retornará 0 se `c` não satisfizer a condição de teste.

## <a name="remarks"></a>Comentários

`__isascii` e `iswascii` são implementados como macros, a menos que a macro do pré-processador _CTYPE_DISABLE_MACROS esteja definida.

Para compatibilidade com versões anteriores, `isascii` é implementado como uma macro somente [&#95; &#95; STDC #95; &#95; ](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, será indefinido.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|`_istascii`|`__isascii`|`__isascii`|`iswascii`|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`isascii`, `__isascii`|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|
|`iswascii`|C: \<wctype.h>, \<ctype.h> ou \<wchar.h><br /><br /> C++: \<cwctype>, \<cctype>, \<wctype.h>, \<ctype.h> ou \<wchar.h>|

As funções `isascii`, `__isascii` e `iswascii` são específicas da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)   
[Localidade](../../c-runtime-library/locale.md)   
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)