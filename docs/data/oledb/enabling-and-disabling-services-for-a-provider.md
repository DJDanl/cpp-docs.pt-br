---
title: "Habilitando e desabilitando servi&#231;os para um provedor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Serviços OLE DB [OLE DB], habilitando e desabilitando"
  - "provedores de serviço [OLE DB]"
ms.assetid: 3deac1bb-f660-407a-92ef-95e139e280c0
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Habilitando e desabilitando servi&#231;os para um provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os serviços individuais OLE DB podem ser habilitados ou desabilitados por padrão para todos os aplicativos que acessam um único provedor.  Isso é feito adicionando uma entrada de Registro de **OLEDB\_SERVICES** em CLSID do provedor, com um valor de `DWORD` especificando os serviços para habilitar ou desabilitar, conforme mostrado na seguinte tabela.  
  
|Serviços padrão habilitados|Valor de palavra\-chave|  
|---------------------------------|-----------------------------|  
|Todos os serviços \(padrão\)|0xffffffff|  
|Todos exceptuam clustering e AutoEnlistment|0xfffffffe|  
|Todos exceptuam o cursor do cliente|0xfffffffb|  
|Todos exceptuam clustering, AutoEnlistment, e cursor do cliente|0xfffffff0|  
|Nenhum serviços|0x00000000|  
|Nenhuma agregação, todos os serviços desabilitados|\<chave ausente\>|  
  
## Consulte também  
 [Habilitando e desabilitando serviços de banco de dados OLE](../../data/oledb/enabling-and-disabling-ole-db-services.md)