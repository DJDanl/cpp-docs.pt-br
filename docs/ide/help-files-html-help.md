---
title: (Ajuda HTML) de arquivos de ajuda | Microsoft Docs
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
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="help-files-html-help"></a>Arquivos de ajuda (ajuda HTML)
Os seguintes arquivos são criados quando você adicionar o tipo de Ajuda em HTML da Ajuda e suporte para o seu aplicativo selecionando o **ajuda contextual** caixa de seleção e, em seguida, selecionando **formato de ajuda HTML** no [Recursos avançados](../mfc/reference/advanced-features-mfc-application-wizard.md) página do Assistente de aplicativo MFC.  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de solução|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*Projname*.hhp|*NomeDoProjeto*\hlp|Arquivos da Ajuda HTML|O arquivo de projeto de Ajuda. Ele contém os dados necessários para compilar os arquivos de Ajuda em um arquivo HXS ou um arquivo. chm.|  
|*Projname*.hhk|*NomeDoProjeto*\hlp|Arquivos da Ajuda HTML|Contém um índice dos tópicos da Ajuda.|  
|*Projname*.hhc|*NomeDoProjeto*\hlp|Arquivos da Ajuda HTML|O conteúdo da Ajuda do projeto.|  
|Makehtmlhelp.bat|*Projname*|Arquivos de fonte|Usada pelo sistema para compilar o projeto de ajuda quando o projeto é compilado.|  
|Afxcore.htm|*NomeDoProjeto*\hlp|Tópicos de ajuda HTML|Contém tópicos da Ajuda padrão para comandos do MFC padrão e objetos da tela. Adicione seus próprios tópicos de ajuda para este arquivo.|  
|Afxprint.htm|*NomeDoProjeto*\hlp|Tópicos de ajuda HTML|Contém tópicos da Ajuda para os comandos de impressão.|  
|*.jpg; \*.gif|*NomeDoProjeto*\hlp\Images|Arquivos de recursos|Contém imagens para os tópicos do arquivo de ajuda gerado.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)