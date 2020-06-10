---
title: Como implementar o acompanhamento no código
ms.date: 11/04/2016
helpviewer_keywords:
- CRectTracker class [MFC], implementing trackers
ms.assetid: baaeca2c-5114-485f-bf58-8807db1bc973
ms.openlocfilehash: 3d71543261021c7e20041d317401b7b7b8d0616e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621663"
---
# <a name="how-to-implement-tracking-in-your-code"></a>Como implementar o acompanhamento no código

Para acompanhar um item OLE, você deve lidar com determinados eventos relacionados ao item, como clicar no item ou atualizar a exibição do documento. Em todos os casos, é suficiente declarar um objeto [CRectTracker](reference/crecttracker-class.md) temporário e manipular o item por meio desse objeto.

Quando um usuário seleciona um item ou insere um objeto com um comando de menu, você deve inicializar o rastreador com os estilos adequados para representar o estado do item OLE. A tabela a seguir descreve as convenções usadas pelo exemplo OCLIENT. Para obter mais informações sobre esses estilos, consulte `CRectTracker` .

### <a name="container-styles-and-states-of-the-ole-item"></a>Estilos de contêiner e Estados do item OLE

|Estilo exibido|Estado do item OLE|
|---------------------|-----------------------|
|Borda pontilhada|O item está vinculado|
|Borda sólida|O item está inserido no documento|
|{1&gt;Alças de redimensionamento&lt;1}|O item está selecionado no momento|
|Borda hachurada|O item está ativo no local no momento|
|Item de sobreposição de padrão de hachura|O servidor do item está aberto|

Você pode manipular essa inicialização facilmente usando um procedimento que verifica o estado do item OLE e define os estilos apropriados. A `SetupTracker` função encontrada no exemplo OCLIENT demonstra a inicialização do rastreador. Os parâmetros para essa função são o endereço do controlador, *pTracker*; um ponteiro para o item de cliente relacionado ao controlador, *pItem*; e um ponteiro para um retângulo, *pTrueRect*. Para obter um exemplo mais completo dessa função, consulte o exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md).

O exemplo de código **SetupTracker** apresenta uma única função; as linhas da função são intercaladas com a discussão dos recursos da função:

[!code-cpp[NVC_MFCOClient#1](codesnippet/cpp/how-to-implement-tracking-in-your-code_1.cpp)]

O rastreador é inicializado definindo o tamanho mínimo e limpando o estilo do controlador.

[!code-cpp[NVC_MFCOClient#2](codesnippet/cpp/how-to-implement-tracking-in-your-code_2.cpp)]

As linhas a seguir verificam se o item está selecionado no momento e se o item está vinculado ao documento ou inserido nele. Os identificadores de redimensionamento localizados no interior da borda são adicionados ao estilo, indicando que o item está selecionado no momento. Se o item estiver vinculado ao documento, o estilo de borda pontilhado será usado. Uma borda sólida será usada se o item for inserido.

[!code-cpp[NVC_MFCOClient#3](codesnippet/cpp/how-to-implement-tracking-in-your-code_3.cpp)]

O código a seguir sobrepõe o item com um padrão hachurado se o item estiver aberto no momento.

[!code-cpp[NVC_MFCOClient#4](codesnippet/cpp/how-to-implement-tracking-in-your-code_4.cpp)]

Em seguida, você pode chamar essa função sempre que o rastreador precisa ser exibido. Por exemplo, chame essa função da `OnDraw` função da classe View. Isso atualiza a aparência do rastreador sempre que a exibição é redesenhada. Para obter um exemplo completo, consulte a `CMainView::OnDraw` função do exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md).

Em seu aplicativo, os eventos que exigem código de rastreador, como redimensionar, mover ou detectar ocorrências, ocorrerão. Essas ações geralmente indicam que uma tentativa está sendo feita para pegar ou mover o item. Nesses casos, você precisará decidir o que foi capturado: um identificador de redimensionamento ou uma parte da borda entre alças de redimensionamento. O `OnLButtonDown` manipulador de mensagens é um bom lugar para testar a posição do mouse em relação ao item. Faça uma chamada para `CRectTracker::HitTest` . Se o teste retornar algo além `CRectTracker::hitOutside` do, o item será redimensionado ou movido. Portanto, você deve fazer uma chamada para a `Track` função membro. Consulte a `CMainView::OnLButtonDown` função localizada no exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) para obter um exemplo completo.

A `CRectTracker` classe fornece várias formas de cursor diferentes usadas para indicar se uma operação de mover, redimensionar ou arrastar está ocorrendo. Para lidar com esse evento, verifique se o item atualmente sob o mouse está selecionado. Se for, faça uma chamada para `CRectTracker::SetCursor` ou chame o manipulador padrão. O exemplo a seguir é do exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md):

[!code-cpp[NVC_MFCOClient#5](codesnippet/cpp/how-to-implement-tracking-in-your-code_5.cpp)]

## <a name="see-also"></a>Consulte também

[Controladores: implementando controladores no aplicativo OLE](trackers-implementing-trackers-in-your-ole-application.md)
