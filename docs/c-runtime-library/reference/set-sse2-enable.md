---
title: _set_SSE2_enable
ms.date: 04/05/2018
api_name:
- _set_SSE2_enable
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
- api-ms-win-crt-math-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _set_SSE2_enable
- set_SSE2_enable
helpviewer_keywords:
- _set_SSE2_enable function
- Streaming SIMD Extensions 2 instructions
- set_SSE2_enable function
ms.assetid: 55db895d-fc1e-475a-9110-b781a9bb51c5
ms.openlocfilehash: 8838282db851c6811a3f24c75a03b31c5870e6d3
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948372"
---
# <a name="_set_sse2_enable"></a>_set_SSE2_enable

Habilita ou desabilita o uso das instruções SSE2 (Streaming SIMD Extensions 2) em rotinas matemáticas do CRT. (Esta função não está disponível em arquiteturas x64 porque SSE2 está habilitado por padrão.)

## <a name="syntax"></a>Sintaxe

```C
int _set_SSE2_enable(
   int flag
);
```

### <a name="parameters"></a>Parâmetros

*flag*<br/>
1 para habilitar a implementação SSE2; 0 para desabilitar a implementação SSE2. Por padrão, a implementação SSE2 está habilitada nos processadores que dão suporte a ela.

## <a name="return-value"></a>Valor de retorno

Diferente de zero se a implementação de SSE2 está habilitada; zero se SSE2 implementação está desabilitada.

## <a name="remarks"></a>Comentários

As funções a seguir têm implementações SSE2 que podem ser habilitadas usando **_set_SSE2_enable**:

- [atan](atan-atanf-atanl-atan2-atan2f-atan2l.md)

- [ceil](ceil-ceilf-ceill.md)

- [exp](exp-expf.md)

- [floor](floor-floorf-floorl.md)

- [log](log-logf-log10-log10f.md)

- [log10](log-logf-log10-log10f.md)

- [modf](modf-modff-modfl.md)

- [pow](pow-powf-powl.md)

As implementações de SSE2 dessas funções podem gerar respostas um pouco diferentes que as implementações padrão porque valores intermediários SSE2 são as quantidades de ponto flutuante de 64 bits, mas os valores intermediários de implementação padrão são quantidades de ponto flutuante de 80 bits.

> [!NOTE]
> Se você usar a opção de compilador [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md) para compilar o projeto, poderá parecer que **_set_SSE2_enable** não tem nenhum efeito. A opção de compilador **/Oi** fornece ao compilador a autoridade para usar intrínsecos para substituir chamadas CRT; Esse comportamento substitui o efeito de **_set_SSE2_enable**. Se você quiser garantir que **/Oi** não substitua **_set_SSE2_enable**, use **/Oi-** para compilar seu projeto. Isso também pode ser uma boa prática quando você usa outras opções de compilador que sugerem **/Oi**.

A implementação de SSE2 é usada apenas se todas as exceções estão mascaradas. Use [_control87, _controlfp](control87-controlfp-control87-2.md) para mascarar exceções.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_SSE2_enable**|\<math.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_set_SSE2_enable.c
// processor: x86
#include <math.h>
#include <stdio.h>

int main()
{
   int i = _set_SSE2_enable(1);

   if (i)
      printf("SSE2 enabled.\n");
   else
      printf("SSE2 not enabled; processor does not support SSE2.\n");
}
```

```Output
SSE2 enabled.
```

## <a name="see-also"></a>Consulte também

[Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md)<br/>
