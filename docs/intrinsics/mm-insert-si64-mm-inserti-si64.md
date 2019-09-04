---
title: _mm_insert_si64, _mm_inserti_si64
ms.date: 09/02/2019
f1_keywords:
- _mm_inserti_si64
- _mm_insert_si64
helpviewer_keywords:
- insertq instruction
- _mm_insert_si64 intrinsic
- _mm_inserti_si64 intrinsic
ms.assetid: 897a4b36-8b08-4b00-a18f-7850f5732d7d
ms.openlocfilehash: 08469ad8049df2a07f0e66d650c1ca3118f8b980
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221778"
---
# <a name="_mm_insert_si64-_mm_inserti_si64"></a>_mm_insert_si64, _mm_inserti_si64

**Seção específica da Microsoft**

Gera a `insertq` instrução para inserir bits do seu segundo operando em seu primeiro operando.

## <a name="syntax"></a>Sintaxe

```C
__m128i _mm_insert_si64(
   __m128i Source1,
   __m128i Source2
);
__m128i _mm_inserti_si64(
   __m128i Source1,
   __m128i Source2
   int Length,
   int Index
);
```

### <a name="parameters"></a>Parâmetros

*Origem1*\
no Um campo de 128 bits que tem dados de entrada em seus bits inferiores de 64, nos quais um campo será inserido.

*Origem2*\
no Um campo de 128 bits que tem os dados a serem inseridos em seus bits baixos.  Para `_mm_insert_si64`, também contém um descritor de campo em seus bits superiores.

*Muito*\
no Uma constante inteira que especifica o comprimento do campo a ser inserido.

*Index*\
no Uma constante de inteiro que especifica o índice do bit menos significativo do campo no qual os dados serão inseridos.

## <a name="return-value"></a>Valor retornado

Um campo de 128 bits, cujos menores bits 64 contêm os bits baixos de 64 originais de *origem1*, com o campo de bit especificado substituído pelos bits baixos de *origem2*. Os bits superiores de 64 do valor de retorno são indefinidos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_insert_si64`|SSE4a|
|`_mm_inserti_si64`|SSE4a|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Esses intrínsecos geram `insertq` a instrução para inserir bits de *origem2* em *origem1*. Há duas versões: `_mm_inserti_si64`, é a versão imediata e `_mm_insert_si64` é a que não é imediata. Cada versão extrai um campo de bits de um determinado comprimento de Origem2 e o insere em Origem1.  Os bits extraídos são os bits menos significativos de Origem2.  O campo Origem1 no qual esses bits serão inseridos é definido pelo comprimento e pelo índice de seu bit menos significativo.  Os valores do comprimento e do índice são obtidos em mod 64, portanto, ambos-1 e 127 são interpretados como 63. Se a soma do índice de bits (reduzido) e o comprimento do campo (reduzido) for maior que 64, os resultados serão indefinidos. Um valor de zero para o tamanho do campo é interpretado como 64. Se o comprimento do campo e o índice de bits forem zero, o bits 63:0 de *origem2* será inserido em *origem1*. Se o tamanho do campo for zero, mas o índice de bits for diferente de zero, os resultados serão indefinidos.

Em uma chamada para _mm_insert_si64, o tamanho do campo está contido em bits 77:72 de Origem2 e no índice em bits 69:64.

Se você chamar `_mm_inserti_si64` com argumentos que o compilador não pode determinar para ser constantes de inteiro, o compilador gerará código para empacotar esses valores em um registro `_mm_insert_si64`de XMM e chamar.

Para determinar o suporte de hardware `insertq` para a instrução, `__cpuid` chame o `InfoType=0x80000001` intrínseco e verifique o bit `CPUInfo[2] (ECX)`6 de. Esse bit será 1 se a instrução tiver suporte e 0 caso contrário. Se você executar o código que usa o intrínseco em hardware que não oferece `insertq` suporte à instrução, os resultados serão imprevisíveis.

## <a name="example"></a>Exemplo

```cpp
// Compile this sample with: /EHsc
#include <iostream>
#include <intrin.h>
using namespace std;

union {
    __m128i m;
    unsigned __int64 ui64[2];
} source1, source2, source3, result1, result2, result3;

int
main()
{

    __int64 mask;

    source1.ui64[0] = 0xffffffffffffffffll;
    source2.ui64[0] = 0xfedcba9876543210ll;
    source2.ui64[1] = 0xc10;
    source3.ui64[0] = source2.ui64[0];

    result1.m = _mm_insert_si64 (source1.m, source2.m);
    result2.m = _mm_inserti_si64(source1.m, source3.m, 16, 12);
    mask = 0xffff << 12;
    mask = ~mask;
    result3.ui64[0] = (source1.ui64[0] & mask) |
                      ((source2.ui64[0] & 0xffff) << 12);

    cout << hex << "result1 = 0x" << result1.ui64[0] << endl;
    cout << "result2 = 0x" << result2.ui64[0] << endl;
    cout << "result3 = 0x" << result3.ui64[0] << endl;

}
```

```Output
result1 = 0xfffffffff3210fff
result2 = 0xfffffffff3210fff
result3 = 0xfffffffff3210fff
```

**Fim da seção específica da Microsoft**

Partes de Copyright 2007 da Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzida com a permissão da Advanced Micro Devices, Inc.

## <a name="see-also"></a>Consulte também

[_mm_extract_si64, _mm_extracti_si64](../intrinsics/mm-extract-si64-mm-extracti-si64.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
