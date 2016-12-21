---
title: "Classe de COleDBRecordView | Microsoft Docs"
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
  - "COleDBRecordView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleDBRecordView"
  - "MFC, OLE DB"
ms.assetid: 98612427-c4c9-4760-b7e1-85b17448add9
caps.latest.revision: 20
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDBRecordView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma exibição que exibe registros do banco de dados dos controles.  
  
## Sintaxe  
  
```  
class COleDBRecordView : public CFormView  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDBRecordView::COleDBRecordView](../Topic/COleDBRecordView::COleDBRecordView.md)|Constrói um objeto de `COleDBRecordView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDBRecordView::OnGetRowset](../Topic/COleDBRecordView::OnGetRowset.md)|Retorna um valor padrão de `HRESULT` .|  
|[COleDBRecordView::OnMove](../Topic/COleDBRecordView::OnMove.md)|Atualizar o registro atual \(se sujo\) na fonte de dados e move para o registro especificado \(em seguida, anterior, primeiro, último ou\).|  
  
## Comentários  
 Modo é uma exibição do formulário conectado diretamente a um objeto de `CRowset` .  Modo é criada de um recurso do modelo da caixa de diálogo e exibe os campos do objeto de `CRowset` nos controles do modelo da caixa de diálogo.  O objeto de `COleDBRecordView` usar a caixa de diálogo de troca de dados \(DDX\), e a funcionalidade de navegação compilada em `CRowset`, para automatizar o movimento de dados entre os controles no formulário e campos de rowset.  `COleDBRecordView` também fornece uma implementação padrão para mover para o primeiro, o próximo registro, ou anterior, o último e uma interface para atualizar o registro atualmente no modo.  
  
 Você pode usar funções de DDX com **COleDbRecordView** para obter dados diretamente do conjunto de registros do banco de dados e exibi\-los em um controle caixa de diálogo.  Você deve usar os métodos de **DDX\_\*** \(como `DDX_Text`\), não as funções de **DDX\_Field\*** \(como `DDX_FieldText`\) com **COleDbRecordView**.  `DDX_FieldText` não funcionará com **COleDbRecordView** porque `DDX_FieldText` usa um argumento adicional do tipo **CRecordset\*** \(para `CRecordView`\) ou **CDaoRecordset\*** \(para `CDaoRecordView`\).  
  
> [!NOTE]
>  Se você estiver trabalhando com acesso a dados objetos de classes \(DAO\) em vez de classes do modelo do consumidor do OLE DB, use a classe [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) em vez de isso.  Para obter mais informações, consulte o artigo [visão geral: Programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 `COleDBRecordView` mantém registro da posição do usuário no rowset de modo que a exibição do registro pode atualizar a interface do usuário.  Quando o usuário move para qualquer uma das extremidades de rowset, a exibição do registro desativa objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para se mover mais na mesma direção.  
  
 Para obter mais informações sobre as classes de rowset, consulte o artigo de [Usando modelos do consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 [CFormView](../../mfc/reference/cformview-class.md)  
  
 `COleDBRecordView`  
  
## Requisitos  
 **Cabeçalho:** afxoledb.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)