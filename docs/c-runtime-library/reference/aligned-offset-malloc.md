---
title: _aligned_offset_malloc
ms.date: 11/04/2016
api_name:
- _aligned_offset_malloc
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
- _aligned_offset_malloc
- aligned_offset_malloc
helpviewer_keywords:
- _aligned_offset_malloc function
- aligned_offset_malloc function
ms.assetid: 447681a3-7c95-4655-86ba-fa3a4ca4c521
ms.openlocfilehash: 3e8d6f839f3c675b7543ff14f3f633b0c7d5151f
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943852"
---
# <a name="_aligned_offset_malloc"></a>_aligned_offset_malloc

Aloca memória em um limite de alinhamento especificado.

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_offset_malloc(
   size_t size,
   size_t alignment,
   size_t offset
);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Tamanho da alocação de memória solicitada.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

## <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que foi alocado ou **nulo** se a operação falhou.

## <a name="remarks"></a>Comentários

**_aligned_offset_malloc** é útil em situações em que o alinhamento é necessário em um elemento aninhado; por exemplo, se o alinhamento fosse necessário em uma classe aninhada.

o **_aligned_offset_malloc** é baseado em **malloc**; para obter mais informações, consulte [malloc](malloc.md).

**_aligned_offset_malloc** é marcado `__declspec(noalias)` como `__declspec(restrict)`e, o que significa que a função está garantida para não modificar variáveis globais e que o ponteiro retornado não tem um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Essa função define **errno** como **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado era maior que **_HEAP_MAXREQ**. Para obter mais informações sobre **errno**, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, o **_aligned_offset_malloc** valida seus parâmetros. Se o *alinhamento* não for uma potência de 2 ou se o *deslocamento* for maior ou igual ao *tamanho* e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em validação de [parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função retornará **NULL** e definirá **errno** como **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_malloc**|\<malloc.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [_aligned_malloc](aligned-malloc.md).

## <a name="see-also"></a>Consulte também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
