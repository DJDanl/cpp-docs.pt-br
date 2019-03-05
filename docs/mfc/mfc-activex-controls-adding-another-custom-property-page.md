---
title: 'Controles ActiveX MFC: Adicionando outra página de propriedade personalizada'
ms.date: 11/04/2016
helpviewer_keywords:
- property pages [MFC], MFC ActiveX controls
- custom property pages [MFC]
- ActiveX controls [MFC], property pages
- MFC ActiveX controls [MFC], property pages
ms.assetid: fcf7e119-9f29-41a9-908d-e9b1607e08af
ms.openlocfilehash: 87b71fdddc5b52f66c34cdbcdb234c83616d0850
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289540"
---
# <a name="mfc-activex-controls-adding-another-custom-property-page"></a>Controles ActiveX MFC: Adicionando outra página de propriedade personalizada

Ocasionalmente, um controle ActiveX terá mais propriedades que razoavelmente pode caber em uma única página de propriedade. Nesse caso, você pode adicionar páginas de propriedades para o controle ActiveX para exibir essas propriedades.

Este artigo aborda a adição de novas páginas de propriedade para um controle ActiveX que já tem pelo menos uma página de propriedade. Para obter mais informações sobre como adicionar a propriedade de estoque páginas (fonte, imagem ou cor), consulte o artigo [controles ActiveX MFC: Usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md).

Os procedimentos a seguir usam uma estrutura de controle de ActiveX de exemplo criada pelo Assistente de controle ActiveX. Portanto, os nomes de classe e os identificadores são exclusivos para esse exemplo.

Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX MFC: Páginas de propriedades](../mfc/mfc-activex-controls-property-pages.md)

- [Controles ActiveX MFC: Usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)

    > [!NOTE]
    >  É altamente recomendável essa nova propriedade páginas seguem o tamanho padrão para páginas de propriedades do controle ActiveX. A propriedade de imagem e a cor de estoque páginas unidades de caixa de diálogo de medida 250 x 62 (DLU). A página de propriedades de fonte padrão é 250 x 110 DLUs. A página de propriedades padrão criada pelo Assistente de controle ActiveX usa o padrão DLU de 250 x 62.

### <a name="to-insert-a-new-property-page-template-into-your-project"></a>Para inserir um novo modelo de página de propriedade em seu projeto

1. Com seu projeto de controle é aberto, abra a exibição de recurso no espaço de trabalho do projeto.

1. Clique com botão direito na exibição de recurso para abrir o menu de atalho e clique em **adicionar recurso**.

1. Expanda o **caixa de diálogo** nó e selecione **IDD_OLE_PROPPAGE_SMALL**.

1. Clique em **New** para adicionar o recurso ao seu projeto.

1. Selecione o novo modelo de página de propriedade para atualizar a janela Propriedades.

1. Insira um novo valor para o **ID** propriedade. Este exemplo usa **IDD_PROPPAGE_NEWPAGE**.

1. Clique em **salvar** na barra de ferramentas.

### <a name="to-associate-the-new-template-with-a-class"></a>Para associar o novo modelo uma classe

1. Abrir modo de exibição de classe.

1. Clique com botão direito no modo de exibição de classe para abrir o menu de atalho.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar classe**.

   Isso abre o [Adicionar classe](../ide/add-class-dialog-box.md) caixa de diálogo.

1. Clique duas vezes o **classe MFC** modelo.

1. No **nome da classe** caixa de [MFC Class Wizard](../mfc/reference/mfc-add-class-wizard.md), digite um nome para a nova classe de caixa de diálogo. (Neste exemplo, `CAddtlPropPage`.)

1. Se você quiser alterar os nomes de arquivo, clique em **alterar**. Digite os nomes para os arquivos de cabeçalho e de implementação ou aceite os nomes padrão.

1. No **classe base** caixa, selecione `COlePropertyPage`.

1. No **ID da caixa de diálogo** caixa, selecione **IDD_PROPPAGE_NEWPAGE**.

9. Clique em **concluir** para criar a classe.

Para permitir que os usuários do controle acesso a essa nova página de propriedades, faça as seguintes alterações à seção do controle propriedade página IDs macro (localizada no arquivo de implementação de controle):

[!code-cpp[NVC_MFC_AxUI#32](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_1.cpp)]

Observe que você deve aumentar o segundo parâmetro da macro BEGIN_PROPPAGEIDS (a contagem de páginas de propriedade) de 1 a 2.

Você também deve modificar o arquivo de implementação de controle (. Arquivo CPP) para incluir o cabeçalho (. H) o arquivo da nova classe de página de propriedade.

A próxima etapa envolve a criação de dois novos recursos de cadeia de caracteres que fornecerão um nome de tipo e uma legenda para a nova página de propriedade.

#### <a name="to-add-new-string-resources-to-a-property-page"></a>Para adicionar novos recursos de cadeia de caracteres para uma página de propriedades

1. Com seu projeto de controle é aberto, abra o modo de exibição de recursos.

1. Clique duas vezes o **tabela de cadeia de caracteres** pasta e clique duas vezes no recurso ao qual você deseja adicionar uma cadeia de caracteres de tabela de cadeia de caracteres existente.

   Isso abre a tabela de cadeia de caracteres em uma janela.

1. Selecione a linha em branco no final da tabela de cadeia de caracteres e digite o texto ou a legenda da cadeia de caracteres: por exemplo, "adicionais propriedade página".

   Isso abre uma **propriedades de cadeia de caracteres** mostrando **legenda** e **ID** caixas. O **legenda** caixa contém a cadeia de caracteres que você digitou.

1. No **ID** caixa, selecione ou digite uma ID para a cadeia de caracteres. Quando você terminar, pressione Enter.

   Este exemplo usa **IDS_SAMPLE_ADDPAGE** para o nome do tipo da nova página de propriedade.

1. Repita as etapas 3 e 4 usando **IDS_SAMPLE_ADDPPG_CAPTION** para a ID e a "Página de propriedades adicionais" para a legenda.

1. Na. O arquivo CPP da sua nova classe de página de propriedade (neste exemplo, `CAddtlPropPage`) modificar as `CAddtlPropPage::CAddtlPropPageFactory::UpdateRegistry` para que IDS_SAMPLE_ADDPAGE é passado por [AfxOleRegisterPropertyPageClass](../mfc/reference/registering-ole-controls.md#afxoleregisterpropertypageclass), conforme mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFC_AxUI#33](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_2.cpp)]

1. Modifique o construtor de `CAddtlPropPage` para que IDS_SAMPLE_ADDPPG_CAPTION é passado para o `COlePropertyPage` construtor, da seguinte maneira:

   [!code-cpp[NVC_MFC_AxUI#34](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_3.cpp)]

Depois de ter feito as modificações necessárias Recrie seu projeto e usar o contêiner de teste para testar a nova página de propriedade. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
