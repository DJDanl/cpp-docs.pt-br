---
title: _unlock_file
ms.date: 11/04/2016
api_name:
- _unlock_file
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
ms.openlocfilehash: 2983408f066ea00c0b7ab111d9a6349700ecaece
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957484"
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

*file*<br/>
Identificador de arquivo.

## <a name="remarks"></a>Comentários

A função **_unlock_file** desbloqueia o arquivo especificado pelo *arquivo*. Desbloquear um arquivo permite o acesso ao arquivo por outros processos. Essa função não deve ser chamada a menos que **_lock_file** tenha sido chamado anteriormente no ponteiro do *arquivo* . Chamar **_unlock_file** em um arquivo que não está bloqueado pode resultar em um deadlock. Para um exemplo, consulte [_lock_file](lock-file.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_unlock_file**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_lock_file](lock-file.md)<br/>
