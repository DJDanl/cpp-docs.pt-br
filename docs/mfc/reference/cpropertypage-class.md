---
title: "Classe de CPropertyPage | Microsoft Docs"
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
  - "CPropertyPage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPropertyPage"
  - "caixas de diálogo, snaplines"
  - "páginas de propriedades, Classe de CPropertyPage"
  - "caixas de diálogo da guia"
ms.assetid: d9000a21-aa81-4530-85d9-f43432afb4dc
caps.latest.revision: 25
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPropertyPage
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa as páginas individuais de uma folha de propriedades, se não conhecido como uma caixa de diálogo de tabulação.  
  
## Sintaxe  
  
```  
class CPropertyPage : public CDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPropertyPage::CPropertyPage](../Topic/CPropertyPage::CPropertyPage.md)|Constrói um objeto de `CPropertyPage` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPropertyPage::CancelToClose](../Topic/CPropertyPage::CancelToClose.md)|Altera o botão OK para ler o final, e desativa o botão cancelar, após uma alteração irrecuperável de uma página na folha de propriedades modal.|  
|[CPropertyPage::Construct](../Topic/CPropertyPage::Construct.md)|Constrói um objeto de `CPropertyPage` .  Use `Construct` se você desejar especificar em tempo de execução seus parâmetros, ou se você estiver usando matrizes.|  
|[CPropertyPage::GetPSP](../Topic/CPropertyPage::GetPSP.md)|Recupera a estrutura de [PROPSHEETPAGE](http://msdn.microsoft.com/library/windows/desktop/bb774548) do windows associada com o objeto de `CPropertyPage` .|  
|[CPropertyPage::OnApply](../Topic/CPropertyPage::OnApply.md)|Chamado pela estrutura quando se aplicar os botões agora é clicado.|  
|[CPropertyPage::OnCancel](../Topic/CPropertyPage::OnCancel.md)|Chamado pela estrutura quando o botão cancelar for clicado.|  
|[CPropertyPage::OnKillActive](../Topic/CPropertyPage::OnKillActive.md)|Chamado pela estrutura quando a página atual não está mais a página.  Executar a validação de dados aqui.|  
|[CPropertyPage::OnOK](../Topic/CPropertyPage::OnOK.md)|Chamado pela estrutura quando OK, se aplica agora, ou pelo próximo botão é clicado.|  
|[CPropertyPage::OnQueryCancel](../Topic/CPropertyPage::OnQueryCancel.md)|Chamado pela estrutura quando o botão cancelar é clicado, e antes de cancelamento ocorreu.|  
|[CPropertyPage::OnReset](../Topic/CPropertyPage::OnReset.md)|Chamado pela estrutura quando o botão cancelar for clicado.|  
|[CPropertyPage::OnSetActive](../Topic/CPropertyPage::OnSetActive.md)|Chamado pela estrutura quando a página for feita à página.|  
|[CPropertyPage::OnWizardBack](../Topic/CPropertyPage::OnWizardBack.md)|Chamado pela estrutura quando o botão é clicado novamente ao usar um folha de propriedades de uma tipo.|  
|[CPropertyPage::OnWizardFinish](../Topic/CPropertyPage::OnWizardFinish.md)|Chamado pela estrutura de suporte quando o botão é clicado para usar uma folha de propriedades de uma tipo.|  
|[CPropertyPage::OnWizardNext](../Topic/CPropertyPage::OnWizardNext.md)|Chamado pela estrutura quando o botão é clicado seguir ao usar um folha de propriedades de uma tipo.|  
|[CPropertyPage::QuerySiblings](../Topic/CPropertyPage::QuerySiblings.md)|Encaminha a mensagem para cada página de folha de propriedades.|  
|[CPropertyPage::SetModified](../Topic/CPropertyPage::SetModified.md)|A chamada para ativar ou desativar aplicar os agora.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPropertyPage::m\_psp](../Topic/CPropertyPage::m_psp.md)|A estrutura de [PROPSHEETPAGE](http://msdn.microsoft.com/library/windows/desktop/bb774548) do windows.  Fornece acesso aos parâmetros básicos da página de propriedades.|  
  
## Comentários  
 Como com caixas de diálogo padrão, você deriva de uma classe `CPropertyPage` para cada página na folha de propriedades.  Para usar `CPropertyPage`de objetos derivados, primeiro crie um objeto de [CPropertySheet](../../mfc/reference/cpropertysheet-class.md) , e então crie um objeto para cada página que aparece na folha de propriedades.  Chame [CPropertySheet::AddPage](../Topic/CPropertySheet::AddPage.md) para cada página na folha e em seguida, exibir a folha de propriedades chamando [CPropertySheet::DoModal](../Topic/CPropertySheet::DoModal.md) para uma folha de propriedades modal, ou [CPropertySheet::Create](../Topic/CPropertySheet::Create.md) para uma folha de propriedades sem janela restrita.  
  
 Você pode criar um tipo de caixa de diálogo de guia chamado um assistente, que consiste em uma folha de propriedades com uma seqüência de páginas de propriedades que guiam o usuário através das etapas de uma operação, como configurar um dispositivo ou a criação de um boletim de notícias.  Em uma caixa de diálogo de guia de uma tipo, as páginas de propriedades não têm guias, e apenas uma página de propriedades é visível em vez.  Além de isso, em vez de ter OK e aplicar agora botões, um tipo que uma guia da caixa de diálogo tem um botão voltar de em seguida, um botão ou de suporte, e um botão cancelar.  
  
 Para obter mais informações sobre como estabelecer uma folha de propriedades como um assistente, consulte [CPropertySheet::SetWizardMode](../Topic/CPropertySheet::SetWizardMode.md).  Para obter mais informações sobre como usar objetos de `CPropertyPage` , consulte o artigo [folhas e páginas de propriedades de propriedade](../../mfc/property-sheets-and-property-pages-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 `CPropertyPage`  
  
## Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL1](../../top/visual-cpp-samples.md)   
 [Exemplo CMNCTRL2 MFC](../../top/visual-cpp-samples.md)   
 [Exemplo PROPDLG MFC](../../top/visual-cpp-samples.md)   
 [Exemplo SNAPVW MFC](../../top/visual-cpp-samples.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CPropertySheet](../../mfc/reference/cpropertysheet-class.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)   
 [CPropertySheet::SetWizardMode](../Topic/CPropertySheet::SetWizardMode.md)