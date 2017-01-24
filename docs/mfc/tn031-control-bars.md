---
title: "TN031: barras de controle | Microsoft Docs"
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
  - "vc.controls.bars"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "barras de controle, estilos"
  - "Classe CStatusBar, Tech uso da observação 31"
  - "Classe CControlBar, Tech uso da observação 31"
  - "Classe CControlBar, derivando de"
  - "barras de controle, classes"
  - "Classe CDialogBar, Tech uso da observação 31"
  - "Classe CToolBar, Tech uso da observação 31"
  - "TN031"
  - "estilos, barras de controle"
ms.assetid: 8cb895c0-40ea-40ef-90ee-1dd29f34cfd1
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN031: barras de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esta nota técnica não foi atualizada desde que ele foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on\-line.  
  
 Esta nota descreve as classes da barra de controle no MFC: geral [CControlBar](#_mfcnotes_ccontrolbar), [CStatusBar](#_mfcnotes_cstatusbar), [CToolBar](#_mfcnotes_ctoolbar), [CDialogBar](#_mfcnotes_cdialogbar), e **CDockBar**.  
  
 `CControlBar`  
  
 A **ControlBar** é um `CWnd`\-derivada da classe que:  
  
-   Será alinhado à parte superior ou inferior de uma janela de quadro.  
  
-   Pode conter itens filho que qualquer um dos controles baseados em HWND \(por exemplo, `CDialogBar`\) ou não\-`HWND` com base em itens \(por exemplo, `CToolBar`, `CStatusBar`\).  
  
 Barras de controle oferecem suporte os estilos adicionais:  
  
-   `CBRS_TOP` \(O padrão\) fixar a barra de controle na parte superior.  
  
-   `CBRS_BOTTOM` Fixe a barra de controle na parte inferior.  
  
-   `CBRS_NOALIGN` Reposiciona a barra de controle quando o pai é redimensionado.  
  
 Classes derivadas de `CControlBar` fornecer implementações mais interessantes:  
  
-   `CStatusBar` Uma barra de status, os itens são painéis da barra de status que contém texto.  
  
-   `CToolBar` Uma barra de ferramentas, os itens são alinhados em uma linha de botões de bitmap.  
  
-   `CDialogBar` Um quadro semelhante a barra de ferramentas que contém o padrão do windows controles \(criados a partir de um recurso de modelo de caixa de diálogo\).  
  
-   **CDockBar** um generalizado área de encaixe para outros `CControlBar` objetos derivados. As funções de membro específico e variáveis disponíveis nessa classe têm probabilidade de mudar em versões futuras.  
  
 Barra de controle todos os objetos\/windows será janelas filho de uma janela de quadro pai. Geralmente, eles são adicionados como um irmão na área do cliente do quadro \(por exemplo, um cliente MDI ou exibição\). A ID de janela filho de uma barra de controle é importante. O layout padrão da barra de controle funciona apenas em barras de controle com IDs no intervalo de **AFX\_IDW\_CONTROLBAR\_FIRST** para **AFX\_IDW\_CONTROLBAR\_LAST**. Observe que, embora haja um intervalo de controle 256 barra IDs, as primeiras 32 dessas barras de controle IDs são especiais como eles são diretamente suportados pela arquitetura de visualização de impressão.  
  
 O `CControlBar` classe fornece uma implementação padrão para:  
  
-   Alinhando a barra de controle para a parte superior, inferior ou ambos os lados do quadro.  
  
-   Alocar matrizes de item de controle.  
  
-   Suporte a implementação de classes derivadas.  
  
 Objetos de barra de controle do C\+\+ geralmente serão incorporados como membros de uma `CFrameWnd` classe derivada e será limpo quando o pai `HWND` e os objetos são destruídos. Se você precisar alocar um objeto da barra de controle na pilha, você pode simplesmente definir a **m\_bAutoDestruct** membro **TRUE** para deixar a barra de controle "**Excluir esta**" quando o `HWND` é destruído.  
  
> [!NOTE]
>  Se você criar seu próprio `CControlBar`\-derivado de classe, em vez de usando um do MFC classes derivadas, como `CStatusBar`, `CToolBar`, ou `CDialogBar`, você precisará definir o `m_dwStyle` membro de dados. Isso pode ser feito na substituição do **criar**:  
  
```  
// CMyControlBar is derived from CControlBar  
BOOL CMyControlBar::Create( CWnd* pParentWnd, DWORD dwStyle, UINT nID )  
{  
   m_dwStyle = dwStyle;  
  
   .  
   .  
   .  
}  
```  
  
 **Algoritmo de Layout da barra de controle**  
  
 O algoritmo de layout da barra de controle é muito simple. A janela do quadro envia uma mensagem **WM\_SIZEPARENT** para todos os filhos do intervalo da barra de controle. Juntamente com essa mensagem, é passado um ponteiro para o retângulo do cliente do pai. Esta mensagem é enviada aos filhos na ordem Z. Os filhos de barra de controle usam essas informações para se posicionar e diminuir o tamanho da área do cliente do pai. O retângulo final que é necessário para a área do cliente normal \(menos barras de controle\) é usado para posicionar a janela principal do cliente \(geralmente um cliente, a exibição ou divisor janela MDI\).  
  
 Consulte `CWnd::RepositionBars` e `CFrameWnd::RecalcLayout` para obter mais detalhes.  
  
 Privada mensagens do Windows MFC, incluindo **WM\_SIZEPARENT**, estão documentados em [técnico 24 Observação](../mfc/tn024-mfc-defined-messages-and-resources.md).  
  
 `CStatusBar`  
  
 Uma barra de status é uma barra de controle que tem uma linha de painéis de saída de texto. Há duas maneiras de usar painéis de saída de texto:  
  
-   Como uma linha de mensagem  
  
     \(por exemplo, o menu padrão ajuda a linha de mensagem\). Eles geralmente são acessados por um indexada baseado em 0  
  
-   Como os indicadores de status  
  
     \(por exemplo, os limite, NUM e SCRL indicadores\). Eles normalmente são acessados pelo ID de cadeia de caracteres\/comando.  
  
 A fonte para a barra de status é o ponto de 10 MS Sans Serif \(determinado pelo guia de Design de aplicativo da Interface do Windows ou a fonte mapeadores melhor correspondência de uma fonte proporcional Suíça de 10 pontos\). Em determinadas versões do Windows, como a edição em japonês, as fontes selecionadas são diferentes.  
  
 As cores usadas na barra de status também são consistentes com a recomendação do guia de Design de aplicativo da Interface do Windows. Essas cores não são codificadas e são alteradas dinamicamente em resposta a personalização do usuário no painel de controle.  
  
|Item|Valor de cor do Windows|Padrão RGB|  
|----------|-----------------------------|----------------|  
|Plano de fundo de barra de status|**COLOR\_BTNFACE**|RGB \(192, 192, 192\)|  
|Texto da barra de status|**COLOR\_BTNTEXT**|RGB \(000, 000 000.\)|  
|Barra superior\/esquerdo bordas de status|**COLOR\_BTNHIGHLIGHT**|RGB \(255, 255, 255\)|  
|Barra bordas de bot\/direito de status|**COLOR\_BTNSHADOW**|RGB \(128, 128, 128\)|  
  
 **Suporte a CCmdUI CStatusBar**  
  
 A maneira como os indicadores normalmente são atualizados é por meio do `ON_UPDATE_COMMAND_UI` mecanismo. No tempo ocioso, a barra de status chamará o `ON_UPDATE_COMMAND_UI` manipulador com a ID de cadeia de caracteres do painel de indicador.  
  
 O `ON_UPDATE_COMMAND_UI` manipulador pode chamar:  
  
-   **Habilitar**: para habilitar ou desabilitar o painel. Um painel desabilitado parece exatamente um painel habilitado, mas o texto é invisível \(ou seja, desativa o indicador de texto\).  
  
-   **SetText**: para alterar o texto. Tenha cuidado se você usar esse porque o painel não será redimensionado automaticamente.  
  
 Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) no *referência da biblioteca de classe* para obter detalhes sobre `CStatusBar` criação e personalização de APIs. A maioria dos personalização das barras de status deve ser feita antes que a barra de status é inicialmente tornada visível.  
  
 A barra de status oferece suporte a apenas um painel alongado, geralmente o primeiro painel. O tamanho do painel é realmente um tamanho mínimo. Se a barra de status é maior do que o tamanho mínimo de todos os painéis, qualquer largura extra terá ao painel alongado. O aplicativo padrão com uma barra de status tem indicadores alinhado à direita para CAP, NUM e SCRL como o primeiro painel é alongado.  
  
 `CToolBar`  
  
 Uma barra de ferramentas é uma barra de controle com uma linha de botões de bitmap que podem conter separadores. Há suporte para dois estilos de botões: pushbuttons e botões da caixa de seleção. Funcionalidade do grupo de opção pode ser montada com botões da caixa de seleção e `ON_UPDATE_COMMAND_UI`.  
  
 Todos os botões de bitmap na barra de ferramentas são obtidos de um bitmap. Esse bitmap deve conter uma imagem ou glifo para cada botão. Normalmente, a ordem de glifos\/imagens no bitmap é a mesma ordem em que elas serão desenhadas na tela. \(Isso pode ser alterado usando a APIs de personalização.\)  
  
 Cada botão deve ser do mesmo tamanho. O padrão é os padrão 24 x 22 pixels. Cada imagem\/glifo deve ser do mesmo tamanho e deve estar lado a lado no bitmap. O tamanho de imagem\/glifos padrão é 15 x 16 pixels. Portanto, para uma barra de ferramentas com 10 botões \(usando tamanhos padrão\), é necessário um bitmap é 160 pixels de largura e 15 pixels de altura.  
  
 Cada botão tem somente uma imagem\/glifo. O botão diferente estados e estilos \(por exemplo, pressionado, para cima, para baixo, desabilitado, desabilitado para baixo, indeterminado\) algorítmica gerados a partir de que uma imagem\/glifo. Qualquer bitmap colorido ou DIB pode ser usado na teoria. O algoritmo para gerar o botão diferente estados funciona melhor se a imagem original for tons de cinza. Examinar os botões da barra de ferramentas padrão e o botão de barra de ferramentas clip\-art fornecido no exemplo de MFC geral [Clip\-art](../top/visual-cpp-samples.md) para obter exemplos.  
  
 As cores usadas na barra de ferramentas também são consistentes com a recomendação do guia de Design de aplicativo da Interface do Windows. Essas cores não são codificadas e são alteradas dinamicamente em resposta a personalização do usuário no painel de controle.  
  
|Item|Valor de cor do Windows|Padrão RGB|  
|----------|-----------------------------|----------------|  
|Plano de fundo da barra de ferramentas|**COLOR\_BTNFACE**|RGB\(192,192,192\)|  
|Botões de barra de ferramentas bordas superior\/esquerdo|**COLOR\_BTNHIGHLIGHT**|RGB\(255,255,255\)|  
|Botões de barra de ferramentas bordas de bot ou para a direita|**COLOR\_BTNSHADOW**|RGB\(128,128,128\)|  
  
 Além disso, os botões de bitmap são recoloridos como se fossem os controles de botão padrão do Windows. Este recolorindo ocorre quando o bitmap é carregado do recurso e, em resposta a uma alteração de cores do sistema em resposta a personalização do usuário no painel de controle. As seguintes cores em um bitmap da barra de ferramentas serão Recolorir automaticamente para que eles devem ser usados com cuidado. Se não desejar que uma parte do seu bitmap recolorido, use uma cor que se aproxima um dos valores RGB mapeados. O mapeamento é feito com base em valores RGB exatos.  
  
|Valor RGB|Valor de cor mapeado dinamicamente|  
|---------------|----------------------------------------|  
|RGB \(000, 000 000.\)|COLOR\_BTNTEXT|  
|RGB \(128, 128, 128\)|COLOR\_BTNSHADOW|  
|RGB \(192, 192, 192\)|COLOR\_BTNFACE|  
|RGB \(255, 255, 255\)|COLOR\_BTNHIGHLIGHT|  
  
 Consulte a classe [CToolBar](../mfc/reference/ctoolbar-class.md) o *referência da biblioteca de classe* para obter detalhes sobre o `CToolBar` criação e personalização de APIs. A maioria dos personalização das barras de ferramentas deve ser feita antes da barra de ferramentas é inicialmente tornada visível.  
  
 A personalização APIs podem ser usadas para ajustar o botão IDs, estilos, largura de espaçador e qual imagem\/glifo é usado para o botão. Por padrão, não é necessário usar essas APIs.  
  
## Suporte a CCmdUI CToolBar  
 É a maneira como os botões da barra de ferramentas são sempre atualizadas por meio de `ON_UPDATE_COMMAND_UI` mecanismo. No tempo ocioso, a barra de ferramentas chamará o `ON_UPDATE_COMMAND_UI` manipulador com a ID de comando do botão.`ON_UPDATE_COMMAND_UI` não é chamado para separadores, mas ela é chamada para pushbuttons e os botões da caixa de seleção.  
  
 O `ON_UPDATE_COMMAND_UI` manipulador pode chamar:  
  
-   **Habilitar**: para habilitar ou desabilitar o botão. Isso funciona igualmente para pushbuttons e os botões da caixa de seleção.  
  
-   `SetCheck`: Para definir o estado de um botão de seleção. Chamar isso de um botão da barra de ferramentas, ela se transformará em um botão de caixa de seleção.`SetCheck` leva um parâmetro que pode ser 0 \(não verificado\), 1 \(marcado\) ou 2 \(indeterminado\)  
  
-   `SetRadio`: Uma abreviação para `SetCheck`.  
  
 Caixa de seleção botões é "AUTO" caixa de seleção; Isto é, quando o usuário pressiona\-las imediatamente irá alterar estado. Verificado é o estado pressionado ou para baixo. Não há nenhuma maneira de interface do usuário interno para alterar um botão no estado "indeterminado"; Isso deve ser feito por meio de código.  
  
 A personalização APIs permitirão alterar o estado de um botão da barra de ferramentas, preferencialmente, você deve alterar esses estados no `ON_UPDATE_COMMAND_UI` manipulador para o comando que representa o botão de barra de ferramentas. Lembre\-se de que o processamento ocioso alterará o estado dos botões da barra de ferramentas com o `ON_UPDATE_COMMAND_UI` manipulador, para que as alterações para esses estados feitas por meio de SetButtonStyle podem ser perdidas após o próximo ocioso.  
  
 Botões da barra de ferramentas enviará **WM\_COMMAND** mensagens como botões normais ou itens de menu e normalmente são manipuladas por um `ON_COMMAND` manipulador na mesma classe que fornece a `ON_UPDATE_COMMAND_UI` manipulador.  
  
 Há quatro ferramentas botão estilos \(valores TBBS\_\) usados para os estados de exibição:  
  
-   TBBS\_CHECKED: caixa de seleção é marcada atualmente \(baixo\).  
  
-   TBBS\_INDETERMINATE: caixa de seleção estará desativada no momento.  
  
-   TBBS\_DISABLED: Botão está desabilitado atualmente.  
  
-   TBBS\_PRESSED: Botão atualmente é pressionado.  
  
 Os seis estilos de botão oficiais do guia de Design de aplicativos de Interface do Windows são representados pelos valores TBBS:  
  
-   Até \= 0  
  
-   Apertar \= TBBS\_PRESSED \(&#124; qualquer outro estilo\)  
  
-   Desabilitado \= TBBS\_DISABLED  
  
-   Para baixo \= TBBS\_CHECKED  
  
-   Para baixo desabilitado \= TBBS\_CHECKED &#124; TBBS\_DISABLED  
  
-   Indeterminada \= TBBS\_INDETERMINATE  
  
##  <a name="_mfcnotes_cdialogbar"></a> CDialogBar  
 Uma barra da caixa de diálogo é uma barra de controle que contém controles padrão do Windows. Ele atua como uma caixa de diálogo que contém os controles e oferece suporte a tabulação entre eles. Ele também atua como uma caixa de diálogo que utiliza um modelo de caixa de diálogo para representar a barra.  
  
 A `CDialogBar` é usada para a barra de ferramentas de visualização de impressão, que contém controles padrão do botão de pressão.  
  
 Usando um `CDialogBar` é como usar um `CFormView`. Você deve definir um modelo de caixa de diálogo para a barra da caixa de diálogo e remover todos os estilos exceto **WS\_CHILD**. Observe que a caixa de diálogo não deve estar visível.  
  
 As notificações de controle para um `CDialogBar` será enviado para o pai da barra de controle \(como botões da barra de ferramentas\).  
  
## Suporte a CCmdUI CDialogBar  
 Botões da barra de diálogo devem ser atualizados por meio do `ON_UPDATE_COMMAND_UI` mecanismo do manipulador. No tempo ocioso, a barra de diálogo chamará o `ON_UPDATE_COMMAND_UI` manipulador com a ID de comando de todos os botões que têm uma ID \> 0x8000 \(isto é, no intervalo de IDs de comando\).  
  
 O `ON_UPDATE_COMMAND_UI` manipulador pode chamar:  
  
-   Habilitar: para habilitar ou desabilitar o botão.  
  
-   SetText: para alterar o texto do botão.  
  
 Personalização pode ser feita por meio de APIs do Gerenciador de janela padrão.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)