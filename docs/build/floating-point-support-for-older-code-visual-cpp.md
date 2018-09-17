---
title: Suporte de ponto flutuante para código anterior (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a2a26b96-7bc2-418a-981a-51aa1a0294a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7285325bf1a934afcef337da318d019ec6fe375c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706804"
---
# <a name="floating-point-support-for-older-code-visual-c"></a>Suporte de ponto flutuante para código anterior (Visual C++)

O MMX e os registros de pilha de ponto flutuante (MM0-MM7/ST0-ST7) são preservados entre alternâncias de contexto.  Não há nenhum convenção de chamada explícita para esses registros.  O uso desses registros é estritamente proibido no código em modo kernel.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)