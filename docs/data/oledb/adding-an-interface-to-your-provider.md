---
title: Adicionando uma Interface ao provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB provider templates, object interfaces
ms.assetid: b0fc7cf8-428a-4584-9d64-ce9074d0eb66
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 83f04b53ec7d3527ddfbd58582f435d5fb153014
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50073065"
---
# <a name="adding-an-interface-to-your-provider"></a>Adicionando uma interface ao provedor

Determine qual objeto você deseja adicionar a interface para (geralmente código-fonte, conjunto de linhas, comando ou sessão de objetos de dados criados pelo Assistente do provedor de banco de dados OLE). É possível que o objeto que você precisa adicionar a interface é que seu provedor não dá suporte atualmente. Nesse caso, execute o ATL OLE DB Provider Assistente para criar o objeto. Clique com botão direito no projeto no modo de exibição de classe, clique em **Add Class** da **Add** menu e, em seguida, clique **ATL OLE DB Provider**. Você talvez queira colocar o código da interface em um diretório separado e, em seguida, copie os arquivos para seu projeto de provedor.

Se você criou uma nova classe para oferecer suporte à interface, tornar o objeto que herdam dessa classe. Por exemplo, você pode adicionar a classe **IRowsetIndexImpl** a um objeto de conjunto de linhas:

```cpp
template <class Creator>
class CAgentRowset :
    public CRowsetImpl< CAgentRowset<Creator>, CAgentMan, Creator>,
    public IRowsetIndexImpl< ... >
```

Adicionar o adaptador **COM_MAP** no objeto usando a macro COM_INTERFACE_ENTRY. Se não há nenhum mapa, crie um. Por exemplo:

```cpp
BEGIN_COM_MAP(CAgentRowset)
     COM_INTERFACE_ENTRY(IRowsetIndex)
END_COM_MAP()
```

Para o objeto de conjunto de linhas, cadeia o mapa de seu pai do objeto para que o objeto possa delegar para a classe pai. Neste exemplo, adicione a macro COM_INTERFACE_ENTRY_CHAIN no mapa:

```cpp
BEGIN_COM_MAP(CAgentRowset)
     COM_INTERFACE_ENTRY(IRowsetIndex)
     COM_INTERFACE_ENTRY_CHAIN(CRowsetImpl)
END_COM_MAP()
```

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)