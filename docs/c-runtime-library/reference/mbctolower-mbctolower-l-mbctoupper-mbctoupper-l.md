---
title: _mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _mbctolower_l
- _mbctoupper_l
- _mbctoupper
- _mbctolower
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
- mbctoupper_l
- mbctolower_l
- _mbctolower
- _mbctolower_l
- _mbctoupper
- mbctoupper
- mbctolower
- _mbctoupper_l
dev_langs:
- C++
helpviewer_keywords:
- _mbctolower function
- mbctolower_l function
- totupper function
- _mbctoupper function
- totlower function
- _mbctoupper_l function
- mbctolower function
- _totupper function
- _mbctolower_l function
- mbctoupper_l function
- _totlower function
- mbctoupper function
ms.assetid: 787fab71-3224-4ed7-bc93-4dcd8023fc54
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1af1ae33d9f3b752ed58aaa7bd3dd3e22f7de8c2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32403655"
---
# <a name="mbctolower-mbctolowerl-mbctoupper-mbctoupperl"></a>_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l

Testa e converte o formato de maiúsculas e minúsculas de um caractere multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _mbctolower(
   unsigned int c
);
unsigned int _mbctolower_l(
   unsigned int c,
   _locale_t locale
);
unsigned int _mbctoupper(
   unsigned int c
);
unsigned int _mbctoupper_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Caracteres multibyte a serem convertidos.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna o caractere convertido *c*, se possível. Caso contrário, retorna o caractere *c* inalterado.

## <a name="remarks"></a>Comentários

As funções de testar um caractere *c* e, se possível, aplicar uma das conversões a seguir.

|Rotinas|Converte|
|--------------|--------------|
|**mbctolower**, **mbctolower_l**|Caracteres maiúsculos para caracteres minúsculos.|
|**mbctoupper**, **mbctoupper_l**|Caracteres minúsculos para caracteres maiúsculos.|

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. A versão dessa função sem o **_l** sufixo usa a localidade atual para este comportamento dependente de localidade; a versão com o **_l** sufixo é idêntico, exceto que ele usa o parâmetro de localidade passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Nas versões anteriores, **mbctolower** foi chamado **jtolower**, e **mbctoupper** foi chamado **jtoupper**. Para código novo, use os novos nomes.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**totlower**|**tolower**|**_mbctolower**|**towlower**|
|**_totlower_l**|**_tolower_l**|**_mbctolower_l**|**_towlower_t**|
|**totupper**|**toupper**|**_mbctoupper**|**towupper**|
|**_totupper_l**|**toupper_l**|**_mbctoupper_l**|**_towupper_l**|

## <a name="requirements"></a>Requisitos

|Rotinas|Cabeçalho necessário|
|--------------|---------------------|
|**mbctolower**, **mbctolower_l**|\<mbstring.h>|
|**mbctoupper**, **mbctoupper_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[_mbbtombc, _mbbtombc_l](mbbtombc-mbbtombc-l.md)<br/>
[_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l](mbcjistojms-mbcjistojms-l-mbcjmstojis-mbcjmstojis-l.md)<br/>
[_mbctohira, _mbctohira_l, _mbctokata, _mbctokata_l](mbctohira-mbctohira-l-mbctokata-mbctokata-l.md)<br/>
[_mbctombb, _mbctombb_l](mbctombb-mbctombb-l.md)<br/>
