---
title: "_mm_extract_si64, _mm_extracti_si64 | Microsoft Docs"
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
  - "_mm_extracti_si64"
  - "_mm_extract_si64"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução extrq"
  - "_mm_extracti_si64 intrínseco"
  - "_mm_extract_si64 intrínseco"
ms.assetid: 459fdd72-cc54-4ee5-bbd5-d2c6067a88e7
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mm_extract_si64, _mm_extracti_si64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o `extrq` instruções para extrair os bits especificados do 64 bits baixos de seu primeiro argumento.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 \[in\]`Source`  
 Um campo de 128 bits com dados de entrada de 64 bits inferiores.  
  
 \[in\]`Descriptor`  
 Um campo de 128 bits que descreve o campo de bits para extrair.  
  
 \[in\]`Length`  
 Um inteiro que especifica o comprimento do campo para extrair.  
  
 \[in\]`Index`  
 Um inteiro que especifica o índice do campo para extrair  
  
## Valor de retorno  
 Um campo de 128 bits com o campo extraído em seus bits menos significativos.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`_mm_extract_si64`|SSE4a|  
|`_mm_extracti_si64`|SSE4a|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínsecas gera o `extrq` instruções para extrair os bits de `Source`.Há duas versões intrínsecas: `_mm_extracti_si64` é a versão imediata e `_mm_extract_si64` é o não\-imediatos.  Cada versão extrai de `Source` um campo de bits definido pelo seu comprimento e o índice do bit menos significativo.  Os valores de comprimento e índice são tirados mod 64, portanto, \-1 e 127 são interpretados como 63.  Se a soma do comprimento do campo \(menor\) e índice \(reduzido\) é maior que 64, os resultados são indefinidos.  Um valor de zero para o comprimento do campo é interpretado como 64.  Se o índice de bit e de comprimento de campo forem ambos zero, 63:0 de bits de `Source` são extraídos.  Se o comprimento do campo é zero, mas o índice de bit é diferente de zero, os resultados são indefinidos.  
  
 Em uma chamada para \_mm\_extract\_si64, o `Descriptor` contém o índice em 13: 8 bits e o comprimento do campo de dados sejam extraídos em bits 5: 0..  
  
 Se você chamar `_mm_extracti_si64` com argumentos que o compilador não pode determinar constantes de inteiro, o compilador gera código pack esses valores em um registro XMM \(`Descriptor`\) e chamar `_mm_extract_si64`.  
  
 Para determinar o suporte de hardware para o `extrq` instrução, chamada de `__cpuid` intrínseca com `InfoType=0x80000001` e verificar o bit 6 do `CPUInfo[2] (ECX)`.  Esse bit será 1 se a instrução for aceito e 0 caso contrário.  Se você executar o código que usa este hardware intrínseca que não oferece suporte a `extrq` as instruções, os resultados são imprevisíveis.  
  
## Exemplo  
  
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
  
  **Resultado1 \= 0x30eca86 Resultado2 \= result3 0x30eca86 \= 0x30eca86**   
## END Microsoft específicos  
 Copyright 2007 pela Advanced Micro dispositivos, Inc. todos os direitos reservados.  Reproduzido com permissão do Advanced Micro dispositivos, Inc.  
  
## Consulte também  
 [\_mm\_insert\_si64, \_mm\_inserti\_si64](../Topic/_mm_insert_si64,%20_mm_inserti_si64.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)