---
title: "TN029: janelas separadoras | Microsoft Docs"
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
  - "vc.windows.splitter"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "janelas separadoras, sobre janelas separadoras"
  - "TN029"
ms.assetid: 2c57ce99-2a3c-4eff-9cea-baccb13af075
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN029: janelas separadoras
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve o MFC [Classe de CSplitterWnd](../mfc/reference/csplitterwnd-class.md), que fornece divisões da janela e gerencia redimensionar de outras janelas do painel.  
  
## Estilo do separador  
 `CSplitterWnd` oferece suporte a dois estilos diferentes do windows de linhas.  
  
 “Nos separadores estáticos,” a janela do separador cria os painéis quando ela é criada.  A ordem e o número de painéis nunca são alterados.  As barras separadoras são usadas para redimensionar os diferentes painéis.  Você pode usar esse estilo para exibir uma classe diferente da exibição em cada painel.  O editor de gráficos do Visual C\+\+ e o gerenciador de arquivos do windows são exemplos de programas que usam esse estilo do separador.  Esse estilo da janela do separador não usa caixas do separador.  
  
 “Nos separadores dinâmicos”, os painéis adicionais são criados e destruído como as divisões do usuário e exibições de divisões não novas.  Esse separador começa com uma única exibição e fornece caixas de divisão para o usuário à divisão iniciada.  A janela do separador cria dinamicamente um novo objeto de exibição quando a exibição é dividida em uma direção.  Esse novo objeto de exibição representa o novo painel.  Se a exibição é dividida em duas direções usando a interface de teclado, a janela do separador cria três novos objetos de exibição para os três novos painéis.  Quando a divisão está ativa, as janelas exibem a caixa do separador como uma barra de divisão entre os painéis.  As janelas destroem exibir objetos adicionais quando o usuário remove uma divisão, mas a exibição original permanece até que a própria janela do separador foi destruída.  O Microsoft Excel e o Microsoft Word são exemplos de aplicativos que usam o estilo do separador dinâmico.  
  
 Quando você cria qualquer tipo da janela do divisor, você deve especificar o número máximo de linhas e de colunas que o separador gerenciará.  Um separador estático criará os painéis para preencher todas as linhas e colunas.  Um separador dinâmico criará apenas o primeiro o painel quando `CSplitterWnd` é criado.  
  
 O número máximo de painéis que você pode especificar para separadores estáticos é 16 linhas por 16 colunas.  As configurações recomendadas são:  
  
-   linha 1 x 2 colunas: normalmente com diferentes painéis  
  
-   2 x 1 linhas coluna: normalmente com diferentes painéis  
  
-   2 linhas x 2 colunas: normalmente com painéis semelhantes  
  
 O número máximo de painéis que você pode especificar para separadores dinâmicos é 2 linhas por 2 colunas.  As configurações recomendadas são:  
  
-   linha 1 x 2 colunas: para dados de coluna  
  
-   2 x 1 linhas coluna: para dados textuais ou outros  
  
-   2 linhas x 2 colunas: para a grade ou tabela orientou dados  
  
## Exemplos do separador  
 Muitos dos programas de exemplo MFC usam o windows do separador direta ou indiretamente.  O exemplo [VIEWEX](../top/visual-cpp-samples.md) gerais de MFC ilustra vários usos de separadores estáticos, inclusive como colocar um separador em um separador.  
  
 Você também pode usar ClassWizard para criar uma classe filho da janela do quadro de \(MDI\) de novo ambiente MDI que contém uma janela do separador.  Para obter mais informações sobre as janelas do divisor, consulte [Vários tipos de documento, exibições, e janelas do quadro](../mfc/multiple-document-types-views-and-frame-windows.md).  
  
## Terminologia usada pela implementação  
 Eis uma lista de termos que são específicos do windows do separador:  
  
 `CSplitterWnd`:  
 Uma janela que fornece controles e as barras de rolagem de linhas que são compartilhados entre todos os painéis em uma linha ou coluna.  Você especifica linhas e colunas com números com base em zero \(o primeiro painel é 0 \= linha e coluna \= 0\).  
  
 O painel:  
 Uma janela específica do aplicativo que `CSplitterWnd` gerencia.  Um painel é geralmente um objeto que é derivado de [Classe de CView](../Topic/CView%20Class.md), mas pode ser qualquer objeto de [CWnd](../Topic/CWnd%20Class.md) que tem a ID apropriada na janela filho  
  
 Para usar `CWnd`\- objeto derivada, passe `RUNTIME_CLASS` de objeto para a função de `CreateView` como se você estiver usando `CView`\- a classe derivada.  A sua classe deve usar `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE` porque a estrutura usa a criação dinâmico em tempo de execução.  Embora haja muito código em `CSplitterWnd` que é específico da classe de `CView` , [CObject::IsKindOf](../Topic/CObject::IsKindOf.md) sempre é usado antes que as ações serão executadas.  
  
 Barra divisória:  
 Um controle que é colocado entre linhas e colunas os painéis.  Pode ser usado para ajustar os tamanhos das linhas ou colunas os painéis.  
  
 Caixa do separador:  
 Um controle em `CSplitterWnd` dinâmico que você pode usar para criar novas linhas ou colunas os painéis.  Está localizado na parte superior das barras de rolagem vertical ou à esquerda das barras de rolagem horizontal.  
  
 Interseção do separador:  
 A interseção de uma barra vertical do separador e uma barra horizontal do separador.  Você pode arrastá\-lo simultaneamente para ajustar o tamanho de uma linha e uma coluna de painéis.  
  
## Barras de rolagem compartilhadas  
 A classe de `CSplitterWnd` também suporta barras de rolagem compartilhadas.  Esses controles da barra de rolagem são filhos de `CSplitterWnd` e são compartilhados com os diferentes painéis o separador.  
  
 Por exemplo, em uma janela de linha 1 x 2 colunas, você pode especificar WS\_VSCROLL ao criar `CSplitterWnd`.  O windows cria um controle especial da barra de rolagem que é compartilhado entre os dois painéis.  
  
```  
[      ][      ][^]  
[pane00][pane01][|]  
[      ][      ][v]  
```  
  
 Quando o usuário move a barra de rolagem, as mensagens de `WM_VSCROLL` serão enviadas a ambas as exibições.  Quando qualquer exibição define a posição da barra de rolagem, a barra de rolagem compartilhada será definida.  
  
 Observe que as barras de rolagem compartilhadas são mais úteis com objetos de visualização semelhantes.  Se você mescla exibições de tipos diferentes em um separador, você pode precisar escrever o código especial para coordenar as posições de rolagem.  Qualquer `CView`\- a classe derivada usando as APIs da barra de rolagem de `CWnd` delegará à barra de rolagem compartilhada se existir.  A implementação de `CScrollView` é um exemplo de uma classe de `CView` que suporte barras de rolagem compartilhadas.  As classes que não são derivadas de `CView`, as classes que dependem de barras de rolagem de não controle, ou classes que usam implementações padrão do windows \(por exemplo, `CEditView`\) não funcionarão com o recurso compartilhado da barra de rolagem de `CSplitterWnd`.  
  
## Tamanhos mínimo  
 Para cada linha há uma altura mínima de linha, e cada coluna há uma largura mínima da coluna.  Este mínimo garante que um painel não for muito pequeno para ser exibido em detalhes completo.  
  
 Para uma janela estático do divisor, a altura e a largura da coluna mínimas iniciais de linha é 0.  Para uma janela dinâmico do divisor, a altura e a largura da coluna mínimas iniciais de linha são definidas pelo parâmetro de `sizeMin` da função de `CSplitterWnd::Create` .  
  
 Você pode modificar estes tamanhos mínimo usando as funções de [CSplitterWnd::SetRowInfo](../Topic/CSplitterWnd::SetRowInfo.md) e de [CSplitterWnd::SetColumnInfo](../Topic/CSplitterWnd::SetColumnInfo.md) .  
  
## Real em tamanhos ideais  
 O layout dos painéis na janela do separador depende do tamanho do tableau que os contém.  Quando um usuário redimensiona o quadro contentor, `CSplitterWnd` reposições e redimensionar os painéis de modo que caiba melhor possível.  
  
 O usuário pode definir manualmente os tamanhos de altura e largura de coluna da linha, ou o programa pode definir o tamanho ideal usando a classe de `CSplitterWnd` .  O tamanho real pode ser menor ou maior que o ideal.  As janelas ajustarão o tamanho real se não houver espaço suficiente exibir o tamanho ideal ou se houver muito espaço em branco à direita ou na parte inferior da janela do separador.  
  
## Controles personalizados.  
 Você pode substituir muitas funções para fornecer o comportamento personalizado e uma interface personalizado.  Você pode substituir o este primeiro conjunto para fornecer a aparência de backup para os vários componentes gráficos de uma janela do separador.  
  
-   `virtual void OnDrawSpltter(CDC* pDC, ESplitType nType, const CRect& rect);`  
  
-   `virtual void OnInvertTracker(const CRect& rect);`  
  
 Você chamará essa função para criar um controle compartilhado da barra de rolagem.  Você pode substituí\-los para criar controles adicionais ao lado da barra de rolagem.  
  
-   `virtual BOOL CreateScrollBarCtrl(DWORD dwStyle, UINT nID);`  
  
 Essas funções implementa a lógica da janela dinâmico do separador.  Você pode substituir esses para fornecer uma lógica mais avançada do separador.  
  
-   `virtual void DeleteView(int row, int col);`  
  
-   `virtual BOOL SplitRow(int cyBefore);`  
  
-   `virtual BOOL SplitColumn(int cxBefore);`  
  
-   `virtual void DeleteRow(int rowDelete);`  
  
-   `virtual void DeleteColumn(int colDelete);`  
  
## Funcionalidade de CView  
 A classe de `CView` usa os seguintes comandos de alto nível delegar a `CSplitterWnd` a implementação.  Como esses comandos são virtuais, a implementação padrão de `CView` não exigirá a implementação inteira de `CSplitterWnd` ser vinculada no.  Para aplicativos que usam `CView` mas não `CSplitterWnd`, a implementação de `CSplitterWnd` não será vinculada com o aplicativo.  
  
 `virtual BOOL CanActivateNext(BOOL bPrev = FALSE);`  
 Verifica se ID\_NEXT\_PANE ou ID\_PREV\_PANE sejam atualmente possível.  
  
 `virtual void ActivateNext(BOOL bPrev = FALSE);`  
 Executa o comando “do próximo painel” ou “do painel anterior”.  
  
 `virtual BOOL DoKeyboardSplit();`  
 Executa o comando dividido de teclado, em geral “janela de divisão”.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)