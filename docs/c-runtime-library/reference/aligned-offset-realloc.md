---
title: _aligned_offset_realloc
ms.date: 11/04/2016
api_name:
- _aligned_offset_realloc
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
- aligned_offset_realloc
- _aligned_offset_realloc
helpviewer_keywords:
- aligned_offset_realloc function
- _aligned_offset_realloc function
ms.assetid: e0263533-991e-41b0-acc9-1b8a51ab9ecd
ms.openlocfilehash: a24aef5c7d96cb8308ecfec424d0d59b48447f7b
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943842"
---
# <a name="_aligned_offset_realloc"></a>_aligned_offset_realloc

Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md).

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_offset_realloc(
   void *memblock,
   size_t size,
   size_t alignment,
   size_t offset
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
O ponteiro do bloco de memória atual.

*size*<br/>
O tamanho da alocação de memória.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

## <a name="return-value"></a>Valor de retorno

**_aligned_offset_realloc** retorna um ponteiro void para o bloco de memória realocado (e possivelmente movido). O valor de retorno será **nulo** se o tamanho for zero e o argumento de buffer não for **nulo**ou se não houver memória suficiente disponível para expandir o bloco para o tamanho especificado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

**_aligned_offset_realloc** é marcado `__declspec(noalias)` como `__declspec(restrict)`e, o que significa que a função está garantida para não modificar variáveis globais e que o ponteiro retornado não tem um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

## <a name="remarks"></a>Comentários

Como [_aligned_offset_malloc](aligned-offset-malloc.md), o **_aligned_offset_realloc** permite que uma estrutura seja alinhada em um deslocamento dentro da estrutura.

**_aligned_offset_realloc** é baseado em **malloc**. Para obter mais informações sobre como usar o **_aligned_offset_malloc**, consulte [malloc](malloc.md). Se *memblock* for **NULL**, a função chamará **_aligned_offset_malloc** internamente.

Essa função define **errno** como **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado era maior que **_HEAP_MAXREQ**. Para obter mais informações sobre **errno**, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, o **_aligned_offset_realloc** valida seus parâmetros. Se o *alinhamento* não for uma potência de 2 ou se o *deslocamento* for maior ou igual ao *tamanho* e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em validação de [parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função retornará **NULL** e definirá **errno** como **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_realloc**|\<malloc.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [_aligned_malloc](aligned-malloc.md).

## <a name="see-also"></a>Consulte também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
