---
title: "Controles ActiveX MFC: adicionando outra p&#225;gina de propriedade personalizada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], páginas de propriedade"
  - "páginas de propriedades personalizadas"
  - "Controles ActiveX MFC [C++], páginas de propriedade"
  - "páginas de propriedades [C++], Controles ActiveX MFC"
ms.assetid: fcf7e119-9f29-41a9-908d-e9b1607e08af
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: adicionando outra p&#225;gina de propriedade personalizada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ocasionalmente, um controle ActiveX terá mais propriedades de que podem razoavelmente ajuste em uma página de propriedades.  Nesse caso, você pode adicionar páginas de propriedades no controle ActiveX para exibir essas propriedades.  
  
 Este artigo descreve adicionar novas páginas de propriedades a um controle ActiveX que já tem pelo menos uma página de propriedades.  Para obter mais informações sobre como adicionar as páginas de propriedades de estoque \(fonte, cor ou imagem,\), consulte o artigo [Controles ActiveX MFC: Usando as páginas de propriedades de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md).  
  
 Os procedimentos a seguir usam uma estrutura de exemplo do controle ActiveX criada pelo assistente de controle ActiveX.  Como consequência, os nomes da classe e os identificadores são exclusivas deste exemplo.  
  
 Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os artigos a seguir:  
  
-   [Controles ActiveX MFC: Páginas de propriedades](../mfc/mfc-activex-controls-property-pages.md)  
  
-   [Controles ActiveX MFC: Usando as páginas de propriedades de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)  
  
    > [!NOTE]
    >  É altamente recomendável que as novas páginas de propriedades ela segue o padrão do tamanho para páginas de propriedades do controle ActiveX.  As páginas de propriedades de estoque de imagem e cor abrangem as unidades da caixa de diálogo 250x62 \(DLU\).  A página de propriedades de fonte padrão é 250x110 DLUs.  A página de propriedades padrão criada pelo assistente de controle ActiveX usa o padrão de 250x62 DLU.  
  
### Para inserir um novo modelo da página de propriedades do projeto  
  
1.  Com o projeto de controle, abra a exibição aberta de recursos no espaço de trabalho do projeto.  
  
2.  Clique com o botão direito do mouse na exibição do recurso para abrir o menu de atalho e clique **Adicionar Recurso**.  
  
3.  Expanda o nó de **Caixa de Diálogo** , e selecione **IDD\_OLE\_PROPPAGE\_SMALL**.  
  
4.  Clique `New` para adicionar o recurso ao seu projeto.  
  
5.  Selecione o novo modelo da página de propriedades para atualizar a janela Propriedades.  
  
6.  Insira um novo valor para a propriedade de **ID** .  Este exemplo usa **IDD\_PROPPAGE\_NEWPAGE**.  
  
7.  Clique **Salvar** na barra de ferramentas.  
  
### Para associar um novo modelo com uma classe  
  
1.  Exibição aberta da classe.  
  
2.  Clique com o botão direito do mouse na exibição da classe para abrir o menu de atalho.  
  
3.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Classe**.  
  
     Isso abre a caixa de diálogo de [Adicione a classe](../ide/add-class-dialog-box.md) .  
  
4.  Clique duas vezes no modelo de **Classe do MFC** .  
  
5.  Na caixa de **Nome da classe** em [Assistente da classe de MFC](../mfc/reference/mfc-add-class-wizard.md), digite um nome para a nova classe da caixa de diálogo. \(Neste exemplo, `CAddtlPropPage`.\)  
  
6.  Para que os nomes de arquivo de alterações, clique em **Alterar**.  Digite os nomes para sua implementação e arquivos de cabeçalho, ou aceite os nomes padrão.  
  
7.  Na caixa de **Classe Base** , `COlePropertyPage`selecione.  
  
8.  Na caixa de **ID de Diálogo** , **IDD\_PROPPAGE\_NEWPAGE**selecione.  
  
9. Clique em **Concluir** para criar a classe.  
  
 Para permitir o acesso de usuário de controle a essa nova página de propriedades, faça as seguintes alterações na seção macro de IDs de página de propriedades de controle \(localizada no arquivo de implementação do controle\):  
  
 [!code-cpp[NVC_MFC_AxUI#32](../mfc/codesnippet/CPP/mfc-activex-controls-adding-another-custom-property-page_1.cpp)]  
  
 Observe que você deve aumentar o segundo parâmetro de macro de `BEGIN_PROPPAGEIDS` \(\) a contagem de página de propriedades de 1 a 2.  
  
 Você também deve modificar o arquivo do arquivo de implementação de controle \(.CPP\) para incluir o cabeçalho \(. H\) arquivo da nova classe da página de propriedades.  
  
 A próxima etapa envolve criar dois novos recursos de cadeia de caracteres que fornecer um nome de tipo e uma legenda para a nova página de propriedades.  
  
#### Para adicionar novos recursos de cadeia de caracteres para uma página de propriedades  
  
1.  Com o projeto de controle, abra a exibição aberta de recursos.  
  
2.  Clique duas vezes na pasta de **Tabela de Cadeias de Caracteres** e clique duas vezes no recurso existente da tabela de cadeia de caracteres ao qual você deseja adicionar uma cadeia de caracteres.  
  
     Isso abre a tabela de cadeia de caracteres em uma janela.  
  
3.  Selecione a linha em branco ao final da tabela de cadeia de caracteres e digite o texto, a legenda, de cadeia de caracteres: por exemplo, “página de propriedades adicionais.”  
  
     Isso abre uma página de **String Properties** que mostra **Legenda** e caixas de **ID** .  A caixa de **Legenda** contém a cadeia de caracteres que você digitou.  
  
4.  Na caixa de **ID** , selecione ou digite uma ID para a cadeia de caracteres.  Pressione enter quando você terminar.  
  
     Este exemplo usa **IDS\_SAMPLE\_ADDPAGE** para o nome do tipo da nova página de propriedades.  
  
5.  Repita **IDS\_SAMPLE\_ADDPPG\_CAPTION** de utilização das etapas 3 e 4 para o ID “e a página de propriedades adicionais” para a legenda.  
  
6.  No arquivo de .CPP de sua nova classe da página de propriedades \(neste exemplo, `CAddtlPropPage`\) modificar `CAddtlPropPage::CAddtlPropPageFactory::UpdateRegistry` de forma que IDS\_SAMPLE\_ADDPAGE é passado por [AfxOleRegisterPropertyPageClass](../Topic/AfxOleRegisterPropertyPageClass.md), como no exemplo a seguir:  
  
     [!code-cpp[NVC_MFC_AxUI#33](../mfc/codesnippet/CPP/mfc-activex-controls-adding-another-custom-property-page_2.cpp)]  
  
7.  Modifique o construtor de `CAddtlPropPage` de forma que **IDS\_SAMPLE\_ADDPPG\_CAPTION** é passado para o construtor de `COlePropertyPage` , como segue:  
  
     [!code-cpp[NVC_MFC_AxUI#34](../mfc/codesnippet/CPP/mfc-activex-controls-adding-another-custom-property-page_3.cpp)]  
  
 Depois que você fez a recriação de alterações necessárias para seu projeto e usa o contêiner de teste para testar a nova página de propriedades.  Consulte [Propriedades e eventos de teste com contêineres de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter mais informações sobre como acessar o contêiner de teste.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)