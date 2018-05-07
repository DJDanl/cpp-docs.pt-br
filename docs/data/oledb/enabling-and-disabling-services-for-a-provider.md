---
title: Habilitando e desabilitando serviços para um provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 3deac1bb-f660-407a-92ef-95e139e280c0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ef36e35234aa4878e30e70748a5b2ba2975c38dc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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