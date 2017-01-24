---
title: "Classe de CSimpleDialog | Microsoft Docs"
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
  - "ATL::CSimpleDialog"
  - "CSimpleDialgo"
  - "CSimpleDialog"
  - "ATL.CSimpleDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleDialog"
  - "Classe de CSimpleDialog, caixas de diálogo modais em ATL"
  - "caixas de diálogo, modal"
  - "caixas de diálogo modais, ATL"
ms.assetid: 2ae65cc9-4f32-4168-aecd-200b4a480fdf
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa uma caixa de diálogo modal básica.  
  
## Sintaxe  
  
```  
  
      template <  
   WORD t_wDlgTemplateID,  
   BOOL t_bCenter = TRUE  
>  
class CSimpleDialog :  
   public CDialogImplBase  
```  
  
#### Parâmetros  
 *t\_wDlgTemplateID*  
  
 A identificação de recurso de recursos do modelo da caixa de diálogo.  
  
 *t\_bCenter*  
 **Verdadeiro** se o objeto da caixa de diálogo deve ser centralizado na janela do proprietário; se não **Falso**.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleDialog::DoModal](../Topic/CSimpleDialog::DoModal.md)|Cria uma caixa de diálogo modal.|  
  
## Comentários  
 Implementa uma caixa de diálogo modal com funcionalidade básica.  `CSimpleDialog` fornece suporte para controles comuns do windows somente.  Para criar e exibir um caixa de diálogo modal, crie uma instância da classe, fornecendo o nome de um modelo existente de recursos para a caixa de diálogo.  O objeto da caixa de diálogo fecha quando o usuário clica em qualquer controle com um valor predefinido \(como IDOK ou IDCANCEL\).  
  
 `CSimpleDialog` permite que você crie apenas caixas de diálogo modais.  `CSimpleDialog` fornece o procedimento da caixa de diálogo, que usa o mapeamento padrão de mensagem para direcionar mensagens para manipuladores apropriadas.  
  
 Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para mais informações.  
  
## Hierarquia de herança  
 `CDialogImplBase`  
  
 `CSimpleDialog`  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)