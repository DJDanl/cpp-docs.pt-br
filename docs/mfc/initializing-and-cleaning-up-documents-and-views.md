---
title: "Inicializando e limpando documentos e exibi&#231;&#245;es | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos de documento, ciclo de vida de"
  - "documentos, limpando"
  - "documentos, inicializando"
  - "inicializando documentos"
  - "inicializando objetos, objetos de documento"
  - "inicializando exibições"
  - "modos de exibição, limpando"
  - "modos de exibição, inicializando"
ms.assetid: 95d6f09b-a047-4079-856a-ae7d0548e9d2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializando e limpando documentos e exibi&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as seguintes diretrizes inicializando e limpeza após os seus documentos e exibições:  
  
-   Inicializa a estrutura MFC documentos e exibições; você inicializar todos os dados que você adicionar a eles.  
  
-   A estrutura limpa como documentos e exibições é fechado; você deverá desalocar qualquer memória que você atribua no heap de dentro das funções de membro dos documentos e exibições.  
  
> [!NOTE]
>  Lembre\-se de que a inicialização do aplicativo inteiro será feita melhor na substituição da função de membro de [InitInstance](../Topic/CWinApp::InitInstance.md) da classe `CWinApp`, e a limpeza do aplicativo inteiro é feita melhor na substituição da função de membro [ExitInstance](../Topic/CWinApp::ExitInstance.md)de `CWinApp` .  
  
 O ciclo de vida de um documento \(e suas janela do quadro e exibição ou exibições\) em um aplicativo MDI é a seguinte:  
  
1.  Durante a criação dinâmico, o construtor de documento é chamado.  
  
2.  Para cada novo documento, [OnNewDocument](../Topic/CDocument::OnNewDocument.md) ou [OnOpenDocument](../Topic/CDocument::OnOpenDocument.md) do documento são chamados.  
  
3.  O usuário interage com o documento durante todo o tempo de vida.  Normalmente isso ocorre quando o usuário trabalhar nos dados de documento com a exibição, selecionando e editando os dados.  A exibição passa alterações no documento para o armazenamento e atualizar outras exibições.  Durante esse tempo o documento e a exibição podem tratar comandos.  
  
4.  A estrutura chama [DeleteContents](../Topic/CDocument::DeleteContents.md) para excluir os dados específicos de para um documento.  
  
5.  O destruidor do documento é chamado.  
  
 Em um aplicativo de SDI etapa 1, será executada uma vez, quando o documento é criado.  Nas etapas de 2 a 4 serão executadas repetidamente sempre que um novo documento é aberto.  O novo documento reutilizam o objeto existente do documento.  Finalmente, a etapa 5 é executada quando o aplicativo termina.  
  
## Que você deseja saber mais?  
  
-   [Inicializando documentos e exibições](../mfc/initializing-documents-and-views.md)  
  
-   [Limpar autodocumentação e exibições](../Topic/Cleaning%20Up%20Documents%20and%20Views.md)  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)