---
title: Adicionando uma interface ao provedor
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB provider templates, object interfaces
ms.assetid: b0fc7cf8-428a-4584-9d64-ce9074d0eb66
ms.openlocfilehash: a1d219568c1787558674c47edd55436b8690a61c
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65524802"
---
# <a name="adding-an-interface-to-your-provider"></a>Adicionando uma interface ao provedor

> [!NOTE]
> O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

Determine a qual objeto você deseja adicionar a interface (geralmente fonte de dados, conjunto de linhas, comando ou objetos de sessão criados pelo **Assistente de Provedor OLE DB**). É possível que o objeto ao qual você precise adicionar a interface não seja compatível no momento com o provedor. Nesse caso, execute o **Assistente de Provedor OLE DB da ATL** para criar o objeto. Clique com o botão direito do mouse no projeto no **Modo de Exibição de Classe**, clique em **Adicionar** > **Novo Item** no menu, selecione **Instalado** > **Visual C++** > **ATL** e, em seguida, clique em **provedor OLEDB do ATL**. Convém colocar o código da interface em um diretório separado e copiar os arquivos no seu projeto de provedor.

Se você criou uma nova classe para dar suporte à interface, faça o objeto ser herdado dessa classe. Por exemplo, você pode adicionar a classe `IRowsetIndexImpl` a um objeto de conjunto de linhas:

```cpp
template <class Creator>
class CCustomRowset :
    public CRowsetImpl< CCustomRowset<Creator>, CCustomWindowsFile, Creator>,
    public IRowsetIndexImpl< ... >
```

Adicione a interface a COM_MAP no objeto usando a macro COM_INTERFACE_ENTRY. Se não houver mapa, crie um. Por exemplo:

```cpp
BEGIN_COM_MAP(CCustomRowset)
     COM_INTERFACE_ENTRY(IRowsetIndex)
END_COM_MAP()
```

Para o objeto de conjunto de linhas, encadeie o mapa de seu objeto pai para que o objeto possa ser delegado à classe pai. Neste exemplo, adicione a macro COM_INTERFACE_ENTRY_CHAIN ao mapa:

```cpp
BEGIN_COM_MAP(CCustomRowset)
     COM_INTERFACE_ENTRY(IRowsetIndex)
     COM_INTERFACE_ENTRY_CHAIN(CRowsetImpl)
END_COM_MAP()
```

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)