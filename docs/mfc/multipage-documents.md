---
title: Documentos Multipágina | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fb7362e7b9ccb15d338c09da337a6af5077a9789
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929868"
---
# <a name="multipage-documents"></a>Documentos multipágina
Este artigo descreve o protocolo de impressão do Windows e explica como imprimir documentos que contêm mais de uma página. O artigo aborda os seguintes tópicos:  
  
-   [Protocolo de impressão](#_core_the_printing_protocol)  
  
-   [Substituindo funções da classe de exibição](#_core_overriding_view_class_functions)  
  
-   [Paginação](#_core_pagination)  
  
-   [Páginas de impressora versus páginas do documento](#_core_printer_pages_vs.._document_pages)  
  
-   [Paginação de tempo de impressão](#_core_print.2d.time_pagination)  
  
##  <a name="_core_the_printing_protocol"></a> O protocolo de impressão  
 Para imprimir um documento de várias páginas, a estrutura e o modo de exibição interagem da seguinte maneira. Primeiro mostra a estrutura de **impressão** caixa de diálogo, cria um contexto de dispositivo para a impressora e chama o [StartDoc](../mfc/reference/cdc-class.md#startdoc) função membro do [CDC](../mfc/reference/cdc-class.md) objeto. Em seguida, para cada página do documento, o framework chama o [StartPage](../mfc/reference/cdc-class.md#startpage) função membro do `CDC` de objeto, instrui o objeto de exibição para imprimir a página e chama o [página final](../mfc/reference/cdc-class.md#endpage) função de membro. Se o modo de impressora deve ser alterado antes de iniciar uma determinada página, o modo de exibição chama [ResetDC](../mfc/reference/cdc-class.md#resetdc), que atualiza o [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura que contém as novas informações de modo de impressora. Quando o documento inteiro tiver sido impresso, o framework chama o [EndDoc](../mfc/reference/cdc-class.md#enddoc) função de membro.  
  
##  <a name="_core_overriding_view_class_functions"></a> Substituindo funções da classe de exibição  
 O [CView](../mfc/reference/cview-class.md) classe define várias funções de membro chamadas pelo framework durante a impressão. Substituindo essas funções em sua classe de exibição, você deve fornecer as conexões entre a lógica de impressão da estrutura e a lógica de impressão da sua classe de exibição. A tabela a seguir lista essas funções de membro.  
  
### <a name="cviews-overridable-functions-for-printing"></a>Funções de substituível do CView para impressão  
  
|Nome|Motivo para substituição|  
|----------|---------------------------|  
|[OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting)|Para inserir valores na caixa de diálogo de impressão, especialmente o tamanho do documento|  
|[OnBeginPrinting](../mfc/reference/cview-class.md#onbeginprinting)|Para alocar fontes ou outros recursos GDI|  
|[OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc)|Para ajustar os atributos do contexto do dispositivo para uma determinada página, ou para fazer paginação de tempo de impressão|  
|[OnPrint](../mfc/reference/cview-class.md#onprint)|Para imprimir uma página específica|  
|[OnEndPrinting](../mfc/reference/cview-class.md#onendprinting)|Desalocar recursos GDI|  
  
 Você pode fazer o processamento relacionados à impressão em outras funções, mas essas funções são aqueles que orientam o processo de impressão.  
  
 A figura a seguir ilustra as etapas envolvidas no processo de impressão e mostra onde cada `CView`de impressão são chamadas de funções de membro. O restante deste artigo explica a maioria dessas etapas mais detalhadamente. Adicionais partes do processo de impressão são descritas no artigo [alocar recursos de GDI](../mfc/allocating-gdi-resources.md).  
  
 ![Imprimindo o processo de loop](../mfc/media/vc37c71.gif "vc37c71")  
O Loop de impressão  
  
##  <a name="_core_pagination"></a> Paginação  
 A estrutura armazena muitas das informações sobre um trabalho de impressão em uma [CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura. Muitos dos valores no `CPrintInfo` pertencem à paginação; esses valores são acessíveis, conforme mostrado na tabela a seguir.  
  
### <a name="page-number-information-stored-in-cprintinfo"></a>Informações de número de páginas armazenadas em CPrintInfo  
  
|Variável de membro ou<br /><br /> nomes de função|Número de página referenciado|  
|-----------------------------------------------|----------------------------|  
|`GetMinPage`/`SetMinPage`|Primeira página do documento|  
|`GetMaxPage`/`SetMaxPage`|Última página do documento|  
|`GetFromPage`|Primeira página a ser impressa|  
|`GetToPage`|Última página a ser impressa|  
|`m_nCurPage`|Página está sendo impressa no momento|  
  
 Início de números de página em 1, ou seja, a primeira página é numerada 1, não em 0. Para obter mais informações sobre esses e outros membros de [CPrintInfo](../mfc/reference/cprintinfo-structure.md), consulte o *referência MFC*.  
  
 No início do processo de impressão, o framework chama o modo de exibição [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) função de membro, passando um ponteiro para um `CPrintInfo` estrutura. O Assistente de aplicativo fornece uma implementação de `OnPreparePrinting` que chama [DoPreparePrinting](../mfc/reference/cview-class.md#doprepareprinting), outra função de membro de `CView`. `DoPreparePrinting` é a função que exibe a caixa de diálogo de impressão e cria um contexto de dispositivo de impressora.  
  
 Neste ponto o aplicativo não sabe quantas páginas são do documento. Ele usa os valores padrão 1 e 0xFFFF para os números da primeira e última página do documento. Se você souber o número de páginas de documento, substituir `OnPreparePrinting` e chamar [SetMaxPage]--brokenlink--(reference/cprintinfo-class.md#setmaxpage) para o `CPrintInfo` estrutura antes de enviá-la para `DoPreparePrinting`. Isso lhe permite especificar o tamanho do documento.  
  
 `DoPreparePrinting` em seguida, exibe a caixa de diálogo de impressão. Quando retorna, o `CPrintInfo` estrutura contém os valores especificados pelo usuário. Se o usuário desejar imprimir apenas um intervalo de páginas selecionado, ele pode especificar o início e término de números de página na caixa de diálogo Imprimir. A estrutura recupera esses valores usando o `GetFromPage` e `GetToPage` funções de [CPrintInfo](../mfc/reference/cprintinfo-structure.md). Se o usuário não especificar um intervalo de página, o framework chama `GetMinPage` e `GetMaxPage` e usa os valores retornados para imprimir o documento inteiro.  
  
 Para cada página de um documento a ser impresso, o framework chama duas funções de membro em sua classe de exibição, [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) e [OnPrint](../mfc/reference/cview-class.md#onprint)e transmite a cada função dois parâmetros: um ponteiro para um [ CDC](../mfc/reference/cdc-class.md) objeto e um ponteiro para um `CPrintInfo` estrutura. Cada vez que a estrutura chama `OnPrepareDC` e `OnPrint`, ele passa um valor diferente no *m_nCurPage* membro do `CPrintInfo` estrutura. Dessa forma o framework informa o modo de exibição que página deve ser impresso.  
  
 O [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) função membro também é usada para exibição na tela. Faz ajustes para o contexto de dispositivo antes de desenho ocorre. `OnPrepareDC` serve uma função semelhante na impressão, mas há algumas diferenças: primeiro, o `CDC` objeto representa um contexto de dispositivo de impressora em vez de um contexto de dispositivo de tela e, segundo, um `CPrintInfo` objeto é passado como um segundo parâmetro. (Esse parâmetro é **nulo** quando `OnPrepareDC` é chamado para exibição na tela.) Substituir `OnPrepareDC` fazer ajustes ao contexto de dispositivo com base em qual página está sendo impressa. Por exemplo, você pode mover a origem do visor e da região de recorte para garantir que a parte apropriada do documento é impresso.  
  
 O [OnPrint](../mfc/reference/cview-class.md#onprint) executa a função de membro a impressão real da página. O artigo [como padrão impressão é feita](../mfc/how-default-printing-is-done.md) mostra como o framework chama [OnDraw](../mfc/reference/cview-class.md#ondraw) com um contexto de dispositivo de impressora para executar a impressão. Mais precisamente, a estrutura chama `OnPrint` com um `CPrintInfo` estrutura e um contexto de dispositivo e `OnPrint` passa o contexto de dispositivo `OnDraw`. Substituir `OnPrint` para executar qualquer processamento que deve ser feito apenas durante a impressão e não para exibição na tela. Por exemplo, para imprimir cabeçalhos ou rodapés de página (consulte o artigo [cabeçalhos e rodapés](../mfc/headers-and-footers.md) para obter mais informações). Em seguida, chame `OnDraw` de substituição do `OnPrint` para fazer o processamento comuns a tela tanto e impressão.  
  
 O fato de que `OnDraw` dá a renderização de ambos tela de exibição e impressão significa que seu aplicativo é WYSIWYG: "o que você vê é o que você obterá." No entanto, suponha que você não estiver escrevendo um aplicativo WYSIWYG. Por exemplo, considere um texto de editor que usa uma fonte em negrito para impressão, mas exibe códigos de controle para indicar o texto em negrito na tela. Em tal situação, você deve usar `OnDraw` estritamente para exibição na tela. Quando você substituir `OnPrint`, substitua a chamada para `OnDraw` com uma chamada para uma função de desenho separada. Essa função desenha o documento a maneira como ele aparece em papel, usando os atributos que não for exibida na tela.  
  
##  <a name="_core_printer_pages_vs.._document_pages"></a> Impressora páginas vs. Páginas do documento  
 Quando você se referir aos números de página, às vezes, é necessário distinguir entre o conceito da impressora de uma página e o conceito de um documento de uma página. Do ponto de vista da impressora, uma página é uma folha de papel. No entanto, uma folha de papel não necessariamente é igual a uma página do documento. Por exemplo, se você estiver imprimindo um boletim informativo, onde as planilhas devem ser dobradas, uma folha de papel pode conter ambos as primeira e última páginas do documento, lado a lado. Da mesma forma, se você estiver imprimindo uma planilha, o documento não consistem em páginas em todos os. Em vez disso, uma folha de papel pode conter linhas de 1 a 20, colunas de 6 a 10.  
  
 A página todos os números no [CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura se referir a páginas da impressora. A estrutura chama `OnPrepareDC` e `OnPrint` uma vez para cada folha de papel que passará por meio da impressora. Quando você substituir o [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) de função para especificar o tamanho do documento, você deve usar páginas de impressora. Se houver uma correspondência (ou seja, uma página de impressora é igual a uma página do documento), e isso é fácil. Se, por outro lado, as páginas do documento e páginas de impressora não correspondem diretamente, você deve converter entre eles. Por exemplo, considere a possibilidade de impressão de uma planilha. Ao substituir `OnPreparePrinting`, você deve calcular quantas folhas de papel serão necessárias para imprimir a planilha inteira e, em seguida, use esse valor ao chamar o `SetMaxPage` função de membro `CPrintInfo`. Da mesma forma, ao substituir `OnPrepareDC`, você deve converter *m_nCurPage* dentro do intervalo de linhas e colunas que aparecem nessa planilha específica e, em seguida, ajustar adequadamente a origem do visor.  
  
##  <a name="_core_print.2d.time_pagination"></a> Paginação de tempo de impressão  
 Em algumas situações, a classe de exibição pode não saber com antecedência quanto tempo o documento é até que realmente tiver sido impresso. Por exemplo, suponha que seu aplicativo não WYSIWYG, portanto comprimento do documento na tela não corresponde ao seu tamanho quando impresso.  
  
 Isso faz com que um problema quando você substituir [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting) para sua classe de exibição: você não pode passar um valor para o `SetMaxPage` função do [CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura, porque você não sabe o comprimento de um documento. Se o usuário não especificar um número de página para parar em usando a caixa de diálogo de impressão, a estrutura não sabe quando parar o loop de impressão. É a única maneira de determinar quando parar o loop de impressão imprimir o documento e ver quando ele termina. A classe de exibição deve verificar para o fim do documento enquanto ele está sendo impressa e informe o framework quando é atingido o fim.  
  
 A estrutura se baseia em sua classe de exibição [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) função para informá-lo quando parar. Após cada chamada para `OnPrepareDC`, verifica se a estrutura de um membro do `CPrintInfo` estrutura chamada *m_bContinuePrinting*. O valor padrão é **TRUE.** Desde que ela permaneça isso, o framework continua o loop de impressão. Se for definido como **FALSE**, as paradas do framework. Para realizar a paginação de tempo de impressão, substituir `OnPrepareDC` para verificar se o fim do documento foi atingido e definir *m_bContinuePrinting* para **FALSE** quando ele tem.  
  
 A implementação padrão de `OnPrepareDC` define *m_bContinuePrinting* para **FALSE** se a página atual for maior que 1. Isso significa que, se o comprimento do documento não foi especificado, o framework pressupõe que o documento é uma página longa. Uma consequência disso é que você deve ter cuidado se você chamar a versão da classe base de `OnPrepareDC`. Não presuma que *m_bContinuePrinting* será **TRUE** após chamar a versão da classe base.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)  
  
-   [Alocando recursos GDI](../mfc/allocating-gdi-resources.md)  
  
## <a name="see-also"></a>Consulte também  
 [Impressão](../mfc/printing.md)   
 [Classe CView](../mfc/reference/cview-class.md)   
 [Classe CDC](../mfc/reference/cdc-class.md)