---
title: _mm_insert_si64, _mm_inserti_si64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _mm_inserti_si64
- _mm_insert_si64
dev_langs:
- C++
helpviewer_keywords:
- insertq instruction
- _mm_insert_si64 intrinsic
- _mm_inserti_si64 intrinsic
ms.assetid: 897a4b36-8b08-4b00-a18f-7850f5732d7d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a1c6b21ded6814492557ced792772508add06e53
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712816"
---
# <a name="mminsertsi64-mminsertisi64"></a>_mm_insert_si64, _mm_inserti_si64

**Seção específica da Microsoft**  
  
Gera o `insertq` instruções para inserir os bits de seu segundo operando em seu primeiro operando.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
*Source1*<br/>
[in] Um campo de 128 bits com dados de entrada em seus 64 bits inferiores na qual um campo será inserido.  
  
*Source2*<br/>
[in] Um campo de 128 bits com os dados a serem inseridos em seus bits baixos.  Para `_mm_insert_si64`, também contém um descritor de campo no seus bits altos.  
  
*Comprimento*<br/>
[in] Uma constante de inteiro que especifica o comprimento do campo a ser inserido.  
  
*Índice*<br/>
[in] Uma constante de inteiro que especifica o índice do bit menos significativo do campo na qual os dados serão inseridos.  
  
## <a name="return-value"></a>Valor de retorno  
 Um campo de 128 bits, 64 bits cujos inferiores contêm os originais 64 bits baixos do `Source1` com o campo de bits especificada substituída pelos bits baixos do `Source2`. 64 bits superiores do valor de retorno são indefinidos.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_mm_insert_si64`|SSE4a|  
|`_mm_inserti_si64`|SSE4a|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
## <a name="remarks"></a>Comentários  
 Esse intrínseco gera o `insertq` instruções para inserir os bits do `Source2` em `Source1`. Há duas versões desse intrínseco: `_mm_inserti_si64`, é a versão de imediata, e `_mm_insert_si64` é aquele não imediato.  Cada versão extrai um campo de bits de um determinado comprimento de Source2 e o insere na Source1.  Os bits extraídos são os bits menos significativos do Source2.  O Source1 de campo no qual esses bits serão inseridos é definido, o comprimento e o índice do bit menos significativo.  Os valores do comprimento e índice serão levados mod 64, portanto, -1 e 127 são interpretados como 63. Se a soma do índice de bit (reduzidos) e tamanho do campo (reduzidos) for maior que 64, os resultados são indefinidos. Um valor de zero para o tamanho do campo é interpretado como 64.  Se o índice de comprimento e o bit de campo é os dois 63:0 zero, bits de `Source2` são inseridos em `Source1`.  Se o tamanho do campo for zero, mas o índice de bit é diferente de zero, os resultados são indefinidos.  
  
 Em uma chamada para _mm_insert_si64, o tamanho do campo está contido em bits 77:72 do Source2 e o índice no 69:64 bits.  
  
 Se você chamar `_mm_inserti_si64` com os argumentos que o compilador não pode determinar ser constantes de inteiro, o compilador gera código para empacotar esses valores em um registro de registros de MMX e para chamar `_mm_insert_si64`.  
  
 Para determinar o suporte de hardware para o `insertq` chamada de instrução de `__cpuid` intrínseco com `InfoType=0x80000001` e marque 6 bits de `CPUInfo[2] (ECX)`. Esse bit será 1 se a instrução for compatível e 0 caso contrário. Se você executar o código que usa esse intrínseco no hardware que não oferece suporte a `insertq` instrução, os resultados serão imprevisíveis.  
  
## <a name="example"></a>Exemplo  
  
```  
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

Copyright 2007 por dispositivos Micro avançada, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro dispositivos, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [_mm_extract_si64, _mm_extracti_si64](../intrinsics/mm-extract-si64-mm-extracti-si64.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)