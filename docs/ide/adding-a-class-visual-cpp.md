---
title: Adicionando uma classe (Visual C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.classes.adding
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding classes
- classes [C++], creating
- classes [C++], adding
ms.assetid: c34b5f70-4e72-4faa-ba21-e2b05361c4d9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ac87368f2bd38c32425799103fa3999dd11b3298
ms.sourcegitcommit: 30ab99c775d99371ed22d1a46598e542012ed8c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/03/2018
---
# <a name="adding-a-class-visual-c"></a>Adicionando uma classe (Visual C++)
Para adicionar uma classe em um projeto do Visual C++, em **Solution Explorer**, clique com o botão direito, clique em **adicionar**e, em seguida, clique em **classe**. Isso abre o [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md) caixa de diálogo.  
  
 Quando você adiciona uma classe, você deve especificar um nome que seja diferente das classes que já existem no MFC ou do ATL Se você especificar um nome que já existe em qualquer biblioteca, o IDE mostra uma mensagem de erro.  
  
 Se seu projeto de convenção de nomenclatura exige que você use um nome existente, em seguida, é possível alterar apenas no caso de uma ou mais letras no nome porque C++ diferencia maiusculas de minúsculas. Por exemplo, embora você não pode nomear uma classe `CDocument`, você pode atribuir o nome `cdocument`.  
  
## <a name="what-kind-of-class-do-you-want-to-add"></a>O tipo de classe você deseja adicionar?  
 No **Adicionar classe** caixa de diálogo, quando você expande o **Visual C++** nó no painel esquerdo, vários agrupamentos de modelos instalados são exibidos. Os grupos de incluir **CLR**, **ATL**, **MFC**, e **C++**. Quando você seleciona um grupo, uma lista dos modelos disponíveis nesse grupo é exibida no painel central. Cada modelo contém os arquivos e o código-fonte que são necessários para uma classe.  
  
 Para gerar uma nova classe, selecione um modelo no painel central, digite um nome para a classe de **nome** caixa e clique em **adicionar**. Isso abre o **Adicionar Assistente de classe** para que você possa especificar opções para a classe.  
  
-   Para obter mais informações sobre como criar classes MFC, consulte [classe MFC](../mfc/reference/adding-an-mfc-class.md).  
  
-   Para obter mais informações sobre como criar classes ATL, consulte [objeto ATL simples](../atl/reference/adding-an-atl-simple-object.md).  
  
> [!NOTE]
>  O modelo **adicionar suporte ATL ao MFC** não cria uma classe, mas em vez disso, configura o projeto para usar ATL. Para obter mais informações, consulte [suporte ATL em um projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md).  
  
 Para tornar uma classe C++ que não use MFC, ATL ou CLR, use o **classe C++** modelo o **C++** grupo de modelos instalados. Para obter mais informações, consulte [adicionando uma classe C++ genérica](../ide/adding-a-generic-cpp-class.md).  
  
 Existem dois tipos de classes C++ baseadas no formulário. O primeiro deles, [CFormView classe](../mfc/reference/cformview-class.md) cria uma classe do MFC. Segunda cria uma classe CLR Windows Forms.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um aplicativo MFC com base em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md)   
 [Adicionar caixa de diálogo de classe](../ide/add-class-dialog-box.md)   
 [Criando projetos de área de trabalho usando os assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)