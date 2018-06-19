---
title: _aligned_malloc_dbg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _aligned_malloc_dbg
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
- _aligned_malloc_dbg
- aligned_malloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- aligned_malloc_dbg function
- _aligned_malloc_dbg function
ms.assetid: fb0429c3-685d-4826-9075-2515c5bdc5c6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 622f48138404425723c226dde52c8621580d0131
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
ms.locfileid: "34451700"
---
# <a name="alignedmallocdbg"></a>_aligned_malloc_dbg

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

### <a name="parameters"></a>Parâmetros

*size*<br/>
Tamanho da alocação de memória solicitada.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que a operação de alocação solicitada ou **nulo**.

*linenumber*<br/>
Número no arquivo de origem em que a operação de alocação foi solicitada da linha ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que foi alocado ou **nulo** se a operação falhou.

## <a name="remarks"></a>Comentários

**aligned_malloc_dbg** é uma versão de depuração de [aligned_malloc](aligned-malloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não está definida, cada chamada para **aligned_malloc_dbg** é reduzido para uma chamada para **aligned_malloc**. Ambos **aligned_malloc** e **aligned_malloc_dbg** alocar um bloco de memória no heap de base, mas **aligned_malloc_dbg** oferece vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para testar perdas, e *filename*/*linenumber* informações para determinar a origem de solicitações de alocação.

**aligned_malloc_dbg** aloca o bloco de memória com um pouco mais espaço do que o solicitado *tamanho*. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.

**aligned_malloc_dbg** define **errno** para **ENOMEM** se a falha de alocação de memória ou se excede a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) **_ HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **aligned_malloc_dbg** valida seus parâmetros. Se *alinhamento* não é uma potência de 2 ou *tamanho* for zero, essa função invoca o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_malloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
