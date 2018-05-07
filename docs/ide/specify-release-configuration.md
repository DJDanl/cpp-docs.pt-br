---
title: Configuração de lançamento do novo projeto de código existente | Microsoft Docs
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
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="specify-release-configuration-settings-create-new-project-from-existing-code-files-wizard"></a>Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes
Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar as configurações de projeto de versão.  
  
## <a name="task-list"></a>Lista de Tarefas  
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Mesmo que a configuração de depuração**  
 Especifica que o assistente irá gerar versão as configurações de projeto idênticas para depurar configurações de projeto. Essa opção é selecionada por padrão. Todas as outras opções nesta página estarão inativas exceto se você desmarcar essa caixa.  
  
 **Criar linha de comando**  
 Especifica a linha de comando que cria o novo projeto. Digite o nome do compilador mais qualquer switches ou argumentos que você deseja usar para criar o novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página.  
  
 **Recriar a linha de comando**  
 Especifica a linha de comando que recria o novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página.  
  
 **Limpar linha de comando**  
 Especifica a linha de comando para excluir arquivos de suporte gerados pelas ferramentas de compilação para o novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página.  
  
 **Saída (para depuração)**  
 Especifica o caminho do diretório dos arquivos de saída para a configuração de depuração do novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página.  
  
 **Definições de pré-processador (/ D)**  
 Define símbolos de pré-processamento para o novo projeto. Para obter mais informações, consulte [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md).  
  
 **Caminho de pesquisa de inclusão (/ eu)**  
 Especifica os caminhos de diretório para adicionar à lista de diretórios que o compilador pesquisará a resolver referências de arquivo passados para as diretivas de pré-processamento no novo projeto. Para obter mais informações, consulte [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md).  
  
 **Arquivos de inclusão forçados (/FI)**  
 Especifica os arquivos de cabeçalho para processar ao criar o novo projeto. Para obter mais informações, consulte [/FI (nomear arquivo de include forçado)](../build/reference/fi-name-forced-include-file.md).  
  
 **Caminho de pesquisa de assembly .NET (/ AI)**  
 Especifica os caminhos de diretório que o compilador pesquisará para resolver referências de assembly .NET passado para as diretivas de pré-processamento no novo projeto. Para obter mais informações, consulte [/AI (Especificar Diretórios de Metadados)](../build/reference/ai-specify-metadata-directories.md).  
  
 **Forçado a usar assemblies .NET (/ /FU)**  
 Especifica os assemblies do .NET para processar ao criar o novo projeto. Para obter mais informações, consulte [/FU (nome forçado #usando arquivo)](../build/reference/fu-name-forced-hash-using-file.md).  
  
## <a name="see-also"></a>Consulte também  
 [Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-project-settings-create-new-project-from-existing-code-files-wizard.md)