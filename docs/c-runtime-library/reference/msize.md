---
title: _msize
ms.date: 4/2/2020
api_name:
- _msize
- _o__msize
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
- msize
- _msize
helpviewer_keywords:
- memory blocks
- msize function
- _msize function
ms.assetid: 02b1f89e-d0d7-4f12-938a-9eeba48a0f88
ms.openlocfilehash: 7d5f62bd6111a305c18b0ee19bb6d3e90f2ddb49
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338660"
---
# <a name="_msize"></a>_msize

Retorna o tamanho de um bloco de memória alocado no heap.

## <a name="syntax"></a>Sintaxe

```C
size_t _msize(
   void *memblock
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Ponteiro para o bloco de memória.

## <a name="return-value"></a>Valor retornado

**_msize** retorna o tamanho (em bytes) como um inteiro não assinado.

## <a name="remarks"></a>Comentários

A função **_msize** retorna o tamanho, em bytes, do bloco de **malloc**memória alocado por **realloc**uma chamada para call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to call to **call**to

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **_msize** resolve [_msize_dbg](msize-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

Esta função valida seu parâmetro. Se *o memblock* for um ponteiro nulo, **_msize** invocar á socéia inválida, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se o erro for manipulado, a função define **errno** para **EINVAL** e retorna -1.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_msize**|\<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [realloc](realloc.md).

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[_expand](expand.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
