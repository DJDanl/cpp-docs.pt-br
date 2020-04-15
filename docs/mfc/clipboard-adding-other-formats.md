---
title: 'Área de Transferência: adicionando outros formatos'
ms.date: 11/04/2016
helpviewer_keywords:
- formats [MFC], Clipboard
- Clipboard, formats
- custom formats, placing on Clipboard
- custom formats
- registering custom Clipboard data formats
- custom Clipboard data formats
ms.assetid: aea58159-65ed-4385-aeaa-3d9d5281903b
ms.openlocfilehash: 6f4e159cc1b6918843d4a164dcca88500eb7b038
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374599"
---
# <a name="clipboard-adding-other-formats"></a>Área de Transferência: adicionando outros formatos

Este tópico explica como expandir a lista de formatos suportados, particularmente para suporte ao OLE. O tópico [Área de transferência: Copiar e colar dados](../mfc/clipboard-copying-and-pasting-data.md) descreve a implementação mínima necessária para suportar a cópia e a colagem da Área de Transferência. Se isso for tudo o que você implementa, os únicos formatos colocados na Área de Transferência são **CF_METAFILEPICT,** **CF_EMBEDSOURCE,** **CF_OBJECTDESCRIPTOR**e possivelmente **CF_LINKSOURCE**. A maioria dos aplicativos precisará de mais formatos na Área de Transferência do que estes três.

## <a name="registering-custom-formats"></a><a name="_core_registering_custom_formats"></a>Registrando formatos personalizados

Para criar seus próprios formatos personalizados, siga o mesmo procedimento que você usaria ao registrar qualquer formato de área de transferência personalizada: passe o nome do formato para a função **RegisterClipboardFormat** e use seu valor de retorno como iD de formato.

## <a name="placing-formats-on-the-clipboard"></a><a name="_core_placing_formats_on_the_clipboard"></a>Colocando formatos na área de transferência

Para adicionar mais formatos aos colocados na Área `OnGetClipboardData` de Transferência, você deve `COleClientItem` substituir `COleServerItem` a função na classe de que você derivava de qualquer um ou (dependendo se os dados a serem copiados são nativos). Nesta função, você deve usar o seguinte procedimento.

#### <a name="to-place-formats-on-the-clipboard"></a>Para colocar formatos na área de transferência

1. Crie um objeto `COleDataSource`.

1. Passe essa fonte de dados para uma função que adiciona seus formatos `COleDataSource::CacheGlobalData`de dados nativos à lista de formatos suportados por chamada .

1. Adicione formatos padrão `COleDataSource::CacheGlobalData` chamando para cada formato padrão que você deseja suportar.

Esta técnica é usada no programa de amostra MFC `OnGetClipboardData` OLE [HIERSVR](../overview/visual-cpp-samples.md) (examine a função membro da classe **CServerItem).** A única diferença nesta amostra é que a terceira etapa não é implementada porque o HIERSVR não suporta outros formatos padrão.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Objetos de dados OLE e fontes de dados e transferência uniforme de dados](../mfc/data-objects-and-data-sources-ole.md)

- [Arrastar e soltar do OLE](../mfc/drag-and-drop-ole.md)

- [OLE](../mfc/ole-background.md)

## <a name="see-also"></a>Confira também

[Área de transferência: usando o mecanismo de área de transferência do OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)
