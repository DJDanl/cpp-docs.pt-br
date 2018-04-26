---
title: _recalloc_dbg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _recalloc_dbg
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
- recalloc_dbg
- _recalloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- _recalloc_dbg function
- recalloc_dbg function
ms.assetid: 43c3e9b2-be6d-4508-9b0f-3220c8a47ca3
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 78246b18a5706d5f69990c01bac473587be5c62a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="recallocdbg"></a>_recalloc_dbg

Realoca uma matriz e inicializa seus elementos como 0 (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void *_recalloc_dbg(
   void *userData,
   size_t num,
   size_t size,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*Dados do usuário*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*Número*<br/>
Número necessário de blocos de memória.

*size*<br/>
Tamanho necessário de cada bloco de memória (bytes).

*blockType*<br/>
Tipo de bloco de memória solicitado: **client_block** ou **normal_block**.

Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração).

*filename*<br/>
Ponteiro para o nome do arquivo de origem que a operação de alocação solicitada ou **nulo**.

*linenumber*<br/>
Número no arquivo de origem em que a operação de alocação foi solicitada da linha ou **nulo**.

O *filename* e *linenumber* parâmetros estão disponíveis somente quando **recalloc_dbg** foi chamado explicitamente ou [crtdbg_map_alloc](../../c-runtime-library/crtdbg-map-alloc.md) constante de pré-processador foi definido.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória realocado, chama a nova função do manipulador ou retorna NULL. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [_recalloc](recalloc.md).

## <a name="remarks"></a>Comentários

**recalloc_dbg** é uma versão de depuração de [recalloc](recalloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não está definida, cada chamada para **recalloc_dbg** é reduzido para uma chamada para **recalloc**. Ambos **recalloc** e **recalloc_dbg** realocar um bloco de memória no heap de base, mas **recalloc_dbg** acomoda a vários recursos de depuração: buffers em ambos os lados da parte do bloco de teste para as perdas de usuário, um bloco de parâmetro para rastrear tipos específicos de alocação, do tipo e *filename*/*linenumber* informações para determinar o origem de solicitações de alocação.

**recalloc_dbg** realoca o bloco de memória especificado com um pouco mais espaço do que o tamanho solicitado (*número* * *tamanho*) que pode ser maior ou menor que o tamanho do o bloco de memória alocada originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. A parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição são preenchidos com 0xFD.

**recalloc_dbg** define **errno** para **ENOMEM** se falhar de alocação de memória; **EINVAL** será retornado se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) excede **heap_maxreq**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_recalloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
