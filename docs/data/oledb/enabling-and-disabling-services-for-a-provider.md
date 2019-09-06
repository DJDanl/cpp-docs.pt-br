---
title: Habilitando e desabilitando serviços para um provedor
ms.date: 07/30/2019
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 3deac1bb-f660-407a-92ef-95e139e280c0
ms.openlocfilehash: a74f8a8b099a30cf25007547e8059c77728435f9
ms.sourcegitcommit: 725e86dabe2901175ecc63261c3bf05802dddff4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2019
ms.locfileid: "70311700"
---
# <a name="enabling-and-disabling-services-for-a-provider"></a>Habilitando e desabilitando serviços para um provedor

Os serviços individuais de OLE DB podem ser habilitados ou desabilitados por padrão para todos os aplicativos que acessam um único provedor. Isso é feito adicionando uma entrada de registro OLEDB_SERVICES sob o CLSID do provedor, com um valor DWORD especificando os serviços a serem habilitados ou desabilitados, conforme mostrado na tabela a seguir.

|Serviços padrão habilitados|Valor DWORD|
|------------------------------|-------------------|
|Todos os serviços, exceto o cursor do cliente e o pooling|0xfffffffa|
|Todos os serviços, exceto o cursor do cliente|0xfffffffb|
|Todos os serviços, exceto pooling e inscrição automática|0xfffffffc|
|Todos os serviços, exceto pooling|0xfffffffe|
|Todos os serviços (padrão)|0xFFFFFFFF|
|Nenhum serviço|0x00000000|
|Sem agregação, todos os serviços desabilitados|Nenhuma entrada de registro OLEDB_Services|

## <a name="see-also"></a>Consulte também

[Habilitando e desabilitando serviços do OLE DB](../../data/oledb/enabling-and-disabling-ole-db-services.md)
