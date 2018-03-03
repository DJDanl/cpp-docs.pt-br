---
title: "Como: implementar o acompanhamento no seu código | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- CRectTracker class [MFC], implementing trackers
ms.assetid: baaeca2c-5114-485f-bf58-8807db1bc973
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2ad49c70113780e0c0570e88efab06efc347e83d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-implement-tracking-in-your-code"></a>Como implementar o acompanhamento no código
Para rastrear um item OLE, você deve tratar determinados eventos relacionados ao item, como clicando no item ou atualizando a exibição do documento. Em todos os casos, é suficiente declarar um temporário [CRectTracker](../mfc/reference/crecttracker-class.md) do objeto e manipular o item por meio desse objeto.  
  
 Quando um usuário seleciona um item ou insere um objeto com um comando de menu, você deve inicializar o controlador com os estilos adequados para representar o estado do item OLE. A tabela a seguir descreve as convenções usadas pelo exemplo OCLIENT. Para obter mais informações sobre esses estilos, consulte `CRectTracker`.  
  
### <a name="container-styles-and-states-of-the-ole-item"></a>Estilos de contêiner e os estados de Item OLE  
  
|Estilo|Estado do item OLE|  
|---------------------|-----------------------|  
|Borda pontilhada|Item está vinculado|  
|Borda sólida|Item é inserido no documento|  
|{1&gt;Alças de redimensionamento&lt;1}|Item está selecionado no momento|  
|Borda tracejada|Item está ativo no momento no local|  
|Item de sobreposições de padrão de hachura|Servidor do item está aberta|  
  
 Você pode tratar essa inicialização facilmente usando um procedimento que verifica o estado do item OLE e define os estilos apropriados. O **SetupTracker** função encontrada no exemplo OCLIENT demonstra a inicialização do controlador. Os parâmetros para esta função são o endereço do controlador, *pTracker*; um ponteiro para o item de cliente que está relacionado ao controlador, `pItem`; e um ponteiro para um retângulo, *pTrueRect*. Para obter um exemplo mais completo dessa função, consulte o exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md).  
  
 O **SetupTracker** código de exemplo apresenta uma única função, linhas da função são intercaladas com a discussão sobre os recursos da função:  
  
 [!code-cpp[NVC_MFCOClient#1](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_1.cpp)]  
  
 O controlador é inicializado, definindo o tamanho mínimo e limpar o estilo do controlador.  
  
 [!code-cpp[NVC_MFCOClient#2](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_2.cpp)]  
  
 As seguintes linhas verificar se o item é selecionado no momento e se o item está vinculado ao documento ou inserido nele. Alças de redimensionamento localizadas no interior da borda são adicionadas ao estilo, indicando que o item está selecionado no momento. Se o item está vinculado ao documento, o estilo de borda pontilhada será usado. Uma borda sólida é usada se o item é inserido.  
  
 [!code-cpp[NVC_MFCOClient#3](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_3.cpp)]  
  
 Abra o item com um padrão hachurado se o item está as sobreposições de código a seguir.  
  
 [!code-cpp[NVC_MFCOClient#4](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_4.cpp)]  
  
 Em seguida, você pode chamar essa função sempre que o controlador tem a ser exibido. Por exemplo, chamar essa função do `OnDraw` função da sua classe de exibição. Isso atualiza a aparência do rastreador sempre que o modo de exibição é redesenhado. Para obter um exemplo completo, consulte o **CMainView::OnDraw** função MFC OLE do exemplo de [OCLIENT](../visual-cpp-samples.md).  
  
 Em seu aplicativo, os eventos que requerem o código do controlador, como detecção de ocorrências, redimensionamento ou movimentação, ocorrerá. Essas ações geralmente indicam que está sendo feita uma tentativa de obter ou mover o item. Nesses casos, você precisará decidir o que foi capturado: uma alça de redimensionamento ou uma parte da borda entre alças de redimensionamento. O `OnLButtonDown` manipulador de mensagens é um bom lugar para testar a posição do mouse em relação ao item. Fazer uma chamada para `CRectTracker::HitTest`. Se o teste retorna algo além **CRectTracker::hitOutside**, o item está sendo redimensionado ou movido. Portanto, você deve fazer uma chamada para o `Track` função de membro. Consulte o **CMainView::OnLButtonDown** função localizada no MFC OLE exemplo [OCLIENT](../visual-cpp-samples.md) para obter um exemplo completo.  
  
 O `CRectTracker` classe fornece várias formas diferentes de cursor usadas para indicar se um mover, redimensionar ou arraste operação está ocorrendo. Para lidar com esse evento, verifique se o item atualmente sob o mouse é selecionado. Se for, fazer uma chamada para `CRectTracker::SetCursor`, ou ligue para o manipulador padrão. O exemplo a seguir é um OLE do MFC exemplo de [OCLIENT](../visual-cpp-samples.md):  
  
 [!code-cpp[NVC_MFCOClient#5](../mfc/codesnippet/cpp/how-to-implement-tracking-in-your-code_5.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controladores: implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)

