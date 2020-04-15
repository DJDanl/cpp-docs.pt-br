---
title: _heapadd
ms.date: 11/04/2016
api_name:
- _heapadd
api_location:
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr80.dll
- msvcrt.dll
- msvcr110.dll
- msvcr90.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- heapadd
- _heapadd
helpviewer_keywords:
- _heapadd function
- memory, adding to heaps
- heaps, adding memory
- heapadd function
ms.assetid: 4d691fe2-2763-49f4-afb1-62738b7cd3ff
ms.openlocfilehash: c5eeb66ff0e6fb05063ec395e12cd97106ad724d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351330"
---
# <a name="_heapadd"></a>_heapadd

Adiciona memória ao heap.

> [!IMPORTANT]
> Essa função está obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.

## <a name="syntax"></a>Sintaxe

```
int _heapadd(
   void *memblock,
   size_t size
);
```

#### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Ponteiro para a memória de heap.

*Tamanho*<br/>
Tamanho da memória a ser adicionada, em bytes.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, `_heapadd` retornará 0. Caso contrário, a função retornará -1 e definirá `errno` como `ENOSYS`.

Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Começando com o Visual C++ versão 4.0, a estrutura de heap subjacente foi movida para as bibliotecas de tempo de execução de C para dar suporte a novos recursos de depuração. Como resultado, `_heapadd` não tem mais suporte em nenhuma plataforma baseada na API do Win32.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|`_heapadd`|\<malloc.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.

## <a name="see-also"></a>Confira também

[Alocação de memória](../c-runtime-library/memory-allocation.md)<br/>
[Livre](../c-runtime-library/reference/free.md)<br/>
[_heapchk](../c-runtime-library/reference/heapchk.md)<br/>
[_heapmin](../c-runtime-library/reference/heapmin.md)<br/>
[_heapset](../c-runtime-library/heapset.md)<br/>
[_heapwalk](../c-runtime-library/reference/heapwalk.md)<br/>
[malloc](../c-runtime-library/reference/malloc.md)<br/>
[realloc](../c-runtime-library/reference/realloc.md)
