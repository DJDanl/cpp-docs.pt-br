---
title: 'Área de transferência: Copiando e colando dados | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Clipboard, copying data to
- Clipboard, pasting
ms.assetid: 580e10be-241f-4f9f-94cf-8302edc5beef
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8f4a3ba23fbf6e9465d78b04fcd79758c7cae525
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060217"
---
# <a name="clipboard-copying-and-pasting-data"></a>Área de Transferência: copiando e colando dados

Este tópico descreve o trabalho mínimo necessário para implementar para a cópia e colagem da área de transferência no aplicativo OLE. É recomendável que você leia as [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) tópicos antes de continuar.

Antes de implementar copiar ou colar, primeiro você deve fornecer funções para lidar com as opções de copiar, recortar e colar no menu Editar.

##  <a name="_core_copying_or_cutting_data"></a> Copiar ou recortar dados

#### <a name="to-copy-data-to-the-clipboard"></a>Para copiar dados para a área de transferência

1. Determine se os dados a serem copiados são dados nativos ou é um item vinculado ou inserido.

   - Se os dados são inseridos ou vinculados, obter um ponteiro para o `COleClientItem` objeto que foi selecionado.

   - Se os dados são nativos e o aplicativo for um servidor, crie um novo objeto derivado de `COleServerItem` que contém os dados selecionados. Caso contrário, crie um `COleDataSource` objeto para os dados.

1. Chame o item selecionado `CopyToClipboard` função de membro.

1. Se o usuário escolher uma operação Cut em vez de uma operação de cópia, exclua os dados selecionados do seu aplicativo.

Para ver um exemplo dessa sequência, consulte o `OnEditCut` e `OnEditCopy` programas de exemplo de funções na OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md). Observe que esses exemplos de mantenham um ponteiro para os dados selecionados no momento, portanto, a etapa 1 já foi concluída.

##  <a name="_core_pasting_data"></a> Colando dados

Colagem de dados é mais complicado do que copiá-lo porque você precisa escolher o formato a ser usado em Colar os dados em seu aplicativo.

#### <a name="to-paste-data-from-the-clipboard"></a>Para colar dados da área de transferência

1. Em sua classe de exibição, implementar `OnEditPaste` para lidar com os usuários a escolher a opção de colar no menu Editar.

1. No `OnEditPaste` funcionar, crie um `COleDataObject` objeto e chame seu `AttachClipboard` função de membro para vincular a esse objeto para os dados na área de transferência.

1. Chamar `COleDataObject::IsDataAvailable` para verificar se um determinado formato está disponível.

   Como alternativa, você pode usar `COleDataObject::BeginEnumFormats` para procurar outros formatos até encontrar uma mais adequado ao seu aplicativo.

1. Realize a colagem no formato.

Para obter um exemplo de como isso funciona, consulte a implementação de `OnEditPaste` funções de membro nas classes de exibição definidas nos programas de exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md).

> [!TIP]
>  O principal benefício de separar a operação de colagem para sua própria função é que o mesmo código de colar pode ser usado quando dados são soltos em seu aplicativo durante uma operação de arrastar e soltar. Como na, OCLIENT e HIERSVR, suas `OnDrop` também pode chamar a função `DoPasteItem`, reutilizar o código escrito para implementar operações de colagem.

Para lidar com a opção Colar especial no menu Editar, consulte o tópico [caixas de diálogo em OLE](../mfc/dialog-boxes-in-ole.md).

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)

- [Transferência de dados uniformes e fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-ole.md)

- [Arrastar e soltar OLE](../mfc/drag-and-drop-ole.md)

- [OLE](../mfc/ole-background.md)

## <a name="see-also"></a>Consulte também

[Área de transferência: usando o mecanismo de área de transferência do OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

