---
title: Arquivos de recurso (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- resources [C++]
- .rc files [C++]
- resource files [C++]
- resource script files [C++]
- resource script files [C++], Win-32 based applications
- resource script files [C++], files updated when editing resources
- resources [C++], types of resource files
- rct files [C++]
- rc files [C++]
- resource files [C++], types of
- .rct files [C++]
- resource script files [C++], unsupported types
ms.assetid: 4d2b6fcc-07cf-4289-be87-83a60f69533c
ms.openlocfilehash: 9ad36f19185bc5b3430e7644ef55164d3cb0839a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50461685"
---
# <a name="resource-files-c"></a>Arquivos de recurso (C++)

> [!NOTE]
> Este material se aplica a aplicativos de área de trabalho do Windows. Para obter informações sobre recursos em aplicativos da plataforma Universal do Windows, consulte [definindo recursos do aplicativo](/windows/uwp/app-resources/).
>
> Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).
>
> Como projetos em linguagens de programação .NET usa arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

O termo "arquivo de recurso" pode se referir a um número de tipos de arquivo, incluindo:

- O arquivo de script (. rc) do recurso de um programa.

- Um arquivo de modelo (. rct) do recurso.

- Um recurso individual existente como um arquivo autônomo, como um arquivo de bitmap, ícone ou cursor que é chamado de um arquivo. rc.

- Um arquivo de cabeçalho gerado pelo ambiente de desenvolvimento, por exemplo Resource. h, que é chamado de um arquivo. rc.

Recursos também podem ser encontrados em [outros tipos de arquivo](../windows/editable-file-types-for-resources.md) como arquivos .exe,. dll e. res. Você pode trabalhar com recursos e arquivos de recurso de dentro de seu projeto e com aqueles que não fazem parte do projeto atual. Você também pode trabalhar com arquivos de recurso que não foram criados no ambiente de desenvolvimento do Visual Studio. Por exemplo, você pode:

- Trabalhar com arquivos de recursos aninhados e incluídas condicionalmente.

- Atualizar recursos existentes ou convertê-los para o formato do Visual C++.

- Importar ou exportar recursos gráficos para ou do arquivo de recurso atual.

- Inclua compartilhados ou somente leitura identificadores (símbolos) que não podem ser modificados pelo ambiente de desenvolvimento.

- Inclua recursos em seu arquivo executável (.exe) que não exigem a edição (ou que você não deseja ser editados) durante o seu projeto atual, como recursos que são compartilhados entre vários projetos.

- Inclua tipos de recursos não suportados pelo ambiente de desenvolvimento.

Esta seção abrange:

- [Criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md)

- [Criar um novo recurso](../windows/how-to-create-a-resource.md)

- [Exibir recursos em um arquivo de Script de recurso](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)

- [Abrir um arquivo de Script de recurso no formato de texto](../windows/how-to-open-a-resource-script-file-in-text-format.md)

- [Incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)

- [Copiando recursos](../windows/how-to-copy-resources.md)

- [Usando modelos de recursos (. rct)](../windows/how-to-use-resource-templates.md)

- [Importar e exportar recursos](../windows/how-to-import-and-export-resources.md)

- [Tipos de arquivo editáveis para recursos](../windows/editable-file-types-for-resources.md)

- [Arquivos afetados pela edição de recurso](../windows/files-affected-by-resource-editing.md)

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Menus e outros recursos](https://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)