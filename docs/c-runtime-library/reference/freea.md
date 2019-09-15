---
title: _freea
ms.date: 11/04/2016
api_name:
- _freea
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
- freea
- _freea
helpviewer_keywords:
- _freea function
- freea function
- memory deallocation
ms.assetid: dcd30584-dd9d-443b-8c4c-13237a1cecac
ms.openlocfilehash: dcad8bea4f8cec28d8cb15a9937b1032593ef0cc
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70956719"
---
# <a name="_freea"></a>_freea

Desaloca ou libera um bloco de memória.

## <a name="syntax"></a>Sintaxe

```C
void _freea(
   void *memblock
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Bloqueio de memória anteriormente alocado a ser liberado.

## <a name="return-value"></a>Valor de retorno

nenhuma.

## <a name="remarks"></a>Comentários

A função **_freea** Desaloca um bloco de memória (*memblock*) que foi previamente alocado por uma chamada para [_malloca](malloca.md). **_freea** verifica se a memória foi alocada no heap ou na pilha. Se ele foi alocado na pilha, o **_freea** não fará nada. Se tiver sido alocada no heap, o número de bytes liberados será equivalente ao número de bytes solicitados quando o bloco foi alocado. Se *memblock* for **NULL**, o ponteiro será ignorado e **_freea** retornará imediatamente. A tentativa de liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por **_malloca**) pode afetar as solicitações de alocação subsequentes e causar erros.

**_freea** chamadas **gratuitas** internamente se descobrir que a memória está alocada no heap. Um marcador colocado na memória, no endereço imediatamente anterior à memória alocada, determina se a memória está no heap ou na pilha.

Se ocorrer um erro na liberação da memória, **errno** será definido com informações do sistema operacional na natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Após um bloco de memória ter sido liberado, [_heapmin](heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.

Uma chamada para **_freea** deve acompanhar todas as chamadas para **_malloca**. Também é um erro para chamar **_freea** duas vezes na mesma memória. Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, particularmente com os recursos do [_malloc_dbg](malloc-dbg.md) habilitados pela definição de **_CRTDBG_MAP_ALLOC**, é mais fácil localizar chamadas ausentes ou duplicadas para **_freea**. Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**_freea** é marcado `__declspec(noalias)`, o que significa que a função está garantida para não modificar variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_freea**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [_malloca](malloca.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[_malloca](malloca.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[_malloc_dbg](malloc-dbg.md)<br/>
[realloc](realloc.md)<br/>
[_free_dbg](free-dbg.md)<br/>
[_heapmin](heapmin.md)<br/>
