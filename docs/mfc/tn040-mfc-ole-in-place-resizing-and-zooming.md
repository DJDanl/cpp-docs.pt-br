---
title: 'TN040: MFC-OLE in-loco redimensionamento e zoom'
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.ole
helpviewer_keywords:
- resizing in-place
- TN040
- zooming and in-place activation
- in-place activation, zooming and resizing
ms.assetid: 4d7859bd-0b2e-4254-be62-2735cecf02c6
ms.openlocfilehash: 072ebe0180bb44145cef694e2283e91a0cacf602
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477201"
---
# <a name="tn040-mfcole-in-place-resizing-and-zooming"></a>TN040: redimensionamento/zoom in-loco MFC/OLE

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Esta Observação discute os problemas relacionados para edição no local e como um servidor deve realizar correto de zoom e redimensionamento in-loco. Com a ativação in-loco, o conceito de WYSIWYG é obtido de uma etapa posterior em que contêineres e servidores cooperam entre si e, em particular interpretam a especificação OLE em grande parte da mesma maneira.

Pela interação entre um contêiner e o servidor com suporte a ativação in-loco, há um número das expectativas do usuário final que deve ser mantido:

- A exibição de apresentação (metarquivo desenhado no `COleServerItem::OnDraw` substituir) deve exatamente a mesma aparência quando ela é desenhada para edição (exceto pelo fato de que ferramentas de edição não são visíveis).

- Quando o contêiner amplia, a janela do servidor deve muito!

- O contêiner e o servidor devem exibir objetos para edição usando as mesmas métricas. Isso significa que usar um modo de mapeamento com base no número de *lógica* pixels por polegada — não físicas pixels por polegada, durante a renderização no dispositivo de vídeo.

> [!NOTE]
>  Porque a ativação in-loco só se aplica a itens que são inseridos (não vinculados), zoom só se aplica a objetos incorporados. Você verá as APIs em ambos `COleServerDoc` e `COleServerItem` que são usados para aumentar o zoom. A razão para essa dicotomia é que apenas as funções que são válidas para os itens vinculados e inseridos estão em `COleServerItem` (Isso permite que você tenha uma implementação comum) e funções que são válidas somente para objetos inseridos estão localizadas no `COleServerDoc` classe (da perspectiva do servidor, ele é o **documento** que é inserido).

A maioria da carga é colocado no implementador de servidor, em que o servidor deve estar ciente do fator de zoom do contêiner e modificar sua interface de edição conforme apropriado. Mas como o servidor determinar o fator de zoom que está usando o contêiner

## <a name="mfc-support-for-zooming"></a>Suporte MFC para aumentar o zoom

O fator de zoom atual pode ser determinado chamando `COleServerDoc::GetZoomFactor`. Quando o documento não está ativo no local de chamada isso sempre resultará em um fator de zoom de 100% (ou taxa de 1:1). Chamando-o enquanto ativo no local pode retornar algo diferente de 100%.

Para obter um exemplo do zoom corretamente, consulte o exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md). Aumentar o zoom HIERSVR é complicado pelo fato de que ele exibe o texto e texto, em geral, não dimensione de maneira linear (dicas de, convenções tipográficas, design larguras e alturas todos complicar a questão). Ainda assim, HIERSVR é uma referência razoável para a implementação de zoom corretamente, e então é o Tutorial de MFC [RABISCO](../visual-cpp-samples.md) (etapa 7).

`COleServerDoc::GetZoomFactor` Determina o fator de zoom com base em um número de métricas diferentes disponíveis do contêiner ou da implementação de sua `COleServerItem` e `COleServerDoc` classes. Em resumo, o fator de zoom atual é determinado pela fórmula a seguir:

```
Position Rectangle (PR) / Container Extent (CE)
```

A posição do retângulo é determinado pelo contêiner. Ele é retornado para o servidor durante a ativação in-loco quando `COleClientItem::OnGetItemPosition` é chamado e é atualizado quando contêiner chama o servidor `COleServerDoc::OnSetItemRects` (com uma chamada para `COleClientItem::SetItemRects`).

A extensão do CONTÊINER é um pouco mais complexa para ser calculada. Se o contêiner tiver chamado `COleServerItem::OnSetExtent` (com uma chamada para `COleClientItem::SetExtent`), em seguida, a extensão do CONTÊINER é o valor convertido em pixels, com base no número de pixels por polegada lógica. Se o contêiner não chamado SetExtent (que é geralmente o caso), a extensão do CONTÊINER é o tamanho retornado de `COleServerItem::OnGetExtent`. Portanto, se o contêiner não tiver chamado SetExtent, o framework pressupõe que se tivesse o contêiner seria ter chamado ele com 100% da extensão natural (o valor retornado de `COleServerItem::GetExtent`). Indicado de outra forma, o framework pressupõe que o contêiner está exibindo 100% (não mais, nem menos) do item.

É importante observar que embora `COleServerItem::OnSetExtent` e `COleServerItem::OnGetExtent` tiverem nomes semelhantes, eles não manipular o mesmo atributo do item. `OnSetExtent` é chamado para informar o servidor quanto o objeto é visível no contêiner (independentemente do fator de zoom) e `OnGetExtent` é chamado pelo contêiner para determinar o tamanho ideal do objeto.

Ao examinar cada uma das APIs envolvidas, você pode obter uma visão mais clara:

## <a name="coleserveritemongetextent"></a>COleServerItem::OnGetExtent

Essa função deve retornar o "tamanho natural" em unidades HIMETRIC do item. A melhor maneira de pensar o "tamanho natural" é defini-lo como o tamanho pode aparecer quando impresso. O tamanho retornado aqui é constante para um conteúdo específico de item (muito semelhante o metarquivo, que é constante para um determinado item). Esse tamanho não é alterado quando a aplicação de zoom é aplicada ao item. Ele geralmente não é alterado quando o contêiner fornece o item mais ou menos espaço por meio da chamada `OnSetExtent`. Um exemplo de uma alteração pode ser de um editor de texto simples com nenhum recurso de "margin" que encapsulado com base no que a última extensão enviada pelo contêiner de texto. Se um servidor for alterado, o servidor provavelmente deverá definir o OLEMISC_RECOMPOSEONRESIZE bit no registro do sistema (consulte a documentação do SDK OLE para obter mais informações sobre essa opção).

## <a name="coleserveritemonsetextent"></a>COleServerItem::OnSetExtent

Essa função é chamada quando o contêiner mostra "mais ou menos" do objeto. A maioria dos contêineres não chamará isso em todos os. A implementação padrão armazena o último valor recebido do contêiner de 'm_sizeExtent', que é usado em `COleServerDoc::GetZoomFactor` ao calcular o valor de extensão do CONTÊINER descrito acima.

## <a name="coleserverdoconsetitemrects"></a>COleServerDoc::OnSetItemRects

Essa função é chamada somente quando o documento está ativo no local. Ele é chamado quando o contêiner atualiza a posição do item ou o recorte aplicado ao item. O retângulo de posição, como discutido acima, fornece o numerador para o cálculo de fator de zoom. Um servidor pode solicitar que a posição do item ser alterado por meio da chamada `COleServerDoc::RequestPositionChange`. O contêiner pode ou não responder a essa solicitação chamando `OnSetItemRects` (com uma chamada para `COleServerItem::SetItemRects`).

## <a name="coleserverdocondraw"></a>COleServerDoc::OnDraw

É importante perceber que o metarquivo criado por meio da substituição de `COleServerItem::OnDraw` produz exatamente o mesmo metarquivo, independentemente do fator de zoom atual. O contêiner será dimensionado metarquivo conforme apropriado. Essa é uma distinção importante entre o modo de exibição `OnDraw` e o item de servidor `OnDraw`. Os identificadores de exibição zoom, o item apenas cria um *cartaz* metarquivo e deixa que o contêiner para fazer o zoom apropriado.

A melhor maneira de garantir que seu servidor se comportará corretamente é usar a implementação de `COleServerDoc::GetZoomFactor` se seu documento está ativo no local.

## <a name="mfc-support-for-in-place-resizing"></a>Suporte MFC para redimensionamento in-loco

MFC implementa totalmente a interface de redimensionamento em vigor, conforme descrito na especificação do OLE 2. Suporte a interface do usuário a `COleResizeBar` classe, uma mensagem personalizada WM_SIZECHILD e manipulação especial dessa mensagem na `COleIPFrameWnd`.

Você talvez queira implementar o tratamento de diferente dessa mensagem que é fornecido pela estrutura. Conforme descrito acima, o framework deixa os resultados de redimensionamento in-loco até o contêiner — o servidor responde à alteração no fator de zoom. Se o contêiner reage definindo a ambos EXTENT do CONTÊINER e o retângulo de posição durante o processamento de seu `COleClientItem::OnChangeItemPosition` (chamado como resultado de uma chamada para `COleServerDoc::RequestPositionChange`) e em seguida, o redimensionamento in-loco resultará na exibição de "mais ou menos" do item na edição janela. Se o contêiner reage ao definir a posição do retângulo durante o processamento de `COleClientItem::OnChangeItemPosition`, o fator de zoom será alterado e o item será mostrado como "ampliação ou redução."

Um servidor pode controlar (até certo ponto), o que acontece durante essa negociação. Por exemplo, uma planilha, pode optar por mostrar mais ou menos células quando o usuário redimensiona a janela ao editar o item no local. Um processador de texto pode optar por alterar as margens da página"" para que eles são o mesmo que a janela e quebrar o texto para a nova margem. Servidores de implementam isso alterando a extensão natural (tamanho retornado de `COleServerItem::OnGetExtent`) quando o redimensionamento é feito. Isso fará com que o retângulo de posição e a extensão de CONTÊINER para alterar a mesma quantidade, resultando no fator de zoom a mesma, mas um maior ou menor de área de exibição. Além disso, mais ou menos do documento serão visíveis no metarquivo gerado pelo `OnDraw`. Nesse caso, o documento em si está mudando quando o usuário redimensiona o item, em vez de apenas a área de exibição.

Você pode implementar o redimensionamento personalizada e ainda aproveitar a interface de usuário fornecida pelo `COleResizeBar` , substituindo a mensagem WM_SIZECHILD na sua `COleIPFrameWnd` classe. Para obter mais informações sobre as especificações de WM_SIZECHILD, consulte [24 de observação técnica](../mfc/tn024-mfc-defined-messages-and-resources.md).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

