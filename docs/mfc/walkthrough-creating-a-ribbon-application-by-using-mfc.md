---
title: 'Instruções passo a passo: criando um aplicativo da faixa de opções usando MFC'
ms.date: 09/09/2019
helpviewer_keywords:
- ribbon application, creating (MFC)
- creating a ribbon application (MFC)
ms.assetid: e61393e2-1d6b-4594-a7ce-157d3d1b0d9f
ms.openlocfilehash: 0f81b27d479b15864302b21a467bff9489ba465a
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821916"
---
# <a name="walkthrough-creating-a-ribbon-application-by-using-mfc"></a>Instruções passo a passo: criando um aplicativo da faixa de opções usando MFC

Este tutorial mostra como usar o **Assistente de aplicativo MFC** para criar um aplicativo que tenha uma faixa de faixas por padrão. Em seguida, você pode expandir a faixa de faixas adicionando uma categoria de faixa de medida **personalizada** que tenha um painel de faixa de- **favoritos** e, em seguida, adicionando alguns comandos usados com frequência ao painel.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Este tutorial pressupõe que você definiu o Visual Studio para usar **configurações de desenvolvimento gerais**. Se você estiver usando configurações diferentes, alguns dos elementos da interface do usuário que são referenciados nas instruções a seguir podem não ser exibidos.

### <a name="to-create-an-mfc-application-that-has-a-ribbon"></a>Para criar um aplicativo do MFC que tenha uma faixa de opções

1. Use o **Assistente de aplicativo MFC** para criar um aplicativo MFC que tenha uma faixa de uma. Consulte [Walkthrough: usando os novos controles do shell do MFC](walkthrough-using-the-new-mfc-shell-controls.md) para obter instruções sobre como abrir o assistente para sua versão do Visual Studio.

1. Defina as seguintes opções no **Assistente de aplicativo do MFC**:

    1. Na seção **tipo de aplicativo** , em **estilo visual e cores**, selecione **Office 2007 (tema azul)** .

    1. Na seção **suporte a documentos compostos** , certifique-se de que **nenhum** esteja selecionado.

    1. Na seção **Propriedades do modelo de documento** , na caixa **extensão de arquivo** , digite uma extensão de nome de arquivo para documentos que esse aplicativo cria, por exemplo, *mfcrbnapp*.

    1. Na seção **suporte a banco de dados** (somente Visual Studio 2015), certifique-se de que **nenhum** esteja selecionado.

    1. Na seção **recursos da interface do usuário** , certifique-se de que **usar uma faixa de faixas** esteja selecionado.

    1. Por padrão, o **Assistente de aplicativo do MFC** adiciona suporte para vários painéis de encaixe. Como este passo a passo aborda apenas a faixa de opções, é possível remover essas opções do aplicativo. Na seção **recursos avançados** , desmarque todas as opções.

1. Clique em **concluir** para criar o aplicativo MFC.

1. Para verificar se o aplicativo foi criado com êxito, compile e o execute. Para criar o aplicativo, no menu **Compilar** , clique em **Compilar solução**. Se o aplicativo for compilado com êxito, execute-o clicando em **Iniciar Depuração** no menu **depurar** .

    O assistente cria automaticamente uma faixa de faixas que tem uma categoria de faixa de faixas chamada **página inicial**. Essa faixa de visão contém três painéis de faixa de faixas, que são chamados de **área de transferência**, **exibição**e **janela**.

### <a name="to-add-a-category-and-panel-to-the-ribbon"></a>Para adicionar uma categoria e um painel à faixa de opções

1. Para abrir o recurso de faixa de tipos criado pelo assistente, no menu **Exibir** , aponte para **outras janelas** e clique em **modo de exibição de recursos**. Em **modo de exibição de recursos**, clique em **faixa** de medida e clique duas vezes em **IDR_RIBBON**.

1. Primeiro, adicione uma categoria personalizada à faixa de bits clicando duas vezes em **categoria** na **caixa de ferramentas**.

    Uma categoria com a legenda **Category1** é criada. Por padrão, a categoria contém um painel.

    Clique com o botão direito do mouse em **Category1** e clique em **Propriedades**. Na janela **Propriedades** , altere a **legenda** para *personalizado*.

    As propriedades **imagens grandes** e **imagens pequenas** especificam os bitmaps que são usados como ícones para os elementos da faixa de faixas nesta categoria. Como a criação de bitmaps personalizados vai além do escopo deste passo a passo, basta reutilizar os bitmaps criados pelo assistente. Bitmaps pequenos têm 16 pixels por 16 pixels. Para imagens pequenas, use os bitmaps que são acessados pela ID de recurso `IDB_FILESMALL`. Bitmaps grandes têm 32 pixels por 32 pixels. Para imagens grandes, use os bitmaps que são acessados pela ID de recurso `IDB_FILELARGE`.

    > [!NOTE]
    > Em monitores HDPI (High Dots Per Inch, Muitos pontos por polegada), as versões HDPI das imagens são usadas automaticamente.

1. Em seguida, personalize o painel. Os painéis são usados para agrupar itens logicamente relacionados uns aos outros. Por exemplo, na guia **início** deste aplicativo, os comandos **recortar**, **copiar**e **colar** estão todos localizados no painel da **área de transferência** . Para personalizar o painel, clique com o botão direito do mouse em **Panel1** e clique em **Propriedades**. Na janela **Propriedades** , altere a **legenda** para *favoritos*.

    Você pode especificar o **índice de imagem** para o painel. Esse número especifica o ícone que será exibido se o painel da faixa de faixas for adicionado à **barra de ferramentas de acesso rápido**. O ícone não é exibido no painel da faixa de faixas em si.

1. Para verificar se a categoria e o painel da faixa de opções foram criados com êxito, visualize o controle da faixa de opções. Na **barra de ferramentas do editor de faixa de faixas**, clique no botão **testar faixa** de medida. Uma guia **personalizada** e um painel **favoritos** devem ser exibidos na faixa de faixas.

### <a name="to-add-elements-to-the-ribbon-panels"></a>Para adicionar elementos aos painéis da faixa de opções

1. Para adicionar elementos ao painel que você criou no procedimento anterior, arraste controles da seção editor de **faixa** de **caixa de ferramentas** para o painel no modo de exibição de design.

1. Primeiro, adicione um botão **Imprimir** . O botão **Imprimir** terá um submenu que contém um comando de **impressão rápida** que é impresso usando a impressora padrão. Esses dois comandos já estão definidos para esse aplicativo. Eles estão localizados no menu do aplicativo.

    Para criar o botão **Imprimir** , arraste uma ferramenta de botão para o painel.

    Na janela **Propriedades** , altere a propriedade **ID** para **ID_FILE_PRINT**, que já deve estar definida. Altere a **legenda** para *Imprimir*. Altere o **índice de imagem** para *4*.

    Para criar o botão **impressão rápida** , clique na coluna valor da propriedade ao lado de **itens de menu**e clique nas reticências ( **...** ). No **Editor de itens**, clique no botão **Adicionar** sem rótulo para criar um item de menu. Na janela **Propriedades** , altere a **legenda** para *impressão rápida*, **ID** para *ID_FILE_PRINT_DIRECT*e **imagem** para *5*. A propriedade Image especifica o ícone de **impressão rápida** no recurso de bitmap `IDB_FILESMALL`.

1. Para verificar se os botões foram adicionados ao painel da faixa de opções, compile e execute o aplicativo. Para criar o aplicativo, no menu **Compilar** , clique em **Compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando em **Iniciar Depuração** no menu **depurar** . O botão **Imprimir** e a caixa de combinação no painel **favoritos** na guia **personalizado** na faixa de faixas devem ser exibidos.

## <a name="next-steps"></a>Próximas etapas

[Como personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)

[Como personalizar o botão Aplicativo](../mfc/how-to-customize-the-application-button.md)

Para obter exemplos de ponta a ponta, consulte [exemplos (MFC Feature Pack)](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Veja também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)<br/>
[Exemplos (MFC Feature Pack)](../overview/visual-cpp-samples.md)
