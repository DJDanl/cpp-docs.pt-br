---
title: "Classes de banco de dados ATL (modelos de banco de dados OLE) | Microsoft Docs"
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
  - "classes de banco de dados [C++], ATL"
  - "classes de banco de dados [C++], OLE DB"
  - "Modelos OLE DB [C++], classes de banco de dados ATL"
ms.assetid: 219766aa-e18a-405f-9e36-d7a0fdb31b2b
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de banco de dados ATL (modelos de banco de dados OLE)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Microsoft fornece várias implementações do OLE DB, um conjunto de interfaces COM que fornecem acesso a dados uniforme em fontes e em vários formatos de informações.  
  
 Os modelos OLE DB são modelos C\+\+ em ATL que facilitam a tecnologia da base de dados de alto desempenho OLE DB usar fornecendo as classes que implementam muitas das interfaces de uso geral do OLE DB.  
  
 Essa biblioteca do modelo contém duas partes:  
  
-   [Modelos do consumidor OLE DB](../data/oledb/ole-db-consumer-templates-cpp.md) usado para implementar um aplicativo cliente OLE DB \(consumidor\).  
  
-   [Modelos do provedor OLE DB](../data/oledb/ole-db-provider-templates-cpp.md) usado para implementar um aplicativo de servidor de provedor OLE DB \(\).  
  
 Além disso, [Atributos do consumidor OLE DB](../windows/ole-db-consumer-attributes.md) fornece um modo conveniente de criar consumidores de OLE DB.  Os atributos de OLE DB injetam o código baseado em modelos do consumidor OLE DB para testar consumidores de OLE DB.  
  
 Observe que a biblioteca MFC contém uma classe, [COleDBRecordView](../mfc/reference/coledbrecordview-class.md), que exibe registros de base de dados dos controles.  A exibição é uma exibição de formulário conectada diretamente a um objeto de `CRowset` , e exibe os campos de objeto de `CRowset` nos controles de modelo da caixa de diálogo.  
  
 Para obter mais informações, consulte [Programação de OLE DB](../data/oledb/ole-db-programming.md) e [Guia de O programador de OLE DB](http://go.microsoft.com/fwlink/?LinkId=121548).  
  
## Consulte também  
 [Criando um consumidor de banco de dados OLE](../data/oledb/creating-an-ole-db-consumer.md)   
 [Criando um provedor de banco de dados OLE](../data/oledb/creating-an-ole-db-provider.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../data/oledb/ole-db-consumer-templates-reference.md)   
 [Referência dos modelos de provedor de banco de dados OLE](../data/oledb/ole-db-provider-templates-reference.md)   
 [OLE DB Templates Samples](http://msdn.microsoft.com/pt-br/08958863-0b5f-41ad-ae99-fca7440c553c)