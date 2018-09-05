---
title: Modelos OLE DB, atributos e outras implementações | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB, implementations
- OLE DB templates, about OLE DB templates
- OLE DB templates
ms.assetid: 0c780c1b-9bba-4788-8c33-8552d9f120ac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7338f513754722bc00a96f5ee71cce06591f031d
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43685984"
---
# <a name="ole-db-templates-attributes-and-other-implementations"></a>Modelos de banco de dados OLE, atributos e outras implementações
## <a name="atl-ole-db-templates"></a>Modelos do ATL OLE DB  
 Os modelos OLE DB, que fazem parte da ATL (Active Template Library), verifique a tecnologia de banco de dados do OLE DB de alto desempenho mais fáceis de usar, fornecendo classes que implementam muitas das interfaces do OLE DB comumente usadas. Juntamente com esse modelo de biblioteca é fornecido suporte do Assistente para criação de aplicativos de início do OLE DB.  
  
 Essa biblioteca de modelo contém duas partes:  
  
-   **OLE DB modelos de consumidor** usado para implementar um aplicativo de cliente (consumidor) do OLE DB.  
  
-   **Modelos OLE DB Provider** usado para implementar um aplicativo de servidor (provedor) do OLE DB.  
  
 Para usar os modelos OLE DB, você deve estar familiarizado com modelos de C++, COM e as interfaces do OLE DB. Se você não estiver familiarizado com o OLE DB, consulte [referência do programador DB OLE](/previous-versions/windows/desktop/ms713643\(v=vs.85\)).  
  
 Para obter mais informações, você pode:  
  
-   Leia os tópicos sobre o [OLE DB modelos de consumidor](../../data/oledb/ole-db-consumer-templates-cpp.md) ou [modelos OLE DB Provider](../../data/oledb/ole-db-provider-templates-cpp.md).  
  
-   Criar uma [consumidor OLE DB](../../data/oledb/creating-an-ole-db-consumer.md) ou [provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md).  
  
-   Consulte a lista de [classes de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) ou [classes de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-reference.md).  
  
-   Consulte a lista de [exemplos de modelos OLE DB](https://github.com/Microsoft/VCSamples).  
  
-   Ver [referência do programador do OLE DB](/previous-versions/windows/desktop/ms713643\(v=vs.85\)) (no Windows SDK).  
  
## <a name="ole-db-attributes"></a>Atributos do OLE DB  
 O [atributos de consumidor do OLE DB](../../windows/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar os consumidores do OLE DB. Os atributos de OLE DB injetam código com base nas [modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) criar provedores e os consumidores OLE DB do trabalho. Se você precisar especificar funcionalidade sem suporte pelos atributos, você pode usar os modelos OLE DB em conjunto com os atributos em seu código.  
  
## <a name="mfc-ole-db-classes"></a>Classes do MFC OLE DB  
 A biblioteca do MFC tem uma classe, [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), que exibe os registros do banco de dados em controles. A exibição é um modo de exibição de formulário conectado diretamente a um `CRowset` do objeto e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo. Ele também fornece uma implementação padrão para a movimentação para o primeiro, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição. Para obter mais informações, consulte `COleDBRecordView`.  
  
## <a name="ole-db-sdk-interfaces"></a>SDK de Interfaces do OLE DB  
 Nos casos onde os modelos OLE DB não dão suporte à funcionalidade OLE DB, você precisará usar as interfaces do OLE DB em si. Para obter mais informações, consulte [referência do programador DB OLE](/previous-versions/windows/desktop/ms713643\(v=vs.85\)) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Programação OLE DB](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)