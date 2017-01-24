---
title: "Editando partes de uma imagem (editor de imagens para &#237;cones) | Microsoft Docs"
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
  - "C++"
helpviewer_keywords: 
  - "Área de Transferência [C++], colando"
  - "gráficos [C++], edição"
  - "Editor de imagem [C++], editando imagens"
  - "imagens [C++], copiando partes selecionadas"
  - "imagens [C++], excluindo partes selecionadas"
  - "imagens [C++], arrastando e replicando partes selecionadas"
  - "imagens [C++], edição"
  - "imagens [C++], movendo partes selecionadas"
  - "imagens [C++], colando em"
ms.assetid: ff4f5fef-71a4-4fd8-825e-049399fed391
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editando partes de uma imagem (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode executar operações padrões de edição — recortar, copiar, desmarcando, e se movendo — em [seleção](../mfc/selecting-an-area-of-an-image-image-editor-for-icons.md), se a seleção é a imagem inteira ou apenas uma parte de ela.  Porque o editor de imagem usa as janelas área de transferência, você pode transferir imagens entre o editor de imagem e outros aplicativos do windows.  
  
 Além de isso, você pode redimensionar a seleção, se inclui a imagem inteira ou apenas uma parte.  
  
### Para recortar a seleção atual e mova\-a para a área de transferência  
  
1.  Clique **Recortar** no menu de **Editar** .  
  
### para copiar a seleção  
  
1.  Posicione o ponteiro na borda de seleção ou em qualquer lugar em ele exceto as alças de dimensionamento.  
  
2.  Manter pressionada a tecla de **CTRL** conforme você arrasta a seleção para um novo local.  A área de seleção original é inalterado.  
  
3.  Para copiar a seleção na imagem em sua localidade atual, clique fora do cursor de seleção.  
  
### Cole o conteúdo da área de transferência em uma imagem  
  
1.  Em o menu de **Editar** , escolha **Colar**.  
  
     O conteúdo da área de transferência, rodeados pela borda de seleção, aparecem no canto superior esquerdo do painel.  
  
2.  Posicione o ponteiro na borda de seleção e arraste a imagem para o local desejado na imagem.  
  
3.  Para ancorar a imagem no seu novo local, clique fora da borda de seleção.  
  
### Para excluir a seleção atual sem mova\-a para a área de transferência  
  
1.  Em o menu de **Editar** , escolha **Excluir**.  
  
     A área original de seleção é preenchida com a cor do plano de fundo atual.  
  
    > [!NOTE]
    >  Você pode acessar recortar, copiar, excluir e colar, comandos clicando com o botão direito na janela de exibição de recurso.  
  
### para mover a seleção  
  
1.  Posicione o ponteiro na borda de seleção ou em qualquer lugar em ele exceto as alças de dimensionamento.  
  
2.  Arraste a seleção para o novo local.  
  
3.  Para ancorar a seleção na imagem no seu novo local, clique fora da borda de seleção.  
  
 Para obter mais informações sobre o desenho com uma seleção, consulte [Criando um desenho personalizado](../Topic/Creating%20a%20Custom%20Brush%20\(Image%20Editor%20for%20Icons\).md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, por favor consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md)*na guia do desenvolvedor do .NET Framework.* Para obter informações sobre manualmente de adicionar arquivos de recurso para projetos gerenciados, acessando recursos, exibindo recursos estáticos, e atribuindo a recursos cadeias de caracteres para propriedades, consulte [passo a passo: Localizando windows forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../mfc/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)