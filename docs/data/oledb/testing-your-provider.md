---
title: Testando o provedor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- testing, OLE DB providers
- testing providers
- OLE DB providers, testing
ms.assetid: bf824fe4-81af-4ffb-beb3-4fa2928dc450
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0d273c746a27c85dbcd58cb5e7fb544a0fc6a0bb
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="testing-your-provider"></a>Testando o provedor
Antes de liberar um provedor, você deve executar os testes a seguir, na ordem indicada. Esses testes Certifique-se de que as funções de provedor corretamente para a maioria dos usuários em potencial.  
  
1.  Testar o provedor usando um [consumidor](../../data/oledb/creating-an-ole-db-consumer.md) aplicativo escrito com os modelos de consumidor OLE DB. O consumidor de teste deve cobrir todas as áreas funcionais do provedor (todo o código que você tenha adicionado ou modificado).  
  
2.  Teste o provedor usando um aplicativo cliente escrito com o ADO. A maioria dos desenvolvedores (especialmente desenvolvedores do Microsoft Visual Basic e c# Microsoft) usam ADO ou ADO.NET para aplicativos de consumidor. O consumidor de teste deve cobrir todas as áreas funcionais do provedor. Para obter um exemplo de um aplicativo de consumidor de ADO, consulte [exemplos de código ADO no Microsoft Visual Basic](https://msdn.microsoft.com/en-us/library/ms807514.aspx).  
  
3.  Execute os testes de conformidade de banco de dados OLE (inclusive testes de conformidade de ADO) para garantir que seu provedor atende o nível padrão de 0 para provedores OLE DB. (Para obter uma explicação de nível 0, pesquise "OLE DB nível 0 testes de conformidade" em [guia do programador do DB OLE](http://go.microsoft.com/fwlink/p/?linkid=121548). Esses testes e a documentação associada são incluídos com o Visual C++ no SDK de acesso a dados. Esses testes também ajudam a garantir que o provedor é executado bem quando agregados por outros [provedores de serviços](../../data/oledb/ole-db-resource-pooling-and-services.md) e são especialmente úteis se você modificar ou adiciona propriedades. Para obter mais informações sobre os testes de conformidade, consulte o arquivo Leiame para o SDK de acesso de dados, que está localizado em um dos CDs do Visual Studio.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)