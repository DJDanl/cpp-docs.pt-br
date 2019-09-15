---
title: _aligned_offset_malloc_dbg
ms.date: 11/04/2016
api_name:
- _aligned_offset_malloc_dbg
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
- _aligned_offset_malloc_dbg
- aligned_offset_malloc_dbg
helpviewer_keywords:
- _aligned_offset_malloc_dbg function
- aligned_offset_malloc_dbg function
ms.assetid: 6c242307-c59e-4d63-aae5-d8cbec8e021c
ms.openlocfilehash: 4fbacb170fd1ae1ce92de4a11ea85ff42b3942a0
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939778"
---
# <a name="_aligned_offset_malloc_dbg"></a>_aligned_offset_malloc_dbg

Aloca memória em um limite de alinhamento especificado (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_offset_malloc_dbg(
   size_t size,
   size_t alignment,
   size_t offset,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Tamanho da alocação de memória solicitada.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nula**.

## <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que foi alocado ou **nulo** se a operação falhou.

## <a name="remarks"></a>Comentários

**_aligned_offset_malloc_dbg** é uma versão de depuração da função [_aligned_offset_malloc](aligned-offset-malloc.md) . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, cada chamada para **_aligned_offset_malloc_dbg** é reduzida para uma chamada para **_aligned_offset_malloc**. **_Aligned_offset_malloc** e **_aligned_offset_malloc_dbg** alocam um bloco de memória no heap base, mas o **_aligned_offset_malloc_dbg** oferece vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para teste para vazamentos e informações de *nome de arquivo*/*LineNumber* para determinar a origem das solicitações de alocação. O rastreamento de tipos de alocação específicos com um parâmetro de tipo de bloco não é um recurso de depuração com suporte para alocações alinhadas. As alocações alinhadas aparecerão como um tipo de bloco _NORMAL_BLOCK.

**_aligned_offset_malloc_dbg** aloca o bloco de memória com um pouco mais de espaço do que o *tamanho*solicitado. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.

**_aligned_offset_malloc_dbg** é útil em situações em que o alinhamento é necessário em um elemento aninhado; por exemplo, se o alinhamento fosse necessário em uma classe aninhada.

o **_aligned_offset_malloc_dbg** é baseado em **malloc**; para obter mais informações, consulte [malloc](malloc.md).

Essa função define **errno** como **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado era maior que **_HEAP_MAXREQ**. Para obter mais informações sobre **errno**, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, o **_aligned_offset_malloc** valida seus parâmetros. Se o *alinhamento* não for uma potência de 2 ou se o *deslocamento* for maior ou igual ao *tamanho* e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em validação de [parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função retornará **NULL** e definirá **errno** como **EINVAL**.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_malloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
