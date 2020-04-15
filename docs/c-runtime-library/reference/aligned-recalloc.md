---
title: _aligned_recalloc
ms.date: 4/2/2020
api_name:
- _aligned_recalloc
- _o__aligned_recalloc
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
- aligned_recalloc
- _aligned_recalloc
helpviewer_keywords:
- aligned_recalloc function
- _aligned_recalloc function
ms.assetid: d3da3dcc-79ef-4273-8af5-ac7469420142
ms.openlocfilehash: af12322742c777cda879e01cb9c054297f807725
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350487"
---
# <a name="_aligned_recalloc"></a>_aligned_recalloc

Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md) e inicializa a memória como 0.

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_recalloc(
   void *memblock,
   size_t num,
   size_t size,
   size_t alignment
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
O ponteiro do bloco de memória atual.

*number*<br/>
O número de elementos.

*Tamanho*<br/>
O tamanho, em bytes, de cada elemento.

*alinhamento*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

## <a name="return-value"></a>Valor retornado

**_aligned_recalloc** retorna um ponteiro vazio para o bloco de memória realocado (e possivelmente movido). O valor de retorno é **NULO** se o tamanho for zero e o argumento de buffer não for **NULO,** ou se não houver memória disponível suficiente para expandir o bloco para o tamanho dado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

Realocar a memória e alterar o alinhamento de um bloco é um erro.

## <a name="remarks"></a>Comentários

**_aligned_recalloc** é baseado em **malloc**. Para obter mais informações sobre como usar **_aligned_offset_malloc,** consulte [malloc](malloc.md).

Esta função define **errno** ao **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado for maior que **_HEAP_MAXREQ**. Para obter mais informações sobre **errno,** consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **_aligned_recalloc** valida seus parâmetros. Se *o alinhamento* não for uma potência de 2, esta função invoca o manipulador de parâmetros inválidos, conforme descrito na Validação de [Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função retorna **NULL** e define **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_recalloc**|\<malloc.h>|

## <a name="see-also"></a>Confira também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
[_recalloc](recalloc.md)<br/>
[_aligned_offset_recalloc](aligned-offset-recalloc.md)<br/>
