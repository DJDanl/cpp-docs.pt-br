---
title: _aligned_offset_malloc_dbg
ms.date: 11/04/2016
apiname:
- _aligned_offset_malloc_dbg
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
- _aligned_offset_malloc_dbg
- aligned_offset_malloc_dbg
helpviewer_keywords:
- _aligned_offset_malloc_dbg function
- aligned_offset_malloc_dbg function
ms.assetid: 6c242307-c59e-4d63-aae5-d8cbec8e021c
ms.openlocfilehash: 96fe9e7fda0d0cdfdbfa5462e4f601e3649e2233
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62348868"
---
# <a name="alignedoffsetmallocdbg"></a>_aligned_offset_malloc_dbg

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
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que foi alocado ou **nulo** se a operação falhou.

## <a name="remarks"></a>Comentários

**aligned_offset_malloc_dbg** é uma versão de depuração de [aligned_offset_malloc](aligned-offset-malloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **aligned_offset_malloc_dbg** é reduzida a uma chamada para **aligned_offset_malloc**. Ambos **aligned_offset_malloc** e **aligned_offset_malloc_dbg** alocar um bloco de memória no heap de base, mas **aligned_offset_malloc_dbg** oferece diversos recursos de depuração: buffers nos dois lados da parte do usuário do bloco para testar se há perdas, e *filename*/*linenumber* informações para determinar a origem do solicitações de alocação. Tipos de alocação específicos com um parâmetro de tipo de bloco de controle não é um recurso de depuração com suporte para alocações alinhados. Alocações alinhadas serão exibido como um tipo de bloco normal_block.

**aligned_offset_malloc_dbg** aloca o bloco de memória com um pouco mais de espaço que o solicitado *tamanho*. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.

**aligned_offset_malloc_dbg** é útil em situações em que o alinhamento é necessário em um elemento aninhado; por exemplo, se o alinhamento foi necessário em uma classe aninhada.

**aligned_offset_malloc_dbg** se baseia **malloc**; para obter mais informações, consulte [malloc](malloc.md).

Essa função definirá **errno** à **ENOMEM** se a alocação de memória tiver falhado ou se o tamanho solicitado for maior **heap_maxreq**. Para obter mais informações sobre **errno**, consulte [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **aligned_offset_malloc** valida seus parâmetros. Se *alinhamento* não for uma potência de 2 ou se *deslocamento* é maior que ou igual a *tamanho* e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito na [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

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
