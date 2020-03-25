---
title: _aligned_malloc_dbg
ms.date: 11/04/2016
api_name:
- _aligned_malloc_dbg
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
- _aligned_malloc_dbg
- aligned_malloc_dbg
helpviewer_keywords:
- aligned_malloc_dbg function
- _aligned_malloc_dbg function
ms.assetid: fb0429c3-685d-4826-9075-2515c5bdc5c6
ms.openlocfilehash: 49278c2282698478ad96cc1c7b1ad27add0a6787
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170924"
---
# <a name="_aligned_malloc_dbg"></a>_aligned_malloc_dbg

Aloca memória em um limite de alinhamento especificado com espaço adicional para um cabeçalho de depuração e buffers de substituição (apenas versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_malloc_dbg(
    size_t size,
    size_t alignment,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>parâmetros

*size*<br/>
Tamanho da alocação de memória solicitada.

*sintonia*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou NULL.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou NULL.

## <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que foi alocado ou nulo se a operação falhou.

## <a name="remarks"></a>Comentários

**_aligned_malloc_dbg** é uma versão de depuração da função [_aligned_malloc](aligned-malloc.md) . Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, cada chamada para **_aligned_malloc_dbg** é reduzida a uma chamada para `_aligned_malloc`. Ambos `_aligned_malloc` e **_aligned_malloc_dbg** alocar um bloco de memória no heap base, mas **_aligned_malloc_dbg** oferece vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para testar vazamentos e informações de *nome de arquivo*/*LineNumber* para determinar a origem das solicitações de alocação. O rastreamento de tipos de alocação específicos com um parâmetro de tipo de bloco não é um recurso de depuração com suporte para alocações alinhadas. As alocações alinhadas aparecerão como um tipo de bloco _NORMAL_BLOCK.

**_aligned_malloc_dbg** aloca o bloco de memória com um pouco mais de espaço do que o *tamanho*solicitado. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.

**_aligned_malloc_dbg** define `errno` como `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) excede `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **_aligned_malloc_dbg** valida seus parâmetros. Se o *alinhamento* não for uma potência de 2 ou o *tamanho* for zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função retornará NULL e definirá `errno` como `EINVAL`.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_malloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Confira também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)
