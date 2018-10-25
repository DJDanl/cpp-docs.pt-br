---
title: Definindo propriedades no provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, properties
- properties [C++], OLE DB provider
ms.assetid: 26a8b493-7ec4-4686-96d0-9ad5d2bca5ac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7555e90a6eca9c9f4031458963ff2a90eed552a7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50057829"
---
# <a name="setting-properties-in-your-provider"></a>Definindo propriedades no provedor

Localize o grupo de propriedades e a ID de propriedade para a propriedade desejada. Para obter mais informações, consulte [propriedades do OLE DB](/previous-versions/windows/desktop/ms722734) na *referência do programador DB OLE*.

No código do provedor gerado pelo assistente, encontre o mapa de propriedade correspondente ao grupo de propriedades. O nome do grupo de propriedades geralmente corresponde ao nome do objeto. Propriedades de comando e o conjunto de linhas podem ser encontradas no comando ou conjunto de linhas; Propriedades de inicialização e a fonte de dados podem ser encontradas no objeto de fonte de dados.

No mapa de propriedade, adicione uma [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md) macro. PROPERTY_INFO_ENTRY_EX assume quatro parâmetros:

- A ID de propriedade correspondente à sua propriedade. Você deve remover os sete primeiros caracteres ("DBPROP_") a partir do início do nome da propriedade. Por exemplo, se você quiser adicionar `DBPROP_MAXROWS`, passar `MAXROWS` como o primeiro elemento. Quando se trata de uma propriedade personalizada, passe o nome completo do GUID (por exemplo, `DBMYPROP_MYPROPERTY`).

- O tipo de variante da propriedade (em [propriedades do OLE DB](/previous-versions/windows/desktop/ms722734) na *referência do programador DB OLE*). Insira o tipo (como VT_BOOL ou VT_I2) VT_ correspondente ao tipo de dados.

- Sinalizadores para indicar se a propriedade é legível e gravável e o grupo ao qual ele pertence. Por exemplo, o código a seguir indica uma propriedade de leitura/gravação que pertencem ao grupo de conjunto de linhas:

    ```
    DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE
    ```

- O valor base da propriedade. Isso pode ser `VARIANT_FALSE` para um valor booliano, digite ou zero para um tipo inteiro, por exemplo. A propriedade tem esse valor, a menos que ele é alterado.

    > [!NOTE]
    >  Algumas propriedades são conectadas ou encadeadas a outras propriedades, como indicadores ou atualizar. Quando um consumidor define uma propriedade como true, outra propriedade também pode ser definida. Os modelos de provedor do OLE DB oferecer suporte a isso por meio do método [cutlprops:: OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md).

## <a name="properties-ignored-by-microsoft-ole-db-providers"></a>Propriedades ignoradas por provedores de OLE DB da Microsoft

Os provedores OLE DB da Microsoft ignorar as propriedades de OLE DB a seguir:

- `DBPROP_MAXROWS` funciona somente para provedores de somente leitura (ou seja, onde DBPROP_IRowsetChange e DBPROP_IRowsetUpdate são false); Caso contrário, não há suporte para essa propriedade.

- `DBPROP_MAXPENDINGROWS` é ignorado; o provedor especifica seu próprio limite.

- `DBPROP_MAXOPENROWS` é ignorado; o provedor especifica seu próprio limite.

- `DBPROP_CANHOLDROWS` é ignorado; o provedor especifica seu próprio limite.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)