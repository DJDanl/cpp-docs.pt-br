---
title: _ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _ismbcl2
- _ismbcl1
- _ismbcl0
- _ismbcl2_l
- _ismbcl1_l
- _ismbcl0_l
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
- ismbcl0
- _ismbcl1_l
- _ismbcl0
- ismbcl1
- ismbcl0_l
- _ismbcl2_l
- ismbcl2
- ismbcl1_l
- _ismbcl1
- _ismbcl0_l
- _ismbcl2
- ismbcl2_l
dev_langs:
- C++
helpviewer_keywords:
- _ismbcl0_l function
- _ismbcl2 function
- _ismbcl1_l function
- ismbcl2 function
- _ismbcl1 function
- ismbcl0_l function
- ismbcl2_l function
- ismbcl1_l function
- ismbcl0 function
- ismbcl1 function
- _ismbcl2_l function
- _ismbcl0 function
ms.assetid: ee15ebd1-462c-4a43-95f3-6735836d626a
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4cbca36f0b396bd0623fee3a4039c20cee3d367c
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ismbcl0-ismbcl0l-ismbcl1-ismbcl1l-ismbcl2-ismbcl2l"></a>_ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l

**Funções específicas da página de código 932**, usando a localidade atual ou uma categoria de estado de conversão LC_CTYPE especificada.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _ismbcl0(
   unsigned int c
);
int _ismbcl0_l(
   unsigned int c,
   _locale_t locale
);
int _ismbcl1(
   unsigned int c
);
int _ismbcl1_l(
   unsigned int c ,
   _locale_t locale
);
int _ismbcl2(
   unsigned int c
);
int _ismbcl2_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Caractere a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas retornará um valor diferente de zero se o caractere satisfizer a condição de teste ou 0 se não satisfizer. Se *c* < = 255 e há um correspondente **ismbb** rotina (por exemplo, **ismbcalnum** corresponde à **ismbbalnum**), o resultado é o valor de retorno do **ismbb** rotina.

## <a name="remarks"></a>Comentários

Cada uma dessas funções testa um determinado caractere multibyte quanto a uma determinada condição.

O valor de saída é afetado pela configuração do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

|Rotina|Condição de teste (página de código 932 somente)|
|-------------|-------------------------------------------|
|**_ismbcl0**|JIS Kanji não: 0x8140 < =*c*< = 0x889E.|
|**_ismbcl0_l**|JIS Kanji não: 0x8140 < =*c*< = 0x889E.|
|**_ismbcl1**|Nível 1 JIS: 0x889F < =*c*< = 0x9872.|
|**_ismbcl1_l**|Nível 1 JIS: 0x889F < =*c*< = 0x9872.|
|**_ismbcl2**|Nível 2 JIS: 0x989F < =*c*< = 0xEAA4.|
|**_ismbcl2_l**|Nível 2 JIS: 0x989F < =*c*< = 0xEAA4.|

As funções de verificam que o valor especificado *c* correspondências as condições de teste descrito acima, mas não verificam que *c* é um caractere de multibyte válido. Se o byte inferior estiver nos intervalos 0x00 – 0x3F, 0x7F ou 0xFD – 0xFF, essas funções retornarão um valor diferente de zero, indicando que o caractere satisfaz a condição de teste. Use [_ismbbtrail](ismbbtrail-ismbbtrail-l.md) para testar se o caractere multibyte foi definido.

**Final específico da página de código 932**

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbcl0**|\<mbstring.h>|
|**_ismbcl0_l**|\<mbstring.h>|
|**_ismbcl1**|\<mbstring.h>|
|**_ismbcl1_l**|\<mbstring.h>|
|**_ismbcl2**|\<mbstring.h>|
|**_ismbcl2_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
