---
title: 'TN025: Documento, exibição e criação de quadro'
ms.date: 11/04/2016
f1_keywords:
- vc.creation
helpviewer_keywords:
- documents [MFC], view and frame creation
- TN025
ms.assetid: 09254d72-6e1d-43db-80e9-693887dbeda2
ms.openlocfilehash: 4958e7c4ca2c3cf9eed6420d72d0399fa112098d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284678"
---
# <a name="tn025-document-view-and-frame-creation"></a>TN025: Documento, exibição e criação de quadro

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve os problemas de criação e a propriedade para WINAPPS Word, DocTemplates, documentos, quadros e modos de exibição.

## <a name="winapp"></a>WinApp

Há um `CWinApp` objeto no sistema.

Ele estaticamente é criado e inicializado pela implementação interna da estrutura de `WinMain`. Você deve derivar de `CWinApp` fazer alguma coisa útil (exceção: DLLs de extensão do MFC não devem ter uma `CWinApp` instância — que é feita na `DllMain` em vez disso).

Aquele `CWinApp` objeto possui uma lista de modelos de documento (um `CPtrList`). Há um ou mais o modelo de documento por aplicativo. DocTemplates geralmente são carregados do arquivo de recurso (ou seja, uma matriz de cadeia de caracteres) em `CWinApp::InitInstance`.

```
pTemplate = new CDocTemplate(IDR_MYDOCUMENT, ...);

AddDocTemplate(pTemplate);
```

Aquele `CWinApp` objeto possui todas as janelas de quadro no aplicativo. A janela do quadro principal para o aplicativo deve ser armazenada em `CWinApp::m_pMainWnd`; geralmente você define *m_pMainWnd* no `InitInstance` implementação se você não tem que AppWizard fazê-lo para você. Para a interface de documento único (SDI) Este é um `CFrameWnd` que serve como a janela do quadro principal do aplicativo, bem como a janela de quadro único documento. Para a interface de documentos múltiplos (MDI), isso é um quadro MDI (classe `CMDIFrameWnd`) que serve como a janela do quadro principal do aplicativo que contém todos os filhos `CFrameWnd`s. Cada janela filho é da classe `CMDIChildWnd` (derivado de `CFrameWnd`) e serve como uma das janelas de quadro possivelmente de vários documentos.

## <a name="doctemplates"></a>DocTemplates

O `CDocTemplate` é o criador e o Gerenciador de documentos. Ele possui os documentos que ele cria. Se seu aplicativo usa a abordagem baseada em recursos descrita abaixo, ele não será necessário derivar de `CDocTemplate`.

Para um aplicativo SDI, a classe `CSingleDocTemplate` mantém o controle de um documento aberto. Para um aplicativo MDI, a classe `CMultiDocTemplate` mantém uma lista (um `CPtrList`) de todos os documentos abertos no momento criados a partir desse modelo. `CDocTemplate::AddDocument` e `CDocTemplate::RemoveDocument` fornecem funções de membro virtual para a adição ou remoção de um documento do modelo. `CDocTemplate` é um amigo `CDocument` portanto, podemos definir protegido `CDocument::m_pDocTemplate` ponteiro para voltar para apontar de volta para o modelo de documento que criou o documento.

`CWinApp` lida com o padrão `OnFileOpen` implementação, que por sua vez consultará todos os modelos de documento. A implementação inclui a procura de documentos já está abertos e decidir qual formato para abrir novos documentos no.

`CDocTemplate` gerencia a associação de interface do usuário para documentos e quadros.

`CDocTemplate` mantém uma contagem do número de documentos sem nome.

## <a name="cdocument"></a>CDocument

Um `CDocument` pertencente a um `CDocTemplate`.

Documentos têm uma lista de abertos em modos de exibição (derivado de `CView`) que está exibindo o documento (um `CPtrList`).

Documentos não criar/destruir os modos de exibição, mas eles estão conectados uns aos outros depois que eles são criados. Quando um documento é fechado (isto é, por meio das arquivo/de fechamento), todos os modos de exibição anexados serão fechados. O documento será fechado quando a última exibição em um documento é fechada (ou seja, janela/de fechamento).

O `CDocument::AddView`, `RemoveView` interface é usada para manter a lista de exibição. `CDocument` é um amigo `CView` portanto, podemos definir o `CView::m_pDocument` ponteiro para voltar.

## <a name="cframewnd"></a>CFrameWnd

Um `CFrameWnd` (também conhecido como um quadro) desempenha a mesma função como no MFC 1.0, mas agora o `CFrameWnd` classe é projetada para ser usado em muitos casos, sem derivar uma nova classe. As classes derivadas `CMDIFrameWnd` e `CMDIChildWnd` também foram aprimorados para que muitos comandos padrão já sejam implementados.

O `CFrameWnd` é responsável por criar janelas na área de cliente do quadro. Normalmente, há uma janela principal, preenchendo a área de cliente do quadro.

Para uma janela de quadro MDI, a área de cliente é preenchida com o controle MDICLIENT que por sua vez é o pai de todas as janelas de quadro MDI filho. Para uma janela de quadro SDI ou uma janela do quadro filho MDI, a área de cliente geralmente é preenchida com um `CView`-derivados do objeto de janela. No caso de `CSplitterWnd`, a área de cliente do modo de exibição é preenchida com o `CSplitterWnd` objeto de janela e o `CView`-objetos de janela derivadas (um por painel de divisão) são criados como janelas filho do `CSplitterWnd`.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
