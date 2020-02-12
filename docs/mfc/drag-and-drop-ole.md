---
title: arrastar e soltar OLE
description: Visão geral de arrastar e soltar de MFC (MFC), como implementar uma fonte de soltar, um destino de soltar e como personalizar o recurso de arrastar e soltar.
ms.date: 02/09/2020
helpviewer_keywords:
- OLE server applications [MFC], drag and drop
- drag and drop [MFC]
- OLE applications [MFC], drag and drop
- File Manager drag and drop support [MFC]
- drag and drop [MFC], about OLE drag and drop
- OLE drag and drop [MFC]
ms.assetid: a4595350-ca06-4400-88a1-f0175c76b77b
ms.openlocfilehash: c601e8f0324510346513dc8da48dd1a83c95bceb
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127862"
---
# <a name="ole-drag-and-drop"></a>arrastar e soltar OLE

O recurso de arrastar e soltar do OLE é, principalmente, um atalho para copiar e colar dados. Quando você usa a área de transferência para copiar ou colar dados, várias etapas são necessárias. Você seleciona os dados e escolhe **recortar** ou **copiar** no menu **Editar** . Em seguida, você passa para o aplicativo ou a janela de destino e coloca o cursor no local de destino. Por fim, escolha **editar** > **colar** no menu.

O recurso de arrastar e soltar OLE é diferente do mecanismo de arrastar e soltar do Gerenciador de arquivos. O Gerenciador de arquivos só pode manipular nomes de arquivo e é projetado especificamente para passar nomes de arquivos para aplicativos. Arrastar e soltar em OLE é muito mais geral. Ele permite que você arraste e solte todos os dados que também podem ser colocados na área de transferência.

Ao usar o recurso arrastar e soltar OLE, você remove duas etapas do processo. Você seleciona os dados na janela de origem ("soltar origem") e, em seguida, arrasta-os para o destino ("soltar destino"). Você o solta ao soltar o botão do mouse. A operação elimina a necessidade de menus e é mais rápida do que a sequência de copiar/colar. Há apenas um requisito: a origem e o destino de soltar devem estar abertos e, pelo menos, parcialmente visíveis na tela.

Usando o recurso arrastar e soltar OLE, os dados podem ser transferidos facilmente de um local para outro: dentro de um documento, entre diferentes documentos ou entre aplicativos. Ele pode ser implementado em um contêiner ou em um aplicativo de servidor. Qualquer aplicativo pode ser uma origem, um destino de soltar ou ambos. Se um aplicativo implementar o suporte a drop-Source e o destino, você poderá arrastar e soltar entre janelas filhas ou dentro de uma janela. Esse recurso torna seu aplicativo muito mais fácil de usar.

Os artigos sobre [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) explicam como implementar a transferência de dados em seus aplicativos. Também é útil examinar os exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md).

## <a name="implement-a-drop-source"></a>Implementar uma origem de remoção

Para fazer com que seu aplicativo forneça dados a uma operação de arrastar e soltar, você implementa uma fonte de soltar. A implementação básica de uma fonte de descarte é relativamente simples. A primeira etapa é determinar quais eventos iniciam uma operação de arrastar. As diretrizes de interface do usuário recomendadas definem o início de uma operação de arrastar como quando um evento **WM_LBUTTONDOWN** ocorre em um ponto dentro de alguns dados selecionados. Os exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md) seguem estas diretrizes.

Se seu aplicativo for um contêiner e os dados selecionados forem um objeto vinculado ou inserido do tipo `COleClientItem`, chame sua função de membro `DoDragDrop`. Caso contrário, construa um objeto `COleDataSource`, inicialize-o com a seleção e chame a função de membro `DoDragDrop` do objeto de fonte de dados. Se seu aplicativo for um servidor, use `COleServerItem::DoDragDrop`. Para obter informações sobre como personalizar o comportamento padrão do tipo "arrastar e soltar", consulte a seção [Personalizar arrastar e soltar](#customize-drag-and-drop).

Se `DoDragDrop` retornar **DROPEFFECT_MOVE**, exclua os dados de origem do documento de origem imediatamente. Nenhum outro valor de retorno de `DoDragDrop` tem efeito em uma origem de descarte.

Para obter mais informações, consulte [objetos de dados OLE e fontes de dados: criação e destruição](../mfc/data-objects-and-data-sources-creation-and-destruction.md) e [fontes de dados e objetos de dados ole: manipulação](../mfc/data-objects-and-data-sources-manipulation.md)\.

## <a name="implement-a-drop-target"></a>Implementar um destino de soltura

Leva um pouco mais de trabalho para implementar um destino de soltar do que uma fonte de soltar, mas ainda é relativamente simples.

### <a name="to-implement-an-ole-drop-target"></a>Para implementar um destino OLE drop

1. Se ainda não estiver lá, adicione uma chamada para `AfxOleInit` na função de membro `InitInstance` do seu aplicativo. Essa chamada é necessária para inicializar as bibliotecas OLE.

1. Adicione uma variável de membro a cada exibição no aplicativo que você deseja que seja um destino de soltura. Essa variável de membro deve ser do tipo `COleDropTarget` ou uma classe derivada dela.

1. Da função da classe View que manipula a mensagem de **WM_CREATE** (normalmente `OnCreate`), chame a função de membro `Register` nova variável de membro. `Revoke` será chamado automaticamente quando a exibição for destruída.

1. Substitua as funções a seguir. Se você quiser o mesmo comportamento em todo o aplicativo, substitua essas funções em sua classe View. Se você quiser modificar o comportamento em casos isolados ou desejar habilitar o descarte em janelas não`CView`, substitua essas funções em sua classe derivada de `COleDropTarget`.

   | Substituições | Para permitir |
   | -------- | -------- |
   | `OnDragEnter` | Descartar operações para ocorrer na janela. Chamado quando o cursor entra pela primeira vez na janela. |
   | `OnDragLeave` | Comportamento especial quando a operação de arrastar deixa a janela especificada. |
   | `OnDragOver` | Descartar operações para ocorrer na janela. Chamado quando o cursor está sendo arrastado pela janela. |
   | `OnDrop` | Manipulação de dados sendo retirados na janela especificada. |
   | `OnScrollBy` | Comportamento especial para o momento em que a rolagem é necessário na janela de destino. |

Consulte o MAINVIEW. O arquivo CPP que faz parte do exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) para obter um exemplo de como essas funções funcionam em conjunto.

Para obter mais informações, consulte [objetos de dados OLE e fontes de dados: criação e destruição](../mfc/data-objects-and-data-sources-creation-and-destruction.md) e [fontes de dados e objetos de dados ole: manipulação](../mfc/data-objects-and-data-sources-manipulation.md)\.

## <a name="customize-drag-and-drop"></a>Personalizar arrastar e soltar

A implementação padrão do recurso de arrastar e soltar é suficiente para a maioria dos aplicativos. No entanto, alguns aplicativos podem exigir que você altere esse comportamento padrão. Esta seção explica as etapas necessárias para alterar esses padrões. Você pode usar essa técnica para criar aplicativos que não dão suporte a documentos compostos em fontes drop.

Se você estiver personalizando o comportamento de arrastar e soltar OLE padrão, ou se tiver um aplicativo não OLE, deverá criar um objeto de `COleDataSource` para conter os dados. Quando o usuário inicia uma operação de arrastar e soltar, seu código deve chamar a função `DoDragDrop` desse objeto em vez de outras classes que dão suporte a operações de arrastar e soltar.

Opcionalmente, você pode criar um objeto `COleDropSource` para controlar a queda e substituir algumas de suas funções, dependendo do tipo de comportamento que você deseja alterar. Esse objeto drop-Source é passado para `COleDataSource::DoDragDrop` para alterar o comportamento padrão dessas funções. Essas diferentes opções permitem uma grande flexibilidade na forma como você dá suporte a operações de arrastar e soltar em seu aplicativo. Para obter mais informações sobre fontes de dados, consulte o artigo [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md).

Você pode substituir as seguintes funções para personalizar as operações de arrastar e soltar:

| Substituições | Para personalizar |
| -------- | ------------ |
| `OnBeginDrag` | Como a operação de arrastar começa depois que você chama `DoDragDrop`. |
| `GiveFeedback` | Comentários visuais, como a aparência do cursor, para resultados de drop diferentes. |
| `QueryContinueDrag` | O encerramento de uma operação de arrastar e soltar. Essa função permite que você verifique os Estados de chave do modificador durante a operação de arrastar. |

## <a name="see-also"></a>Consulte também

\ [OLE](../mfc/ole-in-mfc.md)
[Objetos de dados OLE e fontes de dados](../mfc/data-objects-and-data-sources-ole.md)\
[Objetos de dados OLE e fontes de dados: criação e destruição](../mfc/data-objects-and-data-sources-creation-and-destruction.md)\
[Objetos de dados OLE e fontes de dados: manipulação](../mfc/data-objects-and-data-sources-manipulation.md)\
[COleClientItem::D odragdrop](../mfc/reference/coleclientitem-class.md#dodragdrop)\
\ [classe COleDataSource](../mfc/reference/coledatasource-class.md)
[COleDataSource::D odragdrop](../mfc/reference/coledatasource-class.md#dodragdrop)\
\ [classe COleDropSource](../mfc/reference/coledropsource-class.md)
\ [classe COleDropTarget](../mfc/reference/coledroptarget-class.md)
[Cvisualização:: OnDragLeave](../mfc/reference/cview-class.md#ondragleave)
