---
title: Instruções de iteração (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- iteration statements
- loop structures, iteration statements
ms.assetid: bf6d75f7-ead2-426a-9c47-33847f59b8c7
ms.openlocfilehash: e8f064fd19e69de2819673f48a7f14e26d60b87e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178244"
---
# <a name="iteration-statements-c"></a>Instruções de iteração (C++)

As instruções de iteração fazem com que as instruções (ou instruções compostas) sejam executadas nenhuma ou mais vezes, de acordo com os critérios de término de loop. Quando essas instruções são instruções compostas, elas são executadas em ordem, exceto quando a instrução [Break](../cpp/break-statement-cpp.md) ou a instrução [continue](../cpp/continue-statement-cpp.md) é encontrada.

C++fornece quatro instruções de iteração – [enquanto](../cpp/while-statement-cpp.md) [, do,](../cpp/do-while-statement-cpp.md) [para](../cpp/for-statement-cpp.md)o e o [baseado em intervalo](../cpp/range-based-for-statement-cpp.md). Cada uma dessas iterações até que sua expressão de término seja avaliada como zero (false), ou até que o encerramento do loop seja forçado com uma instrução **Break** . A tabela a seguir resume essas instruções e suas ações; cada uma delas é discutida em detalhes nas seções seguintes.

### <a name="iteration-statements"></a>Instruções de iteração

|de|Avaliada como|Inicialização|Incremento|
|---------------|------------------|--------------------|---------------|
|**while**|Topo do loop|Não|Não|
|**do**|Final do loop|Não|Não|
|**for**|Topo do loop|Sim|Sim|
|**baseado em intervalo para**|Topo do loop|Sim|Sim|

A parte da instrução de uma instrução de iteração não pode ser uma declaração. No entanto, pode ser uma instrução composta que contenha uma declaração.

## <a name="see-also"></a>Confira também

[Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)
