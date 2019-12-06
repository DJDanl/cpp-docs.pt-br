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
ms.openlocfilehash: aa6e977b3aa03b5f08901cfa8b0abe1b4046e72d
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857002"
---
# <a name="storage-class"></a>Classe de armazenamento

O especificador storage-class em uma definição de função fornece à função uma classe de armazenamento de `extern` ou **static**.

## <a name="syntax"></a>Sintaxe

*function-definition*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

*atributo de \* /-Seq* é \*específico da Microsoft /

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*storage-class-specifier*: /\* Para definições de função \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**extern**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**static**

Se uma definição de função não inclui um *storage-class-specifier*, a classe de armazenamento usa `extern` como padrão. Você pode declarar explicitamente uma função como `extern`, mas isso não é necessário.

Se a declaração de uma função contiver o *storage-class-specifier* `extern`, o identificador terá a mesma vinculação de qualquer declaração visível do identificador com escopo de arquivo. Se não houver declaração visível com escopo de arquivo, o identificador terá vinculação externa. Se um identificador tiver escopo de arquivo e nenhum *storage-class-specifier*, o identificador terá vinculação externa. Vinculação externa significa que cada instância do identificador denota o mesmo objeto ou função. Consulte [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md) para obter informações sobre vinculação e escopo de arquivo.

As declarações de função block-scope com um especificador storage-class diferente de `extern` geram erros.

Uma função com a classe de armazenamento **static** só é visível no arquivo de origem em que é definida. Todas as outras funções, tendo recebido a classe de armazenamento `extern` de forma explícita ou implícita, são visíveis em todos os arquivos de origem do programa. Se a classe de armazenamento **static** for desejada, ela deverá ser declarada na primeira ocorrência de uma declaração (se houver) da função e na definição da função.

**Seção específica da Microsoft**

Quando as extensões da Microsoft são habilitadas, uma função originalmente declarada sem uma classe de armazenamento (ou com a classe de armazenamento `extern`) receberá a classe de armazenamento **static** se a definição da função estiver no mesmo arquivo de origem e se a definição especificar explicitamente a classe de armazenamento **static**.

Ao compilar com a opção do compilador /Ze, as funções declaradas em um bloco usando a palavra-chave `extern` terão visibilidade global. Isso não ocorre na compilação com /Za. Esse recurso não deve ser usado se a portabilidade do código-fonte estiver em consideração.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Definições de função C](../c-language/c-function-definitions.md)
