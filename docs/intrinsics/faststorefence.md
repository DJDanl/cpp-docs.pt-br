---
title: __faststorefence | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- __faststorefence_cpp
- __faststorefence
dev_langs:
- C++
helpviewer_keywords:
- __faststorefence intrinsic
- sfence instruction
ms.assetid: 6c6eb973-3cf0-4306-b3af-cfde9b0210a5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 70999adc4bba03b3a8b00ad10330b18c68695af8
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="faststorefence"></a>__faststorefence
**Seção específica da Microsoft**  
  
 Garante que cada referência anterior de memória, inclusive carregar e armazena as referências de memória, é globalmente visíveis antes de qualquer referência memória subsequentes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __faststorefence();  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__faststorefence`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Gera uma sequência de instruções de barreira total de memória que garantias de carregar e armazenam operações emitido antes são intrínseco globalmente continua visível antes da execução. O efeito é comparável ao mas mais rápido do que o `_mm_mfence` intrínseco em x64 todas as plataformas.  
  
 Na plataforma AMD64, esta rotina gera uma instrução que é um limite de armazenamento mais rápido que o `sfence` instrução. Código crítico em termos de tempo, use nesse intrínseco em vez de `_mm_sfence` apenas em plataformas AMD64. Em plataformas de Intel x64, a `_mm_sfence` instrução é mais rápida.  
  
 Essa rotina só está disponível como função intrínseca.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)