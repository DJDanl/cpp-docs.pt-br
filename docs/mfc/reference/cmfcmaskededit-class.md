---
title: "Classe de CMFCMaskedEdit | Microsoft Docs"
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
  - "CMFCMaskedEdit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCMaskedEdit"
  - "Construtor de CMFCMaskedEdit"
ms.assetid: 13b1a645-2d5d-4c37-8599-16d5003f23a5
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCMaskedEdit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCMaskedEdit` suporta um controle de edição mascarado, que valide a entrada do usuário contra uma máscara e exibe os resultados validados de acordo com um modelo.  
  
## Sintaxe  
  
```  
class CMFCMaskedEdit : public CEdit  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCMaskedEdit::CMFCMaskedEdit`|Construtor padrão.|  
|`CMFCMaskedEdit::~CMFCMaskedEdit`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCMaskedEdit::DisableMask](../Topic/CMFCMaskedEdit::DisableMask.md)|Desativa verificação que validam a entrada do usuário.|  
|[CMFCMaskedEdit::EnableGetMaskedCharsOnly](../Topic/CMFCMaskedEdit::EnableGetMaskedCharsOnly.md)|Especifica se o método de `GetWindowText` retorna apenas caracteres mascarados.|  
|[CMFCMaskedEdit::EnableMask](../Topic/CMFCMaskedEdit::EnableMask.md)|Inicializa o controle de edição mascarado.|  
|[CMFCMaskedEdit::EnableSelectByGroup](../Topic/CMFCMaskedEdit::EnableSelectByGroup.md)|Especifica se o controle de edição mascarado seleciona grupos específicos de entrada do usuário, ou qualquer entrada do usuário.|  
|[CMFCMaskedEdit::EnableSetMaskedCharsOnly](../Topic/CMFCMaskedEdit::EnableSetMaskedCharsOnly.md)|Especifica se o texto é validado contra apenas caracteres mascarados, ou com a máscara inteira.|  
|`CMFCMaskedEdit::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCMaskedEdit::GetWindowText](../Topic/CMFCMaskedEdit::GetWindowText.md)|Retrieves validou o texto do controle de edição mascarado.|  
|[CMFCMaskedEdit::SetValidChars](../Topic/CMFCMaskedEdit::SetValidChars.md)|Especifica uma cadeia de caracteres de caracteres válidos que o usuário pode inserir.|  
|[CMFCMaskedEdit::SetWindowText](../Topic/CMFCMaskedEdit::SetWindowText.md)|Exibe um aviso o controle de edição mascarado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCMaskedEdit::IsMaskedChar](../Topic/CMFCMaskedEdit::IsMaskedChar.md)|Chamado pela estrutura para validar o caractere especificado com o caractere correspondente da máscara.|  
  
## Comentários  
 Execute as seguintes etapas para usar o controle de `CMFCMaskedEdit` em seu aplicativo:  
  
 1.  Inserir um objeto de `CMFCMaskedEdit` em sua classe de janela.  
  
 2.  Chame o método de [CMFCMaskedEdit::EnableMask](../Topic/CMFCMaskedEdit::EnableMask.md) para especificar a máscara.  
  
 3.  Chame o método de [CMFCMaskedEdit::SetValidChars](../Topic/CMFCMaskedEdit::SetValidChars.md) para especificar a lista de caracteres válidos.  
  
 4.  Chame o método de [CMFCMaskedEdit::SetWindowText](../Topic/CMFCMaskedEdit::SetWindowText.md) para especificar o texto padrão para o controle de edição mascarado.  
  
 5.  Chame o método de [CMFCMaskedEdit::GetWindowText](../Topic/CMFCMaskedEdit::GetWindowText.md) para recuperar o texto validado.  
  
 Se você não chama um ou mais métodos para inicializar a máscara, caracteres válidos, e o texto padrão, o controle de edição mascarado se comporta exatamente como o controle de edição padrão se comporta.  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar uma máscara \(por exemplo um número de telefone\) usando o método de `EnableMask` para criar a máscara para o controle de edição mascarado, o método de `SetValidChars` para especificar uma cadeia de caracteres de caracteres válidos que o usuário pode inserir, e o método de `SetWindowText` exibe um aviso o controle de edição mascarado.  Este exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#11](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#11)]  
[!CODE [NVC_MFC_NewControls#12](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#12)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CEdit](../Topic/CEdit%20Class.md)  
  
 [CMFCMaskedEdit](../../mfc/reference/cmfcmaskededit-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxmaskededit.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CEdit](../Topic/CEdit%20Class.md)