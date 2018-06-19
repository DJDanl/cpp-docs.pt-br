---
title: Arrastar e soltar (OLE) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE server applications [MFC], drag and drop
- drag and drop [MFC]
- OLE applications [MFC], drag and drop
- File Manager drag and drop support [MFC]
- drag and drop [MFC], about OLE drag and drop
- OLE drag and drop [MFC]
ms.assetid: a4595350-ca06-4400-88a1-f0175c76b77b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cc23c7695bf5afa22734c382ddc72e8418ff74c5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344325"
---
# <a name="drag-and-drop-ole"></a>Arrastar e soltar (OLE)
O recurso de arrastar e soltar do OLE é principalmente um atalho para copiar e colar dados. Quando você usar a área de transferência para copiar ou colar dados, várias etapas são necessárias. Selecione os dados, clique em **Recortar** ou **cópia** do **editar** menu, vá para o arquivo de destino, a janela ou aplicativo, coloque o cursor no local desejado e clique em **Colar** do **editar** menu.  
  
 Arrastar e soltar OLE é diferente do que o mecanismo de arrastar e soltar do Gerenciador de arquivos, que pode lidar somente com nomes de arquivo e foi desenvolvido especificamente para passar os nomes de arquivos para aplicativos. Arrastar e soltar OLE é muito mais geral. Ele permite que você arrastar e soltar os dados que também podem ser colocados na área de transferência.  
  
 Quando você usar o arrastar e soltar OLE, você remover duas etapas do processo. Selecione os dados na janela de origem (a "origem soltar"), arraste-o para o destino desejado (o "destino") e solte-soltando o botão do mouse. A operação elimina a necessidade de menus e é mais rápida do que a sequência de copiar/colar. O único requisito é que a origem para soltar e o destino de soltar devem ser aberta e pelo menos parcialmente visível na tela.  
  
 Usando o OLE arrastar e soltar, os dados podem ser transferidos de um local para outro dentro de um documento, entre documentos diferentes ou entre aplicativos. Ele pode ser implementado em um contêiner ou um aplicativo de servidor e qualquer aplicativo pode ser uma origem para soltar, um destino ou ambos. Se um aplicativo tem suporte de descarte de origem e destino de soltar implementado, arrastar e soltar é habilitado entre janelas filho ou em uma janela. Esse recurso pode tornar seu aplicativo mais fácil usar.  
  
 Se você quiser usar os recursos de arrastar e soltar do OLE, consulte [arrastar e soltar: Personalizando](../mfc/drag-and-drop-customizing.md). Você pode usar as técnicas explicadas no artigo para fazer com que aplicativos OLE não remover fontes. O artigo [arrastar e soltar: Implementando um destino de soltar](../mfc/drag-and-drop-implementing-a-drop-target.md) descreve como implementar o suporte de destino de soltar para OLE e aplicativos não-OLE. Também será útil examinar os exemplos de OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md).  
  
 Se você não leu o [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) família de artigos, talvez você queira fazer isso agora. Esses artigos explicam os conceitos básicos de transferência de dados e como implementá-la em seus aplicativos.  
  
 Para obter mais informações sobre como arrastar e soltar, consulte:  
  
-   [Arrastar e soltar: implementando uma origem para soltar](../mfc/drag-and-drop-implementing-a-drop-source.md)  
  
-   [Arrastar e soltar: implementando um destino para soltar](../mfc/drag-and-drop-implementing-a-drop-target.md)  
  
-   [Arrastar e soltar: personalizando](../mfc/drag-and-drop-customizing.md)  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Objetos e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)

