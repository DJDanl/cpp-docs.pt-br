---
title: "Classe de CPrintDialogEx | Microsoft Docs"
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
  - "CPrintDialogEx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPrintDialogEx"
  - "Caixa de diálogo de impressão"
  - "Caixa de diálogo de configuração de impressão"
ms.assetid: 1d506703-ee1c-44cc-b4ce-4e778fec26b8
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPrintDialogEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula os serviços fornecidos pela folha de propriedades de impressão do Windows 2000.  
  
## Sintaxe  
  
```  
class CPrintDialogEx : public CCommonDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPrintDialogEx::CPrintDialogEx](../Topic/CPrintDialogEx::CPrintDialogEx.md)|Constrói um objeto de `CPrintDialogEx` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPrintDialogEx::CreatePrinterDC](../Topic/CPrintDialogEx::CreatePrinterDC.md)|Cria um contexto do dispositivo de impressora sem exibir a caixa de diálogo de impressão.|  
|[CPrintDialogEx::DoModal](../Topic/CPrintDialogEx::DoModal.md)|Exibe a caixa de diálogo e permite que o usuário faça seleções.|  
|[CPrintDialogEx::GetCopies](../Topic/CPrintDialogEx::GetCopies.md)|Retorna o número de cópias solicitados.|  
|[CPrintDialogEx::GetDefaults](../Topic/CPrintDialogEx::GetDefaults.md)|Recupera opções de dispositivo sem exibir uma caixa de diálogo.|  
|[CPrintDialogEx::GetDeviceName](../Topic/CPrintDialogEx::GetDeviceName.md)|Recupera o nome de dispositivo de impressão atualmente selecionado.|  
|[CPrintDialogEx::GetDevMode](../Topic/CPrintDialogEx::GetDevMode.md)|Recupera a estrutura de `DEVMODE` .|  
|[CPrintDialogEx::GetDriverName](../Topic/CPrintDialogEx::GetDriverName.md)|Recupera o nome do driver de dispositivo definido pelo sistema de impressão.|  
|[CPrintDialogEx::GetPortName](../Topic/CPrintDialogEx::GetPortName.md)|Recupera o nome da porta de impressora selecionada.|  
|[CPrintDialogEx::GetPrinterDC](../Topic/CPrintDialogEx::GetPrinterDC.md)|Recupera um identificador para o contexto do dispositivo de impressora.|  
|[CPrintDialogEx::PrintAll](../Topic/CPrintDialogEx::PrintAll.md)|Determina se imprimir todas as páginas do documento.|  
|[CPrintDialogEx::PrintCollate](../Topic/CPrintDialogEx::PrintCollate.md)|Determina se as cópias agrupada são solicitados.|  
|[CPrintDialogEx::PrintCurrentPage](../Topic/CPrintDialogEx::PrintCurrentPage.md)|Determina se imprimir a página atual do documento.|  
|[CPrintDialogEx::PrintRange](../Topic/CPrintDialogEx::PrintRange.md)|Determina se apenas impressão um intervalo específico de páginas.|  
|[CPrintDialogEx::PrintSelection](../Topic/CPrintDialogEx::PrintSelection.md)|Determina se apenas impressão os itens atualmente selecionados.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPrintDialogEx::m\_pdex](../Topic/CPrintDialogEx::m_pdex.md)|Uma estrutura usada para personalizar um objeto de `CPrintDialogEx` .|  
  
## Comentários  
 Você pode confiar na estrutura para manipular muitos aspectos do processo de impressão para seu aplicativo.  Para obter mais informações sobre como usar a estrutura para gerenciar tarefas de impressão, consulte o artigo [Imprimindo](../../mfc/printing.md).  
  
 Se você quiser que seu aplicativo manipule a impressão sem participação de estrutura, você pode usar a classe de `CPrintDialogEx` como “é” com o construtor fornecido, ou você pode derivar sua própria classe da caixa de diálogo de `CPrintDialogEx` e escrever um construtor para atender às suas necessidades.  Em ambos os casos, essas caixas de diálogo se comportar como caixas de diálogo padrão MFC porque eles são derivadas da classe `CCommonDialog`.  
  
 Para usar um objeto de `CPrintDialogEx` , primeiro crie o objeto usando o construtor de `CPrintDialogEx` .  Uma vez que a caixa de diálogo foi construída, você pode definir ou modificar os valores na estrutura de [m\_pdex](../Topic/CPrintDialogEx::m_pdex.md) para inicializar valores dos controles da caixa de diálogo.  A estrutura de `m_pdex` é do tipo [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844).  Para obter mais informações sobre essa estrutura, consulte [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se você não fornecer suas próprias identificadores em `m_pdex` para os membros de **hDevMode** e de **hDevNames** , certifique\-se chamar a função do windows **GlobalFree** para essas alças quando você concluiu a caixa de diálogo.  
  
 Após inicializado os controles de caixa de diálogo, chame a função de membro de `DoModal` para exibir a caixa de diálogo e para permitir que o usuário selecione opções de impressão.  Quando `DoModal` retorna, você pode determinar se o usuário tiver selecionado, aplica, OK ou cancelar o botão.  
  
 Se o usuário pressionou OK, você pode usar as funções de membro de `CPrintDialogEx` para recuperar informações de entrada pelo usuário.  
  
 A função de membro de `CPrintDialogEx::GetDefaults` é útil para recuperar as opções de impressão atual sem exibir uma caixa de diálogo.  Este método não requer qualquer interação do usuário.  
  
 Você pode usar a função de **CommDlgExtendedError** do windows para determinar se um erro ocorrer durante a inicialização da caixa de diálogo e para aprender mais sobre o erro.  Para obter mais informações sobre essa função, consulte [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre como usar `CPrintDialogEx`, consulte [Classes comuns da caixa de diálogo](../../mfc/common-dialog-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 `IObjectWithSite`  
  
 `IPrintDialogCallback`  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 `CPrintDialogEx`  
  
## Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
## Consulte também  
 [Classe de CCommonDialog](../Topic/CCommonDialog%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Estrutura de CPrintInfo](../../mfc/reference/cprintinfo-structure.md)