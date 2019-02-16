---
title: Arquivos de recurso (C++)
ms.date: 02/14/2019
f1_keywords:
- vc.editors.resource
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
- manifest resources [C++]
- resources [C++], manifest
- resources [C++], opening
- file types [C++], for resources
- resources [C++], editing
- files [C++], editable types
- resource editing
ms.assetid: 4d2b6fcc-07cf-4289-be87-83a60f69533c
ms.openlocfilehash: 4d56a62dfa350b3113a28355433130563464c6be
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320530"
---
# <a name="resource-files-c"></a>Arquivos de recurso (C++)

> [!NOTE]
> Como projetos em linguagens de programação .NET usa arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

O termo "arquivo de recurso" pode se referir a um número de tipos de arquivo, incluindo:

- O arquivo de script (. rc) do recurso de um programa.

- Um arquivo de modelo (. rct) do recurso.

- Um recurso individual existente como um arquivo autônomo, como um arquivo de bitmap, ícone ou cursor que é chamado de um arquivo. rc.

- Um arquivo de cabeçalho gerado pelo ambiente de desenvolvimento, por exemplo Resource. h, que é chamado de um arquivo. rc.

Recursos também são encontrados em outros tipos de arquivo como .exe,. dll e arquivos. res. Você pode trabalhar com recursos e arquivos de recurso em seu projeto e aqueles que não fazem parte do projeto atual. Você também pode trabalhar com arquivos de recursos que não foram criados no ambiente de desenvolvimento do Visual Studio. Por exemplo, você pode:

- Trabalhar com arquivos de recursos aninhados e incluídas condicionalmente.

- Atualizar recursos existentes ou convertê-los para o formato do Visual C++.

- Importar ou exportar recursos gráficos para ou do arquivo de recurso atual.

- Inclua compartilhados ou somente leitura identificadores (símbolos) que não podem ser modificados pelo ambiente de desenvolvimento.

- Inclua recursos em seu arquivo executável (.exe) que não exigem a edição (ou que não devem ser editados) durante o seu projeto atual, como recursos compartilhados entre vários projetos.

- Inclua tipos de recursos não suportados pelo ambiente de desenvolvimento.

Esta seção aborda como:

- [Criar recursos](../windows/how-to-create-a-resource-script-file.md)

- [Gerenciar recursos](../windows/how-to-copy-resources.md)

- [Incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)

## <a name="editable-resource-file-types"></a>Tipos de arquivo de recurso editável

Os seguintes tipos de arquivos podem ser abertos para editar os recursos que eles contêm:

|Nome do arquivo|Descrição|
|---------|-----------------|
|.rc|Arquivos de script de recurso|
|.rct|Arquivos de modelo de recurso|
|.res|Arquivos de recurso|
|.resx|Arquivos de recurso gerenciados|
|.exe|Arquivos executáveis|
|.dll|Arquivos de biblioteca de vínculo dinâmico|
|. bmp,. ico,. dib e. cur|Arquivos de bitmap, ícone, barra de ferramentas e cursor.|

Ambiente do Visual Studio funciona com e afeta os seguintes arquivos durante sua sessão de edição de recurso:

|Nome do arquivo|Descrição|
|---------------|-----------------|
|Resource.h|Arquivo de cabeçalho gerado pelo ambiente de desenvolvimento. contém definições de símbolo. (Inclui esse arquivo no controle de origem).|
|Filename.aps|Versão binária do arquivo de script de recurso atual; usado para o carregamento rápido.<br /><br /> Os editores de recursos não lidos diretamente os arquivos. rc ou Resource. h. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não são simbólicas (por exemplo, comentários) serão descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo Resource h). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md). (Normalmente, você não deve incluir o arquivo .aps no controle de origem).|
|.rc|Arquivo de script de recurso que contém um script para os recursos em seu projeto atual. Esse arquivo é substituído pelo arquivo .aps sempre que você salva. (Inclui esse arquivo no controle de origem).|

## <a name="manifest-resources"></a>Recursos de manifesto

Em projetos do C++ da área de trabalho, recursos de manifesto são arquivos XML que descrevem as dependências que um aplicativo usa. Por exemplo, no Visual Studio, o arquivo de manifesto gerado pelo assistente MFC define quais do controle comum do Windows DLLs o aplicativo deve usar, versão 5.0 ou 6.0:

```xml
<description>Your app description here</description>
<dependency>
    <dependentAssembly>
        <assemblyIdentity
            type="win32"
            name="Microsoft.Windows.Common-Controls"
            version="6.0.0.0"
            processorArchitecture="X86"
            publicKeyToken="6595b64144ccf1df"
            language="*"
        />
    </dependentAssembly>
</dependency>
```

Para um aplicativo do Windows XP ou Windows Vista, o recurso de manifesto não só especifica que o aplicativo usar a versão mais atual dos controles comuns do Windows, v 6.0, como visto acima, mas ele também dá suporte a [controle Syslink](/windows/desktop/Controls/syslink-overview).

Para exibir a versão e digite as informações contidas em um recurso de manifesto, você pode abrir o arquivo em um visualizador XML ou no editor de texto do Visual Studio. Se você abrir um recurso de manifesto da [exibição de recurso](../windows/resource-view-window.md), o recurso será aberto no formato binário. Para exibir o conteúdo de um recurso de manifesto em um formato mais visível, você deve abrir o recurso a partir **Gerenciador de soluções**.

### <a name="to-open-a-manifest-resource"></a>Para abrir um recurso de manifesto

1. Abra seu projeto no Visual Studio.

1. Navegue até **Gerenciador de soluções** e expanda o **arquivos de recurso** pasta.

   - Editor de texto, clique duas vezes o arquivo. manifest.

   - Para outros editores, o arquivo. manifest com o botão direito e selecione **abrir com...** , em seguida, especifique o editor para usar e escolha **aberto**.

> [!NOTE]
> Você pode ter apenas um recurso de manifesto por módulo.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Identificadores de recurso (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>