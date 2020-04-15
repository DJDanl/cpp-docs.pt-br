---
title: _unlock_file
ms.date: 4/2/2020
api_name:
- _unlock_file
- _o__unlock_file
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-filesystem-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _unlock_file
- unlock_file
helpviewer_keywords:
- files [C++], unlocking
- unlock_file function
- _unlock_file function
- unlocking files
ms.assetid: cf380a51-6d3a-4f38-bd64-2d4fb57b4369
ms.openlocfilehash: 46d07a8b3645ae0d68276d96271be0a246716f0b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361214"
---
# <a name="_unlock_file"></a>_unlock_file

Desbloqueia um arquivo, permitindo que outros processos acessem o arquivo.

## <a name="syntax"></a>Sintaxe

```C
void _unlock_file(
   FILE* file
);
```

### <a name="parameters"></a>Parâmetros

*Arquivo*<br/>
Identificador de arquivo.

## <a name="remarks"></a>Comentários

A função **_unlock_file** desbloqueia o arquivo especificado pelo *arquivo*. Desbloquear um arquivo permite o acesso ao arquivo por outros processos. Esta função não deve ser chamada a menos que **_lock_file** tenha sido previamente chamado no ponteiro do *arquivo.* Chamar **_unlock_file** em um arquivo que não está bloqueado pode resultar em um impasse. Para um exemplo, consulte [_lock_file](lock-file.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_unlock_file**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_lock_file](lock-file.md)<br/>
