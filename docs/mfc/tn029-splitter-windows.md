---
title: 'TN029: Divisor Windows | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.windows.splitter
dev_langs:
- C++
helpviewer_keywords:
- TN029
- splitter windows [MFC], about splitter windows
ms.assetid: 2c57ce99-2a3c-4eff-9cea-baccb13af075
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 24556d7a331a74936631eef4fec2e293126cdbab
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379509"
---
# <a name="tn029-splitter-windows"></a>TN029: janelas separadoras

Essa observação descreve o MFC [classe CSplitterWnd](../mfc/reference/csplitterwnd-class.md), que fornece a janela divide e gerencia o redimensionamento de outras janelas do painel.

## <a name="splitter-styles"></a>Estilos de divisor

Um `CSplitterWnd` dá suporte a dois estilos diferentes de divisão do windows.

Em "divisores estáticos", a janela divisora cria painéis quando ele é criado. Nunca altere a ordem e o número de painéis. As barras do separador são usadas para redimensionar os painéis diferentes. Você pode usar esse estilo para exibir uma classe de exibição diferente em cada painel. O editor de gráficos do Visual C++ e o Gerenciador de arquivos do Windows são exemplos de programas que usam esse estilo do separador. Esse estilo de janela separadora não usa caixas de distribuição.

Em "divisores dinâmicos", painéis adicionais são criados e destruídos como os usuário divisões e divisões un novos modos de exibição. Esse divisor começa com uma única exibição e fornece caixas de distribuição para o usuário inicie a divisão. Janela divisora cria dinamicamente um novo objeto de exibição quando o modo de exibição é dividido em uma única direção. Esse novo objeto de exibição representa o novo painel. Se o modo de exibição é dividido em duas direções usando a interface de teclado, a janela divisora cria três novos objetos de exibição para os três novos painéis. Quando a divisão estiver ativa, o Windows exibe a caixa de divisor como uma barra divisória entre os painéis. Windows destrói os objetos de exibição adicionais quando o usuário remove uma divisão, mas o modo de exibição original continuam até a janela de divisor em si é destruído. Microsoft Word e Microsoft Excel são exemplos de aplicativos que usam o estilo do separador dinâmico.

Quando você cria um desses tipos de janela separadora, você deve especificar o número máximo de linhas e colunas que gerenciará o divisor. Um separador estático será criar painéis para preencher todas as linhas e colunas. Um separador dinâmico criará somente o primeiro painel quando o `CSplitterWnd` é criado.

O número máximo de painéis, que você pode especificar para divisores estáticos é 16 linhas por 16 colunas. As configurações recomendadas são:

- colunas da 1 linha x 2: geralmente com diferentes painéis

- coluna 2 linhas x 1: geralmente com diferentes painéis

- colunas de 2 linhas x 2: normalmente, com painéis semelhantes

O número máximo de painéis que você pode especificar para divisores dinâmicos é 2 linhas por 2 colunas. As configurações recomendadas são:

- colunas da 1 linha x 2: para dados de colunas

- coluna 2 linhas x 1: para dados textuais ou

- colunas de 2 linhas x 2: tabela ou grade orientados a dados

## <a name="splitter-examples"></a>Exemplos de divisor

Muitos dos programas de exemplo do MFC usam janelas separadoras direta ou indiretamente. O exemplo de MFC geral [VIEWEX](../visual-cpp-samples.md) ilustra vários usos de divisores estáticos, inclusive sobre como colocar um divisor em um divisor.

Você também pode usar o ClassWizard para criar um novo vários documento interface MDI filho quadro classe de janela que contém uma janela separadora. Para obter mais informações sobre janelas separadoras, consulte [vários tipos de documentos, exibições e quadro Windows](../mfc/multiple-document-types-views-and-frame-windows.md).

## <a name="terminology-used-by-implementation"></a>Terminologia usada pela implementação

Aqui está uma lista de termos que são específicos para janelas separadoras:

`CSplitterWnd`: Uma janela que fornece controles de painel de divisão e barras de rolagem que são compartilhadas entre todos os painéis em uma linha ou coluna. Especificar linhas e colunas com números com base em zero (o primeiro painel é linha = 0 e coluna = 0).

Painel: Uma janela específica do aplicativo que um `CSplitterWnd` gerencia. Um painel geralmente é um objeto que deriva a [classe CView](../mfc/reference/cview-class.md), mas pode ser qualquer [CWnd](../mfc/reference/cwnd-class.md) objeto que tem a ID da janela filho apropriados.

Para usar um `CWnd`-derivado do objeto, passe o RUNTIME_CLASS do objeto para o `CreateView` funcionar como você faria se estivesse usando um `CView`-classe derivada. Sua classe deve usar DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE porque a estrutura usa criação dinâmica em tempo de execução. Embora haja muitos códigos na `CSplitterWnd` que é específico para o `CView` classe, [CObject::IsKindOf](../mfc/reference/cobject-class.md#iskindof) é sempre usado antes que essas ações são executadas.

Barra de divisão: Um controle que é colocado entre linhas e colunas de painéis. Ele pode ser usado para ajustar os tamanhos de linhas ou colunas de painéis.

Caixa de divisor: Um controle dinâmico `CSplitterWnd` que você pode usar para criar novas linhas ou colunas de painéis. Ele está localizado na parte superior das barras de rolagem vertical ou à esquerda das barras de rolagem horizontal.

Divisor interseção: A interseção de uma barra divisora vertical e uma barra divisora horizontal. Você pode arrastá-lo para ajustar o tamanho de uma linha e coluna de painéis ao mesmo tempo.

## <a name="shared-scroll-bars"></a>As barras de rolagem compartilhado

O `CSplitterWnd` classe também dá suporte a barras de rolagem compartilhado. Esses controles de barra de rolagem são filhos do `CSplitterWnd` e são compartilhadas com os diferentes painéis no divisor de.

Por exemplo, em uma janela de coluna 1 linha x 2, você pode especificar WS_VSCROLL ao criar o `CSplitterWnd`. Windows cria um controle de barra de rolagem especial que é compartilhado entre os dois painéis.

```
[      ][      ][^]
[pane00][pane01][|]
[      ][      ][v]
```

Quando o usuário move a barra de rolagem, WM_VSCROLL mensagens serão enviadas para ambos os modos de exibição. Quando o modo de exibição define a posição da barra de rolagem, a barra de rolagem compartilhado será definida.

Observe que as barras de rolagem compartilhado são mais úteis com objetos de modo semelhante. Se você mesclar os modos de exibição de tipos diferentes em um divisor, em seguida, talvez você precise escrever códigos especiais para coordenar suas posições de rolagem. Qualquer `CView`-derivado da classe que usa o `CWnd` barra de rolagem APIs delegará a barra de rolagem compartilhado se ele existir. O `CScrollView` implementação é um exemplo de um `CView` compartilhado de classe que dá suporte a barras de rolagem. Classes que não são derivadas de `CView`, as classes que dependem de barras de rolagem não-controle ou classes que usam as implementações padrão do Windows (por exemplo, `CEditView`) não funcionará com o recurso de barra de rolagem compartilhado do `CSplitterWnd`.

## <a name="minimum-sizes"></a>Tamanhos mínimo

Há uma altura mínima da linha para cada linha, e há uma largura mínima da coluna para cada coluna. Isso garante o mínimo que um painel não é muito pequeno para ser mostrado em detalhes completos.

Para uma janela separadora estático, a mínimo da linha inicial altura e largura de coluna é 0. Para uma janela divisora dinâmica, a mínimo da linha inicial altura e largura de coluna são definidos pela *sizeMin* parâmetro do `CSplitterWnd::Create` função.

Você pode alterar esses tamanhos mínimo usando o [CSplitterWnd::SetRowInfo](../mfc/reference/csplitterwnd-class.md#setrowinfo) e [CSplitterWnd::SetColumnInfo](../mfc/reference/csplitterwnd-class.md#setcolumninfo) funções.

## <a name="actual-vs-ideal-sizes"></a>Real versus. Tamanhos ideais

O layout dos painéis da janela divisora depende do tamanho do quadro que os contém. Quando um usuário redimensiona o quadro que contém, o `CSplitterWnd` reposiciona e redimensiona os painéis para que eles se ajustam melhor maneira possível.

O usuário pode definir manualmente a linha de tamanhos de largura de altura e a coluna ou o programa pode definir o tamanho ideal usando o `CSplitterWnd` classe. O tamanho real pode ser menor ou maior que o ideal. Windows irá ajustar o tamanho real se não houver espaço suficiente para exibir o tamanho ideal ou se não há muito espaço vazio à direita ou inferior da janela do divisor.

## <a name="custom-controls"></a>Controles personalizados

Você pode substituir muitas funções para fornecer comportamento personalizado e uma interface personalizada. Você pode substituir esse primeiro conjunto para fornecer imagens alternativas para os vários componentes gráficas de uma janela separadora.

- `virtual void OnDrawSpltter(CDC* pDC, ESplitType nType, const CRect& rect);`

- `virtual void OnInvertTracker(const CRect& rect);`

Você chama essa função para criar um controle de barra de rolagem compartilhado. Você pode substituí-la para criar controles extras ao lado da barra de rolagem.

- `virtual BOOL CreateScrollBarCtrl(DWORD dwStyle, UINT nID);`

Essas funções implementam a lógica da janela divisora dinâmica. Você pode substituir esses para fornecer a lógica de divisor mais avançada.

- `virtual void DeleteView(int row, int col);`

- `virtual BOOL SplitRow(int cyBefore);`

- `virtual BOOL SplitColumn(int cxBefore);`

- `virtual void DeleteRow(int rowDelete);`

- `virtual void DeleteColumn(int colDelete);`

## <a name="cview-functionality"></a>Funcionalidade de CView

O `CView` classe usa os seguintes comandos de alto níveis para delegar para o `CSplitterWnd` implementação. Como esses comandos são virtuais, o padrão `CView` implementação não exigirá que toda a `CSplitterWnd` implementação a ser vinculada. Para aplicativos que usam `CView` , mas não `CSplitterWnd`, o `CSplitterWnd` implementação não será vinculada com o aplicativo.

- `virtual BOOL CanActivateNext(BOOL bPrev = FALSE);`

   Verifica se ID_NEXT_PANE ou ID_PREV_PANE é atualmente possível.

- `virtual void ActivateNext(BOOL bPrev = FALSE);`

   Executa o comando "Próximo painel" ou "Painel anterior".

- `virtual BOOL DoKeyboardSplit();`

   Executa o comando, geralmente "divisão da janela" de divisão do teclado.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

