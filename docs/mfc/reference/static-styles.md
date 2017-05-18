---
title: "Estilos estáticos | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SS_SUNKEN
- SS_CENTER
- SS_ENHMETAFILE
- SS_RIGHT
- SS_BLACKRECT
- SS_LEFTNOWORDWRAP
- SS_GRAYFRAME
- SS_USERITEM
- SS_GRAYRECT
- SS_WHITEFRAME
- SS_ETCHEDFRAME
- SS_ETCHEDVERT
- SS_WHITERECT
- SS_PATHELLIPSIS
- SS_WORDELLIPSIS
- SS_NOPREFIX
- SS_BITMAP
- SS_SIMPLE
- SS_CENTERIMAGE
- SS_BLACKFRAME
- SS_OWNERDRAW
- SS_REALSIZEIMAGE
- SS_RIGHTJUST
- SS_ICON
- SS_NOTIFY
- SS_ETCHEDHORZ
- SS_LEFT
- SS_ENDELLIPSIS
dev_langs:
- C++
helpviewer_keywords:
- SS_ICON constant
- SS_WHITEFRAME constant
- SS_BLACKFRAME constant
- SS_ETCHEDHORZ constant
- SS_OWNERDRAW constant
- SS_BITMAP constant
- SS_NOPREFIX constant
- SS_NOTIFY constant
- SS_CENTER constant
- SS_REALSIZEIMAGE constant
- SS_ETCHEDFRAME constant
- SS_CENTERIMAGE constant
- SS_SUNKEN constant
- SS_ENDELLIPSIS constant
- SS_WORDELLIPSIS constant
- SS_WHITERECT constant
- SS_ETCHEDVERT constant
- SS_GRAYFRAME constant
- SS_LEFTNOWORDWRAP constant
- SS_LEFT constant
- SS_SIMPLE constant
- static styles
- SS_ENHMETAFILE constant
- SS_GRAYRECT constant
- SS_USERITEM constant
- SS_PATHELLIPSIS constant
- SS_BLACKRECT constant
- SS_RIGHT constant
- SS_RIGHTJUST constant
ms.assetid: a1114548-fc6d-491d-8c46-21d11b8574f5
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: ad34c688fdfd3c2b4c81a0a03fbce53a905162ad
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="static-styles"></a>Estilos estáticos
-   **SS_BITMAP** Especifica um bitmap a ser exibido no controle estático. O texto especificado é o nome de um bitmap (não um nome de arquivo) definido em outro lugar no arquivo de recurso. O estilo ignora os parâmetros nWidth e nHeight; o controle dimensiona automaticamente para acomodar o bitmap.  
  
-   **SS_BLACKFRAME** Especifica uma caixa com um quadro com a mesma cor de quadros de janela. O padrão é preto.  
  
-   **SS_BLACKRECT** Especifica um retângulo preenchido com a cor usada para desenhar quadros de janela. O padrão é preto.  
  
-   **SS_CENTER** designa um retângulo simples e exibe o texto determinado centralizado no retângulo. O texto é formatado antes que ele seja exibido. Palavras que seriam estende além do final de uma linha são automaticamente encapsuladas para o início da próxima linha centralizado.  
  
-   **SS_CENTERIMAGE** Especifica que, se o bitmap ou ícone for menor do que a área do cliente do controle estático, o restante da área do cliente é preenchido com a cor do pixel no canto superior esquerdo do bitmap ou ícone. Se o controle estático contém uma única linha de texto, o texto está centralizado verticalmente na área do cliente do controle.  
  
-   **SS_ENDELLIPSIS** ou **SS_PATHELLIPSIS** substitui parte da cadeia de caracteres especificada com reticências, se necessário, para que o resultado se encaixa no retângulo especificado.  
  
     Você pode especificar **SS_END_ELLIPSIS** para substituir caracteres ao final da cadeia de caracteres, ou **SS_PATHELLIPSIS** para substituir caracteres no meio da cadeia. Se a cadeia de caracteres contém a barra invertida (\\) caracteres, **SS_PATHELLIPSIS** preserva máximo do texto após a última barra invertida possível.  
  
-   **SS_ENHMETAFILE** Especifica um metarquivo avançado deve ser exibido no controle estático. O texto especificado é o nome de um metarquivo. Um controle estático Metarquivo Avançado tem um tamanho fixo; o metarquivo é dimensionado para ajustar a área do cliente do controle estático.  
  
-   **SS_ETCHEDFRAME** desenha o quadro do controle estático usando o **EDGE_ETCHED** estilo de borda.  
  
-   **SS_ETCHEDHORZ** desenha as bordas superior e inferior do controle estático usando o **EDGE_ETCHED** estilo de borda.  
  
-   **SS_ETCHEDVERT** desenha as bordas esquerdas e direita do controle estático usando o estilo de borda EDGE_ETCHED.  
  
-   **SS_GRAYFRAME** Especifica uma caixa com um quadro com a mesma cor do plano de fundo de tela (desktop). O padrão é cinza.  
  
-   **SS_GRAYRECT** Especifica um retângulo preenchido com a cor usada para preencher o plano de fundo de tela. O padrão é cinza.  
  
-   **SS_ICON** designa um ícone exibido na caixa de diálogo. O texto especificado é o nome de um ícone (não um nome de arquivo) definido em outro lugar no arquivo de recurso. O `nWidth` e `nHeight` os parâmetros são ignorados; o ícone dimensiona automaticamente em si.  
  
-   **SS_LEFT** designa um retângulo simples e exibe o texto determinado flush esquerdo do retângulo. O texto é formatado antes que ele seja exibido. Palavras que seriam estende além do final de uma linha são automaticamente encapsuladas para o início da próxima linha esquerda de liberação.  
  
-   **SS_LEFTNOWORDWRAP** designa um retângulo simples e exibe o texto determinado flush esquerdo do retângulo. Guias são expandidas, mas palavras não são encapsuladas. Texto que ultrapassa o final de uma linha é cortado.  
  
-   **SS_NOPREFIX** , a menos que esse estilo é especificado, Windows irá interpretar qualquer caractere e comercial (&) no texto do controle caracteres de prefixo de acelerador. Nesse caso, o e comercial é removido e o próximo caractere na cadeia de caracteres está sublinhado. Se for um controle estático conter o texto em que esse recurso não se for desejado, **SS_NOPREFIX** podem ser adicionados. Esse estilo de controle estático pode ser incluído com qualquer um dos controles estáticos definidos. Você pode combinar **SS_NOPREFIX** com outros estilos usando o operador OR bit a bit. Isso geralmente é usado quando nomes de arquivos ou outras cadeias de caracteres que podem conter um e comercial precisam ser exibido em um controle estático em uma caixa de diálogo.  
  
-   **SS_NOTIFY** envia a janela pai **STN_CLICKED**, **STN_DBLCLK**, **STN_DISABLE**, e **STN_ENABLE** mensagens de notificação quando o usuário clica ou clica duas vezes no controle.  
  
-   **SS_OWNERDRAW** Especifica que o proprietário do controle estático é responsável por desenhar o controle. A janela do proprietário recebe um `WM_DRAWITEM` mensagem sempre que o controle deve ser desenhado.  
  
-   **SS_REALSIZEIMAGE** impede que um controle estático ícone ou bitmap (ou seja, os controles estáticos que têm o **SS_ICON** ou **SS_BITMAP** estilo) seja redimensionada conforme ele é carregado ou desenhado. Se o ícone ou o bitmap for maior que a área de destino, a imagem é recortada.  
  
-   **SS_RIGHT** designa um retângulo simples e exibe o texto determinado flush-direita do retângulo. O texto é formatado antes que ele seja exibido. Palavras que seriam estende além do final de uma linha são automaticamente encapsuladas para o início da próxima linha flush direito.  
  
-   **SS_RIGHTJUST** Especifica que o canto inferior direito de um controle estático com o **SS_BITMAP** ou **SS_ICON** estilo é permanecer fixo quando o controle é redimensionado. Somente os lados superior e esquerdos são ajustados para acomodar um novo bitmap ou ícone.  
  
-   **SS_SIMPLE** designa um retângulo simples e exibe uma única linha de texto flush esquerdo do retângulo. A linha de texto não pode ser reduzida ou alterada de alguma maneira. (Caixa de diálogo ou janela pai do controle não precisa processar o `WM_CTLCOLOR` mensagem.)  
  
-   **SS_SUNKEN** desenha uma borda submersa em torno de um controle estático.  
  
-   **SS_USERITEM** Especifica um item definido pelo usuário.  
  
-   **SS_WHITEFRAME** Especifica uma caixa com um quadro com a mesma cor do plano de fundo da janela. O padrão é branco.  
  
-   **SS_WHITERECT** Especifica um retângulo preenchido com a cor usada para preencher o plano de fundo da janela. O padrão é branco.  
  
-   **SS_WORDELLIPSIS** trunca o texto que não couber e adiciona elipses.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CStatic::Create](../../mfc/reference/cstatic-class.md#create)   
 [DrawEdge](http://msdn.microsoft.com/library/windows/desktop/dd162477)   
 [Estilos de controle estático](http://msdn.microsoft.com/library/windows/desktop/bb760773)


