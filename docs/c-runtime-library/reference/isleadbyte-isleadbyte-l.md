---
title: isleadbyte, _isleadbyte_l
ms.date: 11/04/2016
apiname:
- _isleadbyte_l
- isleadbyte
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
- _istleadbyte
- _isleadbyte_l
- isleadbyte
helpviewer_keywords:
- lead bytes
- _isleadbyte_l function
- _istleadbyte function
- istleadbyte function
- isleadbyte function
ms.assetid: 3b2bcf09-d82b-4803-9e80-59d04942802a
ms.openlocfilehash: 1a3f427e49e53bb553020da100b0e713350fab3f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531883"
---
# <a name="isleadbyte-isleadbytel"></a>isleadbyte, _isleadbyte_l

Determina se um caractere é o byte inicial de um caractere multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int isleadbyte( int c );
int _isleadbyte_l( int c );
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor de retorno

**isleadbyte** retorna um valor diferente de zero se o argumento satisfaz a condição de teste ou 0 se não existir. Na localidade "C" e em um byte do conjunto de caracteres localidades (SBCS), **isleadbyte** sempre retorna 0.

## <a name="remarks"></a>Comentários

O **isleadbyte** macro retorna um valor diferente de zero se o argumento for o primeiro byte de um caractere multibyte. **isleadbyte** produz um resultado significativo para qualquer argumento inteiro de -1 (**EOF**) para **UCHAR_MAX** (0xFF), inclusivo.

O tipo de argumento esperado de **isleadbyte** é **int**; se um caractere com sinal for passado, o compilador poderá convertê-la em um inteiro pela extensão de sinal, gerando resultados imprevisíveis.

A versão dessa função com o **l** sufixo é idêntico, exceto que ele usa a localidade passada em vez da localidade atual para o seu comportamento dependente da localidade.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**istleadbyte**|Sempre retorna falso|**_isleadbyte**|Sempre retorna falso|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isleadbyte**|\<ctype.h>|
|**_isleadbyte_l**|\<ctype.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
