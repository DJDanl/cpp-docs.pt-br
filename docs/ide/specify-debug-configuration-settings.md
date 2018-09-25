---
title: Configuração de Depuração de Novo Projeto com base em um Código Existente (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.appwiz.importwiz.debugsettings
dev_langs:
- C++
ms.assetid: 607339a8-9d33-458b-8095-dc73f374e29d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: df50dfba79ad4160728e77b96d5814d6b03add1e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440882"
---
# <a name="specify-debug-configuration-settings-create-new-project-from-existing-code-files-wizard"></a>Especificar definições de configuração da depuração, Assistente para Criar Novo Projeto de Arquivos de Código Existentes

Use esta página do assistente para Criar Novo Projeto com base em Arquivos de Código Existentes para especificar as definições do projeto da configuração de Depuração.

## <a name="task-list"></a>Lista de Tarefas

[Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)

## <a name="uielement-list"></a>Lista UIElement

- **Linha de comando de Build**

   Especifica a linha de comando que compila o novo projeto. Por exemplo, insira o nome do compilador (além de opções e argumentos) ou os scripts de build que deseja usar para compilar o novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**; caso contrário, ela não fica disponível.

- **Linha de comando de Recompilar**

   Especifica a linha de comando que recompila o novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**; caso contrário, ela não fica disponível.

- **Linha de comando de Limpar**

   Especifica a linha de comando para excluir os arquivos de suporte gerados pelas ferramentas de build para o novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**; caso contrário, ela não fica disponível.

- **Saída (para depuração)**

   Especifica o caminho do diretório dos arquivos de saída para a configuração de Depuração do novo projeto. Essa opção fica habilitada quando a opção **Usar sistema de build externo** é selecionada na página **Especificar Configurações de Projeto**; caso contrário, ela não fica disponível.

- **Definições de pré-processador (/D)**

   Define os símbolos do pré-processador para o novo projeto. Para obter mais informações, consulte [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md).

- **Caminho de pesquisa de inclusão (/I)**

   Especifica os caminhos do diretório a serem adicionados à lista de diretórios que o compilador pesquisará para resolver as referências de arquivo passadas para as diretivas do pré-processador no novo projeto. Para obter mais informações, consulte [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md).

- **Arquivos de inclusão forçada (/FI)**

   Especifica os arquivos de cabeçalho a serem processados ao compilar o novo projeto. Para obter mais informações, consulte [/FI (nomear arquivo de include forçado)](../build/reference/fi-name-forced-include-file.md).

- **Caminho de pesquisa de assembly .NET (/AI)**

   Especifica os caminhos do diretório que o compilador pesquisará para resolver as referências de assembly .NET passadas para as diretivas do pré-processador no novo projeto. Para obter mais informações, consulte [/AI (Especificar Diretórios de Metadados)](../build/reference/ai-specify-metadata-directories.md).

- **Uso forçado de assemblies .NET (/FU)**

   Especifica os assemblies .NET a serem processados ao compilar o novo projeto. Para obter mais informações, consulte [/FU (nome forçado #usando arquivo)](../build/reference/fu-name-forced-hash-using-file.md).

## <a name="see-also"></a>Consulte também

[Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md)
