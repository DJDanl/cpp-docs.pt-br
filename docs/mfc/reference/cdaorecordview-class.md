---
title: "Classe de CDaoRecordView | Microsoft Docs"
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
  - "CDaoRecordView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assistentes do aplicativo [C++], criando exibição do registro"
  - "controles associados [C++], exibindo dados do banco de dados"
  - "Classe de CDaoRecordView"
  - "controles [MFC], associação de dados"
  - "associação de dados [C++], Modos de DAO"
  - "controles associados a dados [C++], controles DAO"
ms.assetid: 5aa7d0e2-bd05-413e-b216-80c404ce18ac
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoRecordView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma exibição que exibe registros do banco de dados dos controles.  
  
## Sintaxe  
  
```  
  
class AFX_NOVTABLE CDaoRecordView : public CFormView  
  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoRecordView::CDaoRecordView](../Topic/CDaoRecordView::CDaoRecordView.md)|Constrói um objeto de `CDaoRecordView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoRecordView::IsOnFirstRecord](../Topic/CDaoRecordView::IsOnFirstRecord.md)|Retorna diferente de zero se o registro atual é o primeiro registro no conjunto de registros associado.|  
|[CDaoRecordView::IsOnLastRecord](../Topic/CDaoRecordView::IsOnLastRecord.md)|Retorna diferente de zero se o registro atual é o último registro no conjunto de registros associado.|  
|[CDaoRecordView::OnGetRecordset](../Topic/CDaoRecordView::OnGetRecordset.md)|Retorna um ponteiro para um objeto de uma classe derivada de `CDaoRecordset`.  ClassWizard substitui essa função para você e criar o conjunto de registros se necessário.|  
|[CDaoRecordView::OnMove](../Topic/CDaoRecordView::OnMove.md)|Se o registro atual foi alterado, atualizá\-lo na fonte de dados, então move para o registro especificado \(em seguida, anterior, primeiro, último ou\).|  
  
## Comentários  
 Modo é uma exibição do formulário conectado diretamente a um objeto de `CDaoRecordset` .  Modo é criada de um recurso do modelo da caixa de diálogo e exibe os campos do objeto de `CDaoRecordset` nos controles do modelo da caixa de diálogo.  A caixa de diálogo de objeto usa `CDaoRecordView` de troca de dados \(DDX\) e de registro de DAO troca do campo \(DFX\) para automatizar o movimento de dados entre os controles no formulário e os campos do conjunto de registros.  `CDaoRecordView` também fornece uma implementação padrão para mover para o primeiro, o próximo registro, ou anterior, o último e uma interface para atualizar o registro atualmente no modo.  
  
> [!NOTE]
>  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  Você ainda pode acessar fontes de dados ODBC com as classes de DAO; as classes de DAO geralmente oferecem recursos superiores porque usam o mecanismo de banco de dados Microsoft Jet.  
  
 A maneira mais comum para o modo de exibição do registro é com o assistente do aplicativo.  O assistente do aplicativo cria tanto a classe de visualização do registro e sua classe associado do conjunto de registros como parte do seu aplicativo de esqueleto de iniciantes.  
  
 Se você precisa apenas um único formulário, a abordagem do assistente do aplicativo é mais fácil.  ClassWizard permite que você decidir usar posteriormente uma exibição do registro no processo de desenvolvimento.  Se você não criar a classe de visualização do registro com o assistente do aplicativo, você pode criá\-lo posteriormente com o ClassWizard.  Usar ClassWizard separada para criar uma exibição do registro e um conjunto de registros e para conectar\-se então é a abordagem mais flexível porque ela fornece maior controle sobre nomear a classe do conjunto de registros e seu. arquivos de H\/.CPP.  Essa abordagem também permite que você ter vários modos de exibição do registro na mesma classe do conjunto de registros.  
  
 Para tornar mais fácil para que os usuários finais transportem\-se de registro para o registro no modo do registro, o assistente do aplicativo cria recursos de menu \(e opcionalmente a barra de ferramentas\) para o registro mover para o primeiro, seguir, ou anterior, o último.  Se você criar uma classe de visualização do registro com o ClassWizard, você precisa criar esses recursos você mesmo com os editores de menu e de bitmap.  
  
 Para obter informações sobre a implementação padrão para mover do registro ao registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [Usando uma exibição do registro](../../data/using-a-record-view-mfc-data-access.md), que se aplica a `CRecordView` e a `CDaoRecordView`.  
  
 `CDaoRecordView` mantém registro da posição do usuário no conjunto de registros de modo que a exibição do registro pode atualizar a interface do usuário.  Quando o usuário move para um ou outro final do conjunto de registros, a exibição do registro desativa objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para se mover mais na mesma direção.  
  
 Para obter mais informações sobre como declarar e usar as classes de exibição e do recordset do registro, consulte “criar e criar uma exibição do registro” no artigo [Exibição do registro](../../data/record-views-mfc-data-access.md).  Para obter mais informações sobre como as exibições de registro funcionam e como usá\-los, consulte o artigo [Usando uma exibição do registro](../../data/using-a-record-view-mfc-data-access.md).  Todos os artigos mencionados acima se aplicam a `CRecordView` e a `CDaoRecordView`.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 [CFormView](../../mfc/reference/cformview-class.md)  
  
 `CDaoRecordView`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe de CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe de CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe de CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe de CFormView](../../mfc/reference/cformview-class.md)