---
title: __crtLCMapStringW
ms.date: 11/04/2016
apiname:
- __crtLCMapStringW
apilocation:
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcrt.dll
- msvcr120.dll
- msvcr110.dll
- msvcr80.dll
apitype: DLLExport
f1_keywords:
- __crtLCMapStringW
helpviewer_keywords:
- __crtLCMapStringW
ms.assetid: 45b4ac0e-438c-4fa3-b4d1-34195f4467d9
ms.openlocfilehash: 0c3752baba05e18903c32919505d702081d09dca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468413"
---
# <a name="crtlcmapstringw"></a>__crtLCMapStringW

Mapeia uma cadeia de caracteres para outra, executando a transformação dependente de localidade especificada. Essa função também pode ser usada para gerar uma chave de classificação para a cadeia de caracteres de entrada.

## <a name="syntax"></a>Sintaxe

```cpp
int __crtLCMapStringW(
   LCID    Locale,
   DWORD   dwMapFlags,
   LPCWSTR lpSrcStr,
   int     cchSrc,
   LPWSTR  lpDestStr,
   int     cchDest)
```

#### <a name="parameters"></a>Parâmetros

*Localidade*<br/>
Identificador de localidade. A localidade fornece um contexto para o mapeamento de cadeia de caracteres ou a geração de chaves de classificação. Um aplicativo pode usar a macro `MAKELCID` para criar um identificador de localidade.

*dwMapFlags*<br/>
O tipo de transformação a ser usado durante o mapeamento da cadeia de caracteres ou a geração da chave de classificação.

*lpSrcStr*<br/>
Ponteiro para uma cadeia de caracteres de origem que a função mapeia ou usa para geração de chave de classificação. Esse parâmetro é considerado uma cadeia de caracteres Unicode.

*cchSrc*<br/>
Tamanho, em caracteres, da cadeia de caracteres apontada pelo parâmetro `lpSrcStr`. Essa contagem pode incluir ou não o terminador nulo.

Um valor `cchSrc` de -1 especifica que a cadeia de caracteres apontada por `lpSrcStr` é terminada em nulo. Se esse for o caso, e essa função estiver sendo usada no modo de mapeamento de cadeia de caracteres, a função calcula o comprimento da cadeia de caracteres e termina em nulo a cadeia de caracteres mapeada armazenada em `*lpDestStr`.

*lpDestStr*<br/>
Ponteiro longo para um buffer em que a função armazena a cadeia de caracteres ou chave de classificação mapeada.

*cchDest*<br/>
Tamanho, em caracteres, do buffer apontado por `lpDestStr`.

## <a name="return-value"></a>Valor retornado

Se o valor de `cchDest` for diferente de zero, o número de caracteres, ou bytes, se `LCMAP_SORTKEY` for especificado, gravados no buffer indica êxito. Essa contagem inclui espaço para um terminador nulo.

Se o valor de `cchDest` for zero, o tamanho do buffer em caracteres, ou bytes, se `LCMAP_SORTKEY` for especificado, necessário para receber a cadeia de caracteres ou chave de classificação traduzida indica êxito. Esse tamanho inclui espaço para um terminador nulo.

Zero indica uma falha. Para obter outras informações sobre o erro, chame a função `GetLastError`.

## <a name="remarks"></a>Comentários

Se `cchSrc` for maior que zero e `lpSrcStr` for uma cadeia de caracteres terminada em nulo, `__crtLCMapStringW` define `cchSrc` para o comprimento da cadeia de caracteres. Em seguida, `__crtLCMapStringW` chama a versão de cadeia de caracteres larga (Unicode) da função `LCMapString` com os parâmetros especificados. Para obter mais informações sobre os parâmetros e o valor retornado dessa função, consulte [LCMapString](/windows/desktop/api/winnls/nf-winnls-lcmapstringa).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__crtLCMapStringW|awint.h|