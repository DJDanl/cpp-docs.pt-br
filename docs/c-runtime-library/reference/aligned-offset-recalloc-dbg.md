---
title: _aligned_offset_recalloc_dbg
ms.date: 11/04/2016
apiname:
- _aligned_offset_recalloc_dbg
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
- aligned_offset_recalloc_dbg
- _aligned_offset_recalloc_dbg
helpviewer_keywords:
- aligned_offset_recalloc_dbg function
- _aligned_offset_recalloc_dbg function
ms.assetid: 7ab719c3-77e0-4d2e-934f-01529d062fbf
ms.openlocfilehash: 0b314b4aca080877b4e41723a8d2010fd8e835ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50627962"
---
# <a name="alignedoffsetrecallocdbg"></a>_aligned_offset_recalloc_dbg

Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md) e inicializa a memória como 0 (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_offset_recalloc_dbg(
   void *memblock,
   size_t num,
   size_t size,
   size_t alignment,
   size_t offset,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
O ponteiro do bloco de memória atual.

*número*<br/>
Número de elementos.

*size*<br/>
O comprimento, em bytes, de cada elemento.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de realloc ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de realloc foi solicitada ou **nulo**.

## <a name="return-value"></a>Valor de retorno

**aligned_offset_recalloc_dbg** retorna um ponteiro nulo para o bloco de memória realocado (e possivelmente migrado). O valor retornado será **nulo** se o tamanho é zero e o argumento do buffer não está **nulo**, ou se não houver memória suficiente disponível para expandir o bloco para determinado tamanho. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

## <a name="remarks"></a>Comentários

**aligned_offset_realloc_dbg** é uma versão de depuração de [aligned_offset_recalloc](aligned-offset-recalloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **aligned_offset_recalloc_dbg** é reduzida a uma chamada para **aligned_offset_recalloc**. Ambos **aligned_offset_recalloc** e **aligned_offset_recalloc_dbg** realocam um bloco de memória no heap de base, mas **aligned_offset_recalloc_dbg** acomoda vários recursos de depuração: buffers nos dois lados da parte do usuário do bloco para testar se há vazamentos, um parâmetro de tipo de bloco para rastrear tipos de alocação específicos e *filename*/*linenumber*  informações para determinar a origem das solicitações de alocação.

**aligned_offset_realloc_dbg** realoca o bloco de memória especificado com um pouco mais de espaço que o solicitado *newSize*. *newSize* pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. Se o bloco de memória for movido, o conteúdo do bloco original será substituído.

Essa função definirá **errno** à **ENOMEM** se a alocação de memória tiver falhado ou se o tamanho solicitado (*número* * *tamanho* ) era maior que **heap_maxreq**. Para obter mais informações sobre **errno**, consulte [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **aligned_offset_recalloc_dbg** valida seus parâmetros. Se *alinhamento* não for uma potência de 2 ou se *deslocamento* é maior que ou igual ao tamanho solicitado e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_recalloc_dbg**|\<malloc.h>|

## <a name="see-also"></a>Consulte também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
