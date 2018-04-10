---
title: Classes de banco de dados ATL (modelos OLE DB) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- OLE DB templates [C++], ATL database classes
- database classes [C++], OLE DB
- database classes [C++], ATL
ms.assetid: 219766aa-e18a-405f-9e36-d7a0fdb31b2b
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ca7607c037cdb1f6a42a2267d64ef274d1041cb2
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="atl-database-classes-ole-db-templates"></a>Classes de banco de dados ATL (modelos de banco de dados OLE)
A Microsoft fornece várias implementações de OLE DB, um conjunto de interfaces que fornecem acesso uniforme a dados em informações de várias fontes e formatos.  OLE DB foi oficialmente preterido; Esta documentação é para desenvolvedores que estão mantendo o código herdado. Novos aplicativos devem usar o ODBC para se conectar a fontes de dados do SQL.
  
 Os modelos OLE DB são modelos de C++ em ATL que facilitam o uso, fornecendo as classes que implementam a muitas das interfaces de OLE DB usadas de tecnologia de banco de dados OLE DB.  
  
 Essa biblioteca de modelo contém duas partes:  
  
-   [Modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-cpp.md) usadas para implementar um aplicativo de cliente (consumidor) do OLE DB.  
  
-   [Modelos de provedor do OLE DB](../data/oledb/ole-db-provider-templates-cpp.md) usadas para implementar um aplicativo de servidor (provedor) do OLE DB.  
  
 Além disso, o [atributos de consumidor OLE DB](../windows/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar os consumidores do OLE DB. Os atributos de OLE DB injetar código com base nos modelos de consumidor OLE DB para criar os consumidores OLE DB do trabalho.  
  
 Observe que a biblioteca do MFC contém uma classe, [COleDBRecordView](../mfc/reference/coledbrecordview-class.md), que exibe os registros do banco de dados em controles. A exibição é um modo de exibição de formulário conectado diretamente a um `CRowset` objeto e, em seguida, exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo.  
  
 Para obter mais informações, consulte [OLE DB de programação](../data/oledb/ole-db-programming.md) e [guia do programador do DB OLE](http://go.microsoft.com/fwlink/p/?linkid=121548).  
  
## <a name="see-also"></a>Consulte também  
 [Criando um consumidor do OLE DB](../data/oledb/creating-an-ole-db-consumer.md)   
 [Criando um provedor do OLE DB](../data/oledb/creating-an-ole-db-provider.md)   
 [Referência de modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-reference.md)   
 [Referência de modelos de provedor do OLE DB](../data/oledb/ole-db-provider-templates-reference.md)   
 [Exemplos de modelos OLE DB](http://msdn.microsoft.com/en-us/08958863-0b5f-41ad-ae99-fca7440c553c)