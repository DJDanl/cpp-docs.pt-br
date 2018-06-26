---
title: 'Área de transferência: Adicionando outros formatos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- formats [MFC], Clipboard
- Clipboard, formats
- custom formats, placing on Clipboard
- custom formats
- registering custom Clipboard data formats
- custom Clipboard data formats
ms.assetid: aea58159-65ed-4385-aeaa-3d9d5281903b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 67004ac43193d47720626da241a8030ba396abdf
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36932011"
---
# <a name="clipboard-adding-other-formats"></a>Área de Transferência: adicionando outros formatos
Este tópico explica como expandir a lista de formatos com suporte, principalmente para suporte OLE. O tópico [área de transferência: copiar e colar dados](../mfc/clipboard-copying-and-pasting-data.md) descreve a implementação mínimo necessária para dar suporte a copiar e colar da área de transferência. Se isso é tudo o que você implementar, são os únicos formatos colocados na área de transferência **CF_METAFILEPICT**, **CF_EMBEDSOURCE**, **CF_OBJECTDESCRIPTOR**e possivelmente **CF_LINKSOURCE**. A maioria dos aplicativos será necessário mais formatos na área de transferência que esses três.  
  
##  <a name="_core_registering_custom_formats"></a> Formatos de registro personalizadas  
 Para criar formatos personalizados, siga o mesmo procedimento, você usaria ao registrar qualquer formato personalizado de área de transferência: passe o nome do formato para o **RegisterClipboardFormat** de função e usar seu valor de retorno como a ID de formato.  
  
##  <a name="_core_placing_formats_on_the_clipboard"></a> Colocar formatos na área de transferência  
 Para adicionar mais formatos às colocado na área de transferência, você deve substituir o `OnGetClipboardData` função na classe derivada do `COleClientItem` ou `COleServerItem` (dependendo se os dados a serem copiados são nativo). Nessa função, você deve usar o procedimento a seguir.  
  
#### <a name="to-place-formats-on-the-clipboard"></a>Para colocar formatos na área de transferência  
  
1.  Crie um objeto `COleDataSource`.  
  
2.  Passar essa fonte de dados para uma função que adiciona seus formatos de dados nativos à lista de formatos com suporte ao chamar `COleDataSource::CacheGlobalData`.  
  
3.  Adicionar os formatos padrão chamando `COleDataSource::CacheGlobalData` para cada formato padrão que você deseja dar suporte.  
  
 Essa técnica é usada no programa de exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md) (examinar o `OnGetClipboardData` função de membro de **CServerItem** classe). A única diferença neste exemplo é a etapa três não é implementada como HIERSVR oferece suporte a nenhum outro formato padrão.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Transferência de dados uniformes e fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-ole.md)  
  
-   [Arrastar e soltar OLE](../mfc/drag-and-drop-ole.md)  
  
-   [OLE](../mfc/ole-background.md)  
  
## <a name="see-also"></a>Consulte também  
 [Área de transferência: usando o mecanismo de área de transferência do OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

