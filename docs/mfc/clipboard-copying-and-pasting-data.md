---
title: 'Área de Transferência: copiando e colando dados'
ms.date: 11/04/2016
helpviewer_keywords:
- Clipboard, copying data to
- Clipboard, pasting
ms.assetid: 580e10be-241f-4f9f-94cf-8302edc5beef
ms.openlocfilehash: 74348dd3e790cceada9aafd718464694997316ed
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374562"
---
# <a name="clipboard-copying-and-pasting-data"></a>Área de Transferência: copiando e colando dados

Este tópico descreve o trabalho mínimo necessário para implementar a cópia e a cola da Área de Transferência em seu aplicativo OLE. Recomenda-se que você leia os [tópicos de Objetos de Dados e Fontes de Dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) antes de prosseguir.

Antes de implementar a cópia ou a colagem, você deve primeiro fornecer funções para lidar com as opções Copiar, Cortar e Colar no menu Editar.

## <a name="copying-or-cutting-data"></a><a name="_core_copying_or_cutting_data"></a>Copiando ou cortando dados

#### <a name="to-copy-data-to-the-clipboard"></a>Para copiar dados para a Área de Transferência

1. Determine se os dados a serem copiados são dados nativos ou se é um item incorporado ou vinculado.

   - Se os dados forem incorporados ou `COleClientItem` vinculados, obtenha um ponteiro para o objeto selecionado.

   - Se os dados forem nativos e o aplicativo for `COleServerItem` um servidor, crie um novo objeto derivado da contenção dos dados selecionados. Caso contrário, `COleDataSource` crie um objeto para os dados.

1. Ligue para a função `CopyToClipboard` membro do item selecionado.

1. Se o usuário escolheu uma operação Cortar em vez de uma operação Copiar, exclua os dados selecionados do seu aplicativo.

Para ver um exemplo desta `OnEditCut` seqüência, consulte as funções e `OnEditCopy` funções nos programas de amostra MFC OLE [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md). Observe que essas amostras mantêm um ponteiro para os dados selecionados no momento, então a etapa 1 já está completa.

## <a name="pasting-data"></a><a name="_core_pasting_data"></a>Colar dados

Colar dados é mais complicado do que copiá-los porque você precisa escolher o formato a ser usado na colagem dos dados em seu aplicativo.

#### <a name="to-paste-data-from-the-clipboard"></a>Para colar dados da Área de Transferência

1. Na sua classe `OnEditPaste` de exibição, implemente para lidar com os usuários escolhendo a opção Colar no menu Editar.

1. Na `OnEditPaste` função, crie `COleDataObject` um objeto `AttachClipboard` e chame sua função de membro para vincular esse objeto aos dados na Área de Transferência.

1. Ligue `COleDataObject::IsDataAvailable` para verificar se um determinado formato está disponível.

   Alternativamente, você `COleDataObject::BeginEnumFormats` pode usar para procurar outros formatos até encontrar um mais adequado para sua aplicação.

1. Executar a pasta do formato.

Para um exemplo de como isso funciona, consulte a implementação das funções do `OnEditPaste` membro nas classes de exibição definidas nos programas de amostra de OLE MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md).

> [!TIP]
> O principal benefício de separar a operação de colar em sua própria função é que o mesmo código de pasta pode ser usado quando os dados são descartados em seu aplicativo durante uma operação de arrastar e soltar. Como em OCLIENT e HIERSVR, `OnDrop` `DoPasteItem`sua função também pode chamar, reutilizando o código escrito para implementar operações de Colar.

Para lidar com a opção Colar especial no menu Editar, consulte o tópico [Caixas de Diálogo em OLE](../mfc/dialog-boxes-in-ole.md).

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)

- [Objetos de dados OLE e fontes de dados e transferência uniforme de dados](../mfc/data-objects-and-data-sources-ole.md)

- [Arrastar e soltar do OLE](../mfc/drag-and-drop-ole.md)

- [OLE](../mfc/ole-background.md)

## <a name="see-also"></a>Confira também

[Área de transferência: usando o mecanismo de área de transferência do OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)
