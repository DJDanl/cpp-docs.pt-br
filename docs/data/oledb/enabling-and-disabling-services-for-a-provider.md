---
title: "Habilitando e desabilitando serviços para um provedor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 3deac1bb-f660-407a-92ef-95e139e280c0
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: dc6b3d7cc8e80eaa24c2e2dd9b4e23e79dfb09f9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="enabling-and-disabling-services-for-a-provider"></a>Habilitando e desabilitando serviços para um provedor
Serviços de OLE DB individuais podem ser habilitados ou desabilitados por padrão para todos os aplicativos que acessam um único provedor. Isso é feito adicionando uma **OLEDB_SERVICES** entrada do registro sob o provedor do CLSID, com um `DWORD` valor que especifica os serviços para habilitar ou desabilitar, conforme mostrado na tabela a seguir.  
  
|Serviços padrão habilitados|Valor de palavra-chave|  
|------------------------------|-------------------|  
|Todos os serviços (padrão)|0xFFFFFFFF|  
|Tudo, exceto o pool e AutoEnlistment|0xFFFFFFFE|  
|Tudo, exceto Cursor do cliente|0xfffffffb|  
|Todos exceto pool, AutoEnlistment e o Cursor do cliente|0xfffffff0|  
|Nenhum serviço|0x00000000|  
|Nenhuma agregação, todos os serviços desabilitados|\<chave ausente >|  
  
## <a name="see-also"></a>Consulte também  
 [Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)