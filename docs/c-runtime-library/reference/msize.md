---
title: _msize
ms.date: 11/04/2016
api_name:
- _msize
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
ms.openlocfilehash: c1760cfa6a416e2eb4cd7b549cb5ae9bed00a609
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951432"
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

## <a name="return-value"></a>Valor de retorno

**_msize** retorna o tamanho (em bytes) como um inteiro sem sinal.

## <a name="remarks"></a>Comentários

A função **_msize** retorna o tamanho, em bytes, do bloco de memória alocado por uma chamada para **calloc**, **malloc**ou **realloc**.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, o **_msize** é resolvido para [_msize_dbg](msize-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

Esta função valida seu parâmetro. Se *memblock* for um ponteiro nulo, **_msize** invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função definirá **errno** como **EINVAL** e retornará-1.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_msize**|\<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [realloc](realloc.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[_expand](expand.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
