---
title: "Classe de CStringData | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CStringData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStringData"
  - "classes compartilhadas, CStringData"
ms.assetid: 4e31b5ca-3dbe-4fd5-b692-8211fbfb2593
caps.latest.revision: 16
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStringData
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa os dados de um objeto de cadeia de caracteres.  
  
## Sintaxe  
  
```  
  
struct CStringData  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[AddRef](../Topic/CStringData::AddRef.md)|Sai contagem de referência de objeto de dados de cadeia de caracteres.|  
|[dados](../Topic/CStringData::data.md)|Recupera dados de caractere de um objeto de cadeia de caracteres.|  
|[IsLocked](../Topic/CStringData::IsLocked.md)|Determina se o buffer do objeto associado de cadeia de caracteres é bloqueado.|  
|[IsShared](../Topic/CStringData::IsShared.md)|Determina se o buffer do objeto associado de cadeia de caracteres é compartilhado no momento.|  
|[Bloquear](../Topic/CStringData::Lock.md)|Bloqueia o buffer do objeto associado de cadeia de caracteres.|  
|[Versão](../Topic/CStringData::Release.md)|Libera o objeto de cadeia de caracteres especificado.|  
|[Unlock](../Topic/CStringData::Unlock.md)|Desbloqueia o buffer do objeto associado de cadeia de caracteres.|  
  
### Membros de dados  
  
|||  
|-|-|  
|[nAllocLength](../Topic/CStringData::nAllocLength.md)|Comprimento de dados atribuídos em `XCHAR`s \(não incluindo de terminação o zero\)|  
|[nDataLength](../Topic/CStringData::nDataLength.md)|Comprimento de dados atualmente usados em `XCHAR`s \(não incluindo de terminação o zero\)|  
|[nRefs](../Topic/CStringData::nRefs.md)|A contagem de referência de objeto atual.|  
|[pStringMgr](../Topic/CStringData::pStringMgr.md)|Um ponteiro ao gerenciador de cadeia de caracteres de esse objeto de cadeia de caracteres.|  
  
## Comentários  
 Essa classe deve ser usada somente os desenvolvedores que implementam gerentes personalizados de cadeia de caracteres.  Para obter mais informações sobre os gerentes personalizados de cadeia de caracteres, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md)  
  
 Essa classe encapsula vários tipos de informação e os dados associados com uma cadeia de caracteres mais alta objetos, como objetos de [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), de [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), ou de [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md) .  Cada objeto de uma cadeia de caracteres mais alta contém um ponteiro para seu respectivo objeto de `CStringData` , permitindo vários objetos de cadeia de caracteres para apontar para o mesmo objeto de dados de cadeia de caracteres.  Esse relacionamento é representada pela contagem de referência \(`nRefs`\) do objeto de `CStringData` .  
  
> [!NOTE]
>  Em alguns casos, um tipo cadeia de caracteres \(como\) não **CFixedString**compartilhar um objeto de dados de cadeia de caracteres com mais de um objeto de uma cadeia de caracteres mais alta.  Para obter mais informações sobre isso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
 Esses dados são compostos de:  
  
-   O gerenciador de memória \(de tipo [IAtlStringMgr](../Topic/IAtlStringMgr%20Class.md)\) de cadeia de caracteres.  
  
-   O comprimento atual \([nDataLength](../Topic/CStringData::nDataLength.md)\) de cadeia de caracteres.  
  
-   O comprimento atribuído \([nAllocLength](../Topic/CStringData::nAllocLength.md)\) de cadeia de caracteres.  Por razões de desempenho, isso pode diferir de comprimento atual de cadeia de caracteres  
  
-   A contagem de referência atual \([nRefs](../Topic/CStringData::nRefs.md)\) do objeto de `CStringData`.  Esse valor é usado em determinar quantos objetos de cadeia de caracteres está compartilhando o mesmo objeto de `CStringData` .  
  
-   O buffer real de caractere \([dados](../Topic/CStringData::data.md)\) de cadeia de caracteres.  
  
    > [!NOTE]
    >  O buffer real de caracteres do objeto de cadeia de caracteres é determinado pelo gerenciador de cadeia de caracteres e acrescentado ao objeto de `CStringData` .  
  
## Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)