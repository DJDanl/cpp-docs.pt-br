---
title: Objetos e origens de dados (OLE)
ms.date: 11/04/2016
helpviewer_keywords:
- data objects [MFC], definition
- data transfer [MFC]
- OLE [MFC], data transfer
- data sources [MFC], definition
- data transfer [MFC], definition
- OLE [MFC], data objects
- OLE [MFC], data sources
ms.assetid: 8f68eed8-0ce8-4489-a4cc-f95554f89090
ms.openlocfilehash: 09e328171657c3c6557a5d77acae0f034e517955
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612479"
---
# <a name="data-objects-and-data-sources-ole"></a>Objetos e origens de dados (OLE)

Quando você executa uma transferência de dados usando a área de transferência ou arrastar e soltar, os dados têm uma origem e um destino. Um aplicativo fornece os dados para copiar e outro aplicativo aceita-la para colá-lo. Cada lado da transferência precisa para executar operações diferentes nos mesmos dados para a transferência seja bem-sucedida. A biblioteca Microsoft Foundation Class (MFC) oferece duas classes que representam cada lado dessa transferência:

- Fontes de dados (conforme implementado pela `COleDataSource` objetos) representam o lado da transferência de dados de origem. Eles são criados pelo aplicativo de origem quando dados deve ser copiada na área de transferência, ou quando dados são fornecidos para uma operação de arrastar e soltar.

- Objetos de dados (conforme implementado pela `COleDataObject` objetos) representam o lado de destino da transferência de dados. Eles são criados quando o aplicativo de destino tem dados que foram soltos nele, ou quando ele é solicitado a executar uma operação de colagem da área de transferência.

Os artigos a seguir explicam como usar objetos de dados e fontes de dados em seus aplicativos. Essas informações se aplicam a aplicativos de contêiner e o servidor, pois ambos podem ser abertas em copiar e colar dados.

- [Objetos e fontes de dados: criação e destruição](../mfc/data-objects-and-data-sources-creation-and-destruction.md)

- [Objetos e fontes de dados: manipulação](../mfc/data-objects-and-data-sources-manipulation.md)

## <a name="in-this-section"></a>Nesta seção

[Arrastar e soltar](../mfc/drag-and-drop-ole.md)

[Área de transferência](../mfc/clipboard.md)

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Classe COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
[Classe COleDataSource](../mfc/reference/coledatasource-class.md)
