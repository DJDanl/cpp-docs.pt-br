---
title: "Alterando a fonte de texto em uma imagem (editor de imagens para &#237;cones) | Microsoft Docs"
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
  - "C++"
helpviewer_keywords: 
  - "fontes, alterando em uma imagem"
ms.assetid: b8849d40-d401-4e06-808f-e615cb2bee3b
caps.latest.revision: 8
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando a fonte de texto em uma imagem (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O procedimento a seguir é um exemplo de como:  
  
-   Adicionar texto a um ícone em um aplicativo Windows  
  
-   Manipular a fonte do seu texto.  
  
### Para alterar a fonte do texto em uma imagem  
  
1.  Crie um aplicativo de formulários do Windows do C\+\+.  Para obter detalhes, consulte  [Criando um projeto de aplicativo do Windows](http://msdn.microsoft.com/pt-br/b2f93fed-c635-4705-8d0e-cf079a264efa).  O  [O modelo de aplicativo do Windows Forms](http://msdn.microsoft.com/pt-br/1babdebf-ab3f-4a64-a608-98499a5b9cea) adiciona um arquivo chamado app.ico ao seu projeto por padrão.  
  
2.  No Solution Explorer, clique duas vezes em app.ico o arquivo.  O  [Editor de imagens](../mfc/image-editor-for-icons.md) será aberto.  
  
3.  Do  **imagem** menu, selecione  **Ferramentas** e, em seguida, selecione  **Ferramenta de texto**.  O  [Caixa de diálogo Ferramenta de texto](../Topic/Text%20Tool%20Dialog%20Box%20\(Image%20Editor%20for%20Icons\).md) será exibido.  
  
4.  Na caixa de diálogo da ferramenta de texto, digite `C++` na área de texto vazia.  Esse texto será exibido em uma caixa redimensionável, localizada no canto superior esquerdo da app.ico, no Editor de imagem.  
  
5.  No Editor de imagem, arraste a caixa de redimensionável para o centro da app.ico, para melhorar a legibilidade do texto.  
  
6.  Na caixa de diálogo da ferramenta de texto, clique no  **fonte** botão.  O  [Caixa de diálogo fonte do texto ferramenta](../mfc/text-tool-font-dialog-box-image-editor-for-icons.md) será exibido.  
  
7.  Na caixa de diálogo fonte de ferramenta texto, selecione  **Times New Roman** da lista de fontes disponíveis listadas na  **fonte** caixa de listagem.  
  
8.  Selecione  **Bold** da lista de estilos de fontes disponíveis listadas na  **estilo de fonte** caixa de listagem.  
  
9. Selecione  **10** a partir da lista de disponíveis ponto tamanhos listados no  **tamanho** caixa de listagem.  
  
10. Clique no botão **OK**.  A caixa de diálogo de fonte do texto ferramenta será fechado e as novas configurações de fonte serão aplicadas ao texto.  
  
11. Clique no  **Fechar** botão na caixa de diálogo da ferramenta texto.  A caixa redimensionável ao redor de seu texto desaparecerão do Editor de imagem.  
  
## Consulte também  
 [Editando recursos gráficos](../mfc/editing-graphical-resources-image-editor-for-icons.md)   
 [Barra de ferramentas](../mfc/toolbar-image-editor-for-icons.md)