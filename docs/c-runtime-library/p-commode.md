---
title: __p__commode
ms.date: 11/04/2016
api_name:
- __p__commode
api_location:
- msvcr110.dll
- msvcrt.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __p__commode
helpviewer_keywords:
- __p__commode
ms.assetid: 4380acb8-e3e4-409c-a60f-6205ac5189ce
ms.openlocfilehash: e3121c127c3ebf0f5fccdeb7ae0f67d0164d0965
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171470"
---
# <a name="__p__commode"></a>__p__commode

Aponta para a variável global `_commode`, que especifica o *modo de confirmação de arquivos* padrão para operações de E/S de arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
int * __p__commode(
   );
```

## <a name="return-value"></a>Valor retornado

Ponteiro para a variável global `_commode`.

## <a name="remarks"></a>Comentários

A função `__p__commode` destina-se apenas ao uso interno e não deve ser chamada do código do usuário.

O modo de confirmação de arquivo especifica quando os dados críticos são gravados no disco. Para obter mais informações, consulte [fflush](../c-runtime-library/reference/fflush.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__p\__commode|internal.h|
