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
ms.openlocfilehash: 227c4614bad42706893301c69882c3f40af12e2f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214338"
---
# <a name="drawing-in-a-view"></a>Desenhando uma exibição

Quase todos os desenhos em seu aplicativo ocorrem na função membro `OnDraw` da exibição, que você deve substituir em sua classe de exibição. (A exceção é desenho do mouse, discutida em [interpretando a entrada do usuário por meio de uma exibição](../mfc/interpreting-user-input-through-a-view.md).) Substituição de `OnDraw`:

1. Obtém dados chamando as funções de membro de documento que você fornecer.

1. Exibe os dados chamando funções de membro de um objeto de contexto de dispositivo que a estrutura passa para `OnDraw`.

Quando os dados de um documento são alterados de alguma forma, a exibição deve ser redesenhada para refletir as alterações. Normalmente, isso acontece quando o usuário faz uma alteração por meio de uma exibição no documento. Nesse caso, a exibição chama a função de membro [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) do documento para notificar todas as exibições no mesmo documento para serem atualizadas. `UpdateAllViews` chama a função de membro [OnUpdate](../mfc/reference/cview-class.md#onupdate) de cada exibição. A implementação padrão de `OnUpdate` invalida a área inteira do cliente da exibição. Você pode substituí-lo para invalidar apenas as regiões da área do cliente que são mapeadas para as partes modificadas do documento.

A função membro `UpdateAllViews` da classe `CDocument` e a função membro `OnUpdate` da classe `CView` permitem que você passe informações que descrevem quais partes do documento foram modificadas. Esse mecanismo de "dica" permite limitar a área que a exibição deve redesenhar. `OnUpdate` usa dois argumentos "Hint". O primeiro, *lHint*, do tipo **lParam**, permite que você passe todos os dados que desejar, enquanto o segundo, *pHint*, do tipo `CObject`*, permite passar um ponteiro para qualquer objeto derivado de `CObject`.

Quando uma exibição se torna inválida, o Windows envia a ela uma mensagem de **WM_PAINT** . A função de manipulador [OnPaint](../mfc/reference/cwnd-class.md#onpaint) da exibição responde à mensagem criando um objeto de contexto de dispositivo da classe [CPaintDC](../mfc/reference/cpaintdc-class.md) e chama a função de membro `OnDraw` da exibição. Normalmente, você não precisa escrever uma função de manipulador de `OnPaint` de substituição.

Um [contexto de dispositivo](../mfc/device-contexts.md) é uma estrutura de dados do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. Para desenhar na tela, `OnDraw` é passado um objeto `CPaintDC`. Para desenhar em uma impressora, é passado um objeto [CDC](../mfc/reference/cdc-class.md) configurado para a impressora atual.

Seu código para desenhar na exibição primeiro recupera um ponteiro para o documento e, em seguida, faz chamadas de desenho por meio do contexto do dispositivo. O exemplo de `OnDraw` simples a seguir ilustra o processo:

[!code-cpp[NVC_MFCDocView#1](../mfc/codesnippet/cpp/drawing-in-a-view_1.cpp)]

Neste exemplo, você definiria a função `GetData` como um membro de sua classe de documento derivada.

O exemplo imprime qualquer cadeia de caracteres obtida do documento, centralizada na exibição. Se a chamada de `OnDraw` for para o desenho de tela, o objeto de `CDC` passado no *PDC* é um `CPaintDC` cujo Construtor já chamou `BeginPaint`. Chamadas para funções de desenho são feitas por meio do ponteiro de contexto do dispositivo. Para obter informações sobre contextos de dispositivo e chamadas de desenho, consulte classe [CDC](../mfc/reference/cdc-class.md) na *referência do MFC* e [trabalhando com objetos de janela](../mfc/working-with-window-objects.md).

Para obter mais exemplos de como escrever `OnDraw`, consulte os [exemplos de MFC](../overview/visual-cpp-samples.md#mfc-samples).

## <a name="see-also"></a>Confira também

[Usando exibições](../mfc/using-views.md)
