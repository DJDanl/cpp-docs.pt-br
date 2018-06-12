---
title: Arquivos de Ajuda (Ajuda HTML) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- file types [C++], HTML Help files
ms.assetid: d30a1b1b-318f-4a78-8b60-93da53a224a8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d180fe4f9cf1baf26b27423ffda975bfe0fe85ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33325069"
---
# <a name="help-files-html-help"></a>Arquivos de ajuda (ajuda HTML)
Os arquivos a seguir são criados quando você adiciona o tipo Ajuda HTML do suporte de Ajuda ao aplicativo, marcando a caixa de seleção **Ajuda contextual** e, em seguida, selecionando **Formato da Ajuda HTML** na página [Funcionalidades Avançadas](../mfc/reference/advanced-features-mfc-application-wizard.md) do Assistente de Aplicativo MFC.  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de Soluções|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*Nome_do_projeto*.hhp|*Nome_do_projeto*\hlp|Arquivos da Ajuda HTML|O arquivo de projeto da Ajuda. Ele contém os dados necessários para compilar os arquivos de Ajuda em um arquivo .hxs ou .chm.|  
|*Nome_do_projeto*.hhk|*Nome_do_projeto*\hlp|Arquivos da Ajuda HTML|Contém um índice dos tópicos da Ajuda.|  
|*Nome_do_projeto*.hhc|*Nome_do_projeto*\hlp|Arquivos da Ajuda HTML|O conteúdo do projeto da Ajuda.|  
|Makehtmlhelp.bat|*Nome_do_projeto*|Arquivos de fonte|Usado pelo sistema para compilar o projeto da Ajuda quando o projeto é compilado.|  
|Afxcore.htm|*Nome_do_projeto*\hlp|Tópicos da Ajuda HTML|Contém tópicos da Ajuda padrão para comandos MFC padrão e objetos de tela. Adicione seus próprios tópicos da Ajuda a esse arquivo.|  
|Afxprint.htm|*Nome_do_projeto*\hlp|Tópicos da Ajuda HTML|Contém os tópicos da Ajuda para os comandos de impressão.|  
|*.jpg; \*.gif|*Nome_do_projeto*\hlp\Images|Arquivos de recursos|Contém as imagens para os tópicos do arquivo de Ajuda gerados.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)