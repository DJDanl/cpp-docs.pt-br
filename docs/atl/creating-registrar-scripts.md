---
title: Criando Scripts para o registrador da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- scripting, registry scripting
- ATL, registry
- registrar scripts [ATL]
- scripts, Registrar scripts
- scripts, creating
ms.assetid: cbd5024b-8061-4a71-be65-7fee90374a35
ms.openlocfilehash: bc76e41ab0d2cd2d26ef227e6368cb420a8a6401
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50480231"
---
# <a name="creating-registrar-scripts"></a>Criação de Scripts do registrador

Um script de registrador fornece acesso controlado por dados, em vez de controlado por API, o registro do sistema. Acesso controlado por dados é geralmente mais eficiente, pois leva apenas uma ou duas linhas em um script para adicionar uma chave ao registro.

O [Assistente de controle ATL](../atl/reference/atl-control-wizard.md) automaticamente gera um script de registrador para o servidor COM. Você pode encontrar esse script no arquivo. rgs associado ao objeto.

O mecanismo de Script do ATL registrador processa o script de registrador em tempo de execução. ATL chama automaticamente o mecanismo de Script durante a instalação do servidor.

Este artigo aborda os seguintes tópicos relacionados a scripts do registrador:

- [Noções básicas sobre a sintaxe BNF (Backus Nauer Form)](../atl/understanding-backus-nauer-form-bnf-syntax.md)

- [Noções básicas sobre árvores de análise](../atl/understanding-parse-trees.md)

- [Exemplos de scripts do Registro](../atl/registry-scripting-examples.md)

- [Usando parâmetros substituíveis (pré-processador do Registrador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)

- [Invocando scripts](../atl/invoking-scripts.md)

## <a name="see-also"></a>Consulte também

[Componente de registro (Registrar)](../atl/atl-registry-component-registrar.md)

