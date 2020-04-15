---
title: Imprimir arquitetura de visualização
ms.date: 11/04/2016
helpviewer_keywords:
- print preview [MFC], process
- previewing printing
- print preview [MFC], architecture
- printing [MFC], print preview
- print preview [MFC], modifications to MFC
ms.assetid: 0efc87e6-ff8d-43c5-9d72-9b729a169115
ms.openlocfilehash: 5943edc22cd48ed10d152f72624467ff87104b96
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375940"
---
# <a name="print-preview-architecture"></a>Imprimir arquitetura de visualização

Este artigo explica como a estrutura do MFC implementa a funcionalidade de visualização de impressão. Os tópicos abordados incluem:

- [Processo de visualização de impressão](#_core_the_print_preview_process)

- [Modificando a visualização de impressão](#_core_modifying_print_preview)

A visualização de impressão é um pouco diferente da exibição e impressão da tela porque, em vez de desenhar diretamente uma imagem em um dispositivo, o aplicativo deve simular a impressora usando a tela. Para acomodar isso, a Microsoft Foundation Class Library define uma classe especial `CPreviewDC`(não documentada) derivada do CDC [Class](../mfc/reference/cdc-class.md), chamado . Todos `CDC` os objetos contêm dois contextos de dispositivos, mas geralmente são idênticos. Em `CPreviewDC` um objeto, eles são diferentes: o primeiro representa a impressora sendo simulada, e a segunda representa a tela em que a saída é realmente exibida.

## <a name="the-print-preview-process"></a><a name="_core_the_print_preview_process"></a>O processo de visualização de impressão

Quando o usuário seleciona o comando Imprimir visualização `CPreviewDC` no menu **Arquivo,** a estrutura cria um objeto. Sempre que seu aplicativo executa uma operação que define uma característica do contexto do dispositivo da impressora, a estrutura também realiza uma operação semelhante no contexto do dispositivo de tela. Por exemplo, se o aplicativo selecionar uma fonte para impressão, a estrutura selecionará uma fonte para exibição de tela que simula a fonte da impressora. Sempre que seu aplicativo envia a saída para a impressora, a estrutura envia a saída para a tela.

A visualização de impressão também difere da impressão na ordem em que cada um desenha as páginas de um documento. Durante a impressão, a estrutura continua um loop de impressão até que uma certa gama de páginas tenha sido renderizada. Durante a visualização de impressão, uma ou duas páginas são exibidas a qualquer momento e, em seguida, o aplicativo aguarda; nenhuma outra página é exibida até que o usuário responda. Durante a visualização de impressão, o aplicativo também deve responder a WM_PAINT mensagens, assim como faz durante a exibição da tela comum.

A função [CView::OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) é chamada quando o modo de visualização é invocado, assim como é no início de um trabalho de impressão. A estrutura [cprintinfo passada](../mfc/reference/cprintinfo-structure.md) para a função contém vários membros cujos valores você pode definir para ajustar certas características da operação de visualização de impressão. Por exemplo, você pode definir o *m_nNumPreviewPages* membro para especificar se deseja visualizar o documento no modo de uma ou duas páginas.

## <a name="modifying-print-preview"></a><a name="_core_modifying_print_preview"></a>Modificando a visualização de impressão

Você pode modificar o comportamento e a aparência da visualização de impressão de várias maneiras facilmente. Por exemplo, você pode, entre outras coisas:

- Fazer com que a janela de visualização de impressão exiba uma barra de rolagem para fácil acesso a qualquer página do documento.

- Causar visualização de impressão para manter a posição do usuário no documento iniciando sua exibição na página atual.

- Causar uma inicialização diferente para visualização e impressão de impressão.

- Causar visualização de impressão para exibir números de página em seus próprios formatos.

Se você souber quanto tempo `SetMaxPage` o documento é e ligar com o valor apropriado, a estrutura pode usar essas informações no modo de visualização, bem como durante a impressão. Uma vez que a estrutura saiba o comprimento do documento, ele pode fornecer a janela de visualização com uma barra de rolagem, permitindo que o usuário page para frente e para trás através do documento no modo de visualização. Se você não tiver definido o comprimento do documento, a estrutura não poderá posicionar a caixa de rolagem para indicar a posição atual, de modo que a estrutura não adicione uma barra de rolagem. Neste caso, o usuário deve usar os botões Página Seguinte e Página Anterior na barra de controle da janela de visualização para página através do documento.

Para visualização de impressão, você pode achar útil atribuir `CPrintInfo`um valor ao *membro m_nCurPage,* mesmo que você nunca o faça para impressão comum. Durante a impressão ordinária, este membro carrega informações da estrutura para a sua classe de visualização. É assim que a estrutura informa a exibição de qual página deve ser impressa.

Em contrapartida, quando *o* modo de visualização de impressão é iniciado, o m_nCurPage membro carrega informações na direção oposta: da vista para a estrutura. O framework usa o valor deste membro para determinar qual página deve ser visualizada primeiro. O valor padrão deste membro é 1, então a primeira página do documento é exibida inicialmente. Você pode `OnPreparePrinting` substituir para definir este membro para o número da página que está sendo visualizada no momento em que o comando Print Preview foi invocado. Dessa forma, o aplicativo mantém a posição atual do usuário ao passar do modo normal de exibição para o modo de visualização de impressão.

Às vezes, `OnPreparePrinting` você pode querer realizar uma inicialização diferente, dependendo se ela é chamada para um trabalho de impressão ou para visualização de impressão. Você pode determinar isso *m_bPreview* examinando a `CPrintInfo` variável membro m_bPreview na estrutura. Este membro é definido **como TRUE** quando a visualização de impressão é invocada.

A `CPrintInfo` estrutura também contém um membro chamado *m_strPageDesc*, que é usado para formatar as strings exibidas na parte inferior da tela em modos de página única e de várias páginas. Por padrão, essas strings são do formulário "Page *n"* e "Pages `OnPreparePrinting` *n* - *m*", mas você pode modificar *m_strPageDesc* de dentro e definir as strings para algo mais elaborado. Consulte [CPrintInfo Structure](../mfc/reference/cprintinfo-structure.md) na *referência MFC* para obter mais informações.

## <a name="see-also"></a>Confira também

[Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)<br/>
[Imprimindo](../mfc/printing.md)<br/>
[Classe CView](../mfc/reference/cview-class.md)<br/>
[Classe CDC](../mfc/reference/cdc-class.md)
