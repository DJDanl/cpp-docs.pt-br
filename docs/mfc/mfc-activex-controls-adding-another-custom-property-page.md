---
title: 'Controles ActiveX MFC: adicionando outra página de propriedade personalizada'
ms.date: 11/04/2016
helpviewer_keywords:
- property pages [MFC], MFC ActiveX controls
- custom property pages [MFC]
- ActiveX controls [MFC], property pages
- MFC ActiveX controls [MFC], property pages
ms.assetid: fcf7e119-9f29-41a9-908d-e9b1607e08af
ms.openlocfilehash: a749c5d8d676ac85c3c2085eb041328aff599ab8
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508881"
---
# <a name="mfc-activex-controls-adding-another-custom-property-page"></a>Controles ActiveX MFC: adicionando outra página de propriedade personalizada

Ocasionalmente, um controle ActiveX terá mais propriedades do que pode se ajustar de forma razoável em uma página de propriedades. Nesse caso, você pode adicionar páginas de propriedades ao controle ActiveX para exibir essas propriedades.

Este artigo aborda a adição de novas páginas de propriedades a um controle ActiveX que já tem pelo menos uma página de propriedades. Para obter mais informações sobre como adicionar páginas de propriedades de estoque (fonte, imagem ou cor), consulte o artigo [controles ActiveX do MFC: usando páginas de propriedades de estoque](mfc-activex-controls-using-stock-property-pages.md).

Os procedimentos a seguir usam uma estrutura de controle ActiveX de exemplo criada pelo assistente de controle ActiveX. Portanto, os nomes e identificadores de classe são exclusivos para este exemplo.

Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX do MFC: páginas de propriedades](mfc-activex-controls-property-pages.md)

- [Controles ActiveX do MFC: usando páginas de propriedades de estoque](mfc-activex-controls-using-stock-property-pages.md)

    > [!NOTE]
    >  É altamente recomendável que as novas páginas de propriedades aderem ao padrão de tamanho das páginas de propriedades do controle ActiveX. As páginas de propriedade de imagem e cor de estoque medem 250x62 DLU (unidades de diálogo). A página de propriedades de fonte padrão é 250x110 DLUs. A página de propriedades padrão criada pelo assistente de controle ActiveX usa o padrão 250x62 DLU.

### <a name="to-insert-a-new-property-page-template-into-your-project"></a>Para inserir um novo modelo de página de propriedades em seu projeto

1. Com seu projeto de controle aberto, abra Modo de Exibição de Recursos no espaço de trabalho do projeto.

1. Clique com o botão direito do mouse em Modo de Exibição de Recursos para abrir o menu de atalho e clique em **Adicionar recurso**.

1. Expanda o nó da **caixa de diálogo** e selecione **IDD_OLE_PROPPAGE_SMALL**.

1. Clique em **novo** para adicionar o recurso ao seu projeto.

1. Selecione o novo modelo de página de propriedades para atualizar a janela **Propriedades** (em **modo de exibição de recursos**).

1. Insira um novo valor para a propriedade **ID** . Este exemplo usa **IDD_PROPPAGE_NEWPAGE**.

1. Clique em **Salvar** na barra de ferramentas.

### <a name="to-associate-the-new-template-with-a-class"></a>Para associar o novo modelo a uma classe

1. Abra Modo de Exibição de Classe.

1. Clique com o botão direito do mouse em Modo de Exibição de Classe para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

   Isso abre a caixa de diálogo [Adicionar classe](../ide/adding-a-class-visual-cpp.md#add-class-dialog-box) .

1. Clique duas vezes no modelo de **classe do MFC** .

1. Na caixa **nome da classe** no [Assistente de classe do MFC](reference/mfc-add-class-wizard.md), digite um nome para a nova classe da caixa de diálogo. (Neste exemplo, `CAddtlPropPage` .)

1. Se você quiser alterar nomes de arquivo, clique em **alterar**. Digite os nomes dos arquivos de implementação e de cabeçalho ou aceite os nomes padrão.

1. Na caixa **classe base** , selecione `COlePropertyPage` .

1. Na caixa **ID de diálogo** , selecione **IDD_PROPPAGE_NEWPAGE**.

1. Clique em **concluir** para criar a classe.

Para permitir que os usuários do controle acessem essa nova página de propriedades, faça as seguintes alterações na seção de macro IDs de página de propriedades do controle (localizada no arquivo de implementação de controle):

[!code-cpp[NVC_MFC_AxUI#32](codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_1.cpp)]

Observe que você deve aumentar o segundo parâmetro da macro BEGIN_PROPPAGEIDS (a contagem de páginas de propriedades) de 1 para 2.

Você também deve modificar o arquivo de implementação de controle (. CPP) para incluir o cabeçalho (. H) do arquivo da nova classe de página de propriedades.

A próxima etapa envolve a criação de dois novos recursos de cadeia de caracteres que fornecerão um nome de tipo e uma legenda para a nova página de propriedades.

#### <a name="to-add-new-string-resources-to-a-property-page"></a>Para adicionar novos recursos de cadeia de caracteres a uma página de propriedades

1. Com seu projeto de controle aberto, abra Modo de Exibição de Recursos.

1. Clique duas vezes na pasta da **tabela de cadeia de caracteres** e clique duas vezes no recurso de tabela de cadeia de caracteres existente ao qual você deseja adicionar uma cadeia de caracteres.

   Isso abre a tabela de cadeia de caracteres em uma janela.

1. Selecione a linha em branco no final da tabela de cadeia de caracteres e digite o texto, ou legenda, da cadeia de caracteres: por exemplo, "página de propriedades adicional".

   Isso abre uma página de **Propriedades de cadeia de caracteres mostrando as** caixas **legenda** e **ID** . A caixa **legenda** contém a cadeia de caracteres que você digitou.

1. Na caixa **ID** , selecione ou digite uma ID para a cadeia de caracteres. Pressione Enter quando terminar.

   Este exemplo usa **IDS_SAMPLE_ADDPAGE** para o nome do tipo da nova página de propriedades.

1. Repita as etapas 3 e 4 usando **IDS_SAMPLE_ADDPPG_CAPTION** para a ID e "página de propriedades adicional" para a legenda.

1. No. Arquivo CPP da sua nova classe de página de Propriedades (neste exemplo, `CAddtlPropPage` ) modifique o `CAddtlPropPage::CAddtlPropPageFactory::UpdateRegistry` para que IDS_SAMPLE_ADDPAGE seja passado por [AfxOleRegisterPropertyPageClass](reference/registering-ole-controls.md#afxoleregisterpropertypageclass), como no exemplo a seguir:

   [!code-cpp[NVC_MFC_AxUI#33](codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_2.cpp)]

1. Modifique o construtor de `CAddtlPropPage` para que IDS_SAMPLE_ADDPPG_CAPTION seja passado para o `COlePropertyPage` Construtor, da seguinte maneira:

   [!code-cpp[NVC_MFC_AxUI#34](codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_3.cpp)]

Depois de fazer as modificações necessárias, recompile seu projeto e use o contêiner de teste para testar a nova página de propriedades. Consulte [testando Propriedades e eventos com o contêiner de teste](testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
