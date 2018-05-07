---
title: 'Como: criar um projeto de C++ de código existente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- C++, creating projects from existing code
ms.assetid: e328a938-395c-48ea-9e35-dd433de12b31
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1786e5704d7afd07576ab738d907eb841518f8be
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-create-a-c-project-from-existing-code"></a>Como criar um projeto do C++ a partir do código existente

No Visual Studio, pode transferir os arquivos de código existentes em um projeto do Visual C++ usando o **criar novo projeto de arquivos de código existentes** assistente. Este assistente não está disponível em mais antigas edições Express do Visual Studio. Este assistente cria uma nova solução e projeto que usa o sistema de MSBuild para gerenciar seus arquivos de origem e a configuração de compilação.  
  
Movimentando seus arquivos de código existente para um projeto do Visual C++ permite que você use todos os recursos de gerenciamento de projeto MSBuild nativo embutidos no IDE. Se você preferir usar o sistema de compilação existentes, como nmake makefiles, CMake ou alternativas, você pode usar a opção de abrir a pasta. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](../ide/non-msbuild-projects.md). Ambas as opções permitem que você use recursos IDE, como [IntelliSense](/visualstudio/ide/using-intellisense) e [propriedades do projeto](../ide/working-with-project-properties.md).  
  
### <a name="to-create-a-c-project-from-existing-code"></a>Para criar um projeto em C++ a partir de um código existente  
  
1.  Sobre o **arquivo** , aponte para **novo**e, em seguida, clique em **projeto de código existente**.  
  
1.  Na primeira página do **criar novo projeto de arquivos de código existentes** assistente, selecione **Visual C++** no **que tipo de projeto você deseja criar** lista. Escolha **Avançar** para continuar. 
  
1.  Especifique o local do projeto e o diretório para arquivos de origem. Para obter detalhes sobre essa página, consulte [especificar local do projeto e arquivos de origem, o projeto de existente código arquivos Assistente para criar novo](../ide/specify-project-location-and-source-files.md). Escolha **Avançar** para continuar.  
  
1.  Especifique as configurações de projeto para usar. Para obter detalhes sobre essa página, consulte [especificar configurações de projeto, criar novo projeto de existente código arquivos assistente](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md). Escolha **Avançar** para continuar.  

1.  Especifique as definições de configuração de depuração a ser usado. Para obter detalhes sobre essa página, consulte [especificar configurações de depuração, criar novo projeto de existente código arquivos assistente](../ide/specify-debug-configuration-settings.md). Escolha **Avançar** para continuar.  

1.  Especifique as configurações de versão a ser usado. Para obter detalhes sobre essa página, consulte [especificar configurações de versão, o projeto de existente código arquivos Assistente para criar novo](../ide/specify-release-configuration.md). Escolha **concluir** para gerar o novo projeto.  
  
## <a name="see-also"></a>Consulte também  

[Especificar o projeto local e arquivos de origem, criar novo projeto de Assistente de arquivos de código existentes](../ide/specify-project-location-and-source-files.md)   
[Especificar configurações do projeto, criar novo projeto de Assistente de arquivos de código existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md)   
[Especificar configurações de depuração, criar novo projeto de Assistente de arquivos de código existentes](../ide/specify-debug-configuration-settings.md)   
[Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-release-configuration.md)