---
title: _mm_cvttss_si64x | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _mm_cvttss_si64x
dev_langs:
- C++
helpviewer_keywords:
- _mm_cvttss_si64x intrinsic
- cvttss2si instruction
ms.assetid: f9a3fd07-5bd8-4758-8744-6315c082cf87
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c4fd8aebb3f9a4f0078c8174aa25b9abb9378f1b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33333623"
---
# <a name="mmcvttsssi64x"></a>_mm_cvttss_si64x
**Seção específica da Microsoft**  
  
 Emite x64 estendidos versão de Convert com número de ponto flutuante de precisão simples de truncamento em inteiro de 64 bits (`cvttss2si`) instrução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__int64 _mm_cvttss_si64x(   
   __m128 value   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `value`  
 Um `__m128` estrutura que contém valores de ponto flutuante de precisão simples.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado da conversão do primeiro valor de ponto flutuante para um inteiro de 64 bits.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_mm_cvttss_si64x`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Difere intrínseca `_mm_cvtss_si64x` apenas se inexato conversões são truncados em direção a zero. Porque o `__m128` estrutura representa um registro XMM, a instrução gerada move os dados de um registro XMM na memória do sistema.  
  
 Essa rotina só está disponível como função intrínseca.  
  
## <a name="example"></a>Exemplo  
  
```  
// _mm_cvttss_si64x.cpp  
// processor: x64  
#include <intrin.h>  
#include <stdio.h>  
  
#pragma intrinsic(_mm_cvttss_si64x)  
  
int main()  
{  
    __m128 a;  
    __int64 b = 54;  
  
    // _mm_load_ps requires an aligned buffer.  
    __declspec(align(16)) float af[4] = { 101.5, 200.75,  
                                          300.5, 400.5 };  
  
    // Load a with the floating point values.  
    // The values will be copied to the XMM registers.  
    a = _mm_load_ps(af);  
  
    // Extract the first element of a and convert to an integer  
    b = _mm_cvttss_si64x(a);  
  
    printf_s("%I64d\n", b);  
}  
```  
  
```Output  
101  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__m128](../cpp/m128.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)