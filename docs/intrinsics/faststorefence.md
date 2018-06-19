---
title: faststorefence | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f8c4a343126a14e1aea931b1e154714af280904
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33327792"
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