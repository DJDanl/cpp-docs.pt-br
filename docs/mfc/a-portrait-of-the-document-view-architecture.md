---
title: "Um retrato da arquitetura do modo de exibição de documentos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- documents [MFC], views
- multiple views [MFC], updating from document
- document/view architecture [MFC]
- views [MFC], and user input
- documents [MFC], accessing data from view
- views [MFC], updating
- input [MFC], view class
- documents [MFC], multiple views
- document/view architecture [MFC], accessing data from view
- document/view architecture [MFC], about document/view architecture
- views [MFC], accessing document data from
ms.assetid: 4e7f65dc-b166-45d8-bcd5-9bb0d399b946
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7e79222f908a7b71e81033fb34517834987e6590
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="a-portrait-of-the-documentview-architecture"></a>Um retrato da arquitetura de documento/exibição
Documentos e exibições são combinadas em um aplicativo típico do MFC. Dados são armazenados no documento, mas o modo de exibição tem acesso aos dados privilegiado. A separação de documento na exibição de separa o armazenamento e a manutenção de dados de sua exibição.  
  
## <a name="gaining-access-to-document-data-from-the-view"></a>O acesso aos dados da exibição de documento  
 O modo de exibição acessa dados do seu documento com a [GetDocument](../mfc/reference/cview-class.md#getdocument) de função, que retorna um ponteiro para o documento, ou fazendo com que o modo de exibição de classe C++ de `friend` da classe do documento. O modo de exibição, em seguida, usa o acesso aos dados para obter os dados quando estiver pronto para desenhar ou manipulá-lo.  
  
 Por exemplo, a partir do modo de exibição [OnDraw](../mfc/reference/cview-class.md#ondraw) função de membro, a exibição usa **GetDocument** para obter um ponteiro de documento. Em seguida, ele usa esse ponteiro para acessar um `CString` membro de dados no documento. O modo de exibição passa a cadeia de caracteres para o `TextOut` função. Para ver o código para este exemplo, consulte [desenhando uma exibição](../mfc/drawing-in-a-view.md).  
  
## <a name="user-input-to-the-view"></a>Entrada do usuário para o modo de exibição  
 O modo de exibição também pode interpretar um clique do mouse em si mesmo como seleção ou edição de dados. Da mesma forma, ele poderá interpretá pressionamentos de tecla como entrada de dados ou edição. Suponha que o usuário digita uma cadeia de caracteres em uma exibição que gerencia o texto. O modo de exibição obtém um ponteiro para o documento e usa o ponteiro para passar os novos dados para o documento, que armazena em algumas estruturas de dados.  
  
## <a name="updating-multiple-views-of-the-same-document"></a>Atualizando vários modos de exibição do mesmo documento  
 Em um aplicativo com vários modos de exibição do mesmo documento — como uma janela separadora em um editor de texto — o modo de exibição primeiro passa novos dados para o documento. Em seguida, ele chama o documento [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) a função de membro, que faz com que todos os modos de exibição do documento para atualizar, refletindo os novos dados. Isso sincroniza os modos de exibição.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Vantagens da arquitetura de documento/exibição](../mfc/advantages-of-the-document-view-architecture.md)  
  
-   [Alternativas à arquitetura de documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md)  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

