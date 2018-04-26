---
title: _CrtMemCheckpoint | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CrtMemCheckpoint function
- _CrtMemCheckpoint function
ms.assetid: f1bacbaa-5a0c-498a-ac7a-b6131d83dfbc
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 80f9d0b88e5bf1195ca8097e4cfbab5ba97942d7
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*estado* ponteiro para **crtmemstate** estrutura para preencher com o ponto de verificação de memória.

## <a name="remarks"></a>Comentários

O **crtmemcheckpoint** função cria um instantâneo do estado atual do heap de depuração a qualquer momento. Esse instantâneo pode ser usado por outras funções de estado de heap como [_CrtMemDifference](crtmemdifference.md) para ajudar a detectar perdas de memória e outros problemas. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtmemstate** são removidos durante o pré-processamento.

O aplicativo deve transmitir um ponteiro para uma instância alocada anteriormente o **crtmemstate** estrutura, definida em crtdbg. h, no *estado* parâmetro. Se **crtmemcheckpoint** encontra um erro durante a criação do ponto de verificação, a função gera uma **_CRT_WARN** depurar relatório que descreve o problema.

Para obter mais informações sobre funções de estado de heap e a **crtmemstate** estrutura, consulte [funções de emissão de relatórios de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

Se *estado* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como **EINVAL** e a função retorna.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtMemCheckpoint**|\<crtdbg.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração do UCRT.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtMemDifference](crtmemdifference.md)<br/>
