---
title: "Visão geral da programação OLE DB | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Universal Data Access
- OLE DB, about OLE DB
ms.assetid: a5a69730-2793-4277-a67d-6f3c8edab6df
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1f3d97dda514b3cdb0773adb3d7830e611bca3d9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ole-db-programming-overview"></a>Visão geral da programação de banco de dados OLE
OLE DB é uma tecnologia de banco de dados de alto desempenho, COM base em com. Ele fornece uma maneira comum para acessar dados, independentemente do formato no qual ela está armazenada. Em uma situação de típicos de negócios, uma grande quantidade de informações é armazenada fora de bancos de dados corporativos. Essas informações se encontra em sistemas de arquivos (como FAT ou NTFS), arquivos indexados sequencial, bancos de dados pessoais (como acesso), planilhas (como o Excel), aplicativos de planejamento de projeto (como o projeto) e email (como o Outlook). OLE DB permite que você acesse qualquer tipo de repositório de dados da mesma maneira, como o repositório de dados tem um provedor OLE DB.
  
 OLE DB permite que você desenvolva aplicativos que acessam diversas fontes de dados, independentemente de estarem DBMS ou não. OLE DB possibilita acesso universal usando interfaces COM que suportam a funcionalidade DBMS apropriada para uma determinada fonte de dados. COM reduz a duplicação desnecessária de serviços e maximizado interoperabilidade não apenas entre fontes de dados, mas também entre os outros aplicativos.  
  
## <a name="benefits-of-com"></a>Benefícios do COM  
 Isso é aqui que entra COM. OLE DB é um conjunto de interfaces COM. Acessando dados por meio de um conjunto uniforme de interfaces, você pode organizar um banco de dados em uma matriz de componentes trabalham em conjunto.  
  
 Com base na especificação de COM, OLE DB define uma coleção extensível e sustentável de interfaces implementadas por fatores e encapsular partes consistentes e reutilizáveis da funcionalidade DBMS. Essas interfaces definem os limites dos componentes DBMS como contêineres de linha, processadores de consulta e coordenadores de transação, que permitem acesso transacional uniforme para fontes diferentes de informações.  
 
  
## <a name="see-also"></a>Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Modelos do OLE DB](../../data/oledb/ole-db-templates.md)