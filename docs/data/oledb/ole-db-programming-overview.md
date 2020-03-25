---
title: Visão geral da programação de banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- Universal Data Access
- OLE DB, about OLE DB
ms.assetid: a5a69730-2793-4277-a67d-6f3c8edab6df
ms.openlocfilehash: 2b855e0917ba9cdbdaa38a92473d7bddb4279101
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210061"
---
# <a name="ole-db-programming-overview"></a>Visão geral da programação de banco de dados OLE

OLE DB é uma tecnologia de banco de dados baseada em COM de alto desempenho. Ele fornece uma maneira comum de acessar dados independentemente do formulário no qual ele está armazenado. Em uma situação de negócios típica, uma grande quantidade de informações não é armazenada em bancos de dados corporativos. Essas informações são encontradas em sistemas de arquivos (como FAT ou NTFS), arquivos seqüenciais indexados, bancos de dados pessoais (como o Access), planilhas (como o Excel), aplicativos de planejamento de projetos (como projeto) e email (como o Outlook). OLE DB permite que você acesse qualquer tipo de armazenamento de dados da mesma maneira, desde que o armazenamento de dados tenha um provedor de OLE DB.

OLE DB permite que você desenvolva aplicativos que acessam diversas fontes de dados, sejam eles DBMS ou não. OLE DB torna possível o acesso universal usando interfaces COM que dão suporte à funcionalidade de DBMS apropriada para uma determinada fonte de dados. O COM reduz a duplicação desnecessária de serviços e a interoperabilidade maximizada não apenas entre fontes de dados, mas também entre outros aplicativos.

## <a name="benefits-of-com"></a>Benefícios do COM

É aí que entra o COM. OLE DB é um conjunto de interfaces COM. Ao acessar dados por meio de um conjunto uniforme de interfaces, você pode organizar um banco de dado em uma matriz de componentes de cooperação.

Com base na especificação COM, OLE DB define uma coleção extensível e passível de manutenção de interfaces que fatorar e encapsular partes consistentes e reutilizáveis da funcionalidade do DBMS. Essas interfaces definem os limites de componentes do DBMS, como contêineres de linha, processadores de consulta e coordenadores de transações, que permitem o acesso transacional uniforme a diversas fontes de informações.

## <a name="see-also"></a>Confira também

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Modelos do OLE DB](../../data/oledb/ole-db-templates.md)
