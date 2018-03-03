---
title: "TN025: Documento, exibição e criação de quadro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.creation
dev_langs:
- C++
helpviewer_keywords:
- documents [MFC], view and frame creation
- TN025
ms.assetid: 09254d72-6e1d-43db-80e9-693887dbeda2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 89ca395b19a36c42163b854c8997cce424352ead
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn025-document-view-and-frame-creation"></a>TN025: documento, exibição e criação de quadro
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve os problemas de criação e a propriedade de WINAPPS Word, DocTemplates, documentos, quadros e modos de exibição.  
  
## <a name="winapp"></a>WinApp  
 Há um `CWinApp` objeto do sistema.  
  
 Estaticamente é criada e inicializada, a implementação interna da estrutura de `WinMain`. Você deve derivar de `CWinApp` fazer nada útil (exceção: DLLs de extensão do MFC não devem ter um `CWinApp` instância — é feita na `DllMain` em vez disso).  
  
 O `CWinApp` objeto possui uma lista de modelos de documento (um `CPtrList`). Há um ou mais o modelo de documento por aplicativo. DocTemplates geralmente são carregados do arquivo de recurso (ou seja, uma matriz de cadeia de caracteres) em `CWinApp::InitInstance`.  
  
```  
pTemplate = new CDocTemplate(IDR_MYDOCUMENT, ...);

AddDocTemplate(pTemplate);
```  
  
 O `CWinApp` objeto possui todas as janelas de quadro no aplicativo. A janela do quadro principal para o aplicativo deve ser armazenada em **CWinApp::m_pMainWnd**; normalmente você definir `m_pMainWnd` no `InitInstance` implementação se você não tem que AppWizard fazê-lo para você. Para a interface de documento único (SDI) esse é um `CFrameWnd` que serve como a janela do quadro principal do aplicativo, bem como a janela do quadro de documento somente. Para a interface de documentos múltiplos (MDI), este é um quadro MDI (classe `CMDIFrameWnd`) que serve como a janela do quadro principal do aplicativo que contém todos os filhos `CFrameWnd`s. Cada janela filho é da classe `CMDIChildWnd` (derivado de `CFrameWnd`) e serve como um potencialmente muitas janelas de quadro do documento.  
  
## <a name="doctemplates"></a>DocTemplates  
 O `CDocTemplate` é o criador e o Gerenciador de documentos. Ele possui os documentos que ele cria. Se seu aplicativo usa a abordagem baseada em recursos descrita abaixo, não será necessário derivar de `CDocTemplate`.  
  
 Para um aplicativo SDI, a classe `CSingleDocTemplate` mantém o controle de um documento aberto. Para um aplicativo MDI, a classe `CMultiDocTemplate` mantém uma lista (um `CPtrList`) de todos os documentos abertos criados a partir desse modelo. `CDocTemplate::AddDocument`e `CDocTemplate::RemoveDocument` fornecem o membro virtual funções para adicionar ou remover um documento do modelo. `CDocTemplate`é um amigo do **CDocument** forma podemos definir protegido **CDocument::m_pDocTemplate** retorno que apontam para o modelo de documento que criou o documento.  
  
 `CWinApp`manipula o padrão `OnFileOpen` implementação, que por sua vez consultará todos os modelos de documento. A implementação inclui procurando documentos já abertos e decidir qual formato para abrir novos documentos no.  
  
 `CDocTemplate`gerencia a associação de interface do usuário para documentos e quadros.  
  
 `CDocTemplate`mantém uma contagem do número de documentos sem nome.  
  
## <a name="cdocument"></a>CDocument  
 Um **CDocument** pertence a um `CDocTemplate`.  
  
 Documentos tem uma lista de abertos exibições (derivado de `CView`) que está exibindo o documento (um `CPtrList`).  
  
 Documentos não criar/destruir os modos de exibição, mas eles são conectados uns aos outros após serem criadas. Quando um documento é fechado (ou seja, a arquivo/fechar), todas as exibições anexadas serão fechadas. O documento será fechado quando a última exibição em um documento é fechada (ou seja, janela/Fechar).  
  
 O `CDocument::AddView`, `RemoveView` interface é usada para manter a lista de exibição. **CDocument** é um amigo do `CView` forma podemos definir o **CView::m_pDocument** retorno.  
  
## <a name="cframewnd"></a>CFrameWnd  
 Um `CFrameWnd` (também conhecido como um quadro) desempenha a mesma função de MFC 1.0, mas agora o `CFrameWnd` classe foi projetada para ser usado em muitos casos sem derivar uma nova classe. As classes derivadas `CMDIFrameWnd` e `CMDIChildWnd` também foram aprimorados para muitos comandos padrão já são implementados.  
  
 O `CFrameWnd` é responsável pela criação do windows na área cliente do quadro. Normalmente, há uma janela principal que preenche a área cliente do quadro.  
  
 Para uma janela de quadro MDI, a área do cliente é preenchida com o controle MDICLIENT que por sua vez é o pai de todas as janelas de quadro filho MDI. Para uma janela de quadro SDI ou uma janela filho MDI do quadro, a área de cliente geralmente é preenchida com um `CView`-janela objeto derivado. No caso de `CSplitterWnd`, a área do cliente do modo de exibição é preenchida com o `CSplitterWnd` objeto de janela e o `CView`-objetos de janela derivadas (um por painel de divisão) são criados como janelas filho do `CSplitterWnd`.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

