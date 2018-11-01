---
title: Relacionamentos entre objetos MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, relationships between key objects
- objects [MFC], relationships
- relationships, MFC objects
- MFC object relationships
ms.assetid: 6e8f3b51-e80f-4d88-94c8-4c1e4ee163ad
ms.openlocfilehash: c02cf723ee7711ec1bfe00841c90bbde8c260ac1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50585504"
---
# <a name="relationships-among-mfc-objects"></a>Relacionamentos entre objetos MFC

Para ajudar a colocar o processo de criação de documento/exibição em perspectiva, considere um programa em execução: um documento, a janela do quadro usado para conter o modo de exibição e o modo de exibição associado ao documento.

- Um documento mantém uma lista dos modos de exibição de documento e um ponteiro para o modelo de documento que criou o documento.

- Uma exibição mantém um ponteiro para o seu documento e é um filho de sua janela de quadro do pai.

- Uma janela de quadro do documento mantém um ponteiro para sua exibição ativa atual.

- Um modelo de documento mantém uma lista de seus documentos abertos.

- O aplicativo mantém uma lista de seus modelos de documento.

- Windows mantém o controle de todas as janelas abertas para que ele possa enviar mensagens a eles.

Essas relações são estabelecidas durante a criação de documento/exibição. A tabela a seguir mostra como os objetos em um programa em execução podem acessar outros objetos. Qualquer objeto pode obter um ponteiro para o objeto de aplicativo, chamando a função global [AfxGetApp](../mfc/reference/application-information-and-management.md#afxgetapp).

### <a name="gaining-access-to-other-objects-in-your-application"></a>Obtendo acesso a outros objetos em seu aplicativo

|Do objeto|Como acessar outros objetos|
|-----------------|---------------------------------|
|Documento|Use [GetFirstViewPosition](../mfc/reference/cdocument-class.md#getfirstviewposition) e [GetNextView](../mfc/reference/cdocument-class.md#getnextview) para acessar a lista de exibição do documento.<br /><br /> Chame [GetDocTemplate](../mfc/reference/cdocument-class.md#getdoctemplate) para obter o modelo de documento.|
|Exibir|Chame [GetDocument](../mfc/reference/cview-class.md#getdocument) para obter o documento.<br /><br /> Chame [GetParentFrame](../mfc/reference/cwnd-class.md#getparentframe) para obter a janela do quadro.|
|Janela de quadro do documento|Chame [GetActiveView](../mfc/reference/cframewnd-class.md#getactiveview) para obter a exibição atual.<br /><br /> Chame [GetActiveDocument](../mfc/reference/cframewnd-class.md#getactivedocument) para obter o documento anexado ao modo de exibição atual.|
|Janela de quadro MDI|Chame [MDIGetActive](../mfc/reference/cmdiframewnd-class.md#mdigetactive) para obter o ativo no momento [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).|

Normalmente, uma janela de quadro tem uma exibição, mas às vezes, como em janelas separadoras, a mesma janela do quadro contém vários modos de exibição. A janela do quadro mantém um ponteiro para a exibição ativa no momento; o ponteiro é atualizado sempre que outro modo de exibição é ativado.

> [!NOTE]
>  Um ponteiro para a janela do quadro principal é armazenado na [m_pMainWnd](../mfc/reference/cwinthread-class.md#m_pmainwnd) variável de membro do objeto de aplicativo. Uma chamada para `OnFileNew` em seu substituto do `InitInstance` função de membro `CWinApp` define *m_pMainWnd* para você. Se você não chamar `OnFileNew`, você deve definir o valor da variável no `InitInstance` por conta própria. (Aplicativos de componentes (servidor) de SDI COM podem não definir a variável se a opção /Embedding está na linha de comando.) Observe que *m_pMainWnd* agora é um membro da classe `CWinThread` em vez de `CWinApp`.

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](../mfc/document-template-creation.md)<br/>
[Criação de documento/exibição](../mfc/document-view-creation.md)<br/>
[Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

