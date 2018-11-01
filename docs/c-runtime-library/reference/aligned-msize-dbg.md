---
title: _aligned_msize_dbg
ms.date: 11/04/2016
apiname:
- _aligned_msize_dbg
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
apitype: DLLExport
f1_keywords:
- _aligned_msize_dbg
helpviewer_keywords:
- _aligned_msize_dbg
ms.assetid: f1c44af0-3f66-4033-81d1-d71d3afecba0
ms.openlocfilehash: 054f7b88f93eef37a9a88fbb7895452f7c158716
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451292"
---
# <a name="alignedmsizedbg"></a>_aligned_msize_dbg

Retorna o tamanho de um bloco de memória alocado no heap (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
size_t _aligned_msize_dbg(
   void *memblock,
   size_t alignment,
   size_t offset
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Ponteiro para o bloco de memória.

*alignment*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

## <a name="return-value"></a>Valor de retorno

Retorna o tamanho (em bytes) como um inteiro sem sinal.

## <a name="remarks"></a>Comentários

O *alinhamento* e *deslocamento* valores devem ser o mesmo que os valores passados para a função que alocou o bloco.

**aligned_msize_dbg** é uma versão de depuração de [aligned_msize](aligned-msize.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **aligned_msize_dbg** é reduzida a uma chamada para **aligned_msize**. Ambos **aligned_msize** e **aligned_msize_dbg** calcular o tamanho de um bloco de memória no heap de base, mas **aligned_msize_dbg** adiciona um recurso de depuração: ele inclui bloqueiam os buffers nos dois lados da parte do usuário da memória no tamanho retornado.

Esta função valida seu parâmetro. Se *memblock* for um ponteiro nulo ou *alinhamento* não for uma potência de 2 **msize** invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro ](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função definirá **errno** à **EINVAL** e retornará -1.

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_msize_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
