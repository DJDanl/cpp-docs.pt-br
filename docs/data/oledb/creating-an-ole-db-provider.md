---
title: Criando um provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: f73017c3-c89f-41a6-a306-ea992cf6092c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 441fdfcf98e08b30e1049cac986ebc9e0f7df682
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46030398"
---
# <a name="creating-an-ole-db-provider"></a>Criando um provedor de banco de dados OLE

A maneira recomendada para criar um provedor OLE DB é usar os assistentes para criar um projeto de ATL COM e um provedor e, em seguida, modificar os arquivos usando os modelos OLE DB. Como personalizar o seu provedor, você pode comentar propriedades indesejadas e adicionar interfaces opcionais.  
  
As etapas básicas são as seguintes:  
  
1. Usar o Assistente de projeto do ATL para criar os arquivos de projeto básico e ATL OLE DB Provider Assistente para criar o provedor (selecione **ATL OLE DB Provider** da pasta no Visual C++ **Adicionar classe**).  
  
1. Modificar o código de `Execute` método na CMyProviderRS.h. Por exemplo, consulte [lendo cadeias de caracteres em um provedor OLE DB](../../data/oledb/reading-strings-into-the-ole-db-provider.md).  
  
1. Edite os mapeamentos de propriedade em myproviderds. H, myprovidersess. H e myproviderrs. H. O assistente cria mapas de propriedade que contêm todas as propriedades de um provedor pode implementar. Percorra os mapas de propriedade e remova ou comente as propriedades que seu provedor não precisa dar suporte.  
  
1. Atualize PROVIDER_COLUMN_MAP, que pode ser encontrado em myproviderrs. H. Por exemplo, consulte [armazenar cadeias de caracteres no provedor OLE DB](../../data/oledb/storing-strings-in-the-ole-db-provider.md).  
  
1. Quando você estiver pronto para testar seu provedor, você pode testá-lo ao tentar localizar o provedor em uma enumeração do provedor. Para obter exemplos de código de teste que localiza um provedor em uma enumeração, consulte o [CATDB](https://github.com/Microsoft/VCSamples) e [DBVIEWER](https://github.com/Microsoft/VCSamples) exemplos ou o exemplo [consumidor simples A implementação de](../../data/oledb/implementing-a-simple-consumer.md).  
  
1. Adicione quaisquer interfaces adicionais que você deseja. Por exemplo, consulte [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).  
  
    > [!NOTE]
    >  Por padrão, os assistentes geram código que é o nível de banco de dados OLE 0 em conformidade. Para garantir que seu aplicativo permaneça nível 0 em conformidade, não remova qualquer uma das interfaces geradas pelo Assistente do código.  
  
## <a name="see-also"></a>Consulte também  

[CATDB](https://github.com/Microsoft/VCSamples)<br/>
[DBVIEWER](https://github.com/Microsoft/VCSamples)