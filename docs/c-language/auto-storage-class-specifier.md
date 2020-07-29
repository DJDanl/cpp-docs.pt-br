---
title: Especificador de classe de armazenamento auto
ms.date: 11/04/2016
ms.assetid: 8e73f57e-aa92-4e41-91ea-5c8ad2a2b332
ms.openlocfilehash: e39b37e2dc91dce31b6871d721875c75b8ebd629
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223753"
---
# <a name="auto-storage-class-specifier"></a>`auto`Especificador de classe de armazenamento

O **`auto`** especificador de classe de armazenamento declara uma variável automática, uma variável com um tempo de vida local. Uma **`auto`** variável é visível somente no bloco no qual ela é declarada. Declarações de **`auto`** variáveis podem incluir inicializadores, conforme discutido na [inicialização](../c-language/initialization.md). Como as variáveis com **`auto`** classe de armazenamento não são inicializadas automaticamente, você deve inicializá-las explicitamente ao declará-las ou atribuí-las a valores iniciais em instruções dentro do bloco. Os valores das variáveis não inicializadas **`auto`** são indefinidos. (Uma variável local **`auto`** ou **`register`** classe de armazenamento é inicializada toda vez que chegar no escopo se um inicializador for fornecido.)

Uma **`static`** variável interna (uma variável estática com escopo de bloco ou local) pode ser inicializada com o endereço de qualquer **`static`** item ou externo, mas não com o endereço de outro **`auto`** Item, porque o endereço de um **`auto`** item não é uma constante.

## <a name="see-also"></a>Confira também

[`auto`Chaves](../cpp/auto-keyword.md)
