---
title: Definindo propriedades no provedor
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB providers, properties
- properties [C++], OLE DB provider
ms.assetid: 26a8b493-7ec4-4686-96d0-9ad5d2bca5ac
ms.openlocfilehash: 905a9bb32544dbd7453d46362e100047516d22a8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209567"
---
# <a name="setting-properties-in-your-provider"></a>Definindo propriedades no provedor

Localize o grupo de propriedades e a ID da propriedade que você deseja. Para obter mais informações, consulte [Propriedades de OLE DB](/previous-versions/windows/desktop/ms722734(v=vs.85)) na **referência do programador de OLE DB**.

No código do provedor gerado pelo assistente, localize o mapa de propriedade correspondente ao grupo de propriedades. O nome do grupo de propriedades geralmente corresponde ao nome do objeto. As propriedades Command e Rowset podem ser encontradas no comando ou conjunto de linhas; as propriedades de fonte de dados e inicialização podem ser encontradas no objeto de fonte de dados.

No mapa de propriedades, adicione uma macro [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md) . PROPERTY_INFO_ENTRY_EX usa quatro parâmetros:

- A ID de propriedade correspondente à sua propriedade. Remova os primeiros sete caracteres ("DBPROP_") da parte frontal do nome da propriedade. Por exemplo, se você quiser adicionar `DBPROP_MAXROWS`, passe `MAXROWS` como o primeiro elemento. Se essa for uma propriedade personalizada, passe o nome completo do GUID (por exemplo, `DBMYPROP_MYPROPERTY`).

- O tipo de variante da propriedade (em [OLE DB Propriedades](/previous-versions/windows/desktop/ms722734(v=vs.85)) na **referência do programador de OLE DB**). Insira o tipo de VT_ (como VT_BOOL ou VT_I2) correspondente ao tipo de dados.

- Sinalizadores para indicar se a propriedade é legível e gravável e o grupo ao qual ela pertence. Por exemplo, o código a seguir indica uma propriedade de leitura/gravação que pertence ao grupo de conjunto de linhas:

    ```cpp
    DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE
    ```

- O valor base da propriedade. Isso pode ser `VARIANT_FALSE` para um tipo booliano ou zero para um tipo inteiro, por exemplo. A propriedade tem esse valor, a menos que seja alterada.

    > [!NOTE]
    > Algumas propriedades são conectadas ou encadeadas a outras propriedades, como indicadores ou atualizações. Quando um consumidor define uma propriedade como true, outra propriedade também pode ser definida. Os modelos de provedor de OLE DB dão suporte a isso por meio do método [CUtlProps:: OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md).

## <a name="properties-ignored-by-microsoft-ole-db-providers"></a>Propriedades ignoradas pelos provedores de OLE DB da Microsoft

Os provedores do Microsoft OLE DB ignoram as seguintes propriedades de OLE DB:

- `DBPROP_MAXROWS` só funciona para provedores somente leitura (ou seja, onde `DBPROP_IRowsetChange` e `DBPROP_IRowsetUpdate` são **false**); caso contrário, essa propriedade não terá suporte.

- `DBPROP_MAXPENDINGROWS` é ignorado; o provedor especifica seu próprio limite.

- `DBPROP_MAXOPENROWS` é ignorado; o provedor especifica seu próprio limite.

- `DBPROP_CANHOLDROWS` é ignorado; o provedor especifica seu próprio limite.

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)
