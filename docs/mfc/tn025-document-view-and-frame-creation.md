---
title: "TN025: documento, exibi&#231;&#227;o e cria&#231;&#227;o de quadro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.creation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "documentos, exibição e criação de quadro"
  - "TN025"
ms.assetid: 09254d72-6e1d-43db-80e9-693887dbeda2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN025: documento, exibi&#231;&#227;o e cria&#231;&#227;o de quadro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve os problemas de criação e de propriedade para WinApps, DocTemplates, documentos, peças e exibições.  
  
## WinApp  
 Há um objeto de `CWinApp` no sistema.  
  
 Estaticamente é construído e inicializado pela implementação interna da estrutura de `WinMain`.  Você deve derivar de `CWinApp` para fazer nada útil \(exceção: dlls de extensão não devem ter uma instância de `CWinApp` — a inicialização é feita em `DllMain` no lugar\).  
  
 O objeto de `CWinApp` possui uma lista de modelos do documento \( `CPtrList`\).  Há um ou mais modelo de documento pelo aplicativo.  DocTemplates geralmente é carregado do arquivo de recurso \(ou seja, uma matriz de cadeia de caracteres\) em `CWinApp::InitInstance`.  
  
```  
pTemplate = new CDocTemplate(IDR_MYDOCUMENT, ...);  
AddDocTemplate(pTemplate);  
```  
  
 O objeto de `CWinApp` possui todas as janelas do quadro no aplicativo.  A janela principal do quadro para o aplicativo deve ser armazenada em **CWinApp::m\_pMainWnd**; geralmente você `m_pMainWnd` definido na implementação de `InitInstance` se você não permitem que AppWizard faz para você.  Para a interface \(SDI\) de um único documento este é um `CFrameWnd` que serve como o aplicativo principal enquadram a janela bem como a única janela do quadro do documento.  Para a interface documentos \(MDI\) este é um MDI\- quadro \(classe `CMDIFrameWnd`\) que serve como a janela do quadro de aplicativo principal que contém todos os `CFrameWnd`filho S.  Cada janela filho é da classe `CMDIChildWnd` \(derivado de `CFrameWnd`\) e de atua como uma potencial de muitas janelas do quadro do documento.  
  
## DocTemplates  
 `CDocTemplate` é o designer e o gerenciador de documentos.  Possui os documentos que cria.  Se seu aplicativo usar a abordagem com base nos recursos descrita abaixo, não precisará derivar de `CDocTemplate`.  
  
 Para um aplicativo de SDI, a classe `CSingleDocTemplate` mantém acompanha de um documento aberto.  Para um aplicativo MDI, a classe `CMultiDocTemplate` mantém uma lista `CPtrList`\(\) de todos os documentos abertos atualmente criados desse modelo.  `CDocTemplate::AddDocument` e `CDocTemplate::RemoveDocument` fornecem as funções de membro virtuais para adicionar ou remover um documento de modelo.  `CDocTemplate` é um amigo de **CDocument** para podermos definir o ponteiro protegido voltar do **CDocument::m\_pDocTemplate** para apontar novamente para o modelo de doc que criou o documento.  
  
 `CWinApp` trata a implementação padrão de `OnFileOpen` , verá que por sua vez todos os modelos de doc.  A implementação já inclui a procura de documentos abertos e decidir qual formato para abrir novos documentos.  
  
 `CDocTemplate` gerencia interface do usuário que associa para documentos e peças.  
  
 `CDocTemplate` mantém uma contagem do número de documentos sem nome.  
  
## CDocument  
 **CDocument** é de propriedade de `CDocTemplate`.  
  
 Os documentos têm uma lista de exibições abertas \(derivadas de `CView`\) que está exibindo o documento \( `CPtrList`\).  
  
 Os documentos não criação\/destroem as exibições, mas estiverem conectados entre si depois que eles são criados.  Quando um documento seja fechado \(isto é, com o Arquivo\/término\), todas as exibições anexados serão fechadas.  Quando a exibição a mais recente em um documento é fechada \(isto é, a janela\/\) para o documento será fechado.  
  
 `CDocument::AddView`, interface de `RemoveView` é usado para manter a lista de exibição.  **CDocument** é um amigo de `CView` para podermos definir o ponteiro voltar do **CView::m\_pDocument** .  
  
## CFrameWnd  
 `CFrameWnd` \(também conhecido como um quadro\) executa a mesma função de em MFC 1,0, mas a classe de `CFrameWnd` agora é criado para ser usado em muitos casos sem derivar uma nova classe.  As classes derivadas `CMDIFrameWnd` e `CMDIChildWnd` são aprimoradas também muitos comandos padrão são implementadas já.  
  
 `CFrameWnd` é responsável por criar o windows na área de cliente do quadro.  Geralmente há uma janela principal que preenche a área de cliente do quadro.  
  
 Para uma janela de MDI\- quadro, a área de cliente é preenchida com o controle de MDICLIENT por sua vez que é o pai de todas as janelas do quadro de MDI\- filho.  Para uma janela de SDI\- quadro ou uma janela do quadro de MDI\- filho, a área de cliente geralmente é preenchida com `CView`\- objeto derivado da janela.  No caso de `CSplitterWnd`, a área do cliente da exibição é preenchida com o objeto da janela de `CSplitterWnd` , e o `CView`\- os objetos derivados da janela do \(por um painel dividido\) são criados como janelas filho de `CSplitterWnd`.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)