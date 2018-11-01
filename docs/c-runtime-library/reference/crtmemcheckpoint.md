---
title: _CrtMemCheckpoint
ms.date: 11/04/2016
apiname:
- _CrtMemCheckpoint
apilocation:
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
apitype: DLLExport
f1_keywords:
- CrtMemCheckpoint
- _CrtMemCheckpoint
- crtdbg/_CrtMemCheckpoint
helpviewer_keywords:
- CrtMemCheckpoint function
- _CrtMemCheckpoint function
ms.assetid: f1bacbaa-5a0c-498a-ac7a-b6131d83dfbc
ms.openlocfilehash: ee435ba3e9e40795280dee0f97feaad32c8b0fc3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50589498"
---
# <a name="crtmemcheckpoint"></a>_CrtMemCheckpoint

Obtém o estado atual do heap de depuração e armazena em um aplicativo fornecido pelo **crtmemstate** estrutura (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtMemCheckpoint(
   _CrtMemState *state
);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Ponteiro para **crtmemstate** estrutura a ser preenchido com o ponto de verificação de memória.

## <a name="remarks"></a>Comentários

O **crtmemcheckpoint** função cria um instantâneo do estado atual do heap de depuração em um determinado momento. Esse instantâneo pode ser usado por outras funções de estado de heap como [_CrtMemDifference](crtmemdifference.md) para ajudar a detectar perdas de memória e outros problemas. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtmemstate** são removidas durante o pré-processamento.

O aplicativo deve passar um ponteiro para uma instância previamente alocada dos **crtmemstate** estrutura, definida em crtdbg. h, nas *estado* parâmetro. Se **crtmemcheckpoint** encontrar um erro durante a criação do ponto de verificação, a função gera uma **_CRT_WARN** depurar relatório descrevendo o problema.

Para obter mais informações sobre as funções de estado de heap e o **crtmemstate** estrutura, consulte [funções de relatório de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

Se *estado* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como **EINVAL** e a função retorna.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtMemCheckpoint**|\<crtdbg.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração do UCRT.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtMemDifference](crtmemdifference.md)<br/>
