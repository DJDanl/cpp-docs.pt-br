---
title: (Ajuda HTML) de arquivos de ajuda | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: file types [C++], HTML Help files
ms.assetid: d30a1b1b-318f-4a78-8b60-93da53a224a8
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c96cd6ad904439f556f2baa51602353ea00c5ac7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="help-files-html-help"></a>Arquivos de ajuda (ajuda HTML)
Os seguintes arquivos são criados quando você adicionar o tipo de Ajuda em HTML da Ajuda e suporte para o seu aplicativo selecionando o **ajuda contextual** caixa de seleção e, em seguida, selecionando **formato de ajuda HTML** no [Recursos avançados](../mfc/reference/advanced-features-mfc-application-wizard.md) página do Assistente de aplicativo MFC.  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de solução|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*NomeDoProjeto*. hhp|*NomeDoProjeto*\hlp|Arquivos da Ajuda HTML|O arquivo de projeto de Ajuda. Ele contém os dados necessários para compilar os arquivos de Ajuda em um arquivo HXS ou um arquivo. chm.|  
|*NomeDoProjeto*.hhk|*NomeDoProjeto*\hlp|Arquivos da Ajuda HTML|Contém um índice dos tópicos da Ajuda.|  
|*NomeDoProjeto*.hhc|*NomeDoProjeto*\hlp|Arquivos da Ajuda HTML|O conteúdo da Ajuda do projeto.|  
|Makehtmlhelp.bat|*NomeDoProjeto*|Arquivos de fonte|Usada pelo sistema para compilar o projeto de ajuda quando o projeto é compilado.|  
|Afxcore.htm|*NomeDoProjeto*\hlp|Tópicos de ajuda HTML|Contém tópicos da Ajuda padrão para comandos do MFC padrão e objetos da tela. Adicione seus próprios tópicos de ajuda para este arquivo.|  
|Afxprint.htm|*NomeDoProjeto*\hlp|Tópicos de ajuda HTML|Contém tópicos da Ajuda para os comandos de impressão.|  
|JPG; \*. gif|*NomeDoProjeto*\hlp\Images|Arquivos de recursos|Contém imagens para os tópicos do arquivo de ajuda gerado.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)