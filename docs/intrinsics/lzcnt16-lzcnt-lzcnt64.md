---
title: "__lzcnt16, __lzcnt, __lzcnt64 | Microsoft Docs"
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
  - "__lzcnt64"
  - "__lzcnt16"
  - "__lzcnt"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__lzcnt intrínseco"
  - "instrução lzcnt"
  - "lzcnt16 intrínseco"
  - "lzcnt intrínseco"
  - "__lzcnt16 intrínseco"
  - "lzcnt64 intrínseco"
  - "__lzcnt64 intrínseco"
ms.assetid: 412113e7-052e-46e5-8bfa-d5ad72abc10e
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __lzcnt16, __lzcnt, __lzcnt64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Conta o número das principais zeros em um 16, 32 ou inteiro de 64 bytes.  
  
## Sintaxe  
  
```  
unsigned short __lzcnt16(  
   unsigned short value  
);  
unsigned int __lzcnt(  
   unsigned int value  
);  
unsigned __int64 __lzcnt64(  
   unsigned __int64 value  
);  
```  
  
#### Parâmetros  
 \[in\] `value`  
 Os 16, 32 ou inteiro não assinado de 64 bits para verificar se há zeros à esquerda.  
  
## Valor de retorno  
 O número de líderes em valores zero a `value` parâmetro. Se `value` for zero, o valor de retorno é o tamanho do operando entrado \(16, 32 ou 64\). Se mais bit significativo de `value` é um, o valor de retorno é zero.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__lzcnt16`|AMD: Manipulação de bits avançada \(ABM\)<br /><br /> Intel: Haswell|  
|`__lzcnt`|AMD: Manipulação de bits avançada \(ABM\)<br /><br /> Intel: Haswell|  
|`__lzcnt64`|AMD: Avançados de manipulação de bits \(ABM\) no modo de 64 bits.<br /><br /> Intel: Haswell|  
  
 **Arquivo de cabeçalho** \< intrin. h \>  
  
## Comentários  
 Cada um desses intrínsecos gera o `lzcnt` instrução.  O tamanho do valor que o `lzcnt` instrução retorna é igual ao tamanho do argumento.  No modo de 32 bits não há nenhum 64\-bit registros de uso geral, portanto, não de 64 bits `lzcnt`.  
  
 Para determinar o suporte de hardware para o `lzcnt` chamada de instrução de `__cpuid` intrínseco com `InfoType=0x80000001` e verifique se o bit 5 da `CPUInfo[2] (ECX)`. Esse bit será 1 se a instrução tiver suporte e 0 caso contrário. Se você executar o código que usa esse intrínseco no hardware que não oferece suporte a `lzcnt` instrução, os resultados serão imprevisíveis.  
  
 Em processadores Intel que não dão suporte a `lzcnt` instrução, a codificação de byte de instrução é executada como `bsr` \(bit inverso de verificação\). Se a portabilidade de código for uma preocupação, considere o uso do `_BitScanReverse` intrínseco em vez disso. Para obter mais informações, consulte [\_BitScanReverse, \_BitScanReverse64](../intrinsics/bitscanreverse-bitscanreverse64.md).  
  
## Exemplo  
  
```  
// Compile this test with: /EHsc  
#include <iostream>   
#include <intrin.h>   
using namespace std;   
  
int main()   
{  
  unsigned short us[3] = {0, 0xFF, 0xFFFF};  
  unsigned short usr;  
  unsigned int   ui[4] = {0, 0xFF, 0xFFFF, 0xFFFFFFFF};  
  unsigned int   uir;  
  
  for (int i=0; i<3; i++) {  
    usr = __lzcnt16(us[i]);  
    cout << "__lzcnt16(0x" << hex << us[i] << ") = " << dec << usr << endl;  
  }  
  
  for (int i=0; i<4; i++) {  
    uir = __lzcnt(ui[i]);  
    cout << "__lzcnt(0x" << hex << ui[i] << ") = " << dec << uir << endl;  
  }  
}  
  
```  
  
```Output  
__lzcnt16(0x0) = 16 __lzcnt16(0xff) = 8 __lzcnt16(0xffff) = 0 __lzcnt(0x0) = 32 __lzcnt(0xff) = __lzcnt(0xffff) 24 = 16 __lzcnt(0xffffffff) = 0  
```  
  
## FIM de específico da Microsoft  
 Partes deste conteúdo foram Copyright 2007 por Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro Devices, Inc.  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)