---
title: "Imprimir arquitetura de visualiza&#231;&#227;o | Microsoft Docs"
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
  - "visualizando a impressão"
  - "visualizar impressão, arquitetura"
  - "visualizar impressão, modificações em MFC"
  - "visualizar impressão, process"
  - "imprimindo [MFC], visualizar impressão"
ms.assetid: 0efc87e6-ff8d-43c5-9d72-9b729a169115
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Imprimir arquitetura de visualiza&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como a estrutura de MFC implementa a funcionalidade de visualização da impressão.  Os tópicos abordados incluem:  
  
-   [Processo de visualização de impressão](#_core_the_print_preview_process)  
  
-   [Visualizar impressão de alteração](#_core_modifying_print_preview)  
  
 A visualização de impressão é um pouco diferente da ótica e visualização de impressão porque, em vez de diretamente desenhar uma imagem em um dispositivo, o aplicativo deve simular a impressora que usa a tela.  Para acomodar isso, a biblioteca de classes do Microsoft define uma classe \(\) não documentado especial derivada de [CDC Class](../Topic/CDC%20Class.md), **CPreviewDC**chamado.  Todos os objetos de `CDC` contêm dois contextos de dispositivo, mas geralmente são idênticos.  Em um objeto de **CPreviewDC** , são diferentes: o primeiro representa a impressora que está sendo simulada, e o segundo representa a tela no qual a saída são exibidas na verdade.  
  
##  <a name="_core_the_print_preview_process"></a> O processo de visualização de impressão  
 Quando o usuário seleciona o comando de visualização de impressão no menu de **Arquivo** , a estrutura cria um objeto de **CPreviewDC** .  Sempre que o aplicativo executa uma operação que define uma característica de contexto do dispositivo de impressora, a estrutura também executa uma operação semelhante no contexto do dispositivo da tela.  Por exemplo, se o seu aplicativo selecionar uma fonte para imprimir, a estrutura selecionar uma fonte para a visualização que simula ótica a fonte da impressora.  Sempre que o aplicativo enviaria saída para a impressora, em vez da estrutura envia a saída à tela.  
  
 A visualização de impressão também difere de impressão na ordem e cada uma desenha as páginas de um documento.  Durante a impressão, a estrutura continua um loop de impressão até que algum intervalo de páginas seja renderizado.  Durante a visualização de impressão, uma ou duas páginas são exibidas a qualquer momento, e o aplicativo espera; nenhuma página adicional é exibida até que o usuário responder.  Durante a visualização de impressão, o aplicativo deve também responder a mensagens de `WM_PAINT` , como faz durante a visualização ótica comum.  
  
 A função de [CView::OnPreparePrinting](../Topic/CView::OnPreparePrinting.md) será chamada quando o modo de visualização é chamado, assim como é no início de um trabalho de cópia.  A estrutura de [Estrutura de CPrintInfo](../mfc/reference/cprintinfo-structure.md) passada para a função contém vários membros cujos valores você pode definir para ajustar certas características da operação de visualização da impressão.  Por exemplo, você pode definir o membro de **m\_nNumPreviewPages** para especificar se você deseja visualizar o documento no modo de uma página ou de duas página.  
  
##  <a name="_core_modifying_print_preview"></a> Visualizar impressão de alteração  
 Você pode modificar o comportamento e a aparência de visualização de impressão em várias maneiras um pouco esforço.  Por exemplo, você pode, entre outros coisas:  
  
-   Faz com que a janela de visualização de impressão exibe uma barra de rolagem para facilitar o acesso a qualquer página do documento.  
  
-   Faz com que a visualização de impressão manter a posição do usuário no documento começando sua exibição na página atual.  
  
-   Causar a inicialização diferente a ser executada para a visualização de impressão e a impressão.  
  
-   Causar a visualização de impressão para exibir números de página em seus próprios formatos.  
  
 Se você souber quanto tempo o documento é e chama `SetMaxPage` com o valor apropriado, a estrutura pode usar essas informações no modo de visualização bem como durante a impressão.  Uma vez que a estrutura souber o tamanho do documento, pode fornecer a janela de visualização com uma barra de rolagem, permitindo que o usuário página para a frente e para trás no documento em modo de visualização.  Se você não definiu o tamanho do documento, a estrutura não pode posicionar a caixa de rolagem para indicar a posição atual, a estrutura não adiciona uma barra de rolagem.  Nesse caso, o usuário deve usar os botões da próxima página e de página anterior na barra de controle da janela de visualização para chamar através do documento.  
  
 Para a visualização de impressão, talvez seja útil atribuir um valor ao membro de `m_nCurPage` de `CPrintInfo`, mesmo que você nunca faça\-o de impressão comum.  Durante a impressão comum, esse membro representa as informações de estrutura a sua classe da exibição.  Isso é semelhante à estrutura informa a exibição que a página deve ser impressa.  
  
 Por outro lado, quando o modo de visualização de impressão é iniciado, o membro de `m_nCurPage` leva as informações na direção oposta: exibição à estrutura.  A estrutura usa o valor desse membro para determinar qual a página deve ser visualizada primeiro.  O valor padrão desse membro é 1, o que a primeira página do documento é exibida inicialmente.  Você pode substituir `OnPreparePrinting` para definir esse membro ao número da página que está sendo exibida no comando de visualização de impressão foi chamado.  Dessa forma, o aplicativo mantiver a posição atual do usuário ao mover de modo de exibição normal para o modo de visualização da impressão.  
  
 Talvez você queira `OnPreparePrinting` para executar a inicialização diferente dependendo se será chamada para um trabalho de cópia ou para a visualização de impressão.  Você pode determinar esse revisando a variável de membro de **m\_bPreview** na estrutura de `CPrintInfo` .  Esse membro é definido como **Verdadeiro** quando a visualização de impressão é invocado.  
  
 A estrutura de `CPrintInfo` também contém um membro **m\_strPageDesc**nomeado, que é usado para formatar as cadeias de caracteres exibidas na parte inferior da tela nos modos de página única e de várias páginas.  Por padrão essas cadeias de caracteres são a página “ *n*” formulário e “páginas *em* \- *m*”, mas você pode alterar **m\_strPageDesc** de dentro de `OnPreparePrinting` e definir as cadeias de caracteres para algo mais elaborado.  Consulte [Estrutura de CPrintInfo](../mfc/reference/cprintinfo-structure.md)*na referência de MFC* para obter mais informações.  
  
## Consulte também  
 [Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)   
 [Imprimindo](../mfc/printing.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [CDC Class](../Topic/CDC%20Class.md)