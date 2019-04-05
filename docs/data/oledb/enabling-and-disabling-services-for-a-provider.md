---
title: Habilitando e desabilitando serviços para um provedor
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB services [OLE DB], enabling and disabling
- service providers [OLE DB]
ms.assetid: 3deac1bb-f660-407a-92ef-95e139e280c0
ms.openlocfilehash: d91f08accf1a8be69f63d6bbcaa4c620d68c1077
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033025"
---
# <a name="enabling-and-disabling-services-for-a-provider"></a>Habilitando e desabilitando serviços para um provedor

Serviços de OLE DB individuais podem ser habilitados ou desabilitados por padrão para todos os aplicativos que acessam um único provedor. Isso é feito adicionando uma entrada de registro OLEDB_SERVICES sob o CLSID do provedor, com um valor DWORD que especifica os serviços para habilitar ou desabilitar, conforme mostrado na tabela a seguir.

|Serviços padrão habilitados|Valor de palavra-chave|
|------------------------------|-------------------|
|Todos os serviços (padrão)|0xffffffff|
|Todos, exceto de Pooling e AutoEnlistment|0xfffffffe|
|Todos, exceto o Cursor do cliente|0xfffffffb|
|Todos exceto Pooling, AutoEnlistment e Cursor do cliente|0xfffffff0|
|Não há serviços|0x00000000|
|Nenhuma agregação, todos os serviços desabilitados|\<chave ausente >|

## <a name="see-also"></a>Consulte também

[Habilitando e desabilitando serviços de banco de dados OLE](../../data/oledb/enabling-and-disabling-ole-db-services.md)