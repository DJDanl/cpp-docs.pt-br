---
title: "Classe de CPropertySheet | Microsoft Docs"
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
  - "CPropertySheet"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPropertySheet"
  - "caixas de diálogo, snaplines"
  - "folhas de propriedade, Classe de CPropertySheet"
  - "caixas de diálogo da guia"
ms.assetid: 8461ccff-d14f-46e0-a746-42ad642ef94e
caps.latest.revision: 30
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPropertySheet
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa as folhas de propriedade, também conhecido como caixas de diálogo de tabulação.  
  
## Sintaxe  
  
```  
class CPropertySheet : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPropertySheet::CPropertySheet](../Topic/CPropertySheet::CPropertySheet.md)|Constrói um objeto de `CPropertySheet` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPropertySheet::AddPage](../Topic/CPropertySheet::AddPage.md)|Adiciona uma página a folha de propriedades.|  
|[CPropertySheet::Construct](../Topic/CPropertySheet::Construct.md)|Constrói um objeto de `CPropertySheet` .|  
|[CPropertySheet::Create](../Topic/CPropertySheet::Create.md)|Exibe uma folha de propriedades sem janela restrita.|  
|[CPropertySheet::DoModal](../Topic/CPropertySheet::DoModal.md)|Exibe uma folha de propriedades modal.|  
|[CPropertySheet::EnableStackedTabs](../Topic/CPropertySheet::EnableStackedTabs.md)|Indica se a folha de propriedades usa guias empilhado ou de rolagem.|  
|[CPropertySheet::EndDialog](../Topic/CPropertySheet::EndDialog.md)|Finaliza a folha de propriedades.|  
|[CPropertySheet::GetActiveIndex](../Topic/CPropertySheet::GetActiveIndex.md)|Retorna o índice da página ativo da folha de propriedades.|  
|[CPropertySheet::GetActivePage](../Topic/CPropertySheet::GetActivePage.md)|Retorna o objeto de página.|  
|[CPropertySheet::GetPage](../Topic/CPropertySheet::GetPage.md)|Recupera um ponteiro para a página especificada.|  
|[CPropertySheet::GetPageCount](../Topic/CPropertySheet::GetPageCount.md)|Retorna o número de páginas na folha de propriedades.|  
|[CPropertySheet::GetPageIndex](../Topic/CPropertySheet::GetPageIndex.md)|Retorna o índice da página especificada da folha de propriedades.|  
|[CPropertySheet::GetTabControl](../Topic/CPropertySheet::GetTabControl.md)|Recupera um ponteiro para um controle de guia.|  
|[CPropertySheet::MapDialogRect](../Topic/CPropertySheet::MapDialogRect.md)|Converte as unidades de diálogo de um retângulo para selecionar unidades.|  
|[CPropertySheet::OnInitDialog](../Topic/CPropertySheet::OnInitDialog.md)|Substituição para aumentar a inicialização da folha de propriedades.|  
|[CPropertySheet::PressButton](../Topic/CPropertySheet::PressButton.md)|Simula a escolha do botão especificado em uma folha de propriedades.|  
|[CPropertySheet::RemovePage](../Topic/CPropertySheet::RemovePage.md)|Remove uma página da folha de propriedades.|  
|[CPropertySheet::SetActivePage](../Topic/CPropertySheet::SetActivePage.md)|Defina programaticamente o objeto da página.|  
|[CPropertySheet::SetFinishText](../Topic/CPropertySheet::SetFinishText.md)|Define o texto do botão de suporte.|  
|[CPropertySheet::SetTitle](../Topic/CPropertySheet::SetTitle.md)|Define a legenda da folha de propriedades.|  
|[CPropertySheet::SetWizardButtons](../Topic/CPropertySheet::SetWizardButtons.md)|Permite que os botões do assistente.|  
|[CPropertySheet::SetWizardMode](../Topic/CPropertySheet::SetWizardMode.md)|Ativar o modo do assistente.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPropertySheet::m\_psh](../Topic/CPropertySheet::m_psh.md)|A estrutura de [PROPSHEETHEADER](http://msdn.microsoft.com/library/windows/desktop/bb774546) do windows.  Fornece acesso aos parâmetros básicos da folha de propriedades.|  
  
## Comentários  
 Uma folha de propriedades consiste em um objeto de `CPropertySheet` e em um ou mais objetos de [CPropertyPage](../../mfc/reference/cpropertypage-class.md) .  A estrutura exibe uma folha de propriedades como uma janela com um conjunto de índices da guia e uma área que contém a página selecionada.  O usuário navegar para uma página específica usando a guia apropriada.  
  
 `CPropertySheet` fornece suporte para a estrutura expandida de [PROPSHEETHEADER](http://msdn.microsoft.com/library/windows/desktop/bb774546) introduzida em [!INCLUDE[Win98](../../mfc/reference/includes/win98_md.md)] e no Windows NT 2000.  A estrutura contém os sinalizadores e membros adicionais que suportam usando um bitmap de plano de fundo do “marca de agua”.  
  
 Para exibir novos automaticamente essas imagens no seu objeto da folha de propriedades, passe valores válidos para o bitmap e a paleta imagens na chamada a [CPropertySheet::Construct](../Topic/CPropertySheet::Construct.md) ou a [CPropertySheet::CPropertySheet](../Topic/CPropertySheet::CPropertySheet.md).  
  
 Mesmo que `CPropertySheet` não é derivado de [CDialog](../../mfc/reference/cdialog-class.md), gerenciar um objeto de `CPropertySheet` é como gerenciar um objeto de `CDialog` .  Por exemplo, a criação de uma folha de propriedades requer a compilação duas partes: o construtor, e então chame [DoModal](../Topic/CPropertySheet::DoModal.md) para uma folha de propriedades modal ou [Criar](../Topic/CPropertySheet::Create.md) para uma folha de propriedades sem janela restrita.  `CPropertySheet` tem dois tipos de construtores: [CPropertySheet::Construct](../Topic/CPropertySheet::Construct.md) e [CPropertySheet::CPropertySheet](../Topic/CPropertySheet::CPropertySheet.md).  
  
 Quando você constrói um objeto de `CPropertySheet` , qualquer [Estilos de janela](../Topic/Window%20Styles.md) pode fazer com que uma exceção de primeira tentativa ocorra.  Isso resulta do sistema que tenta alterar o estilo de folha propriedade antes da folha ser criada.  Para evitar essa exceção, certifique\-se de definir os seguintes estilos quando você cria seu `CPropertySheet`:  
  
-   DS\_3DLOOK  
  
-   DS\_CONTROL  
  
-   WS\_CHILD  
  
-   WS\_TABSTOP  
  
 Os seguintes estilos são opcionais, e não fará com que a exceção de primeira tentativa:  
  
-   DS\_SHELLFONT  
  
-   DS\_LOCALEDIT  
  
-   WS\_CLIPCHILDREN  
  
 Qualquer outro `Window Styles` é proibido e você não deve permite que eles.  
  
 Os trocar dados entre um objeto de `CPropertySheet` e um objeto externo são semelhantes para trocar dados com um objeto de `CDialog` .  A diferença importante é que as configurações de uma folha de propriedades são normalmente variáveis de membro de objetos de `CPropertyPage` em vez do próprio objeto de `CPropertySheet` .  
  
 Você pode criar um tipo de caixa de diálogo de guia chamado um assistente, que consiste em uma folha de propriedades com uma seqüência de páginas de propriedades que guiam o usuário através das etapas de uma operação, como configurar um dispositivo ou a criação de um boletim de notícias.  Em uma caixa de diálogo de guia de uma tipo, as páginas de propriedades não têm guias, e apenas uma página de propriedades é visível em vez.  Além de isso, em vez de ter **OK** e botões de **Aplicar agora** , uma caixa de diálogo de guia de uma tipo tem um botão de **Voltar** , um botão de **Avançar** ou de **Concluir** , um botão de **Cancelar** , e um botão de **Ajuda** .  
  
 Para criar um caixa de diálogo de uma tipo, siga as mesmas etapas que você seguiria para criar um folha de propriedades padrão, mas a chamada [SetWizardMode](../Topic/CPropertySheet::SetWizardMode.md) antes de chamar [DoModal](../Topic/CPropertySheet::DoModal.md).  Para ativar os botões do assistente, chame [SetWizardButtons](../Topic/CPropertySheet::SetWizardButtons.md), usando os sinalizadores para personalizar suas função e aparência.  Para ativar o botão de **Concluir** , chamada [SetFinishText](../Topic/CPropertySheet::SetFinishText.md) após o usuário tem a ação colocada na última página do assistente.  
  
 Para obter mais informações sobre como usar objetos de `CPropertySheet` , consulte o artigo [folhas e páginas de propriedades de propriedade](../../mfc/property-sheets-and-property-pages-in-mfc.md).  Além de isso, consulte o artigo de Base de Dados de Conhecimento Q146916: HOWTO: Crie um CPropertySheet sem\-modo com os botões padrão e o artigo Q300606: HOWTO: Criar uma folha de propriedades redimensionável MFC.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CPropertySheet`  
  
## Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL1](../../top/visual-cpp-samples.md)   
 [Exemplo CMNCTRL2 MFC](../../top/visual-cpp-samples.md)   
 [Exemplo PROPDLG MFC](../../top/visual-cpp-samples.md)   
 [Exemplo SNAPVW MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)