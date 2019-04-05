---
title: Adicionando uma interface ao provedor
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB provider templates, object interfaces
ms.assetid: b0fc7cf8-428a-4584-9d64-ce9074d0eb66
ms.openlocfilehash: c0452ca74509b65de3787af93bff41b3cb399c99
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033859"
---
# <a name="adding-an-interface-to-your-provider"></a>Adicionando uma interface ao provedor

Determinar quais objetos você deseja adicionar a interface para (normalmente, os objetos de dados de origem, conjunto de linhas, comando ou sessão criado pelo **OLE DB Provider Wizard**). É possível que o objeto que você precisa adicionar o adaptador é aquele que atualmente não dá suporte a seu provedor. Nesse caso, execute as **ATL OLE DB Provider Wizard** para criar o objeto. Clique com botão direito no projeto no **Class View**, clique em **Add** > **Novo Item** no menu, selecione **instalado**  >  **Visual C++** > **ATL**e, em seguida, clique em **provedor de OLEDB do ATL**. Você talvez queira colocar o código da interface em um diretório separado e, em seguida, copie os arquivos para seu projeto de provedor.

Se você criou uma nova classe para oferecer suporte à interface, tornar o objeto que herdam dessa classe. Por exemplo, você pode adicionar a classe `IRowsetIndexImpl` a um objeto de conjunto de linhas:

```cpp
template <class Creator>
class CCustomRowset :
    public CRowsetImpl< CCustomRowset<Creator>, CCustomWindowsFile, Creator>,
    public IRowsetIndexImpl< ... >
```

Adicione a interface para COM_MAP no objeto usando a macro COM_INTERFACE_ENTRY. Se não há nenhum mapa, crie um. Por exemplo:

```cpp
BEGIN_COM_MAP(CCustomRowset)
     COM_INTERFACE_ENTRY(IRowsetIndex)
END_COM_MAP()
```

Para o objeto de conjunto de linhas, cadeia o mapa de seu pai do objeto para que o objeto possa delegar para a classe pai. Neste exemplo, adicione a macro COM_INTERFACE_ENTRY_CHAIN no mapa:

```cpp
BEGIN_COM_MAP(CCustomRowset)
     COM_INTERFACE_ENTRY(IRowsetIndex)
     COM_INTERFACE_ENTRY_CHAIN(CRowsetImpl)
END_COM_MAP()
```

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)