---
title: Configuração de Versão de Novo Projeto com base em um Código Existente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.appwiz.importwiz.releasesettings
dev_langs:
- C++
ms.assetid: 3e2fc73c-bdbd-4790-b2bd-d31731f0cece
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4f3995b1a7227e4d2f0a531c86726b84e960d8ec
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33340483"
---
# <a name="specify-release-configuration-settings-create-new-project-from-existing-code-files-wizard"></a>Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes
Use esta página do assistente para Criar Novo Projeto com base em Arquivos de Código Existentes para especificar as definições do projeto da configuração de Versão.  
  
## <a name="task-list"></a>Lista de Tarefas  
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Igual à Configuração de Depuração**  
 Especifica que o assistente gerará configurações de projeto da configuração de Versão idênticas às configurações de projeto da configuração de Depuração. Essa opção está marcada por padrão. Todas as outras opções dessa página ficam inativas, a menos que você desmarque essa caixa.  
  
 **Linha de comando de Build**  
 Especifica a linha de comando que compila o novo projeto. Insira o nome do compilador, além de opções ou argumentos que deseja usar para compilar o novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**.  
  
 **Linha de comando de Recompilar**  
 Especifica a linha de comando que recompila o novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**.  
  
 **Linha de comando de Limpar**  
 Especifica a linha de comando para excluir os arquivos de suporte gerados pelas ferramentas de build para o novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**.  
  
 **Saída (para depuração)**  
 Especifica o caminho do diretório dos arquivos de saída para a configuração de Depuração do novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**.  
  
 **Definições de pré-processador (/D)**  
 Define os símbolos do pré-processador para o novo projeto. Para obter mais informações, consulte [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md).  
  
 **Caminho de pesquisa de inclusão (/I)**  
 Especifica os caminhos do diretório a serem adicionados à lista de diretórios que o compilador pesquisará para resolver as referências de arquivo passadas para as diretivas do pré-processador no novo projeto. Para obter mais informações, consulte [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md).  
  
 **Arquivos de inclusão forçada (/FI)**  
 Especifica os arquivos de cabeçalho a serem processados ao compilar o novo projeto. Para obter mais informações, consulte [/FI (nomear arquivo de include forçado)](../build/reference/fi-name-forced-include-file.md).  
  
 **Caminho de pesquisa de assembly .NET (/AI)**  
 Especifica os caminhos do diretório que o compilador pesquisará para resolver as referências de assembly .NET passadas para as diretivas do pré-processador no novo projeto. Para obter mais informações, consulte [/AI (Especificar Diretórios de Metadados)](../build/reference/ai-specify-metadata-directories.md).  
  
 **Uso forçado de assemblies .NET (/FU)**  
 Especifica os assemblies .NET a serem processados ao compilar o novo projeto. Para obter mais informações, consulte [/FU (nome forçado #usando arquivo)](../build/reference/fu-name-forced-hash-using-file.md).  
  
## <a name="see-also"></a>Consulte também  
 [Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md)