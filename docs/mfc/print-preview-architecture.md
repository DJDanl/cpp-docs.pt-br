---
title: Arquitetura de visualização de impressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- print preview [MFC], process
- previewing printing
- print preview [MFC], architecture
- printing [MFC], print preview
- print preview [MFC], modifications to MFC
ms.assetid: 0efc87e6-ff8d-43c5-9d72-9b729a169115
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7e89349811b2d340357e003ad31394cea13eb36b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417575"
---
# <a name="print-preview-architecture"></a>Imprimir arquitetura de visualização

Este artigo explica como a estrutura MFC implementa a funcionalidade de visualização de impressão. Os tópicos abordados incluem:

- [Processo de visualização de impressão](#_core_the_print_preview_process)

- [Modificando a visualização de impressão](#_core_modifying_print_preview)

Visualização de impressão é um pouco diferente da impressão e exibição de tela porque, em vez de desenhar diretamente uma imagem em um dispositivo, o aplicativo deve simular a impressora usando a tela. Para acomodar isso, a biblioteca Microsoft Foundation Class define uma classe (não documentada) especial, derivada de [classe CDC](../mfc/reference/cdc-class.md), chamado `CPreviewDC`. Todos os `CDC` objetos contêm dois contextos de dispositivo, mas normalmente eles são idênticos. Em um `CPreviewDC` do objeto, eles são diferentes: o primeiro representa a impressora que está sendo simulada e o segundo representa a tela em que a saída, na verdade, é exibida.

##  <a name="_core_the_print_preview_process"></a> O processo de visualização de impressão

Quando o usuário seleciona o comando Visualizar impressão do **arquivo** menu, o framework cria uma `CPreviewDC` objeto. Sempre que o aplicativo executa uma operação que define uma característica de contexto do dispositivo de impressora, a estrutura também realiza uma operação semelhante no contexto de dispositivo de tela. Por exemplo, se seu aplicativo seleciona uma fonte para impressão, o framework seleciona uma fonte para a exibição de tela que simula a fonte da impressora. Sempre que seu aplicativo enviará a saída para a impressora, a estrutura em vez disso, envia a saída para a tela.

Visualização de impressão também é diferente da impressão na ordem em que cada Desenha as páginas de um documento. Durante a impressão, o framework continua um loop de impressão até que um determinado intervalo de páginas foi renderizado. Durante a visualização de impressão, uma ou duas páginas são exibidas a qualquer momento e, em seguida, o aplicativo aguarda; Não há mais páginas são exibidas até que o usuário responda. Durante a visualização de impressão, o aplicativo também deve responder às mensagens WM_PAINT, assim como faz durante a exibição de tela comum.

O [CView::OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) função é chamada quando o modo de visualização é invocado, assim ele está no início de um trabalho de impressão. O [estrutura CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura passada para a função contém vários membros cujos valores você pode definir para ajustar a certas características da operação de visualização de impressão. Por exemplo, você pode definir as *m_nNumPreviewPages* membro para especificar se deseja visualizar o documento no modo de uma página ou duas páginas.

##  <a name="_core_modifying_print_preview"></a> Modificando a visualização de impressão

Você pode modificar o comportamento e aparência da visualização de impressão em um número de maneiras com bastante facilidade. Por exemplo, você pode, entre outras coisas:

- Fazer com que a janela de visualização de impressão exibir uma barra de rolagem para facilitar o acesso a qualquer página do documento.

- Fazer com que a visualização de impressão manter a posição do usuário no documento, começando sua exibição na página atual.

- Fazer com que a inicialização a ser executada para impressão e visualização de impressão diferente.

- Fazer com que a visualização de impressão exibir números de página em seus próprios formatos.

Se você souber quanto tempo é o documento e chamar `SetMaxPage` com o valor apropriado, o framework pode usar essas informações no modo de visualização, bem como durante a impressão. Depois que a estrutura sabe o tamanho do documento, ele pode fornecer a janela de visualização com uma barra, permitindo que o usuário para trás e navegar pelas páginas o documento no modo de visualização de rolagem. Se você ainda não tiver definido o tamanho do documento, a estrutura não é possível posicionar a caixa de rolagem para indicar a posição atual, portanto, a estrutura não adiciona uma barra de rolagem. Nesse caso, o usuário deve usar os botões de página anterior e próxima página na barra de controle da janela de visualização para ver o documento.

Para visualização de impressão, você pode ser útil para atribuir um valor para o *m_nCurPage* membro `CPrintInfo`, mesmo que você nunca faria isso para impressão comum. Durante a impressão comum, esse membro transporta informações do framework à sua classe de exibição. Isso é como o framework informa o modo de exibição qual página deve ser impressa.

Por outro lado, quando o modo de visualização de impressão é iniciado, o *m_nCurPage* membro carrega as informações na direção oposta: a exibição para a estrutura. A estrutura usa o valor desse membro para determinar qual página deve ser visualizada pela primeira vez. O valor padrão desse membro é 1, portanto, a primeira página do documento é exibida inicialmente. Você pode substituir `OnPreparePrinting` para definir esse membro como o número da página que está sendo exibido no momento em que o comando Visualizar impressão foi invocado. Dessa forma, o aplicativo mantém a posição do usuário atual ao mover de modo de exibição normal para o modo de visualização de impressão.

Às vezes você pode desejar `OnPreparePrinting` para executar a inicialização diferente, dependendo se ele for chamado para um trabalho de impressão ou para a visualização de impressão. Você pode determinar isso examinando a *m_bPreview* variável de membro no `CPrintInfo` estrutura. Esse membro é definido como **verdadeira** quando a visualização de impressão é invocada.

O `CPrintInfo` estrutura também contém um membro chamado *m_strPageDesc*, que é usado para formatar as cadeias de caracteres exibidas na parte inferior da tela em modos de página única e várias páginas. Por padrão essas cadeias de caracteres estão no formato "página *n*" e "páginas *n* - *m*,", mas você pode modificar *m_strPageDesc* de dentro de `OnPreparePrinting` e defina as cadeias de caracteres para algo mais elaborado. Ver [estrutura CPrintInfo](../mfc/reference/cprintinfo-structure.md) na *referência da MFC* para obter mais informações.

## <a name="see-also"></a>Consulte também

[Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)<br/>
[Imprimindo](../mfc/printing.md)<br/>
[Classe CView](../mfc/reference/cview-class.md)<br/>
[Classe CDC](../mfc/reference/cdc-class.md)
