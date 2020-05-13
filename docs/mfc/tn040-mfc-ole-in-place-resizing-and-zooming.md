---
title: 'TN040: MFC-OLE no lugar Redimensionamento e Zoom'
ms.date: 11/04/2016
helpviewer_keywords:
- resizing in-place
- TN040
- zooming and in-place activation
- in-place activation, zooming and resizing
ms.assetid: 4d7859bd-0b2e-4254-be62-2735cecf02c6
ms.openlocfilehash: 65f9ef04c9740e8e6f0a8e72d9d6c39008198755
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372162"
---
# <a name="tn040-mfcole-in-place-resizing-and-zooming"></a>TN040: redimensionamento/zoom in-loco MFC/OLE

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota discutirá as questões relacionadas à edição no local e como um servidor deve realizar o zoom correto e o redimensionamento no local. Com a ativação no local, o conceito WYSIWYG é dado um passo adiante na medida em que contêineres e servidores cooperam entre si e, em particular, interpretam a especificação OLE da mesma forma.

Devido à interação estreita entre um contêiner e um servidor que suporta maativar no local, há uma série de expectativas do usuário final que devem ser mantidas:

- O visor de apresentação `COleServerItem::OnDraw` (o metaarquivo desenhado na substituição) deve ser exatamente o mesmo que quando é desenhado para edição (exceto que as ferramentas de edição não são visíveis).

- Quando o contêiner faz zoom, a janela do servidor também deve!

- Tanto o contêiner quanto o servidor devem exibir objetos para edição usando as mesmas métricas. Isso significa usar um modo de mapeamento baseado no número de pixels *lógicos* por polegada — não pixels físicos por polegada, ao renderizar no dispositivo de exibição.

> [!NOTE]
> Como a ativação no local só se aplica a itens incorporados (não vinculados), o zoom só se aplica a objetos incorporados. Você verá APIs `COleServerDoc` em `COleServerItem` ambos e que são usadas para zoom. A razão para essa dicotomia é que apenas funções válidas tanto `COleServerItem` para itens vinculados quanto incorporados estão em (isso permite que você `COleServerDoc` tenha uma implementação comum) e funções válidas apenas para objetos incorporados estão localizadas na classe (na perspectiva do servidor, é o **documento** que está incorporado).

A maior parte da carga é colocada no implementador do servidor, na medida em que o servidor deve estar ciente do fator de zoom do contêiner e modificar sua interface de edição conforme apropriado. Mas como o servidor determina o fator de zoom que o contêiner está usando

## <a name="mfc-support-for-zooming"></a>Suporte MFC para zoom

O fator de zoom atual `COleServerDoc::GetZoomFactor`pode ser determinado pelo chamado . Chamar isso quando o documento não estiver ativo no local sempre resultará em um fator de zoom de 100% (ou proporção de 1:1). Chamá-lo enquanto estiver ativo no lugar pode retornar algo diferente de 100%.

Para um exemplo de zoom corretamente, consulte a amostra DeMFC OLE [HIERSVR](../overview/visual-cpp-samples.md). O zoom no HIERSVR é complicado pelo fato de que ele exibe texto, e o texto, em geral, não escala de forma linear (dicas, convenções tipográficas, larguras de design e alturas complicam a questão). Ainda assim, hiersvr é uma referência razoável para implementar zoom corretamente, assim como o MFC Tutorial [SCRIBBLE](../overview/visual-cpp-samples.md) (etapa 7).

`COleServerDoc::GetZoomFactor`determina o fator zoom com base em uma série de métricas diferentes disponíveis no contêiner ou a partir da implementação de suas `COleServerItem` classes. `COleServerDoc` Em suma, o fator de zoom atual é determinado pela seguinte fórmula:

```
Position Rectangle (PR) / Container Extent (CE)
```

A POSIÇÃO RECTANGLE é determinada pelo recipiente. Ele é devolvido ao servidor durante a `COleClientItem::OnGetItemPosition` ativação no local quando é chamado `COleServerDoc::OnSetItemRects` e é `COleClientItem::SetItemRects`atualizado quando o contêiner chama o servidor (com uma chamada para ).

A extensão do CONTAINER é um pouco mais complexa de calcular. Se o contêiner `COleServerItem::OnSetExtent` tiver chamado `COleClientItem::SetExtent`(com uma chamada para), então o CONTAINER EXTENT é esse valor convertido em pixels com base no número de pixels por polegada lógica. Se o recipiente não tiver chamado SetExtent (que geralmente é o caso), então a EXTENSÃO DO CONTÊINER é o tamanho devolvido . `COleServerItem::OnGetExtent` Assim, se o contêiner não tiver chamado SetExtent, a estrutura assume que se o fizesse o contêiner o teria `COleServerItem::GetExtent`chamado com 100% da extensão natural (o valor devolvido). Dito de outra forma, a estrutura pressupõe que o contêiner esteja exibindo 100% (nem mais, nem menos) do item.

É importante notar que, embora `COleServerItem::OnSetExtent` e `COleServerItem::OnGetExtent` tenham nomes semelhantes, eles não manipulam o mesmo atributo do item. `OnSetExtent`é chamado para deixar o servidor saber quanto do objeto é visível no `OnGetExtent` recipiente (independentemente do fator zoom) e é chamado pelo contêiner para determinar o tamanho ideal do objeto.

Ao olhar para cada uma das APIs envolvidas, você pode obter uma imagem mais clara:

## <a name="coleserveritemongetextent"></a>COleServerItem::OnGetExtent

Esta função deve retornar o "tamanho natural" em unidades HIMETRIC do item. A melhor maneira de pensar no "tamanho natural" é defini-lo como o tamanho que pode aparecer quando impresso. O tamanho devolvido aqui é constante para um determinado conteúdo de item (muito parecido com o metaarquivo, que é constante para um determinado item). Este tamanho não muda quando o zoom é aplicado ao item. Geralmente não muda quando o recipiente dá mais ou `OnSetExtent`menos espaço ao item chamando . Um exemplo de mudança pode ser o de um simples editor de texto sem capacidade de "margem" que embrulhou o texto com base na última extensão enviada pelo contêiner. Se um servidor mudar, o servidor provavelmente deve definir o OLEMISC_RECOMPOSEONRESIZE bit no registro do sistema (consulte a documentação OLE SDK para obter mais informações sobre essa opção).

## <a name="coleserveritemonsetextent"></a>COleServerItem::OnSetExtent

Esta função é chamada quando o recipiente mostra "mais ou menos" do objeto. A maioria dos contêineres não vai chamar isso de todo. A implementação padrão armazena o último valor recebido do contêiner `COleServerDoc::GetZoomFactor` em 'm_sizeExtent', que é usado ao calcular o valor DE EXTENSÃO DE CONTÊINER descrito acima.

## <a name="coleserverdoconsetitemrects"></a>COleServerDoc::OnSetItemRects

Esta função é chamada apenas quando o documento está ativo no local. É chamado quando o contêiner atualiza a posição do item ou o recorte aplicado ao item. O POSITION RECTANGLE, como discutido acima, fornece o numerador para o cálculo do fator zoom. Um servidor pode solicitar que a posição `COleServerDoc::RequestPositionChange`do item seja alterada por chamada . O contêiner pode ou não responder `OnSetItemRects` a esta solicitação `COleServerItem::SetItemRects`ligando (com uma chamada para ).

## <a name="coleserverdocondraw"></a>COleServerDoc::OnDraw

É importante perceber que o metaarquivo criado `COleServerItem::OnDraw` pela substituição de produz exatamente o mesmo metaarquivo, independentemente do fator de zoom atual. O recipiente dimensionará o metaarquivo conforme apropriado. Esta é uma distinção importante `OnDraw` entre a exibição `OnDraw`e o item do servidor. A visão manipula zoom, o item apenas cria um metaarquivo *zoom e* deixa-o até o recipiente para fazer o zoom apropriado.

A melhor maneira de garantir que seu servidor se comporte `COleServerDoc::GetZoomFactor` corretamente é usar a implementação se o documento estiver ativo no local.

## <a name="mfc-support-for-in-place-resizing"></a>Suporte mfc para redimensionamento no local

O MFC implementa totalmente a interface de redimensionamento no local conforme descrito na especificação OLE 2. A interface de usuário é `COleResizeBar` suportada pela classe, uma mensagem personalizada `COleIPFrameWnd`WM_SIZECHILD e um tratamento especial desta mensagem em .

Você pode querer implementar um tratamento diferente desta mensagem do que o fornecido pela estrutura. Como descrito acima, o quadro deixa os resultados de redimensionamento no local até o contêiner — o servidor responde à alteração no fator zoom. Se o contêiner reagir definindo a EXTENSÃO DO CONTÊINER e `COleClientItem::OnChangeItemPosition` o RECTANGLE DE POSIÇÃO `COleServerDoc::RequestPositionChange`durante o processamento de sua (chamada como resultado de uma chamada para ) o redimensionamento no local resultará em mostrar "mais ou menos" do item na janela de edição. Se o recipiente reagir apenas definindo o RECTÂNGULO `COleClientItem::OnChangeItemPosition`DE POSIÇÃO durante o processamento de , o fator de zoom mudará e o item será mostrado "ampliado ou para fora".

Um servidor pode controlar (até certo ponto) o que acontece durante essa negociação. Uma planilha, por exemplo, pode optar por mostrar mais ou menos células quando o usuário redimensiona a janela enquanto edita o item no lugar. Um processador de texto pode optar por alterar as "margens de página" para que sejam iguais à janela e reembrulhar o texto para a nova margem. Os servidores implementam isso alterando a extensão natural (o tamanho devolvido) `COleServerItem::OnGetExtent`quando o redimensionamento é feito. Isso fará com que tanto o RECTANGLE DE POSIÇÃO quanto a EXTENSÃO DO CONTÊINER mudem pela mesma quantidade, resultando no mesmo fator de zoom, mas em uma área de visualização maior ou menor. Além disso, mais ou menos do documento será visível `OnDraw`no metaarquivo gerado por . Neste caso, o documento em si está mudando quando o usuário redimensiona o item, em vez de apenas a área de visualização.

Você pode implementar o redimensionamento personalizado e `COleResizeBar` ainda aproveitar a interface `COleIPFrameWnd` de usuário fornecida, substituindo a mensagem WM_SIZECHILD em sua classe. Para obter mais informações sobre as especificidades de WM_SIZECHILD, consulte [nota técnica 24](../mfc/tn024-mfc-defined-messages-and-resources.md).

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
