---
title: "Classe de CDragListBox | Microsoft Docs"
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
  - "CDragListBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDragListBox"
  - "caixa de listagem de arrastar [C++]"
  - "arrastando itens da lista"
  - "caixas de listagem"
  - "Windows [C++], caixas de listagem"
ms.assetid: fee20b42-60ae-4aa9-83f9-5a3d9b96e33b
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDragListBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Além de fornecer a funcionalidade de uma caixa de lista do windows, a classe de `CDragListBox` permite que o usuário mova itens da caixa de listagem, como nomes de arquivo, na caixa de listagem.  
  
## Sintaxe  
  
```  
class CDragListBox : public CListBox  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDragListBox::CDragListBox](../Topic/CDragListBox::CDragListBox.md)|Constrói um objeto de `CDragListBox` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDragListBox::BeginDrag](../Topic/CDragListBox::BeginDrag.md)|Chamado pela estrutura quando iniciar uma operação de arrastar.|  
|[CDragListBox::CancelDrag](../Topic/CDragListBox::CancelDrag.md)|Chamado pela estrutura quando uma operação de arrasto é cancelada.|  
|[CDragListBox::Dragging](../Topic/CDragListBox::Dragging.md)|Chamado pela estrutura durante uma operação de arrastar.|  
|[CDragListBox::DrawInsert](../Topic/CDragListBox::DrawInsert.md)|Desenha inserção da guia da caixa de listagem de arrastar.|  
|[CDragListBox::Dropped](../Topic/CDragListBox::Dropped.md)|Chamado pela estrutura depois que o item foi solto.|  
|[CDragListBox::ItemFromPt](../Topic/CDragListBox::ItemFromPt.md)|Retorna as coordenadas do item que está sendo arrastado.|  
  
## Comentários  
 As caixas de listagem com esse recurso permite que os usuários ordenem os itens em uma lista no modo que é útil para ele.  Por padrão, a caixa de listagem moverá o item para o novo local na lista.  Em o entanto, objetos de `CDragListBox` podem ser personalizados para copiar itens em vez de movê\-los.  
  
 O controle de caixa de listagem associado com a classe de `CDragListBox` não deve ter **LBS\_SORT** ou o estilo de **LBS\_MULTIPLESELECT** .  Para obter uma descrição de estilos da caixa de listagem, consulte [Estilos da caixa de listagem](../../mfc/reference/list-box-styles.md).  
  
 Para usar uma caixa de listagem de arrastar em uma caixa de diálogo existente do aplicativo, adicione um controle de caixa de listagem ao modelo da caixa de diálogo usando o editor de diálogo e depois atribua a um membro \(de categoria `Control` e tipo de variável `CDragListBox`\) corresponder a variável para o controle de caixa de listagem no seu modelo da caixa de diálogo.  
  
 Para obter mais informações sobre controles de atribuição a variáveis de membro, consulte [Atalho para definir variáveis de membro para controles de caixa de diálogo](../../mfc/defining-member-variables-for-dialog-controls.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CListBox](../Topic/CListBox%20Class.md)  
  
 `CDragListBox`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [Exemplo TSTCON MFC](../../top/visual-cpp-samples.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)