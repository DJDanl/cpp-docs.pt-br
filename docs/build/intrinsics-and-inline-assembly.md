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
ms.openlocfilehash: ff2b99eedcdd81a96dc3091046a4f62ffe002509
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42572320"
---
# <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e assembly embutido
Uma das restrições para o x64 compilador é fazer com que não há suporte de assembler embutido. Isso significa que funções que não pode ser gravada em C ou C++ será terá que ser escrito como sub-rotinas ou funções intrínsecas suportadas pelo compilador. Determinadas funções são dependentes do desempenho, enquanto outros não são. Funções de diferenciação de desempenho devem ser implementadas como funções intrínsecas.  
  
 Os intrínsecos suportados pelo compilador são descritos em [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)