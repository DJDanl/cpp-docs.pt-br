---
title: "Instru&#231;&#245;es passo a passo: criando um aplicativo da faixa de op&#231;&#245;es usando MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "criando um aplicativo de faixa de opções (MFC)"
  - "aplicativo de faixa de opções, criando (MFC)"
ms.assetid: e61393e2-1d6b-4594-a7ce-157d3d1b0d9f
caps.latest.revision: 21
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando um aplicativo da faixa de op&#231;&#245;es usando MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo mostra como usar o **Assistente para Aplicativo do MFC** para criar um aplicativo que tenha uma faixa de opções por padrão.  Depois, você pode expandir a faixa de opções adicionando uma categoria de faixa de opções **Personalizado** que tem um painel de faixa de opções **Favoritos** e, em seguida, adicionando os comandos mais usados ao painel.  
  
## Pré-requisitos  
 Este passo a passo pressupõe que você tenha definido [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] para usar **Configurações Gerais de Desenvolvimento**.  Se você estiver usando configurações diferentes, alguns dos elementos da interface do usuário \(UI\) mencionados nas instruções talvez não sejam exibidos.  Para obter informações sobre como alterar configurações, consulte [How to: Reset Your Settings](http://msdn.microsoft.com/pt-br/c95c51be-e609-4769-abba-65e6beedec76).  
  
### Para criar um aplicativo do MFC que tenha uma faixa de opções  
  
1.  Use o **Assistente para Aplicativo do MFC** para criar um aplicativo do MFC que tenha uma faixa de opções.  Para executar o assistente, no menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.  
  
2.  Na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C\+\+** em **Modelos Instalados**, selecione **MFC** e **Aplicativo do MFC**.  Digite um nome para o projeto. Por exemplo, `MFCRibbonApp`e, em seguida, clique em **OK**.  
  
3.  Na primeira página do **Assistente para Aplicativo do MFC**, clique em **Avançar**.  
  
4.  Na página **Tipo de Aplicativo**, em **Estilo visual e cores**, selecione **Office 2007 \(Tema Azul\)**.  Deixe as outras configurações como estão.  Clique em **Avançar**.  
  
5.  Na página **Suporte de Documento Composto**, verifique se **Nenhum** está selecionado e, em seguida, clique em **Próximo**.  
  
6.  Na página **Propriedades do Modelo de Documento**, na caixa **Extensão do Arquivo**, digite uma extensão de nome de arquivo para documentos criados por esse aplicativo. Por exemplo, `mfcrbnapp`.  Clique em **Avançar**.  
  
7.  Na página **Suporte de Banco de Dados**, verifique se **Nenhum** está selecionado e, em seguida, clique em **Próximo**.  
  
8.  Na página **Recursos de Interface do Usuário**, verifique se **Usar uma faixa de opções** está selecionado.  Clique em **Avançar**.  
  
9. Por padrão, o **Assistente para Aplicativo do MFC** adiciona suporte para vários painéis de encaixe.  Como este passo a passo aborda apenas a faixa de opções, é possível remover essas opções do aplicativo.  Na página **Recursos Avançados**, desmarque todas as opções.  Clique em **Avançar**.  
  
10. Na página **Classes Geradas**, clique em **Concluir** para criar o aplicativo do MFC.  
  
11. Para verificar se o aplicativo foi criado com êxito, compile e o execute.  Para compilar o aplicativo, no menu **Compilar**, clique em **Compilar Solução**.  Se o aplicativo for compilado com êxito, execute\-o clicando em **Iniciar Depuração** no menu **Depurar**.  
  
     O assistente cria automaticamente uma faixa de opções que tem uma categoria de faixa de opções chamada **Página Inicial**.  Esta faixa contém três painéis de faixa de opções, chamados de **Área de Transferência**, **Exibir** e **Janela**.  
  
### Para adicionar uma categoria e um painel à faixa de opções  
  
1.  Para abrir o recurso da faixa de opções criado pelo assistente, no menu **Exibir**, aponte para **Outras Janelas** e, em seguida, clique em **Modo de Exibição de Recursos**.  Em **Modo de Exibição de Recursos**, clique em **Faixa de Opções** e, em seguida, clique duas vezes em **IDR\_RIBBON**.  
  
2.  Primeiro, adicione uma categoria personalizada à faixa de opções clicando duas vezes em **Categoria** na **Caixa de Ferramentas**.  
  
     Uma categoria com a legenda **Categoria1** é criada.  Por padrão, a categoria contém um painel.  
  
     Clique com o botão direito do mouse em **Categoria1** e clique em **Propriedades**.  Na janela **Propriedades**, altere **Legenda** para `Personalizada`.  
  
     As propriedades **Imagens Grandes** e **Imagens Pequenas** especificam os bitmaps usados como ícones para os elementos da faixa de opções nessa categoria.  Como a criação de bitmaps personalizados vai além do escopo deste passo a passo, basta reutilizar os bitmaps criados pelo assistente.  Bitmaps pequenos têm 16 pixels por 16 pixels.  Para imagens pequenas, use os bitmaps acessados pelo ID do recurso IDB\_FILESMALL.  Bitmaps grandes têm 32 pixels por 32 pixels.  Para imagens grandes, use os bitmaps acessados pelo ID do recurso IDB\_FILELARGE.  
  
    > [!NOTE]
    >  Em monitores HDPI \(High Dots Per Inch, Muitos pontos por polegada\), as versões HDPI das imagens são usadas automaticamente.  
  
3.  Em seguida, personalize o painel.  Os painéis são usados para agrupar itens logicamente relacionados uns aos outros.  Por exemplo, na guia **Página Inicial** deste aplicativo, os comandos **Recortar**, **Copiar** e **Colar** estão todos localizados no painel **Área de Transferência**.  Para personalizar o painel, clique com o botão direito do mouse em **Painel1** e, em seguida, clique em **Propriedades**.  Na janela **Propriedades**, altere **Legenda** para `Favoritos`.  
  
     É possível especificar o **Índice de Imagem** para o painel.  Esse número especifica o ícone que será exibido se o painel da faixa de opções for adicionado à **Barra de Ferramentas de Acesso Rápido**.  O ícone não é exibido no painel da faixa de opções propriamente dito.  
  
4.  Para verificar se a categoria e o painel da faixa de opções foram criados com êxito, visualize o controle da faixa de opções.  Na **Barra de Ferramentas do Editor da Barra de Ferramentas**, clique no botão **Faixa de Opções de Teste**.  Uma guia **Personalizar** e um painel **Favoritos** devem ser exibidos na faixa de opções.  
  
### Para adicionar elementos aos painéis da faixa de opções  
  
1.  Para adicionar elementos ao painel criado no procedimento anterior, arraste os controles da seção **Editor da Faixa de Opções** da **Caixa de Ferramentas** para o painel no modo de exibição de Design.  
  
2.  Primeiro, adicione um botão **Imprimir**.  O botão **Imprimir** terá um submenu contendo um comando **Impressão Rápida** que imprime usando a impressora padrão.  Esses dois comandos já estão definidos para esse aplicativo.  Eles estão localizados no menu do aplicativo.  
  
     Para criar o botão **Imprimir**, arraste uma ferramenta Botão para o painel.  
  
     Na janela **Propriedades**, altere a propriedade **ID** para **ID\_FILE\_PRINT**, que já deve estar definida.  Altere **Legenda** para `Imprimir`.  Altere **Índice de Imagem** para `4`.  
  
     Para criar o botão **Impressão Rápida**, clique na coluna de valor da propriedade próxima de **Itens de Menu**e, em seguida, clique nas reticências \(**...**\).  No **Editor de Itens**, clique no botão **Adicionar** sem rótulo para criar um item de menu.  Na janela **Propriedades**, altere **Legenda** para `Impressão Rápida`, **ID** para `ID_FILE_PRINT_DIRECT` e **Imagem** para `5`.  A propriedade image especifica o ícone de Impressão Rápida no recurso de bitmap IDB\_FILESMALL.  
  
3.  Para verificar se os botões foram adicionados ao painel da faixa de opções, compile e execute o aplicativo.  Para compilar o aplicativo, no menu **Compilar**, clique em **Compilar Solução**.  Se o aplicativo for compilado com êxito, execute\-o clicando em **Iniciar Depuração** no menu **Depurar**.  O botão **Imprimir** e a caixa de combinação no painel **Favoritos** da guia **Personalizado** na faixa de opções devem ser exibidos.  
  
## Próximas etapas  
 [Como personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)  
  
 [Como personalizar o botão do aplicativo](../mfc/how-to-customize-the-application-button.md)  
  
 Para exemplos de ponta a ponta, consulte [Exemplos \(MFC Feature Pack\)](../top/visual-cpp-samples.md).  
  
## Consulte também  
 [Explicações Passo\-a\-passo](../mfc/walkthroughs-mfc.md)   
 [Exemplos \(MFC Feature Pack\)](../top/visual-cpp-samples.md)