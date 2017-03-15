---
title: "TN040: redimensionamento/zoom in-loco MFC/OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ativação no local, zoom e redimensionamento"
  - "redimensionando no local"
  - "TN040"
  - "zoom e ativação no local"
ms.assetid: 4d7859bd-0b2e-4254-be62-2735cecf02c6
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN040: redimensionamento/zoom in-loco MFC/OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreverá os problemas em relação ao editar no local e como um servidor deve aplicar zoom correto e redimensionar o local.  Com a ativação no local, o conceito de WYSIWYG é feito uma etapa adicional que os contêineres e os servidores cooperam entre si, e interpreta em particular a especificação OLE da mesma forma.  
  
 Devido à interação entre próximo contêiner e um ativação in\-loco de suporte de servidor existe um número de expectativa do usuário final que deve ser mantido:  
  
-   A exibição de apresentação \(EMF o desenhado na substituição de `COleServerItem::OnDraw` \) deve ter exatamente o mesmo de quando é desenhada para a edição \(exceto que as ferramentas de edição não é visível\).  
  
-   Quando o contêiner aplicar zoom, a janela de servidor deve muito\!  
  
-   O contêiner e o servidor devem exibir objetos para editar usando o mesmo métricas.  Isso significa usando um modo de mapeamento com base no número de pixels *lógicos* por polegada\) — pixels não físicos por polegada, ao renderizar no dispositivo de exibição.  
  
> [!NOTE]
>  Como o ativação no local se aplica apenas aos itens que são inseridos \(não vinculado\), aplicar zoom se aplica apenas aos objetos inseridos.  Verá APIs no `COleServerDoc` e `COleServerItem` que são usados aplicar zoom.  A razão para isso é que só dicotomia as funções que são válidos para itens vinculados e inseridos estão em `COleServerItem` \(isso permite que você tenha uma implementação comum\) e funções que são válidos para objetos inseridos estão localizadas na classe de `COleServerDoc` \(da perspectiva do servidor, é `document` que é inserida\).  
  
 A maioria da carga é colocada no implementador de servidor, que o servidor deve estar consciente do fator de zoom do contêiner e alterar sua interface de edição conforme apropriado.  Mas como o servidor determina o fator de zoom que o contêiner estiver usando?  
  
## Suporte de MFC aplicar zoom  
 O fator de zoom atual pode ser determinado chamando `COleServerDoc::GetZoomFactor`.  Chamar isso quando o documento não estiver ativa no local sempre resultará um fator de zoom 100% \(ou à taxa de 1:1\).  Chamando o quando ativa no local pode retornar algo diferente de 100%.  
  
 Para obter um exemplo de zoom corretamente consulte o exemplo [HIERSVR](../top/visual-cpp-samples.md)MFC OLE.  Amplie HIERSVR é complicado pelo fato de que exibe o texto, e o texto, em geral, não tamanho de maneira linear \(dicas, as convenções tipográficas, as larguras de design, e as alturas todos complicam a questão\).  Ainda, HIERSVR é uma referência razoável para implementar zoom corretamente, e também o MFC [GARRANCHO](../top/visual-cpp-samples.md) tutorial \(etapa 7\).  
  
 `COleServerDoc::GetZoomFactor` determina o fator de zoom baseado em um número diferente de métricas disponível do contêiner ou da implementação de suas classes de `COleServerItem` e de `COleServerDoc` .  Em resumo, o fator de zoom do atual é determinado pela seguinte fórmula:  
  
```  
Position Rectangle (PR) / Container Extent (CE)  
```  
  
 O RETÂNGULO de POSIÇÃO é determinado pelo contêiner.  É retornado ao servidor durante o `COleClientItem::OnGetItemPosition` in\-loco ativação quando é chamado e atualizado quando o contêiner chama `COleServerDoc::OnSetItemRects` do servidor \(por uma chamada a `COleClientItem::SetItemRects`\).  
  
 EXTENT de CONTÊINER é um pouco mais complexa calcular.  Se o contêiner chamou `COleServerItem::OnSetExtent` \(com uma chamada a `COleClientItem::SetExtent`\), então EXTENT de CONTÊINER esse valor é convertido em pixels com base no número de pixels por polegada lógica.  Se o contêiner não chamou SetExtent \(que é geralmente o caso\), então EXTENT de CONTÊINER é o tamanho de `COleServerItem::OnGetExtent`retornado.  Assim, se o contêiner não chamou SetExtent, a estrutura pressupõe que se tivesse o contêiner o chamaria com a 100% da extensão natural \(o valor retornado de **COleServerItem::GetExtent**\).  De outro modo, a estrutura supõe que o contêiner está exibindo 100% \(não mais, nenhum menos\) do item.  
  
 É importante observar que embora `COleServerItem::OnSetExtent` e `COleServerItem::OnGetExtent` tenham nomes semelhantes, não manipulam o mesmo atributo do item.  `OnSetExtent` é chamado para deixar o servidor saber quantos do objeto é visível no contêiner \(independentemente do fator de zoom\) e `OnGetExtent` é chamado pelo contêiner para determinar o tamanho ideal do objeto.  
  
 Examinando cada uma das APIs envolvidos, você poderá obter uma imagem mais limpa:  
  
## COleServerItem::OnGetExtent  
 Essa função deve retornar “o tamanho natural” em unidades de HIMETRIC do item.  A melhor maneira de entender “natural de tamanho” é defini\-la como o tamanho que podem aparecer quando impresso.  O tamanho é retornado é constante para conteúdo de um item de detalhes \(bem como o metarquivo, que é constante para um item específico\).  Esse tamanho não se altera ao aplicar zoom é aplicado ao item.  Geralmente não se altera quando o contêiner do item mais ou menos espaço chamando `OnSetExtent`.  Um exemplo de uma alteração pode ser o de um editor de texto simples sem o recurso de “margem” que o texto definido com base na extensão a última enviados pelo contêiner.  Se um servidor for alterado, o servidor deve provavelmente definir o bit de OLEMISC\_RECOMPOSEONRESIZE no Registro do sistema \(consulte a documentação do SDK do OLE para obter mais informações sobre essa opção\).  
  
## COleServerItem::OnSetExtent  
 Essa função é chamada quando o contêiner mostrará “mais ou menos” do objeto.  A maioria de chamarão não este contêiner de todos eles.  A implementação padrão armazena o último valor recebida do contêiner em “m\_sizeExtent”, que é usado em `COleServerDoc::GetZoomFactor` ao calcular o valor de EXTENT de CONTÊINER descrito acima.  
  
## COleServerDoc::OnSetItemRects  
 Essa função é chamada somente quando o documento é ativo no local.  É chamada quando o contêiner atualiza qualquer a posição ou recuo do item aplicada ao item.  O RETÂNGULO de POSIÇÃO, como descrito acima, fornece o numerador para o cálculo do fator de zoom.  Um servidor pode solicitar que a posição do item seja alterada chamando `COleServerDoc::RequestPositionChange`.  O contêiner pode ou não pode responder a essa solicitação chamando `OnSetItemRects` \(com uma chamada a **COleServerItem::SetItemRects**\).  
  
## COleServerDoc::OnDraw  
 É importante observar que o metarquivo criado substituindo de `COleServerItem::OnDraw` gerencia exatamente o mesmo metarquivo, independentemente do fator de zoom atual.  O contêiner dimensionará o metarquivo conforme apropriado.  Essa é uma diferença importante entre `OnDraw` de exibição e `OnDraw`do item do servidor.  A exibição trata zoom, o cria apenas um item e as folhas *zoomable* EMF ele até o contêiner para fazer zoom apropriado.  
  
 A melhor maneira de assegurar que seu servidor se comporta adequadamente é usar a implementação de `COleServerDoc::GetZoomFactor` se o documento está ativa no local.  
  
## Suporte de MFC para redimensionar in\-loco  
 MFC O implementa totalmente a interface redimensionando in\-loco como descrito na especificação OLE 2.  A interface do usuário tem suporte da classe de `COleResizeBar` , uma mensagem **WM\_SIZECHILD**personalizadas, e a manipulação especial dessa mensagem em `COleIPFrameWnd`.  
  
 Você pode querer implementar a manipulação diferente da mensagem do que é fornecido pela estrutura.  Como descrito acima, a estrutura permite que os resultados redimensionar in\-loco até o contêiner — o servidor responde à alteração no fator de zoom.  Se o contêiner estiver definindo EXTENT de CONTÊINER e o RETÂNGULO de POSIÇÃO durante o processamento do `COleClientItem::OnChangeItemPosition` \(chamado no resultado de uma chamada a `COleServerDoc::RequestPositionChange`\) em que o é redimensionada resultarão na exibição “mais ou menos” do item na janela de edição.  Se o contêiner estiver apenas a definição do RETÂNGULO de POSIÇÃO durante o processamento de `COleClientItem::OnChangeItemPosition`, o fator de zoom será alterado e o item será mostrado ampliado ou “out”.  
  
 Um servidor pode controlar \(até certo ponto\) o que ocorre durante essa negociação.  Uma planilha, por exemplo pode optar por exibir mais ou menos células quando o usuário redimensionar a janela para editar o item no local.  Um direita de tratamento de textos pode optar por alterar as margens de “página” eles são as mesmas que a janela e o rewrap o texto para a nova margem.  Os servidores implementam isso alterando a extensão natural \(o tamanho retornado de `COleServerItem::OnGetExtent`\) quando redimensionar será feito.  Isso fará com que o RETÂNGULO de POSIÇÃO e EXTENT de CONTÊINER a alteração pela mesma quantidade, resultando no mesmo fator de zoom, mas uma área exibindo maior ou menor.  Além disso, mais ou menos do documento serão visíveis em metarquivo gerado por `OnDraw`.  Nesse caso, o próprio documento está alterando quando o usuário redimensiona o item, em vez de apenas da área de exibição.  
  
 Você pode implementar o personalizado que é redimensionado e ainda aproveitar a interface do usuário fornecida por `COleResizeBar` substituindo a mensagem de **WM\_SIZECHILD** em sua classe de `COleIPFrameWnd` .  Para obter mais informações sobre específicos de **WM\_SIZECHILD**, consulte [Observação 24 técnica](../mfc/tn024-mfc-defined-messages-and-resources.md).  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)