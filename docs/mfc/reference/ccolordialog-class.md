---
title: "Classe de CColorDialog | Microsoft Docs"
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
  - "CColorDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CColorDialog"
  - "cores, caixa de diálogo"
  - "caixas de diálogo, cores"
ms.assetid: d013dc25-9290-4b5d-a97e-95ad7208e13b
caps.latest.revision: 25
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CColorDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que você insira uma caixa de diálogo de cor\- seleção em seu aplicativo.  
  
## Sintaxe  
  
```  
class CColorDialog : public CCommonDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CColorDialog::CColorDialog](../Topic/CColorDialog::CColorDialog.md)|Constrói um objeto de `CColorDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CColorDialog::DoModal](../Topic/CColorDialog::DoModal.md)|Exibe uma caixa de diálogo de cor e permite que o usuário faça uma seleção.|  
|[CColorDialog::GetColor](../Topic/CColorDialog::GetColor.md)|Retorna uma estrutura de **COLORREF** que contém os valores de cor selecionada.|  
|[CColorDialog::GetSavedCustomColors](../Topic/CColorDialog::GetSavedCustomColors.md)|Recupera as cores personalizados criados pelo usuário.|  
|[CColorDialog::SetCurrentColor](../Topic/CColorDialog::SetCurrentColor.md)|Força a cor de seleção atual para a cor especificada.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CColorDialog::OnColorOK](../Topic/CColorDialog::OnColorOK.md)|Substituição para validar a cor inserida na caixa de diálogo.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CColorDialog::m\_cc](../Topic/CColorDialog::m_cc.md)|Uma estrutura usada para personalizar as configurações da caixa de diálogo.|  
  
## Comentários  
 Um objeto de `CColorDialog` é um caixa de diálogo com uma lista de cores que são definidas para o sistema de exibição.  O usuário pode selecionar ou criar uma cor específico na lista, que é relatada de volta para o aplicativo quando a caixa de diálogo será encerrado.  
  
 Para criar um objeto de `CColorDialog` , usando o construtor fornecido ou derivar uma nova classe e usar seu próprio construtor personalizado.  
  
 Uma vez que a caixa de diálogo foi construída, você pode definir ou modificar os valores na estrutura de[m\_cc](../Topic/CColorDialog::m_cc.md) para inicializar valores dos controles da caixa de diálogo.  A estrutura de `m_cc` é do tipo [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830).  
  
 Após inicializado os controles da caixa de diálogo, chame a função de membro de `DoModal` para exibir a caixa de diálogo e para permitir que o usuário selecione uma cor.  `DoModal` retorna a seleção do usuário de OK da caixa de diálogo \(**IDOK**\) ou um botão cancelar \(**IDCANCEL**\).  
  
 Se `DoModal` retorna **IDOK**, você pode usar uma das funções de membro de `CColorDialog` para recuperar informações de entrada pelo usuário.  
  
 Você pode usar a função de [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) do windows para determinar se um erro ocorrer durante a inicialização da caixa de diálogo e para aprender mais sobre o erro.  
  
 `CColorDialog` depende do arquivo de COMMDLG.DLL que vem com versões 3,1 e posterior do windows.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CColorDialog`, forneça um modelo personalizado da caixa de diálogo, e adicionar um mapa de mensagens para processar as notificações dos controles estendidos.  Todas as mensagens não processadas devem ser passada para a classe base.  
  
 Personalizar a função de gancho não é necessário.  
  
> [!NOTE]
>  Em algumas instalações o objeto de `CColorDialog` não exibirá com um plano de fundo cinza se você usou a estrutura para fazer o outro cinza de objetos de `CDialog` .  
  
 Para obter mais informações sobre como usar `CColorDialog`, consulte [Classes comuns da caixa de diálogo](../../mfc/common-dialog-classes.md)  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 `CColorDialog`  
  
## Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
## Consulte também  
 [O MFC prova MDI](../../top/visual-cpp-samples.md)   
 [Exemplo DRAWCLI MFC](../../top/visual-cpp-samples.md)   
 [Classe de CCommonDialog](../Topic/CCommonDialog%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)