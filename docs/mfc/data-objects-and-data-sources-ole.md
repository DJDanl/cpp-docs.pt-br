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
ms.openlocfilehash: dfe400dddfecce3e52337f7f449e975dff2ca83e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616213"
---
# <a name="data-objects-and-data-sources-ole"></a>Objetos e origens de dados (OLE)

Quando você executa uma transferência de dados, seja usando a área de transferência ou arrastando e solta, os dados têm uma origem e um destino. Um aplicativo fornece os dados para cópia e outro aplicativo o aceita para colar. Cada lado da transferência precisa executar operações diferentes nos mesmos dados para que a transferência seja realizada com sucesso. A biblioteca do Microsoft Foundation Class (MFC) fornece duas classes que representam cada lado desta transferência:

- As fontes de dados (conforme implementadas por `COleDataSource` objetos) representam o lado da origem da transferência de dados. Eles são criados pelo aplicativo de origem quando os dados devem ser copiados para a área de transferência ou quando os dados são fornecidos para uma operação de arrastar e soltar.

- Os objetos de dados (conforme implementados por `COleDataObject` objetos) representam o lado de destino da transferência de dados. Eles são criados quando o aplicativo de destino tem dados inseridos nele, ou quando é solicitado a executar uma operação de colagem na área de transferência.

Os artigos a seguir explicam como usar objetos de dados e fontes de dados em seus aplicativos. Essas informações se aplicam a aplicativos de contêiner e de servidor, porque ambos podem ser chamados para copiar e colar dados.

- [Objetos e fontes de dados: criação e destruição](data-objects-and-data-sources-creation-and-destruction.md)

- [Objetos e fontes de dados: manipulação](data-objects-and-data-sources-manipulation.md)

## <a name="in-this-section"></a>Nesta seção

[Arrastar e soltar](drag-and-drop-ole.md)

[Área de transferência](clipboard.md)

## <a name="see-also"></a>Consulte também

[OLE](ole-in-mfc.md)<br/>
[Classe COleDataObject](reference/coledataobject-class.md)<br/>
[Classe COleDataSource](reference/coledatasource-class.md)
