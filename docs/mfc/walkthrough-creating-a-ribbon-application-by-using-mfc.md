---
title: 'Passo a passo: Criando um aplicativo de faixa de opções usando MFC'
ms.date: 04/25/2019
helpviewer_keywords:
- ribbon application, creating (MFC)
- creating a ribbon aplication (MFC)
ms.assetid: e61393e2-1d6b-4594-a7ce-157d3d1b0d9f
ms.openlocfilehash: a45df5258a16885b50e11d4cca8ba99eb4b3d458
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64558233"
---
# <a name="walkthrough-creating-a-ribbon-application-by-using-mfc"></a>Passo a passo: Criando um aplicativo de faixa de opções usando MFC

Este passo a passo mostra como usar o **Assistente de aplicativo MFC** para criar um aplicativo que tenha uma faixa de opções por padrão. Em seguida, você pode expandir a faixa de opções adicionando uma **personalizado** categoria de faixa de opções que tem um **Favoritos** painel e, em seguida, adicionando alguns comandos mais usados ao painel de faixa de opções.

## <a name="prerequisites"></a>Pré-requisitos

Este passo a passo pressupõe que você configurou o Visual Studio para usar **configurações gerais de desenvolvimento**. Se você estiver usando configurações diferentes, alguns dos elementos de (UI) de interface do usuário que são referenciados nas instruções a seguir podem não ser exibidos.

### <a name="to-create-an-mfc-application-that-has-a-ribbon"></a>Para criar um aplicativo do MFC que tenha uma faixa de opções

1. Use o **Assistente de aplicativo MFC** para criar um aplicativo do MFC que tenha uma faixa de opções. Confira [Passo a passo: Usando os novos controles de Shell MFC](walkthrough-using-the-new-mfc-shell-controls.md) para obter instruções sobre como abrir o Assistente para a sua versão do Visual Studio.

1. Defina as seguintes opções **Assistente de aplicativo MFC**:

    1. No **tipo de aplicativo** seção, no **Estilo Visual e cores**, selecione **Office 2007 (tema azul)**.

    1. No **suporte de documento composto** seção, certifique-se de que **None** está selecionado.

    1. No **propriedades do modelo de documento** seção, o **extensão de arquivo** , digite uma extensão de nome de arquivo para documentos que esse aplicativo cria, por exemplo, *mfcrbnapp*.

    1. No **suporte do banco de dados** seção (somente Visual Studio 2015), certifique-se de que **None** está selecionado.

    1. No **recursos de Interface do usuário** seção, certifique-se de que **usar uma faixa de opções** está selecionado.

    1. Por padrão, o **Assistente de aplicativo MFC** adiciona suporte para vários painéis de encaixe. Como este passo a passo aborda apenas a faixa de opções, é possível remover essas opções do aplicativo. No **recursos avançados** seção, desmarque todas as opções.

1. Clique em **concluir** para criar o aplicativo do MFC.

1. Para verificar se o aplicativo foi criado com êxito, compile e o execute. Para compilar o aplicativo, na **construir** menu, clique em **compilar solução**. Se o aplicativo foi compilado com êxito, execute-o clicando **iniciar depuração** sobre o **depurar** menu.

    O assistente cria automaticamente uma faixa de opções que tem uma categoria de faixa de opções chamado **Home**. Esta faixa contém três painéis de faixa de opções, que são nomeados **na área de transferência**, **exibição**, e **janela**.

### <a name="to-add-a-category-and-panel-to-the-ribbon"></a>Para adicionar uma categoria e um painel à faixa de opções

1. Para abrir o recurso de faixa de opções criado pelo assistente, na **modo de exibição** , aponte para **Other Windows** e, em seguida, clique em **exibição de recurso**. Na **exibição de recurso**, clique em **faixa de opções** e, em seguida, clique duas vezes em **IDR_RIBBON**.

1. Primeiro, adicione uma categoria personalizada à faixa de opções clicando duas vezes **categoria** na **caixa de ferramentas**.

    Uma categoria que tem a legenda **Categoria1** é criado. Por padrão, a categoria contém um painel.

    Clique com botão direito **Categoria1** e, em seguida, clique em **propriedades**. No **propriedades** janela, alteração **legenda** para *personalizado*.

    O **imagens grandes** e **imagens pequenas** propriedades especificam os bitmaps usados como ícones para os elementos de faixa de opções nessa categoria. Como a criação de bitmaps personalizados vai além do escopo deste passo a passo, basta reutilizar os bitmaps criados pelo assistente. Bitmaps pequenos têm 16 pixels por 16 pixels. Para imagens pequenas, use os bitmaps acessados pelo `IDB_FILESMALL` ID de recurso. Bitmaps grandes têm 32 pixels por 32 pixels. Para imagens grandes, use os bitmaps acessados pelo `IDB_FILELARGE` ID de recurso.

    > [!NOTE]
    > Em monitores HDPI (High Dots Per Inch, Muitos pontos por polegada), as versões HDPI das imagens são usadas automaticamente.

1. Em seguida, personalize o painel. Os painéis são usados para agrupar itens logicamente relacionados uns aos outros. Por exemplo, na **página inicial** guia deste aplicativo, o **Recortar**, **cópia**, e **colar** comandos estão localizados no  **Área de transferência** painel. Para personalizar o painel, clique com botão direito **Panel1** e, em seguida, clique em **propriedades**. No **propriedades** janela, alteração **legenda** para *Favoritos*.

    Você pode especificar o **índice de imagem** para o painel. Esse número Especifica o ícone que será exibido se o painel de faixa de opções é adicionado para o **ferramentas de acesso rápido**. O ícone não é exibido no painel de faixa de opções em si.

1. Para verificar se a categoria e o painel da faixa de opções foram criados com êxito, visualize o controle da faixa de opções. Sobre o **barra de ferramentas do Editor de faixa de opções**, clique no **faixa de opções de teste** botão. Um **personalizado** guia e **Favoritos** painel deve ser exibida na faixa de opções.

### <a name="to-add-elements-to-the-ribbon-panels"></a>Para adicionar elementos aos painéis da faixa de opções

1. Para adicionar elementos ao painel que você criou no procedimento anterior, arraste os controles do **Editor de faixa de opções** seção o **caixa de ferramentas** ao painel no modo de exibição de design.

1. Primeiro, adicione uma **impressão** botão. O **Print** botão terá um submenu que contém uma **impressão rápida** comando imprime usando a impressora padrão. Esses dois comandos já estão definidos para esse aplicativo. Eles estão localizados no menu do aplicativo.

    Para criar o **impressão** botão, arraste uma ferramenta botão para o painel.

    No **propriedades** janela, altere o **ID** propriedade a ser **ID_FILE_PRINT**, que já deve estar definido. Alteração **legenda** à *impressão*. Alteração **índice de imagem** à *4*.

    Para criar o **impressão rápida** , clique em coluna valor da propriedade lado **itens de Menu**e, em seguida, clique no botão de reticências (**...** ). No **Editor de itens**, clique em sem o rótulo **Add** botão para criar um item de menu. No **propriedades** janela, alteração **legenda** para *impressão rápida*, **ID** para *ID_FILE_PRINT_DIRECT*, e **imagem** para *5*. A propriedade image Especifica o **impressão rápida** ícone no `IDB_FILESMALL` recurso de bitmap.

1. Para verificar se os botões foram adicionados ao painel da faixa de opções, compile e execute o aplicativo. Para compilar o aplicativo, na **construir** menu, clique em **compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando **iniciar depuração** sobre o **depurar** menu. O **Print** botão e a caixa de combinação caixa na **Favoritos** painel a **personalizado** guia na faixa de opções deve ser exibido.

## <a name="next-steps"></a>Próximas etapas

[Como: personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)

[Como: personalizar o botão do aplicativo](../mfc/how-to-customize-the-application-button.md)

Para obter exemplos de ponta a ponta, consulte [exemplos (MFC Feature Pack)](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)<br/>
[Exemplos (MFC Feature Pack)](../overview/visual-cpp-samples.md)
