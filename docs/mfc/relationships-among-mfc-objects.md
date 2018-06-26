---
title: Relações entre objetos MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, relationships between key objects
- objects [MFC], relationships
- relationships, MFC objects
- MFC object relationships
ms.assetid: 6e8f3b51-e80f-4d88-94c8-4c1e4ee163ad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef6a9e605948fac4f31338f87b4d00bbaa8712f4
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931646"
---
# <a name="relationships-among-mfc-objects"></a>Relacionamentos entre objetos MFC
Para ajudar a colocar o processo de criação de documento/exibição em perspectiva, considere a possibilidade de um programa em execução: um documento, a janela do quadro usado para conter o modo de exibição e o modo de exibição associada ao documento.  
  
-   Um documento mantém uma lista dos modos de exibição de documento e um ponteiro para o modelo de documento que criou o documento.  
  
-   Um modo de exibição mantém um ponteiro para o documento e é um filho de sua janela pai do quadro.  
  
-   Uma janela do quadro de documento mantém um ponteiro para o modo de exibição ativo atual.  
  
-   Um modelo de documento mantém uma lista de seus documentos abertos.  
  
-   O aplicativo mantém uma lista de seus modelos de documento.  
  
-   Windows mantém o controle de todas as janelas abertas para enviar mensagens a elas.  
  
 Essas relações são estabelecidas durante a criação da exibição de documentos. A tabela a seguir mostra como os objetos em um programa em execução podem acessar outros objetos. Qualquer objeto pode obter um ponteiro para o objeto de aplicativo, chamando a função global [AfxGetApp](../mfc/reference/application-information-and-management.md#afxgetapp).  
  
### <a name="gaining-access-to-other-objects-in-your-application"></a>Obtendo acesso a outros objetos no seu aplicativo  
  
|Do objeto|Como outros objetos de acesso|  
|-----------------|---------------------------------|  
|Documento|Use [GetFirstViewPosition](../mfc/reference/cdocument-class.md#getfirstviewposition) e [GetNextView](../mfc/reference/cdocument-class.md#getnextview) para acessar a lista de exibição do documento.<br /><br /> Chamar [GetDocTemplate](../mfc/reference/cdocument-class.md#getdoctemplate) para obter o modelo de documento.|  
|Exibir|Chamar [GetDocument](../mfc/reference/cview-class.md#getdocument) para obter o documento.<br /><br /> Chamar [GetParentFrame](../mfc/reference/cwnd-class.md#getparentframe) para obter a janela do quadro.|  
|Janela de quadro do documento|Chamar [GetActiveView](../mfc/reference/cframewnd-class.md#getactiveview) para obter o modo de exibição atual.<br /><br /> Chamar [GetActiveDocument](../mfc/reference/cframewnd-class.md#getactivedocument) para obter o documento anexado ao modo de exibição atual.|  
|Janela de quadro MDI|Chamar [MDIGetActive](../mfc/reference/cmdiframewnd-class.md#mdigetactive) para obter um ativo no momento [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).|  
  
 Normalmente, uma janela do quadro tem um modo de exibição, mas às vezes, como em janelas separadoras, a mesma janela do quadro contém vários modos de exibição. A janela do quadro mantém um ponteiro para a exibição ativa no momento; o ponteiro é atualizado sempre que outro modo de exibição é ativado.  
  
> [!NOTE]
>  Um ponteiro para a janela do quadro principal é armazenado no [m_pMainWnd](../mfc/reference/cwinthread-class.md#m_pmainwnd) variável de membro de objeto do aplicativo. Uma chamada para `OnFileNew` em sua substituição do `InitInstance` função membro de `CWinApp` define *m_pMainWnd* para você. Se você não chama `OnFileNew`, você deve definir o valor da variável no `InitInstance` por conta própria. (COM SDI (servidor) de componente aplicativos podem não definir a variável se a opção /Embedding na linha de comando.) Observe que *m_pMainWnd* agora é um membro da classe `CWinThread` em vez de `CWinApp`.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação do modelo de documento](../mfc/document-template-creation.md)   
 [Criação de documento/exibição](../mfc/document-view-creation.md)   
 [Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

