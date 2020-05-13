---
title: Especificador de classe de armazenamento auto
ms.date: 11/04/2016
ms.assetid: 8e73f57e-aa92-4e41-91ea-5c8ad2a2b332
ms.openlocfilehash: 6bd36fd534602a5a4df95047a830058e8c5ef163
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62313461"
---
# <a name="auto-storage-class-specifier"></a>Especificador de classe de armazenamento auto

O especificador de classe de armazenamento **auto** declara uma variável automática, uma variável com um tempo de vida local. Uma variável **auto** pode ser vista somente no bloco em que é declarada. As declarações de variáveis **auto** podem incluir inicializadores, conforme discutido em [Inicialização](../c-language/initialization.md). Como as variáveis com a classe de armazenamento **auto** não são inicializadas automaticamente, você deve inicializá-las explicitamente ao declará-las ou atribuir valores iniciais a elas em instruções no bloco. Os valores das variáveis **auto** não inicializadas estão indefinidos. (A variável local da classe de armazenamento **auto** ou **register** será inicializada sempre que aparecer no escopo, se um inicializador for fornecido.)

Uma variável interna **static** (uma variável estática com escopo local ou de bloco) pode ser inicializada com o endereço de qualquer item externo ou **static**, mas não com o endereço de outro item **auto**, pois o endereço de um item **auto** não é uma constante.

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../cpp/auto-keyword.md)
