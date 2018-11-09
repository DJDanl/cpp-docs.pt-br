---
title: Substituindo uma função virtual (Visual C++)
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.virtualfunc.override
helpviewer_keywords:
- virtual functions, overriding
- base classes, overriding virtual functions defined in
- Properties window, overriding virtual functions in
ms.assetid: 2d8c76f2-7a6b-4c9c-8de5-4282ce7755b6
ms.openlocfilehash: 193c84d2b9a0fe50ae84d3e69834feab27342042
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484130"
---
# <a name="overriding-a-virtual-function-visual-c"></a>Substituindo uma função virtual (Visual C++)

Substitua funções virtuais definidas em uma classe base na [janela Propriedades](/visualstudio/ide/reference/properties-window) do Visual Studio.

### <a name="to-override-a-virtual-function-in-the-properties-window"></a>Para substituir uma função virtual na janela Propriedades

1. Em Modo de Exibição de Classe, clique na classe.

1. Na janela Propriedades, clique no botão **Substituições**.

   > [!NOTE]
   >  O botão **Substituições** fica disponível quando você seleciona o nome da classe em Modo de Exibição de Classe ou quando você clica dentro da janela de origem.

   A coluna à esquerda lista as funções virtuais. Se o nome de uma função virtual também é exibido na coluna à direita, isso indica que uma substituição já foi implementada.

1. Se a função não tiver nenhuma substituição, clique na célula da coluna à direita na janela Propriedades para exibir o nome sugerido da substituição de função como \<add>*FuncName*.

1. Clique no nome sugerido para adicionar um código de stub à função.

1. Para editar uma função de substituição, clique duas vezes no nome da função em Modo de Exibição de Classe e edite o código na janela de origem.

Para remover uma substituição, clique no nome da função de substituição na coluna à direita e selecione \<delete>*FuncName*. O código da função será comentado.

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)<br>
[Adicionando uma classe](../ide/adding-a-class-visual-cpp.md)<br>
[Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)<br>
[Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)<br>
[Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)<br>
[Navegando pela estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)