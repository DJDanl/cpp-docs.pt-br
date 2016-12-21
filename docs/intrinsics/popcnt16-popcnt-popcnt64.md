---
title: "__popcnt16, __popcnt, __popcnt64 | Microsoft Docs"
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
  - "__popcnt64"
  - "__popcnt"
  - "__popcnt16"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução popcnt"
  - "__popcnt16"
  - "__popcnt64"
  - "__popcnt"
ms.assetid: e525b236-adc8-42df-9b9b-8b7d8c245d3b
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __popcnt16, __popcnt, __popcnt64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Conta o número de um bits \(contagem de população\) em 16\-, 32 ou 64 bytes inteiro não assinado.  
  
## Sintaxe  
  
```  
unsigned short __popcnt16(  
   unsigned short value  
);  
unsigned int __popcnt(  
   unsigned int value  
);  
unsigned __int64 __popcnt64(  
   unsigned __int64 value  
);  
```  
  
#### Parâmetros  
 \[in\]`value`  
 16\-, 32 Ou 64 bits inteiro não assinado para o qual queremos a contagem de população.  
  
## Valor de retorno  
 O número de bits de um a `value` parâmetro.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__popcnt16`|Avançados de manipulação de bits|  
|`__popcnt`|Avançados de manipulação de bits|  
|`__popcnt64`|Avançados de manipulação de bits no modo de 64 bits.|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Cada um desses intrínsecos gera o `popcnt` instrução.  O tamanho do valor que o `popcnt` instrução retorna é o mesmo tamanho do argumento.  No modo de 32 bits não há nenhuma 64 bits geral registra, portanto, não de 64 bits `popcnt`.  
  
 Para determinar o suporte de hardware para o `popcnt` instrução, chamada de `__cpuid` intrínseca com `InfoType=0x00000001` e verificar o bit 23 de `CPUInfo[2] (ECX)`.  Este bit é 1 se houver suporte para a instrução e 0 caso contrário.  Se você executa código que usa intrínseca neste hardware não oferece suporte a `popcnt` as instruções, os resultados são imprevisíveis.  
  
## Exemplo  
  
```  
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
    usr = __popcnt16(us[i]);  
    cout << "__popcnt16(0x" << hex << us[i] << ") = " << dec << usr << endl;  
  }  
  
  for (int i=0; i<4; i++) {  
    uir = __popcnt(ui[i]);  
    cout << "__popcnt(0x" << hex << ui[i] << ") = " << dec << uir << endl;  
  }  
}  
  
```  
  
  **\_\_popcnt16\(0x0\) \= 0 \_\_popcnt16\(0xff\) \= \_\_popcnt16\(0xffff\) 8 \= 16 \_\_popcnt\(0x0\) \= 0 \_\_popcnt\(0xff\) \= 8 \_\_oopcnt\(0xffff\) \= \_\_popcnt\(0xffffffff\) 16 \= 32**   
## END Microsoft específicos  
 Copyright 2007 pela Advanced Micro dispositivos, Inc. todos os direitos reservados.  Reproduzido com permissão do Advanced Micro dispositivos, Inc.  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)