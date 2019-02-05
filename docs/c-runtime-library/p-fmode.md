---
title: __p__fmode
ms.date: 11/04/2016
apiname:
- __p__fmode
apilocation:
- msvcr80.dll
- msvcr120.dll
- msvcr90.dll
- msvcrt.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __p__fmode
helpviewer_keywords:
- __p__fmode
ms.assetid: 1daa1394-81eb-43aa-a71b-4cc6acf3207b
ms.openlocfilehash: bdb390ef5ae7254c463a3abd66860559cebeeeb9
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55703045"
---
# <a name="pfmode"></a>__p__fmode

Aponta para a variável global `_fmode`, que especifica o *modo de translação de arquivos* padrão para operações de E/S de arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
int* __p__fmode(
   );
```

## <a name="return-value"></a>Valor de retorno

Ponteiro para a variável global `_fmode`.

## <a name="remarks"></a>Comentários

A função `__p__fmode` destina-se apenas ao uso interno e não deve ser chamada do código do usuário.

O modo de translação de arquivo especifica uma translação `binary` ou `text` para operações E/S [_open](../c-runtime-library/reference/open-wopen.md) e [_pipe](../c-runtime-library/reference/pipe.md). Para obter mais informações, consulte [_fmode](../c-runtime-library/fmode.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__p\__fmode|stdlib.h|