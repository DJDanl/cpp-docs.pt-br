---
title: "OLE DB pool de recursos e serviços | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- resource pooling [OLE DB], provider requirements
- OLE DB, resource pooling
- service providers [OLE DB]
- OLE DB services [OLE DB], provider requirements
- OLE DB services [OLE DB]
- OLE DB providers, resource pooling
ms.assetid: 360c36e2-25ae-4caf-8ee7-d4a6b6898f68
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5d3d9ddba2039c1b4445bdb8d4ee77e9a68d9796
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ole-db-resource-pooling-and-services"></a>Pooling de recursos e serviços de banco de dados OLE
Para funcionar bem com o pool de OLE DB, ou com qualquer serviço do OLE DB, o provedor deve oferecer suporte a agregação de todos os objetos. Este é um requisito de OLE DB 1.5 ou posterior provedor. É essencial que aproveita os serviços. Provedores que não oferecem suporte a agregação não podem ser colocado em pool e sem serviços adicionais são fornecidos.  
  
 Para ser colocado em pool, os provedores devem oferecer suporte a modelo de thread livre. O pool de recursos determina o modelo de thread do provedor de acordo com o **DBPROP_THREADMODEL** propriedade.  
  
 Se o provedor tem um estado de conexão global que pode ser alterado enquanto a fonte de dados está em um estado inicializado, ele deve dar suporte aos novos **DBPROP_RESETDATASOURCE** propriedade. Essa propriedade é chamada antes de uma conexão é reutilizado e o provedor a oportunidade para limpar o estado antes do próximo seu uso. Se o provedor não pode limpar algum estado associado a conexão, ele pode retornar **DBPROPSTATUS_NOTSETTABLE** para a propriedade e a conexão não serão reutilizados.  
  
 Provedores de se conectar a um banco de dados remoto e podem detectar se que a conexão pode ser perdido deve dar suporte a **DBPROP_CONNECTIONSTATUS** propriedade. Esta propriedade fornece serviços de OLE DB a capacidade de detectar conexões inativas e certifique-se de que eles não são retornados ao pool.  
  
 Por fim, a inscrição automática de transação geralmente não funciona, a menos que ele é implementado no mesmo nível que o pool ocorre. Provedores que dão suporte a inscrição automática em transações si devem oferecer suporte a desabilitar esta inscrição expondo o **DBPROP_INIT_OLEDBSERVICES** propriedade e desabilitar inscrição se o **DBPROPVAL_OS_ TXNENLISTMENT** está desmarcada.  
  
## <a name="see-also"></a>Consulte também  
 [Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)