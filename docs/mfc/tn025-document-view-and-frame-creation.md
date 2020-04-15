---
title: 'TN025: documento, exibição e criação de quadro'
ms.date: 11/04/2016
f1_keywords:
- vc.creation
helpviewer_keywords:
- documents [MFC], view and frame creation
- TN025
ms.assetid: 09254d72-6e1d-43db-80e9-693887dbeda2
ms.openlocfilehash: 2fdabdcb1a87d4a5661348588d49303290c966ce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370363"
---
# <a name="tn025-document-view-and-frame-creation"></a>TN025: documento, exibição e criação de quadro

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve os problemas de criação e propriedade de WinApps, DocTemplates, Documentos, Quadros e Visualizações.

## <a name="winapp"></a>WinApp

Há um `CWinApp` objeto no sistema.

É construído e iniciado estáticamente pela implementação interna `WinMain`do quadro de . Você deve `CWinApp` derivar de fazer qualquer coisa útil (exceção: `CWinApp` DLLs de `DllMain` extensão MFC não devem ter uma instância — a inicialização é feita em vez disso).

O `CWinApp` único objeto possui uma lista de `CPtrList`modelos de documentos (a ). Há um ou mais modelos de documento por aplicativo. DocTemplates geralmente são carregados a partir do arquivo de `CWinApp::InitInstance`recursos (ou seja, uma matriz de strings) em .

```
pTemplate = new CDocTemplate(IDR_MYDOCUMENT, ...);

AddDocTemplate(pTemplate);
```

O `CWinApp` único objeto possui todas as janelas de quadro no aplicativo. A janela do quadro principal para `CWinApp::m_pMainWnd`a aplicação deve ser armazenada em; normalmente *m_pMainWnd* você define `InitInstance` m_pMainWnd na implementação se você não deixar o AppWizard fazê-lo para você. Para interface de documento único (SDI), esta é uma `CFrameWnd` que serve como a janela principal do quadro do aplicativo, bem como a única janela de quadro de documento. Para interface de documento múltiplo (MDI), esta `CMDIFrameWnd`é uma MDI-Frame (classe) que `CFrameWnd`serve como a janela principal do quadro do aplicativo que contém todos os filhos. Cada janela infantil `CMDIChildWnd` é de `CFrameWnd`classe (derivada ) e serve como uma das potencialmente muitas janelas de quadro de documentos.

## <a name="doctemplates"></a>DocTemplates

O `CDocTemplate` é o criador e gerente de documentos. É dono dos documentos que cria. Se o aplicativo usar a abordagem baseada em recursos `CDocTemplate`descrita abaixo, ela não precisará derivar de .

Para um aplicativo SDI, a classe `CSingleDocTemplate` mantém o controle de um documento aberto. Para um aplicativo MDI, a `CMultiDocTemplate` classe `CPtrList`mantém uma lista (a ) de todos os documentos abertos atualmente criados a partir desse modelo. `CDocTemplate::AddDocument`e `CDocTemplate::RemoveDocument` fornecer as funções de membro virtual para adicionar ou remover um documento do modelo. `CDocTemplate`é um `CDocument` amigo de modo que `CDocument::m_pDocTemplate` podemos definir o ponteiro de volta protegido para apontar de volta para o modelo doc que criou o documento.

`CWinApp`lida com `OnFileOpen` a implementação padrão, que, por sua vez, consultará todos os modelos doc. A implementação inclui procurar documentos já abertos e decidir em que formato abrir novos documentos.

`CDocTemplate`gerencia a vinculação da UI para documentos e quadros.

`CDocTemplate`mantém uma contagem do número de documentos não nomeados.

## <a name="cdocument"></a>Cdocument

A `CDocument` é propriedade `CDocTemplate`de um .

Os documentos têm uma lista de visualizações abertas atualmente (derivadas) `CView`que estão visualizando o documento (a `CPtrList`).

Os documentos não criam/destroem as visualizações, mas são anexadas umas às outras depois de criadas. Quando um documento é fechado (isto é, através de Arquivo/Fechamento), todas as visualizações anexadas serão fechadas. Quando a última exibição de um documento estiver fechada (ou seja, Janela/Fechamento) o documento será fechado.

A `CDocument::AddView` `RemoveView` interface é usada para manter a lista de exibição. `CDocument`é um `CView` amigo de modo `CView::m_pDocument` que podemos definir o ponteiro de volta.

## <a name="cframewnd"></a>CFrameWnd

A `CFrameWnd` (também conhecido como quadro) desempenha o mesmo papel que no `CFrameWnd` MFC 1.0, mas agora a classe foi projetada para ser usada em muitos casos sem obter uma nova classe. As classes `CMDIFrameWnd` derivadas e `CMDIChildWnd` também são aprimoradas, então muitos comandos padrão já estão implementados.

O `CFrameWnd` é responsável por criar janelas na área cliente do quadro. Normalmente há uma janela principal preenchendo a área do cliente do quadro.

Para uma janela MDI-Frame, a área do cliente é preenchida com o controle MDICLIENT, que por sua vez é o pai de todas as janelas de quadro MDI-Child. Para uma janela SDI-Frame ou uma janela de quadro MDI-Child, a área do cliente geralmente é preenchida com um `CView`objeto de janela derivado. No caso `CSplitterWnd`de , a área cliente da `CSplitterWnd` exibição é `CView`preenchida com o objeto da janela, e os objetos `CSplitterWnd`de janela derivados (um por painel dividido) são criados como janelas de criança do .

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
