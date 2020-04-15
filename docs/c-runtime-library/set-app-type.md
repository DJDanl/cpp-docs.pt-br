---
title: _set_app_type
ms.date: 4/2/2020
api_name:
- _set_app_type
- _o__set_app_type
api_location:
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _set_app_type
- corecrt_startup/_set_app_type
ms.assetid: 1e7fe786-b587-4116-8c05-f7d762350100
ms.openlocfilehash: 9791cff55ccd55c32d124ab89cc43ab54c0f9c69
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360966"
---
# <a name="_set_app_type"></a>_set_app_type

Uma função interna usada na inicialização para informar ao CRT se o aplicativo é um aplicativo de console ou um aplicativo GUI.

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum _crt_app_type
{
    _crt_unknown_app,
    _crt_console_app,
    _crt_gui_app
} _crt_app_type;

void __cdecl _set_app_type(
    _crt_app_type appType
    );
```

## <a name="parameters"></a>Parâmetros

*appType*<br/>
Um valor que indica o tipo de aplicativo. Os valores possíveis são:

|Valor|Descrição|
|----------------|-----------------|
|_crt_unknown_app|Tipo de aplicativo desconhecido.|
|_crt_console_app|Aplicativo de console (linha de comando).|
|_crt_gui_app|Aplicativo GUI (Windows).|

## <a name="remarks"></a>Comentários

Normalmente, você não precisa chamar essa função. Ela faz parte do código de inicialização em runtime C que é executado antes de `main` ser chamado em seu aplicativo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_set_app_type|process.h|
