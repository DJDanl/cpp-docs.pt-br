---
title: _recalloc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _recalloc
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _recalloc
- recalloc
dev_langs:
- C++
helpviewer_keywords:
- _recalloc function
- recalloc function
ms.assetid: 1db8305a-3f03-418c-8844-bf9149f63046
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c4ae06fbd3d10f1014fe1c879b482f30302a4f3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32409297"
---
# <a name="recalloc"></a>_recalloc

Uma combinação de **realloc** e **calloc**. Realoca uma matriz na memória e inicializa seus elementos como 0.

## <a name="syntax"></a>Sintaxe

```C
void *_recalloc(
   void *memblock
   size_t num,
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*Número*<br/>
Número de elementos.

*size*<br/>
O comprimento, em bytes, de cada elemento.

## <a name="return-value"></a>Valor de retorno

**recalloc** retorna um **void** ponteiro para o bloco de memória realocada (e possivelmente movido).

Se não houver memória suficiente disponível para expandir o bloco para determinado tamanho, o bloco original é permanecem inalteradas, e **nulo** é retornado.

Se o tamanho solicitado é zero, o bloco apontada pelo *memblock* é liberada; o valor de retorno é **nulo**, e *memblock* for deixado apontando para um bloco livre.

O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **void**, use um tipo de conversão do valor de retorno.

## <a name="remarks"></a>Comentários

O **recalloc** função altera o tamanho de um bloco de memória alocada. O *memblock* argumento aponta para o início do bloco de memória. Se *memblock* é **nulo**, **recalloc** se comporta da mesma maneira que [calloc](calloc.md) e aloca um novo bloco de *número*  *  *tamanho* bytes. Cada elemento é inicializado como 0. Se *memblock* não é **nulo**, ele deve ser um ponteiro retornado por uma chamada anterior a **calloc**, [malloc](malloc.md), ou [realloc ](realloc.md).

Como o novo bloco pode ser em um novo local de memória, o ponteiro retornado pelo **recalloc** não é garantido para ser o ponteiro transmitido a *memblock* argumento.

**recalloc** define **errno** para **ENOMEM** se a alocação de memória falhar ou se a quantidade de memória solicitada excede **heap_maxreq**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

**recalloc** chamadas **realloc** para usar o C++ [set_new_mode](set-new-mode.md) função para definir o novo modo de manipulador. O novo modo de manipulador indica se, em caso de falha **realloc** é chamar a rotina do manipulador de novo conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **realloc** não chamar a rotina do manipulador de novo em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando **recalloc** Falha ao alocar memória, **realloc** chama a rotina do manipulador de novo na mesma forma que o **novo** operador não quando ele falhar pela mesma razão. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

no início do programa ou vincule com NEWMODE.OBJ.

Quando o aplicativo está vinculado com uma versão de depuração das bibliotecas de tempo de execução do C, **recalloc** resolve [recalloc_dbg](recalloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**recalloc** está marcado como `__declspec(noalias)` e `__declspec(restrict)`, que significa que a função é garantida que não modificar variáveis globais, e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_recalloc**|\<stdlib.h> e \<malloc.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[_recalloc_dbg](recalloc-dbg.md)<br/>
[_aligned_recalloc](aligned-recalloc.md)<br/>
[_aligned_offset_recalloc](aligned-offset-recalloc.md)<br/>
[free](free.md)<br/>
[Opções de link](../../c-runtime-library/link-options.md)<br/>
