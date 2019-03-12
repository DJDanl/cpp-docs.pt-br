---
title: ___lc_codepage_func
ms.date: 11/04/2016
apiname:
- ___lc_codepage_func
apilocation:
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr80.dll
- msvcr100.dll
- msvcr90.dll
- msvcr110.dll
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- lc_codepage_func
- ___lc_codepage_func
helpviewer_keywords:
- ___lc_codepage_func
ms.assetid: 6a663bd0-5a63-4a2f-9507-872ec1582aae
ms.openlocfilehash: aebd978839cc59c94c01e9c24432b69add72c4dc
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57751319"
---
# <a name="lccodepagefunc"></a>___lc_codepage_func

Função CRT interna. Recupera a página de código atual do thread.

## <a name="syntax"></a>Sintaxe

```cpp
UINT ___lc_codepage_func(void);
```

## <a name="return-value"></a>Valor de retorno

A página de código atual do thread.

## <a name="remarks"></a>Comentários

`___lc_codepage_func` é uma função CRT interna usada por outras funções CRT para obter a página de código atual do armazenamento local do thread para os dados do CRT. Essas informações também estão disponíveis usando a função [_get_current_locale](../c-runtime-library/reference/get-current-locale.md).

Uma *página de código* é um mapeamento dos códigos de um ou dois bytes para caracteres individuais. Diferentes páginas de código contêm caracteres especiais diferentes, que geralmente são personalizados para um idioma ou um grupo de idiomas. Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).

Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão. Não recomendamos usá-las no seu código.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`___lc_codepage_func`|crt\src\setlocal.h|

## <a name="see-also"></a>Consulte também

[_get_current_locale](../c-runtime-library/reference/get-current-locale.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)<br/>
[_free_locale](../c-runtime-library/reference/free-locale.md)
