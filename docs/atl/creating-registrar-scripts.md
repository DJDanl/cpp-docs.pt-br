---
title: Como criar scripts para o Registrador da ATL
ms.date: 05/14/2014
helpviewer_keywords:
- scripting, registry scripting
- ATL, registry
- registrar scripts [ATL]
- scripts, Registrar scripts
- scripts, creating
ms.assetid: cbd5024b-8061-4a71-be65-7fee90374a35
ms.openlocfilehash: f32606701ea08736985f0b0dd2ed82712040a049
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707052"
---
# <a name="creating-registrar-scripts"></a>Como criar scripts do Registrador

Um script do registrador fornece acesso controlado por dados, em vez de controlado pela API, ao Registro do sistema. Normalmente, o acesso controlado por dados é mais eficiente, pois usa apenas uma ou duas linhas em um script para adicionar uma chave ao Registro.

O [Assistente de Controle da ATL](../atl/reference/atl-control-wizard.md) gera automaticamente um script de registrador para o servidor COM. É possível encontrar este script no arquivo .rgs associado ao seu objeto.

O Mecanismo de Script do Registrador da ATL processa seu script do registrador em tempo de execução. A ATL invoca automaticamente o Mecanismo de script durante a instalação do servidor.

Este artigo aborda os seguintes tópicos relacionados aos scripts de registrador:

- [Noções básicas sobre a sintaxe BNF (forma de Backus-Naur)](../atl/understanding-backus-naur-form-bnf-syntax.md)

- [Noções básicas sobre árvores de análise](../atl/understanding-parse-trees.md)

- [Exemplos de scripts do Registro](../atl/registry-scripting-examples.md)

- [Usando parâmetros substituíveis (pré-processador do Registrador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)

- [Invocando scripts](../atl/invoking-scripts.md)

## <a name="see-also"></a>Consulte também

[Componente de Registro (Registrador)](../atl/atl-registry-component-registrar.md)
