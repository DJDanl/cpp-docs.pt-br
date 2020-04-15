---
title: _aligned_offset_malloc
ms.date: 4/2/2020
api_name:
- _aligned_offset_malloc
- _o__aligned_offset_malloc
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
- _aligned_offset_malloc
- aligned_offset_malloc
helpviewer_keywords:
- _aligned_offset_malloc function
- aligned_offset_malloc function
ms.assetid: 447681a3-7c95-4655-86ba-fa3a4ca4c521
ms.openlocfilehash: 1f13afbab75d2926d1c642c1430a3ffe5ecbac8d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350578"
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

*Tamanho*<br/>
Tamanho da alocação de memória solicitada.

*alinhamento*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

## <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que foi alocado ou **NULL** se a operação falhar.

## <a name="remarks"></a>Comentários

**_aligned_offset_malloc** é útil em situações em que o alinhamento é necessário em um elemento aninhado; por exemplo, se o alinhamento fosse necessário em uma classe aninhada.

**_aligned_offset_malloc** é baseada em **malloc;** para obter mais informações, consulte [malloc](malloc.md).

**_aligned_offset_malloc** é `__declspec(noalias)` `__declspec(restrict)`marcado e , o que significa que a função é garantida para não modificar variáveis globais e que o ponteiro retornado não é aliased. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Esta função define **errno** ao **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado for maior que **_HEAP_MAXREQ**. Para obter mais informações sobre **errno,** consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **_aligned_offset_malloc** valida seus parâmetros. Se *o alinhamento* não for uma potência de 2 ou se a *compensação* for maior ou igual ao *tamanho* e não zero, esta função invoca o manipulador de parâmetros inválido, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função retorna **NULL** e define **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_malloc**|\<malloc.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [_aligned_malloc](aligned-malloc.md).

## <a name="see-also"></a>Confira também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
