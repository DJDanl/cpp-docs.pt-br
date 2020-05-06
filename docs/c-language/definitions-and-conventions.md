---
title: Definições e convenções
ms.date: 11/04/2016
helpviewer_keywords:
- nonterminals definition
ms.assetid: f9b3cf5f-6a7c-4a10-9b18-9d4a43efdaeb
ms.openlocfilehash: 0ff3f8b447e29f0da59405a7c0286d7a696b4613
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234425"
---
# <a name="definitions-and-conventions"></a>Definições e convenções

Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.

Os não terminais são espaços reservados na sintaxe e são definidos em outra parte deste resumo da sintaxe. As definições podem ser recursivas.

Um componente opcional é indicado pela <sub>recusa</sub>de subscrito. Por exemplo,

> **{** *expressão*<sub>opt</sub> **}**

indica uma expressão opcional entre chaves.

As convenções de sintaxe usam atributos diferentes de fonte para componentes diferentes de sintaxe. Os símbolos e as fontes são os seguintes:

|Atributo|Descrição|
|---------------|-----------------|
|*Não terminal*|O tipo em itálico indica não terminais.|
|**const**|Os terminais de tipo em negrito são palavras reservadas a literais e símbolos que devem ser inseridos como mostrado. Os caracteres nesse contexto sempre diferenciam maiúsculas de minúsculas.|
|<sub>opt</sub>|Os não-terminais seguidos por <sub>opt</sub> são sempre opcionais.|
|default typeface|Os caracteres no conjunto listados ou descritos nesta face de tipos podem ser usados como terminais em instruções de C.|

Um sinal de dois pontos (**:**) depois de um não terminal introduz sua definição. Definições alternativas estão listadas em linhas separadas, exceto quando prefaciadas com as palavras "um de".

## <a name="see-also"></a>Confira também

[Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md)
