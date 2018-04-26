---
title: _ismbblead, _ismbblead_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _ismbblead_l
- _ismbblead
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- ismbblead_l
- istlead
- _ismbblead
- _ismbblead_l
- ismbblead
- _istlead
dev_langs:
- C++
helpviewer_keywords:
- _ismbblead_l function
- ismbblead function
- _ismbblead function
- istlead function
- ismbblead_l function
- _istlead function
ms.assetid: 2abc6f75-ed5c-472e-bfd0-e905a1835ccf
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7833abbe4a13a2c5f012926ffcca6befdc8b52ff
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ismbblead-ismbbleadl"></a>_ismbblead, _ismbblead_l

Testa um caractere para determinar se ele é um byte inicial ou um caractere multibyte.

## <a name="syntax"></a>Sintaxe

```C
int _ismbblead(
   unsigned int c
);
int _ismbblead_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se o número inteiro *c* é o primeiro byte de um caractere multibyte.

## <a name="remarks"></a>Comentários

Caracteres multibyte consistem em um byte inicial seguido de um byte à direita. Bytes iniciais são diferenciados por estarem em um intervalo específico de um determinado conjunto de caracteres. Por exemplo, em bytes de avanço, somente de código 932 da página variam de 0x81-0x9F e 0xE0 - 0xFC.

**ismbblead** usa a localidade atual para o comportamento dependente de localidade. **ismbblead_l** é idêntico, exceto que ele usa a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**istlead**|Sempre retorna falso|**_ismbblead**|Sempre retorna falso|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_ismbblead**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|
|**_ismbblead_l**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|

\* Para constantes de manifesto para as condições de teste.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
