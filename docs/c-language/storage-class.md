---
title: Classe de armazenamento
ms.date: 11/04/2016
helpviewer_keywords:
- linkage [C++], external
- function storage class
- function specifiers, storage class
- storage classes
- Microsoft-specific storage classes
- external linkage, storage-class specifiers
- static storage class specifiers
ms.assetid: 39a79ba6-edf5-42b6-8e45-f94227603dd6
ms.openlocfilehash: 872a014dfc7c21b46f9af810f1cb3463016c7e09
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211678"
---
# <a name="storage-class"></a>Classe de armazenamento

O especificador de classe de armazenamento em uma definição de função fornece a função **`extern`** ou a **`static`** classe de armazenamento.

## <a name="syntax"></a>Sintaxe

*função-definição*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\**Attribute-Seq* é específico da Microsoft\*/

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*armazenamento-classe-especificador*:/ \* para definições de função\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`extern`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`static`**

Se uma definição de função não incluir um *especificador de classe de armazenamento*, a classe de armazenamento será padronizada como **`extern`** . Você pode declarar explicitamente uma função como **`extern`** , mas ela não é necessária.

Se a declaração de uma função contiver o *especificador de classe de armazenamento* **`extern`** , o identificador terá o mesmo vínculo que qualquer declaração visível do identificador com escopo de arquivo. Se não houver declaração visível com escopo de arquivo, o identificador terá vinculação externa. Se um identificador tiver escopo de arquivo e nenhum *storage-class-specifier*, o identificador terá vinculação externa. Vinculação externa significa que cada instância do identificador denota o mesmo objeto ou função. Consulte [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md) para obter informações sobre vinculação e escopo de arquivo.

Declarações de função de escopo de bloco com um especificador de classe de armazenamento diferente de **`extern`** gerar erros.

Uma função com **`static`** classe de armazenamento é visível somente no arquivo de origem no qual ela está definida. Todas as outras funções, se recebem **`extern`** uma classe de armazenamento explícita ou implicitamente, são visíveis em todos os arquivos de origem do programa. Se a **`static`** classe de armazenamento for desejada, ela deverá ser declarada na primeira ocorrência de uma declaração (se houver) da função e na definição da função.

**Específico da Microsoft**

Quando as extensões da Microsoft são habilitadas, uma função originalmente declarada sem uma classe de armazenamento (ou com **`extern`** classe de armazenamento) recebe **`static`** a classe de armazenamento se a definição da função estiver no mesmo arquivo de origem e se a definição especificar explicitamente a **`static`** classe de armazenamento.

Ao compilar com a opção de compilador/ze, as funções declaradas em um bloco usando a **`extern`** palavra-chave têm visibilidade global. Isso não ocorre na compilação com /Za. Esse recurso não deve ser usado se a portabilidade do código-fonte estiver em consideração.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Definições de função C](../c-language/c-function-definitions.md)
