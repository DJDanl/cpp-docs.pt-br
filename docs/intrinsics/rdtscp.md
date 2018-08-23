---
title: __rdtscp | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __rdtscp
dev_langs:
- C++
helpviewer_keywords:
- rdtscp intrinsic
- __rdtscp intrinsic
- rdtscp instruction
ms.assetid: f17d9a9c-88bb-44e0-b69d-d516bc1c93ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a98f1e84f3ef09d3cef5d45028374b93887fc6d4
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42544391"
---
# <a name="rdtscp"></a>__rdtscp
**Seção específica da Microsoft**  
  
 Gera o `rdtscp` instrução, grava `TSC_AUX[31:0`] à memória e retorna o contador de carimbo de data / hora 64-bit (`TSC)` resultado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 __rdtscp(  
   unsigned int * Aux  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `Aux`  
 Ponteiro para um local que conterá o conteúdo do registro específicas do computador `TSC_AUX[31:0]`.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma contagem de tiques do inteiro sem sinal de 64 bits.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__rdtscp`|Família de NPT AMD 0Fh ou versões posteriores|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
## <a name="remarks"></a>Comentários  
 Esse intrínseco gera o `rdtscp` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco com `InfoType=0x80000001` e marque pouco 27 de `CPUInfo[3] (EDX)`. Esse bit é 1 se a instrução for compatível e 0, caso contrário.  Se você executar o código que usa esse intrínseco no hardware que não oferece suporte a `rdtscp` instrução, os resultados serão imprevisíveis.  
  
> [!CAUTION]
>  Diferentemente `rdtsc`, `rdtscp` é uma instrução de serialização; no entanto, o compilador pode mover o código em torno disso intrínseco.  
  
 A interpretação do valor TSC nessa geração de hardware é diferente do que em versões anteriores do x64.  Consulte os manuais de hardware para obter mais informações.  
  
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
 Copyright 2007 por dispositivos Micro avançada, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro dispositivos, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [__rdtsc](../intrinsics/rdtsc.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)