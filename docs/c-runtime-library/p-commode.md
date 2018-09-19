---
title: __p__commode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- __p__commode
apilocation:
- msvcr110.dll
- msvcrt.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __p__commode
dev_langs:
- C++
helpviewer_keywords:
- __p__commode
ms.assetid: 4380acb8-e3e4-409c-a60f-6205ac5189ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5f610b26c79201f3431b6263a002b59df7456cfe
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46082437"
---
# <a name="pcommode"></a>__p__commode

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