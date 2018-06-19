---
title: isgraph, iswgraph, _isgraph_l, _iswgraph_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- isgraph
- iswgraph
- _iswgraph_l
- _isgraph_l
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
- _isgraph_l
- _iswgraph_l
- _ismbcgraph_l
- Isgraph
- _istgraph_l
- _istgraph
- iswgraph
dev_langs:
- C++
helpviewer_keywords:
- isgraph function
- _istgraph_l function
- istgraph function
- _isgraph_l function
- iswgraph function
- _iswgraph_l function
- _istgraph function
- _ismbcgraph_l function
ms.assetid: 531a5f34-4302-4d0a-8a4f-b7ea150ad941
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b60e022471bdfa7cbbddb6b5263f757438572a2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32401266"
---
# <a name="isgraph-iswgraph-isgraphl-iswgraphl"></a>isgraph, iswgraph, _isgraph_l, _iswgraph_l

Determina se um inteiro representa um caractere gráfico.

## <a name="syntax"></a>Sintaxe

```C
int isgraph(
   int c
);
int iswgraph(
   wint_t c
);
int _isgraph_l(
   int c,
   _locale_t locale
);
int _iswgraph_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor de retorno

Cada essas rotinas retornará zero se *c* é uma representação específica de um caractere imprimível que não seja um espaço. **isgraph** retorna um valor diferente de zero se *c* é um caractere imprimível que não seja um espaço. **iswgraph** retorna um valor diferente de zero se *c* é um caractere largo imprimível além do espaço de um caractere largo. Cada uma dessas rotinas retornará 0 se *c* não satisfaz a condição de teste.

As versões dessas funções que têm o **_l** sufixo usam a localidade que é transmitida em vez da localidade atual para o comportamento dependente de localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **isgraph** e **isgraph_l** será indefinido se *c* não é EOF ou no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e *c* não é uma desses valores, o aumento de funções uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**istgraph**|**isgraph**|[_ismbcgraph](ismbcgraph-functions.md)|**iswgraph**|
|**istgraph_l**|**_isgraph_l**|[_ismbcgraph_l](ismbcgraph-functions.md)|**_iswgraph_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isgraph**|\<ctype.h>|
|**iswgraph**|\<ctype.h> ou \<wchar.h>|
|**_isgraph_l**|\<ctype.h>|
|**_iswgraph_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
