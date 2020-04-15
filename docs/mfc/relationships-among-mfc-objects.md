---
title: Relacionamentos entre objetos MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, relationships between key objects
- objects [MFC], relationships
- relationships, MFC objects
- MFC object relationships
ms.assetid: 6e8f3b51-e80f-4d88-94c8-4c1e4ee163ad
ms.openlocfilehash: d7e40e25b405d3f8ec50a518889cc2b89bc8c725
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372806"
---
# <a name="relationships-among-mfc-objects"></a>Relacionamentos entre objetos MFC

Para ajudar a colocar o processo de criação de documentos/visualização em perspectiva, considere um programa em execução: um documento, a janela de quadro usada para conter a exibição e a exibição associada ao documento.

- Um documento mantém uma lista das visualizações desse documento e um ponteiro para o modelo de documento que criou o documento.

- Uma visualização mantém um ponteiro em seu documento e é uma criança de sua janela de quadro dos pais.

- Uma janela de quadro de documento mantém um ponteiro para sua exibição ativa atual.

- Um modelo de documento mantém uma lista de seus documentos abertos.

- O aplicativo mantém uma lista de seus modelos de documentos.

- O Windows mantém o controle de todas as janelas abertas para que possa enviar mensagens para eles.

Essas relações são estabelecidas durante a criação de documentos/visualizações. A tabela a seguir mostra como objetos em um programa em execução podem acessar outros objetos. Qualquer objeto pode obter um ponteiro para o objeto do aplicativo chamando a função global [AfxGetApp](../mfc/reference/application-information-and-management.md#afxgetapp).

### <a name="gaining-access-to-other-objects-in-your-application"></a>Obtendo acesso a outros objetos em sua aplicação

|Do objeto|Como acessar outros objetos|
|-----------------|---------------------------------|
|Document|Use [GetFirstViewPosition](../mfc/reference/cdocument-class.md#getfirstviewposition) e [GetNextView](../mfc/reference/cdocument-class.md#getnextview) para acessar a lista de exibição do documento.<br /><br /> Ligue para [o GetDocTemplate](../mfc/reference/cdocument-class.md#getdoctemplate) para obter o modelo do documento.|
|Visualizar|Ligue para [o GetDocument](../mfc/reference/cview-class.md#getdocument) para obter o documento.<br /><br /> Ligue para [getParentFrame](../mfc/reference/cwnd-class.md#getparentframe) para obter a janela do quadro.|
|Janela do quadro do documento|Ligue para [o GetActiveView](../mfc/reference/cframewnd-class.md#getactiveview) para obter a visualização atual.<br /><br /> Ligue para [o GetActiveDocument](../mfc/reference/cframewnd-class.md#getactivedocument) para obter o documento anexado à exibição atual.|
|Janela do quadro MDI|Ligue para o [MDIGetActive](../mfc/reference/cmdiframewnd-class.md#mdigetactive) para obter o [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)atualmente ativo .|

Normalmente, uma janela de quadro tem uma visão, mas às vezes, como em janelas de divisor, a mesma janela de quadro contém várias visualizações. A janela de quadro mantém um ponteiro para a exibição ativa atualmente; o ponteiro é atualizado sempre que outra exibição é ativada.

> [!NOTE]
> Um ponteiro para a janela do quadro principal é armazenado na variável [membro m_pMainWnd](../mfc/reference/cwinthread-class.md#m_pmainwnd) do objeto de aplicação. Uma chamada `OnFileNew` para a sua `InitInstance` substituição `CWinApp` da função membro de conjuntos *m_pMainWnd* para você. Se você não `OnFileNew`ligar, você deve definir `InitInstance` o valor da variável em si mesmo. (Os aplicativos do componente SDI COM (servidor) podem não definir a variável se /Incorporação estiver na linha de comando.) Note que *m_pMainWnd* agora é `CWinThread` um `CWinApp`membro de classe em vez de .

## <a name="see-also"></a>Confira também

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](../mfc/document-template-creation.md)<br/>
[Criação de documento/exibição](../mfc/document-view-creation.md)<br/>
[Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)
