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
ms.openlocfilehash: 1956313d4e904255ba59e79690fe3d7144669a29
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623944"
---
# <a name="print-preview-architecture"></a>Imprimir arquitetura de visualização

Este artigo explica como a estrutura MFC implementa a funcionalidade de visualização de impressão. Os tópicos abordados incluem:

- [Processo de visualização de impressão](#_core_the_print_preview_process)

- [Modificando visualização de impressão](#_core_modifying_print_preview)

A visualização de impressão é um pouco diferente da exibição da tela e da impressão porque, em vez de desenhar diretamente uma imagem em um dispositivo, o aplicativo deve simular a impressora usando a tela. Para acomodar isso, o biblioteca MFC define uma classe especial (não documentada) derivada da [classe CDC](reference/cdc-class.md), chamada `CPreviewDC` . Todos os `CDC` objetos contêm dois contextos de dispositivo, mas geralmente são idênticos. Em um `CPreviewDC` objeto, eles são diferentes: o primeiro representa a impressora que está sendo simulada e a segunda representa a tela na qual a saída é realmente exibida.

## <a name="the-print-preview-process"></a><a name="_core_the_print_preview_process"></a>O processo de visualização de impressão

Quando o usuário seleciona o comando Visualizar impressão no menu **arquivo** , a estrutura cria um `CPreviewDC` objeto. Sempre que seu aplicativo executa uma operação que define uma característica do contexto do dispositivo de impressora, a estrutura também executa uma operação semelhante no contexto do dispositivo de tela. Por exemplo, se seu aplicativo selecionar uma fonte para impressão, a estrutura selecionará uma fonte para exibição de tela que simula a fonte da impressora. Sempre que o aplicativo enviar a saída para a impressora, a estrutura, em vez disso, envia a saída para a tela.

A visualização de impressão também difere da impressão na ordem em que cada uma desenha as páginas de um documento. Durante a impressão, a estrutura continua um loop de impressão até que um determinado intervalo de páginas tenha sido renderizado. Durante a visualização de impressão, uma ou duas páginas são exibidas a qualquer momento e, em seguida, o aplicativo aguarda; nenhuma outra página será exibida até que o usuário responda. Durante a visualização de impressão, o aplicativo também deve responder a WM_PAINT mensagens, assim como ocorre durante a exibição de tela comum.

A função [cvisualização:: OnPreparePrinting](reference/cview-class.md#onprepareprinting) é chamada quando o modo de visualização é invocado, assim como no início de um trabalho de impressão. A estrutura de [estrutura CPrintInfo](reference/cprintinfo-structure.md) passada para a função contém vários membros cujos valores você pode definir para ajustar determinadas características da operação de visualização de impressão. Por exemplo, você pode definir o membro *m_nNumPreviewPages* para especificar se deseja visualizar o documento em modo de uma página ou de duas páginas.

## <a name="modifying-print-preview"></a><a name="_core_modifying_print_preview"></a>Modificando visualização de impressão

Você pode modificar o comportamento e a aparência da visualização de impressão de várias maneiras facilmente. Por exemplo, você pode, entre outras coisas:

- Faz com que a janela de visualização de impressão exiba uma barra de rolagem para facilitar o acesso a qualquer página do documento.

- Faz com que a visualização de impressão mantenha a posição do usuário no documento iniciando sua exibição na página atual.

- Fazer com que a inicialização diferente seja executada para impressão e visualização de impressão.

- Faz com que a visualização de impressão exiba números de página em seus próprios formatos.

Se você souber por quanto tempo o documento está e chamar `SetMaxPage` com o valor apropriado, a estrutura poderá usar essas informações no modo de visualização, bem como durante a impressão. Depois que a estrutura sabe o comprimento do documento, ela pode fornecer a janela de visualização com uma barra de rolagem, permitindo que o usuário faça uma página de volta e passe pelo documento no modo de visualização. Se você não tiver definido o comprimento do documento, a estrutura não poderá posicionar a caixa de rolagem para indicar a posição atual, de modo que a estrutura não adicionará uma barra de rolagem. Nesse caso, o usuário deve usar os botões página seguinte e página anterior na barra de controle da janela de visualização para fazer a página passar pelo documento.

Para visualização de impressão, talvez seja útil atribuir um valor ao membro *m_nCurPage* de `CPrintInfo` , mesmo que você nunca faça isso para impressão comum. Durante a impressão comum, esse membro transporta informações da estrutura para sua classe View. É assim que a estrutura informa ao modo de exibição qual página deve ser impressa.

Por outro lado, quando o modo de visualização de impressão é iniciado, o membro *m_nCurPage* transporta informações na direção oposta: da exibição para a estrutura. A estrutura usa o valor desse membro para determinar qual página deve ser visualizada primeiro. O valor padrão desse membro é 1, portanto, a primeira página do documento é exibida inicialmente. Você pode substituir `OnPreparePrinting` para definir esse membro como o número da página que está sendo exibida no momento em que o comando de visualização de impressão foi invocado. Dessa forma, o aplicativo mantém a posição atual do usuário ao mover do modo de exibição normal para o modo de visualização de impressão.

Às vezes, talvez você queira `OnPreparePrinting` executar uma inicialização diferente dependendo se ela é chamada para um trabalho de impressão ou para visualização de impressão. Você pode determinar isso examinando a variável de membro *m_bPreview* na `CPrintInfo` estrutura. Esse membro é definido como **true** quando a visualização de impressão é chamada.

A `CPrintInfo` estrutura também contém um membro chamado *m_strPageDesc*, que é usado para formatar as cadeias de caracteres exibidas na parte inferior da tela em modos de página única e de várias páginas. Por padrão, essas cadeias de caracteres são do formato "página *n*" e "páginas *n*  -  *m*", mas você pode modificar *m_strPageDesc* de dentro `OnPreparePrinting` e definir as cadeias de caracteres para algo mais elaborado. Consulte [estrutura CPrintInfo](reference/cprintinfo-structure.md) na *referência do MFC* para obter mais informações.

## <a name="see-also"></a>Consulte também

[Impressão e visualização de impressão](printing-and-print-preview.md)<br/>
[Impressão](printing.md)<br/>
[Classe CView](reference/cview-class.md)<br/>
[Classe CDC](reference/cdc-class.md)
