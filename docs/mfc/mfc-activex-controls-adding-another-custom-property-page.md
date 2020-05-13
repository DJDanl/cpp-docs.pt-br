---
title: 'Controles ActiveX MFC: adicionando outra página de propriedade personalizada'
ms.date: 11/04/2016
helpviewer_keywords:
- property pages [MFC], MFC ActiveX controls
- custom property pages [MFC]
- ActiveX controls [MFC], property pages
- MFC ActiveX controls [MFC], property pages
ms.assetid: fcf7e119-9f29-41a9-908d-e9b1607e08af
ms.openlocfilehash: 02c87c2c5283b7293c2a7ab028ec9a2abbba2b33
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364733"
---
# <a name="mfc-activex-controls-adding-another-custom-property-page"></a>Controles ActiveX MFC: adicionando outra página de propriedade personalizada

Ocasionalmente, um controle ActiveX terá mais propriedades do que pode caber razoavelmente em uma página de propriedade. Neste caso, você pode adicionar páginas de propriedade ao controle ActiveX para exibir essas propriedades.

Este artigo discute a adição de novas páginas de propriedade a um controle ActiveX que já tem pelo menos uma página de propriedade. Para obter mais informações sobre a adição de páginas de propriedade de estoque (fonte, imagem ou cor), consulte o artigo [MFC ActiveX Controls: Usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md).

Os procedimentos a seguir usam uma estrutura de controle ActiveX de amostra criada pelo ActiveX Control Wizard. Portanto, os nomes e identificadores de classe são exclusivos deste exemplo.

Para obter mais informações sobre o uso de páginas de propriedade em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX do MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)

- [Controles ActiveX do MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)

    > [!NOTE]
    >  É fortemente recomendável que novas páginas de propriedade aderam ao padrão de tamanho para páginas de propriedade de controle ActiveX. As páginas de imagem de estoque e propriedade de cor medem as unidades de diálogo 250x62 (DLU). A página de propriedade de fonte padrão é 250x110 DLUs. A página de propriedade padrão criada pelo ActiveX Control Wizard usa o padrão DLU 250x62.

### <a name="to-insert-a-new-property-page-template-into-your-project"></a>Para inserir um novo modelo de página de propriedade em seu projeto

1. Com seu projeto de controle aberto, abra a Visualização de Recursos no espaço de trabalho do projeto.

1. Clique com o botão direito do mouse na exibição de recursos para abrir o menu de atalho e clique **em Adicionar recurso**.

1. Expanda o nó **Diálogo** e selecione **IDD_OLE_PROPPAGE_SMALL**.

1. Clique **em Novo** para adicionar o recurso ao seu projeto.

1. Selecione o novo modelo de página de propriedade para atualizar a janela **Propriedades** (em **Exibição de recursos**).

1. Digite um novo valor para a propriedade **ID.** Este exemplo usa **IDD_PROPPAGE_NEWPAGE**.

1. Clique em **Salvar** na barra de ferramentas.

### <a name="to-associate-the-new-template-with-a-class"></a>Associar o novo modelo a uma classe

1. Vista de classe aberta.

1. Clique com o botão direito do mouse na exibição de classe para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

   Isso abre a caixa de diálogo [Adicionar classe.](../ide/add-class-dialog-box.md)

1. Clique duas vezes no modelo **Classe MFC.**

1. Na caixa Nome de **classe** no [Assistente de Classe Do MFC,](../mfc/reference/mfc-add-class-wizard.md)digite um nome para a nova classe de diálogo. (Neste exemplo, `CAddtlPropPage`.)

1. Se você quiser alterar os nomes dos arquivos, clique **em Alterar**. Digite os nomes para seus arquivos de implementação e cabeçalho ou aceite os nomes padrão.

1. Na caixa **Classe base,** selecione `COlePropertyPage`.

1. Na caixa **'ID de diálogo',** selecione **IDD_PROPPAGE_NEWPAGE**.

1. Clique **em Concluir** para criar a classe.

Para permitir que os usuários do controle acessem essa nova página de propriedade, faça as seguintes alterações na seção de macro IDs da página de propriedade do controle (localizada no arquivo de implementação de controle):

[!code-cpp[NVC_MFC_AxUI#32](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_1.cpp)]

Observe que você deve aumentar o segundo parâmetro da macro BEGIN_PROPPAGEIDS (a contagem da página de propriedade) de 1 para 2.

Você também deve modificar o arquivo de implementação de controle (. Arquivo CPP) para incluir o cabeçalho (. H) arquivo da nova classe de página de propriedade.

O próximo passo envolve a criação de dois novos recursos de string que fornecerão um nome de tipo e uma legenda para a nova página de propriedade.

#### <a name="to-add-new-string-resources-to-a-property-page"></a>Para adicionar novos recursos de string a uma página de propriedade

1. Com seu projeto de controle aberto, abra a Visualização de Recursos.

1. Clique duas vezes na pasta **Tabela de strings** e clique duas vezes no recurso de tabela de strings existente ao qual você deseja adicionar uma seqüência.

   Isso abre a mesa de cordas em uma janela.

1. Selecione a linha em branco no final da tabela de strings e digite o texto, ou legenda, da string: por exemplo, "Página de propriedade adicional".

   Isso abre uma página **propriedades de string** mostrando **legenda** e caixas **de dissé.** A **caixa Legenda** contém a seqüência digitada.

1. Na caixa **ID,** selecione ou digite um ID para a seqüência. Pressione Enter quando terminar.

   Este exemplo usa **IDS_SAMPLE_ADDPAGE** para o nome de tipo da nova página de propriedade.

1. Repita as etapas 3 e 4 usando **IDS_SAMPLE_ADDPPG_CAPTION** para o ID e "Página de Propriedade Adicional" para a legenda.

1. No . O arquivo CPP da sua nova classe `CAddtlPropPage`de `CAddtlPropPage::CAddtlPropPageFactory::UpdateRegistry` página de propriedade (neste exemplo) modificar o IDS_SAMPLE_ADDPAGE é passado pelo [AfxOleRegisterPropertyPageClass](../mfc/reference/registering-ole-controls.md#afxoleregisterpropertypageclass), como no exemplo a seguir:

   [!code-cpp[NVC_MFC_AxUI#33](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_2.cpp)]

1. Modificar o construtor `CAddtlPropPage` para que IDS_SAMPLE_ADDPPG_CAPTION seja `COlePropertyPage` passado para o construtor, da seguinte forma:

   [!code-cpp[NVC_MFC_AxUI#34](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_3.cpp)]

Depois de fazer as modificações necessárias, reconstrua seu projeto e use o Test Container para testar a nova página de propriedade. Consulte [Propriedades de teste e eventos com o recipiente de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o recipiente de teste.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
