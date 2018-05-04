---
title: Intrínsecos e Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8affd4bb-279d-46f3-851f-8be0a9c5ed3f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5b8651bea0b1ee9f54ec0af704d92feef0722368
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e assembly embutido
Uma das restrições para o [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] compilador é fazer com que não há suporte do assembler embutido. Isso significa que as funções que não pode ser gravada em C ou C++ em terá que ser escrito como sub-rotinas ou funções intrínsecas suportadas pelo compilador. Determinadas funções são confidenciais de desempenho e outros não. Funções de diferenciação de desempenho devem ser implementadas como funções intrínsecas.  
  
 Os intrínsecos suportados pelo compilador são descritos na [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)