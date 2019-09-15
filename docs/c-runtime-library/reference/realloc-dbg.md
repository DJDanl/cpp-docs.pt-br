---
title: _realloc_dbg
ms.date: 11/04/2016
api_name:
- _realloc_dbg
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
- _realloc_dbg
- realloc_dbg
helpviewer_keywords:
- reallocating memory blocks
- realloc_dbg function
- memory blocks, reallocating
- memory, reallocating
- _realloc_dbg function
ms.assetid: 7c3cb780-51ed-4d9c-9929-cdde606d846a
ms.openlocfilehash: 58d12ed6f4b013996f3f59cba1b146b823adbee6
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949507"
---
# <a name="_realloc_dbg"></a>_realloc_dbg

Realoca um bloco de memória especificado no heap movendo e/ou redimensionando o bloco (somente a versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void *_realloc_dbg(
   void *userData,
   size_t newSize,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*userData*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*newSize*<br/>
Tamanho solicitado do bloco realocado (bytes).

*blockType*<br/>
Tipo solicitado para o bloco realocado: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de **realocação** ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de **realocação** foi solicitada ou **nula**.

Os parâmetros *filename* e *LineNumber* só estão disponíveis quando **_realloc_dbg** foi chamado explicitamente ou a constante de pré-processador [_CRTDBG_MAP_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) foi definida.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória realocada, chama a nova função de manipulador ou retorna **NULL**. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [realloc](realloc.md).

## <a name="remarks"></a>Comentários

**_realloc_dbg** é uma versão de depuração da função de [realocação](realloc.md) . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, cada chamada para **_realloc_dbg** é reduzida a uma chamada para **realocar**. **Realloc** e **_realloc_dbg** realocar um bloco de memória no heap base, mas o **_realloc_dbg** acomoda vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para testar se há vazamentos, um parâmetro de tipo de bloco para Rastreie tipos de alocação específicos e informações de *nome de arquivo*/*LineNumber* para determinar a origem das solicitações de alocação.

**_realloc_dbg** realoca o bloco de memória especificado com um pouco mais de espaço do que o *newSize*solicitado. *newSize* pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. Se o bloco de memória for movido, o conteúdo do bloco original será substituído.

**_realloc_dbg** define **errno** como **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_realloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo no tópico [_msize_dbg](msize-dbg.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_malloc_dbg](malloc-dbg.md)<br/>
