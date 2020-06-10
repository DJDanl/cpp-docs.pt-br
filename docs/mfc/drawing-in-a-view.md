---
title: Desenhando uma exibição
ms.date: 11/04/2016
helpviewer_keywords:
- drawing [MFC], in views
- views [MFC], printing
- views [MFC], updating
- printing [MFC], views
- views [MFC], rendering
- printing views [MFC]
- paint messages in view class [MFC]
- device contexts, screen drawings
ms.assetid: e3761db6-0f19-4482-a4cd-ac38ef7c4d3a
ms.openlocfilehash: c60d99fdebcd64ad844bc19918a30beb90b86af3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618932"
---
# <a name="drawing-in-a-view"></a>Desenhando uma exibição

Quase todo o desenho em seu aplicativo ocorre na função de `OnDraw` membro da exibição, que você deve substituir em sua classe de exibição. (A exceção é desenho do mouse, discutida em [interpretando a entrada do usuário por meio de uma exibição](interpreting-user-input-through-a-view.md).) Sua `OnDraw` substituição:

1. Obtém dados chamando as funções de membro de documento que você fornecer.

1. Exibe os dados chamando as funções de membro de um objeto de contexto de dispositivo para o qual a estrutura passa `OnDraw` .

Quando os dados de um documento são alterados de alguma forma, a exibição deve ser redesenhada para refletir as alterações. Normalmente, isso acontece quando o usuário faz uma alteração por meio de uma exibição no documento. Nesse caso, a exibição chama a função de membro [UpdateAllViews](reference/cdocument-class.md#updateallviews) do documento para notificar todas as exibições no mesmo documento para serem atualizadas. `UpdateAllViews`chama a função de membro [OnUpdate](reference/cview-class.md#onupdate) de cada exibição. A implementação padrão de `OnUpdate` invalida a área inteira do cliente da exibição. Você pode substituí-lo para invalidar apenas as regiões da área do cliente que são mapeadas para as partes modificadas do documento.

A `UpdateAllViews` função membro da classe `CDocument` e a `OnUpdate` função de membro da classe `CView` permitem que você passe informações descrevendo quais partes do documento foram modificadas. Esse mecanismo de "dica" permite limitar a área que a exibição deve redesenhar. `OnUpdate`usa dois argumentos "Hint". O primeiro, *lHint*, do tipo **lParam**, permite que você passe todos os dados que desejar, enquanto o segundo, *pHint*, do tipo `CObject` *, permite passar um ponteiro para qualquer objeto derivado de `CObject` .

Quando uma exibição se torna inválida, o Windows envia a ela uma mensagem de **WM_PAINT** . A função de manipulador [OnPaint](reference/cwnd-class.md#onpaint) da exibição responde à mensagem criando um objeto de contexto de dispositivo da classe [CPaintDC](reference/cpaintdc-class.md) e chama a função de membro da exibição `OnDraw` . Normalmente, você não precisa escrever uma função de `OnPaint` manipulador de substituição.

Um [contexto de dispositivo](device-contexts.md) é uma estrutura de dados do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. Para desenhar na tela, `OnDraw` é passado um `CPaintDC` objeto. Para desenhar em uma impressora, é passado um objeto [CDC](reference/cdc-class.md) configurado para a impressora atual.

Seu código para desenhar na exibição primeiro recupera um ponteiro para o documento e, em seguida, faz chamadas de desenho por meio do contexto do dispositivo. O exemplo simples a seguir `OnDraw` ilustra o processo:

[!code-cpp[NVC_MFCDocView#1](codesnippet/cpp/drawing-in-a-view_1.cpp)]

Neste exemplo, você definiria a `GetData` função como um membro de sua classe de documento derivada.

O exemplo imprime qualquer cadeia de caracteres obtida do documento, centralizada na exibição. Se a `OnDraw` chamada for para desenho de tela, o `CDC` objeto passado no *PDC* será um `CPaintDC` cujo Construtor já chamou `BeginPaint` . Chamadas para funções de desenho são feitas por meio do ponteiro de contexto do dispositivo. Para obter informações sobre contextos de dispositivo e chamadas de desenho, consulte classe [CDC](reference/cdc-class.md) na *referência do MFC* e [trabalhando com objetos de janela](working-with-window-objects.md).

Para obter mais exemplos de como escrever `OnDraw` , consulte os [exemplos do MFC](../overview/visual-cpp-samples.md#mfc-samples).

## <a name="see-also"></a>Consulte também

[Usando exibições](using-views.md)
