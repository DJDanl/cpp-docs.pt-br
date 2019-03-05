---
title: 'Área de transferência: Adicionando outros formatos'
ms.date: 11/04/2016
helpviewer_keywords:
- formats [MFC], Clipboard
- Clipboard, formats
- custom formats, placing on Clipboard
- custom formats
- registering custom Clipboard data formats
- custom Clipboard data formats
ms.assetid: aea58159-65ed-4385-aeaa-3d9d5281903b
ms.openlocfilehash: 16e949973ff621b1e4e36475d95763ac47b4a00d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57280212"
---
# <a name="clipboard-adding-other-formats"></a>Área de transferência: Adicionando outros formatos

Este tópico explica como expandir a lista de formatos com suporte, principalmente para suporte ao OLE. O tópico [na área de transferência: Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md) descreve a implementação mínima necessária para oferecer suporte a cópia e colagem da área de transferência. Se isso é tudo o que você implemente, os únicos formatos colocados na área de transferência são **CF_METAFILEPICT**, **CF_EMBEDSOURCE**, **CF_OBJECTDESCRIPTOR**e possivelmente **CF_LINKSOURCE**. A maioria dos aplicativos será necessário mais formatos na área de transferência que esses três.

##  <a name="_core_registering_custom_formats"></a> Formatos de registro personalizado

Para criar seus próprios formatos personalizados, siga o mesmo procedimento que você usaria ao registrar qualquer formato de área de transferência personalizado: passe o nome do formato para o **RegisterClipboardFormat** funcionar e usar seu valor de retorno como a ID de formato.

##  <a name="_core_placing_formats_on_the_clipboard"></a> Colocar formatos na área de transferência

Para adicionar mais formatos para aqueles colocados na área de transferência, você deve substituir a `OnGetClipboardData` função na classe derivada de uma `COleClientItem` ou `COleServerItem` (dependendo se os dados a serem copiados estão nativos). Nessa função, você deve usar o procedimento a seguir.

#### <a name="to-place-formats-on-the-clipboard"></a>Para colocar formatos na área de transferência

1. Crie um objeto `COleDataSource`.

1. Passar essa fonte de dados para uma função que adiciona seus formatos de dados nativos à lista de formatos com suporte por meio da chamada `COleDataSource::CacheGlobalData`.

1. Adicionar formatos padrão chamando `COleDataSource::CacheGlobalData` para cada formato padrão que você deseja dar suporte.

Essa técnica é usada no programa de exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md) (examinar o `OnGetClipboardData` função de membro de **CServerItem** classe). A única diferença neste exemplo é que a etapa três não é implementada como HIERSVR dá suporte a nenhum outro formato padrão.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Transferência de dados uniformes e fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-ole.md)

- [Arrastar e soltar OLE](../mfc/drag-and-drop-ole.md)

- [OLE](../mfc/ole-background.md)

## <a name="see-also"></a>Consulte também

[Área de transferência: Usando o mecanismo de área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)
