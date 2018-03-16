---
title: Ajuda (WinHelp) de arquivos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- file types [C++], WinHelp files
ms.assetid: 4fdcbd66-66b0-4866-894a-fd7b4c2557e4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a5698f7001512c5a4f8c45b5c787f35c9ce0ca6c
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="help-files-winhelp"></a>Arquivos de ajuda (WinHelp)
Os seguintes arquivos são criados quando você adicionar o tipo de WinHelp de Ajuda e suporte para o seu aplicativo selecionando o **ajuda contextual** caixa de seleção e, em seguida, selecionando **formato WinHelp** no [Recursos avançados](../mfc/reference/advanced-features-mfc-application-wizard.md) página do Assistente de aplicativo MFC.  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de solução|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*Projname*.hpj|*Projname*\hlp|Arquivos de fonte|O arquivo de projeto de Ajuda usado pelo compilador ajuda a criar seu programa ou arquivo de Ajuda do controle.|  
|*Projname*.rtf|*Projname*\hlp|Arquivos de ajuda|Contém tópicos de modelo que você pode editar e informações sobre como personalizar o arquivo. hpj.|  
|*Projname*.cnt|*Projname*\hlp|Arquivos de ajuda|Fornece a estrutura para o **conteúdo** janela na Ajuda do Windows.|  
|Makehelp.bat|*Projname*|Arquivos de fonte|Usada pelo sistema para compilar o projeto de ajuda quando o projeto é compilado.|  
|Print.rtf|*Projname*\hlp|Arquivos de ajuda|Criado se seu projeto inclui suporte para impressão (padrão). Descreve as caixas de diálogo e comandos de impressão.|  
|*.bmp|*Projname*\hlp|Arquivos de recursos|Contém imagens para os tópicos do arquivo de ajuda gerado.|  
  
 Você pode adicionar suporte de WinHelp para um projeto de controle ActiveX MFC selecionando **gerar arquivos de Ajuda** no [configurações de aplicativo](../mfc/reference/application-settings-mfc-activex-control-wizard.md) guia do Assistente de controle ActiveX do MFC. Os seguintes arquivos são adicionados ao seu projeto quando você adiciona o suporte de ajuda para um controle ActiveX MFC:  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de solução|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*Projname*.hpj|*Projname*\hlp|Arquivos de origem|O arquivo de projeto usado pelo compilador de ajuda para criar seu programa ou arquivo de Ajuda do controle.|  
|*Projname*.rtf|*Projname*\hlp|Projeto|Contém tópicos de modelo que você pode editar e informações sobre como personalizar o arquivo. hpj.|  
|Makehelp.bat|*Projname*|Arquivos de fonte|Usada pelo sistema para compilar o projeto de ajuda quando o projeto é compilado.|  
|Porta|*Projname*|Arquivos de recursos|Usado por tópicos padrão de arquivo de ajuda para representar a lista com marcadores.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)