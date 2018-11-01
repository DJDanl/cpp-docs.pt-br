---
title: Adicionando arquivos a aplicativos Win32 vazios
ms.date: 11/04/2016
helpviewer_keywords:
- empty projects [C++], adding files
- projects [C++], adding items
- blank projects
- files [C++], adding to projects
ms.assetid: 070098e8-0396-49fe-a697-3daa2f1be6de
ms.openlocfilehash: d5347a0693619e5db44b1087fc249c68b9227fb2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50568643"
---
# <a name="adding-files-to-an-empty-win32-applications"></a>Adicionando arquivos a aplicativos Win32 vazios

### <a name="to-add-your-files-to-an-empty-windows-desktop-application"></a>Para adicionar os arquivos para um aplicativo da área de trabalho do Windows vazio

1. Selecione o diretório no **Gerenciador de soluções**.

2. O nome do diretório com o botão direito, clique em **Add** do menu de atalho e clique **Item existente**.

3. No **caixa de diálogo Adicionar Item existente**, navegue até os arquivos que você deseja adicionar ao seu projeto.

4. Clique em **OK**.

Para adicionar arquivos que não são código-fonte, cabeçalho ou arquivos de recurso ao seu projeto, clique com botão direito do **solução** nó no **Gerenciador de soluções** e adicione os arquivos ao projeto da mesma maneira. Um **Miscelânea** pasta será criada para manter os outros arquivos em seu projeto.

> [!NOTE]
> Antes de compilar seu projeto, você precisará especificar opções de build para esses arquivos para que eles são incluídos corretamente em seu aplicativo concluído. Para obter mais informações, consulte [especificando as configurações de projeto com páginas de propriedades](../ide/property-pages-visual-cpp.md) e [criando um programa em C/C++](../build/building-c-cpp-programs.md).

## <a name="see-also"></a>Consulte também

[Criando um aplicativo da área de trabalho do Windows vazio](../windows/creating-an-empty-windows-desktop-application.md)
