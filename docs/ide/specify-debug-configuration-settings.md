---
title: "Novo projeto de código existente depurar configuração (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.importwiz.debugsettings
dev_langs: C++
ms.assetid: 607339a8-9d33-458b-8095-dc73f374e29d
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ec7d357d53cb93ad5ba81c02fc3ccf1931cdd1cf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="specify-debug-configuration-settings-create-new-project-from-existing-code-files-wizard"></a>Especificar definições de configuração da depuração, Assistente para Criar Novo Projeto de Arquivos de Código Existentes
Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar as configurações de projeto de depuração.  
  
## <a name="task-list"></a>Lista de Tarefas  
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Criar linha de comando**  
 Especifica a linha de comando que cria o novo projeto. Por exemplo, digite o nome do compilador (além de quaisquer opções e argumentos) ou a compilação de scripts que você deseja usar para criar o novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página; caso contrário, ele não está disponível.  
  
 **Recriar a linha de comando**  
 Especifica a linha de comando que recria o novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página; caso contrário, ele não está disponível.  
  
 **Limpar linha de comando**  
 Especifica a linha de comando para excluir arquivos de suporte gerados pelas ferramentas de compilação para o novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página; caso contrário, ele não está disponível.  
  
 **Saída (para depuração)**  
 Especifica o caminho do diretório dos arquivos de saída para a configuração de depuração do novo projeto. Essa opção é habilitada quando o **sistema de compilação externo Use** opção é selecionada no **especificar configurações de projeto** página; caso contrário, ele não está disponível.  
  
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
