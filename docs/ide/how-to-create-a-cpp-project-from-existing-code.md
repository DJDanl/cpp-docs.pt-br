---
title: Como criar um projeto do C++ a partir do código existente
ms.date: 11/04/2016
helpviewer_keywords:
- C++, creating projects from existing code
ms.assetid: e328a938-395c-48ea-9e35-dd433de12b31
ms.openlocfilehash: dafd4e939444c581a76e9ccfcab4c3f6bbe819d3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552497"
---
# <a name="how-to-create-a-c-project-from-existing-code"></a>Como criar um projeto do C++ a partir do código existente

No Visual Studio, você pode portar os arquivos de código existentes para um projeto do Visual C++ usando o assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes**. Esse assistente não está disponível nas edições Express mais antigas do Visual Studio. Esse assistente cria uma nova solução e um novo projeto que usa o sistema do MSBuild para gerenciar os arquivos de origem e a configuração de build.

A portabilidade dos arquivos de código existentes para um projeto do Visual C++ permite que você use todas as funcionalidades nativas de gerenciamento de projetos do MSBuild internos do IDE. Se preferir usar o sistema de build existente, como makefiles NMake, CMake ou outras alternativas, use a opção Abrir Pasta. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](../ide/non-msbuild-projects.md). Ambas as opções permitem que você use funcionalidades do IDE, como [IntelliSense](/visualstudio/ide/using-intellisense) e [Propriedades do Projeto](../ide/working-with-project-properties.md).

### <a name="to-create-a-c-project-from-existing-code"></a>Para criar um projeto em C++ a partir de um código existente

1. No menu **Arquivo**, aponte para **Novo** e, em seguida, clique em **Projeto com base em Código Existente**.

1. Na primeira página do assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes**, selecione **Visual C++** na lista **Que tipo de projeto deseja criar?**. Escolha **Avançar** para continuar.

1. Especifique o local do projeto e o diretório dos arquivos de origem. Para obter detalhes sobre essa página, confira [Especificar Local do Projeto e Arquivos de Origem, Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes](../ide/specify-project-location-and-source-files.md). Escolha **Avançar** para continuar.

1. Especifique as configurações de projeto a serem usadas. Para obter detalhes sobre essa página, confira [Especificar Configurações de Projeto, Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md). Escolha **Avançar** para continuar.

1. Especifique as definições de configuração de Depuração a serem usadas. Para obter detalhes sobre essa página, confira [Especificar Definições de Configuração de Depuração, Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes](../ide/specify-debug-configuration-settings.md). Escolha **Avançar** para continuar.

1. Especifique as definições de configuração de Versão a serem usadas. Para obter detalhes sobre essa página, confira [Especificar Definições de Configuração de Versão, Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes](../ide/specify-release-configuration.md). Escolha **Concluir** para gerar o novo projeto.

## <a name="see-also"></a>Consulte também

[Especificar local do projeto e arquivos de origem, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-project-location-and-source-files.md)<br>
[Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md)<br>
[Especificar definições de configuração da depuração, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-debug-configuration-settings.md)<br>
[Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-release-configuration.md)