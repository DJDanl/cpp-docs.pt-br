---
title: __p__fmode
ms.date: 11/04/2016
api_name:
- __p__fmode
api_location:
- msvcr80.dll
- msvcr120.dll
- msvcr90.dll
- msvcrt.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __p__fmode
helpviewer_keywords:
- __p__fmode
ms.assetid: 1daa1394-81eb-43aa-a71b-4cc6acf3207b
ms.openlocfilehash: 6f7676fc5c9958be3d0567e6bf22a11367094150
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939978"
---
# <a name="__p__fmode"></a>__p__fmode

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