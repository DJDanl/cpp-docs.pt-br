---
title: "_rotl8, _rotl16 | Microsoft Docs"
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
  - "_rotl8"
  - "_rotl16"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_rotl16 intrínseca"
  - "_rotl8 intrínseca"
ms.assetid: 8c519ab6-aef9-4f07-a387-daee8408368f
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _rotl8, _rotl16
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Gire os valores de entrada à esquerda para o bit mais significativo \(MSB\) por um número especificado de posições de bits.  
  
## Sintaxe  
  
```  
unsigned char _rotl8(     unsigned char value,     unsigned char shift  ); unsigned short _rotl16(     unsigned short value,     unsigned char shift  );  
```  
  
#### Parâmetros  
 \[in\] `value`  
 O valor a ser girado.  
  
 \[in\] `shift`  
 O número de bits a girar.  
  
## Valor de retorno  
 O valor girado.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_rotl8`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`_rotl16`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Ao contrário de uma operação de deslocamento à esquerda, ao executar um giro à direita, os bits da extremidade alta são movidos para as posições de bits menos significativas.  
  
## Exemplo  
  
```  
// rotl.cpp  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_rotl8, _rotl16)  
  
int main()  
{  
    unsigned char c = 'A', c1, c2;  
  
    for (int i = 0; i < 8; i++)  
    {  
       printf_s("Rotating 0x%x left by %d bits gives 0x%x\n", c,  
               i, _rotl8(c, i));  
    }  
  
    unsigned short s = 0x12;  
    int nBit = 10;  
  
    printf_s("Rotating unsigned short 0x%x left by %d bits gives 0x%x\n",  
            s, nBit, _rotl16(s, nBit));  
}  
```  
  
  **Girar 0x41 à esquerda por 0 bit resulta em 0x41**  
**Girar 0x41 à esquerda por 1 bit resulta em 0x82**  
**Girar 0x41 à esquerda por 2 bits resulta em 0x5**  
**Girar 0x41 à esquerda por 3 bits resulta em 0xa**  
**Girar 0x41 à esquerda por 4 bits resulta em 0x14**  
**Girar 0x41 à esquerda por 5 bits resulta em 0x28**  
**Girar 0x41 à esquerda por 6 bits resulta em 0x50**  
**Girar 0x41 à esquerda por 7 bits resulta em 0xa0**  
**Girar curto sem sinal 0x12 à esquerda por 10 bits resulta em 0x4800**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [\_rotr8, \_rotr16](../intrinsics/rotr8-rotr16.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)