---
title: "Arquitetura de visualização de impressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- print preview [MFC], process
- previewing printing
- print preview [MFC], architecture
- printing [MFC], print preview
- print preview [MFC], modifications to MFC
ms.assetid: 0efc87e6-ff8d-43c5-9d72-9b729a169115
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ffffa6c446487752974549f4a070cf8e86e91aea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="print-preview-architecture"></a>Imprimir arquitetura de visualização
Este artigo explica como o framework MFC implementa a funcionalidade de visualização de impressão. Os tópicos abordados incluem:  
  
-   [Processo de visualização de impressão](#_core_the_print_preview_process)  
  
-   [Modificando a visualização de impressão](#_core_modifying_print_preview)  
  
 Visualização de impressão é um pouco diferente de impressão e tela porque, em vez de desenho de uma imagem diretamente em um dispositivo, o aplicativo deve simular a impressora usando a tela. Para acomodar isso, a biblioteca Microsoft Foundation Class define uma classe de (não documentada) especial derivada [classe CDC](../mfc/reference/cdc-class.md), chamado **CPreviewDC**. Todos os `CDC` objetos contêm dois contextos de dispositivo, mas normalmente eles são idênticos. Em um **CPreviewDC** do objeto, eles são diferentes: a primeira representa a impressora que está sendo simulada e a segunda representa a tela em que a saída, na verdade, é exibida.  
  
##  <a name="_core_the_print_preview_process"></a>O processo de visualização de impressão  
 Quando o usuário seleciona o comando de visualização de impressão do **arquivo** a estrutura de menu, cria um **CPreviewDC** objeto. Sempre que o aplicativo executa uma operação que define uma característica do contexto de dispositivo de impressora, a estrutura também realiza uma operação semelhante no contexto de dispositivo de tela. Por exemplo, se seu aplicativo seleciona uma fonte para impressão, o framework seleciona uma fonte para a exibição de tela que simula a fonte da impressora. Sempre que seu aplicativo deve enviar a saída para a impressora, o framework em vez disso, envia a saída para a tela.  
  
 Visualização de impressão também é diferente da impressão na ordem em que cada Desenha as páginas de um documento. Durante a impressão, a estrutura continua um loop de impressão até que um determinado intervalo de páginas é processado. Durante a visualização de impressão, uma ou duas páginas são exibidas a qualquer momento, e, em seguida, o aplicativo espera; Não há mais páginas são exibidas até que o usuário responda. Durante a visualização de impressão, o aplicativo também deve responder às `WM_PAINT` mensagens, assim como acontece durante a exibição de tela comum.  
  
 O [CView::OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) função é chamada quando o modo de visualização é invocado, exatamente como ele está no início de um trabalho de impressão. O [estrutura CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura passada para a função contém vários membros cujos valores você pode definir para ajustar certas características da operação de visualização de impressão. Por exemplo, você pode definir o **m_nNumPreviewPages** membro para especificar se deseja visualizar o documento no modo de uma página ou em duas páginas.  
  
##  <a name="_core_modifying_print_preview"></a>Modificando a visualização de impressão  
 Você pode modificar o comportamento e aparência de visualização de impressão em um número de maneiras em vez disso, facilmente. Por exemplo, você pode, entre outras coisas:  
  
-   Fazer com que a janela de visualização de impressão exibir uma barra de rolagem para facilitar o acesso a qualquer página do documento.  
  
-   Fazer com que a visualização de impressão manter a posição do usuário no documento, começando sua exibição na página atual.  
  
-   Fazer com que a inicialização diferente a ser executada para impressão e visualização de impressão.  
  
-   Fazer com que a visualização de impressão exibir números de página em seus próprios formatos.  
  
 Se você souber quanto tempo o documento é e chamar `SetMaxPage` com o valor apropriado, a estrutura pode usar essas informações no modo de visualização, bem como durante a impressão. Depois que a estrutura conhece a duração do documento, ele pode fornecer a janela de visualização com uma barra, permitindo que o usuário e para trás da página no documento no modo de visualização de rolagem. Se você não definir o tamanho do documento, a estrutura não é possível posicionar a caixa de rolagem para indicar a posição atual, para que o framework não adiciona uma barra de rolagem. Nesse caso, o usuário deve usar os botões de página anterior e próxima página na barra de controle da janela de visualização para ver o documento.  
  
 Para visualização de impressão, você pode achar útil para atribuir um valor para o `m_nCurPage` membro `CPrintInfo`, mesmo que você nunca faria isso para impressão comum. Durante a impressão normal, esse membro contém informações da estrutura para sua classe de exibição. Isso é como o framework informa o modo de exibição que página deve ser impresso.  
  
 Por outro lado, quando o modo de visualização de impressão é iniciado, o `m_nCurPage` membro traz informações na direção oposta: do modo de exibição para a estrutura. A estrutura usa o valor desse membro para determinar qual página deve ser visualizada pela primeira vez. O valor padrão desse membro é 1, portanto, a primeira página do documento é exibida inicialmente. Você pode substituir `OnPreparePrinting` para definir esse membro como o número da página que está sendo exibido no momento em que o comando de visualização de impressão foi invocado. Dessa forma, o aplicativo mantém a posição do usuário atual ao mudar do modo de exibição normal para o modo Visualizar impressão.  
  
 Às vezes, convém `OnPreparePrinting` para executar inicialização diferente dependendo se ele é chamado de um trabalho de impressão ou de visualização de impressão. Isso pode ser determinado examinando a **m_bPreview** variável de membro no `CPrintInfo` estrutura. Esse membro é definido como **TRUE** quando a visualização de impressão é invocada.  
  
 O `CPrintInfo` estrutura também contém um membro chamado **m_strPageDesc**, que é usada para formatar as cadeias de caracteres exibidas na parte inferior da tela no modo de página única e de várias páginas. Por padrão, essas cadeias são no formato "página  *n* " e "páginas  *n*   -  *m*,", mas você pode modificar **m _ strPageDesc** na `OnPreparePrinting` e defina as cadeias de caracteres para algo mais sofisticadas. Consulte [estrutura CPrintInfo](../mfc/reference/cprintinfo-structure.md) no *referência MFC* para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)   
 [Impressão](../mfc/printing.md)   
 [Classe CView](../mfc/reference/cview-class.md)   
 [Classe CDC](../mfc/reference/cdc-class.md)
