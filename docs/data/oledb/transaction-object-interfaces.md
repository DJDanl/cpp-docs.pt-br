---
title: "Interfaces de objeto de transação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- interfaces, OLE DB
- transaction object interfaces
- OLE DB, interfaces
- OLE DB providers, transaction support
- OLE DB provider templates, object interfaces
- interfaces, list of
ms.assetid: d2ce99ce-6f7a-4ff9-bc6e-acda3633d5c8
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5731d4d187fa02b0b68c9e4b764bf9aeb1f653dc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="transaction-object-interfaces"></a>Interfaces de objeto da transação
O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como as unidades de trabalho se relacionam entre si. Este objeto não é diretamente suportado por modelos de provedor do OLE DB (ou seja, você deve criar seu próprio objeto).  
  
 A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de transação.  
  
|Interface|Necessário?|Implementado por modelos OLE DB?|  
|---------------|---------------|--------------------------------------|  
|[IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857)|Obrigatório|Não|  
|[ITransaction](https://msdn.microsoft.com/en-us/library/ms723053.aspx)|Obrigatório|Não|  
|[ISupportErrorInfo](https://msdn.microsoft.com/en-us/library/ms715816.aspx)|Opcional|Não|  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)