---
title: _mm_extract_si64, _mm_extracti_si64
ms.date: 09/02/2019
f1_keywords:
- _mm_extracti_si64
- _mm_extract_si64
helpviewer_keywords:
- extrq instruction
- _mm_extracti_si64 intrinsic
- _mm_extract_si64 intrinsic
ms.assetid: 459fdd72-cc54-4ee5-bbd5-d2c6067a88e7
ms.openlocfilehash: cfd7029966c29f876f0e4f671830e20e2eacc940
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217405"
---
# <a name="_mm_extract_si64-_mm_extracti_si64"></a>_mm_extract_si64, _mm_extracti_si64

**Seção específica da Microsoft**

Gera a `extrq` instrução para extrair os bits especificados dos baixos 64 bits de seu primeiro argumento.

## <a name="syntax"></a>Sintaxe

```C
__m128i _mm_extract_si64(
   __m128i Source,
   __m128i Descriptor
);
__m128i _mm_extracti_si64(
   __m128i Source,
   int Length,
   int Index
);
```

### <a name="parameters"></a>Parâmetros

*Source*\
no Um campo de 128 bits com dados de entrada em seus bits inferiores de 64.

*Descritor*\
no Um campo de 128 bits que descreve o campo de bits a ser extraído.

*Muito*\
no Um inteiro que especifica o comprimento do campo a ser extraído.

*Index*\
no Um inteiro que especifica o índice do campo a ser extraído

## <a name="return-value"></a>Valor retornado

Um campo de 128 bits com o campo extraído em seus bits menos significativos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_extract_si64`|SSE4a|
|`_mm_extracti_si64`|SSE4a|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Esses intrínsecos geram `extrq` a instrução para extrair bits da *origem*. Há duas versões: `_mm_extracti_si64` é a versão imediata e `_mm_extract_si64` é a que não é imediata. Cada versão extrai da *fonte* um campo de bits definido por seu comprimento e o índice de seu bit menos significativo. Os valores do comprimento e do índice são obtidos em mod 64, portanto, ambos-1 e 127 são interpretados como 63. Se a soma do índice (reduzido) e o comprimento do campo (reduzido) for maior que 64, os resultados serão indefinidos. Um valor de zero para o tamanho do campo é interpretado como 64. Se o comprimento do campo e o índice de bits forem zero, o bits 63:0 da *origem* será extraído. Se o tamanho do campo for zero, mas o índice de bits for diferente de zero, os resultados serão indefinidos.

Em uma chamada para `_mm_extract_si64`, o *descritor* contém o índice em bits 13:8 e o tamanho do campo dos dados a serem extraídos em bits 5:0.

Se você chamar `_mm_extracti_si64` com argumentos que o compilador não pode determinar para ser constantes de inteiro, o compilador gerará código para empacotar esses valores emum XMM (registro) `_mm_extract_si64`e chamar.

Para determinar o suporte de hardware `extrq` para a instrução, `__cpuid` chame o `InfoType=0x80000001` intrínseco e verifique o bit `CPUInfo[2] (ECX)`6 de. Esse bit será 1 se a instrução tiver suporte e 0 caso contrário. Se você executar o código que usa esse hardware intrínseco que não dá `extrq` suporte à instrução, os resultados são imprevisíveis.

## <a name="example"></a>Exemplo

```cpp
// Compile this sample with: /EHsc
#include <iostream>
#include <intrin.h>
using namespace std;

union {
    __m128i m;
    unsigned __int64 ui64[2];
} source, descriptor, result1, result2, result3;

int
main()
{
    source.ui64[0] =     0xfedcba9876543210ll;
    descriptor.ui64[0] = 0x0000000000000b1bll;

    result1.m = _mm_extract_si64 (source.m, descriptor.m);
    result2.m = _mm_extracti_si64(source.m, 27, 11);
    result3.ui64[0] = (source.ui64[0] >> 11) & 0x7ffffff;

    cout << hex << "result1 = 0x" << result1.ui64[0] << endl;
    cout << "result2 = 0x" << result2.ui64[0] << endl;
    cout << "result3 = 0x" << result3.ui64[0] << endl;
}
```

```Output
result1 = 0x30eca86
result2 = 0x30eca86
result3 = 0x30eca86
```

**Fim da seção específica da Microsoft**

Partes de Copyright 2007 da Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzida com a permissão da Advanced Micro Devices, Inc.

## <a name="see-also"></a>Consulte também

[_mm_insert_si64, _mm_inserti_si64](../intrinsics/mm-insert-si64-mm-inserti-si64.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
