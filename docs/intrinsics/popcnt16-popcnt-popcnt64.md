---
title: __popcnt16, __popcnt, __popcnt64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- __popcnt64
- __popcnt
- __popcnt16
dev_langs:
- C++
helpviewer_keywords:
- popcnt instruction
- __popcnt16
- __popcnt64
- __popcnt
ms.assetid: e525b236-adc8-42df-9b9b-8b7d8c245d3b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ce622f6283036dc3bde24f526da4c5256474ce00
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="popcnt16-popcnt-popcnt64"></a>__popcnt16, __popcnt, __popcnt64
**Seção específica da Microsoft**  
  
 Conta o número de um bits (contagem de população) em um 16, 32 ou inteiro não assinado de 64 bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 [in] `value`  
 A 16, 32 ou inteiro não assinado de 64 bits para os quais queremos que a contagem de população.  
  
## <a name="return-value"></a>Valor de retorno  
 O número de bits um o `value` parâmetro.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__popcnt16`|Manipulação de bits avançadas|  
|`__popcnt`|Manipulação de bits avançadas|  
|`__popcnt64`|Manipulação de bits avançadas no modo de 64 bits.|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Cada um desses intrínsecos gera o `popcnt` instrução.  O tamanho do valor que o `popcnt` instrução retorna é o mesmo que o tamanho do argumento.  Em modo de 32 bits são sem 64-bit para fins gerais registros, portanto, não de 64 bits `popcnt`.  
  
 Para determinar o suporte de hardware para o `popcnt` instrução, chamada de `__cpuid` intrínseco com `InfoType=0x00000001` e verifique se o bit 23 de `CPUInfo[2] (ECX)`. Esse bit for 1 se a instrução tiver suporte e 0, caso contrário. Se você executar o código que usa nesse intrínseco no hardware que não oferece suporte a `popcnt` instrução, os resultados são imprevisíveis.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
__popcnt16(0x0) = 0  
__popcnt16(0xff) = 8  
__popcnt16(0xffff) = 16  
__popcnt(0x0) = 0  
__popcnt(0xff) = 8  
__popcnt(0xffff) = 16  
__popcnt(0xffffffff) = 32  
```  
  
**Fim da seção específica da Microsoft**  
 Copyright 2007 Advanced Micro dispositivos, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro Devices, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
