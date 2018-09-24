---
title: _set_app_type | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: conceptual
apiname:
- _set_app_type
apilocation:
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _set_app_type
- corecrt_startup/_set_app_type
dev_langs:
- C++
ms.assetid: 1e7fe786-b587-4116-8c05-f7d762350100
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1b2ad7e22bf6ba366a33dd44ce49c1a384f88b87
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46041253"
---
# <a name="setapptype"></a>_set_app_type

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

Normalmente, você não precisa chamar essa função. Ela faz parte do código de inicialização em tempo de execução C que é executado antes de `main` ser chamado em seu aplicativo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_set_app_type|process.h|

