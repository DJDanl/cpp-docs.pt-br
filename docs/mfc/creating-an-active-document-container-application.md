---
title: "Criando um aplicativo de cont&#234;iner de documento ativo | Microsoft Docs"
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
  - "contêineres de documentos ativos [C++], criando"
  - "documentos ativos [C++], contêineres"
  - "aplicativos [MFC], contêiner de documentos ativos"
  - "contêineres [C++], documento ativo"
  - "COM MFC [C++], contenção de documentos ativos"
ms.assetid: 14e2d022-a6c5-4249-8712-706b0f4433f7
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um aplicativo de cont&#234;iner de documento ativo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira mais simples e mais recomendada de criar um aplicativo de contêiner ativa do documento é criar um aplicativo de contêineres de MFC EXE usando o assistente de aplicativo MFC, então altera o aplicativo dar suporte à retenção ativa do documento.  
  
#### Para criar um aplicativo de contêineres do documento ativo  
  
1.  No menu de **Arquivo** , clique em **Projeto**no submenu de **Novo** .  
  
2.  No painel esquerdo, tipo de projeto de **Visual C\+\+** clique em.  
  
3.  **Aplicativo do MFC** Selecione no painel direito.  
  
4.  O nome do projeto `MyProj`, clique em **OK**.  
  
5.  Selecione a página de **Combina o suporte do documento** .  
  
6.  Selecione a opção de **Contêiner** ou de **Contêiner\/servidor completo** .  
  
7.  Marque a caixa de seleção de **Contêiner do documento ativo** .  
  
8.  Clique em **Concluir**.  
  
9. Quando o assistente de aplicativo MFC terminar de gerar o aplicativo, abra os seguintes arquivos usando Solution Explorer:  
  
    -   MyProjview.cpp  
  
10. Em MyProjview.cpp, faça as seguintes alterações:  
  
    -   Em `CMyProjView::OnPreparePrinting`, substitua o conteúdo da função com o seguinte código:  
  
         [!code-cpp[NVC_MFCDocView#56](../mfc/codesnippet/CPP/creating-an-active-document-container-application_1.cpp)]  
  
     `OnPreparePrinting` fornece suporte de impressão.  Esse código substitui `DoPreparePrinting`, que é a preparação padrão de cópia.  
  
     A retenção ativa do documento fornece um esquema aprimorado de impressão:  
  
    -   Você pode chamar primeiro para o documento ativo pela interfacede `IPrint`e para dizê\-la para imprimir\-se.  Isso é diferente de retenção OLE anterior, em que o contêiner tinha que processar uma imagem do item contido no objeto de `CDC`da impressora.  
  
    -   Se isso falhar, digamos o item contido para imprimir\-se pela interfacede `IOleCommandTarget`  
  
    -   Se isso falhar, faça sua própria renderização do item.  
  
     As funções de membro estáticas `COleDocObjectItem::OnPrint` e `COleDocObjectItem::OnPreparePrinting`, conforme implementado no código anterior, tratam esse esquema aprimorado de impressão.  
  
11. Adicionar qualquer implementação de seus próprios e criar o aplicativo.  
  
## Consulte também  
 [Contenção de documento ativa](../mfc/active-document-containment.md)