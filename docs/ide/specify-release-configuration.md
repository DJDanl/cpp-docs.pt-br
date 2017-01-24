---
title: "Especificar defini&#231;&#245;es de configura&#231;&#227;o da vers&#227;o, Assistente para Criar Novo Projeto de Arquivos de C&#243;digo Existentes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.importwiz.releasesettings"
dev_langs: 
  - "C++"
ms.assetid: 3e2fc73c-bdbd-4790-b2bd-d31731f0cece
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificar defini&#231;&#245;es de configura&#231;&#227;o da vers&#227;o, Assistente para Criar Novo Projeto de Arquivos de C&#243;digo Existentes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar as configurações de projeto de versão.  
  
## Lista de Tarefas  
 [Como criar um projeto do C\+\+ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## Lista UIElement  
 **Mesmo que a configuração de depuração**  
 Especifica que o assistente irá gerar o projeto configurações de versão idênticas para configurações de projeto de configuração de depuração.  Essa opção é marcada por padrão.  Todas as outras opções nesta página estão inativas, a menos que você desmarcar essa caixa.  
  
 **Criar linha de comando**  
 Especifica a linha de comando que cria o novo projeto.  Digite o nome do compilador mais quaisquer switches ou argumentos que você deseja usar para criar o novo projeto.  Essa opção é ativada quando o  **sistema de compilação externo de uso** opção é selecionada no  **Especificar configurações de projeto** página.  
  
 **Reconstruir a linha de comando**  
 Especifica a linha de comando que recria o novo projeto.  Essa opção é ativada quando o  **sistema de compilação externo de uso** opção é selecionada no  **Especificar configurações de projeto** página.  
  
 **Limpar linha de comando**  
 Especifica a linha de comando para excluir os arquivos de suporte gerados pelas ferramentas de compilação para o novo projeto.  Essa opção é ativada quando o  **sistema de compilação externo de uso** opção é selecionada no  **Especificar configurações de projeto** página.  
  
 **Saída \(para depuração\)**  
 Especifica o caminho do diretório dos arquivos de saída para a configuração de depuração do novo projeto.  Essa opção é ativada quando o  **sistema de compilação externo de uso** opção é selecionada no  **Especificar configurações de projeto** página.  
  
 **As definições do pré\-processador \(\/d\)**  
 Define os símbolos de pré\-processamento para o novo projeto.  Para obter mais informações, consulte [\/D \(definições de pré\-processador\)](../build/reference/d-preprocessor-definitions.md).  
  
 **Incluir o caminho de pesquisa \(\/ eu\)**  
 Especifica os caminhos de diretório para adicionar à lista de diretórios que o compilador pesquisará para resolver referências de arquivo passado para diretivas de pré\-processamento no novo projeto.  Para obter mais informações, consulte [\/I \(diretórios de inclusão adicionais\)](../build/reference/i-additional-include-directories.md).  
  
 **Arquivos de inclusão forçados \(\/FI\)**  
 Especifica os arquivos de cabeçalho para processar quando estiver criando um novo projeto.  Para obter mais informações, consulte [\/FI \(Arquivo de inclusão forçado do nome\)](../Topic/-FI%20\(Name%20Forced%20Include%20File\).md).  
  
 **.Caminho de pesquisa de assembly NET \(\/ AI\)**  
 Especifica os caminhos de diretório que o compilador pesquisará para resolver.NET assembly referências passaram para as diretivas de pré\-processamento no novo projeto.  Para obter mais informações, consulte [\/AI \(especificar diretórios de metadados\)](../build/reference/ai-specify-metadata-directories.md).  
  
 **Uso forçado.NET assemblies \(\/ FU\)**  
 Especifica.NET usados para processar quando estiver criando um novo projeto.  Para obter mais informações, consulte [\/FU \(nome forçado \#usando arquivo\)](../build/reference/fu-name-forced-hash-using-file.md).  
  
## Consulte também  
 [Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md)