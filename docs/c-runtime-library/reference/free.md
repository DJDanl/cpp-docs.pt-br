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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 0e0a53dd9d24634442c8dd456e4f9d38f742e292
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920417"
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

A função **Free** Desaloca um bloco de memória (*memblock*) que foi previamente alocado por uma chamada para **calloc**, **malloc**ou **realloc**. O número de bytes liberados é equivalente ao número de bytes solicitados quando o bloco foi alocado (ou realocado, no caso de **realloc**). Se *memblock* for **NULL**, o ponteiro será ignorado e o botão **Free** retornará imediatamente. A tentativa de liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por **calloc**, **malloc**ou **realloc**) pode afetar as solicitações de alocação subsequentes e causar erros.

Se ocorrer um erro na liberação da memória, **errno** será definido com informações do sistema operacional na natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Após um bloco de memória ter sido liberado, [_heapmin](heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, a solução **gratuita** é resolvida para [_free_dbg](free-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**Free** é marcado `__declspec(noalias)`, o que significa que a função está garantida para não modificar variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

Para liberar a memória alocada com [_malloca](malloca.md), use [_freea](freea.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**informações**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [malloc](malloc.md).

## <a name="see-also"></a>Consulte também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[_alloca](alloca.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
[_free_dbg](free-dbg.md)<br/>
[_heapmin](heapmin.md)<br/>
[_freea](freea.md)<br/>
