---
title: _realloc_dbg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- reallocating memory blocks
- realloc_dbg function
- memory blocks, reallocating
- memory, reallocating
- _realloc_dbg function
ms.assetid: 7c3cb780-51ed-4d9c-9929-cdde606d846a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c4bb3eab58807805ec3c4fbc35611d268bbeee9
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
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

*Dados do usuário*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*newSize*<br/>
Tamanho solicitado do bloco realocado (bytes).

*blockType*<br/>
Tipo para o bloco realocado solicitado: **client_block** ou **normal_block**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou o **realloc** operação ou **nulo**.

*linenumber*<br/>
Número no arquivo de origem da linha onde o **realloc** operação foi solicitada ou **nulo**.

O *filename* e *linenumber* parâmetros estão disponíveis somente quando **realloc_dbg** foi chamado explicitamente ou [crtdbg_map_alloc](../../c-runtime-library/crtdbg-map-alloc.md) constante de pré-processador foi definido.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, essa função retorna um ponteiro à parte do usuário do bloco de memória realocada, chama a nova função de manipulador ou retorna **nulo**. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [realloc](realloc.md).

## <a name="remarks"></a>Comentários

**realloc_dbg** é uma versão de depuração de [realloc](realloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não está definida, cada chamada para **realloc_dbg** é reduzido para uma chamada para **realloc**. Ambos **realloc** e **realloc_dbg** realocar um bloco de memória no heap de base, mas **realloc_dbg** acomoda a vários recursos de depuração: buffers em cada lado das parte do usuário do bloco para testar vazamentos, um parâmetro de tipo de bloco para rastrear tipos específicos de alocação, e *filename*/*linenumber* informações para determinar a origem do solicitações de alocação.

**realloc_dbg** realoca o bloco de memória especificado com um pouco mais espaço do que o solicitado *newSize*. *newSize* pode ser maior ou menor que o tamanho do bloco de memória alocada originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. Se o bloco de memória for movido, o conteúdo do bloco original será substituído.

**realloc_dbg** define **errno** para **ENOMEM** se a falha de alocação de memória ou se excede a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) **_HEAP_ MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

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
