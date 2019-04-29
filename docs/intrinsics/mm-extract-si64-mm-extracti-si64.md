---
title: _mm_extract_si64, _mm_extracti_si64
ms.date: 11/04/2016
f1_keywords:
- _mm_extracti_si64
- _mm_extract_si64
helpviewer_keywords:
- extrq instruction
- _mm_extracti_si64 intrinsic
- _mm_extract_si64 intrinsic
ms.assetid: 459fdd72-cc54-4ee5-bbd5-d2c6067a88e7
ms.openlocfilehash: e77ca5589ed50a4199921603afec1d9888c6cca5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62263692"
---
# <a name="mmextractsi64-mmextractisi64"></a>_mm_extract_si64, _mm_extracti_si64

**Seção específica da Microsoft**

Gera o `extrq` instruções para extrair seu de 64 bits baixos do seu primeiro argumento especificado do bits.

## <a name="syntax"></a>Sintaxe

```
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

#### <a name="parameters"></a>Parâmetros

*Source*<br/>
[in] Um campo de 128 bits com dados de entrada em seus 64 bits inferiores.

*Descritor*<br/>
[in] Um campo de 128 bits que descreve o campo de bits para extrair.

*Comprimento*<br/>
[in] Um inteiro que especifica o comprimento do campo para extrair.

*Índice*<br/>
[in] Um inteiro que especifica o índice do campo para extrair

## <a name="return-value"></a>Valor de retorno

Um campo de 128 bits com o campo extraído em seus bits menos significativos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_extract_si64`|SSE4a|
|`_mm_extracti_si64`|SSE4a|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco gera o `extrq` instruções para extrair os bits do `Source`. Há duas versões desse intrínseco: `_mm_extracti_si64` é a versão de imediata, e `_mm_extract_si64` é aquele não imediato.  Cada versão extrai `Source` um campo de bits definido por seu tamanho e o índice do bit menos significativo. Os valores do comprimento e índice serão levados mod 64, portanto, -1 e 127 são interpretados como 63. Se a soma do tamanho do campo (reduzidos) e índice (reduzidos) for maior que 64, os resultados são indefinidos. Um valor de zero para o tamanho do campo é interpretado como 64. Se o índice de comprimento e o bit de campo é os dois 63:0 zero, bits de `Source` são extraídos. Se o tamanho do campo for zero, mas o índice de bit é diferente de zero, os resultados são indefinidos.

Em uma chamada para _mm_extract_si64, o `Descriptor` contém o índice em 13:8 bits e o tamanho do campo de dados a ser extraído em 5 de bits: 0...

Se você chamar `_mm_extracti_si64` com argumentos que o compilador não pode determinar ser constantes de inteiro, o compilador gera código para empacotar esses valores em um registro de registros de MMX (`Descriptor`) e chamar `_mm_extract_si64`.

Para determinar o suporte de hardware para o `extrq` instrução, a chamada a `__cpuid` intrínseco com `InfoType=0x80000001` e marque 6 bits de `CPUInfo[2] (ECX)`. Esse bit será 1 se a instrução for compatível e 0 caso contrário. Se você executar o código que usa este hardware intrínseco que não oferece suporte a `extrq` instrução, os resultados serão imprevisíveis.

## <a name="example"></a>Exemplo

```
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

Copyright 2007 por dispositivos Micro avançada, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro dispositivos, Inc.

## <a name="see-also"></a>Consulte também

[_mm_insert_si64, _mm_inserti_si64](../intrinsics/mm-insert-si64-mm-inserti-si64.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)