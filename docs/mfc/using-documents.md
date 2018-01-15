---
title: Usando documentos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- documents [MFC], C++ applications
- data [MFC], reading
- documents [MFC]
- files [MFC], writing to
- data [MFC], documents
- files [MFC]
- views [MFC], C++ applications
- document/view architecture [MFC], documents
- reading data [MFC], documents and views
- printing [MFC], documents
- writing to files [MFC]
ms.assetid: f390d6d8-d0e1-4497-9b6a-435f7ce0776c
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 691d8d00b9c4671ea4b9c318313851a7fab73f7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-documents"></a>Usando documentos
Trabalhando juntos, documentos e exibições:  
  
-   Contêm, gerenciar e exibir sua específicas do aplicativo [dados](../mfc/managing-data-with-document-data-variables.md).  
  
-   Fornecer uma interface que consiste em [variáveis de dados de documento](../mfc/managing-data-with-document-data-variables.md) para manipular os dados.  
  
-   Participar [gravar e ler arquivos](../mfc/serializing-data-to-and-from-files.md).  
  
-   Participar [impressão](../mfc/role-of-the-view-in-printing.md).  
  
-   [Tratar](../mfc/handling-commands-in-the-document.md) a maioria dos comandos e mensagens de seu aplicativo.  
  
 O documento é particularmente envolvido no gerenciamento de dados. Armazene os dados, normalmente, em variáveis de membro de classe de documento. A exibição usa essas variáveis para acessar os dados para exibir e atualizar. Mecanismo de serialização do documento padrão gerencia lendo e gravando os dados para e de arquivos. Documentos também podem lidar com comandos (mas não Windows mensagens que **WM_COMMAND**).  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Derivando uma classe de documento de CDocument](../mfc/deriving-a-document-class-from-cdocument.md)  
  
-   [Gerenciando dados com variáveis de dados de documento](../mfc/managing-data-with-document-data-variables.md)  
  
-   [Serializando dados para e de arquivos](../mfc/serializing-data-to-and-from-files.md)  
  
-   [Ignorando o mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)  
  
-   [Manipulando comandos no documento](../mfc/handling-commands-in-the-document.md)  
  
-   [A função de membro OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument)  
  
-   [A função de membro DeleteContents](../mfc/reference/cdocument-class.md#deletecontents)  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

