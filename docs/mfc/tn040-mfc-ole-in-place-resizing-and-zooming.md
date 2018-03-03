---
title: 'TN040: OLE MFC in-loco redimensionamento | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.ole
dev_langs:
- C++
helpviewer_keywords:
- resizing in-place
- TN040
- zooming and in-place activation
- in-place activation, zooming and resizing
ms.assetid: 4d7859bd-0b2e-4254-be62-2735cecf02c6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b1113da01e58ec00cd4420aab4424b1c20e127e0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn040-mfcole-in-place-resizing-and-zooming"></a>TN040: redimensionamento/zoom in-loco MFC/OLE
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Essa observação sobre os problemas relacionados para edição no local e como um servidor deve realizar correto zoom e redimensionamento no local. Com a ativação no local, o conceito de WYSIWYG é realizado uma etapa adicional que contêineres e servidores cooperam entre si e interpretam em particular a especificação OLE em grande parte da mesma maneira.  
  
 Devido a interação entre um contêiner e o servidor de suporte à ativação no local, há um número das expectativas do usuário final que deve ser mantido:  
  
-   A exibição da apresentação (o metarquivo desenhado no `COleServerItem::OnDraw` substituir) deve exatamente a mesma aparência quando ela é desenhada para edição (exceto que ferramentas de edição não são visíveis).  
  
-   Quando o contêiner de zoom, a janela do servidor deve muito!  
  
-   O contêiner e o servidor devem exibir objetos para edição usando as mesmas métricas. Isso significa que usar um modo de mapeamento com base no número de *lógica* pixels por polegada — não físicas pixels por polegada, quando o dispositivo de vídeo de renderização.  
  
> [!NOTE]
>  Como a ativação no local só se aplica a itens incorporados (não vinculados), aumentar o zoom se aplica somente objetos inseridos. Você verá os APIs no `COleServerDoc` e `COleServerItem` que são usados para aumentar o zoom. A razão para essa dicotomia é que apenas as funções que são válidas para itens incorporados e vinculados estão em `COleServerItem` (Isso permite que você tenha uma implementação comum) e funções que são válidas somente para objetos inseridos estão localizadas no `COleServerDoc` classe (da perspectiva do servidor, é o `document` que é inserido).  
  
 A maioria da carga é colocada no implementador de servidor, em que o servidor deve estar ciente do fator de zoom do contêiner e modificar sua interface de edição conforme apropriado. Mas como o servidor determinar o fator de zoom que o contêiner está usando  
  
## <a name="mfc-support-for-zooming"></a>Suporte MFC para aumentar o zoom  
 O fator de zoom atual pode ser determinado chamando `COleServerDoc::GetZoomFactor`. Quando o documento não está ativo no local de chamada isso sempre resultará em um fator de zoom de 100% (ou a taxa de 1:1). Chamando-o enquanto ativo no local pode retornar algo diferente de 100%.  
  
 Para obter um exemplo de zoom corretamente, consulte o exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md). Aumentar o zoom HIERSVR é complicado pelo fato de que ele exibe o texto e texto, em geral, não se adapta de forma linear (dicas de, convenções tipográficas, design larguras e alturas todos complicar a questão). Ainda assim, HIERSVR é uma referência razoável para implementar o zoom corretamente, e então é o Tutorial MFC [RABISCO](../visual-cpp-samples.md) (etapa 7).  
  
 `COleServerDoc::GetZoomFactor`Determina o fator de zoom com base em um número de diferentes métricas disponíveis do contêiner ou da implementação de sua `COleServerItem` e `COleServerDoc` classes. Em resumo, o fator de zoom atual é determinado pela seguinte fórmula:  
  
```  
Position Rectangle (PR) / Container Extent (CE)  
```  
  
 A posição do retângulo é determinado pelo contêiner. Ele é retornado para o servidor durante a ativação no local quando `COleClientItem::OnGetItemPosition` é chamado e é atualizado quando o contêiner chama o servidor `COleServerDoc::OnSetItemRects` (com uma chamada para `COleClientItem::SetItemRects`).  
  
 A extensão de CONTÊINER é um pouco mais complexa para ser calculada. Se o contêiner tiver chamado `COleServerItem::OnSetExtent` (com uma chamada para `COleClientItem::SetExtent`), em seguida, a extensão do CONTÊINER é o valor convertido em pixels, com base no número de pixels por polegada lógica. Se o contêiner não chamado SetExtent (que é geralmente o caso), a extensão do CONTÊINER é o tamanho retornado de `COleServerItem::OnGetExtent`. Portanto, se o contêiner não chamado SetExtent, a estrutura pressupõe que se tivesse o contêiner deve ter chamado com 100% da extensão natural (o valor retornado de **COleServerItem::GetExtent**). Indicado de outra forma, a estrutura pressupõe que o contêiner está exibindo 100% (não mais, menos) do item.  
  
 É importante observar que embora `COleServerItem::OnSetExtent` e `COleServerItem::OnGetExtent` tenham nomes semelhantes, eles não manipular o mesmo atributo do item. `OnSetExtent`é chamado para informar o servidor quanto o objeto está visível no contêiner (independentemente do fator de zoom) e `OnGetExtent` é chamado pelo contêiner para determinar o tamanho ideal do objeto.  
  
 Ao examinar cada uma das APIs envolvidas, você pode obter uma imagem mais nítida:  
  
## <a name="coleserveritemongetextent"></a>COleServerItem::OnGetExtent  
 Essa função deve retornar "tamanho natural" em DÉCIMOS de milímetros do item. A melhor maneira de pensar "tamanho natural" é defini-lo como o tamanho pode aparecer quando impresso. O tamanho retornado aqui é constante para um conteúdo do item específico (muito semelhante o metarquivo, que é constante para um determinado item). Esse tamanho não é alterado quando zoom é aplicado ao item. Geralmente não é alterado quando o contêiner fornece o item mais ou menos espaço chamando `OnSetExtent`. Um exemplo de uma alteração pode ser de um editor de texto simples com nenhum recurso de "margem" que recuo de texto com base na última extensão enviada pelo contêiner. Se um servidor for alterado, o servidor provavelmente deve definir o bit no registro do sistema OLEMISC_RECOMPOSEONRESIZE (consulte a documentação do SDK OLE para obter mais informações sobre essa opção).  
  
## <a name="coleserveritemonsetextent"></a>COleServerItem::OnSetExtent  
 Essa função é chamada quando o contêiner mostra "mais ou menos" do objeto. A maioria dos contêineres não chamará isso em todos os. A implementação padrão armazena o último valor recebido do contêiner de 'm_sizeExtent', que é usado em `COleServerDoc::GetZoomFactor` ao calcular o valor de extensão de CONTÊINER descrito acima.  
  
## <a name="coleserverdoconsetitemrects"></a>COleServerDoc::OnSetItemRects  
 Esta função é chamada somente quando o documento está ativo no local. Ele é chamado quando o contêiner atualiza a posição do item ou o recorte aplicado ao item. O retângulo de posição, como discutido acima, fornece o numerador para o cálculo de fator de zoom. Um servidor pode solicitar que a posição do item ser alterada chamando `COleServerDoc::RequestPositionChange`. O contêiner pode ou não pode responder a esta solicitação chamando `OnSetItemRects` (com uma chamada para **COleServerItem::SetItemRects**).  
  
## <a name="coleserverdocondraw"></a>COleServerDoc::OnDraw  
 É importante observar que o metarquivo criado por meio da substituição de `COleServerItem::OnDraw` produz exatamente o mesmo metarquivo, independentemente do fator de zoom atual. O contêiner será dimensionado metarquivo conforme apropriado. Essa é uma distinção importante entre o modo de exibição `OnDraw` e o item de servidor `OnDraw`. Os identificadores de exibição zoom, o item cria apenas uma *zoom* metarquivo e deixa até o contêiner para fazer o zoom apropriado.  
  
 É a melhor maneira de garantir que o servidor funcione corretamente usar a implementação de `COleServerDoc::GetZoomFactor` se o documento está ativo no local.  
  
## <a name="mfc-support-for-in-place-resizing"></a>Suporte MFC para redimensionamento no local  
 MFC totalmente implementa a interface de redimensionamento no local conforme descrito na especificação do OLE 2. A interface do usuário é suportada pelo `COleResizeBar` classe, uma mensagem personalizada **WM_SIZECHILD**e manipulação especial dessa mensagem em `COleIPFrameWnd`.  
  
 Você talvez queira implementar tratamento diferente da mensagem que é fornecido pela estrutura. Conforme descrito acima, o framework deixa os resultados de redimensionamento no local até o contêiner — o servidor responde à alteração no fator de zoom. Se o contêiner reage definindo os extensão do CONTÊINER e a posição do retângulo durante o processamento de seu `COleClientItem::OnChangeItemPosition` (chamado como resultado de uma chamada para `COleServerDoc::RequestPositionChange`), em seguida, o redimensionamento in-loco resultará em mostrando a edição "mais ou menos" do item janela. Se o contêiner reage definindo a posição do retângulo apenas durante o processamento de `COleClientItem::OnChangeItemPosition`, o fator de zoom será alterado e o item será mostrado como "ampliado in ou out".  
  
 Um servidor pode controlar (até certo ponto), o que acontece durante essa negociação. Por exemplo, uma planilha, pode optar por mostrar mais ou menos células quando o usuário o redimensiona a janela ao editar o item no local. Um processador de texto pode optar por alterar as margens da página"" para que eles são o mesmo que a janela e quebrar o texto para a nova margem. Servidores implementam isso alterando a extensão natural (o tamanho retornado de `COleServerItem::OnGetExtent`) quando o redimensionamento é feito. Isso fará com que a posição do retângulo e a extensão do CONTÊINER para alterar o mesmo valor, resultando em um mesmo fator de zoom, mas um maior ou menor de área de exibição. Além disso, mais ou menos do documento serão visíveis ao metarquivo gerados pelo `OnDraw`. Nesse caso, o próprio documento está sendo alterado quando o usuário o redimensiona o item, em vez de apenas a área de exibição.  
  
 Você pode implementar o redimensionamento personalizado e ainda aproveitar a interface de usuário fornecida pelo `COleResizeBar` , substituindo o **WM_SIZECHILD** de mensagem em seu `COleIPFrameWnd` classe. Para obter mais informações sobre as especificações de **WM_SIZECHILD**, consulte [24 de observação técnica](../mfc/tn024-mfc-defined-messages-and-resources.md).  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

