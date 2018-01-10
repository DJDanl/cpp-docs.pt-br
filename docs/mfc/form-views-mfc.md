---
title: "Formulário Exibições (MFC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- user interfaces [MFC], forms
- forms [MFC]
- applications [MFC], forms-based
- forms-based applications [MFC]
- forms [MFC], adding to applications
ms.assetid: efbe73c1-4ca4-4613-aac2-30d916e92c0e
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4e784858c17c01c8a538edebdb15a89863d16438
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="form-views-mfc"></a>Exibições de formulário (MFC)
Você pode adicionar formulários para qualquer aplicativo do Visual C++ que oferece suporte as bibliotecas MFC, incluindo um [aplicativo baseado em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md) (um cuja exibição de classe é derivada de `CFormView`). Se você não tiver criado seu aplicativo para dar suporte a formulários inicialmente, o Visual C++ adicionará esse suporte para você quando você insere um novo formulário. Em um aplicativo SDI ou MDI, que implementa o padrão [arquitetura de documento/exibição](../mfc/document-view-architecture.md), quando o usuário escolhe o `New` comando (por padrão, no **arquivo** menu), Visual C++ solicita ao usuário Escolha entre formulários disponíveis.  
  
 Com um aplicativo SDI, quando o usuário escolhe o `New` de comando, a instância atual do formulário continuará a ser executado, mas uma nova instância do aplicativo com o formulário selecionado é criada se não for encontrado. Em um aplicativo MDI, a instância atual do formulário continuará a ser executado quando o usuário escolhe o `New` comando.  
  
> [!NOTE]
>  Você pode inserir um formulário em um aplicativo baseado na caixa de diálogo (cuja classe de caixa de diálogo é com base em `CDialog` e um no qual nenhuma exibição de classe é implementada). No entanto, sem a arquitetura de documento/exibição Visual C++ não implementar automaticamente o **arquivo**&#124; **Novo** funcionalidade. Você deve criar uma maneira para que o usuário exiba formas adicionais, como com a implementação de uma caixa de diálogo com várias páginas de propriedade.  
  
 Quando você insere um novo formulário em seu aplicativo, o Visual C++ faz o seguinte:  
  
-   Cria uma classe com base em uma das classes de estilo de formulário que você escolher (`CFormView`, `CRecordView`, `CDaoRecordView`, ou `CDialog`).  
  
-   Cria um recurso de caixa de diálogo com estilos apropriados (ou você pode usar um recurso de caixa de diálogo existente que ainda não foi associado uma classe).  
  
     Se você escolher um recurso de caixa de diálogo existente, você precisará definir esses estilos, usando a página de propriedades para a caixa de diálogo. Estilos para uma caixa de diálogo devem incluir:  
  
     **Estilo**= On  
  
     `WS_BORDER`= Off  
  
     **WS_VISIBLE**= Off  
  
     **WS_CAPTION =**Off  
  
 Para aplicativos baseados em arquitetura de documento/exibição, o **novo formulário** comando (com o botão direito no modo de exibição de classe) também:  
  
-   Cria um **CDocument**-com base em classe  
  
     Em vez de uma nova classe criada, você pode usar qualquer existente **CDocument**-com base em classe em seu projeto.  
  
-   Gera um modelo de documento (derivado de **CDocument**) com recursos de cadeia de caracteres, o menu e o ícone.  
  
     Você também pode criar uma nova classe no qual basear o modelo.  
  
-   Adiciona uma chamada para **AddDocumentTemplate** em seu aplicativo `InitInstance` código.  
  
     Visual C++ adiciona esse código para cada novo formulário que você cria, o que adiciona o formulário à lista de formulários disponíveis quando o usuário escolhe o `New` comando. Esse código inclui a ID de recurso associado do formulário e os nomes de exibição, classes de quadro que compõem o novo objeto de formulário e documento associado.  
  
     Modelos de documento servem como a conexão entre documentos, janelas de quadro e modos de exibição. Para um único documento, você pode criar vários modelos.  
  
 Para obter mais informações, consulte:  
  
-   [Criar um aplicativo baseado em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md)  
  
-   [Inserindo um formulário em um projeto](../mfc/inserting-a-form-into-a-project.md)  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
