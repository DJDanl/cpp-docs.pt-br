---
title: Criando Scripts para o registrador da ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- scripting, registry scripting
- ATL, registry
- registrar scripts [ATL]
- scripts, Registrar scripts
- scripts, creating
ms.assetid: cbd5024b-8061-4a71-be65-7fee90374a35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e140e66ee24d8333d25c0c2942924c7a9db4965b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32354427"
---
# <a name="creating-registrar-scripts"></a>Criação de Scripts do registrador
Um script de registrador fornece acesso controlado por dados, em vez de baseada em API, no registro do sistema. Acesso controlado por dados é geralmente mais eficiente, pois leva apenas uma ou duas linhas em um script para adicionar uma chave ao registro.  
  
 O [Assistente de controle ATL](../atl/reference/atl-control-wizard.md) automaticamente gera um script de registrador para o servidor COM. Você pode encontrar esse script no arquivo. rgs associado ao objeto.  
  
 O mecanismo de Script do registrador ATL processa o script de registrador em tempo de execução. ATL chama automaticamente o mecanismo de Script durante a instalação do servidor.  
  
 Este artigo aborda os seguintes tópicos relacionados aos scripts de registrador:  
  
-   [Noções básicas sobre a sintaxe BNF (Backus Nauer Form)](../atl/understanding-backus-nauer-form-bnf-syntax.md)  
  
-   [Noções básicas sobre árvores de análise](../atl/understanding-parse-trees.md)  
  
-   [Exemplos de scripts do Registro](../atl/registry-scripting-examples.md)  
  
-   [Usando parâmetros substituíveis (pré-processador do Registrador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)  
  
-   [Invocando scripts](../atl/invoking-scripts.md)  
  
## <a name="see-also"></a>Consulte também  
 [Componente de registro (Registrar)](../atl/atl-registry-component-registrar.md)

