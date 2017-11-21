---
title: Definindo propriedades no provedor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB providers, properties
- properties [C++], OLE DB provider
ms.assetid: 26a8b493-7ec4-4686-96d0-9ad5d2bca5ac
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 80b82e1fb69200f45716b2ad62a44160862f7d08
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="setting-properties-in-your-provider"></a>Definindo propriedades no provedor
Localize o grupo de propriedades e a ID de propriedade para a propriedade que você deseja. Para obter mais informações, consulte [propriedades OLE DB](https://msdn.microsoft.com/en-us/library/ms722734.aspx) no *referência do programador de DB OLE*.  
  
 O código gerado pelo Assistente do provedor, encontra o mapa de propriedade correspondente ao grupo de propriedade. O nome do grupo de propriedades geralmente corresponde ao nome do objeto. Propriedades de comando e o conjunto de linhas podem ser encontradas no comando ou conjunto de linhas; Propriedades de inicialização e a fonte de dados podem ser encontradas no objeto de fonte de dados.  
  
 No mapa de propriedade, adicione um [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md) macro. PROPERTY_INFO_ENTRY_EX tem quatro parâmetros:  
  
-   A ID de propriedade correspondente à sua propriedade. Você deve remover os sete primeiros caracteres ("DBPROP_") no início do nome da propriedade. Por exemplo, se você deseja adicionar **DBPROP_MAXROWS**, passar `MAXROWS` como o primeiro elemento. Se esta for uma propriedade personalizada, passe o nome completo do GUID (por exemplo, `DBMYPROP_MYPROPERTY`).  
  
-   O tipo de variante da propriedade (em [propriedades OLE DB](https://msdn.microsoft.com/en-us/library/ms722734.aspx) no *referência do programador de DB OLE*). Insira o **VT_** tipo (como `VT_BOOL` ou `VT_I2`) correspondente ao tipo de dados.  
  
-   Sinalizadores para indicar se a propriedade é legível e gravável e o grupo ao qual ele pertence. Por exemplo, o código a seguir indica uma propriedade de leitura/gravação que pertencem ao grupo de linhas:  
  
    ```  
    DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE  
    ```  
  
-   O valor base da propriedade. Isso pode ser **VARIANT_FALSE** para um valor booleano, digite ou zero para um tipo inteiro, por exemplo. A propriedade tem esse valor, a menos que seja alterado.  
  
    > [!NOTE]
    >  Algumas propriedades são conectadas ou encadeadas para outras propriedades, como indicadores ou atualização. Quando um consumidor define uma propriedade como true, outra propriedade também pode ser definida. Os modelos de provedor do OLE DB oferecer suporte a isso por meio do método [cutlprops:: OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md).  
  
## <a name="properties-ignored-by-microsoft-ole-db-providers"></a>Propriedades ignoradas por provedores de OLE DB da Microsoft  
 Os provedores OLE DB da Microsoft ignorar as seguintes propriedades de OLE DB:  
  
-   **DBPROP_MAXROWS** só funciona para provedores de somente leitura (ou seja, onde DBPROP_IRowsetChange e DBPROP_IRowsetUpdate são false); caso contrário, não há suporte para essa propriedade.  
  
-   **DBPROP_MAXPENDINGROWS** é ignorada; o provedor especificar seu próprio limite.  
  
-   **DBPROP_MAXOPENROWS** é ignorada; o provedor especificar seu próprio limite.  
  
-   **DBPROP_CANHOLDROWS** é ignorada; o provedor especificar seu próprio limite.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)