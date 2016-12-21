---
title: "Documentos multip&#225;gina | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CPrintInfo, documentos multipágina"
  - "páginas de documento vs. páginas de impressora"
  - "documentos, paginando"
  - "documentos, imprimindo"
  - "Método DoPreparePrinting e paginação"
  - "documentos multipágina"
  - "Método OnBeginPrinting"
  - "Método OnDraw, imprimindo"
  - "Método OnEndPrinting"
  - "Método OnPrepareDC"
  - "Método OnPreparePrinting"
  - "Método OnPrint"
  - "substituição, Exibir funções de classe para impressão"
  - "páginas, imprimindo"
  - "paginação"
  - "paginação, imprimindo documentos multipágina"
  - "modo de impressora"
  - "impressoras, modo de impressora"
  - "imprimindo [MFC], documentos multipágina"
  - "imprimindo [MFC], paginação"
  - "imprimindo [MFC], protocolo"
  - "protocolos, protocolo de impressão"
ms.assetid: 69626b86-73ac-4b74-b126-9955034835ef
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Documentos multip&#225;gina
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve as janelas que aparecem no protocolo e explica como imprimir os documentos que contêm mais de uma página.  O artigo abrange os seguintes tópicos:  
  
-   [Protocolo de impressão](#_core_the_printing_protocol)  
  
-   [Substituindo funções de classe da exibição](#_core_overriding_view_class_functions)  
  
-   [Paginação](#_core_pagination)  
  
-   [Páginas da impressora em páginas do documento](#_core_printer_pages_vs.._document_pages)  
  
-   [Paginação do com hora](#_core_print.2d.time_pagination)  
  
##  <a name="_core_the_printing_protocol"></a> O protocolo de impressão  
 Para imprimir da seguinte forma um documento com várias páginas, a estrutura e a exibição interativa.  Primeiro a estrutura exibe a caixa de diálogo de **Imprimir** , cria um contexto de dispositivo para a impressora, e chama a função de membro de [StartDoc](../Topic/CDC::StartDoc.md) do objeto de [CDC](../Topic/CDC%20Class.md) .  Então, para cada página do documento, a estrutura chama a função de membro de [StartPage](../Topic/CDC::StartPage.md) do objeto de `CDC` , instrui o objeto de exibição para imprimir a página, e chama a função de membro de [EndPage](../Topic/CDC::EndPage.md) .  Se o modo da impressora deve ser alterado antes de iniciar uma página específica, a exibição chama [ResetDC](../Topic/CDC::ResetDC.md), que atualiza a estrutura de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) que contém a nova informações de modo da impressora.  Quando o documento inteiro tiver sido impresso, a estrutura chama a função de membro de [EndDoc](../Topic/CDC::EndDoc.md) .  
  
##  <a name="_core_overriding_view_class_functions"></a> Substituindo funções de classe da exibição  
 A classe de [CView](../Topic/CView%20Class.md) define várias funções de membro que são chamadas pela estrutura durante a impressão.  Substituindo essas funções em sua classe da exibição, você fornece as conexões entre a lógica imprimindo a estrutura e a lógica de impressão da sua classe da exibição.  A tabela a seguir lista essas funções de membro.  
  
### As funções substituível de CView para imprimir  
  
|Nome|Motivo para substituir|  
|----------|----------------------------|  
|[OnPreparePrinting](../Topic/CView::OnPreparePrinting.md)|Para inserir valores na caixa de diálogo de impressão, especialmente o tamanho do documento|  
|[OnBeginPrinting](../Topic/CView::OnBeginPrinting.md)|Para atribuir fontes ou outros recursos de GDI|  
|[OnPrepareDC](../Topic/CView::OnPrepareDC.md)|Para ajustar atributos de contexto de dispositivo para uma determinada página, ou fazer a paginação do com hora|  
|[OnPrint](../Topic/CView::OnPrint.md)|Para imprimir uma determinada página|  
|[OnEndPrinting](../Topic/CView::OnEndPrinting.md)|Para desalocar recursos de GDI|  
  
 Você pode fazer o processamento impressão\- relacionados em outras funções além disso, mas essas funções são aquelas que levam o processo de impressão.  
  
 A figura a seguir ilustra as etapas envolvidas no processo de impressão e mostra onde cada um de `CView` que imprime as funções de membro é chamado.  O restante deste artigo explica a maioria dessas etapas com mais detalhes.  As partes adicionais do processo de impressão são descritas no artigo [Alocando recursos de GDI](../mfc/allocating-gdi-resources.md).  
  
 ![Procedimento de Loop de impressão](../Image/vc37C71.gif "vc37C71")  
O loop de impressão  
  
##  <a name="_core_pagination"></a> Paginação  
 A estrutura armazena muitas das informações sobre um trabalho de impressão em uma estrutura de [CPrintInfo](../mfc/reference/cprintinfo-structure.md) .  Vários valores em `CPrintInfo` pertencem à paginação; esses valores são acessíveis conforme mostrado na seguinte tabela.  
  
### Informações de número de página armazenada em CPrintInfo  
  
|Variável de membro ou<br /><br /> nomes de função|Número de página referenciado|  
|-----------------------------------------------|-----------------------------------|  
|`GetMinPage`\/`SetMinPage`|Primeira página do documento|  
|`GetMaxPage`\/`SetMaxPage`|A última página do documento|  
|`GetFromPage`|Primeira página a ser impressa|  
|`GetToPage`|A última página a ser impressa|  
|`m_nCurPage`|Página no momento que está sendo impressa|  
  
 O início em 1, ou seja, a primeira página os números de página numerado é 1, e não 0.  Para obter mais informações sobre esses e de outros membros de [CPrintInfo](../mfc/reference/cprintinfo-structure.md), consulte *a referência de MFC*.  
  
 No início do processo de impressão, a estrutura chama a função de membro de [OnPreparePrinting](../Topic/CView::OnPreparePrinting.md) de exibição, passando um ponteiro para uma estrutura de `CPrintInfo` .  O assistente do aplicativo fornece uma implementação de `OnPreparePrinting` que chama [DoPreparePrinting](../Topic/CView::DoPreparePrinting.md), outra função de membro de `CView`.  `DoPreparePrinting` é a função que exibe a caixa de diálogo imprimir e cria um contexto do dispositivo de impressora.  
  
 Neste momento o aplicativo não souber quantas páginas estão no documento.  Usa os valores padrão 1 e 0xFFFF para os números e sobrenomes da página do documento.  Se você souber quantas páginas o documento tem, substitua `OnPreparePrinting` e chamar [SetMaxPage](../Topic/CPrintInfo::SetMaxPage.md) para a estrutura de `CPrintInfo` antes de enviar à `DoPreparePrinting`.  Isso permite especificar o comprimento do documento.  
  
 `DoPreparePrinting` exibe a caixa de diálogo de impressão.  Quando retorna, a estrutura de `CPrintInfo` contém os valores especificados pelo usuário.  Se os desejos do usuário para imprimir apenas um intervalo selecionado de páginas, da ou deless podem especificar os números de página de início e término na caixa de diálogo de impressão.  A estrutura recupera esses valores usando as funções de `GetFromPage` e de `GetToPage` de [CPrintInfo](../mfc/reference/cprintinfo-structure.md).  Se o usuário não especificar um intervalo de página, a estrutura chama `GetMinPage` e `GetMaxPage` e usa os valores retornados para imprimir o documento inteiro.  
  
 Para cada página de um documento a ser impresso, a estrutura chama duas funções de membro em sua classe, em [OnPrepareDC](../Topic/CView::OnPrepareDC.md) e em [OnPrint](../Topic/CView::OnPrint.md)na exibição, e passa parâmetros de cada função dois: um ponteiro para um objeto de [CDC](../Topic/CDC%20Class.md) e um ponteiro para uma estrutura de `CPrintInfo` .  Cada vez que a estrutura chama `OnPrepareDC` e `OnPrint`, passar um valor diferente no membro de `m_nCurPage` da estrutura de `CPrintInfo` .  Dessa forma a estrutura informa a exibição que a página deve ser impressa.  
  
 A função de membro de [OnPrepareDC](../Topic/CView::OnPrepareDC.md) também é usada para a visualização ótica.  Fazer ajustes no contexto do dispositivo antes de chamar ocorra.  `OnPrepareDC` serve uma função semelhante na impressão, mas há algumas diferenças: primeiro, o objeto de `CDC` representa um contexto do dispositivo de impressora em vez de um contexto do dispositivo da tela e, em seguida, um objeto de `CPrintInfo` é passado como um segundo parâmetro. \(Esse parâmetro é **nulo**`OnPrepareDC` quando é chamado para a visualização ótica.\) Substituir `OnPrepareDC` para fazer ajustes no contexto do dispositivo baseado em que a página está sendo impressa.  Por exemplo, você pode mover a origem do visor e a região de recuo para assegurar que a parte apropriado do documento seja impresso.  
  
 A função de membro de [OnPrint](../Topic/CView::OnPrint.md) executa a impressão real da página.  O artigo [Como usar como padrão a impressão é feita](../Topic/How%20Default%20Printing%20Is%20Done.md) mostra como a estrutura [OnDraw](../Topic/CView::OnDraw.md) chama com um contexto do dispositivo de impressora para executar a impressão.  Mais precisamente, as chamadas `OnPrint` da estrutura com uma estrutura de `CPrintInfo` e um contexto do dispositivo, e passa de `OnPrint` o contexto do dispositivo a `OnDraw`.  Substituir `OnPrint` para a execução de renderização que deve ser feita somente durante a impressão e não para a visualização ótica.  Por exemplo, para imprimir cabeçalhos ou rodapés \(consulte o artigo [Cabeçalhos e rodapés](../mfc/headers-and-footers.md) para obter mais informações\).  Em `OnDraw` chamada de substituição de `OnPrint` para fazer a comum de renderização ótica à visualização e a impressão.  
  
 O fato de que `OnDraw` faz a renderização para a visualização e ótica a impressão significa que o aplicativo é WYSIWYG: “O que você vê é o que você obtém.” Porém, suponha que você não estiver escrevendo um aplicativo de WYSIWYG.  Por exemplo, considere um editor de texto que usa uma fonte em negrito para que os códigos de controle de impressão mas exibe indica o texto em negrito na tela.  Nessa situação, você usa `OnDraw` estritamente para a visualização ótica.  Quando você substitui `OnPrint`, substitua a chamada da `OnDraw` com uma chamada a uma função separada de desenho.  A função desenha o documento a forma como ele aparece no papel, usando os atributos que não são exibidos na tela.  
  
##  <a name="_core_printer_pages_vs.._document_pages"></a> Páginas da impressora em páginas do documento  
 Quando você se referir números de página, algumas vezes é necessário para distinguir entre o conceito da impressora de uma página e o conceito de um documento de uma página.  O ponto de vista da impressora, uma página é uma folha de papel.  No entanto, uma folha do papel não é necessariamente igual uma página do documento.  Por exemplo, se você estiver imprimindo um boletim informativo, onde as folhas devem ser dobrado, uma folha do papel pode conter as duas primeiro e o último páginas do documento, lado a lado.  Da mesma forma, se você estiver imprimindo uma planilha, o documento não consiste em páginas de todo.  Em vez disso, uma folha do papel pode conter as linhas 1 a 20, colunas 6 a 10.  
  
 Todos os números de página na estrutura de [CPrintInfo](../mfc/reference/cprintinfo-structure.md) se referem a páginas da impressora.  A estrutura chama `OnPrepareDC` e `OnPrint` uma vez para cada folha do papel que passará por meio da impressora.  Quando você substitui a função de [OnPreparePrinting](../Topic/CView::OnPreparePrinting.md) para especificar o tamanho do documento, você deve usar páginas da impressora.  Se houver uma correspondência \(ou seja, é igual de uma página da impressora uma página de documento\), esse é fácil.  Se, por outro lado, as páginas do documento e as páginas da impressora não corresponde diretamente, você deve converter entre elas.  Por exemplo, considere a impressão de uma planilha.  Ao substituir `OnPreparePrinting`, você deve calcular quantas folhas do papel serão necessárias para imprimir a planilha inteira e depois usar esse valor ao chamar a função de membro de `SetMaxPage` de `CPrintInfo`.  De maneira semelhante, ao substituir `OnPrepareDC`, você deve converter `m_nCurPage` no intervalo de linhas e de colunas que aparecerão nessa planilha específica e ajustarão na origem do visor adequadamente.  
  
##  <a name="_core_print.2d.time_pagination"></a> Paginação do com hora  
 Em algumas situações, sua classe exibição não pode saber com antecedência quanto tempo o documento é até que seja impresso de fato.  Por exemplo, suponhamos que seu aplicativo não é WYSIWYG, assim que um tamanho do documento na tela não corresponde ao seu tamanho a impressa.  
  
 Isso faz com que um problema quando você substitui [OnPreparePrinting](../Topic/CView::OnPreparePrinting.md) para a sua classe exibição: você não pode passar um valor à função de `SetMaxPage` da estrutura de [CPrintInfo](../mfc/reference/cprintinfo-structure.md) , pois você não souber o comprimento de um documento.  Se o usuário não especificar um número de página para parar em usar a caixa de diálogo de impressão, a estrutura não souber quando parar o loop de cópia.  A única maneira de determinar quando parar o loop de impressão é imprimir do documento e considerá\-la quando termina.  A classe da exibição deve verificar ao final do documento quando é impressa, e depois informar a estrutura quando a extremidade é atingida.  
  
 A estrutura confiar na função de [OnPrepareDC](../Topic/CView::OnPrepareDC.md) da sua classe de exibição para dizê\-la quando parar.  Depois de cada chamada para `OnPrepareDC`, a estrutura verifica um membro da estrutura de `CPrintInfo` chamada `m_bContinuePrinting`.  O valor padrão é **TRUE.** Como permanecerá assim, a estrutura continua o loop de cópia.  Se for definida como **Falso**, a estrutura para.  Para executar a paginação do com hora, a substituição `OnPrepareDC` para verificar se a extremidade do documento foi atingida, e o conjunto `m_bContinuePrinting` a **Falso** quando tiver.  
  
 A implementação padrão de `OnPrepareDC` define `m_bContinuePrinting` a **Falso** se a página atual for maior que 1.  Isso significa que se o tamanho do documento não foi especificado, a estrutura assume o documento é uma página por muito tempo.  Uma resultado dessa é que seja cauteloso se você chamar a versão da classe base de `OnPrepareDC`.  Não suponha que `m_bContinuePrinting` será **Verdadeiro** depois de chamar a versão da classe base.  
  
### Que você deseja saber mais?  
  
-   [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)  
  
-   [Alocando recursos de GDI](../mfc/allocating-gdi-resources.md)  
  
## Consulte também  
 [Imprimindo](../mfc/printing.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [CDC Class](../Topic/CDC%20Class.md)