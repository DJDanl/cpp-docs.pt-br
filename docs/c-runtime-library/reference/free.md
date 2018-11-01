---
title: free
ms.date: 11/04/2016
apiname:
- free
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
- free
helpviewer_keywords:
- memory blocks, deallocating
- free function
ms.assetid: 74ded9cf-1863-432e-9306-327a42080bb8
ms.openlocfilehash: f56212874f05ea5d4ab7bd826a7a4c145551dfc0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50621227"
---
# <a name="free"></a>free

Desaloca ou libera um bloco de memória.

## <a name="syntax"></a>Sintaxe

```C
void free(
   void *memblock
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Bloqueio de memória anteriormente alocado a ser liberado.

## <a name="remarks"></a>Comentários

O **livre** função desaloca um bloco de memória (*memblock*) que foi alocado anteriormente por uma chamada a **calloc**, **malloc**, ou **realloc**. O número de bytes liberados é equivalente ao número de bytes solicitados quando o bloco foi alocado (ou realocado, no caso de **realloc**). Se *memblock* é **nulo**, o ponteiro será ignorado e **livre** retorna imediatamente. A tentativa de liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por **calloc**, **malloc**, ou **realloc**) pode afetar solicitações posteriores de alocação e causar erros.

Se ocorrer um erro liberar a memória **errno** é definido com informações do sistema operacional da natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Após um bloco de memória ter sido liberado, [_heapmin](heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.

Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **livre** resolve [free_dbg](free-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**livre** está marcado como `__declspec(noalias)`, que significa que a função não é garantido que modifica variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

Para liberar a memória alocada com [_malloca](malloca.md), use [_freea](freea.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**free**|\<stdlib.h> e \<malloc.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [malloc](malloc.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[_alloca](alloca.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
[_free_dbg](free-dbg.md)<br/>
[_heapmin](heapmin.md)<br/>
[_freea](freea.md)<br/>
