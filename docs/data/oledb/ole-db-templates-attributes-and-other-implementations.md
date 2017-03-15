---
title: "Modelos de banco de dados OLE, atributos e outras implementa&#231;&#245;es | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Modelos OLE DB"
  - "Modelos OLE DB, sobre modelos OLE DB"
  - "OLE DB, implementações"
ms.assetid: 0c780c1b-9bba-4788-8c33-8552d9f120ac
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de banco de dados OLE, atributos e outras implementa&#231;&#245;es
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Modelos de ATL OLE DB  
 Os modelos OLE DB, que são parte de ATL \(biblioteca ativa do modelo\), facilitam a tecnologia da base de dados de alto desempenho OLE DB fornecendo usar as classes que implementam muitas das interfaces de uso geral do OLE DB.  Com este modelo a biblioteca aparece suporte do assistente para criar aplicativos do acionador de partida do OLE DB.  
  
 Essa biblioteca do modelo contém duas partes:  
  
-   **OLE DB Consumer Templates** usado para implementar um aplicativo cliente OLE DB \(consumidor\).  
  
-   **OLE DB Provider Templates** usado para implementar um aplicativo de servidor de provedor OLE DB \(\).  
  
 Para usar os modelos OLE DB, você deve estar familiarizado com os modelos C\+\+, no, e interfaces OLE DB.  Se você não estiver familiarizado com OLE DB, consulte [A referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx).  
  
 Para obter mais informações, você pode:  
  
-   Leia os tópicos sobre [Modelos do consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md) ou [Modelos do provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md).  
  
-   Crie [Consumidor OLE DB](../../data/oledb/creating-an-ole-db-consumer.md) ou [Provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md).  
  
-   Consulte a lista de [Classes do consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) ou de [Classes de provedor OLE DB](../../data/oledb/ole-db-provider-templates-reference.md).  
  
-   Consulte a lista de [Exemplos de modelos OLE DB](http://msdn.microsoft.com/pt-br/08958863-0b5f-41ad-ae99-fca7440c553c).  
  
-   Consulte [A referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx) \(em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)]\).  
  
## Atributos de OLE DB  
 [Atributos do consumidor OLE DB](../../windows/ole-db-consumer-attributes.md) fornece um modo conveniente de criar consumidores de OLE DB.  Os atributos de OLE DB injetam o código baseado em [Modelos do consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) para testar consumidores e provedores OLE DB.  Se você precisa especificar a funcionalidade não tem suporte pelos atributos, você pode usar os modelos OLE DB em conjunto com atributos em seu código.  
  
## Classes de MFC OLE DB  
 A biblioteca MFC tem uma classe, [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), que exibe registros de base de dados dos controles.  A exibição é uma exibição de formulário conectada diretamente a um objeto de `CRowset` e exibe os campos de objeto de `CRowset` nos controles de modelo da caixa de diálogo.  Também fornece uma implementação padrão para se mover para o primeiro, o próximo registro, anterior, ou o último e uma interface para atualizar o registro atualmente na exibição.  Para obter mais informações, consulte `COleDBRecordView`.  
  
## Interfaces OLE DB SDK  
 Em casos em que os modelos OLE DB não dão suporte à funcionalidade do OLE DB, você precisa usar OLE DB disponibiliza interface.  Para obter mais informações, consulte [A referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx) em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)].  
  
## Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação de banco de dados OLE](../../data/oledb/ole-db-programming-overview.md)