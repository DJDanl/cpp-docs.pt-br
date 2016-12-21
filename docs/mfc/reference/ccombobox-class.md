---
title: "Classe de CComboBox | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CComboBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComboBox"
  - "caixas de combinação, Objetos de CComboBox"
ms.assetid: 4e73b5df-0d2e-4658-9706-38133fb10513
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComboBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma caixa de combinação do windows.  
  
## Sintaxe  
  
```  
class CComboBox : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComboBox::CComboBox](../Topic/CComboBox::CComboBox.md)|Constrói um objeto de `CComboBox` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComboBox::AddString](../Topic/CComboBox::AddString.md)|Adiciona uma cadeia de caracteres ao final da lista na caixa de listagem de uma caixa de combinação, ou na posição classificada para caixas de listagem com o estilo de **CBS\_SORT** .|  
|[CComboBox::Clear](../Topic/CComboBox::Clear.md)|Exclui \(limpa\) a seleção atual, se houver, o controle de edição.|  
|[CComboBox::CompareItem](../Topic/CComboBox::CompareItem.md)|Chamado pela estrutura para determinar a posição relativa de um novo item de uma caixa de combinação proprietário desenhada classificado.|  
|[CComboBox::Copy](../Topic/CComboBox::Copy.md)|Copia a seleção atual, se houver, na área de transferência no formato de **CF\_TEXT** .|  
|[CComboBox::Create](../Topic/CComboBox::Create.md)|Cria a caixa de combinação e anexá\-la ao objeto de `CComboBox` .|  
|[CComboBox::Cut](../Topic/CComboBox::Cut.md)|Exclui \(corta\) a seleção atual, se houver, o controle de edição e as cópias o texto excluído na área de transferência no formato de **CF\_TEXT** .|  
|[CComboBox::DeleteItem](../Topic/CComboBox::DeleteItem.md)|Chamado pela estrutura quando um item de lista é excluído de uma caixa de combinação proprietário desenhada.|  
|[CComboBox::DeleteString](../Topic/CComboBox::DeleteString.md)|Exclui uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|  
|[CComboBox::Dir](../Topic/CComboBox::Dir.md)|Adiciona uma lista de nomes de arquivo para a caixa de listagem de uma caixa de combinação.|  
|[CComboBox::DrawItem](../Topic/CComboBox::DrawItem.md)|Chamado pela estrutura quando uma aparência visual de uma caixa de combinação proprietário desenhada alterar.|  
|[CComboBox::FindString](../Topic/CComboBox::FindString.md)|Localiza a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::FindStringExact](../Topic/CComboBox::FindStringExact.md)|Localiza a primeira cadeia de caracteres da caixa de listagem \(em uma caixa combo\) que corresponde a cadeia de caracteres especificada.|  
|[CComboBox::GetComboBoxInfo](../Topic/CComboBox::GetComboBoxInfo.md)|Recupera informações sobre o objeto de `CComboBox` .|  
|[CComboBox::GetCount](../Topic/CComboBox::GetCount.md)|Retorna o número de itens na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetCueBanner](../Topic/CComboBox::GetCueBanner.md)|Obtém o indicação de texto que é exibido em um controle caixa de combinação.|  
|[CComboBox::GetCurSel](../Topic/CComboBox::GetCurSel.md)|Retorna o índice do item atualmente selecionado, se houver, na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetDroppedControlRect](../Topic/CComboBox::GetDroppedControlRect.md)|Recupera as coordenadas de tela \(solto para baixo\) da caixa de listagem visível de uma caixa de combinação drop\-down.|  
|[CComboBox::GetDroppedState](../Topic/CComboBox::GetDroppedState.md)|Determina se a caixa de listagem de uma caixa de combinação drop\-down estivesse visível \(solto para baixo\).|  
|[CComboBox::GetDroppedWidth](../Topic/CComboBox::GetDroppedWidth.md)|Obtém a largura reservada mínimo para a parte da lista suspensa de uma caixa de combinação.|  
|[CComboBox::GetEditSel](../Topic/CComboBox::GetEditSel.md)|Obtém as posições de caracteres de início e de fim de seleção atual no controle de edição de uma caixa de combinação.|  
|[CComboBox::GetExtendedUI](../Topic/CComboBox::GetExtendedUI.md)|Determina se uma caixa combo tem a interface de usuário padrão ou a interface do usuário estendido.|  
|[CComboBox::GetHorizontalExtent](../Topic/CComboBox::GetHorizontalExtent.md)|Retorna a largura em pixels que parte da caixa de lista da caixa combo pode ser rolada horizontalmente.|  
|[CComboBox::GetItemData](../Topic/CComboBox::GetItemData.md)|Recupera o valor de 32 bits do aplicativo fornecido associado com o item especificado da caixa combo.|  
|[CComboBox::GetItemDataPtr](../Topic/CComboBox::GetItemDataPtr.md)|Recupera o ponteiro de 32 bits do aplicativo fornecido que está associado com o item especificado da caixa combo.|  
|[CComboBox::GetItemHeight](../Topic/CComboBox::GetItemHeight.md)|Recupera a altura dos itens de uma caixa de combinação.|  
|[CComboBox::GetLBText](../Topic/CComboBox::GetLBText.md)|Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetLBTextLen](../Topic/CComboBox::GetLBTextLen.md)|Obtém o tamanho de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetLocale](../Topic/CComboBox::GetLocale.md)|Recupera a identificação de localidade para uma caixa de combinação.|  
|[CComboBox::GetMinVisible](../Topic/CComboBox::GetMinVisible.md)|Obtém o número mínimo de itens visíveis na lista suspensa de caixa combo atual.|  
|[CComboBox::GetTopIndex](../Topic/CComboBox::GetTopIndex.md)|Retorna o índice do primeiro item na parte visível da caixa de lista da caixa combo.|  
|[CComboBox::InitStorage](../Topic/CComboBox::InitStorage.md)|Preallocates blocos de memória para itens e cadeias de caracteres na parte da caixa de lista da caixa combo.|  
|[CComboBox::InsertString](../Topic/CComboBox::InsertString.md)|Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::LimitText](../Topic/CComboBox::LimitText.md)|Limitar o tamanho do texto que o usuário pode inserir o controle de edição de uma caixa de combinação.|  
|[CComboBox::MeasureItem](../Topic/CComboBox::MeasureItem.md)|Chamado pela estrutura para determinar dimensões da caixa de combinação quando uma caixa combo proprietário desenhada é criada.|  
|[CComboBox::Paste](../Topic/CComboBox::Paste.md)|Insere os dados da área de transferência no controle de edição na posição atual do cursor.  Os dados são inseridos somente se a área de transferência contém dados em um formato de **CF\_TEXT** .|  
|[CComboBox::ResetContent](../Topic/CComboBox::ResetContent.md)|Remove todos os itens de controle de caixa de listagem e de edição de uma caixa de combinação.|  
|[CComboBox::SelectString](../Topic/CComboBox::SelectString.md)|Procura por uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, selecione a cadeia de caracteres na caixa de listagem e copia a cadeia de caracteres ao controle de edição.|  
|[CComboBox::SetCueBanner](../Topic/CComboBox::SetCueBanner.md)|Define o texto da indicação que é exibido em um controle caixa de combinação.|  
|[CComboBox::SetCurSel](../Topic/CComboBox::SetCurSel.md)|Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::SetDroppedWidth](../Topic/CComboBox::SetDroppedWidth.md)|Defina a largura reservada mínimo para a parte da lista suspensa de uma caixa de combinação.|  
|[CComboBox::SetEditSel](../Topic/CComboBox::SetEditSel.md)|Seleciona caracteres no controle de edição de uma caixa de combinação.|  
|[CComboBox::SetExtendedUI](../Topic/CComboBox::SetExtendedUI.md)|Seleciona a interface de usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tem o estilo de **CBS\_DROPDOWN** ou de **CBS\_DROPDOWNLIST** .|  
|[CComboBox::SetHorizontalExtent](../Topic/CComboBox::SetHorizontalExtent.md)|Defina a largura em pixels que parte da caixa de lista da caixa combo pode ser rolada horizontalmente.|  
|[CComboBox::SetItemData](../Topic/CComboBox::SetItemData.md)|Defina o valor de 32 bits associado com o item especificado em uma caixa combo.|  
|[CComboBox::SetItemDataPtr](../Topic/CComboBox::SetItemDataPtr.md)|Define o ponteiro de 32 bits associado com o item especificado em uma caixa combo.|  
|[CComboBox::SetItemHeight](../Topic/CComboBox::SetItemHeight.md)|Defina a altura dos itens de uma caixa de combinação ou altura de editions parte do controle \(ou texto estático\) de uma caixa de combinação.|  
|[CComboBox::SetLocale](../Topic/CComboBox::SetLocale.md)|Define a identificação de localidade para uma caixa de combinação.|  
|[CComboBox::SetMinVisibleItems](../Topic/CComboBox::SetMinVisibleItems.md)|Define o número mínimo de itens visíveis na lista suspensa de caixa combo atual.|  
|[CComboBox::SetTopIndex](../Topic/CComboBox::SetTopIndex.md)|Informa a porção da caixa de listagem caixa de combinação para exibir o item com o índice especificado na parte superior.|  
|[CComboBox::ShowDropDown](../Topic/CComboBox::ShowDropDown.md)|Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o estilo de **CBS\_DROPDOWN** ou de **CBS\_DROPDOWNLIST** .|  
  
## Comentários  
 Uma caixa de combinação consiste em uma caixa de lista combinada com um controle estático ou o controle de edição.  A porção da caixa de listagem de controle pode ser exibida em todo ou só pode soltar para baixo quando o usuário seleciona a seta suspensa próxima do controle.  
  
 O item atualmente selecionado \(se houver\) na caixa de listagem estático ou é exibido no controle de edição.  Além de isso, se a caixa combo tem o estilo da lista suspensa, o usuário pode digitar o caractere inicial de um dos itens na lista, e a caixa de listagem, se visível, realçará o próximo item com o caractere inicial.  
  
 A tabela a seguir compara três a caixa de combinação [estilos](../../mfc/reference/combo-box-styles.md).  
  
|Style|Quando é a caixa de listagem visível?|Estático ou controle de edição?|  
|-----------|-------------------------------------------|-------------------------------------|  
|Simples|Sempre|Editar|  
|Lista suspensa|Quando solto para baixo|Editar|  
|Lista suspensa|Quando solto para baixo|Estático|  
  
 Você pode criar um objeto de `CComboBox` de um modelo na caixa de diálogo ou diretamente no seu código.  Em ambos os casos, primeiro chamar o construtor `CComboBox` para construir o objeto de `CComboBox` ; chame a função de membro de [Criar](../Topic/CComboBox::Create.md) para criar o controle para e anexá\-la ao objeto de `CComboBox` .  
  
 Se você desejar manipular as notificações do windows enviadas por uma caixa combo a seu pai \(geralmente uma classe derivada de `CDialog`\), adicionar uma função de membro de entrada e de mensagem\- manipulador de mensagem\- mapa para a classe pai para cada mensagem.  
  
 Cada entrada de mapa mensagem\- tem a seguinte forma:  
  
 Notificação**\(**`id`**,**`memberFxn`**\)**de**ON\_**  
  
 onde `id` especifica a identificação da janela filho do controle de caixa de combinação que envia a notificação e são `memberFxn` o nome da função de membro que você escreveu pai para trate a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx\_msg** `void` `memberFxn` **\( \);**  
  
 A ordem em que determinadas notificações enviadas serão não pode ser esperado.  Em particular, uma notificação de **CBN\_SELCHANGE** pode ocorrer ou antes ou após uma notificação de **CBN\_CLOSEUP** .  
  
 As possíveis entradas de mapa mensagem\- são as seguintes:  
  
-   **ON\_CBN\_CLOSEUP** \(Windows 3.1 e posterior.\) a caixa de listagem de uma caixa de combinação fechou\-se.  Essa notificação não é enviada para uma caixa de combinação que tem o estilo de [CBS\_SIMPLE](../../mfc/reference/combo-box-styles.md) .  
  
-   **ON\_CBN\_DBLCLK** o usuário clica duas vezes em uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  Essa notificação são enviadas somente para uma caixa de combinação com o estilo de **CBS\_SIMPLE** .  Para uma caixa de combinação com o estilo de [CBS\_DROPDOWN](../../mfc/reference/combo-box-styles.md) ou de [CBS\_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) , clique duas vezes não pode ocorrer porque um único clique oculta a caixa de listagem.  
  
-   **ON\_CBN\_DROPDOWN** a caixa de listagem de uma caixa de combinação é o ponto de soltar para baixo \(é feito visível\).  Essa notificação pode ocorrer apenas para uma caixa de combinação com o estilo de **CBS\_DROPDOWN** ou de **CBS\_DROPDOWNLIST** .  
  
-   **ON\_CBN\_EDITCHANGE** o usuário tiver efetuado uma ação que pode ter alterado o texto na parte de editions controle de uma caixa de combinação.  A o contrário da mensagem de **CBN\_EDITUPDATE** , essa mensagem é enviada depois que as janelas atualizem a tela.  Não é enviado se a caixa combo tem o estilo de **CBS\_DROPDOWNLIST** .  
  
-   **ON\_CBN\_EDITUPDATE** a parte de editions controle de uma caixa de combinação é o ponto de exibir o texto alterado.  Essa notificação é enviada após o controle tiver formatado o texto mas antes que exibe o texto.  Não é enviado se a caixa combo tem o estilo de **CBS\_DROPDOWNLIST** .  
  
-   **ON\_CBN\_ERRSPACE** a caixa de combinação não pode alocar memória suficiente para localizar uma solicitação específica.  
  
-   **ON\_CBN\_SELENDCANCEL** \(Windows 3.1 e posterior.\) Indica que a seleção do usuário deve ser cancelada.  O usuário clica em um item e clique em outra janela ou controle para ocultar a caixa de listagem de uma caixa de combinação.  Essa notificação é enviada antes de notificação de **CBN\_CLOSEUP** para indicar que a seleção do usuário deve ser ignorada.  Notificação de **CBN\_SELENDCANCEL** ou de **CBN\_SELENDOK** é enviada se a notificação de **CBN\_CLOSEUP** não é enviada \(como no caso de uma caixa de combinação com o estilo de **CBS\_SIMPLE** \).  
  
-   **ON\_CBN\_SELENDOK** o usuário seleciona um item e então pressione a tecla ENTER ou clique na SETA PARA BAIXO para ocultar a caixa de listagem de uma caixa de combinação.  Essa notificação é enviada antes que a mensagem de **CBN\_CLOSEUP** para indicar que a seleção do usuário deve ser considerada válido.  Notificação de **CBN\_SELENDCANCEL** ou de **CBN\_SELENDOK** é enviada se a notificação de **CBN\_CLOSEUP** não é enviada \(como no caso de uma caixa de combinação com o estilo de **CBS\_SIMPLE** \).  
  
-   **ON\_CBN\_KILLFOCUS** a caixa de combinação está perdendo o foco de entrada.  
  
-   **ON\_CBN\_SELCHANGE** a seleção na caixa de listagem de uma caixa de combinação está prestes a ser alterado como resultado de usuário clicar em na caixa de listagem ou que modifica a seleção usando as teclas de direção.  A o processar esta mensagem, o texto no controle de edição de caixa combo pode apenas ser recuperado através de `GetLBText` ou de outra função semelhante.  `GetWindowText` não pode ser usado.  
  
-   **ON\_CBN\_SETFOCUS** a caixa de combinação recebe o foco de entrada.  
  
 Se você criar um objeto de `CComboBox` de uma caixa de diálogo \(através de um recurso da caixa de diálogo\), o objeto de `CComboBox` é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você inserir um objeto de `CComboBox` dentro de outro objeto na janela, você não precisa destrui\-lo.  Se você criar o objeto de `CComboBox` na pilha, é automaticamente destruída.  Se você criar o objeto de `CComboBox` no heap usando a função de **new** , você deve chamar **delete** no objeto para destrui\-lo quando a caixa de combinação do windows é destruída.  
  
 **Observação** Se você deseja manipular `WM_KEYDOWN` e mensagens de `WM_CHAR` , você precisa subclasse os controles de edição e da caixa de listagem caixa de combinação, para derivar classes de `CEdit` e de `CListBox`, e para adicionar manipuladores para essas mensagens para classes derivadas.  Para obter mais informações, consulte [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;Q174667](http://support.microsoft.com/default.aspx?scid=kb;en-us;Q174667) e [CWnd::SubclassWindow](../Topic/CWnd::SubclassWindow.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CComboBox`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC exemplos CTRLBARS](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CButton](../../mfc/reference/cbutton-class.md)   
 [Classe de CEdit](../Topic/CEdit%20Class.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)   
 [Classe de CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe de CStatic](../Topic/CStatic%20Class.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)