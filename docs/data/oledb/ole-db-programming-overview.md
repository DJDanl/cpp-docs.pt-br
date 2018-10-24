---
title: Visão geral de programação do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- Universal Data Access
- OLE DB, about OLE DB
ms.assetid: a5a69730-2793-4277-a67d-6f3c8edab6df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5fea82dfd7d3f9cdd64d0eab66e44ac1a486abac
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49989886"
---
# <a name="ole-db-programming-overview"></a>Visão geral da programação de banco de dados OLE

OLE DB é uma tecnologia de banco de dados de alto desempenho, COM base em com. Ele fornece uma maneira comum para acessar dados, independentes do formulário no qual ele está armazenado. Em uma situação de negócios típico, uma grande quantidade de informações não é armazenada em bancos de dados corporativos. Essa informação é encontrada em sistemas de arquivos (como FAT ou NTFS), arquivos indexados sequenciais, bancos de dados pessoais (como acesso), planilhas (como o Excel), aplicativos de planejamento de projeto (por exemplo, o projeto) e email (como o Outlook). OLE DB permite que você acesse qualquer tipo de armazenamento de dados da mesma maneira, desde que o armazenamento de dados tenha um provedor OLE DB.
  
OLE DB permite que você desenvolva aplicativos que acessam várias fontes de dados, independentemente de estarem DBMS ou não. OLE DB possibilita acesso universal usando interfaces COM que dão suporte a funcionalidade DBMS apropriada para uma determinada fonte de dados. COM reduz a duplicação desnecessária de serviços e maximizada interoperabilidade não apenas entre fontes de dados, mas também entre os outros aplicativos.  
  
## <a name="benefits-of-com"></a>Benefícios do COM  

Isso é onde entra COM. OLE DB é um conjunto de interfaces COM. Acessando dados por meio de um conjunto uniforme de interfaces, você pode organizar um banco de dados em uma matriz de componentes trabalham em conjunto.  
  
Com base na especificação COM, OLE DB define uma coleção extensível e sustentável de interfaces que fatores e encapsular consistentes e reutilizáveis partes da funcionalidade do DBMS. Essas interfaces definem os limites dos componentes DBMS, como contêineres de linha, processadores de consulta e os coordenadores de transação, que permitem acesso transacional uniforme para várias fontes de informação.  
 
## <a name="see-also"></a>Consulte também  

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Modelos do OLE DB](../../data/oledb/ole-db-templates.md)