---
title: "Objetos e origens de dados (OLE) | Microsoft Docs"
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
  - "objetos de dados [C++], definição"
  - "fonte de dados [C++], definição"
  - "transferência de dados [C++]"
  - "transferência de dados [C++], definição"
  - "OLE [C++], objetos de dados"
  - "OLE [C++], fontes de dados"
  - "OLE [C++], transferência de dados"
ms.assetid: 8f68eed8-0ce8-4489-a4cc-f95554f89090
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos e origens de dados (OLE)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você executa uma transferência de dados, por meio da área de transferência ou o arraste e descartar, os dados têm uma origem e um destino.  Um aplicativo fornece os dados para copiar e outro aplicativo aceitar\-lo para colar.  Cada lado das necessidades de transferência de executar operações diferentes nos mesmos dados para que a transferência foi bem\-sucedida.  A biblioteca de \(MFC\) da classe do Microsoft fornece duas classes que representam cada lado dessa transferência:  
  
-   As fontes de dados \(conforme implementado por objetos de `COleDataSource` \) representam o lado de origem de transferência de dados.  São criados pelo aplicativo de origem quando os dados devem ser copiados para a área de transferência, ou quando os dados são fornecidos para uma operação de arrastar e soltar.  
  
-   Os objetos de dados \(conforme implementado por objetos de `COleDataObject` \) representam o lado de destino de transferência de dados.  São criados quando o aplicativo de destino tem os dados removidos nele, ou quando solicitado para executar uma operação de colagem da área de transferência.  
  
 Os artigos a seguir explicam como usar objetos de dados e fontes de dados em seus aplicativos.  Essas informações são aplicadas ao contêiner e aplicativos para servidores, pois ambos podem ser convidados para copiar e colar dados.  
  
-   [Objetos de dados e fontes de dados: Criação e destruição](../mfc/data-objects-and-data-sources-creation-and-destruction.md)  
  
-   [Objetos de dados e fontes de dados: Tratamento](../mfc/data-objects-and-data-sources-manipulation.md)  
  
## Nesta seção  
 [Drag and Drop \(Arrastar e Soltar\)](../mfc/drag-and-drop-ole.md)  
  
 [Área de transferência](../mfc/clipboard.md)  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Classe de COleDataObject](../mfc/reference/coledataobject-class.md)   
 [Classe de COleDataSource](../mfc/reference/coledatasource-class.md)