---
title: Definições e convenções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- nonterminals definition
ms.assetid: f9b3cf5f-6a7c-4a10-9b18-9d4a43efdaeb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7abaa67ce9bdee0b2f9a69fa11260c2b6bbfcf45
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46034402"
---
# <a name="definitions-and-conventions"></a>Definições e convenções

Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.

Os não terminais são espaços reservados na sintaxe e são definidos em outra parte deste resumo da sintaxe. As definições podem ser recursivas.

Um componente opcional é indicado pelo <sub>opt</sub> subscrito. Por exemplo,

> **{** *expression*<sub>opt</sub> **}**

indica uma expressão opcional entre chaves.

As convenções de sintaxe usam atributos diferentes de fonte para componentes diferentes de sintaxe. Os símbolos e as fontes são os seguintes:

|Atributo|Descrição|
|---------------|-----------------|
|*nonterminal*|O tipo em itálico indica não terminais.|
|**const**|Os terminais de tipo em negrito são palavras reservadas a literais e símbolos que devem ser inseridos como mostrado. Os caracteres nesse contexto sempre diferenciam maiúsculas de minúsculas.|
|<sub>opt</sub>|Não terminais seguidos por <sub>opt</sub> são sempre opcionais.|
|default typeface|Os caracteres no conjunto listados ou descritos nesta face de tipos podem ser usados como terminais em instruções de C.|

Um sinal de dois pontos (**:**) depois de um não terminal introduz sua definição. Definições alternativas estão listadas em linhas separadas, exceto quando prefaciadas com as palavras "um de".

## <a name="see-also"></a>Consulte também

[Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md)