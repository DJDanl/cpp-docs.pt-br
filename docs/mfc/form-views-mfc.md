---
title: Formulário de exibições (MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- user interfaces [MFC], forms
- forms [MFC]
- applications [MFC], forms-based
- forms-based applications [MFC]
- forms [MFC], adding to applications
ms.assetid: efbe73c1-4ca4-4613-aac2-30d916e92c0e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8236ed06a5863e2208c77294e4ddb7352b0f83f7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50052987"
---
# <a name="form-views-mfc"></a>Exibições de formulário (MFC)

Você pode adicionar formulários para qualquer aplicativo do Visual C++ que dá suporte as bibliotecas MFC, incluindo uma [baseada em formulários de aplicativo](../mfc/reference/creating-a-forms-based-mfc-application.md) (um cuja exibição de classe é derivada de `CFormView`). Se você não tiver criado seu aplicativo para dar suporte a formulários inicialmente, o Visual C++ adicionará esse suporte para você quando você insere um novo formulário. Em um aplicativo SDI ou MDI, que implementa o padrão [arquitetura de documento/exibição](../mfc/document-view-architecture.md), quando o usuário escolhe o **New** comando (por padrão, no **arquivo** menu), o Visual C++ solicita que o usuário escolha entre os formatos disponíveis.

Com um aplicativo SDI, quando o usuário escolhe o **New** de comando, a instância atual do formulário continua em execução, mas uma nova instância do aplicativo com o formulário selecionado será criada se não for encontrado. Em um aplicativo MDI, a instância atual do formulário continuará a ser executado quando o usuário escolhe o **New** comando.

> [!NOTE]
>  Você pode inserir um formulário em um aplicativo baseado em diálogo (aquele cuja classe de caixa de diálogo se baseia em `CDialog` e outro no qual nenhuma exibição de classe é implementada). No entanto, sem a arquitetura de documento/exibição, Visual C++ não implementar automaticamente as **arquivo**&#124;**New** funcionalidade. Você deve criar uma maneira para o usuário exibir formulários adicionais, como com a implementação de uma caixa de diálogo com guias com várias páginas de propriedade.

Quando você insere um novo formulário em seu aplicativo, o Visual C++ faz o seguinte:

- Cria uma classe com base em uma das classes do estilo de formulário que você escolher (`CFormView`, `CRecordView`, `CDaoRecordView`, ou `CDialog`).

- Cria um recurso de caixa de diálogo com estilos apropriados (ou você pode usar um recurso de caixa de diálogo existente que ainda não foi associado uma classe).

   Se você escolher um recurso de caixa de diálogo existente, você precisa definir esses estilos por meio da página de propriedades da caixa de diálogo. Estilos para uma caixa de diálogo devem incluir:

     **WS_CHILD**= On

     **WS_BORDER**= Off

     **WS_VISIBLE**= Off

     **WS_CAPTION =** desativado

Para aplicativos com base na arquitetura de documento/exibição, o **novo formulário** (botão direito do mouse na exibição de classe) do comando também:

- Cria um `CDocument`-com base em classe

   Em vez de ter uma nova classe criada, você poderá usar qualquer existente `CDocument`-com base em classe em seu projeto.

- Gera um modelo de documento (derivado de `CDocument`) com recursos de cadeia de caracteres, o menu e ícone.

   Você também pode criar uma nova classe no qual basear o modelo.

- Adiciona uma chamada para `AddDocumentTemplate` em seu aplicativo `InitInstance` código.

   Visual C++ adiciona este código para cada novo formulário que você cria, que adiciona o formulário à lista de formulários disponíveis quando o usuário escolhe o **New** comando. Esse código inclui a ID do recurso associado do formulário e os nomes do documento associado, exibição e classes de quadro que juntos compõem o novo objeto de formulário.

   Modelos de documento servem como a conexão entre documentos, janelas de quadro e modos de exibição. Para um único documento, você pode criar muitos modelos.

Para obter mais informações, consulte:

- [Criar um aplicativo baseado em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md)

- [Inserindo um formulário em um projeto](../mfc/inserting-a-form-into-a-project.md)

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
