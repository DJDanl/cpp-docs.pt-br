---
title: "_rotr8, _rotr16 | Microsoft Docs"
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
  - "_rotr16"
  - "_rotr8"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_rotr16 intrínseca"
  - "_rotr8 intrínseca"
ms.assetid: dfbd2c82-82b4-427a-ad52-51609027ebff
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _rotr8, _rotr16
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Gire os valores de entrada para a direita para o bit menos significativo \(LSB\) por um número especificado de posições de bits.  
  
## Sintaxe  
  
```  
unsigned char _rotr8(     unsigned char value,     unsigned char shift  ); unsigned short _rotr16(     unsigned short value,     unsigned char shift  );  
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
|`_rotr8`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`_rotr16`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Ao contrário de uma operação de deslocamento à direita, ao executar um giro à direita, os bits da extremidade baixa são movidos para as posições de bits de ordem alta.  
  
## Exemplo  
  
```  
// rotr.cpp  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_rotr8, _rotr16)  
  
int main()  
{  
    unsigned char c = 'A', c1, c2;  
  
    for (int i = 0; i < 8; i++)  
    {  
       printf_s("Rotating 0x%x right by %d bits gives 0x%x\n", c,  
                i, _rotr8(c, i));  
    }  
  
    unsigned short s = 0x12;  
    int nBit = 10;  
  
    printf_s("Rotating unsigned short 0x%x right by %d bits "  
             "gives 0x%x\n",  
            s, nBit, _rotr16(s, nBit));  
}  
```  
  
  **Girar 0x41 à direita por 0 bit resulta em 0x41**  
**Girar 0x41 à direita por 1 bit resulta em 0xa0**  
**Girar 0x41 à direita por 2 bits resulta em 0x50**  
**Girar 0x41 à direita por 3 bits resulta em0x28**  
**Girar 0x41 à direita por 4 bits resulta em 0x14**  
**Girar 0x41 à direita por 5 bits resulta em 0xa**  
**Girar 0x41 à direita por 6 bits resulta em 0x5**  
**Girar 0x41 à direita por 7 bits resulta em 0x82**  
**Girar curto sem sinal 0x12 à direita por 10 bits resulta em 0x480**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [\_rotl8, \_rotl16](../intrinsics/rotl8-rotl16.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)