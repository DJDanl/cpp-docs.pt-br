---
title: Palavras-chave (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keywords [C++]
ms.assetid: 021013b2-70ac-4df9-aa77-4af1c67a1a67
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0b9deb25e203ea805b1430b2ec8e56f17a50123b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46445432"
---
# <a name="language-keywords-ccli"></a>Palavras-chave da linguagem (C++/CLI)

Várias palavras-chave alteradas de extensões gerenciadas para C++ para Visual C++.

Na nova sintaxe Visual C++, o sublinhado duplo é removido como um prefixo de todas as palavras-chave (com uma exceção: `__identifier` é mantido). Por exemplo, uma propriedade agora é declarada como `property`, e não `__property`.

Havia dois motivos principais para usar o prefixo sublinhado duplo em extensões gerenciadas:

- É o método de acordo com as conformidades do fornecimento de extensões do locais para o padrão ISO C++. Foi dos principais objetivos do design extensões gerenciadas para não introduzir as incompatibilidades com o idioma padrão, como novas palavras-chave e tokens. Foi esse motivo, em grande parte, que motivou a escolha da sintaxe de ponteiro para a declaração de objetos de tipos de referência gerenciada.

- O uso do sublinhado duplo, além de seu aspecto de acordo com as conformidades, também é uma garantia razoável de sendo não-invasivo com a base de código existentes dos usuários de idioma. Essa foi uma segunda meta principal do design extensões gerenciadas.

Remover os sublinhados duplos, apesar da Microsoft mantém seu compromisso sendo compatível com. No entanto, o suporte para o modelo de objeto dinâmico de CLR representa um paradigma de programação novo e poderoso. Suporte a esse novo paradigma requer suas próprias palavras-chave de alto nível e tokens. Nós temos procurado fornecer uma expressão de primeira classe desse novo paradigma ao integrá-lo e o idioma padrão de suporte. O novo design de sintaxe fornece uma experiência de programação de primeira classe desses dois modelos de objeto diferentes.

Da mesma forma, estamos preocupados com maximizando a natureza não invasiva dessas novas palavras-chave da linguagem. Isso tem sido feito com o uso de palavras-chave contextuais e espaçadas. Antes de examinarmos a nova sintaxe de linguagem real, vamos tentar compreender esses dois tipos especiais de palavra-chave.

Uma palavra-chave contextual tem um significado especial em contextos de programa específico. Dentro do programa geral, por exemplo, `sealed` é tratado como um identificador comum. No entanto, quando ele ocorre dentro a parte de declaração de um tipo de classe de referência gerenciada, ele é tratado como uma palavra-chave dentro do contexto de declaração da classe. Isso minimiza o impacto de invasivo potencial de introduzir uma nova palavra-chave na linguagem, algo que achamos é muito importante para usuários com uma base de código existente. Ao mesmo tempo, permite que os usuários da nova funcionalidade tenham uma experiência de primeira classe do recurso de idioma adicionais - algo que não era possível com extensões gerenciadas. Para obter um exemplo de como `sealed` é usado ver [declaração de um tipo de classe gerenciada](../dotnet/declaration-of-a-managed-class-type.md).

Uma palavra-chave espaçada, tais como `value class`, é um caso especial de uma palavra-chave contextual. Ela combina uma palavra-chave existente com um modificador contextual, separado por um espaço. O par é tratado como uma única unidade em vez de duas palavras-chave separadas.

## <a name="see-also"></a>Consulte também

[Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)<br/>
[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)