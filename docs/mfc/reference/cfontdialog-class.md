---
title: "Classe de CFontDialog | Microsoft Docs"
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
  - "CFontDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFontDialog"
  - "caixas de diálogo, fontes"
  - "fontes"
  - "fontes, selecione"
ms.assetid: 6228d500-ed0f-4156-81e5-ab0d57d1dcf4
caps.latest.revision: 25
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFontDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que você insira uma caixa de diálogo de fontes seleção em seu aplicativo.  
  
## Sintaxe  
  
```  
class CFontDialog : public CCommonDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFontDialog::CFontDialog](../Topic/CFontDialog::CFontDialog.md)|Constrói um objeto de `CFontDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFontDialog::DoModal](../Topic/CFontDialog::DoModal.md)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[CFontDialog::GetCharFormat](../Topic/CFontDialog::GetCharFormat.md)|Recupera a formatação de caracteres de fonte selecionada.|  
|[CFontDialog::GetColor](../Topic/CFontDialog::GetColor.md)|Retorna a cor da fonte selecionada.|  
|[CFontDialog::GetCurrentFont](../Topic/CFontDialog::GetCurrentFont.md)|Atribui as características da fonte selecionada na estrutura de `LOGFONT` .|  
|[CFontDialog::GetFaceName](../Topic/CFontDialog::GetFaceName.md)|Retorna o nome da face de fonte selecionada.|  
|[CFontDialog::GetSize](../Topic/CFontDialog::GetSize.md)|Retorna o tamanho do ponto de fonte selecionada.|  
|[CFontDialog::GetStyleName](../Topic/CFontDialog::GetStyleName.md)|Retorna o nome do estilo de fonte selecionada.|  
|[CFontDialog::GetWeight](../Topic/CFontDialog::GetWeight.md)|Retorna o peso de fonte selecionada.|  
|[CFontDialog::IsBold](../Topic/CFontDialog::IsBold.md)|Determina se a fonte é negrito.|  
|[CFontDialog::IsItalic](../Topic/CFontDialog::IsItalic.md)|Determina se a fonte é itálico.|  
|[CFontDialog::IsStrikeOut](../Topic/CFontDialog::IsStrikeOut.md)|Determina se a fonte é exibida com strikeout.|  
|[CFontDialog::IsUnderline](../Topic/CFontDialog::IsUnderline.md)|Determina se a fonte é sublinhada.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFontDialog::m\_cf](../Topic/CFontDialog::m_cf.md)|Uma estrutura usada para personalizar um objeto de `CFontDialog` .|  
  
## Comentários  
 Um objeto de `CFontDialog` é um caixa de diálogo com uma lista de fontes que são instaladas no sistema.  O usuário pode selecionar uma fonte específico na lista, e essa seleção é relatada de volta para o aplicativo.  
  
 Para criar um objeto de `CFontDialog` , usando o construtor fornecido ou derivar uma nova subclasse de e usar seu próprio construtor personalizado.  
  
 Depois que um objeto de `CFontDialog` foi construído, você pode usar a estrutura de `m_cf` para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de [m\_cf](../Topic/CFontDialog::m_cf.md) é do tipo [CHOOSEFONT](http://msdn.microsoft.com/library/windows/desktop/ms646832).  Para obter mais informações sobre essa estrutura, consulte [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Após inicializado os controles do objeto da caixa de diálogo, chame a função de membro de `DoModal` para exibir a caixa de diálogo e para permitir que o usuário selecione uma fonte.  `DoModal` retorna se o usuário tiver selecionado OK \(**IDOK**\) ou o botão cancelar \(**IDCANCEL**\).  
  
 Se `DoModal` retorna **IDOK**, você pode usar uma das funções de membro de `CFontDialog` para recuperar informações de entrada pelo usuário.  
  
 Você pode usar a função de [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) do windows para determinar se um erro ocorrer durante a inicialização da caixa de diálogo e para aprender mais sobre o erro.  Para obter mais informações sobre essa função, consulte [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `CFontDialog` depende do arquivo de COMMDLG.DLL que vem com versões 3,1 e posterior do windows.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CFontDialog`, forneça um modelo personalizado da caixa de diálogo, e adicionar um mapa mensagem\- para processar as notificações dos controles estendidos.  Todas as mensagens não processadas devem ser passada para a classe base.  
  
 Personalizar a função de gancho não é necessário.  
  
 Para obter mais informações sobre como usar `CFontDialog`, consulte [Classes comuns da caixa de diálogo](../../mfc/common-dialog-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 `CFontDialog`  
  
## Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
## Consulte também  
 [O MFC exemplos HIERSVR](../../top/visual-cpp-samples.md)   
 [Classe de CCommonDialog](../Topic/CCommonDialog%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)