---
title: Objetos de dados e fontes de dados (OLE) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- data objects [MFC], definition
- data transfer [MFC]
- OLE [MFC], data transfer
- data sources [MFC], definition
- data transfer [MFC], definition
- OLE [MFC], data objects
- OLE [MFC], data sources
ms.assetid: 8f68eed8-0ce8-4489-a4cc-f95554f89090
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 766148494c6b8693f8d9e65f27e157b58d8e8689
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342973"
---
# <a name="data-objects-and-data-sources-ole"></a>Objetos e origens de dados (OLE)
Quando você executar uma transferência de dados, usando a área de transferência ou arrastar e soltar, os dados têm uma origem e um destino. Um aplicativo fornece os dados para copiar e outro aplicativo aceita para colá-lo. Cada lado da transferência precisa para executar operações diferentes nos mesmos dados para a transferência seja bem-sucedida. A biblioteca Microsoft Foundation Class (MFC) fornece duas classes que representam cada lado dessa transferência:  
  
-   Fontes de dados (conforme implementado pela `COleDataSource` objetos) representam o lado da transferência de dados de origem. Eles são criados pelo aplicativo de origem quando dados a serem copiados para a área de transferência ou quando dados são fornecidos para uma operação de arrastar e soltar.  
  
-   Objetos de dados (conforme implementado pela `COleDataObject` objetos) representam o lado de destino da transferência de dados. Elas são criadas quando o aplicativo de destino foi removidos para ele, ou quando ele é solicitado a executar uma operação de colagem da área de transferência de dados.  
  
 Os artigos a seguir explicam como usar objetos de dados e fontes de dados em seus aplicativos. Essas informações se aplicam a aplicativos de contêiner e servidor, porque ambos podem ser chamadas para copiar e colar dados.  
  
-   [Objetos e fontes de dados: criação e destruição](../mfc/data-objects-and-data-sources-creation-and-destruction.md)  
  
-   [Objetos e fontes de dados: manipulação](../mfc/data-objects-and-data-sources-manipulation.md)  
  
## <a name="in-this-section"></a>Nesta seção  
 [Arrastar e soltar](../mfc/drag-and-drop-ole.md)  
  
 [Área de transferência](../mfc/clipboard.md)  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Classe COleDataObject](../mfc/reference/coledataobject-class.md)   
 [Classe COleDataSource](../mfc/reference/coledatasource-class.md)
