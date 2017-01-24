---
title: "Classe de CPageSetupDialog | Microsoft Docs"
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
  - "CPageSetupDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPageSetupDialog"
  - "Caixa de diálogo OLE de configuração de página"
  - "configuração de página"
  - "Caixa de diálogo de configuração de página"
  - "Caixa de diálogo de configuração de impressão"
ms.assetid: 049c0ac8-f254-4854-9414-7a8271d1447a
caps.latest.revision: 24
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPageSetupDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula os serviços fornecidos pela caixa de diálogo OLE comuns de configuração de página do windows com suporte adicional para definir margens e de alteração de impressão.  
  
## Sintaxe  
  
```  
class CPageSetupDialog : public CCommonDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPageSetupDialog::CPageSetupDialog](../Topic/CPageSetupDialog::CPageSetupDialog.md)|Constrói um objeto de `CPageSetupDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPageSetupDialog::CreatePrinterDC](../Topic/CPageSetupDialog::CreatePrinterDC.md)|Cria um contexto de dispositivo para imprimir.|  
|[CPageSetupDialog::DoModal](../Topic/CPageSetupDialog::DoModal.md)|Exibe a caixa de diálogo e permite que o usuário fizerem uma seleção.|  
|[CPageSetupDialog::GetDeviceName](../Topic/CPageSetupDialog::GetDeviceName.md)|Retorna o nome de dispositivo da impressora.|  
|[CPageSetupDialog::GetDevMode](../Topic/CPageSetupDialog::GetDevMode.md)|Retorna `DEVMODE` atual da impressora.|  
|[CPageSetupDialog::GetDriverName](../Topic/CPageSetupDialog::GetDriverName.md)|Retorna o driver usado pela impressora.|  
|[CPageSetupDialog::GetMargins](../Topic/CPageSetupDialog::GetMargins.md)|Retorna as configurações atuais de margem da impressora.|  
|[CPageSetupDialog::GetPaperSize](../Topic/CPageSetupDialog::GetPaperSize.md)|Retorna o tamanho do papel da impressora.|  
|[CPageSetupDialog::GetPortName](../Topic/CPageSetupDialog::GetPortName.md)|Retorna o nome da porta de saída.|  
|[CPageSetupDialog::OnDrawPage](../Topic/CPageSetupDialog::OnDrawPage.md)|Chamado pela estrutura para processar uma imagem de tela de uma página impresso.|  
|[CPageSetupDialog::PreDrawPage](../Topic/CPageSetupDialog::PreDrawPage.md)|Chamado pela estrutura antes de processar uma imagem de tela de uma página impresso.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPageSetupDialog::m\_psd](../Topic/CPageSetupDialog::m_psd.md)|Uma estrutura usada para personalizar um objeto de `CPageSetupDialog` .|  
  
## Comentários  
 Essa classe é criada para pegar o local da caixa de diálogo de configuração de impressão.  
  
 Para usar um objeto de `CPageSetupDialog` , primeiro crie o objeto usando o construtor de `CPageSetupDialog` .  Uma vez que a caixa de diálogo foi construída, você pode definir ou modificar os valores no membro de dados de `m_psd` para inicializar valores dos controles da caixa de diálogo.  A estrutura de [m\_psd](../Topic/CPageSetupDialog::m_psd.md) é do tipo **PAGESETUPDLG**.  
  
 Após inicializado os controles de caixa de diálogo, chame a função de membro de `DoModal` para exibir a caixa de diálogo e para permitir que o usuário selecione opções de impressão.  `DoModal` retorna se o usuário tiver selecionado OK \(**IDOK**\) ou o botão cancelar \(**IDCANCEL**\).  
  
 Se `DoModal` retorna **IDOK**, você pode usar várias das funções de membro de `CPageSetupDialog`, ou acessar o membro de dados de `m_psd` , para recuperar informações de entrada pelo usuário.  
  
> [!NOTE]
>  Depois que a caixa de diálogo OLE comuns de configuração de página é demitida, qualquer alteração feita pelo usuário não serão salvas estrutura.  Até o próprio aplicativo salvar os valores de esta caixa de diálogo para um local não\-volátil, como o membro de documento de aplicativo ou da classe do aplicativo.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 `CPageSetupDialog`  
  
## Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
## Consulte também  
 [Exemplo WORDPAD MFC](../../top/visual-cpp-samples.md)   
 [Classe de CCommonDialog](../Topic/CCommonDialog%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)