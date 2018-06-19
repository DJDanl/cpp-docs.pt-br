---
title: _aligned_recalloc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _aligned_recalloc
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
- aligned_recalloc
- _aligned_recalloc
dev_langs:
- C++
helpviewer_keywords:
- aligned_recalloc function
- _aligned_recalloc function
ms.assetid: d3da3dcc-79ef-4273-8af5-ac7469420142
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2792cff3c401d7710f3844bfe65640e194189586
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32393232"
---
# <a name="alignedrecalloc"></a>_aligned_recalloc

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

*Número*<br/>
O número de elementos.

*size*<br/>
O tamanho, em bytes, de cada elemento.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

## <a name="return-value"></a>Valor de retorno

**aligned_recalloc** retorna um ponteiro nulo para o bloco de memória realocada (e possivelmente movido). O valor de retorno é **nulo** se o tamanho é zero e o argumento de buffer não é **nulo**, ou se não houver memória suficiente disponível para expandir o bloco para determinado tamanho. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

Realocar a memória e alterar o alinhamento de um bloco é um erro.

## <a name="remarks"></a>Comentários

**aligned_recalloc** baseia-se em **malloc**. Para obter mais informações sobre como usar **aligned_offset_malloc**, consulte [malloc](malloc.md).

Esta função define **errno** para **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado é maior que **heap_maxreq**. Para obter mais informações sobre **errno**, consulte [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **aligned_recalloc** valida seus parâmetros. Se *alinhamento* não é uma potência de 2, essa função invoca o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essa função retorna **nulo** e define **errno** para **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_recalloc**|\<malloc.h>|

## <a name="see-also"></a>Consulte também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
[_recalloc](recalloc.md)<br/>
[_aligned_offset_recalloc](aligned-offset-recalloc.md)<br/>
