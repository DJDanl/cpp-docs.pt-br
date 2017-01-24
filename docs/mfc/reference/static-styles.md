---
title: "Estilos est&#225;ticos | Microsoft Docs"
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
  - "SS_SUNKEN"
  - "SS_CENTER"
  - "SS_ENHMETAFILE"
  - "SS_RIGHT"
  - "SS_BLACKRECT"
  - "SS_LEFTNOWORDWRAP"
  - "SS_GRAYFRAME"
  - "SS_USERITEM"
  - "SS_GRAYRECT"
  - "SS_WHITEFRAME"
  - "SS_ETCHEDFRAME"
  - "SS_ETCHEDVERT"
  - "SS_WHITERECT"
  - "SS_PATHELLIPSIS"
  - "SS_WORDELLIPSIS"
  - "SS_NOPREFIX"
  - "SS_BITMAP"
  - "SS_SIMPLE"
  - "SS_CENTERIMAGE"
  - "SS_BLACKFRAME"
  - "SS_OWNERDRAW"
  - "SS_REALSIZEIMAGE"
  - "SS_RIGHTJUST"
  - "SS_ICON"
  - "SS_NOTIFY"
  - "SS_ETCHEDHORZ"
  - "SS_LEFT"
  - "SS_ENDELLIPSIS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante SS_BITMAP"
  - "Constante SS_BLACKFRAME"
  - "Constante SS_BLACKRECT"
  - "Constante SS_CENTER"
  - "Constante SS_CENTERIMAGE"
  - "Constante SS_ENDELLIPSIS"
  - "Constante SS_ENHMETAFILE"
  - "Constante SS_ETCHEDFRAME"
  - "Constante SS_ETCHEDHORZ"
  - "Constante SS_ETCHEDVERT"
  - "Constante SS_GRAYFRAME"
  - "Constante SS_GRAYRECT"
  - "Constante SS_ICON"
  - "Constante SS_LEFT"
  - "Constante SS_LEFTNOWORDWRAP"
  - "Constante SS_NOPREFIX"
  - "Constante SS_NOTIFY"
  - "Constante SS_OWNERDRAW"
  - "Constante SS_PATHELLIPSIS"
  - "Constante SS_REALSIZEIMAGE"
  - "Constante SS_RIGHT"
  - "Constante SS_RIGHTJUST"
  - "Constante SS_SIMPLE"
  - "Constante SS_SUNKEN"
  - "Constante SS_USERITEM"
  - "Constante SS_WHITEFRAME"
  - "Constante SS_WHITERECT"
  - "Constante SS_WORDELLIPSIS"
  - "estilos estáticos"
ms.assetid: a1114548-fc6d-491d-8c46-21d11b8574f5
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos est&#225;ticos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

-   **SS\_BITMAP** especifica um bitmap deve ser exibido no controle estático.  O texto fornecido é o nome de um bitmap \(não um nome de arquivo\) definido em outro lugar no arquivo de recurso.  O estilo ignora os parâmetros de nWidth e de nHeight; o controle disponibiliza dimensionar automaticamente para acomodar o bitmap.  
  
-   **SS\_BLACKFRAME** especifica uma caixa com um quadro desenhado com a mesma cor de peças da janela.  A opção é preta.  
  
-   **SS\_BLACKRECT** especifica um retângulo preenchido com a cor usada para desenhar peças da janela.  A opção é preta.  
  
-   **SS\_CENTER** designa um retângulo simples e exibe o texto determinado centralizado no retângulo.  O texto é formatado antes de ser exibido.  As palavras que estenderiam após o término de uma linha são envolvidas automaticamente para o início da linha centralizada seguir.  
  
-   **SS\_CENTERIMAGE** especifica que, se o bitmap ou o ícone é menor que a área do cliente do controle estático, o restante da área de cliente for preenchido com a cor de pixel no canto superior esquerdo de bitmap ou o ícone.  Se o controle estático contém uma única linha de texto, o texto será centralizado verticalmente na área do cliente do controle.  
  
-   **SS\_ENDELLIPSIS** ou **SS\_PATHELLIPSIS** substituem a parte da cadeia de caracteres fornecida com as reticências se necessário, de forma que a medida de resultado no retângulo especificado.  
  
     Você pode especificar **SS\_END\_ELLIPSIS** para substituir caracteres no final da cadeia de caracteres, ou **SS\_PATHELLIPSIS** para substituir caracteres no meio da cadeia de caracteres.  Se a cadeia de caracteres contém caracteres de barra invertida \(\\\), preserva de **SS\_PATHELLIPSIS** tanto quanto de texto após a barra invertida a última possível.  
  
-   **SS\_ENHMETAFILE** especifica um metarquivo aprimorado deve ser exibido no controle estático.  O texto fornecido é o nome de um metarquivo.  Um controle estático de metarquivo aprimorado tem um tamanho fixo; o metarquivo é redimensionado para se ajustar à área de cliente de controle estático.  
  
-   **SS\_ETCHEDFRAME** desenha o quadro estático de controle usando o estilo da borda de **EDGE\_ETCHED** .  
  
-   **SS\_ETCHEDHORZ** desenha a parte superior e as bordas inferiores de controle estático usando o estilo da borda de **EDGE\_ETCHED** .  
  
-   **SS\_ETCHEDVERT** desenha as bordas esquerda e direita do controle estático usando o estilo da borda de EDGE\_ETCHED.  
  
-   **SS\_GRAYFRAME** especifica uma caixa com um quadro desenhado com a mesma cor do plano de fundo da tela \(área de trabalho\).  A opção estiver cinza.  
  
-   **SS\_GRAYRECT** especifica um retângulo preenchido com a cor usada para preencher o plano de fundo da tela.  A opção estiver cinza.  
  
-   **SS\_ICON** designa um ícone exibido na caixa de diálogo.  O texto fornecido é o nome de um ícone \(não um nome de arquivo\) definido em outro lugar no arquivo de recurso.  Os parâmetros de `nWidth` e de `nHeight` são ignorados; o ícone disponibiliza dimensionar automaticamente.  
  
-   **SS\_LEFT** designa um retângulo simples e exibe o texto fornecido resplendor\- esquerdo no retângulo.  O texto é formatado antes de ser exibido.  As palavras que estenderiam após o término de uma linha são envolvidas automaticamente para o início da linha resplendor\- esquerda seguir.  
  
-   **SS\_LEFTNOWORDWRAP** designa um retângulo simples e exibe o texto fornecido resplendor\- esquerdo no retângulo.  As guias são expandidas, mas as palavras não são envolvidas.  Texto que estende após o término de uma linha é anexado.  
  
-   **SS\_NOPREFIX** a menos que esse estilo for especificado, o interpretará todos os caracteres de E comercial \(&\) no texto do controle para ser caracteres de prefixo de acelerador.  Nesse caso, E comercial é removido e o próximo caractere da cadeia de caracteres é sublinhado.  Se um controle conter texto estático é onde esse recurso não é desejado, **SS\_NOPREFIX** pode ser adicionado.  Esse estilo de estática\- controle pode ser incluído em qualquer dos controles estáticos definidos.  Você pode combinar **SS\_NOPREFIX** com outros estilos usando o operador OR bit a bit.  Isso é o mais frequentemente usado quando os nomes de arquivo ou outras cadeias de caracteres que podem conter uma necessidade de E comercial de ser exibido em um controle estático em uma caixa de diálogo.  
  
-   **SS\_NOTIFY** envia a janela pai **STN\_CLICKED**, notificações de **STN\_DBLCLK**, de **STN\_DISABLE**, e de **STN\_ENABLE** quando o usuário clica em ou clique duas vezes no controle.  
  
-   **SS\_OWNERDRAW** especifica que o proprietário do controle estático é responsável para desenhar o controle.  A janela do proprietário recebe uma mensagem de `WM_DRAWITEM` sempre que as necessidades de controle de ser desenhado.  
  
-   **SS\_REALSIZEIMAGE** impede que um controle estático de ícones ou de bitmap \(isto é, os controles estáticos que têm o estilo de **SS\_ICON** ou de **SS\_BITMAP** \) é redimensionado como é carregada ou desenhado.  Se o ícone ou o bitmap é maior do que a área de destino, a imagem será anexado.  
  
-   **SS\_RIGHT** designa um retângulo simples e exibe o texto fornecido resplendor\- direito no retângulo.  O texto é formatado antes de ser exibido.  As palavras que estenderiam após o término de uma linha são envolvidas automaticamente para o início da linha resplendor\- direita seguir.  
  
-   **SS\_RIGHTJUST** especifica que o canto inferior direito de um controle estático com o estilo de **SS\_BITMAP** ou de **SS\_ICON** permanece fixo quando o controle é redimensionado.  Somente os lados esquerdo e superiores são ajustados para acomodar um novo bitmap ou ícone.  
  
-   **SS\_SIMPLE** designa um retângulo simples e exibe uma única linha de texto resplendor\- esquerda do retângulo.  A linha de texto não pode ser abreviada ou modificadas em nenhuma forma. \(A janela pai ou a caixa de diálogo controle não devem processar a mensagem de `WM_CTLCOLOR` .\)  
  
-   **SS\_SUNKEN** desenha uma borda meia afundado ao redor de um controle estático.  
  
-   **SS\_USERITEM** especifica um item definido pelo usuário.  
  
-   **SS\_WHITEFRAME** especifica uma caixa com um quadro desenhado com a mesma cor do plano de fundo da janela.  A opção é branca.  
  
-   **SS\_WHITERECT** especifica um retângulo preenchido com a cor usada para preencher o plano de fundo da janela.  A opção é branca.  
  
-   **SS\_WORDELLIPSIS** trunca o texto que não couber e adiciona reticências.  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CStatic::Create](../Topic/CStatic::Create.md)   
 [DrawEdge](http://msdn.microsoft.com/library/windows/desktop/dd162477)   
 [Static Control Styles](http://msdn.microsoft.com/library/windows/desktop/bb760773)