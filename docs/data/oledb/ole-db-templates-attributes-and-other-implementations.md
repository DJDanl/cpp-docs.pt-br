---
title: "Modelos OLE DB, atributos e outras implementações | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB, implementations
- OLE DB templates, about OLE DB templates
- OLE DB templates
ms.assetid: 0c780c1b-9bba-4788-8c33-8552d9f120ac
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: abdf0565db00b13c932366985c315c88d8d29f9e
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ole-db-templates-attributes-and-other-implementations"></a>Modelos de banco de dados OLE, atributos e outras implementações
## <a name="atl-ole-db-templates"></a>Modelos do ATL OLE DB  
 Os modelos OLE DB, que fazem parte da ATL (Active Template Library), verifique a tecnologia de banco de dados do OLE DB de alto desempenho mais fácil de usar, fornecendo as classes que implementam a muitas das interfaces de OLE DB usadas com frequência. Junto com este modelo de biblioteca é fornecido suporte do Assistente para criação de aplicativos de início de OLE DB.  
  
 Essa biblioteca de modelo contém duas partes:  
  
-   **Modelos OLE DB consumidor** usadas para implementar um aplicativo de cliente (consumidor) do OLE DB.  
  
-   **Modelos OLE DB Provider** usadas para implementar um aplicativo de servidor (provedor) do OLE DB.  
  
 Para usar os modelos OLE DB, você deve estar familiarizado com as interfaces OLE DB, COM e modelos do C++. Se você não estiver familiarizado com o OLE DB, consulte [referência do programador de DB OLE](https://msdn.microsoft.com/en-us/library/ms713643.aspx).  
  
 Para obter mais informações, você pode:  
  
-   Leia os tópicos sobre o [OLE DB modelos de consumidor](../../data/oledb/ole-db-consumer-templates-cpp.md) ou [modelos OLE DB Provider](../../data/oledb/ole-db-provider-templates-cpp.md).  
  
-   Criar um [consumidor OLE DB](../../data/oledb/creating-an-ole-db-consumer.md) ou [provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md).  
  
-   Consulte a lista de [classes de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) ou [classes de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-reference.md).  
  
-   Consulte a lista de [exemplos de modelos OLE DB](http://msdn.microsoft.com/en-us/08958863-0b5f-41ad-ae99-fca7440c553c).  
  
-   Consulte [referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx) (no SDK do Windows).  
  
## <a name="ole-db-attributes"></a>Atributos de banco de dados OLE  
 O [atributos de consumidor OLE DB](../../windows/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar os consumidores do OLE DB. Os atributos de OLE DB injetar código com base no [modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) criar provedores e consumidores OLE DB do trabalho. Se você precisa especificar os atributos não oferece suporte para a funcionalidade, você pode usar os modelos OLE DB em conjunto com os atributos no seu código.  
  
## <a name="mfc-ole-db-classes"></a>Classes do MFC OLE DB  
 A biblioteca do MFC tem uma classe, [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), que exibe os registros do banco de dados em controles. A exibição é um modo de exibição de formulário conectado diretamente a um `CRowset` de objeto e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo. Ele também fornece uma implementação padrão para mover para a primeira, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição. Para obter mais informações, consulte `COleDBRecordView`.  
  
## <a name="ole-db-sdk-interfaces"></a>SDK de Interfaces do OLE DB  
 Nos casos onde os modelos OLE DB não dão suporte à funcionalidade de OLE DB, você precisa usar as próprias interfaces do OLE DB. Para obter mais informações, consulte [referência do programador de DB OLE](https://msdn.microsoft.com/en-us/library/ms713643.aspx) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)