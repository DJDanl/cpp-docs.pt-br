---
title: _free_dbg
ms.date: 11/04/2016
api_name:
- _free_dbg
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
- _free_dbg
- free_dbg
helpviewer_keywords:
- memory blocks, deallocating
- freeing memory
- _free_dbg function
- free_dbg function
ms.assetid: fc5e8299-616d-48a0-b979-e037117278c6
ms.openlocfilehash: 43591ce8710dd25ad33832a5f084ca6e84bba979
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70956801"
---
# <a name="_free_dbg"></a>_free_dbg

Libera um bloco de memória no heap (somente a versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _free_dbg(
   void *userData,
   int blockType
);
```

### <a name="parameters"></a>Parâmetros

*userData*<br/>
Ponteiro para o bloco de memória alocado a ser liberado.

*blockType*<br/>
Tipo de bloco de memória alocado a ser liberado: **_CLIENT_BLOCK**, **_NORMAL_BLOCK**ou **_IGNORE_BLOCK**.

## <a name="remarks"></a>Comentários

A função **_free_dbg** é uma versão de depuração da função [gratuita](free.md) . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, cada chamada para **_free_dbg** é reduzida para uma chamada para **Free**. **Gratuitamente** e **_free_dbg** liberar um bloco de memória no heap base, mas o **_free_dbg** acomoda dois recursos de depuração: a capacidade de manter os blocos liberados na lista vinculada do heap para simular condições de memória insuficiente e um parâmetro de tipo de bloco para tipos de alocação específicos gratuitos.

o **_free_dbg** executa uma verificação de validade em todos os arquivos especificados e locais de bloco antes de executar a operação gratuita. O aplicativo não deve fornecer essas informações. Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição. Se o campo **_CRTDBG_DELAY_FREE_MEM_DF** bit do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) for definido, o bloco liberado será preenchido com o valor 0xDD, atribuído o tipo de bloco **_FREE_BLOCK** e mantido na lista vinculada de blocos de memória do heap.

Se ocorrer um erro na liberação da memória, **errno** será definido com informações do sistema operacional na natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_free_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar o **_free_dbg**, consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_malloc_dbg](malloc-dbg.md)<br/>
