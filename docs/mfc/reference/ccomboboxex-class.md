---
title: "Classe de CComboBoxEx | Microsoft Docs"
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
  - "CComboBoxEx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComboBoxEx"
  - "caixas de combinação [C++], Classe de CComboBoxEx"
  - "controles comuns [C++], caixas de combinação estendidos"
  - "caixas de combinação estendidos, Classe de CComboBoxEx"
  - "Controles comuns do Internet Explorer 4.0"
  - "Controles comuns do Windows [C++], caixas de combinação estendidos"
ms.assetid: 33ca960a-2409-478c-84a4-a2ee8ecfe8f7
caps.latest.revision: 26
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComboBoxEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Estende o controle caixa de combinação fornecendo suporte para listas de imagem.  
  
## Sintaxe  
  
```  
class CComboBoxEx : public CComboBox  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComboBoxEx::CComboBoxEx](../Topic/CComboBoxEx::CComboBoxEx.md)|Constrói um objeto de `CComboBoxEx` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComboBoxEx::Create](../Topic/CComboBoxEx::Create.md)|Cria a caixa de combinação e anexá\-la ao objeto de `CComboBoxEx` .|  
|[CComboBoxEx::CreateEx](../Topic/CComboBoxEx::CreateEx.md)|Cria uma caixa de combinação com os estilos estendidos o windows especificados e anexá\-la a um objeto de **ComboBoxEx** .|  
|[CComboBoxEx::DeleteItem](../Topic/CComboBoxEx::DeleteItem.md)|Remove um item de um controle de **ComboBoxEx** .|  
|[CComboBoxEx::GetComboBoxCtrl](../Topic/CComboBoxEx::GetComboBoxCtrl.md)|Recupera um ponteiro para o controle filho da caixa combo.|  
|[CComboBoxEx::GetEditCtrl](../Topic/CComboBoxEx::GetEditCtrl.md)|Recupera o identificador para a parte do controle de edição de um controle de **ComboBoxEx** .|  
|[CComboBoxEx::GetExtendedStyle](../Topic/CComboBoxEx::GetExtendedStyle.md)|Recupera os estilos estendidos que estão em uso para um controle de **ComboBoxEx** .|  
|[CComboBoxEx::GetImageList](../Topic/CComboBoxEx::GetImageList.md)|Recupera um ponteiro à lista de imagem atribuída a um controle de **ComboBoxEx** .|  
|[CComboBoxEx::GetItem](../Topic/CComboBoxEx::GetItem.md)|Recupera informações de item para um determinado item de **ComboBoxEx** .|  
|[CComboBoxEx::HasEditChanged](../Topic/CComboBoxEx::HasEditChanged.md)|Determina se o usuário alterou o conteúdo do controle de edição de **ComboBoxEx** digitando.|  
|[CComboBoxEx::InsertItem](../Topic/CComboBoxEx::InsertItem.md)|Insere um novo item em um controle de **ComboBoxEx** .|  
|[CComboBoxEx::SetExtendedStyle](../Topic/CComboBoxEx::SetExtendedStyle.md)|Estilos estendidos conjuntos dentro de um controle de **ComboBoxEx** .|  
|[CComboBoxEx::SetImageList](../Topic/CComboBoxEx::SetImageList.md)|Define uma lista de imagem para um controle de **ComboBoxEx** .|  
|[CComboBoxEx::SetItem](../Topic/CComboBoxEx::SetItem.md)|Defina os atributos para um item em um controle de **ComboBoxEx** .|  
|[CComboBoxEx::SetWindowTheme](../Topic/CComboBoxEx::SetWindowTheme.md)|Defina o estilo visual do controle estendido de caixa combo.|  
  
## Comentários  
 Usando `CComboBoxEx` para criar controles de caixa combo, você não precisará implementar seu próprio código de desenho de imagem.  Em vez de isso, o uso `CComboBoxEx` acessar imagens de uma imagem lista.  
  
## Suporte a lista de imagem  
 Em uma caixa de combinação padrão, o proprietário da caixa de combinação é responsável por desenhar uma imagem criando a caixa de combinação como um controle do proprietário.  Quando você usa `CComboBoxEx`, você não precisa definir os estilos **CBS\_OWNERDRAWFIXED** e **CBS\_HASSTRINGS** de desenho porque eles são implicados.  Caso contrário, você deve escrever código para executar operações de desenho.  Suporte de um controle de `CComboBoxEx` até três imagens cada um: um para um estado selecionado, um para um estado cancelado a seleção, e um para uma imagem de sobreposição.  
  
## Estilos  
 `CComboBoxEx` suporta os estilos **CBS\_SIMPLE**, **CBS\_DROPDOWN**, **CBS\_DROPDOWNLIST**, e **WS\_CHILD**.  Todos outros estilos passada quando você cria a janela é ignorado pelo controle.  Após a janela é criada, você pode fornecer outros estilos de caixa combo chamar a função de membro [SetExtendedStyle](../Topic/CComboBoxEx::SetExtendedStyle.md)de `CComboBoxEx` .  Com esses estilos, você pode:  
  
-   Pesquisas de cadeia de caracteres definidas na lista para diferenciar maiúsculas de minúsculas.  
  
-   Crie um controle de caixa de combinação que use a barra \(\/“"\), barra invertida \(\\ “"\), e o ponto final \(“. "\) como caracteres delimitadores palavra.  Isso permite que os usuários saltar do word a palavra, usando a SETA de atalho de teclado CTRL\+.  
  
-   Definir o controle de caixa de combinação para exibir ou para não exibir uma imagem.  Se nenhuma imagem é exibida, a caixa combo pode remover o recorte de texto que acomoda uma imagem.  
  
-   Crie um controle estreito de caixa de combinação, incluindo dimensionamento o portanto recorta a caixa de combinação que contém mais amplo.  
  
 Esses sinalizadores de estilo são descritos mais em [usando CComboBoxEx](../../mfc/using-ccomboboxex.md).  
  
## Atributos de item de retenção e de retorno de chamada de item  
 Informações do item, como índices para itens e imagens, valores de recuo, e cadeias de caracteres de texto, é armazenada na estrutura [COMBOBOXEXITEM](http://msdn.microsoft.com/library/windows/desktop/bb775746)Win32, como descrito em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  A estrutura também contém membros que correspondem aos sinalizadores de retorno de chamada.  
  
 Para uma discussão detalhada, conceitualmente, consulte [usando CComboBoxEx](../../mfc/using-ccomboboxex.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CComboBox](../../mfc/reference/ccombobox-class.md)  
  
 `CComboBoxEx`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [Exemplo MFCIE MFC](../../top/visual-cpp-samples.md)   
 [Classe de CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CComboBox](../../mfc/reference/ccombobox-class.md)