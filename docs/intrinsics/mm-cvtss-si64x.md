---
title: _mm_cvtss_si64x | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _mm_cvtss_si64x
dev_langs:
- C++
helpviewer_keywords:
- cvtss2si intrinsic
- _mm_cvtss_si64x intrinsic
ms.assetid: c279aff2-ee29-4271-8829-3ec691bf7718
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 947c9bf0892da52b44a99486b3ff0f1d59bc6fee
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42541524"
---
# <a name="mmcvtsssi64x"></a>_mm_cvtss_si64x
**Seção específica da Microsoft**  
  
 Gera o x64 estendido a versão do converter escalar único precisão flutuante ponto número inteiro de 64 bits (`cvtss2si`) instrução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__int64 _mm_cvtss_si64x(   
   __m128 value   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `value`  
 Um `__m128` estrutura que contém valores de ponto flutuante.  
  
## <a name="return-value"></a>Valor de retorno  
 Um inteiro de 64 bits, o resultado da conversão do primeiro valor de ponto flutuante para um número inteiro.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_mm_cvtss_si64x`|X64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
## <a name="remarks"></a>Comentários  
 O primeiro elemento da estrutura de valor é convertido em um inteiro e retornado. Os bits de controle de arredondamento no registro MXCSR são usados para determinar o comportamento de arredondamento. O padrão de modo de arredondamento é arredondado ao mais próximo, arredondar para o número par se a parte decimal é 0,5. Porque o `__m128` estrutura representa um valor de um registro de registros de MMX, ele o leva intrínseco de registrar os registros de MMX e grava-o em memória do sistema.  
  
 Essa rotina só está disponível como função intrínseca.  
  
## <a name="example"></a>Exemplo  
  
```  
// _mm_cvtss_si64x.cpp  
// processor: x64  
#include <intrin.h>  
#include <stdio.h>  
  
#pragma intrinsic(_mm_cvtss_si64x)  
  
int main()  
{  
    __m128 a;  
    __int64 b = 54;  
  
    // _mm_load_ps requires an aligned buffer.  
    __declspec(align(16)) float af[4] =  
                           { 101.25, 200.75, 300.5, 400.5 };  
  
    // Load a with the floating point values.  
    // The values will be copied to the XMM registers.  
    a = _mm_load_ps(af);  
  
    // Extract the first element of a and convert to an integer  
    b = _mm_cvtss_si64x(a);  
  
    printf_s("%I64d\n", b);  
}  
```  
  
```Output  
101  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__m128d](../cpp/m128d.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)