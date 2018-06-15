---
title: Arquivos de Ajuda (WinHelp) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- file types [C++], WinHelp files
ms.assetid: 4fdcbd66-66b0-4866-894a-fd7b4c2557e4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 505506c7f3a14a73c6b0c859a70938fee3eed69e
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33331539"
---
# <a name="help-files-winhelp"></a>Arquivos de ajuda (WinHelp)
Os arquivos a seguir são criados quando você adiciona o tipo Ajuda WinHelp do suporte de Ajuda ao aplicativo, marcando a caixa de seleção **Ajuda contextual** e, em seguida, selecionando **Formato WinHelp** na página [Funcionalidades Avançadas](../mfc/reference/advanced-features-mfc-application-wizard.md) do Assistente de Aplicativo MFC.  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de Soluções|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*Nome_do_projeto*.hpj|*Nome_do_projeto*\hlp|Arquivos de fonte|O arquivo de projeto de Ajuda usado pelo compilador de Ajuda para criar o arquivo de Ajuda do programa ou do controle.|  
|*Nome_do_projeto*.rtf|*Nome_do_projeto*\hlp|Arquivos de Ajuda|Contém tópicos de modelo que podem ser editados e informações sobre como personalizar o arquivo .hpj.|  
|*Nome_do_projeto*.cnt|*Nome_do_projeto*\hlp|Arquivos de Ajuda|Fornece a estrutura para a janela **Conteúdo** na Ajuda do Windows.|  
|Makehelp.bat|*Nome_do_projeto*|Arquivos de fonte|Usado pelo sistema para compilar o projeto da Ajuda quando o projeto é compilado.|  
|Print.rtf|*Nome_do_projeto*\hlp|Arquivos de Ajuda|Criado se o projeto inclui suporte para impressão (o padrão). Descreve as caixas de diálogo e os comandos de impressão.|  
|*.bmp|*Nome_do_projeto*\hlp|Arquivos de recursos|Contém as imagens para os tópicos do arquivo de Ajuda gerados.|  
  
 Adicione o suporte do WinHelp a um projeto de Controle ActiveX do MFC selecionando **Gerar arquivos de Ajuda** na guia [Configurações de Aplicativo](../mfc/reference/application-settings-mfc-activex-control-wizard.md) do Assistente de Controle ActiveX do MFC. Os seguintes arquivos são adicionados ao projeto quando você adiciona o suporte de Ajuda a um controle ActiveX do MFC:  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de Soluções|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*Nome_do_projeto*.hpj|*Nome_do_projeto*\hlp|Arquivos de origem|O arquivo de projeto usado pelo compilador de Ajuda para criar o arquivo de Ajuda do programa ou do controle.|  
|*Nome_do_projeto*.rtf|*Nome_do_projeto*\hlp|Projeto|Contém tópicos de modelo que podem ser editados e informações sobre como personalizar o arquivo .hpj.|  
|Makehelp.bat|*Nome_do_projeto*|Arquivos de fonte|Usado pelo sistema para compilar o projeto da Ajuda quando o projeto é compilado.|  
|Bullet.bmp|*Nome_do_projeto*|Arquivos de recursos|Usado pelos tópicos de arquivo de Ajuda padrão para representar a lista com marcadores.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)