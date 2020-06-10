---
title: Documentos multipágina
ms.date: 11/19/2018
helpviewer_keywords:
- pagination [MFC]
- overriding [MFC], View class functions for printing
- OnPrepareDC method [MFC]
- CPrintInfo structure [MFC], multipage documents
- OnEndPrinting method [MFC]
- protocols [MFC], printing protocol
- document pages vs. printer pages [MFC]
- printer mode [MFC]
- printing [MFC], multipage documents
- printers [MFC], printer mode
- documents [MFC], printing
- OnPreparePrinting method [MFC]
- OnPrint method [MFC]
- DoPreparePrinting method and pagination [MFC]
- OnDraw method [MFC], printing
- pagination [MFC], printing multipage documents
- printing [MFC], protocol
- pages [MFC], printing
- OnBeginPrinting method [MFC]
- multipage documents [MFC]
- printing [MFC], pagination
- documents [MFC], paginating
ms.assetid: 69626b86-73ac-4b74-b126-9955034835ef
ms.openlocfilehash: c73692c315b07d6b690180886d494ee12f85f52d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621048"
---
# <a name="multipage-documents"></a>Documentos multipágina

Este artigo descreve o protocolo de impressão do Windows e explica como imprimir documentos que contêm mais de uma página. O artigo aborda os seguintes tópicos:

- [Protocolo de impressão](#_core_the_printing_protocol)

- [Substituindo funções de classe de exibição](#_core_overriding_view_class_functions)

- [Pagina](#_core_pagination)

- [Páginas da impressora versus páginas do documento](#_core_printer_pages_vs.._document_pages)

- [Paginação de tempo de impressão](#_core_print.2d.time_pagination)

## <a name="the-printing-protocol"></a><a name="_core_the_printing_protocol"></a>O protocolo de impressão

Para imprimir um documento de multipáginas, a estrutura e a exibição interagem da seguinte maneira. Primeiro, a estrutura exibe a caixa de diálogo **Imprimir** , cria um contexto de dispositivo para a impressora e chama a função de membro [StartDoc](reference/cdc-class.md#startdoc) do objeto [CDC](reference/cdc-class.md) . Em seguida, para cada página do documento, a estrutura chama a função de membro [Startpage](reference/cdc-class.md#startpage) do `CDC` objeto, instrui o objeto View para imprimir a página e chama a função de membro [EndPage](reference/cdc-class.md#endpage) . Se o modo de impressora precisar ser alterado antes de iniciar uma página específica, a exibição chamará [ResetDC](reference/cdc-class.md#resetdc), que atualizará a estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) que contém as novas informações do modo de impressora. Quando todo o documento tiver sido impresso, a estrutura chamará a função de membro [EndDoc](reference/cdc-class.md#enddoc) .

## <a name="overriding-view-class-functions"></a><a name="_core_overriding_view_class_functions"></a>Substituindo funções de classe de exibição

A classe [cvisualização](reference/cview-class.md) define várias funções de membro que são chamadas pelo Framework durante a impressão. Ao substituir essas funções em sua classe View, você fornece as conexões entre a lógica de impressão da estrutura e a lógica de impressão da sua classe View. A tabela a seguir lista essas funções de membro.

### <a name="cviews-overridable-functions-for-printing"></a>Funções substituíveis do Cvisualização para impressão

|Name|Motivo da substituição|
|----------|---------------------------|
|[OnPreparePrinting](reference/cview-class.md#onprepareprinting)|Para inserir valores na caixa de diálogo Imprimir, especialmente o comprimento do documento|
|[OnBeginPrinting](reference/cview-class.md#onbeginprinting)|Para alocar fontes ou outros recursos GDI|
|[OnPrepareDC](reference/cview-class.md#onpreparedc)|Para ajustar os atributos do contexto do dispositivo para uma determinada página ou para a paginação do tempo de impressão|
|[OnPrint](reference/cview-class.md#onprint)|Para imprimir uma determinada página|
|[OnEndPrinting](reference/cview-class.md#onendprinting)|Para desalocar recursos GDI|

Você pode fazer o processamento relacionado à impressão em outras funções também, mas essas funções são aquelas que orientam o processo de impressão.

A figura a seguir ilustra as etapas envolvidas no processo de impressão e mostra onde cada uma das `CView` funções de membro de impressão são chamadas. O restante deste artigo explica a maioria dessas etapas mais detalhadamente. Partes adicionais do processo de impressão são descritas no artigo [alocando recursos GDI](allocating-gdi-resources.md).

![Processo de loop de impressão](../mfc/media/vc37c71.gif "Processo de loop de impressão") <br/>
O loop de impressão

## <a name="pagination"></a><a name="_core_pagination"></a>Pagina

A estrutura armazena grande parte das informações sobre um trabalho de impressão em uma estrutura [CPrintInfo](reference/cprintinfo-structure.md) . Vários dos valores em `CPrintInfo` pertencem à paginação; esses valores são acessíveis como mostrado na tabela a seguir.

### <a name="page-number-information-stored-in-cprintinfo"></a>Informações de número de página armazenadas no CPrintInfo

|Variável de membro ou<br /><br /> nome (s) da função|Número de página referenciado|
|-----------------------------------------------|----------------------------|
|`GetMinPage`/`SetMinPage`|Primeira página do documento|
|`GetMaxPage`/`SetMaxPage`|Última página do documento|
|`GetFromPage`|Primeira página a ser impressa|
|`GetToPage`|Última página a ser impressa|
|`m_nCurPage`|Página sendo impressa no momento|

Os números de página começam em 1, ou seja, a primeira página é numerada 1, não 0. Para obter mais informações sobre esses e outros membros de [CPrintInfo](reference/cprintinfo-structure.md), consulte a *referência do MFC*.

No início do processo de impressão, a estrutura chama a função de membro [OnPreparePrinting](reference/cview-class.md#onprepareprinting) da exibição, passando um ponteiro para uma `CPrintInfo` estrutura. O assistente de aplicativo fornece uma implementação do `OnPreparePrinting` que chama [DoPreparePrinting](reference/cview-class.md#doprepareprinting), outra função membro de `CView` . `DoPreparePrinting`é a função que exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo de impressora.

Neste ponto, o aplicativo não sabe quantas páginas estão no documento. Ele usa os valores padrão 1 e 0xFFFF para os números da primeira e da última página do documento. Se você souber quantas páginas seu documento tem, substitua `OnPreparePrinting` e chame [SetMaxPage]--brokenlink--(Reference/CPrintInfo-Class. MD # SetMaxPage) para a `CPrintInfo` estrutura antes de enviá-la para `DoPreparePrinting` . Isso permite que você especifique o tamanho do documento.

`DoPreparePrinting`em seguida, exibe a caixa de diálogo Imprimir. Quando retorna, a `CPrintInfo` estrutura contém os valores especificados pelo usuário. Se o usuário quiser imprimir apenas um intervalo de páginas selecionado, ele poderá especificar os números de página inicial e final na caixa de diálogo Imprimir. A estrutura recupera esses valores usando as `GetFromPage` `GetToPage` funções e do [CPrintInfo](reference/cprintinfo-structure.md). Se o usuário não especificar um intervalo de páginas, a estrutura chamará `GetMinPage` e `GetMaxPage` usará os valores retornados para imprimir o documento inteiro.

Para cada página de um documento a ser impresso, a estrutura chama duas funções de membro em sua classe View, [OnPrepareDC](reference/cview-class.md#onpreparedc) e [OnPrint](reference/cview-class.md#onprint), e passa cada função dois parâmetros: um ponteiro para um objeto [CDC](reference/cdc-class.md) e um ponteiro para uma `CPrintInfo` estrutura. Cada vez que a estrutura chama `OnPrepareDC` e `OnPrint` , ela passa um valor diferente no membro *m_nCurPage* da `CPrintInfo` estrutura. Dessa forma, a estrutura informa ao modo de exibição qual página deve ser impressa.

A função de membro [OnPrepareDC](reference/cview-class.md#onpreparedc) também é usada para exibição de tela. Ele faz ajustes no contexto do dispositivo antes que o desenho ocorra. `OnPrepareDC`o serve para uma função semelhante na impressão, mas há algumas diferenças: primeiro, o `CDC` objeto representa um contexto de dispositivo de impressora em vez de um contexto de dispositivo de tela e, segundo, um `CPrintInfo` objeto é passado como um segundo parâmetro. (Esse parâmetro é **nulo** quando `OnPrepareDC` é chamado para exibição de tela.) Substitua `OnPrepareDC` para fazer ajustes no contexto do dispositivo com base em qual página está sendo impressa. Por exemplo, você pode mover a origem do visor e a região de recorte para garantir que a parte apropriada do documento seja impressa.

A função de membro [OnPrint](reference/cview-class.md#onprint) executa a impressão real da página. O artigo [como a impressão padrão é feita](how-default-printing-is-done.md) mostra como a estrutura chama [OnDraw](reference/cview-class.md#ondraw) com um contexto de dispositivo de impressora para executar a impressão. Mais precisamente, a estrutura chama `OnPrint` uma `CPrintInfo` estrutura e um contexto de dispositivo e `OnPrint` passa o contexto do dispositivo para `OnDraw` . Substitua `OnPrint` para executar qualquer renderização que deve ser feita somente durante a impressão e não para exibição de tela. Por exemplo, para imprimir cabeçalhos ou rodapés (consulte o artigo [cabeçalhos e rodapés](headers-and-footers.md) para obter mais informações). Em seguida, chame `OnDraw` da substituição de `OnPrint` para fazer a renderização comum para exibição e impressão de tela.

O fato de que `OnDraw` a renderização para exibição de tela e impressão significa que seu aplicativo é WYSIWYG: "o que você vê é o que você obtém". No entanto, suponha que você não esteja escrevendo um aplicativo WYSIWYG. Por exemplo, considere um editor de texto que usa uma fonte em negrito para impressão, mas exibe códigos de controle para indicar texto em negrito na tela. Nessa situação, você usa `OnDraw` estritamente para exibição de tela. Quando você substituir `OnPrint` , substitua a chamada para `OnDraw` por uma chamada para uma função de desenho separada. Essa função desenha o documento da maneira que aparece no papel, usando os atributos que você não exibe na tela.

## <a name="printer-pages-vs-document-pages"></a><a name="_core_printer_pages_vs.._document_pages"></a>Páginas da impressora versus páginas do documento

Quando você se refere a números de página, às vezes é necessário distinguir entre o conceito da impressora e o conceito de um documento de uma página. Do ponto de vista da impressora, uma página é uma folha de papel. No entanto, uma folha de papel não necessariamente é igual a uma página do documento. Por exemplo, se você estiver imprimindo um boletim informativo, onde as planilhas devem ser dobradas, uma folha de papel poderá conter a primeira e a última páginas do documento, lado a lado. Da mesma forma, se você estiver imprimindo uma planilha, o documento não consistirá em páginas. Em vez disso, uma folha de papel pode conter as linhas de 1 a 20, colunas 6 a 10.

Todos os números de página na estrutura [CPrintInfo](reference/cprintinfo-structure.md) se referem a páginas da impressora. A estrutura chama `OnPrepareDC` e `OnPrint` uma vez para cada folha de papel que passará pela impressora. Ao substituir a função [OnPreparePrinting](reference/cview-class.md#onprepareprinting) para especificar o comprimento do documento, você deve usar as páginas da impressora. Se houver uma correspondência um-para-um (ou seja, uma página de impressora é igual a uma página de documento), isso é fácil. Se, por outro lado, as páginas de documentos e as páginas da impressora não corresponderem diretamente, você deverá fazer a conversão entre elas. Por exemplo, considere imprimir uma planilha. Ao substituir `OnPreparePrinting` , você deve calcular quantas folhas de papel serão necessárias para imprimir toda a planilha e, em seguida, usar esse valor ao chamar a `SetMaxPage` função de membro do `CPrintInfo` . Da mesma forma, ao substituir `OnPrepareDC` , você deve converter *m_nCurPage* no intervalo de linhas e colunas que aparecerão nessa planilha específica e, em seguida, ajustar a origem do visor de acordo.

## <a name="print-time-pagination"></a><a name="_core_print.2d.time_pagination"></a>Paginação de tempo de impressão

Em algumas situações, a classe View pode não saber com antecedência por quanto tempo o documento é até que tenha sido realmente impresso. Por exemplo, suponha que seu aplicativo não seja WYSIWYG, portanto, o comprimento de um documento na tela não corresponde ao seu comprimento quando impresso.

Isso causa um problema quando você substitui [OnPreparePrinting](reference/cview-class.md#onprepareprinting) para sua classe de exibição: não é possível passar um valor para a `SetMaxPage` função da estrutura [CPrintInfo](reference/cprintinfo-structure.md) , pois você não sabe o comprimento de um documento. Se o usuário não especificar um número de página para parar usando a caixa de diálogo Imprimir, a estrutura não saberá quando parar o loop de impressão. A única maneira de determinar quando parar o loop de impressão é imprimir o documento e ver quando ele termina. Sua classe de exibição deve verificar o fim do documento enquanto ele está sendo impresso e informar a estrutura quando o final for atingido.

A estrutura depende da função [OnPrepareDC](reference/cview-class.md#onpreparedc) da sua classe View para informar quando parar. Depois de cada chamada para `OnPrepareDC` , a estrutura verifica um membro da `CPrintInfo` estrutura chamada *m_bContinuePrinting*. Seu valor padrão é **true.** Desde que permaneça assim, a estrutura continuará o loop de impressão. Se estiver definido como **false**, o Framework será interrompido. Para executar a paginação de tempo de impressão, substitua `OnPrepareDC` para verificar se o fim do documento foi atingido e defina *M_bContinuePrinting* como **false** quando ele tiver.

A implementação padrão de `OnPrepareDC` conjuntos *M_bContinuePrinting* como **false** se a página atual for maior que 1. Isso significa que, se o comprimento do documento não tiver sido especificado, a estrutura pressupõe que o documento é uma página longa. Uma consequência disso é que você deve ter cuidado se chamar a versão da classe base do `OnPrepareDC` . Não presuma que *m_bContinuePrinting* será **true** depois de chamar a versão da classe base.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Cabeçalhos e rodapés](headers-and-footers.md)

- [Alocando recursos GDI](allocating-gdi-resources.md)

## <a name="see-also"></a>Consulte também

[Impressão](printing.md)<br/>
[Classe CView](reference/cview-class.md)<br/>
[Classe CDC](reference/cdc-class.md)
