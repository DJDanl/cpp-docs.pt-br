---
title: "Intrínsecos e Assembly embutido | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 8affd4bb-279d-46f3-851f-8be0a9c5ed3f
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 80eb16eb7fde49c499227bb3d60000e2ac6e5143
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e assembly embutido
Uma das restrições para o [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] compilador é fazer com que não há suporte do assembler embutido. Isso significa que as funções que não pode ser gravada em C ou C++ em terá que ser escrito como sub-rotinas ou funções intrínsecas suportadas pelo compilador. Determinadas funções são confidenciais de desempenho e outros não. Funções de diferenciação de desempenho devem ser implementadas como funções intrínsecas.  
  
 Os intrínsecos suportados pelo compilador são descritos na [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)