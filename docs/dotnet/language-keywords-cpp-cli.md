---
title: Palavras-chave (C + + CLI) | Microsoft Docs
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
ms.openlocfilehash: 241205ad25314034d8d36fa7ad1b156b13080fd6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="language-keywords-ccli"></a>Palavras-chave da linguagem (C++/CLI)
Várias palavras-chave alteradas de extensões gerenciadas para C++ para Visual C++.  
  
 Na nova sintaxe Visual C++, o sublinhado duplo é removido como um prefixo de todas as palavras-chave (com uma exceção: `__identifier` é mantido). Por exemplo, uma propriedade agora está declarada como `property`, não `__property`.  
  
 Houve dois motivos principais para usar o prefixo de sublinhado duplo em extensões gerenciadas:  
  
-   É o método compatível do fornecimento de extensões de locais para o padrão ISO C++. O principal objetivo do design das extensões gerenciadas foi não apresentar incompatibilidades com o idioma padrão, como novas palavras-chave e tokens. Foi esse motivo, em grande parte, o qual motivados a escolha da sintaxe de ponteiro para a declaração de objetos dos tipos de referência gerenciada.  
  
-   O uso do sublinhado duplo, além de seu aspecto compatível, também é uma garantia razoável de ser não-invasor com a base de código existente, os usuários do idioma. Essa era um segunda principal objetivo do design das extensões gerenciadas.  
  
 Apesar de remover os sublinhados duplos, Microsoft mantém seu compromisso sendo compatível. Entretanto, há suporte para o modelo de objeto dinâmico CLR representa um paradigma de programação novo e poderoso. Suporte a esse novo paradigma requer seu próprio palavras-chave de alto nível e tokens. Podemos ter procurado fornecer uma expressão de primeira classe desse novo paradigma durante a integração e o idioma padrão de suporte. O novo design de sintaxe fornece uma experiência de programação de primeira classe desses dois modelos de objeto diferentes.  
  
 Da mesma forma, estamos preocupados com maximizando a natureza não invasivo essas novas palavras-chave do idioma. Isso foi realizado com o uso de palavras-chave contextuais e espaçadas. Antes de examinarmos a nova sintaxe de linguagem real, vamos tentar compreender esses dois tipos especiais de palavra-chave.  
  
 Uma palavra-chave contextual tem um significado especial em contextos de programa específico. Dentro do programa geral, por exemplo, `sealed` é tratado como um identificador comum. No entanto, quando ele ocorre dentro a parte da declaração de um tipo de classe de referência gerenciada, ele é tratado como uma palavra-chave dentro do contexto de declaração da classe. Isso minimiza o impacto potencial invasivo de introduzir uma nova palavra-chave no idioma, algo que achamos que é muito importante para usuários com uma base de código existente. Ao mesmo tempo, ele permite que os usuários da nova funcionalidade tenham uma experiência de primeira classe do recurso de idioma adicionais - algo que não era possível com extensões gerenciadas. Para obter um exemplo de como `sealed` usado consulte [declaração de um tipo de classe gerenciada](../dotnet/declaration-of-a-managed-class-type.md).  
  
 Uma palavra-chave espaçada, como `value class`, é um caso especial de uma palavra-chave contextual. Ele pares uma palavra-chave existente com um modificador contextual separado por um espaço. O par é tratado como uma única unidade em vez de duas palavras-chave separadas.  
  
## <a name="see-also"></a>Consulte também  
 [C + + CLI Primer de migração](../dotnet/cpp-cli-migration-primer.md)   
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)