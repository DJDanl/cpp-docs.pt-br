---
title: Documentos, exibições e a estrutura de biblioteca do Microsoft Foundation Class (MFC)
description: Uma descrição de documentos e exibições na biblioteca do Microsoft Foundation Class (MFC).
ms.date: 09/25/2020
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
ms.openlocfilehash: 41e145224e512b95d8674109f6ed3dcee39fffb1
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414094"
---
# <a name="documents-views-and-the-framework"></a>Documentos, exibições e estrutura

No coração da estrutura do MFC estão os conceitos de Document e View. Um documento é um objeto de dados com o qual o usuário interage em uma sessão de edição. Ele é criado pelo comando **novo** ou **abrir** no menu **arquivo** e, em geral, é salvo em um arquivo. (Os documentos padrão do MFC, derivados da classe `CDocument` , são diferentes dos documentos ativos e dos documentos compostos OLE.) Uma exibição é um objeto de janela por meio do qual o usuário interage com um documento.

Os principais objetos em um aplicativo em execução são:

- Objetos de thread

   Se seu aplicativo cria threads separados de execução — por exemplo, para fazer cálculos em segundo plano — você usará classes derivadas de [`CWinThread`](reference/cwinthread-class.md) . [`CWinApp`](reference/cwinapp-class.md) Ele é derivado de `CWinThread` e representa o thread principal de execução (ou o processo principal) em seu aplicativo. Você também pode usar o MFC em threads secundários.

- O objeto Application

   A classe de aplicativo (derivada de [`CWinApp`](reference/cwinapp-class.md) ) controla todos os objetos acima e especifica o comportamento do aplicativo, como inicialização e limpeza. O único objeto do aplicativo cria e gerencia os modelos de documento para qualquer tipo de documento ao qual o aplicativo dá suporte.

- O modelo ou modelos de documento

   Um modelo de documento orquestra a criação de documentos, exibições e janelas de quadros. Uma classe de modelo de documento específica, derivada da classe [`CDocTemplate`](reference/cdoctemplate-class.md) , cria e gerencia todos os documentos abertos de um tipo. Os aplicativos que dão suporte a mais de um tipo de documento têm vários modelos de documento. Use a classe [CSingleDocTemplate](reference/csingledoctemplate-class.md) para aplicativos SDI ou use [`CMultiDocTemplate`](reference/cmultidoctemplate-class.md) a classe para aplicativos MDI.

- As janelas de quadros

   As exibições são exibidas dentro de "janelas de quadro do documento". Em um aplicativo SDI, a janela do quadro do documento também é a "janela principal do quadro" para o aplicativo. Em um aplicativo MDI, as janelas de documentos são janelas filhas exibidas dentro de uma janela de quadro principal. Sua classe de janela de quadro principal derivada especifica os estilos e outras características das janelas de quadros que contêm suas exibições. Se você precisar personalizar janelas de quadros, derive de [`CFrameWnd`](reference/cframewnd-class.md) para personalizar a janela de quadro do documento para aplicativos SDI. Derive de [`CMDIFrameWnd`](reference/cmdiframewnd-class.md) para personalizar a janela principal do quadro para aplicativos MDI. Além disso, derive uma classe de [`CMDIChildWnd`](reference/cmdichildwnd-class.md) para personalizar cada tipo distinto de janelas de quadro de documento MDI que seu aplicativo suporta.

- O documento ou documentos.

   Sua classe de documento (derivada de [`CDocument`](reference/cdocument-class.md) ) especifica os dados do seu aplicativo.

   Se você quiser a funcionalidade OLE em seu aplicativo, derive sua classe de documento de [`COleDocument`](reference/coledocument-class.md) ou de uma de suas classes derivadas, dependendo do tipo de funcionalidade de que você precisa.

- Exibição ou exibições.

   Sua classe de exibição (derivada de [`CView`](reference/cview-class.md) ) é a janela "do usuário nos dados". A classe View controla como o usuário vê os dados do seu documento e interage com ele. Em alguns casos, talvez você queira que um documento tenha várias exibições dos dados.

   Se você precisar de rolagem, derive de [`CScrollView`](reference/cscrollview-class.md) . Se sua exibição tiver uma interface do usuário que é disposta em um recurso de modelo de caixa de diálogo, derive de [`CFormView`](reference/cformview-class.md) . Para dados de texto simples, use ou derive de [`CEditView`](reference/ceditview-class.md) . Para um aplicativo de acesso a dados baseado em formulário, como um programa de entrada de dados, derive de [`CRecordView`](reference/crecordview-class.md) (para ODBC). Também estão disponíveis classes [`CTreeView`](reference/ctreeview-class.md) , [`CListView`](reference/clistview-class.md) e [`CRichEditView`](reference/cricheditview-class.md) .

Em um aplicativo em execução, esses objetos respondem cooperaamente às ações do usuário, ligadas por comandos e outras mensagens. Um único objeto de aplicativo gerencia um ou mais modelos de documento. Cada modelo de documento cria e gerencia um ou mais documentos (dependendo se o aplicativo é SDI ou MDI). O usuário exibe e manipula um documento por meio de uma exibição contida dentro de uma janela de quadro. A figura a seguir mostra as relações entre esses objetos para um aplicativo SDI.

![Objetos em um aplicativo SDI em execução](../mfc/media/vc386v1.gif "Objetos em um aplicativo SDI em execução")\
Objetos em um aplicativo SDI em execução

O restante desta família de artigos explica como as ferramentas de estrutura, o assistente de aplicativo MFC e os editores de recursos, criam esses objetos, como eles funcionam juntos e como usá-los em sua programação. Documentos, modos de exibição e janelas de quadro são discutidos em mais detalhes em [objetos de janela](window-objects.md) e [arquitetura de documento/exibição](document-view-architecture.md).

## <a name="see-also"></a>Confira também

[Usando as classes para gravar aplicativos para Windows](using-the-classes-to-write-applications-for-windows.md)
