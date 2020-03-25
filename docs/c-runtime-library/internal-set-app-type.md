---
title: __set_app_type
ms.date: 11/04/2016
api_name:
- __set_app_type
- _set_app_type
api_location:
- msvcr90.dll
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
- msvcrt.dll
- msvcr120.dll
- msvcr110_clr0400.dll
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __set_app_type
helpviewer_keywords:
- __set_app_type
ms.assetid: f0ac0f4d-70e6-4e96-9e43-eb9d1515490c
ms.openlocfilehash: 8efe2159618f728cfaad33493dd482fbdd5375f7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171483"
---
# <a name="__set_app_type"></a>__set_app_type

Define o tipo de aplicativo atual.

## <a name="syntax"></a>Sintaxe

```cpp
void __set_app_type (
   int at
   )
```

#### <a name="parameters"></a>parâmetros

*at*<br/>
Um valor que indica o tipo de aplicativo. Os valores possíveis são:

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|_UNKNOWN_APP|Tipo de aplicativo desconhecido.|
|_CONSOLE_APP|Aplicativo de console (linha de comando).|
|_GUI_APP|Aplicativo GUI (Windows).|

## <a name="remarks"></a>Comentários

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__set_app_type|internal.h|
