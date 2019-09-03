---
title: Convenções de documento
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor
- preprocessor, conventions
ms.assetid: 469ce448-dc6c-4d0e-ba2b-e2e7a10155e1
ms.openlocfilehash: bb826b879b71edd3631c11a717320cee51c87175
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220365"
---
# <a name="document-conventions"></a>Convenções de documento

As convenções usam atributos diferentes de fonte para componentes diferentes de sintaxe. Os símbolos e as fontes são os seguintes:

| Atributo | Descrição |
|---------------|-----------------|
| *nonterminal* | O tipo em itálico indica não terminais. |
| **#include** | Os terminais de tipo em negrito são palavras reservadas a literais e símbolos que devem ser inseridos como mostrado. Os caracteres nesse contexto sempre diferenciam maiúsculas de minúsculas. |
| <sub>opt</sub> | Não terminais seguidos por <sub>opt</sub> são sempre opcionais.|
| default typeface | Os caracteres no conjunto descrito ou listados nesta face de tipos podem ser usados como terminais em instruções. |

Um sinal de dois pontos ( **:** ) depois de um não terminal introduz sua definição. As definições alternativas são listadas em linhas separadas.

Nos blocos de sintaxe de código, esses símbolos no tipo padrão têm um significado especial:

| Símbolo | Descrição |
|---|---|
| \[] | Colchetes circundam um elemento opcional. |
| { \| } | As chaves envolvem elementos alternativos, separados por barras verticais. |
| ... | Indica que o padrão de elemento anterior pode ser repetido. |

Em blocos de sintaxe de`,`código, vírgulas (), pontos (`.`), ponto-e`;`-vírgulas ()`:`, dois-pontos (`( )`), parênteses ()`"`, aspas duplas () e`'`aspas simples () são literais.

## <a name="see-also"></a>Consulte também

[Resumo da gramática (CC++/)](../preprocessor/grammar-summary-c-cpp.md)
