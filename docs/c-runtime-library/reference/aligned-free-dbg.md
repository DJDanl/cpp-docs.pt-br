---
title: _aligned_free_dbg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _aligned_free_dbg
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
- _aligned_free_dbg
- aligned_free_dbg
dev_langs:
- C++
helpviewer_keywords:
- _aligned_free_dbg function
- aligned_free_dbg function
ms.assetid: eb0cb3c8-0992-4db8-bac3-65f1b8311ca6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 34009ac94d35a377e1080ea674f58715e7a42aa2
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44101048"
---
# <a name="alignedfreedbg"></a>_aligned_free_dbg

Libera um bloco de memória que foi alocado com [aligned_malloc](aligned-malloc.md) ou [aligned_offset_malloc](aligned-offset-malloc.md) (somente depuração).

## <a name="syntax"></a>Sintaxe

```C
void _aligned_free_dbg(
   void *memblock
);
```

### <a name="parameters"></a>Parâmetros

*memblock*  
Um ponteiro para o bloco de memória que foi retornado para o [aligned_malloc](aligned-malloc.md) ou [aligned_offset_malloc](aligned-offset-malloc.md) função.

## <a name="remarks"></a>Comentários

O **aligned_free_dbg** função é uma versão de depuração de [aligned_free](aligned-free.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **aligned_free_dbg** é reduzida a uma chamada para `_aligned_free`. Ambos `_aligned_free` e **aligned_free_dbg** liberam um bloco de memória no heap de base, mas **aligned_free_dbg** acomoda um recurso de depuração: a capacidade de manter liberados blocos na lista vinculada do heap para Simule condições de memória insuficiente.

**aligned_free_dbg** realiza uma verificação de validade em todos os arquivos especificados e locais de bloco antes de executar a operação livre. O aplicativo não deve fornecer essas informações. Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição. Se o crtdbg_delay_free_mem_df de campo de bits de [crtdbgflag](../../c-runtime-library/crtdbgflag.md) sinalizador estiver definido, o bloco liberado é preenchido com o valor 0xDD, atribuído o tipo de bloco free_block e mantido na lista vinculada do heap de blocos de memória.

Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_free_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)  