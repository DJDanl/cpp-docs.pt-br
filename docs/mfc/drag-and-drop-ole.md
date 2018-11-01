---
title: Arrastar e soltar (OLE)
ms.date: 11/04/2016
helpviewer_keywords:
- OLE server applications [MFC], drag and drop
- drag and drop [MFC]
- OLE applications [MFC], drag and drop
- File Manager drag and drop support [MFC]
- drag and drop [MFC], about OLE drag and drop
- OLE drag and drop [MFC]
ms.assetid: a4595350-ca06-4400-88a1-f0175c76b77b
ms.openlocfilehash: 956c746d6eef84edd7be3ab9b6c6d15107269b1c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50450343"
---
# <a name="drag-and-drop-ole"></a>Arrastar e soltar (OLE)

O recurso de arrastar e soltar do OLE é principalmente um atalho para copiar e colar os dados. Quando você usa a área de transferência para copiar ou colar dados, uma série de etapas é necessária. Selecione os dados, clique em **Recortar** ou **cópia** do **editar** menu, vá para o arquivo de destino, a janela ou o aplicativo, coloque o cursor no local desejado e clique em **Colar** da **editar** menu.

Arrastar e soltar OLE é diferente do que o mecanismo de arrastar e soltar do Gerenciador de arquivos, que pode lidar somente com nomes de arquivo e foi projetado especificamente para passar os nomes de arquivo para aplicativos. Arrastar e soltar OLE é muito mais geral. Ele permite que você arraste e solte a todos os dados que também poderia ser colocados na área de transferência.

Quando você usa o arrastar e soltar OLE, você remove duas etapas do processo. Selecione os dados na janela de origem (a "origem de soltar"), arraste-o para o destino desejado (o "soltar") e solte-o ao liberar o botão do mouse. A operação elimina a necessidade de menus e é mais rápida do que a sequência de copiar/colar. O único requisito é que a origem de soltar e o destino de soltar devem estar aberta e pelo menos parcialmente visível na tela.

Usando o OLE arrastar e soltar, os dados podem ser transferidos de um local para outro dentro de um documento, entre documentos diferentes ou entre aplicativos. Ele pode ser implementado em um contêiner ou um aplicativo de servidor e qualquer aplicativo pode ser uma origem para soltar, um destino de soltar ou ambos. Se um aplicativo tiver suporte a origem de soltar e o destino de soltar implementado, arrastar e soltar está habilitada entre janelas filho, ou em uma janela. Esse recurso pode tornar seu aplicativo muito mais fácil de usar.

Se você quiser usar os recursos de arrastar e soltar do OLE, consulte [arrastar e soltar: Personalizando](../mfc/drag-and-drop-customizing.md). Você pode usar as técnicas explicadas neste artigo para fazer com que aplicativos não são OLE remover fontes. O artigo [arrastar e soltar: Implementando um destino de soltar](../mfc/drag-and-drop-implementing-a-drop-target.md) descreve como implementar o suporte de destino de soltar para OLE e aplicativos não são OLE. Também será útil examinar os exemplos de OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md).

Se você não leu a [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) família de artigos, você talvez queira fazer isso agora. Estes artigos explicam os conceitos básicos da transferência de dados e como implementá-lo em seus aplicativos.

Para obter mais informações sobre como arrastar e soltar, consulte:

- [Arrastar e soltar: implementando uma origem para soltar](../mfc/drag-and-drop-implementing-a-drop-source.md)

- [Arrastar e soltar: implementando um destino para soltar](../mfc/drag-and-drop-implementing-a-drop-target.md)

- [Arrastar e soltar: personalizando](../mfc/drag-and-drop-customizing.md)

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Objetos e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)

