---
title: _aligned_offset_realloc_dbg
ms.date: 11/04/2016
apiname:
- _aligned_offset_realloc_dbg
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
- aligned_offset_realloc_dbg
- _aligned_offset_realloc_dbg
helpviewer_keywords:
- aligned_offset_realloc_dbg function
- _aligned_offset_realloc_dbg function
ms.assetid: 64e30a12-887e-453b-aea8-aed793fca9d8
ms.openlocfilehash: 7684a752f489eb726b2105b1055b6da1e86e9cd1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62341568"
---
# <a name="alignedoffsetreallocdbg"></a>_aligned_offset_realloc_dbg

Altera o tamanho de um bloco de memória alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md) (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_offset_realloc_dbg(
   void *memblock,
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

*size*<br/>
O tamanho da alocação de memória.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a **aligned_offset_realloc** operação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que o **aligned_offset_realloc** operação foi solicitada ou **nulo**.

## <a name="return-value"></a>Valor de retorno

**aligned_offset_realloc_dbg** retorna um ponteiro nulo para o bloco de memória realocado (e possivelmente migrado). O valor retornado será **nulo** se o tamanho é zero e o argumento do buffer não está **nulo**, ou se não houver memória suficiente disponível para expandir o bloco para determinado tamanho. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

## <a name="remarks"></a>Comentários

**aligned_offset_realloc_dbg** é uma versão de depuração de [aligned_offset_realloc](aligned-offset-realloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **aligned_offset_realloc_dbg** é reduzida a uma chamada para **aligned_offset_realloc**. Ambos **aligned_offset_realloc** e **aligned_offset_realloc_dbg** realocam um bloco de memória no heap de base, mas **aligned_offset_realloc_dbg** acomoda vários recursos de depuração: buffers nos dois lados da parte do usuário do bloco para testar se há perdas, e *filename*/*linenumber* informações para determinar a origem do solicitações de alocação. Tipos de alocação específicos com um parâmetro de tipo de bloco de controle não é um recurso de depuração com suporte para alocações alinhados. Alocações alinhadas serão exibido como um tipo de bloco normal_block.

Como o [aligned_offset_malloc](aligned-offset-malloc.md), **aligned_offset_realloc_dbg** permite que uma estrutura seja alinhada em um deslocamento dentro da estrutura.

**realloc_dbg** realoca o bloco de memória especificado com um pouco mais de espaço que o solicitado *newSize*. *newSize* pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. Se o bloco de memória for movido, o conteúdo do bloco original será substituído.

Essa função definirá **errno** à **ENOMEM** se a alocação de memória tiver falhado ou se o tamanho solicitado for maior **heap_maxreq**. Para obter mais informações sobre **errno**, consulte [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **aligned_offset_realloc_dbg** valida seus parâmetros. Se *alinhamento* não for uma potência de 2 ou se *deslocamento* é maior que ou igual a *tamanho* e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito na [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_realloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
