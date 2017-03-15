---
title: "Definindo propriedades no provedor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Provedores OLE DB, propriedades"
  - "propriedades [C++], Provedor OLE DB"
ms.assetid: 26a8b493-7ec4-4686-96d0-9ad5d2bca5ac
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo propriedades no provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Localizar a ID do grupo de propriedade e a propriedade para a propriedade que você deseja.  Para obter mais informações, consulte [Propriedades do OLE DB](https://msdn.microsoft.com/en-us/library/ms722734.aspx)*na referência do programador de OLE DB*.  
  
 No código do provedor gerado pelo assistente, localize o mapa de propriedade que corresponde ao grupo da propriedade.  O nome do grupo de propriedades geralmente corresponde ao nome do objeto.  As propriedades de comando e do conjunto de linhas podem ser localizadas no comando ou no conjunto de linhas; as propriedades de fonte de dados e de inicialização podem ser localizadas no objeto de fonte de dados.  
  
 No mapa da propriedade, adicione uma macro de [PROPERTY\_INFORMATION\_ENTRY\_EX](../../data/oledb/property-info-entry-ex.md) .  PROPERTY\_INFORMATION\_ENTRY\_EX usa quatro parâmetros:  
  
-   A ID da propriedade que corresponde à sua propriedade.  Você deve remover os primeiros sete caracteres \(“”\) DBPROP\_ da frente do nome da propriedade.  Por exemplo, se você quiser adicionar **DBPROP\_MAXROWS**, passagem `MAXROWS` como o primeiro elemento.  Se esta é uma propriedade personalizada, o nome completo do GUID \(por exemplo, `DBMYPROP_MYPROPERTY`\).  
  
-   O tipo variante da propriedade \(em [Propriedades do OLE DB](https://msdn.microsoft.com/en-us/library/ms722734.aspx)*na referência do programador de OLE DB*\).  Digite o tipo de **VT\_** \(como `VT_BOOL` ou `VT_I2`\) que corresponde ao tipo de dados.  
  
-   Sinalizadores para indicar se a propriedade estiver legível e graváveis e o grupo ao qual pertence.  Por exemplo, o código a seguir indica uma propriedade de leitura\/gravação que pertence ao grupo do conjunto de linhas:  
  
    ```  
    DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE  
    ```  
  
-   O valor de propriedade base.  Esse pode ser **VARIANT\_FALSE** para um tipo ou um zero booliano para um tipo inteiro, por exemplo.  A propriedade tem esse valor como menos que seja alterada.  
  
    > [!NOTE]
    >  Algumas propriedades são conectadas ou encadeadas a outras propriedades, como indicadores ou atualização.  Quando um consumidor define uma propriedade para retificar, outra propriedade também pode ser definida.  Os modelos do provedor OLE DB da suporte a esse [CUtlProps::OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)com o método.  
  
## Propriedades ignoradas por provedores OLE DB  
 Os provedores OLE DB ignora as seguintes propriedades OLE DB:  
  
-   Trabalho de**DBPROP\_MAXROWS** apenas para provedores somente leitura \(ou seja, onde e DBPROP\_IRowsetChange DBPROP\_IRowsetUpdate é false\); se não essa propriedade não tem suporte.  
  
-   **DBPROP\_MAXPENDINGROWS** é ignorado; o provedor especificar seu próprio limite.  
  
-   **DBPROP\_MAXOPENROWS** é ignorado; o provedor especificar seu próprio limite.  
  
-   **DBPROP\_CANHOLDROWS** é ignorado; o provedor especificar seu próprio limite.  
  
## Consulte também  
 [Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)