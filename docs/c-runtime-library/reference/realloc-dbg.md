---
title: _realloc_dbg
ms.date: 11/04/2016
apiname:
- _realloc_dbg
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
- _realloc_dbg
- realloc_dbg
helpviewer_keywords:
- reallocating memory blocks
- realloc_dbg function
- memory blocks, reallocating
- memory, reallocating
- _realloc_dbg function
ms.assetid: 7c3cb780-51ed-4d9c-9929-cdde606d846a
ms.openlocfilehash: 9b30dfd6fbae9a4831ff53e7896aeb995657da03
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50640278"
---
# <a name="reallocdbg"></a>_realloc_dbg

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

*dados do usuário*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*newSize*<br/>
Tamanho solicitado do bloco realocado (bytes).

*blockType*<br/>
Tipo de bloco realocado solicitado: **client_block** ou **normal_block**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a **realloc** operação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que o **realloc** operação foi solicitada ou **nulo**.

O *filename* e *linenumber* parâmetros estão disponíveis somente quando **realloc_dbg** tiver sido chamado explicitamente ou o [crtdbg_map_alloc](../../c-runtime-library/crtdbg-map-alloc.md) constante do pré-processador foi definido.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória realocado, chama a nova função de manipulador tanto retorna **nulo**. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [realloc](realloc.md).

## <a name="remarks"></a>Comentários

**realloc_dbg** é uma versão de depuração de [realloc](realloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **realloc_dbg** é reduzida a uma chamada para **realloc**. Ambos **realloc** e **realloc_dbg** realocam um bloco de memória no heap de base, mas **realloc_dbg** acomoda diversos recursos de depuração: buffers nos dois lados das parte do usuário do bloco para testar se há vazamentos, um parâmetro de tipo de bloco para rastrear tipos de alocação específicos e *filename*/*linenumber* informações para determinar a origem do solicitações de alocação.

**realloc_dbg** realoca o bloco de memória especificado com um pouco mais de espaço que o solicitado *newSize*. *newSize* pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. Se o bloco de memória for movido, o conteúdo do bloco original será substituído.

**realloc_dbg** define **errno** à **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder **_HEAP_ MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

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
