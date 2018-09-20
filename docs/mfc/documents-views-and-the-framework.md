---
title: Documentos, exibições e estrutura | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- document templates [MFC], template objects
- applications [MFC]
- MFC, application framework
- application objects [MFC], relation to other MFC objects
- documents [MFC]
- MFC, documents
- document objects [MFC], in relation to other MFC objects
- view objects [MFC], relation to other MFC objects
- MFC, views
- document/view architecture [MFC], about document/view architecture
- objects [MFC], MFC applications
- MFC object relationships
- thread objects [MFC]
ms.assetid: 409ddd9b-66ad-4625-84f7-bf55a41d697b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8213ac8d45b2981a7b945fb0af0a590cf7974a8a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402350"
---
# <a name="documents-views-and-the-framework"></a>Documentos, exibições e o Framework

A essência da estrutura MFC são os conceitos de documento e exibição. Um documento é um objeto de dados com o qual o usuário interage em uma sessão de edição. Ela é criada pelo **New** ou **abra** comando o **arquivo** menu e normalmente é salvo em um arquivo. (Os documentos padrão do MFC, derivados da classe `CDocument`, são diferentes de documentos ativos e documentos compostos OLE.) Um modo de exibição é um objeto de janela por meio do qual o usuário interage com um documento.

Os objetos de chave em um aplicativo em execução são:

- O documento ou documentos.

     Sua classe de documento (derivado de [CDocument](../mfc/reference/cdocument-class.md)) especifica os dados do aplicativo.

     Se você quiser a funcionalidade OLE em seu aplicativo, derive sua classe de documento da [COleDocument](../mfc/reference/coledocument-class.md) ou uma de suas classes derivadas, dependendo do tipo de funcionalidade que você precisa.

- O modo de exibição ou modos de exibição.

     Sua classe de exibição (derivado de [CView](../mfc/reference/cview-class.md)) é "janela nos dados" do usuário. A classe de exibição controla como o usuário vê os dados do seu documento e interage com ele. Em alguns casos, convém ter vários modos de exibição dos dados de um documento.

     Se você precisar de rolagem, derivam [CScrollView](../mfc/reference/cscrollview-class.md). Se o modo de exibição tem uma interface de usuário que está disposta em um recurso de modelo de caixa de diálogo, derivam [CFormView](../mfc/reference/cformview-class.md). Para dados de texto simples, usar ou derivar [CEditView](../mfc/reference/ceditview-class.md). Para um aplicativo de acesso a dados baseado em formulário, como um programa de entrada de dados, derivam [CRecordView](../mfc/reference/crecordview-class.md) (para ODBC). Também estão disponíveis as classes [CTreeView](../mfc/reference/ctreeview-class.md), [CListView](../mfc/reference/clistview-class.md), e [CRichEditView](../mfc/reference/cricheditview-class.md).

- As janelas de quadro

     Modos de exibição são exibidos dentro de "janelas de quadro do documento". Em um aplicativo SDI, a janela de quadro do documento também é a "janela de quadro principal" para o aplicativo. Em um aplicativo MDI, janelas de documentos são janelas filho exibidas dentro de uma janela de quadro principal. Sua classe de janela de quadro principal derivada Especifica os estilos e outras características das janelas de quadro que contêm seus modos de exibição. Se você precisar personalizar janelas de quadro, derivam [CFrameWnd](../mfc/reference/cframewnd-class.md) para personalizar a janela do quadro do documento para aplicativos SDI. Derivam [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) para personalizar a janela do quadro principal para aplicativos MDI. Também derive uma classe de [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) para personalizar cada tipo distinto de janelas de quadro de documento MDI que dá suporte a seu aplicativo.

- O modelo de documento ou modelos

     Um modelo de documento orquestra a criação de documentos, exibições e janelas de quadro. Uma classe de modelo de documento específico, derivado da classe [CDocTemplate](../mfc/reference/cdoctemplate-class.md), cria e gerencia todos os documentos abertos de um tipo. Aplicativos que dão suporte a mais de um tipo de documento tem vários modelos de documento. Use a classe [CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md) para aplicativos SDI ou classe de uso [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md) para aplicativos MDI.

- O objeto de aplicativo

     Sua classe de aplicativo (derivado de [CWinApp](../mfc/reference/cwinapp-class.md)) controla todos os objetos acima e especifica o comportamento do aplicativo, como inicialização e limpeza. Uma caixa de diálogo e o único aplicativo objeto cria e gerencia os modelos de documento para a aplicativo dá suporte a tipos de qualquer documento.

- Objetos de thread

     Se seu aplicativo cria threads separados de execução — por exemplo, para executar cálculos em segundo plano — você vai usar classes derivadas [CWinThread](../mfc/reference/cwinthread-class.md). [CWinApp](../mfc/reference/cwinapp-class.md) propriamente dito é derivado de `CWinThread` e representa o thread principal de execução (ou o processo principal) em seu aplicativo. Você também pode usar MFC em threads secundários.

Em um aplicativo em execução, esses objetos cooperativamente respondem às ações do usuário, agrupadas por comandos e outras mensagens. Um objeto de aplicativo único gerencia um ou mais modelos de documento. Cada modelo de documento cria e gerencia um ou mais documentos (dependendo do tipo de aplicativo SDI ou MDI). O usuário exibe e manipula um documento por meio de um modo de exibição contido dentro de uma janela do quadro. A figura a seguir mostra as relações entre esses objetos para um aplicativo SDI.

![Objetos em um aplicativo em execução de SDI](../mfc/media/vc386v1.gif "vc386v1") objetos em um aplicativo de SDI em execução

O restante desta família de artigos explica como as ferramentas do framework, o Assistente de aplicativo do MFC e os editores de recursos, criam esses objetos, como eles funcionam juntos e como usá-los em sua programação. Documentos, exibições e janelas com moldura são discutidas mais detalhadamente [objetos Window](../mfc/window-objects.md) e [arquitetura de documento/exibição](../mfc/document-view-architecture.md).

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
