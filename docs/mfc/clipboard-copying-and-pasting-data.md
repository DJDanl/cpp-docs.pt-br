---
title: 'Área de Transferência: copiando e colando dados'
ms.date: 11/04/2016
helpviewer_keywords:
- Clipboard, copying data to
- Clipboard, pasting
ms.assetid: 580e10be-241f-4f9f-94cf-8302edc5beef
ms.openlocfilehash: ed3056ec4fb3d3098870a03522d3bf17f41fbe34
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620701"
---
# <a name="clipboard-copying-and-pasting-data"></a>Área de Transferência: copiando e colando dados

Este tópico descreve o trabalho mínimo necessário para implementar a cópia e a colagem da área de transferência em seu aplicativo OLE. É recomendável que você leia os tópicos de [objetos de dados e fontes de dados (OLE)](data-objects-and-data-sources-ole.md) antes de continuar.

Antes de implementar a cópia ou colagem, você deve primeiro fornecer funções para manipular as opções de copiar, recortar e colar no menu Editar.

## <a name="copying-or-cutting-data"></a><a name="_core_copying_or_cutting_data"></a>Copiando ou recortando dados

#### <a name="to-copy-data-to-the-clipboard"></a>Para copiar dados para a área de transferência

1. Determine se os dados a serem copiados são dados nativos ou se são um item inserido ou vinculado.

   - Se os dados forem inseridos ou vinculados, obtenha um ponteiro para o `COleClientItem` objeto que foi selecionado.

   - Se os dados forem nativos e o aplicativo for um servidor, crie um novo objeto derivado de `COleServerItem` contendo os dados selecionados. Caso contrário, crie um `COleDataSource` objeto para os dados.

1. Chame a função de membro do item selecionado `CopyToClipboard` .

1. Se o usuário escolher uma operação de recorte em vez de uma operação de cópia, exclua os dados selecionados do seu aplicativo.

Para ver um exemplo dessa sequência, consulte as `OnEditCut` funções e `OnEditCopy` nos programas de exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md). Observe que esses exemplos mantêm um ponteiro para os dados atualmente selecionados, portanto, a etapa 1 já está concluída.

## <a name="pasting-data"></a><a name="_core_pasting_data"></a>Colando dados

Colar dados é mais complicado do que copiá-los porque você precisa escolher o formato a ser usado para colar os dados em seu aplicativo.

#### <a name="to-paste-data-from-the-clipboard"></a>Para colar dados da área de transferência

1. Em sua classe de exibição, implemente `OnEditPaste` para lidar com usuários escolhendo a opção colar no menu Editar.

1. Na `OnEditPaste` função, crie um `COleDataObject` objeto e chame sua `AttachClipboard` função de membro para vincular esse objeto aos dados na área de transferência.

1. Chame `COleDataObject::IsDataAvailable` para verificar se um determinado formato está disponível.

   Como alternativa, você pode usar `COleDataObject::BeginEnumFormats` o para procurar outros formatos até encontrar um mais adequado ao seu aplicativo.

1. Execute a colagem do formato.

Para obter um exemplo de como isso funciona, consulte a implementação das `OnEditPaste` funções de membro nas classes de exibição definidas nos programas de exemplo OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md).

> [!TIP]
> O principal benefício de separar a operação de colar em sua própria função é que o mesmo código de colagem pode ser usado quando os dados são descartados em seu aplicativo durante uma operação de arrastar e soltar. Como em OCLIENT e HIERSVR, sua `OnDrop` função também pode chamar `DoPasteItem` , reutilizando o código escrito para implementar operações de colagem.

Para manipular a opção Colar especial no menu Editar, consulte as caixas de [diálogo de tópico em OLE](dialog-boxes-in-ole.md).

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Adicionando outros formatos](clipboard-adding-other-formats.md)

- [Objetos de dados OLE e fontes de dados e transferência de dados uniforme](data-objects-and-data-sources-ole.md)

- [Arrastar e soltar do OLE](drag-and-drop-ole.md)

- [OLE](ole-background.md)

## <a name="see-also"></a>Consulte também

[Área de transferência: usando o mecanismo de área de transferência do OLE](clipboard-using-the-ole-clipboard-mechanism.md)
