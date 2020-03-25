---
title: _aligned_free
ms.date: 11/04/2016
api_name:
- _aligned_free
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
- aligned_free
- _aligned_free
helpviewer_keywords:
- _aligned_free function
- aligned_free function
ms.assetid: ed1ce952-cdfc-4682-85cc-f75d4101603d
ms.openlocfilehash: 0fa28be550050a7eec2a515cfb47d98fb26591d0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170963"
---
# <a name="_aligned_free"></a>_aligned_free

Libera um bloco de memória que foi alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md).

## <a name="syntax"></a>Sintaxe

```C
void _aligned_free (
   void *memblock
);
```

### <a name="parameters"></a>parâmetros

*memblock*<br/>
Um ponteiro para o bloco de memória que foi retornado para a função `_aligned_malloc` ou `_aligned_offset_malloc`.

## <a name="remarks"></a>Comentários

**_aligned_free** está marcado como `__declspec(noalias)`, o que significa que a função está garantida para não modificar variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

Essa função não valida seu parâmetro, ao contrário das outras funções de CRT _aligned. Se *memblock* for um ponteiro nulo, essa função simplesmente não executará nenhuma ação. Ela não altera `errno` nem chama o manipulador de parâmetro inválido. Se ocorrer um erro na função porque as funções _aligned não foram usadas anteriormente para alocar o bloco de memória ou se ocorrer um desalinhamento de memória devido a algum problema imprevisto, a função gerará um relatório de depuração das [Macros _RPT, _RPTF, _RPTW, _RPTFW](rpt-rptf-rptw-rptfw-macros.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_free**|\<malloc.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [_aligned_malloc](aligned-malloc.md).

## <a name="see-also"></a>Confira também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)
