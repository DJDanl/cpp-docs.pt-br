---
title: Criando Scripts para o registrador da ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- scripting, registry scripting
- ATL, registry
- registrar scripts [ATL]
- scripts, Registrar scripts
- scripts, creating
ms.assetid: cbd5024b-8061-4a71-be65-7fee90374a35
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b3bda4043693d14451a2de14cbc71fbecdcdddba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

