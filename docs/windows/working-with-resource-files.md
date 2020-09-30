---
title: Trabalhando com arquivos de recursos (C++)
ms.date: 02/14/2019
helpviewer_keywords:
- resources [C++], about resources
- resources [C++], about resource files
- resource files [C++], about resource files
ms.assetid: 2699a539-b369-4b78-80f0-df03eb7b6780
ms.openlocfilehash: 3e387a1cefb6577760a34c7957d4f5019b1d49ef
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502907"
---
# <a name="working-with-resource-files"></a>Trabalhando com arquivos de recurso

> [!WARNING]
> Esta seção se aplica a aplicativos de área de trabalho do Windows escritos em C++.
>
> Para obter informações sobre os recursos em aplicativos Plataforma Universal do Windows escritos em C++, consulte [definindo recursos de aplicativo](/windows/uwp/app-resources/)ou adicionando recursos a projetos C++/CLI (gerenciados), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no guia do desenvolvedor de .NET Framework.

Os recursos podem ser compostos por uma ampla variedade de elementos, como:

- Elementos de interface que fornecem informações para o usuário, como um bitmap, ícone ou cursor.
- Recursos personalizados que contêm dados e necessidades do aplicativo.
- Recursos de versão que são usados pelas APIs de instalação.
- Recursos de menu e caixa de diálogo.

Você pode adicionar novos recursos ao seu projeto e modificar esses recursos usando o editor de recursos adequado. A maioria dos assistentes do Visual C++ gerará automaticamente um arquivo .rc para o seu projeto.

> [!NOTE]
> Os **editores de recursos** e **modo de exibição de recursos** não estão disponíveis nas Express Editions.

Para adicionar manualmente os arquivos de recursos a projetos gerenciados, consulte [criando arquivos de recursos para aplicativos da área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Este artigo inclui como acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades.

Para globalizar e localizar recursos em aplicativos gerenciados, consulte [Globalizando e Localizando aplicativos .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="in-this-section"></a>Nesta seção

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
Descreve os arquivos de recursos e como eles são usados em aplicativos de área de trabalho do Windows. Também fornece links para artigos que descrevem como usar arquivos de recurso.

[Identificadores de recurso (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
Descreve os símbolos e fornece informações sobre como usar a caixa de diálogo **símbolos de recurso** para gerenciar símbolos em seus projetos.

[Editores de recursos](../windows/resource-editors.md)<br/>
Descreve os editores de recursos fornecidos no Visual Studio e os tipos de recursos que podem ser modificados com cada editor. Também fornece links para informações detalhadas sobre como usar cada editor.

## <a name="related-sections"></a>Seções relacionadas

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
Fornece links para a documentação do Visual C++.

[Fale conosco](/visualstudio/ide/talk-to-us)<br/>
Fornece links para informações sobre o uso do conjunto de documentação, o contado com suporte ao produto, e a aplicação de recursos de acessibilidade.

## <a name="see-also"></a>Consulte também

[Aplicativos da área de trabalho do Windows](./desktop-applications-visual-cpp.md)<br/>
[Menus e outros recursos](/windows/win32/menurc/resources)
