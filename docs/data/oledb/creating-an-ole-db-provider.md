---
title: Criando um provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 10/13/2018
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
ms.openlocfilehash: 7c3d94bec2638901f542dfa7c412da0de9a60942
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50078291"
---
# <a name="creating-an-ole-db-provider"></a>Criando um provedor de banco de dados OLE

A maneira recomendada para criar um provedor OLE DB é usar os assistentes para criar um projeto de ATL COM e um provedor e, em seguida, modificar os arquivos usando os modelos OLE DB. Como personalizar o seu provedor, você pode comentar propriedades indesejadas e adicionar interfaces opcionais.

As etapas básicas são as seguintes:

1. Use o **ATL Project Wizard** para criar os arquivos de projeto básico e o **Assistente de provedor ATL OLEDB** para criar o provedor (selecionar **provedor de OLEDB do ATL** do **Installed** > **Visual C++** > **ATL** pasta no **Add New Item**).

   > [!NOTE]
   > O projeto deve incluir o suporte do MFC antes de adicionar um **provedor de OLEDB do ATL**.

1. Modificar o código a `Execute` método no [CCustomRowset(CustomRS.h)](cmyproviderrowset-myproviderrs-h.md). Por exemplo, consulte [lendo cadeias de caracteres em um provedor OLE DB](../../data/oledb/reading-strings-into-the-ole-db-provider.md).

1. Editar a propriedade é mapeada na [CustomDS.h](cmyprovidersource-myproviderds-h.md), [CustomSess.h](cmyprovidersession-myprovidersess-h.md), e [CustomRS.h](cmyproviderrowset-myproviderrs-h.md). O assistente cria mapas de propriedade que contêm todas as propriedades de um provedor pode implementar. Percorra os mapas de propriedade e remova ou comente as propriedades que seu provedor não precisa dar suporte.

1. Atualizar PROVIDER_COLUMN_MAP, que pode ser encontrado na [CCustomRowset(CustomRS.h)](cmyproviderrowset-myproviderrs-h.md). Por exemplo, consulte [armazenar cadeias de caracteres no provedor OLE DB](../../data/oledb/storing-strings-in-the-ole-db-provider.md).

1. Quando você estiver pronto para testar seu provedor, você pode testá-lo ao tentar localizar o provedor em uma enumeração do provedor. Para obter exemplos de código de teste que localiza um provedor em uma enumeração, consulte o [CATDB](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/catdb) e [DBVIEWER](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/dbviewer) exemplos ou o exemplo [consumidor simples A implementação de](../../data/oledb/implementing-a-simple-consumer.md).

1. Adicione quaisquer interfaces adicionais que você deseja. Por exemplo, consulte [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).

   > [!NOTE]
   > Por padrão, os assistentes geram código que é o nível de banco de dados OLE 0 em conformidade. Para garantir que seu aplicativo permaneça nível 0 em conformidade, não remova qualquer uma das interfaces geradas pelo Assistente do código.

## <a name="see-also"></a>Consulte também

[Exemplo CatDB: Navegador de esquema de fonte de dados](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/catdb)<br/>
[Exemplo DBViewer: Navegador de banco de dados](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/dbviewer)
