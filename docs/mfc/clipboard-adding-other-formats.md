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
ms.openlocfilehash: 52089364a6be423c69a7031cd0d99e1924de1444
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626072"
---
# <a name="clipboard-adding-other-formats"></a>Área de Transferência: adicionando outros formatos

Este tópico explica como expandir a lista de formatos com suporte, especialmente para o suporte a OLE. O tópico [área de transferência: copiar e colar dados](clipboard-copying-and-pasting-data.md) descreve a implementação mínima necessária para dar suporte à cópia e colagem da área de transferência. Se isso for tudo o que você implementar, os únicos formatos colocados na área de transferência serão **CF_METAFILEPICT**, **CF_EMBEDSOURCE**, **CF_OBJECTDESCRIPTOR**e possivelmente **CF_LINKSOURCE**. A maioria dos aplicativos precisará de mais formatos na área de transferência do que esses três.

## <a name="registering-custom-formats"></a><a name="_core_registering_custom_formats"></a>Registrando formatos personalizados

Para criar seus próprios formatos personalizados, siga o mesmo procedimento que você usaria ao registrar qualquer formato de área de transferência personalizado: passe o nome do formato para a função **RegisterClipboardFormat** e use seu valor de retorno como a ID de formato.

## <a name="placing-formats-on-the-clipboard"></a><a name="_core_placing_formats_on_the_clipboard"></a>Colocando formatos na área de transferência

Para adicionar mais formatos àqueles colocados na área de transferência, você deve substituir a `OnGetClipboardData` função na classe derivada de um `COleClientItem` ou `COleServerItem` (dependendo se os dados a serem copiados são nativos). Nessa função, você deve usar o procedimento a seguir.

#### <a name="to-place-formats-on-the-clipboard"></a>Para posicionar formatos na área de transferência

1. Crie um objeto `COleDataSource`.

1. Passe essa fonte de dados para uma função que adiciona seus formatos de dados nativos à lista de formatos com suporte chamando `COleDataSource::CacheGlobalData` .

1. Adicione formatos padrão chamando `COleDataSource::CacheGlobalData` para cada formato padrão ao qual você deseja dar suporte.

Essa técnica é usada no programa de exemplo OLE do MFC [HIERSVR](../overview/visual-cpp-samples.md) (examine a `OnGetClipboardData` função membro da classe **CServerItem** ). A única diferença nesse exemplo é que a etapa três não é implementada porque o HIERSVR não dá suporte a nenhum outro formato padrão.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Objetos de dados OLE e fontes de dados e transferência de dados uniforme](data-objects-and-data-sources-ole.md)

- [Arrastar e soltar do OLE](drag-and-drop-ole.md)

- [OLE](ole-background.md)

## <a name="see-also"></a>Consulte também

[Área de transferência: usando o mecanismo de área de transferência do OLE](clipboard-using-the-ole-clipboard-mechanism.md)
