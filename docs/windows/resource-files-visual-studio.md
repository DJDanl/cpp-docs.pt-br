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
ms.openlocfilehash: 3de2010cca04d007bf61bf8c139cbc69d790e579
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57562998"
---
# <a name="resource-files-c"></a>Arquivos de recurso (C++)

> [!NOTE]
> Como projetos em linguagens de programação .NET usa arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Use o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados.
>
> Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

O termo *arquivo de recurso* pode se referir a um número de tipos de arquivo, como:

- O arquivo de script (. rc) do recurso de um programa.

- Um arquivo de modelo (. rct) do recurso.

- Um recurso individual existente como um arquivo autônomo. Esse tipo inclui um arquivo de bitmap, ícone ou cursor que é chamado de um arquivo. rc.

- Um arquivo de cabeçalho gerado pelo ambiente de desenvolvimento. Esse tipo inclui `Resource.h`, que é chamado de um arquivo. rc.

Recursos encontrados em outros tipos de arquivo, como arquivos. res,. dll e .exe são denominados *recursos*.

Você pode trabalhar com *arquivos de recurso* e *recursos* de dentro de seu projeto. Você também pode trabalhar com aqueles que não fazem parte do projeto atual ou que foram criados fora do ambiente de desenvolvimento do Visual Studio. Por exemplo, você pode:

- Trabalhar com arquivos de recursos aninhados e incluídas condicionalmente.

- Atualizar recursos existentes ou convertê-los para o Visual C++.

- Importar ou exportar recursos gráficos para ou do arquivo de recurso atual.

- Inclua compartilhados ou somente leitura identificadores (símbolos) que não podem ser modificados pelo ambiente de desenvolvimento.

- Inclua recursos em seu arquivo executável (.exe) que não é necessário editar (ou não devem ser editados), como recursos compartilhados entre vários projetos.

- Inclua tipos de recursos não suportados pelo ambiente de desenvolvimento.

Para obter mais informações sobre recursos, consulte como [criar recursos](../windows/how-to-create-a-resource-script-file.md), [gerenciar recursos](../windows/how-to-copy-resources.md), e [incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).

## <a name="editable-resources"></a>Recursos editáveis

Os seguintes tipos de arquivos podem ser abertos para editar os recursos que eles contêm:

| Nome do arquivo | Descrição |
|---|---|
| .rc | Arquivos de script de recurso |
| .rct | Arquivos de modelo de recurso |
| .res | Arquivos de recurso |
| .resx | Arquivos de recurso gerenciados |
| .exe | Arquivos executáveis |
| .dll | Arquivos de biblioteca de vínculo dinâmico |
| .bmp, .ico, .dib, .cur | Arquivos de bitmap, ícone, barra de ferramentas e cursor |

Ao editar recursos, o ambiente do Visual Studio funciona com e afeta os seguintes arquivos:

| Nome do arquivo | Descrição |
|---|---|
| Resource.h | Arquivo de cabeçalho gerado pelo ambiente de desenvolvimento que contém definições de símbolo.<br/><br/>Inclua esse arquivo no controle de origem. |
| Filename.aps | Versão binária do arquivo de script de recurso atual usado para o carregamento rápido.<br /><br /> Editores de recursos não lidos diretamente os arquivos. rc ou Resource. h. O compilador de recurso compila-os em arquivos de .aps que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos.<br/><br/>Como com um normal de processo de compilação, informações que não são simbólicas, como os comentários, serão descartadas durante o processo de compilação.<br/><br/>Sempre que o arquivo de .aps está fora de sincronia com o arquivo. RC, o arquivo. RC é regenerado. Por exemplo, quando você **salvar**, o editor de recurso substitui o arquivo. RC e o arquivo Resource h. Todas as alterações para os próprios recursos permanecem incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).<br/><br/>Normalmente, você não deve incluir o arquivo de .aps no controle de origem. |
| .rc | Arquivo de script de recurso que contém um script para os recursos em seu projeto atual. Esse arquivo é substituído pelo arquivo .aps sempre que você salva.<br/><br/>Inclua esse arquivo no controle de origem. |

## <a name="manifest-resources"></a>Recursos de manifesto

Em projetos do C++ da área de trabalho, recursos de manifesto são arquivos XML que descrevem as dependências de que um aplicativo usa. Por exemplo, no Visual Studio esse MFC gerado pelo Assistente de arquivo de manifesto define qual versão do Windows comuns controle DLLs o aplicativo deve usar:

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

Para um aplicativo do Windows XP ou Windows Vista, o recurso de manifesto deve especificar a versão mais atual dos controles comuns do Windows para o aplicativo para usar. O exemplo acima usa a versão `6.0.0.0`, que oferece suporte a [controle Syslink](/windows/desktop/Controls/syslink-overview).

> [!NOTE]
> Você pode ter apenas um recurso de manifesto por módulo.

Para exibir a versão e digite as informações contidas em um recurso de manifesto, abra o arquivo em um visualizador XML ou editor de texto do Visual Studio. Se você abrir um recurso de manifesto da [exibição de recurso](../windows/resource-view-window.md), o recurso será aberto no formato binário.

### <a name="to-open-a-manifest-resource"></a>Para abrir um recurso de manifesto

1. Abra seu projeto no Visual Studio e navegue até **Gerenciador de soluções**.

1. Expanda o **arquivos de recurso** pasta, então:

   - Para abrir no editor de texto, clique duas vezes o *. manifest* arquivo.

   - Para abrir em outro editor, clique com botão direito do *. manifest* do arquivo e selecione **abrir com**. Especificar o editor para usar e selecione **aberto**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Identificadores de recursos (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>