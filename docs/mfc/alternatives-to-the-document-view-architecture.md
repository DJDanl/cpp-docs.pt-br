---
title: Alternativas à arquitetura de exibição de documentos
ms.date: 11/04/2016
helpviewer_keywords:
- documents [MFC], applications without
- CDocument class [MFC], space requirements
- views [MFC], applications without
ms.assetid: 2c22f352-a137-45ce-9971-c142173496fb
ms.openlocfilehash: 41af30d25d7ddb9e2bdbb7a0f7b86cb741ae1048
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370796"
---
# <a name="alternatives-to-the-documentview-architecture"></a>Alternativas à arquitetura de documento/exibição

Os aplicativos MFC normalmente usam a arquitetura de documento/exibição para gerenciar informações, formatos de arquivos e a representação visual de dados aos usuários. Para a maioria dos aplicativos de desktop, a arquitetura document/view é uma arquitetura de aplicativo apropriada e eficiente. Essa arquitetura separa os dados da visualização e, na maioria dos casos, simplifica seu aplicativo e reduz o código redundante.

No entanto, a arquitetura de documento/exibição não é apropriada para algumas situações. Considere estes exemplos:

- Se você estiver portando um aplicativo escrito em C para Windows, você pode querer concluir sua porta antes de adicionar suporte a documentos/exibição ao seu aplicativo.

- Se você estiver escrevendo um utilitário leve, você pode descobrir que você pode fazer sem a arquitetura de documento/exibição.

- Se o seu código original já mistura gerenciamento de dados com visualização de dados, mover o código para o modelo de documento/exibição não vale o esforço, porque você deve separar os dois. Você pode preferir deixar o código como está.

Para criar um aplicativo que não use a arquitetura documento/exibição, limpe a caixa de **seleção de suporte à arquitetura Document/View** na etapa 1 do Assistente de Aplicativo Do MFC. Consulte [o MFC Application Wizard](../mfc/reference/mfc-application-wizard.md) para obter detalhes.

> [!NOTE]
> Os aplicativos baseados em diálogo produzidos pelo MFC Application Wizard não usam a arquitetura documento/exibição, portanto, a caixa de **seleção de suporte à arquitetura Document/View** será desativada se você selecionar o tipo de aplicativo de diálogo.

Os assistentes Visual C++, bem como os editores de origem e diálogo, trabalham com o aplicativo gerado da forma como fariam com qualquer outro aplicativo gerado pelo Assistente. O aplicativo pode suportar barras de ferramentas, barras de rolagem e uma barra de status, e tem uma caixa **Sobre.** Seu aplicativo não registrará nenhum modelo de documento e não conterá uma classe de documentos.

Observe que seu aplicativo gerado `CChildView`tem uma `CWnd`classe de exibição, derivada de . O MFC cria e posiciona uma instância da classe de exibição dentro das janelas de quadro criadas pelo aplicativo. O MFC ainda impõe o uso de uma janela de exibição, porque simplifica o posicionamento e o gerenciamento do conteúdo do aplicativo. Você pode adicionar código `OnPaint` de pintura ao membro desta classe. Seu código deve adicionar barras de rolagem à exibição e não ao quadro.

Como a arquitetura de documento/exibição fornecida pelo MFC é responsável pela implementação de muitos dos recursos básicos de um aplicativo, sua ausência em seu projeto significa que você é responsável pela implementação de muitos recursos importantes do seu aplicativo:

- Conforme fornecido pelo MFC Application Wizard, o menu do aplicativo contém apenas comandos **New** and **Exit** no menu **Arquivo.** (O comando **New** é suportado apenas para aplicativos MDI, não para aplicativos SDI sem suporte a documentos/visualização.) O recurso de menu gerado não suportará uma lista MRU (usada mais recentemente).

- Você deve adicionar funções de manipulador e implementações para quaisquer comandos que seu aplicativo irá suportar, incluindo **Abrir** e **Salvar** no menu **Arquivo.** O MFC normalmente fornece código para suportar esses recursos, mas esse suporte está firmemente vinculado à arquitetura document/view.

- A barra de ferramentas para sua aplicação, se você solicitou uma, será mínima.

É fortemente recomendável que você use o MFC Application Wizard para criar aplicativos sem a arquitetura document/view, porque o assistente garante uma arquitetura MFC correta. No entanto, se você deve evitar usar o assistente, aqui estão várias abordagens para ignorar a arquitetura de documento/exibição em seu código:

- Trate o documento como um apêndice não utilizado e implemente seu código de gerenciamento de dados na classe de exibição, como sugerido acima. A sobrecarga para o documento é relativamente baixa. Um único objeto [CDocument](../mfc/reference/cdocument-class.md) incorre em uma pequena quantidade `CDocument`de sobrecarga por si só, além da pequena sobrecarga das classes base, [CCmdTarget](../mfc/reference/ccmdtarget-class.md) e [CObject](../mfc/reference/cobject-class.md). Ambas as últimas classes são pequenas.

   Declarado em `CDocument`:

  - Dois `CString` objetos.

  - Três **BOOLs.**

  - Um `CDocTemplate` ponteiro.

  - Um `CPtrList` objeto, que contém uma lista de visualizações do documento.

  Além disso, o documento requer a quantidade de tempo para criar o objeto do documento, seus objetos de exibição, uma janela de quadro e um objeto de modelo de documento.

- Trate o documento e a visão como apêndices não utilizados. Coloque seu gerenciamento de dados e código de desenho na janela do quadro em vez da exibição. Esta abordagem está mais próxima do modelo de programação em linguagem C.

- Anular as partes da estrutura mfc que criam o documento e visualizam para eliminar a criação deles. O processo de criação de `CWinApp::AddDocTemplate`documentos começa com uma chamada para . Elimine essa chamada da `InitInstance` função de membro da sua classe `InitInstance` de aplicativo e, em vez disso, crie uma janela de quadro em si mesmo. Coloque seu código de gerenciamento de dados na classe de janela do quadro. O processo de criação de documentos/exibição é ilustrado na [Criação de Documentos/Exibição](../mfc/document-view-creation.md). Isso é mais trabalhoso e requer uma compreensão mais profunda da estrutura, mas libera você inteiramente da sobrecarga de documento/visualização.

O artigo [MFC: O uso de classes de banco de dados sem documentos e visualizações](../data/mfc-using-database-classes-without-documents-and-views.md) dá exemplos mais concretos de alternativas de documentação/visualização no contexto de aplicativos de banco de dados.

## <a name="see-also"></a>Confira também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
