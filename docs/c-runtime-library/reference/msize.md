---
title: _msize
ms.date: 11/04/2016
apiname:
- _msize
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
- msize
- _msize
helpviewer_keywords:
- memory blocks
- msize function
- _msize function
ms.assetid: 02b1f89e-d0d7-4f12-938a-9eeba48a0f88
ms.openlocfilehash: 0321e42face817a0a9f12d780f72c86c67ba308d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477266"
---
# <a name="msize"></a>_msize

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

**msize** retorna o tamanho (em bytes) como um inteiro sem sinal.

## <a name="remarks"></a>Comentários

O **msize** função retorna o tamanho, em bytes, do bloco de memória alocado por uma chamada para **calloc**, **malloc**, ou **realloc**.

Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **msize** resolve [msize_dbg](msize-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

Esta função valida seu parâmetro. Se *memblock* for um ponteiro nulo, **msize** invocará um manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função definirá **errno** à **EINVAL** e retornará -1.

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
