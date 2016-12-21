---
title: "__int8, __int16, __int32, __int64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__int8_cpp"
  - "__int64"
  - "__int8"
  - "__int16"
  - "__int16_cpp"
  - "__int64_cpp"
  - "__int32_cpp"
  - "__int32"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __int16 [C++]"
  - "Palavra-chave __int32 [C++]"
  - "Palavra-chave __int64 [C++]"
  - "Palavra-chave __int8 [C++]"
  - "tipo de dados inteiro, tipos de inteiros em C++"
  - "tipos de inteiros [C++]"
ms.assetid: 8e384602-2578-4980-8cc8-da63842356b2
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __int8, __int16, __int32, __int64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 O Microsoft C\/C\+\+ tem suporte para tipos de inteiros dimensionados.  Você pode declarar variáveis de inteiro de 8, 16, 32 ou 64 bits usando o tipo de especificador **\_\_int***n*, em que *n* é 8, 16, 32 ou 64.  
  
 O exemplo a seguir declara uma variável para cada um desses tipos de inteiros dimensionados:  
  
```  
__int8 nSmall;      // Declares 8-bit integer  
__int16 nMedium;    // Declares 16-bit integer  
__int32 nLarge;     // Declares 32-bit integer  
__int64 nHuge;      // Declares 64-bit integer  
```  
  
 Os tipos `__int8`, `__int16` e `__int32` são sinônimos dos tipos ANSI que têm o mesmo tamanho e são úteis para escrever o código portátil que se comporta de forma idêntica em várias plataformas.  O tipo de dados `__int8` é sinônimo do tipo `char`, `__int16` é sinônimo do tipo **short** e `__int32` é sinônimo do tipo `int`.  O tipo `__int64` não tem equivalente ANSI.  
  
## Exemplo  
 O exemplo a seguir mostra que um parâmetro \_\_int*xx* será promovido para `int`:  
  
```  
// sized_int_types.cpp  
  
#include <stdio.h>  
  
void func(int i) {  
    printf_s("%s\n", __FUNCTION__);  
}  
  
int main()  
{  
    __int8 i8 = 100;  
    func(i8);   // no void func(__int8 i8) function  
                // __int8 will be promoted to int  
}  
```  
  
  **func**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)   
 [Intervalos de tipos de dados](../cpp/data-type-ranges.md)