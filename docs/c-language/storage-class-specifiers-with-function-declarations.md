---
title: Especificadores de classe de armazenamento com declarações de função
ms.date: 11/04/2016
helpviewer_keywords:
- function specifiers, storage class
- declaring functions, specifiers
- external declarations
- specifiers, function
- external linkage, function declarations
- external linkage, storage-class specifiers
ms.assetid: 801d7df2-efa9-4924-a725-274a5654cfd4
ms.openlocfilehash: e27cc6ac748c0af3063dbc5b608114761da8b7dc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211691"
---
# <a name="storage-class-specifiers-with-function-declarations"></a>Especificadores de classe de armazenamento com declarações de função

Você pode usar o **`static`** ou o **`extern`** especificador de classe de armazenamento em declarações de função. As funções sempre têm tempos de vida globais.

**Específico da Microsoft**

As declarações de função no nível interno têm o mesmo significado que as declarações de função no nível externo. Isso significa que uma função é visível do ponto de declaração durante o restante da unidade de conversão mesmo que seja declarada no escopo local.

**FINAL específico da Microsoft**

As regras de visibilidade para funções variam ligeiramente das regras para as variáveis, como segue:

- Uma função declarada para ser **`static`** visível somente dentro do arquivo de origem no qual está definida. As funções no mesmo arquivo de origem podem chamar a **`static`** função, mas as funções em outros arquivos de origem não podem acessá-la diretamente pelo nome. Você pode declarar outra **`static`** função com o mesmo nome em um arquivo de origem diferente sem conflito.

- As funções declaradas como **`extern`** estão visíveis em todos os arquivos de origem no programa (a menos que você redeclare posteriormente tal função como **`static`** ). Qualquer função pode chamar uma **`extern`** função.

- As declarações de função que omitem o especificador de classe de armazenamento são **`extern`** por padrão.

**Específico da Microsoft**

A Microsoft permite redefinição de um **`extern`** identificador como **`static`** .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classes de armazenamento C](../c-language/c-storage-classes.md)
