---
title: "Classe de CToolBar | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CToolBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bitmaps [C++], controles de botão"
  - "botões [C++], Barras de ferramentas MFC"
  - "barras de controle [C++], Classe de CToolBar"
  - "Classe de CToolBar"
  - "barras de ferramentas [C++], Classe de CToolBar"
  - "Controles comuns do Windows [C++], Classe de CToolBar"
  - "Controles comuns da barra de ferramentas do windows [C++]"
ms.assetid: e868da26-5e07-4607-9651-e2f863ad9059
caps.latest.revision: 26
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CToolBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Barras de controle que tem uma linha de botões de bitmap e separadores opcionais.  
  
## Sintaxe  
  
```  
class CToolBar : public CControlBar  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CToolBar::CToolBar](../Topic/CToolBar::CToolBar.md)|Constrói um objeto de `CToolBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CToolBar::CommandToIndex](../Topic/CToolBar::CommandToIndex.md)|Retorna o índice de um botão com a identificação determinada de comando|  
|[CToolBar::Create](../Topic/CToolBar::Create.md)|Cria a barra de ferramentas do windows e anexá\-la ao objeto de `CToolBar` .|  
|[CToolBar::CreateEx](../Topic/CToolBar::CreateEx.md)|Cria um objeto de `CToolBar` com os estilos adicionais para o objeto inserido de `CToolBarCtrl` .|  
|[CToolBar::GetButtonInfo](../Topic/CToolBar::GetButtonInfo.md)|Obtém a identificação, o estilo, e o número de imagem de um botão.|  
|[CToolBar::GetButtonStyle](../Topic/CToolBar::GetButtonStyle.md)|Recupera o estilo de um botão.|  
|[CToolBar::GetButtonText](../Topic/CToolBar::GetButtonText.md)|Recupera o texto que aparecerá em um botão.|  
|[CToolBar::GetItemID](../Topic/CToolBar::GetItemID.md)|Retorna a identificação de comando de um botão ou um separador no índice especificado.|  
|[CToolBar::GetItemRect](../Topic/CToolBar::GetItemRect.md)|Recupera o retângulo de exibição para o item no índice especificado.|  
|[CToolBar::GetToolBarCtrl](../Topic/CToolBar::GetToolBarCtrl.md)|Permite acesso direto ao controle comum subjacente.|  
|[CToolBar::LoadBitmap](../Topic/CToolBar::LoadBitmap.md)|Carrega o bitmap que contém imagens de bitmap\- botão.|  
|[CToolBar::LoadToolBar](../Topic/CToolBar::LoadToolBar.md)|Carrega um recurso da barra de ferramentas criado com o editor de recursos.|  
|[CToolBar::SetBitmap](../Topic/CToolBar::SetBitmap.md)|Define uma imagem bitmap.|  
|[CToolBar::SetButtonInfo](../Topic/CToolBar::SetButtonInfo.md)|Define a identificação, o estilo, e o número de imagem de um botão.|  
|[CToolBar::SetButtons](../Topic/CToolBar::SetButtons.md)|Define um estilo e um índice do botão imagens de bitmap em.|  
|[CToolBar::SetButtonStyle](../Topic/CToolBar::SetButtonStyle.md)|Defina o estilo de um botão.|  
|[CToolBar::SetButtonText](../Topic/CToolBar::SetButtonText.md)|Define o texto que aparecerá em um botão.|  
|[CToolBar::SetHeight](../Topic/CToolBar::SetHeight.md)|Defina a altura da barra de ferramentas.|  
|[CToolBar::SetSizes](../Topic/CToolBar::SetSizes.md)|Defina os tamanhos dos botões e seus bitmaps.|  
  
## Comentários  
 Os botões podem atuar como teclas, botões da caixa de seleção, ou botões de opção.  Os objetos de`CToolBar` geralmente são membros de objetos inseridos de quadro\- janela derivados da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md).  
  
 [CToolBar::GetToolBarCtrl](../Topic/CToolBar::GetToolBarCtrl.md), uma função de membro novo a MFC 4,0, permite que você aproveite de suporte comuns de controle do windows para personalização e funcionalidade adicional da barra de ferramentas.  As funções de membro de`CToolBar` dão\-no mais da funcionalidade dos controles comuns do windows; no entanto, quando você chama `GetToolBarCtrl`, você pode dar às barras de ferramentas ainda mais das características Windows 95 \/98 da barra de ferramentas.  Quando você chama `GetToolBarCtrl`, retornará uma referência a um objeto de `CToolBarCtrl` .  Consulte [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando controles comuns.  Para obter informações mais gerais sobre controles comuns, consulte [Controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Visual C\+\+ fornece dois métodos para criar uma barra de ferramentas.  Para criar um recurso da barra de ferramentas usando o editor de recursos, siga estas etapas:  
  
1.  Crie um recurso da barra de ferramentas.  
  
2.  Construir o objeto de `CToolBar` .  
  
3.  Chame a função de [Criar](../Topic/CToolBar::Create.md) \(ou [CreateEx](../Topic/CToolBar::CreateEx.md)\) para criar a barra de ferramentas do windows para e anexá\-la ao objeto de `CToolBar` .  
  
4.  Chamada [LoadToolBar](../Topic/CToolBar::LoadToolBar.md) para carregar o recurso da barra de ferramentas.  
  
 Caso contrário, siga estas etapas:  
  
1.  Construir o objeto de `CToolBar` .  
  
2.  Chame a função de [Criar](../Topic/CToolBar::Create.md) \(ou [CreateEx](../Topic/CToolBar::CreateEx.md)\) para criar a barra de ferramentas do windows para e anexá\-la ao objeto de `CToolBar` .  
  
3.  A chamada [LoadBitmap](../Topic/CToolBar::LoadBitmap.md) para carregar o bitmap que contém o botão da barra de ferramentas imagens.  
  
4.  Chame [SetButtons](../Topic/CToolBar::SetButtons.md) para definir o estilo do botão e para associar cada botão com uma imagem bitmap em.  
  
 Todas as imagens de botão na barra de ferramentas são executadas de um bitmap, que deve conter uma imagem para cada botão.  Todas as imagens devem ser do mesmo tamanho; o padrão é 16 pixels de largura e 15 pixels.  Imagens devem ser lado a lado no bitmap.  
  
 A função de `SetButtons` leva um ponteiro para um array de IDs de controle e um número inteiro que especifica o número de elementos na matriz.  A função define a identificação de cada botão ao valor do elemento correspondente da matriz e a atribui cada botão um índice de imagem, que especifica a posição de imagem de bitmap no botão.  Se um elemento de matriz tem o valor **ID\_SEPARATOR**, nenhum índice da imagem é atribuído.  
  
 A ordem das imagens bitmap em é normalmente a ordem em que eles são desenhados na tela, mas você pode usar a função de [SetButtonInfo](../Topic/CToolBar::SetButtonInfo.md) para alterar a relação entre ordem de imagem e a ordem de desenho.  
  
 Todos os botões na barra de ferramentas são o mesmo tamanho.  O padrão é 24 x 22 pixels, de acordo com as *diretrizes de interface do windows para o design de software*.  Qualquer espaço extra entre a imagem e as dimensões do botão é usado para formar uma borda ao redor da imagem.  
  
 Cada botão tem uma imagem.  Vários estados e estilo de botão \(pressionadas, cima, para baixo, de desativado, desativado para baixo, e indeterminado\) são gerados da uma imagem.  Embora bitmaps possam ser qualquer cor, você pode obter melhores resultados com imagens em preto e em tons de cinza.  
  
> [!WARNING]
>  `CToolBar` suporta bitmaps com um máximo de 16 cores.  Quando você carregar uma imagem em um editor da barra de ferramentas, o Visual Studio automaticamente converte a imagem a um bitmap de cores 16 se necessário, e exibe uma mensagem de aviso se a imagem foi convertido.  Se você usar uma imagem com as cores mais de 16 \(usando um editor externo para editar a imagem\), o aplicativo pode se comportar inesperado.  
  
 Os botões da barra de ferramentas imitam teclas por padrão.  Em o entanto, os botões da barra de ferramentas também pode imitar botões ou botões de opção na caixa de seleção.  Botões da caixa de seleção têm três estados: verificado, desmarcado, e indefinido.  Botões de opção só tem dois estados: verificadas e desmarcada.  
  
 Para definir um estilo individual do botão ou separator sem aponte para uma matriz, chame [GetButtonStyle](../Topic/CToolBar::GetButtonStyle.md) para recuperar o estilo, e então chame [SetButtonStyle](../Topic/CToolBar::SetButtonStyle.md) em vez de `SetButtons`.  `SetButtonStyle` é mais útil quando você deseja alterar em tempo de execução o estilo de um botão.  
  
 Para atribuir texto para aparecer em um botão, chame [GetButtonText](../Topic/CToolBar::GetButtonText.md) para recuperar o texto para aparecer no botão, e então chame [SetButtonText](../Topic/CToolBar::SetButtonText.md) para definir o texto.  
  
 Para criar um botão da caixa de seleção, atribua o estilo **TBBS\_CHECKBOX** ou use a função de membro de `SetCheck` de um objeto de `CCmdUI` em um manipulador de `ON_UPDATE_COMMAND_UI` .  A chamada `SetCheck` torna uma tecla em um botão da caixa de seleção.  `SetCheck` passar um argumento de 0 para não\-verificada, 1 para verificado, ou 2 para indefinido.  
  
 Para criar um botão de opção, chame a função de membro de [SetRadio](../Topic/CCmdUI::SetRadio.md) de um objeto de [CCmdUI](../Topic/CCmdUI%20Class.md) de um manipulador de `ON_UPDATE_COMMAND_UI` .  `SetRadio` passar um argumento de 0 para não\-verificada ou diferente de zero para verificado.  Para fornecer um comportamento mutuamente exclusivos de um grupo de rádio, você deve ter manipuladores de `ON_UPDATE_COMMAND_UI` para todos os botões no grupo.  
  
 Para obter mais informações sobre como usar `CToolBar`, consulte o artigo [Implementação da barra de ferramentas MFC](../../mfc/mfc-toolbar-implementation.md) e [Observe técnica 31: barras de controle](../../mfc/tn031-control-bars.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CToolBar`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [O MFC exemplos CTRLBARS](../../top/visual-cpp-samples.md)   
 [Exemplo DLGCBR32 MFC](../../top/visual-cpp-samples.md)   
 [Exemplo DOCKTOOL MFC](../../top/visual-cpp-samples.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [CToolBar::Create](../Topic/CToolBar::Create.md)   
 [CToolBar::LoadBitmap](../Topic/CToolBar::LoadBitmap.md)   
 [CToolBar::SetButtons](../Topic/CToolBar::SetButtons.md)   
 [CCmdUI::SetCheck](../Topic/CCmdUI::SetCheck.md)   
 [CCmdUI::SetRadio](../Topic/CCmdUI::SetRadio.md)