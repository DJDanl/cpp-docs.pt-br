---
title: ___lc_codepage_func
ms.date: 4/2/2020
api_name:
- ___lc_codepage_func
- _o____lc_codepage_func
api_location:
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr80.dll
- msvcr100.dll
- msvcr90.dll
- msvcr110.dll
- msvcrt.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- lc_codepage_func
- ___lc_codepage_func
helpviewer_keywords:
- ___lc_codepage_func
ms.assetid: 6a663bd0-5a63-4a2f-9507-872ec1582aae
ms.openlocfilehash: 2f3eeb4611a0a41ff1782e0b162cd65d86d3ef65
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351228"
---
# <a name="___lc_codepage_func"></a>___lc_codepage_func

Função CRT interna. Recupera a página de código atual do thread.

## <a name="syntax"></a>Sintaxe

```cpp
UINT ___lc_codepage_func(void);
```

## <a name="return-value"></a>Valor retornado

A página de código atual do thread.

## <a name="remarks"></a>Comentários

`___lc_codepage_func` é uma função CRT interna usada por outras funções CRT para obter a página de código atual do armazenamento local do thread para os dados do CRT. Essas informações também estão disponíveis usando a função [_get_current_locale](../c-runtime-library/reference/get-current-locale.md).

Uma *página de código* é um mapeamento dos códigos de um ou dois bytes para caracteres individuais. Diferentes páginas de código contêm caracteres especiais diferentes, que geralmente são personalizados para um idioma ou um grupo de idiomas. Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).

Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão. Não recomendamos usá-las no seu código.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`___lc_codepage_func`|crt\src\setlocal.h|

## <a name="see-also"></a>Confira também

[_get_current_locale](../c-runtime-library/reference/get-current-locale.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)<br/>
[_free_locale](../c-runtime-library/reference/free-locale.md)
