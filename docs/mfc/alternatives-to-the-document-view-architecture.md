---
title: Alternativas para a arquitetura de exibição de documento
ms.date: 11/04/2016
helpviewer_keywords:
- documents [MFC], applications without
- CDocument class [MFC], space requirements
- views [MFC], applications without
ms.assetid: 2c22f352-a137-45ce-9971-c142173496fb
ms.openlocfilehash: 66325d1ae087b29f59f37197fb8695504bbddbc6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619751"
---
# <a name="alternatives-to-the-documentview-architecture"></a>Alternativas à arquitetura de documento/exibição

Aplicativos MFC normalmente usam a arquitetura de documento/exibição para gerenciar informações, formatos de arquivo e a representação visual de dados para os usuários. Para a maioria dos aplicativos de área de trabalho, a arquitetura de documento/exibição é uma arquitetura de aplicativo adequada e eficiente. Essa arquitetura separa os dados da exibição e, na maioria dos casos, simplifica seu aplicativo e reduz o código redundante.

No entanto, a arquitetura de documento/exibição não é apropriada para algumas situações. Considere estes exemplos:

- Se você estiver portando um aplicativo escrito em C para Windows, talvez queira concluir sua porta antes de adicionar suporte a documento/exibição ao seu aplicativo.

- Se você estiver escrevendo um utilitário leve, poderá achar que pode fazer isso sem a arquitetura de documento/exibição.

- Se o código original já combina o gerenciamento de dados com a exibição de dados, mover o código para o modelo de documento/exibição não vale o esforço, pois você deve separar os dois. Talvez você prefira deixar o código como está.

Para criar um aplicativo que não usa a arquitetura de documento/exibição, desmarque a caixa de seleção de **suporte de arquitetura de documento/exibição** na etapa 1 do assistente de aplicativo do MFC. Consulte [Assistente de aplicativo do MFC](reference/mfc-application-wizard.md) para obter detalhes.

> [!NOTE]
> Aplicativos baseados em caixas de diálogo produzidos pelo assistente de aplicativo MFC não usam a arquitetura de documento/exibição, portanto, a caixa de seleção **suporte para arquitetura de documento/exibição** será desabilitada se você selecionar o tipo de aplicativo de caixa de diálogo.

Os assistentes de Visual C++, bem como os editores de origem e de caixa de diálogo, trabalham com o aplicativo gerado exatamente como fariam com qualquer outro aplicativo gerado pelo assistente. O aplicativo pode dar suporte a barras de ferramentas, barras de rolagem e uma barra de status e tem uma caixa **sobre** . Seu aplicativo não registrará nenhum modelo de documento e não conterá uma classe de documento.

Observe que o aplicativo gerado tem uma classe de exibição, `CChildView` , derivada de `CWnd` . O MFC cria e posiciona uma instância da classe View dentro das janelas de quadros criadas pelo seu aplicativo. O MFC ainda impõe o uso de uma janela de exibição, pois simplifica o posicionamento e o gerenciamento do conteúdo do aplicativo. Você pode adicionar o código de pintura ao `OnPaint` membro desta classe. Seu código deve adicionar barras de rolagem à exibição em vez de ao quadro.

Como a arquitetura de documento/exibição fornecida pelo MFC é responsável por implementar muitos dos recursos básicos de um aplicativo, sua ausência no projeto significa que você é responsável por implementar muitos recursos importantes do seu aplicativo:

- Conforme fornecido pelo assistente de aplicativo MFC, o menu do seu aplicativo contém apenas comandos **novo** e **sair** no menu **arquivo** . (O **novo** comando tem suporte apenas para aplicativos MDI, não para aplicativos SDI sem suporte de documento/exibição.) O recurso de menu gerado não dará suporte a uma lista MRU (usada mais recentemente).

- Você deve adicionar funções de manipulador e implementações para quaisquer comandos aos quais seu aplicativo oferecerá suporte, incluindo **abrir** e **salvar** no menu **arquivo** . O MFC normalmente fornece código para dar suporte a esses recursos, mas esse suporte está intimamente ligado à arquitetura de documento/exibição.

- A barra de ferramentas do seu aplicativo, se você tiver solicitado um, será mínima.

É altamente recomendável que você use o assistente de aplicativo do MFC para criar aplicativos sem a arquitetura de documento/exibição, pois o assistente garante uma arquitetura do MFC correta. No entanto, se você precisar evitar o uso do assistente, aqui estão várias abordagens para ignorar a arquitetura de documento/exibição em seu código:

- Trate o documento como um appendage não utilizado e implemente seu código de gerenciamento de dados na classe View, conforme sugerido acima. A sobrecarga para o documento é relativamente baixa. Um único objeto [CDocument](reference/cdocument-class.md) incorre em uma pequena quantidade de sobrecarga por si só, além da pequena sobrecarga das `CDocument` classes base, [CCmdTarget](reference/ccmdtarget-class.md) e [CObject](reference/cobject-class.md). Ambas as últimas classes são pequenas.

   Declarado em `CDocument` :

  - Dois `CString` objetos.

  - Três **bool**s.

  - Um `CDocTemplate` ponteiro.

  - Um `CPtrList` objeto, que contém uma lista de exibições do documento.

  Além disso, o documento requer a quantidade de tempo para criar o objeto de documento, seus objetos de exibição, uma janela de quadro e um objeto de modelo de documento.

- Trate o documento e a exibição como colossais não utilizados. Coloque o gerenciamento de dados e o código de desenho na janela do quadro, e não no modo de exibição. Essa abordagem é mais próxima do modelo de programação C-Language.

- Substitua as partes da estrutura MFC que criam o documento e a exibição para eliminar a criação deles. O processo de criação do documento começa com uma chamada para `CWinApp::AddDocTemplate` . Elimine a chamada da função de membro da classe de aplicativo `InitInstance` e, em vez disso, crie uma janela de quadro por `InitInstance` conta própria. Coloque seu código de gerenciamento de dados em sua classe de janela do quadro. O processo de criação de documento/exibição é ilustrado em [criação de documento/exibição](document-view-creation.md). Isso é mais trabalhoso e requer uma compreensão mais profunda da estrutura, mas libera inteiramente da sobrecarga de documento/exibição.

O artigo [MFC: usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md) fornece mais exemplos concretos de alternativas de documentos/exibições no contexto de aplicativos de banco de dados.

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
