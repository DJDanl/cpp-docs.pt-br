---
title: __rdtscp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __rdtscp
dev_langs: C++
helpviewer_keywords:
- rdtscp intrinsic
- __rdtscp intrinsic
- rdtscp instruction
ms.assetid: f17d9a9c-88bb-44e0-b69d-d516bc1c93ee
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 697b06bcddbaadb8c3a8a1dece761cdf31a31527
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="rdtscp"></a>__rdtscp
**Seção específica da Microsoft**  
  
 Gera o `rdtscp` instrução, grava `TSC_AUX[31:0`] para a memória e retorna o contador de carimbo de data / hora 64 bits (`TSC)` resultados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 __rdtscp(  
   unsigned int * Aux  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `Aux`  
 Ponteiro para um local que conterá o conteúdo do registro específicas de computador `TSC_AUX[31:0]`.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma contagem de tiques de inteiro não assinado de 64 bits.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__rdtscp`|Família de NPT AMD 0Fh ou versões posteriores|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Nesse intrínsecas gera o `rdtscp` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco com `InfoType=0x80000001` e verifique se o bit 27 de `CPUInfo[3] (EDX)`. Esse bit for 1 se a instrução tiver suporte e 0, caso contrário.  Se você executar o código que usa nesse intrínseco no hardware que não oferece suporte a `rdtscp` instrução, os resultados são imprevisíveis.  
  
> [!CAUTION]
>  Ao contrário de `rdtsc`, `rdtscp` é uma instrução de serialização; no entanto, o compilador pode mover o código ao redor isso intrínseco.  
  
 A interpretação do valor TSC nessa geração de hardware é diferente em versões anteriores do [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)].  Consulte os manuais de hardware para obter mais informações.  
  
 O significado do valor em `TSC_AUX[31:0]` depende do sistema operacional.  
  
## <a name="example"></a>Exemplo  
  
```  
#include <intrin.h>   
#include <stdio.h>  
int main()   
{  
 unsigned __int64 i;  
 unsigned int ui;  
 i = __rdtscp(&ui);  
 printf_s("%I64d ticks\n", i);  
 printf_s("TSC_AUX was %x\n", ui);  
}  
```  
  
```Output  
3363423610155519 ticks  
TSC_AUX was 0  
```  
  
**Fim da seção específica da Microsoft**  
 Copyright 2007 Advanced Micro dispositivos, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro Devices, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [__rdtsc](../intrinsics/rdtsc.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)