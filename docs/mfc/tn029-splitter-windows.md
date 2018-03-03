---
title: 'TN029: Janelas separadoras | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.windows.splitter
dev_langs:
- C++
helpviewer_keywords:
- TN029
- splitter windows [MFC], about splitter windows
ms.assetid: 2c57ce99-2a3c-4eff-9cea-baccb13af075
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 95b7db2678c03b0508a1507567f8bedcf243cd4a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn029-splitter-windows"></a>TN029: janelas separadoras
Esta anotação descreve o MFC [CSplitterWnd classe](../mfc/reference/csplitterwnd-class.md), que fornece a janela se divide e gerencia o redimensionamento de outras janelas do painel.  
  
## <a name="splitter-styles"></a>Estilos de separador  
 A `CSplitterWnd` oferece suporte a dois estilos diferentes de divisão do windows.  
  
 Em "divisores estáticos," janela separadora cria painéis quando ele é criado. Nunca altere a ordem e o número de painéis. As barras separadoras são usadas para redimensionar os painéis diferentes. Você pode usar esse estilo para exibir uma classe de exibição diferente em cada painel. O editor de elementos gráficos do Visual C++ e o Gerenciador de arquivos do Windows são exemplos de programas que usam esse estilo do separador. Esse estilo de janela separadora não usa caixas de distribuição.  
  
 Em "divisores dinâmicos," painéis adicionais são criados e destruídos como os usuário divisões e Cancelar divisões novos modos de exibição. Essa divisão começa com uma única exibição e fornece caixas de distribuição para o usuário inicie a divisão. Janela separadora dinâmica cria um novo objeto de exibição quando o modo de exibição é dividido em uma única direção. Esse novo objeto de exibição representa o novo painel. Se o modo de exibição é dividido em duas direções usando a interface do teclado, janela separadora cria três novos objetos de exibição para os três novos painéis. Enquanto a divisão está ativa, o Windows exibe a caixa de separador como uma barra de divisão entre os painéis. Windows destrói objetos de exibição adicionais quando o usuário remove uma divisão, mas o modo de exibição original continuam até que a própria janela separadora é destruído. Microsoft Word e Microsoft Excel são exemplos de aplicativos que usam o estilo do separador dinâmico.  
  
 Quando você cria um tipo de janela separadora, você deve especificar o número máximo de linhas e colunas que gerenciará o divisor. Uma separador estático cria painéis para preencher todas as linhas e colunas. Um separador dinâmico criará somente o primeiro painel quando o `CSplitterWnd` é criado.  
  
 O número máximo de painéis, que você pode especificar para divisores estáticos é 16 linhas por 16 colunas. As configurações recomendadas são:  
  
-   colunas de 1 linha x 2: normalmente com painéis diferentes  
  
-   coluna de 2 linhas x 1: normalmente com painéis diferentes  
  
-   colunas de 2 linhas x 2: normalmente com painéis semelhantes  
  
 O número máximo de painéis que você pode especificar para divisores dinâmicos é 2 linhas por 2 colunas. As configurações recomendadas são:  
  
-   colunas de 1 linha x 2: para dados de colunas  
  
-   coluna de 2 linhas x 1: para dados textuais ou  
  
-   colunas de 2 linhas x 2: para a tabela ou grade orientada a dados  
  
## <a name="splitter-examples"></a>Exemplos de separador  
 Muitos dos programas de exemplo do MFC usam janelas separadoras direta ou indiretamente. O exemplo de MFC geral [VIEWEX](../visual-cpp-samples.md) ilustra vários usos de divisores estáticos, incluindo como colocar um separador em um divisor.  
  
 Você também pode usar ClassWizard para criar um novo vários documentos interface MDI filho quadro classe de janela que contém uma janela separadora. Para obter mais informações sobre janelas separadoras, consulte [vários tipos de documento, exibições e janelas com moldura](../mfc/multiple-document-types-views-and-frame-windows.md).  
  
## <a name="terminology-used-by-implementation"></a>Terminologia usada pela implementação  
 Aqui está uma lista de termos que são específicos para janelas separadoras:  
  
 `CSplitterWnd`:  
 Uma janela que fornece controles de painel de divisão e barras de rolagem que são compartilhadas entre todos os painéis em uma linha ou coluna. Especifique linhas e colunas com números com base em zero (o primeiro painel é linha = 0 e a coluna = 0).  
  
 Painel:  
 Uma janela específica do aplicativo que um `CSplitterWnd` gerencia. Um painel geralmente é um objeto que é derivado do [classe CView](../mfc/reference/cview-class.md), mas pode ser qualquer [CWnd](../mfc/reference/cwnd-class.md) objeto que tem a ID da janela filho apropriados.  
  
 Para usar um `CWnd`-derivado de objeto, passe o `RUNTIME_CLASS` do objeto para o `CreateView` funcionar como você faria se estivesse usando um `CView`-classe derivada. Use a classe `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE` porque a estrutura usa criação dinâmica no tempo de execução. Embora não haja muitos códigos em `CSplitterWnd` que é específico para o `CView` classe [CObject::IsKindOf](../mfc/reference/cobject-class.md#iskindof) é sempre usado antes que essas ações são executadas.  
  
 Barra de divisão:  
 Um controle que é colocado entre linhas e colunas dos painéis. Ele pode ser usado para ajustar o tamanho das linhas ou colunas de painéis.  
  
 Caixa de divisão:  
 Um controle em um dinâmico `CSplitterWnd` que você pode usar para criar novas linhas ou colunas de painéis. Ele está localizado na parte superior das barras de rolagem vertical ou à esquerda das barras de rolagem horizontal.  
  
 Interseção de separador:  
 A interseção de uma barra de divisão vertical e uma barra de divisão horizontal. Você pode arrastá-la para ajustar o tamanho de uma linha e coluna de painéis ao mesmo tempo.  
  
## <a name="shared-scroll-bars"></a>Barras de rolagem compartilhado  
 O `CSplitterWnd` classe também oferece suporte a barras de rolagem compartilhado. Esses controles de barra de rolagem são filhos do `CSplitterWnd` e são compartilhados com os diferentes painéis no separador.  
  
 Por exemplo, em uma janela de coluna 1 linha x 2, você pode especificar WS_VSCROLL ao criar o `CSplitterWnd`. O Windows cria um controle de barra de rolagem especiais que é compartilhado entre os dois painéis.  
  
```  
[      ][      ][^]  
[pane00][pane01][|]  
[      ][      ][v]  
```  
  
 Quando o usuário move a barra de rolagem, `WM_VSCROLL` as mensagens serão enviadas para ambos os modos de exibição. Quando o modo de exibição define a posição da barra de rolagem, a barra de rolagem compartilhado será definida.  
  
 Observe que as barras de rolagem compartilhado são mais úteis com objetos de modo semelhante. Se você combinar os modos de exibição de tipos diferentes em um separador, precisará escrever códigos especiais para coordenar as posições de rolagem. Qualquer `CView`-derivada da classe que usa o `CWnd` barra de rolagem APIs delegará a barra de rolagem compartilhado se ele existir. O `CScrollView` implementação é um exemplo de um `CView` compartilhado de classe que dá suporte a barras de rolagem. Classes que não derivam de `CView`, classes que dependem de barras de rolagem do controle não ou as classes que usam as implementações padrão do Windows (por exemplo, `CEditView`) não funcionará com o recurso de barra de rolagem compartilhado do `CSplitterWnd`.  
  
## <a name="minimum-sizes"></a>Tamanhos mínimo  
 Há uma altura mínima da linha para cada linha, e há uma largura mínima da coluna para cada coluna. Este mínimo garante que um painel não é muito pequeno para ser mostrada em detalhes completos.  
  
 Para uma janela de separador estático, a mínimo da linha inicial altura e largura de coluna é 0. Para uma janela separadora dinâmica, a mínimo da linha inicial altura e largura de coluna são definidos pelo `sizeMin` parâmetro o `CSplitterWnd::Create` função.  
  
 Você pode alterar esses tamanhos mínimo usando o [CSplitterWnd::SetRowInfo](../mfc/reference/csplitterwnd-class.md#setrowinfo) e [CSplitterWnd::SetColumnInfo](../mfc/reference/csplitterwnd-class.md#setcolumninfo) funções.  
  
## <a name="actual-vs-ideal-sizes"></a>Real versus. Tamanhos ideais  
 O layout dos painéis na janela separadora depende do tamanho do quadro que contém. Quando um usuário redimensionar o quadro que contém, o `CSplitterWnd` reposiciona e redimensiona os painéis para que caibam, bem como possíveis.  
  
 O usuário pode definir manualmente a linha tamanhos de largura de altura e a coluna ou o programa pode definir o tamanho ideal usando o `CSplitterWnd` classe. O tamanho real pode ser menor ou maior do que o ideal. Windows ajustará o tamanho real, se não houver espaço suficiente para exibir o tamanho ideal ou se há muito espaço vazio à direita ou inferior da janela separadora.  
  
## <a name="custom-controls"></a>Controles personalizados  
 Você pode substituir muitas funções para fornecer uma interface personalizada e comportamento personalizado. Você pode substituir esse primeiro conjunto para fornecer imagens alternativas para os vários componentes de gráficos de uma janela separadora.  
  
- `virtual void OnDrawSpltter(CDC* pDC, ESplitType nType, const CRect& rect);`  
  
- `virtual void OnInvertTracker(const CRect& rect);`  
  
 Você chamar esta função para criar um controle de barra de rolagem compartilhado. Você pode substituí-la para criar controles adicionais ao lado da barra de rolagem.  
  
- `virtual BOOL CreateScrollBarCtrl(DWORD dwStyle, UINT nID);`  
  
 Essas funções implementam a lógica da janela separadora dinâmica. Você pode substituir esses para fornecer lógica de separador mais avançada.  
  
- `virtual void DeleteView(int row, int col);`  
  
- `virtual BOOL SplitRow(int cyBefore);`  
  
- `virtual BOOL SplitColumn(int cxBefore);`  
  
- `virtual void DeleteRow(int rowDelete);`  
  
- `virtual void DeleteColumn(int colDelete);`  
  
## <a name="cview-functionality"></a>Funcionalidade de CView  
 O `CView` classe usa os seguintes comandos de alto níveis para delegar para o `CSplitterWnd` implementação. Como esses comandos são virtuais, o padrão `CView` implementação não exigirá que toda a `CSplitterWnd` implementação a ser vinculado no. Para aplicativos que usam `CView` mas não `CSplitterWnd`, o `CSplitterWnd` implementação não será vinculada com o aplicativo.  
  
 `virtual BOOL CanActivateNext(BOOL bPrev = FALSE);`  
 Verifica se ID_NEXT_PANE ou ID_PREV_PANE é possível no momento.  
  
 `virtual void ActivateNext(BOOL bPrev = FALSE);`  
 Executa o comando "Próximo painel" ou "anterior".  
  
 `virtual BOOL DoKeyboardSplit();`  
 Executa o comando, geralmente "divisão da janela" de divisão do teclado.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

