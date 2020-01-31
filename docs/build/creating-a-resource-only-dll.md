---
title: Criando uma DLL somente de recurso
description: Como criar uma DLL somente de recursos no Visual Studio.
ms.date: 01/27/2020
helpviewer_keywords:
- resource-only DLLs [C++], creating
- DLLs [C++], creating
ms.assetid: e6b1d4da-7275-467f-a58c-a0a8a5835199
no-loc:
- noentry
ms.openlocfilehash: ef79de77e35cbef6acd4af1cec82a4edc1b7d105
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821337"
---
# <a name="creating-a-resource-only-dll"></a>Criando uma DLL somente de recurso

Uma DLL somente de recursos é uma DLL que não contém nada, mas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo. Usar uma DLL somente de recursos é uma boa maneira de compartilhar o mesmo conjunto de recursos entre vários programas. Também é uma boa maneira de fornecer um aplicativo com recursos localizados para vários idiomas. Para obter mais informações, consulte [recursos localizados em aplicativos do MFC: DLLs satélite](localized-resources-in-mfc-applications-satellite-dlls.md).

## <a name="create-a-resource-only-dll"></a>Criar uma DLL somente de recursos

Para criar uma DLL somente de recursos, você cria um novo projeto de DLL do Windows (não MFC) e adiciona seus recursos ao projeto:

::: moniker range="vs-2015"

1. Selecione **projeto Win32** na caixa de diálogo **novo projeto** . Insira os nomes do projeto e da solução e escolha **OK**.

1. No **Assistente de aplicativo Win32**, selecione **configurações do aplicativo**. Escolha um **tipo de aplicativo** de **dll**. Em **Opções adicionais**, selecione **projeto vazio**. Escolha **concluir** para criar seu projeto.

1. Crie um novo script de recurso que contenha os recursos para a DLL (como uma cadeia de caracteres ou um menu). Salve o arquivo de `.rc`.

1. No menu **projeto** , selecione **Adicionar item existente**e, em seguida, insira o novo arquivo de `.rc` no projeto.

1. Especifique a opção do vinculador [/NOENTRY](reference/noentry-no-entry-point.md) . `/NOENTRY` impede que o vinculador vincule uma referência a `_main` na DLL; Essa opção é necessária para criar uma DLL somente de recursos.

1. Compile a DLL.

::: moniker-end
::: moniker range=">=vs-2017"

1. Selecione **Assistente de área de trabalho do Windows** na caixa de diálogo **novo projeto** e escolha **Avançar**. Na página **configurar seu novo projeto** , insira os nomes do projeto e da solução e escolha **criar**.

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , selecione um tipo de **aplicativo** da **biblioteca de vínculo dinâmico**. Em **Opções adicionais**, selecione **projeto vazio**. Escolha **OK** para criar seu projeto.

1. Crie um novo script de recurso que contenha os recursos para a DLL (como uma cadeia de caracteres ou um menu). Salve o arquivo de `.rc`.

1. No menu **projeto** , selecione **Adicionar item existente**e, em seguida, insira o novo arquivo de `.rc` no projeto.

1. Especifique a opção do vinculador [/NOENTRY](reference/noentry-no-entry-point.md) . `/NOENTRY` impede que o vinculador vincule uma referência a `_main` na DLL; Essa opção é necessária para criar uma DLL somente de recursos.

1. Compile a DLL.

::: moniker-end

## <a name="use-a-resource-only-dll"></a>Usar uma DLL somente de recursos

O aplicativo que usa a DLL somente de recursos deve chamar [LoadLibraryEx](loadlibrary-and-afxloadlibrary.md) ou uma função relacionada para vincular explicitamente à dll. Para acessar os recursos, chame as funções genéricas `FindResource` e `LoadResource`, que funcionam em qualquer tipo de recurso. Ou então, chame uma das seguintes funções específicas do recurso:

- `FormatMessage`

- `LoadAccelerators`

- `LoadBitmap`

- `LoadCursor`

- `LoadIcon`

- `LoadMenu`

- `LoadString`

O aplicativo deve chamar `FreeLibrary` quando terminar de usar os recursos.

## <a name="see-also"></a>Veja também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)\
[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
