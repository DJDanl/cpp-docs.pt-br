---
title: "Alternativas à arquitetura de modo de exibição de documentos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- documents [MFC], applications without
- CDocument class [MFC], space requirements
- views [MFC], applications without
ms.assetid: 2c22f352-a137-45ce-9971-c142173496fb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 459383474c9ffed9a7ad6cefe01ea21626cb23b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="alternatives-to-the-documentview-architecture"></a>Alternativas à arquitetura de documento/exibição
Aplicativos MFC normalmente usam a arquitetura de documento/exibição para gerenciar informações, formatos de arquivo e a representação visual dos dados para os usuários. Para a maioria dos aplicativos de área de trabalho, a arquitetura de documento/exibição é uma arquitetura de aplicativos apropriado e eficiente. Essa arquitetura separa os dados da exibição e, na maioria dos casos, simplifica o seu aplicativo e reduz o código redundante.  
  
 No entanto, a arquitetura de documento/exibição não é apropriada para algumas situações. Considere estes exemplos:  
  
-   Se você estiver portando um aplicativo escrito em C para Windows, você talvez queira concluir sua porta antes de adicionar suporte de documento/exibição para seu aplicativo.  
  
-   Se você estiver escrevendo um utilitário leve, você pode achar que você pode fazer sem a arquitetura de documento/exibição.  
  
-   Se seu código original já combina o gerenciamento de dados com dados exibindo, movendo o código para o modelo de documento/exibição não é a pena porque você deve separar os dois. Talvez você prefira deixar o código como está.  
  
 Para criar um aplicativo que não usam a arquitetura de documento/exibição, desmarque o **suporte para a arquitetura de documento/exibição** caixa de seleção na etapa 1 do Assistente de aplicativo MFC. Consulte [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) para obter detalhes.  
  
> [!NOTE]
>  Aplicativos baseados na caixa de diálogo produzidos pelo Assistente de aplicativo MFC não usam a arquitetura de documento/exibição, portanto, o **suporte para a arquitetura de documento/exibição** caixa de seleção será desabilitada se você selecionar o tipo de aplicativo de caixa de diálogo.  
  
 Os assistentes do Visual C++, bem como os editores de origem e a caixa de diálogo, trabalhar com o aplicativo gerado como faria com qualquer outro aplicativo gerados pelo assistente. O aplicativo pode dar suporte a barras de ferramentas, barras de rolagem e uma barra de status e tem um **sobre** caixa. Seu aplicativo não registrará os modelos de documento, e ele não conterá uma classe de documento.  
  
 Observe que o aplicativo gerado tem uma classe de exibição, **CChildView**, derivada de `CWnd`. MFC cria e coloca uma instância da classe de exibição dentro de janelas com moldura criadas pelo seu aplicativo. MFC ainda impõe usando uma janela de exibição, pois isso simplifica o posicionamento e gerenciamento de conteúdo do aplicativo. Você pode adicionar código de pintura para o `OnPaint` membro dessa classe. Seu código deve adicionar barras de rolagem no modo de exibição em vez de quadro.  
  
 Como a arquitetura de documento/exibição fornecida pelo MFC é responsável por implementar muitos dos recursos básicos de um aplicativo, sua ausência em seu projeto significa que você é responsável por implementar vários recursos importantes do seu aplicativo:  
  
-   Conforme fornecido pelo Assistente de aplicativo MFC, o menu de seu aplicativo contém apenas `New` e `Exit` comandos no **arquivo** menu. (O `New` comando só tem suporte para aplicativos MDI, suportam de não aplicativos SDI sem a exibição de documentos.) O recurso de menu gerado não dará suporte a uma lista MRU (usado mais recentemente).  
  
-   Você deve adicionar funções do manipulador e implementações para os comandos que seu aplicativo dará suporte, incluindo **abrir** e **salvar** no **arquivo** menu. MFC normalmente fornece código para oferecer suporte a esses recursos, mas esse suporte está estreitamente ligado à arquitetura de documento/exibição.  
  
-   A barra de ferramentas para o seu aplicativo, se solicitado, será mínima.  
  
 É altamente recomendável que você use o Assistente de aplicativo MFC para criar aplicativos sem a arquitetura de documento/exibição, porque o assistente garante uma arquitetura correta do MFC. No entanto, se você deve evitar usar o assistente, aqui estão várias abordagens para ignorar a arquitetura de documento/exibição no seu código:  
  
-   Tratar o documento como um sufixo não utilizado e implementar o código de gerenciamento de dados da classe de exibição, conforme sugerido acima. Sobrecarga para o documento é relativamente baixa. Um único [CDocument](../mfc/reference/cdocument-class.md) objeto incorre em uma pequena quantidade de sobrecarga por si só, além de pequena sobrecarga de **CDocument**da base de classes, [CCmdTarget](../mfc/reference/ccmdtarget-class.md) e [ CObject](../mfc/reference/cobject-class.md). Ambas as classes de segunda são pequenas.  
  
     Declarado em **CDocument**:  
  
    -   Dois `CString` objetos.  
  
    -   Três **BOOL**s.  
  
    -   Um `CDocTemplate` ponteiro.  
  
    -   Um `CPtrList` objeto, que contém uma lista de modos de exibição do documento.  
  
     Além disso, o documento requer a quantidade de tempo para criar o objeto de documento e um objeto de modelo de documento, uma janela do quadro e seus objetos de exibição.  
  
-   Trate o documento e o modo de exibição como suplementos não utilizados. Coloque o gerenciamento de dados e o código de desenho na janela do quadro, em vez do modo de exibição. Essa abordagem é mais próxima ao modelo de programação da linguagem C.  
  
-   Substitua as partes do framework MFC que cria o documento e o modo de exibição para eliminar criá-los em todos os. O processo de criação de documento começa com uma chamada para `CWinApp::AddDocTemplate`. Eliminar a chamada de sua classe de aplicativo `InitInstance` membro de função e, em vez disso, crie uma janela do quadro no `InitInstance` por conta própria. Coloque o código de gerenciamento de dados em sua classe de janela do quadro. O processo de criação de documento/exibição é ilustrado no [criação de documento/exibição](../mfc/document-view-creation.md). Isso é mais trabalho e requer uma compreensão mais profunda do framework, mas ele libera você inteiramente da sobrecarga de documento/exibição.  
  
 O artigo [MFC: usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md) fornece exemplos mais concretos de alternativas de documento/exibição no contexto de aplicativos de banco de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

