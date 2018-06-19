---
title: _aligned_recalloc_dbg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _aligned_recalloc_dbg
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
- _aligned_recalloc_dbg
- aligned_recalloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- aligned_recalloc_dbg function
- _aligned_recalloc_dbg function
ms.assetid: 55c3c27e-561c-4d6b-9bf9-1e34cc556e4b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a73142a832f98caa673c014bad0a909749af3cd9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32399833"
---
# <a name="alignedrecallocdbg"></a>_aligned_recalloc_dbg

Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md) e inicializa a memória como 0 (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_recalloc_dbg(
   void * memblock,
   size_t num,
   size_t size,
   size_t alignment,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
O ponteiro do bloco de memória atual.

*Número*<br/>
O número de elementos.

*size*<br/>
O tamanho, em bytes, de cada elemento.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que a operação de alocação solicitada ou **nulo**.

*linenumber*<br/>
Número no arquivo de origem em que a operação de alocação foi solicitada da linha ou **nulo**.

## <a name="return-value"></a>Valor de retorno

**aligned_recalloc_dbg** retorna um ponteiro nulo para o bloco de memória realocada (e possivelmente movido). O valor de retorno é **nulo** se o tamanho é zero e o argumento de buffer não é **nulo**, ou se não houver memória suficiente disponível para expandir o bloco para determinado tamanho. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

Realocar a memória e alterar o alinhamento de um bloco é um erro.

## <a name="remarks"></a>Comentários

**aligned_recalloc_dbg** é uma versão de depuração de [aligned_recalloc](aligned-recalloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não está definida, cada chamada para **aligned_recalloc_dbg** é reduzido para uma chamada para **aligned_recalloc**. Ambos **aligned_recalloc** e **aligned_recalloc_dbg** realocar um bloco de memória no heap de base, mas **aligned_recalloc_dbg** acomoda a depuração de vários recursos: buffers em ambos os lados da parte do usuário do bloco para testar vazamentos, um parâmetro de tipo de bloco para rastrear tipos específicos de alocação, e *filename*/*linenumber* informações para determinar a origem de solicitações de alocação.

**aligned_recalloc_dbg** realoca o bloco de memória especificado com um pouco mais espaço do que o tamanho solicitado (*número* * *tamanho*) que pode ser maior ou menor que o tamanho do bloco de memória alocada originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. A parte do usuário do bloco é preenchida com o valor 0xCD e os buffers de substituição são preenchidos com 0xFD.

**aligned_recalloc_dbg** define **errno** para **ENOMEM** se falhar de alocação de memória; **EINVAL** será retornado se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) excede **heap_maxreq**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Além disso, **aligned_recalloc_dbg** valida seus parâmetros. Se *alinhamento* não é uma potência de 2, essa função invoca o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_recalloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
