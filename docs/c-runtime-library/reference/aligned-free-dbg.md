---
title: _aligned_free_dbg
ms.date: 11/04/2016
api_name:
- _aligned_free_dbg
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _aligned_free_dbg
- aligned_free_dbg
helpviewer_keywords:
- _aligned_free_dbg function
- aligned_free_dbg function
ms.assetid: eb0cb3c8-0992-4db8-bac3-65f1b8311ca6
ms.openlocfilehash: b510d16b6e784202094bb05e6364f7af1b1fff97
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939913"
---
# <a name="_aligned_free_dbg"></a>_aligned_free_dbg

Libera um bloco de memória que foi alocado com [aligned_malloc](aligned-malloc.md) ou [aligned_offset_malloc](aligned-offset-malloc.md) (somente depuração).

## <a name="syntax"></a>Sintaxe

```C
void _aligned_free_dbg(
   void *memblock
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Um ponteiro para o bloco de memória que foi retornado para a função [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md) .

## <a name="remarks"></a>Comentários

A função **_aligned_free_dbg** é uma versão de depuração da função [_aligned_free](aligned-free.md) . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, cada chamada para **_aligned_free_dbg** é reduzida para uma chamada para `_aligned_free`. Tanto `_aligned_free` o quanto o **_aligned_free_dbg** livres de um bloco de memória no heap base, mas o **_aligned_free_dbg** acomoda um recurso de depuração: a capacidade de manter os blocos liberados na lista vinculada do heap para simular condições de memória insuficiente.

o **_aligned_free_dbg** executa uma verificação de validade em todos os arquivos especificados e locais de bloco antes de executar a operação gratuita. O aplicativo não deve fornecer essas informações. Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição. Se o campo _CRTDBG_DELAY_FREE_MEM_DF bit do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) for definido, o bloco liberado será preenchido com o valor 0xDD, atribuído o tipo de bloco _FREE_BLOCK e mantido na lista vinculada de blocos de memória do heap.

Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_free_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)