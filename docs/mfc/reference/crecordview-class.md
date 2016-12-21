---
title: "Classe de CRecordView | Microsoft Docs"
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
  - "CRecordView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRecordView"
  - "Conjuntos de registros ODBC, exibindo registros"
  - "registros, exibição ODBC"
  - "modos de exibição, ODBC"
ms.assetid: 9b4b0897-bd50-4d48-a0b4-f3323f5ccc55
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRecordView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma exibição que exibe registros do banco de dados dos controles.  
  
## Sintaxe  
  
```  
class AFX_NOVTABLE CRecordView : public CFormView  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRecordView::CRecordView](../Topic/CRecordView::CRecordView.md)|Constrói um objeto de `CRecordView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRecordView::IsOnFirstRecord](../Topic/CRecordView::IsOnFirstRecord.md)|Retorna diferente de zero se o registro atual é o primeiro registro no conjunto de registros associado.|  
|[CRecordView::IsOnLastRecord](../Topic/CRecordView::IsOnLastRecord.md)|Retorna diferente de zero se o registro atual é o último registro no conjunto de registros associado.|  
|[CRecordView::OnGetRecordset](../Topic/CRecordView::OnGetRecordset.md)|Retorna um ponteiro para um objeto de uma classe derivada de `CRecordset`.  ClassWizard substitui essa função para você e criar o conjunto de registros se necessário.|  
|[CRecordView::OnMove](../Topic/CRecordView::OnMove.md)||  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRecordView::OnMove](../Topic/CRecordView::OnMove.md)|Se o registro atual foi alterado, atualizá\-lo na fonte de dados, então move para o registro especificado \(em seguida, anterior, primeiro, último ou\).|  
  
## Comentários  
 Modo é uma exibição do formulário conectado diretamente a um objeto de `CRecordset` .  Modo é criada de um recurso do modelo da caixa de diálogo e exibe os campos do objeto de `CRecordset` nos controles do modelo da caixa de diálogo.  A caixa de diálogo de objeto usa `CRecordView` de troca de dados \(DDX\) e troca do campo do registro \(RFX\) para automatizar o movimento de dados entre os controles no formulário e os campos do conjunto de registros.  `CRecordView` também fornece uma implementação padrão para mover para o primeiro, o próximo registro, ou anterior, o último e uma interface para atualizar o registro atualmente no modo.  
  
> [!NOTE]
>  Se você estiver trabalhando com acesso a dados objetos de classes \(DAO\) em vez das classes Open Database Connectivity \(ODBC\), use a classe [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) em vez de isso.  Para obter mais informações, consulte o artigo [visão geral: Programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 A maneira mais comum para o modo de exibição do registro é com o assistente do aplicativo.  O assistente de aplicativo de Tge cria tanto a classe de visualização do registro e sua classe associado do conjunto de registros como parte do seu aplicativo de esqueleto de iniciantes.  Se você não criar a classe de visualização do registro com o assistente do aplicativo, você pode criá\-lo posteriormente com o ClassWizard.  Se você precisa apenas um único formulário, a abordagem do assistente do aplicativo é mais fácil.  ClassWizard permite que você decidir usar posteriormente uma exibição do registro no processo de desenvolvimento.  Usar ClassWizard separada para criar uma exibição do registro e um conjunto de registros e para conectar\-se então é a abordagem mais flexível porque ela fornece maior controle sobre nomear a classe do conjunto de registros e seu. arquivos de H\/.CPP.  Essa abordagem também permite que você ter vários modos de exibição do registro na mesma classe do conjunto de registros.  
  
 Para tornar mais fácil para que os usuários finais transportem\-se de registro para o registro no modo do registro, o assistente do aplicativo cria recursos de menu \(e opcionalmente a barra de ferramentas\) para o registro mover para o primeiro, seguir, ou anterior, o último.  Se você criar uma classe de visualização do registro com o ClassWizard, você precisa criar esses recursos você mesmo com os editores de menu e de bitmap.  
  
 Para obter informações sobre a implementação padrão para mover do registro ao registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [Usando uma exibição do registro](../../data/using-a-record-view-mfc-data-access.md).  
  
 `CRecordView` mantém registro da posição do usuário no conjunto de registros de modo que a exibição do registro pode atualizar a interface do usuário.  Quando o usuário move para um ou outro final do conjunto de registros, a exibição do registro desativa objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para se mover mais na mesma direção.  
  
 Para obter mais informações sobre como declarar e usar as classes de exibição e do recordset do registro, consulte “criar e criar uma exibição do registro” no artigo [Exibição do registro](../../data/record-views-mfc-data-access.md).  Para obter mais informações sobre como as exibições de registro funcionam e como usá\-los, consulte o artigo [Usando uma exibição do registro](../../data/using-a-record-view-mfc-data-access.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 [CFormView](../../mfc/reference/cformview-class.md)  
  
 `CRecordView`  
  
## Requisitos  
 **Cabeçalho:** afxdb.h  
  
## Consulte também  
 [Classe de CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)   
 [Classe de CFormView](../../mfc/reference/cformview-class.md)