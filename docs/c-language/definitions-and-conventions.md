---
title: Definições e convenções
ms.date: 11/04/2016
helpviewer_keywords:
- nonterminals definition
ms.assetid: f9b3cf5f-6a7c-4a10-9b18-9d4a43efdaeb
ms.openlocfilehash: 9da9a566ef0b8d34a1a3d64dd2b8ce659194e6ce
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226373"
---
# <a name="definitions-and-conventions"></a>Definições e convenções

Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.

Os não terminais são espaços reservados na sintaxe e são definidos em outra parte deste resumo da sintaxe. As definições podem ser recursivas.

Um componente opcional é indicado pela <sub>recusa</sub>de subscrito. Por exemplo:

> **{** *expressão*<sub>opt</sub> **}**

indica uma expressão opcional entre chaves.

As convenções de sintaxe usam atributos diferentes de fonte para componentes diferentes de sintaxe. Os símbolos e as fontes são os seguintes:

|Atributo|Descrição|
|---------------|-----------------|
|*Não terminal*|O tipo em itálico indica não terminais.|
|**`const`**|Os terminais de tipo em negrito são palavras reservadas a literais e símbolos que devem ser inseridos como mostrado. Os caracteres nesse contexto sempre diferenciam maiúsculas de minúsculas.|
|<sub>opt</sub>|Os não-terminais seguidos por <sub>opt</sub> são sempre opcionais.|
|default typeface|Os caracteres no conjunto listados ou descritos nesta face de tipos podem ser usados como terminais em instruções de C.|

Um sinal de dois pontos (**:**) depois de um não terminal introduz sua definição. Definições alternativas estão listadas em linhas separadas, exceto quando prefaciadas com as palavras "um de".

## <a name="see-also"></a>Confira também

[Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md)
