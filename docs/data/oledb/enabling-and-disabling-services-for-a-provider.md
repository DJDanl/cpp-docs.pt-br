---
title: Habilitando e desabilitando serviços para um provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 3deac1bb-f660-407a-92ef-95e139e280c0
ms.openlocfilehash: ca621b005dd0bad60c70298e4d49abce6fb8d1d7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665446"
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