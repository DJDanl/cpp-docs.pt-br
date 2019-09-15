---
title: _malloc_dbg
ms.date: 11/04/2016
api_name:
- _malloc_dbg
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
- malloc_dbg
- _malloc_dbg
helpviewer_keywords:
- malloc_dbg function
- memory allocation
- _malloc_dbg function
ms.assetid: c97eca51-140b-4461-8bd2-28965b49ecdb
ms.openlocfilehash: cfaaaec17dc8546c937045f93027e9609981bd93
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952874"
---
# <a name="_malloc_dbg"></a>_malloc_dbg

Aloca um bloco de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição (apenas versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void *_malloc_dbg(
   size_t size,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Tamanho solicitado do bloco de memória (em bytes).

*blockType*<br/>
Tipo solicitado do bloco de memória: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nula**.

Os parâmetros *filename* e *LineNumber* só estão disponíveis quando **_malloc_dbg** foi chamado explicitamente ou a constante de pré-processador [_CRTDBG_MAP_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) foi definida.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória alocado, chama a nova função de manipulador ou retorna **NULL**. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [malloc](malloc.md).

## <a name="remarks"></a>Comentários

**_malloc_dbg** é uma versão de depuração da função [malloc](malloc.md) . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, cada chamada para **_malloc_dbg** é reduzida a uma chamada para **malloc**. O **malloc** e o **_malloc_dbg** alocam um bloco de memória no heap base, mas o **_malloc_dbg** oferece vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para testar se há vazamentos, um parâmetro de tipo de bloco para rastrear tipos de alocação específicos e informações de *nome de arquivo*/*LineNumber* para determinar a origem das solicitações de alocação.

**_malloc_dbg** aloca o bloco de memória com um pouco mais de espaço do que o *tamanho*solicitado. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.

**_malloc_dbg** define **errno** como **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_malloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar o **_malloc_dbg**, consulte [crt_dbg1](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg1).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[malloc](malloc.md)<br/>
[_calloc_dbg](calloc-dbg.md)<br/>
