---
title: 'Passo a passo: Criando um aplicativo de faixa de opções usando MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ribbon application, creating (MFC)
- creating a ribbon aplication (MFC)
ms.assetid: e61393e2-1d6b-4594-a7ce-157d3d1b0d9f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3b1dada4601b7e20dd4e05af861d48099ce2391c
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36950974"
---
# <a name="walkthrough-creating-a-ribbon-application-by-using-mfc"></a>Instruções passo a passo: criando um aplicativo da faixa de opções usando MFC
Este passo a passo mostra como usar o **Assistente de aplicativo MFC** para criar um aplicativo que tem uma faixa de opções por padrão. Em seguida, você pode expandir a faixa de opções, adicionando um **personalizado** categoria de faixa de opções que tem um **Favoritos** painel e, em seguida, adicionar alguns comandos no painel usados com frequência de faixa de opções.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Este passo a passo pressupõe que você definiu [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usar **configurações gerais de desenvolvimento**. Se você estiver usando configurações diferentes, alguns dos elementos da interface do usuário (UI) mencionados nas instruções talvez não sejam exibidos. Para obter informações sobre como alterar as configurações, consulte [como: redefinir configurações do seu](http://msdn.microsoft.com/en-us/c95c51be-e609-4769-abba-65e6beedec76).  
  
### <a name="to-create-an-mfc-application-that-has-a-ribbon"></a>Para criar um aplicativo do MFC que tenha uma faixa de opções  
  
1.  Use o **Assistente de aplicativo MFC** para criar um aplicativo MFC que tem uma faixa de opções. Para executar o assistente, no **arquivo** , aponte para **novo**e, em seguida, clique em **projeto**.  
  
2.  No **novo projeto** caixa de diálogo caixa, expanda o **Visual C++** nó **modelos instalados**, selecione **MFC**e, em seguida, selecione  **Aplicativo MFC**. Digite um nome para o projeto, por exemplo, *MFCRibbonApp*e, em seguida, clique em **Okey**.  
  
3.  Na primeira página do **Assistente de aplicativo MFC**, clique em **próximo**.  
  
4.  Sobre o **tipo de aplicativo** página em **cores e o estilo Visual**, selecione **Office 2007 (tema azul)**. Deixe as outras configurações como estão. Clique em **Avançar**.  
  
5.  Sobre o **suporte a documentos compostos** página, certifique-se de que **nenhum** está selecionado e, em seguida, clique em **próximo**.  
  
6.  No **propriedades do modelo de documento** página, o **extensão de arquivo** , digite uma extensão de nome de arquivo para documentos que esse aplicativo cria, por exemplo, *mfcrbnapp*. Clique em **Avançar**.  
  
7.  No **suporte do banco de dados** página, certifique-se de que **nenhum** está selecionado e, em seguida, clique em **próximo**.  
  
8.  No **recursos de Interface do usuário** página, certifique-se de que **usar uma faixa de opções** está selecionado. Clique em **Avançar**.  
  
9. Por padrão, o **Assistente de aplicativo MFC** adiciona suporte para vários painéis de encaixe. Como este passo a passo aborda apenas a faixa de opções, é possível remover essas opções do aplicativo. Sobre o **recursos avançados** página, desmarque todas as opções. Clique em **Avançar**.  
  
10. Sobre o **Classes geradas pelo** , clique em **concluir** para criar o aplicativo do MFC.  
  
11. Para verificar se o aplicativo foi criado com êxito, compile e o execute. Para criar o aplicativo, no **criar** menu, clique em **compilar solução**. Se o aplicativo foi criado com êxito, execute-o clicando em **iniciar depuração** no **depurar** menu.  
  
     O assistente cria automaticamente uma faixa de opções que tem uma categoria de faixa de opções chamado **início**. Esta faixa de opções contém três painéis de faixa de opções, que são nomeados **área de transferência**, **exibição**, e **janela**.  
  
### <a name="to-add-a-category-and-panel-to-the-ribbon"></a>Para adicionar uma categoria e um painel à faixa de opções  
  
1.  Para abrir o recurso de faixa de opções que o assistente criou, no **exibição** , aponte para **outras janelas** e, em seguida, clique em **exibição recursos**. Em **exibição recursos**, clique em **faixa de opções** e, em seguida, clique duas vezes em **IDR_RIBBON**.  
  
2.  Primeiro, adicione uma categoria personalizada à faixa de opções, clique duas vezes **categoria** no **caixa de ferramentas**.  
  
     Uma categoria que tem a legenda **Categoria1** é criado. Por padrão, a categoria contém um painel.  
  
     Clique com botão direito **Categoria1** e, em seguida, clique em **propriedades**. No **propriedades** janela, alteração **legenda** para *personalizado*.  
  
     O **imagens grandes** e **imagens pequenas** propriedades especificam os bitmaps que são usados como ícones para os elementos da faixa de opções nessa categoria. Como a criação de bitmaps personalizados vai além do escopo deste passo a passo, basta reutilizar os bitmaps criados pelo assistente. Bitmaps pequenos têm 16 pixels por 16 pixels. Para imagens pequenas, use os bitmaps acessados pelo ID do recurso IDB_FILESMALL. Bitmaps grandes têm 32 pixels por 32 pixels. Para imagens grandes, use os bitmaps acessados pelo ID do recurso IDB_FILELARGE.  
  
    > [!NOTE]
    >  Em monitores HDPI (High Dots Per Inch, Muitos pontos por polegada), as versões HDPI das imagens são usadas automaticamente.  
  
3.  Em seguida, personalize o painel. Os painéis são usados para agrupar itens logicamente relacionados uns aos outros. Por exemplo, no **início** guia deste aplicativo, o **Recortar**, **cópia**, e **colar** comandos estão localizados no  **Área de transferência** painel. Para personalizar o painel, clique com botão direito **Panel1** e, em seguida, clique em **propriedades**. No **propriedades** janela, alteração **legenda** para *Favoritos*.  
  
     Você pode especificar o **índice de imagem** do painel. Esse número Especifica o ícone que será exibido se o painel de faixa de opções é adicionado para o **ferramentas de acesso rápido**. O ícone não é exibido no painel da faixa de opções propriamente dito.  
  
4.  Para verificar se a categoria e o painel da faixa de opções foram criados com êxito, visualize o controle da faixa de opções. Sobre o **barra de ferramentas do Editor de faixa de opções**, clique no **faixa de opções de teste** botão. Um **personalizado** guia e **Favoritos** painel deve ser exibido na faixa de opções.  
  
### <a name="to-add-elements-to-the-ribbon-panels"></a>Para adicionar elementos aos painéis da faixa de opções  
  
1.  Para adicionar elementos ao painel que você criou no procedimento anterior, arraste os controles do **Editor da faixa de opções** seção o **caixa de ferramentas** ao painel no modo de exibição de design.  
  
2.  Primeiro, adicione um **impressão** botão. O **impressão** botão terá um submenu que contém um **impressão rápida** comando imprime usando a impressora padrão. Esses dois comandos já estão definidos para esse aplicativo. Eles estão localizados no menu do aplicativo.  
  
     Para criar o **impressão** botão, arraste uma ferramenta do botão no painel.  
  
     No **propriedades** janela, altere o **ID** propriedade **ID_FILE_PRINT**, que já deve ser definido. Alterar **legenda** para *impressão*. Alterar **índice da imagem** para *4*.  
  
     Para criar o **impressão rápida** , clique em coluna valor da propriedade lado **itens de Menu**e, em seguida, clique no botão de reticências (**...** ). No **itens Editor**, clique em sem o rótulo **adicionar** botão para criar um item de menu. No **propriedades** janela, alteração **legenda** para *impressão rápida*, **ID** para *ID_FILE_PRINT_DIRECT*, e **imagem** para *5*. A propriedade image especifica o ícone de Impressão Rápida no recurso de bitmap IDB_FILESMALL.  
  
3.  Para verificar se os botões foram adicionados ao painel da faixa de opções, compile e execute o aplicativo. Para criar o aplicativo, no **criar** menu, clique em **compilar solução**. Se o aplicativo foi criado com êxito, execute o aplicativo clicando **iniciar depuração** no **depurar** menu. O **impressão** botão e a caixa de combinação caixa o **Favoritos** painel o **personalizado** guia na faixa de opções deve ser exibido.  
  
## <a name="next-steps"></a>Próximas etapas  
 [Como personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)  
  
 [Como personalizar o botão Aplicativo](../mfc/how-to-customize-the-application-button.md)  
  
 Para obter exemplos de ponta a ponta, consulte [exemplos (MFC Feature Pack)](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Explicações passo a passo](../mfc/walkthroughs-mfc.md)   
 [Exemplos (MFC Feature Pack)](../visual-cpp-samples.md)

