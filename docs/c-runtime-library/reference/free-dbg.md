---
title: _free_dbg
ms.date: 11/04/2016
apiname:
- _free_dbg
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
- _free_dbg
- free_dbg
helpviewer_keywords:
- memory blocks, deallocating
- freeing memory
- _free_dbg function
- free_dbg function
ms.assetid: fc5e8299-616d-48a0-b979-e037117278c6
ms.openlocfilehash: 5a0024101e4f5a74f1573b271d444b27738db8e1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50442232"
---
# <a name="freedbg"></a>_free_dbg

Libera um bloco de memória no heap (somente a versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _free_dbg(
   void *userData,
   int blockType
);
```

### <a name="parameters"></a>Parâmetros

*dados do usuário*<br/>
Ponteiro para o bloco de memória alocado a ser liberado.

*blockType*<br/>
Tipo de bloco de memória alocado a ser liberado: **client_block**, **normal_block**, ou **ignore_block**.

## <a name="remarks"></a>Comentários

O **free_dbg** função é uma versão de depuração de [livre](free.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **free_dbg** é reduzida a uma chamada para **livre**. Ambos **livre** e **free_dbg** liberam um bloco de memória no heap de base, mas **free_dbg** acomoda dois recursos de depuração: a capacidade de manter liberados blocos no heap de lista vinculada para simular condições de memória insuficiente e um parâmetro de tipo de bloco para liberar tipos específicos de alocação.

**free_dbg** realiza uma verificação de validade em todos os arquivos especificados e locais de bloco antes de executar a operação livre. O aplicativo não deve fornecer essas informações. Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição. Se o **crtdbg_delay_free_mem_df** campo de bits a [crtdbgflag](../../c-runtime-library/crtdbgflag.md) sinalizador estiver definido, o bloco liberado é preenchido com o valor 0xDD, atribuído a **free_block** tipo, de bloco e mantidos na lista vinculada do heap de blocos de memória.

Se ocorrer um erro liberar a memória **errno** é definido com informações do sistema operacional da natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_free_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **free_dbg**, consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_malloc_dbg](malloc-dbg.md)<br/>
