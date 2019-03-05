---
title: Alternativas à arquitetura de exibição de documento
ms.date: 11/04/2016
helpviewer_keywords:
- documents [MFC], applications without
- CDocument class [MFC], space requirements
- views [MFC], applications without
ms.assetid: 2c22f352-a137-45ce-9971-c142173496fb
ms.openlocfilehash: 98bb4de2f6d1a43fc1958a0fcbaafa1ac0af82a3
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57282546"
---
# <a name="alternatives-to-the-documentview-architecture"></a>Alternativas à arquitetura de documento/exibição

Aplicativos MFC normalmente usam a arquitetura de documento/exibição para gerenciar informações, formatos de arquivo e a representação visual dos dados para os usuários. Para a maioria dos aplicativos da área de trabalho, a arquitetura de documento/exibição é uma arquitetura de aplicativo apropriado e eficiente. Essa arquitetura separa os dados contra a exibição e, na maioria dos casos, simplifica o seu aplicativo e reduz o código redundante.

No entanto, a arquitetura de documento/exibição não é adequada para algumas situações. Considere estes exemplos:

- Se você estiver portando um aplicativo escrito em C para Windows, você talvez queira concluir sua porta antes de adicionar suporte de documento/exibição ao seu aplicativo.

- Se você estiver escrevendo um utilitário leve, você pode achar que você pode fazer sem a arquitetura de documento/exibição.

- Se seu código original já misturar o gerenciamento de dados com dados exibindo, movendo o código para o modelo de documento/exibição não é que vale a pena o esforço porque você deve separar os dois. Talvez você prefira deixar o código como está.

Para criar um aplicativo que não usa a arquitetura de documento/exibição, desmarque a **suporte de arquitetura de documento/exibição** caixa de seleção na etapa 1 do Assistente de aplicativo MFC. Ver [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) para obter detalhes.

> [!NOTE]
>  Os aplicativos baseado em diálogo produzidos pelo Assistente de aplicativo MFC não usam a arquitetura de documento/exibição, portanto, o **suporte de arquitetura de documento/exibição** caixa de seleção estará desabilitada se você selecionar o tipo de aplicativo de caixa de diálogo.

Os assistentes do Visual C++, bem como os editores de código-fonte e a caixa de diálogo, trabalhar com o aplicativo gerado como fariam com qualquer outro aplicativo gerado pelo assistente. O aplicativo pode dar suporte a barras de ferramentas, barras de rolagem e uma barra de status e tem um **sobre** caixa. Seu aplicativo não registrará os modelos de documento e ele não conterá uma classe de documento.

Observe que o aplicativo gerado tem uma classe de exibição `CChildView`, derivado do `CWnd`. MFC cria e posiciona uma instância da classe de exibição dentro de janelas com moldura criadas pelo seu aplicativo. MFC reforça ainda usando uma janela de exibição, porque ele simplifica o posicionamento e gerenciamento de conteúdo do aplicativo. Você pode adicionar código de pintura para o `OnPaint` membro dessa classe. Seu código deve adicionar barras de rolagem para o modo de exibição em vez de quadro.

Como a arquitetura de documento/exibição fornecida pelo MFC é responsável por implementar muitos dos recursos básicos de um aplicativo, sua ausência em seu projeto significa que você é responsável por implementar vários recursos importantes do seu aplicativo:

- Conforme fornecido pelo Assistente de aplicativo MFC, o menu do seu aplicativo contém apenas **New** e **sair** os comandos no **arquivo** menu. (O **New** comando tem suporte apenas para aplicativos MDI, não os aplicativos SDI sem a exibição de documentos de suporte.) O recurso de menu gerado não dará suporte a uma lista MRU (recentemente usado).

- Você deve adicionar funções do manipulador e implementações de todos os comandos que seu aplicativo dará suporte, incluindo **aberto** e **salvar** sobre o **arquivo** menu. Normalmente, o MFC fornece código para dar suporte a esses recursos, mas esse suporte está estreitamente ligado à arquitetura de documento/exibição.

- A barra de ferramentas para seu aplicativo, se você tiver solicitado um, será mínima.

É altamente recomendável usar o Assistente de aplicativo MFC para criar aplicativos sem a arquitetura de documento/exibição, porque o assistente garante uma arquitetura correta do MFC. No entanto, se você deve evitar usar o assistente, aqui estão várias abordagens para ignorar a arquitetura de documento/exibição em seu código:

- Tratar o documento como um sufixo não utilizado e implementar seu código de gerenciamento de dados na classe de exibição, conforme sugerido acima. Sobrecarga para o documento é relativamente baixa. Uma única [CDocument](../mfc/reference/cdocument-class.md) objeto resulta em uma pequena quantidade de sobrecarga por si só, além da pequena sobrecarga `CDocument`da base de classes, [CCmdTarget](../mfc/reference/ccmdtarget-class.md) e [CObject](../mfc/reference/cobject-class.md). Ambas as classes de segundos são pequenas.

   Declarado em `CDocument`:

  - Dois `CString` objetos.

  - Três **BOOL**s.

  - Um `CDocTemplate` ponteiro.

  - Um `CPtrList` objeto, que contém uma lista de modos de exibição do documento.

  Além disso, o documento requer o período de tempo para criar o objeto de documento, seus objetos de exibição, uma janela de quadro e um objeto de modelo de documento.

- Trate o documento e o modo de exibição como colossais não utilizados. Coloque seu código de desenho e o gerenciamento de dados na janela do quadro em vez do modo de exibição. Essa abordagem é mais próxima ao modelo de programação da linguagem C.

- Substitua as partes da estrutura MFC que criar o documento e o modo de exibição para eliminar a criá-los em todos os. O processo de criação de documento começa com uma chamada para `CWinApp::AddDocTemplate`. Eliminar essa chamada de sua classe de aplicativo `InitInstance` membro de função e, em vez disso, criar uma janela do quadro no `InitInstance` por conta própria. Coloque o código de gerenciamento de dados em sua classe de janela do quadro. O processo de criação de documento/exibição é ilustrado na [criação de documento/exibição](../mfc/document-view-creation.md). Isso é mais trabalhoso e requer uma compreensão mais profunda do framework, mas libera você inteiramente da sobrecarga de documento/exibição.

O artigo [MFC: Usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md) dá exemplos mais concretos de alternativas de documento/exibição no contexto de aplicativos de banco de dados.

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
