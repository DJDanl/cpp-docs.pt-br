---
title: "Substituindo uma função Virtual (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.virtualfunc.override
dev_langs: C++
helpviewer_keywords:
- virtual functions, overriding
- base classes, overriding virtual functions defined in
- Properties window, overriding virtual functions in
ms.assetid: 2d8c76f2-7a6b-4c9c-8de5-4282ce7755b6
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 98e77579d511f4c78f0f7835c0b3c1dcea632734
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overriding-a-virtual-function-visual-c"></a>Substituindo uma função virtual (Visual C++)
Você pode substituir funções virtuais definidas em uma classe base a partir do Visual Studio [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
### <a name="to-override-a-virtual-function-in-the-properties-window"></a>Para substituir uma função virtual na janela Propriedades  
  
1.  No modo de exibição de classe, clique na classe.  
  
2.  Na janela Propriedades, clique o **substitui** botão.  
  
    > [!NOTE]
    >  O **substitui** botão está disponível quando você seleciona o nome de classe no modo de exibição de classe ou quando você clica dentro da janela de origem.  
  
     A coluna esquerda lista as funções virtuais. Se o nome de uma função virtual também aparece na coluna à direita, em seguida, uma substituição já foi implementada.  
  
3.  Se a função não tiver nenhuma substituição, em seguida, clique na célula na coluna à direita na janela Propriedades para exibir o nome sugerido da função substituir como \<Adicionar >*FuncName*.  
  
4.  Clique no nome sugerido para adicionar código de stub para a função.  
  
5.  Para editar uma função de substituição, clique duas vezes no nome da função no modo de exibição de classe e editar o código na janela de origem.  
  
 Para remover uma substituição, clique no nome da função de substituição na coluna à direita e selecione \<excluir >*FuncName*. Código da função será comentado.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)