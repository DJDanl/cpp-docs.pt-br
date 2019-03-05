---
title: 'Como: Implementar o acompanhamento no seu código'
ms.date: 11/04/2016
helpviewer_keywords:
- CRectTracker class [MFC], implementing trackers
ms.assetid: baaeca2c-5114-485f-bf58-8807db1bc973
ms.openlocfilehash: af8e1b72bde268a15012515065853daa617936e4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283976"
---
# <a name="how-to-implement-tracking-in-your-code"></a>Como: Implementar o acompanhamento no seu código

Para acompanhar um item OLE, você deve tratar a determinados eventos relacionados ao item, como quando clicar no item ou atualizar a exibição do documento. Em todos os casos, é suficiente para declarar um temporário [CRectTracker](../mfc/reference/crecttracker-class.md) do objeto e manipular o item por meio desse objeto.

Quando um usuário seleciona um item ou insere um objeto com um comando de menu, você deve inicializar o controlador com o estilo adequados para representar o estado do item OLE. A tabela a seguir descreve as convenções usadas pelo exemplo OCLIENT. Para obter mais informações sobre esses estilos, consulte `CRectTracker`.

### <a name="container-styles-and-states-of-the-ole-item"></a>Estilos de contêiner e estados do Item OLE

|Estilo exibido|Estado do item OLE|
|---------------------|-----------------------|
|Borda pontilhada|Item está vinculado|
|Borda sólida|Item é inserido em seu documento|
|{1&gt;Alças de redimensionamento&lt;1}|Item está selecionado no momento|
|Borda tracejada|O item é ativo no momento no local|
|Item de sobreposições de padrão de hachura|Servidor do item está aberto|

Você pode manipular essa inicialização facilmente usando um procedimento que verifica o estado do item OLE e define os estilos apropriados. O `SetupTracker` função encontrada na amostra OCLIENT demonstra a inicialização do rastreador. Os parâmetros para essa função são o endereço do controlador, *pTracker*; um ponteiro para o item do cliente que está relacionado ao controlador, *pItem*; e um ponteiro para um retângulo, *pTrueRect* . Para obter um exemplo mais completo dessa função, consulte o exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md).

O **SetupTracker** exemplo de código apresenta uma única função, linhas da função são intercaladas com discussão dos recursos da função:

[!code-cpp[NVC_MFCOClient#1](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_1.cpp)]

O controlador é inicializado, definindo o tamanho mínimo e limpar o estilo do controlador.

[!code-cpp[NVC_MFCOClient#2](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_2.cpp)]

Verifique as seguintes linhas para ver se o item está selecionado no momento e se o item está vinculado ao documento ou inserido nele. Alças de redimensionamento localizadas dentro da borda são adicionadas ao estilo, indicando que o item está selecionado no momento. Se o item está vinculado ao documento, o estilo de borda pontilhada será usado. Uma borda sólida é usada se o item é inserido.

[!code-cpp[NVC_MFCOClient#3](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_3.cpp)]

Abra o item com um padrão de hachurado se o item está atualmente as sobreposições de código a seguir.

[!code-cpp[NVC_MFCOClient#4](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_4.cpp)]

Em seguida, você pode chamar essa função sempre que o controlador tiver a serem exibidos. Por exemplo, chamar essa função a partir de `OnDraw` função da sua classe de exibição. Isso atualiza a aparência do rastreador sempre que o modo de exibição é redesenhado. Para obter um exemplo completo, consulte o `CMainView::OnDraw` função OLE do MFC do exemplo de [OCLIENT](../visual-cpp-samples.md).

Em seu aplicativo, os eventos que exigem o código de controlador, como detecção de ocorrências, movimentação ou redimensionamento, ocorrerá. Essas ações geralmente indicam que está sendo feita uma tentativa para capturar ou mover o item. Nesses casos, você precisará decidir o que foi capturado: uma alça de redimensionamento ou parte da borda entre alças de redimensionamento. O `OnLButtonDown` manipulador de mensagens é um bom lugar para testar a posição do mouse em relação ao item. Fazer uma chamada para `CRectTracker::HitTest`. Se o teste retorna algo além de `CRectTracker::hitOutside`, o item está sendo redimensionada ou movida. Portanto, você deve fazer uma chamada para o `Track` função de membro. Consulte a `CMainView::OnLButtonDown` função localizada na OLE do MFC amostra [OCLIENT](../visual-cpp-samples.md) para obter um exemplo completo.

O `CRectTracker` classe fornece várias formas diferentes de cursor usadas para indicar se um mover, redimensionar ou arraste a operação está em andamento. Para lidar com esse evento, verifique se o item atualmente sob o mouse está selecionado. Se for, fazer uma chamada para `CRectTracker::SetCursor`, ou chamar o manipulador padrão. O exemplo a seguir está o exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md):

[!code-cpp[NVC_MFCOClient#5](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_5.cpp)]

## <a name="see-also"></a>Consulte também

[Controladores: Implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)
