---
title: 'Controles ActiveX MFC: Adicionando outra propriedade personalizada página | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property pages [MFC], MFC ActiveX controls
- custom property pages [MFC]
- ActiveX controls [MFC], property pages
- MFC ActiveX controls [MFC], property pages
ms.assetid: fcf7e119-9f29-41a9-908d-e9b1607e08af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c9c3d9f4744ae01a7e251387bd342b77292d1c0d
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931603"
---
# <a name="mfc-activex-controls-adding-another-custom-property-page"></a>Controles ActiveX MFC: adicionando outra página de propriedade personalizada
Ocasionalmente, um controle ActiveX terá mais propriedades do que pode conter uma página de propriedade. Nesse caso, você pode adicionar páginas de propriedades para o controle ActiveX para exibir essas propriedades.  
  
 Este artigo aborda a adição de novas páginas de propriedade para um controle ActiveX que já tem pelo menos uma página de propriedade. Para obter mais informações sobre como adicionar propriedade de estoque páginas (fonte, imagem ou cor), consulte o artigo [controles ActiveX MFC: usando páginas de propriedades de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md).  
  
 Os procedimentos a seguir usam uma estrutura de controle ActiveX exemplo criada pelo Assistente de controle ActiveX. Portanto, os nomes de classe e os identificadores são exclusivos para esse exemplo.  
  
 Para obter mais informações sobre como usar páginas de propriedade em um controle ActiveX, consulte os seguintes artigos:  
  
-   [Controles ActiveX do MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)  
  
-   [Controles ActiveX do MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)  
  
    > [!NOTE]
    >  É altamente recomendável essa nova propriedade páginas aderem ao tamanho padrão para páginas de propriedades do controle ActiveX. A propriedade de imagem e a cor de estoque páginas unidades de diálogo medidas 250 x 62 (DLU). A página de propriedades de fonte padrão é 250 x 110 DLUs. A página de propriedade padrão criada pelo Assistente de controle ActiveX usa o padrão DLU 250 x 62.  
  
### <a name="to-insert-a-new-property-page-template-into-your-project"></a>Para inserir um novo modelo de página de propriedade em seu projeto  
  
1.  Com o projeto de controle é aberto, abra modo de exibição de recursos no espaço de trabalho do projeto.  
  
2.  Clique no modo de exibição de recurso para abrir o menu de atalho e clique em **adicionar recurso**.  
  
3.  Expanda o **diálogo** nó e selecione **IDD_OLE_PROPPAGE_SMALL**.  
  
4.  Clique em **novo** para adicionar o recurso ao seu projeto.  
  
5.  Selecione o novo modelo de página de propriedade para atualizar a janela Propriedades.  
  
6.  Insira um novo valor para o **ID** propriedade. Este exemplo usa **IDD_PROPPAGE_NEWPAGE**.  
  
7.  Clique em **salvar** na barra de ferramentas.  
  
### <a name="to-associate-the-new-template-with-a-class"></a>Para associar o novo modelo uma classe  
  
1.  Abrir modo de exibição de classe.  
  
2.  Clique no modo de exibição de classe para abrir o menu de atalho.  
  
3.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar classe**.  
  
     Isso abre o [Adicionar classe](../ide/add-class-dialog-box.md) caixa de diálogo.  
  
4.  Clique duas vezes o **classe MFC** modelo.  
  
5.  No **nome da classe** caixa o [Assistente de classe MFC](../mfc/reference/mfc-add-class-wizard.md), digite um nome para a nova classe de caixa de diálogo. (Neste exemplo, `CAddtlPropPage`.)  
  
6.  Se você quiser alterar nomes de arquivo, clique em **alterar**. Digite os nomes para os arquivos de cabeçalho e de implementação ou aceite os nomes padrão.  
  
7.  No **classe Base** caixa, selecione `COlePropertyPage`.  
  
8.  No **ID da caixa de diálogo** selecione **IDD_PROPPAGE_NEWPAGE**.  
  
9. Clique em **concluir** para criar a classe.  
  
 Para permitir que os usuários do controle acesso para essa nova página de propriedades, faça as seguintes alterações à seção do controle propriedade página IDs macro (localizada no arquivo de implementação de controle):  
  
 [!code-cpp[NVC_MFC_AxUI#32](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_1.cpp)]  
  
 Observe que você deve aumentar o segundo parâmetro de macro BEGIN_PROPPAGEIDS (a contagem de páginas de propriedade) de 1 para 2.  
  
 Você também deve modificar o arquivo de implementação de controle (. Arquivo CPP) para incluir o cabeçalho (. H) de arquivo da nova classe de página de propriedade.  
  
 A próxima etapa envolve a criação de dois novos recursos de cadeia de caracteres que forneçam um nome de tipo e uma legenda para a nova página de propriedade.  
  
#### <a name="to-add-new-string-resources-to-a-property-page"></a>Para adicionar novos recursos de cadeia de caracteres para uma página de propriedades  
  
1.  Com o projeto de controle é aberto, abra a exibição de recursos.  
  
2.  Clique duas vezes o **tabela de cadeia de caracteres** pasta e clique duas vezes a cadeia de caracteres existente da tabela à qual você deseja adicionar uma cadeia de caracteres de recurso.  
  
     Isso abre a tabela de cadeia de caracteres em uma janela.  
  
3.  Selecione a linha em branco no final da tabela de cadeia de caracteres e digite o texto ou a legenda da cadeia de caracteres: por exemplo, "propriedade página adicional."  
  
     Isso abre uma **propriedades de cadeia de caracteres** mostrando **legenda** e **ID** caixas. O **legenda** caixa contém a cadeia de caracteres que você digitou.  
  
4.  No **ID** caixa, selecione ou digite uma ID para a cadeia de caracteres. Quando terminar, pressione Enter.  
  
     Este exemplo usa **IDS_SAMPLE_ADDPAGE** para o nome do tipo da nova página de propriedade.  
  
5.  Repita as etapas 3 e 4 usando **IDS_SAMPLE_ADDPPG_CAPTION** para a ID e a "Página de propriedades adicionais" para a legenda.  
  
6.  No. O arquivo CPP da sua nova classe de página de propriedade (neste exemplo, `CAddtlPropPage`) modificar a `CAddtlPropPage::CAddtlPropPageFactory::UpdateRegistry` para que IDS_SAMPLE_ADDPAGE é passado por [AfxOleRegisterPropertyPageClass](../mfc/reference/registering-ole-controls.md#afxoleregisterpropertypageclass), conforme mostrado no exemplo a seguir:  
  
     [!code-cpp[NVC_MFC_AxUI#33](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_2.cpp)]  
  
7.  Modificar o construtor de `CAddtlPropPage` para que IDS_SAMPLE_ADDPPG_CAPTION é passado para o `COlePropertyPage` construtor, da seguinte maneira:  
  
     [!code-cpp[NVC_MFC_AxUI#34](../mfc/codesnippet/cpp/mfc-activex-controls-adding-another-custom-property-page_3.cpp)]  
  
 Depois de fazer as modificações necessárias recriar seu projeto e use o contêiner de teste para testar a nova página de propriedade. Consulte [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

