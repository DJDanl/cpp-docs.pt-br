---
title: Instruções de iteração (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- iteration statements
- loop structures, iteration statements
ms.assetid: bf6d75f7-ead2-426a-9c47-33847f59b8c7
ms.openlocfilehash: 72f81e2fc58a31db0c4cd3f77ba182bd8b8152a4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366570"
---
# <a name="iteration-statements-c"></a>Instruções de iteração (C++)

As instruções de iteração fazem com que as instruções (ou instruções compostas) sejam executadas nenhuma ou mais vezes, de acordo com os critérios de término de loop. Quando essas instruções são instruções compostas, são executadas em ordem, exceto quando ambos os [quebra](../cpp/break-statement-cpp.md) instrução ou o [continuar](../cpp/continue-statement-cpp.md) instrução for encontrada.

C++ fornece quatro instruções de iteração — [enquanto](../cpp/while-statement-cpp.md), [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), e [baseado em intervalo para](../cpp/range-based-for-statement-cpp.md). Cada uma delas itera até que a expressão de término seja avaliada como zero (false) ou até o término de loop seja imposto com uma **quebra** instrução. A tabela a seguir resume essas instruções e suas ações; cada uma delas é discutida em detalhes nas seções seguintes.

### <a name="iteration-statements"></a>Instruções de iteração

|Instrução|Avaliada como|Inicialização|Incremento|
|---------------|------------------|--------------------|---------------|
|**while**|Topo do loop|Não|Não|
|**do**|Final do loop|Não|Não|
|**for**|Topo do loop|Sim|Sim|
|**baseado em intervalo para**|Topo do loop|Sim|Sim|

A parte da instrução de uma instrução de iteração não pode ser uma declaração. No entanto, pode ser uma instrução composta que contenha uma declaração.

## <a name="see-also"></a>Consulte também

[Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)