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
ms.openlocfilehash: 87912c06a40740d25530235ee421c6c8bfa11aab
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370732"
---
# <a name="multipage-documents"></a>Documentos multipágina

Este artigo descreve o protocolo de impressão do Windows e explica como imprimir documentos que contenham mais de uma página. O artigo aborda os seguintes tópicos:

- [Protocolo de impressão](#_core_the_printing_protocol)

- [Funções de classe de exibição sobrepostas](#_core_overriding_view_class_functions)

- [Paginação](#_core_pagination)

- [Páginas da impressora vs. páginas de documentos](#_core_printer_pages_vs.._document_pages)

- [Paginação por tempo de impressão](#_core_print.2d.time_pagination)

## <a name="the-printing-protocol"></a><a name="_core_the_printing_protocol"></a>O Protocolo de Impressão

Para imprimir um documento de várias páginas, a estrutura e a visualização interagem da seguinte maneira. Primeiro, a estrutura exibe a caixa de diálogo **Imprimir,** cria um contexto de dispositivo para a impressora e chama a função de membro [StartDoc](../mfc/reference/cdc-class.md#startdoc) do objeto [CDC.](../mfc/reference/cdc-class.md) Em seguida, para cada página do documento, a estrutura `CDC` chama a função de membro [StartPage](../mfc/reference/cdc-class.md#startpage) do objeto, instrui o objeto de exibição a imprimir a página e chama a função membro [EndPage.](../mfc/reference/cdc-class.md#endpage) Se o modo de impressora deve ser alterado antes de iniciar uma determinada página, a exibição chama [ResetDC](../mfc/reference/cdc-class.md#resetdc), que atualiza a estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) contendo as novas informações do modo de impressora. Quando todo o documento foi impresso, a estrutura chama a função de membro [EndDoc.](../mfc/reference/cdc-class.md#enddoc)

## <a name="overriding-view-class-functions"></a><a name="_core_overriding_view_class_functions"></a>Substituindo funções de classe de exibição

A classe [CView](../mfc/reference/cview-class.md) define várias funções de membro que são chamadas pela framework durante a impressão. Ao sobrepor essas funções em sua classe de visualização, você fornece as conexões entre a lógica de impressão da estrutura e a lógica de impressão da sua classe de visualização. A tabela a seguir lista essas funções de membro.

### <a name="cviews-overridable-functions-for-printing"></a>Funções superridable do CView para impressão

|Nome|Razão para sobrepor|
|----------|---------------------------|
|[Onprepareprinting](../mfc/reference/cview-class.md#onprepareprinting)|Para inserir valores na caixa de diálogo Imprimir, especialmente o comprimento do documento|
|[Onbeginprinting](../mfc/reference/cview-class.md#onbeginprinting)|Para alocar fontes ou outros recursos GDI|
|[Onpreparedc](../mfc/reference/cview-class.md#onpreparedc)|Para ajustar atributos do contexto do dispositivo para uma determinada página ou para fazer paginação em tempo de impressão|
|[Onprint](../mfc/reference/cview-class.md#onprint)|Para imprimir uma determinada página|
|[Onendprinting](../mfc/reference/cview-class.md#onendprinting)|Para desalocar recursos gdi|

Você pode fazer processamento relacionado à impressão em outras funções também, mas essas funções são as que impulsionam o processo de impressão.

A figura a seguir ilustra as etapas envolvidas `CView`no processo de impressão e mostra onde cada uma das funções do membro de impressão é chamada. O resto deste artigo explica a maioria dessas etapas com mais detalhes. Partes adicionais do processo de impressão são descritas no artigo [Alocando Recursos GDI](../mfc/allocating-gdi-resources.md).

![Processo de loop de impressão](../mfc/media/vc37c71.gif "Processo de loop de impressão") <br/>
O loop de impressão

## <a name="pagination"></a><a name="_core_pagination"></a>Paginação

A estrutura armazena grande parte das informações sobre um trabalho de impressão em uma estrutura [CPrintInfo.](../mfc/reference/cprintinfo-structure.md) Vários dos valores `CPrintInfo` relativos à paginação; esses valores são acessíveis conforme mostrado na tabela a seguir.

### <a name="page-number-information-stored-in-cprintinfo"></a>Informações do número da página armazenadas no CPrintInfo

|Variável membro ou<br /><br /> nome da função(s)|Número da página referenciado|
|-----------------------------------------------|----------------------------|
|`GetMinPage`/`SetMinPage`|Primeira página do documento|
|`GetMaxPage`/`SetMaxPage`|Última página do documento|
|`GetFromPage`|Primeira página a ser impressa|
|`GetToPage`|Última página a ser impressa|
|`m_nCurPage`|Página atualmente sendo impressa|

Os números da página começam em 1, ou seja, a primeira página é numerada 1, não 0. Para obter mais informações sobre esses e outros membros do [CPrintInfo,](../mfc/reference/cprintinfo-structure.md)consulte o *MFC Reference*.

No início do processo de impressão, a estrutura chama a função de membro `CPrintInfo` [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) da exibição, passando um ponteiro para uma estrutura. O Assistente de Aplicativo `OnPreparePrinting` fornece uma implementação das `CView`chamadas [DoPreparePrinting](../mfc/reference/cview-class.md#doprepareprinting), outra função de membro de . `DoPreparePrinting`é a função que exibe a caixa de diálogo Imprimir e cria um contexto de dispositivo de impressora.

Neste momento, o aplicativo não sabe quantas páginas estão no documento. Ele usa os valores padrão 1 e 0xFFFF para os números da primeira e última página do documento. Se você souber quantas páginas seu `OnPreparePrinting` documento tem, anular e chamar [SetMaxPage]--brokenlink--(referência/cprintinfo-class.md#setmaxpage) para a `CPrintInfo` estrutura antes de enviá-lo para `DoPreparePrinting`. Isso permite que você especifique o comprimento do seu documento.

`DoPreparePrinting`em seguida, exibe a caixa de diálogo Imprimir. Quando retorna, `CPrintInfo` a estrutura contém os valores especificados pelo usuário. Se o usuário desejar imprimir apenas uma gama selecionada de páginas, ele ou ela pode especificar os números de página inicial e final na caixa de diálogo Imprimir. A estrutura recupera esses `GetFromPage` valores usando as funções do `GetToPage` [CPrintInfo](../mfc/reference/cprintinfo-structure.md). Se o usuário não especificar um intervalo `GetMinPage` `GetMaxPage` de página, a estrutura liga e usa os valores retornados para imprimir todo o documento.

Para cada página de um documento a ser impresso, a estrutura chama duas funções de membro em sua classe de exibição, [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) e [OnPrint](../mfc/reference/cview-class.md#onprint), e passa cada função dois parâmetros: um ponteiro para um objeto [CDC](../mfc/reference/cdc-class.md) e um ponteiro para uma `CPrintInfo` estrutura. Cada vez que `OnPrepareDC` `OnPrint`o quadro chama e , ele `CPrintInfo` passa um valor diferente no *m_nCurPage* membro da estrutura. Desta forma, o framework informa a exibição de qual página deve ser impressa.

A função de membro [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) também é usada para exibição de tela. Ele faz ajustes no contexto do dispositivo antes do desenho ocorrer. `OnPrepareDC`serve a um papel semelhante na impressão, mas há `CDC` algumas diferenças: primeiro, o objeto representa um contexto `CPrintInfo` de dispositivo de impressora em vez de um contexto de dispositivo de tela, e segundo, um objeto é passado como um segundo parâmetro. (Este parâmetro é `OnPrepareDC` **NULO** quando é chamado para exibição de tela.) Substituir `OnPrepareDC` para fazer ajustes no contexto do dispositivo com base em qual página está sendo impressa. Por exemplo, você pode mover a origem do viewport e a região de recorte para garantir que a parte apropriada do documento seja impressa.

A função [membro OnPrint](../mfc/reference/cview-class.md#onprint) executa a impressão real da página. O artigo [How Default Printing Is Done](../mfc/how-default-printing-is-done.md) mostra como a estrutura chama o [OnDraw](../mfc/reference/cview-class.md#ondraw) com um contexto de dispositivo de impressora para executar a impressão. Mais precisamente, a `OnPrint` estrutura `CPrintInfo` chama com uma `OnPrint` estrutura e um `OnDraw`contexto de dispositivo, e passa o contexto do dispositivo para . Substituir `OnPrint` para executar qualquer renderização que deve ser feita apenas durante a impressão e não para exibição de tela. Por exemplo, para imprimir cabeçalhos ou rodapés (consulte o artigo [Cabeçalhos e Rodapés](../mfc/headers-and-footers.md) para obter mais informações). Em `OnDraw` seguida, ligue `OnPrint` a partir do dispositivo de fazer a renderização comum tanto à exibição quanto à impressão da tela.

O fato `OnDraw` de fazer a renderização tanto para exibição de tela quanto para impressão significa que sua aplicação é WYSIWYG: "O que você vê é o que você recebe." No entanto, suponha que você não está escrevendo um aplicativo WYSIWYG. Por exemplo, considere um editor de texto que use uma fonte em negrito para impressão, mas exiba códigos de controle para indicar texto em negrito na tela. Em tal situação, `OnDraw` você usa estritamente para exibição de tela. Quando você `OnPrint`substituir, substitua `OnDraw` a chamada por uma chamada para uma função de desenho separada. Essa função desenha o documento da maneira como ele aparece no papel, usando os atributos que você não exibe na tela.

## <a name="printer-pages-vs-document-pages"></a><a name="_core_printer_pages_vs.._document_pages"></a>Páginas da impressora vs. Páginas de documentos

Quando você se refere a números de página, às vezes é necessário distinguir entre o conceito de uma página da impressora e o conceito de uma página de um documento. Do ponto de vista da impressora, uma página é uma folha de papel. No entanto, uma folha de papel não é necessariamente igual a uma página do documento. Por exemplo, se você estiver imprimindo um boletim informativo, onde as folhas devem ser dobradas, uma folha de papel pode conter as primeiras e últimas páginas do documento, lado a lado. Da mesma forma, se você estiver imprimindo uma planilha, o documento não consiste em páginas. Em vez disso, uma folha de papel pode conter linhas 1 a 20, colunas 6 a 10.

Todos os números de página na estrutura [CPrintInfo](../mfc/reference/cprintinfo-structure.md) referem-se a páginas de impressora. A estrutura `OnPrepareDC` `OnPrint` chama e uma vez para cada folha de papel que passará pela impressora. Quando você substituir a função [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) para especificar o comprimento do documento, você deve usar páginas da impressora. Se houver uma correspondência um-para-um (ou seja, uma página de impressora é igual a uma página de documento), então isso é fácil. Se, por outro lado, páginas de documentos e páginas de impressora não corresponderem diretamente, você deve traduzir entre elas. Por exemplo, considere imprimir uma planilha. Ao sobrepor, `OnPreparePrinting`você deve calcular quantas folhas de papel serão necessárias para imprimir `SetMaxPage` toda `CPrintInfo`a planilha e, em seguida, usar esse valor ao chamar a função de membro de . Da mesma forma, `OnPrepareDC`ao substituindo, você deve traduzir *m_nCurPage* para a gama de linhas e colunas que aparecerão nessa planilha em particular e, em seguida, ajustar a origem do viewport de acordo.

## <a name="print-time-pagination"></a><a name="_core_print.2d.time_pagination"></a>Paginação em tempo de impressão

Em algumas situações, sua classe de visualização pode não saber com antecedência quanto tempo o documento tem até que ele tenha sido realmente impresso. Por exemplo, suponha que seu aplicativo não seja WYSIWYG, de modo que o comprimento de um documento na tela não corresponde ao seu comprimento quando impresso.

Isso causa um problema quando você anula [o OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) para sua classe `SetMaxPage` de visualização: você não pode passar um valor para a função da estrutura [CPrintInfo,](../mfc/reference/cprintinfo-structure.md) porque você não sabe o comprimento de um documento. Se o usuário não especificar um número de página para parar de usar a caixa de diálogo Imprimir, a estrutura não saberá quando parar o loop de impressão. A única maneira de determinar quando parar o loop de impressão é imprimir o documento e ver quando ele termina. Sua classe de visualização deve verificar o final do documento enquanto ele está sendo impresso e, em seguida, informar o framework quando o final é atingido.

O framework conta com a função [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) da sua classe de visualização para dizer quando parar. Após cada `OnPrepareDC`chamada, o quadro verifica `CPrintInfo` um membro da estrutura chamado *m_bContinuePrinting*. Seu valor padrão é **TRUE.** Enquanto permanecer assim, a estrutura continua o loop de impressão. Se for definido como **FALSE,** a estrutura pára. Para realizar a paginação em `OnPrepareDC` tempo de impressão, anule-se para verificar se o final do documento foi atingido e defina *m_bContinuePrinting* como **FALSO** quando tiver.

A implementação `OnPrepareDC` padrão de conjuntos *m_bContinuePrinting* para **FALSE** se a página atual for maior que 1. Isso significa que, se o comprimento do documento não foi especificado, a estrutura assume que o documento tem uma página de comprimento. Uma consequência disso é que você deve ter cuidado `OnPrepareDC`se você chamar a versão de classe base de . Não assuma que *m_bContinuePrinting* será VERDADEIRA depois **de** chamar a versão de classe base.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)

- [Alocação de recursos GDI](../mfc/allocating-gdi-resources.md)

## <a name="see-also"></a>Confira também

[Imprimindo](../mfc/printing.md)<br/>
[Classe CView](../mfc/reference/cview-class.md)<br/>
[Classe CDC](../mfc/reference/cdc-class.md)
