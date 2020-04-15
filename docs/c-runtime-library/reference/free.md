---
title: livre
ms.date: 4/2/2020
api_name:
- free
- _o_free
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
- api-ms-win-crt-heap-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- free
helpviewer_keywords:
- memory blocks, deallocating
- free function
ms.assetid: 74ded9cf-1863-432e-9306-327a42080bb8
ms.openlocfilehash: eefbe957ce5057b5038f98bc8da8fb2f0bdd3d1c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345985"
---
# <a name="free"></a>livre

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

A função **livre** desaloca um bloco de memória *(memblock)* que foi previamente alocado por uma chamada para call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to **calltoc,** **malloc**ou **realloc**. O número de bytes liberados é equivalente ao número de bytes solicitados quando o bloco foi alocado (ou realocado, no caso do **realloc**). Se *o memblock* for **NULL**, o ponteiro é ignorado e **livre** imediatamente retorna. A tentativa de liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por **calloc**, **malloc**ou **realloc)** pode afetar as solicitações de alocação subseqüentes e causar erros.

Se ocorrer um erro na liberação da memória, **errno** será definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Após um bloco de memória ter sido liberado, [_heapmin](heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, a resolução **gratuita** [para _free_dbg](free-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**livre** é `__declspec(noalias)`marcado, o que significa que a função é garantida para não modificar variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

Para liberar a memória alocada com [_malloca](malloca.md), use [_freea](freea.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**Livre**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [malloc](malloc.md).

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[_alloca](alloca.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
[_free_dbg](free-dbg.md)<br/>
[_heapmin](heapmin.md)<br/>
[_freea](freea.md)<br/>
