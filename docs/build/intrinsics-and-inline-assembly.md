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
ms.openlocfilehash: 6a87e577af339099eda56a3b9d91929a05253a43
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45716242"
---
# <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e assembly embutido

Uma das restrições para o x64 compilador é fazer com que não há suporte de assembler embutido. Isso significa que funções que não pode ser gravada em C ou C++ será terá que ser escrito como sub-rotinas ou funções intrínsecas suportadas pelo compilador. Determinadas funções são dependentes do desempenho, enquanto outros não são. Funções de diferenciação de desempenho devem ser implementadas como funções intrínsecas.

Os intrínsecos suportados pelo compilador são descritos em [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)