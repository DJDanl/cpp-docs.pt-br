---
title: Adicionando uma classe (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.classes.adding
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding classes
- classes [C++], creating
- classes [C++], adding
ms.assetid: c34b5f70-4e72-4faa-ba21-e2b05361c4d9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 14e16d8b5c15939adb792a96a828bafd07ba4041
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33333278"
---
# <a name="adding-a-class-visual-c"></a>Adicionando uma classe (Visual C++)
Para adicionar uma classe a um projeto do Visual C++, no **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto, clique em **Adicionar** e, em seguida, **Classe**. Isso abrirá a caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md).  
  
 Ao adicionar uma classe, é necessário especificar um nome que seja diferente das classes já existentes no MFC ou na ATL. Se você especificar um nome já existente em uma das bibliotecas, o IDE mostrará uma mensagem de erro.  
  
 Caso a convenção de nomenclatura do projeto exija o uso de um nome existente, você poderá alterar apenas o uso de maiúsculas de uma ou mais letras no nome porque o C++ diferencia maiúsculas de minúsculas. Por exemplo, embora não seja possível nomear uma classe `CDocument`, é possível nomeá-la `cdocument`.  
  
## <a name="what-kind-of-class-do-you-want-to-add"></a>Qual tipo de classe você deseja adicionar?  
 Na caixa de diálogo **Adicionar Classe**, quando você expande o nó **Visual C++** no painel esquerdo, vários agrupamentos de modelos instalados são exibidos. Os grupos incluem **CLR**, **ATL**, **MFC** e **C++**. Quando você seleciona um grupo, uma lista dos modelos disponíveis nesse grupo é exibida no painel central. Cada modelo contém os arquivos e o código-fonte necessários para uma classe.  
  
 Para gerar uma nova classe, selecione um modelo no painel central, digite um nome para a classe na caixa **Nome** e clique em **Adicionar**. Isso abrirá o **Assistente de Adição de Classe**, de modo que você possa especificar opções para a classe.  
  
-   Para obter mais informações sobre como criar classes MFC, confira [Classe MFC](../mfc/reference/adding-an-mfc-class.md).  
  
-   Para obter mais informações sobre como criar classes ATL, confira [Objeto ATL Simples](../atl/reference/adding-an-atl-simple-object.md).  
  
> [!NOTE]
>  O modelo **Adicionar Suporte para ATL ao MFC** não cria uma classe, mas configura o projeto para usar a ATL. Para obter mais informações, confira [Suporte para ATL em um projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md).  
  
 Para criar uma classe C++ que não usa o MFC, a ATL ou o CLR, use o modelo **Classe C++** no grupo **C++** de modelos instalados. Para obter mais informações, confira [Adicionando uma classe C++ genérica](../ide/adding-a-generic-cpp-class.md).  
  
 Dois tipos de classes C++ baseadas em formulário estão disponíveis. O primeiro deles, [Classe CFormView](../mfc/reference/cformview-class.md), cria uma classe MFC. O segundo cria uma classe CLR do Windows Forms.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um aplicativo MFC baseado em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md)   
 [Caixa de diálogo Adicionar Classe](../ide/add-class-dialog-box.md)   
 [Criando projetos da área de trabalho com assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)