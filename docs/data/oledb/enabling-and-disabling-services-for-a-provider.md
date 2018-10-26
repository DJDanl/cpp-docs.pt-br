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
ms.openlocfilehash: c9b255e715a635494e3acc34124871e90ceca8f7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055366"
---
# <a name="enabling-and-disabling-services-for-a-provider"></a>Habilitando e desabilitando serviços para um provedor

Serviços de OLE DB individuais podem ser habilitados ou desabilitados por padrão para todos os aplicativos que acessam um único provedor. Isso é feito adicionando uma entrada de registro OLEDB_SERVICES sob o CLSID do provedor, com um `DWORD` valor que especifica os serviços para habilitar ou desabilitar, conforme mostrado na tabela a seguir.

|Serviços padrão habilitados|Valor de palavra-chave|
|------------------------------|-------------------|
|Todos os serviços (padrão)|0xFFFFFFFF|
|Todos, exceto de Pooling e AutoEnlistment|0xFFFFFFFE|
|Todos, exceto o Cursor do cliente|0xfffffffb|
|Todos exceto Pooling, AutoEnlistment e Cursor do cliente|0xfffffff0|
|Não há serviços|0x00000000|
|Nenhuma agregação, todos os serviços desabilitados|\<chave ausente >|

## <a name="see-also"></a>Consulte também

[Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)