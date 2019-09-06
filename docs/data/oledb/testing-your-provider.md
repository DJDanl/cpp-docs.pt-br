---
title: Testando o provedor
ms.date: 10/29/2018
helpviewer_keywords:
- testing, OLE DB providers
- testing providers
- OLE DB providers, testing
ms.assetid: bf824fe4-81af-4ffb-beb3-4fa2928dc450
ms.openlocfilehash: 722757b93d3423b02340c382b16e08a31626bc01
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311764"
---
# <a name="testing-your-provider"></a>Testando o provedor

Antes de liberar um provedor, você deve fazer os testes a seguir, na ordem indicada. Esses testes mostram que o provedor funciona corretamente para a maioria dos usuários potenciais.

1. Teste o provedor usando um aplicativo de [consumidor](../../data/oledb/creating-an-ole-db-consumer.md) escrito com os modelos de consumidor OLE DB. O consumidor de teste deve abranger todas as áreas funcionais do seu provedor (todo o código que você adicionou ou modificou).

1. Teste o provedor usando um aplicativo de consumidor escrito com ADO. A maioria dos desenvolvedores (especialmente o Microsoft C# Visual Basic e os desenvolvedores da Microsoft) usam ADO ou ADO.net para aplicativos de consumidor. O consumidor de teste deve abranger todas as áreas funcionais do seu provedor. Para obter um exemplo de um aplicativo de consumidor do ADO, consulte [exemplos de código do ADO no Microsoft Visual Basic](/previous-versions/ms807514(v=msdn.10)).

1. Execute os testes de conformidade OLE DB (incluindo testes de conformidade do ADO) para mostrar que seu provedor atende ao padrão de nível 0 para provedores de OLE DB. (Para obter uma explicação do nível 0, pesquise os **testes de conformidade de OLE DB nível 0** no [Guia do programador de OLE DB](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming). Esses testes e a documentação associada estão incluídos no C++ visual no SDK de acesso a dados. Esses testes também ajudam a mostrar que seu provedor é executado bem quando agregado por outros [provedores de serviço](../../data/oledb/ole-db-resource-pooling-and-services.md) e é especialmente útil se você modificar ou adicionar propriedades. Para obter mais informações sobre os testes de conformidade, consulte o arquivo Leiame do SDK de acesso a dados, que está localizado em um dos CDs do Visual Studio.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)