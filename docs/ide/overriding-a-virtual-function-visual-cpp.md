---
title: Substituir uma função virtual
ms.date: 11/12/2018
f1_keywords:
- vc.codewiz.virtualfunc.override
helpviewer_keywords:
- virtual functions, overriding
- base classes, overriding virtual functions defined in
- Properties window, overriding virtual functions in
ms.assetid: 2d8c76f2-7a6b-4c9c-8de5-4282ce7755b6
ms.openlocfilehash: 9bb3fd34bbfa14cce1595ed586c4e1b66518e7b7
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694017"
---
# <a name="override-a-virtual-function"></a>Substituir uma função virtual

Substitua funções virtuais definidas em uma classe base na [janela Propriedades](/visualstudio/ide/reference/properties-window) do Visual Studio.

**Para substituir uma função virtual na janela Propriedades:**

1. Em Modo de Exibição de Classe, selecione a classe.

1. Na janela Propriedades, selecione o botão **Substituições**.

   > [!NOTE]
   > O botão **Substituições** fica disponível quando você seleciona o nome da classe em Modo de Exibição de Classe ou quando você seleciona dentro da janela de origem.

   A coluna à esquerda lista as funções virtuais. Se o nome de uma função virtual também é exibido na coluna à direita, isso indica que uma substituição já foi implementada.

1. Se a função não tiver nenhuma substituição, selecione a célula da coluna à direita na janela Propriedades para exibir o nome sugerido da substituição de função como \<add>*FuncName*.

1. Selecione o nome sugerido para adicionar um código de stub à função.

1. Para editar uma função de substituição, clique duas vezes no nome da função em Modo de Exibição de Classe e edite o código na janela de origem.

Para remover uma substituição, selecione o nome da função de substituição na coluna à direita e selecione \<delete>*FuncName*. O código da função será comentado.
