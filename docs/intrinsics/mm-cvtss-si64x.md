---
title: "_mm_cvtss_si64x | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_mm_cvtss_si64x"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cvtss2si intrínseco"
  - "_mm_cvtss_si64x intrínseco"
ms.assetid: c279aff2-ee29-4271-8829-3ec691bf7718
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mm_cvtss_si64x
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] versão estendida do converter Scalar única precisão flutuante ponto número para um inteiro de 64 bits \(`cvtss2si`\) instrução.  
  
## Sintaxe  
  
```  
__int64 _mm_cvtss_si64x(   
   __m128 value   
);  
```  
  
#### Parâmetros  
 \[in\]`value`  
 Um `__m128` estrutura que contém valores de ponto flutuante.  
  
## Valor de retorno  
 Um inteiro de 64 bits, o resultado da conversão do primeiro valor de ponto flutuante para um inteiro.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`_mm_cvtss_si64x`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O primeiro elemento de valor estrutura é convertido para um inteiro e retornado.  Os bits de controle de arredondamento em MXCSR são usados para determinar o comportamento de arredondamento.  O padrão arredondamento modo é arredondado para mais próximo, se a parte decimal é 0,5 o arredondamento para o número par.  Porque o `__m128` estrutura representa um registro XMM neste intrínseco leva um valor do registro XMM e grava\-memória do sistema.  
  
 Esta rotina só está disponível como um intrínseco.  
  
## Exemplo  
  
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
  
  **101**   
## END Microsoft específicos  
  
## Consulte também  
 [\_\_m128d](../cpp/m128d.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)