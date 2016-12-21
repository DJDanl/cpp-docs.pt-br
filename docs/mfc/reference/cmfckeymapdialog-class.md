---
title: "Classe de CMFCKeyMapDialog | Microsoft Docs"
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
  - "CMFCKeyMapDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCKeyMapDialog"
ms.assetid: 5feb4942-d636-462d-a162-0104dd320f4e
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCKeyMapDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCKeyMapDialog` suporta um controle que mapeia comandos nas chaves no teclado.  
  
## Sintaxe  
  
```  
class CMFCKeyMapDialog : public CDialogEx  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCKeyMapDialog::CMFCKeyMapDialog](../Topic/CMFCKeyMapDialog::CMFCKeyMapDialog.md)|Constrói um objeto de `CMFCKeyMapDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCKeyMapDialog::DoModal](../Topic/CMFCKeyMapDialog::DoModal.md)|Exibe uma caixa de diálogo de mapeamento do teclado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCKeyMapDialog::FormatItem](../Topic/CMFCKeyMapDialog::FormatItem.md)|Chamado pela estrutura para criar uma cadeia de caracteres que descreve um mapeamento principal.  Por padrão, a cadeia de caracteres contém o nome de comando, as teclas de atalho usado, e a descrição de tecla de atalho.|  
|[CMFCKeyMapDialog::GetCommandKeys](../Topic/CMFCKeyMapDialog::GetCommandKeys.md)|Recupera uma cadeia de caracteres que contém uma lista de teclas de atalho associadas ao comando específico.|  
|[CMFCKeyMapDialog::OnInsertItem](../Topic/CMFCKeyMapDialog::OnInsertItem.md)|Chamado pela estrutura antes que um novo item está inserido no controle interno de lista que suporta o controle de mapeamento do teclado.|  
|[CMFCKeyMapDialog::OnPrintHeader](../Topic/CMFCKeyMapDialog::OnPrintHeader.md)|Chamado pela estrutura para imprimir o cabeçalho para o mapeamento do teclado em uma nova página.|  
|[CMFCKeyMapDialog::OnPrintItem](../Topic/CMFCKeyMapDialog::OnPrintItem.md)|Chamado pela estrutura para imprimir um item de mapeamento do teclado.|  
|[CMFCKeyMapDialog::OnSetColumns](../Topic/CMFCKeyMapDialog::OnSetColumns.md)|Chamado pela estrutura para definir legendas para as colunas no controle interno de lista que suporta o controle de mapeamento do teclado.|  
|[CMFCKeyMapDialog::PrintKeyMap](../Topic/CMFCKeyMapDialog::PrintKeyMap.md)|Chamado pela estrutura quando um usuário clica no botão de **Imprimir** .|  
|[CMFCKeyMapDialog::SetColumnsWidth](../Topic/CMFCKeyMapDialog::SetColumnsWidth.md)|Chamado pela estrutura para definir a largura das colunas no controle interno de lista que suporta o controle de mapeamento do teclado.|  
  
## Comentários  
 Use a classe de `CMFCKeyMapDialog` para implementar uma caixa de diálogo redimensionável de mapeamento do teclado.  A caixa de diálogo usa um controle de exibição de lista para exibir atalhos de teclado e seus comandos associados.  
  
 Para usar a classe de `CMFCKeyMapDialog` em um aplicativo, passe em um ponteiro para a janela de quadro chave como um parâmetro para o construtor de `CMFCKeyMapDialog` .  Chame o método de `DoModal` para iniciar uma caixa de diálogo modal.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
 [CMFCKeyMapDialog](../../mfc/reference/cmfckeymapdialog-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxkeymapdialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)