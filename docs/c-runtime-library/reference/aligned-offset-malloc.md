---
title: _aligned_offset_malloc
ms.date: 11/04/2016
apiname:
- _aligned_offset_malloc
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
- _aligned_offset_malloc
- aligned_offset_malloc
helpviewer_keywords:
- _aligned_offset_malloc function
- aligned_offset_malloc function
ms.assetid: 447681a3-7c95-4655-86ba-fa3a4ca4c521
ms.openlocfilehash: 824edfd8bb96d805a030fb205dee62fa9eb4fd06
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644631"
---
# <a name="alignedoffsetmalloc"></a>_aligned_offset_malloc

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

**aligned_offset_malloc** é útil em situações em que o alinhamento é necessário em um elemento aninhado; por exemplo, se o alinhamento foi necessário em uma classe aninhada.

**aligned_offset_malloc** se baseia **malloc**; para obter mais informações, consulte [malloc](malloc.md).

**aligned_offset_malloc** está marcada `__declspec(noalias)` e `__declspec(restrict)`, o que significa que a função não é garantido que modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Essa função definirá **errno** à **ENOMEM** se a alocação de memória tiver falhado ou se o tamanho solicitado for maior **heap_maxreq**. Para obter mais informações sobre **errno**, consulte [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **aligned_offset_malloc** valida seus parâmetros. Se *alinhamento* não for uma potência de 2 ou se *deslocamento* é maior que ou igual a *tamanho* e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito na [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_malloc**|\<malloc.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [_aligned_malloc](aligned-malloc.md).

## <a name="see-also"></a>Consulte também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
