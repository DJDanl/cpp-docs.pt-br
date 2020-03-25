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
ms.openlocfilehash: 087cd613fa0dfd9cb6e07ac47a6a38d63bba004e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167869"
---
# <a name="resource-files-c"></a>Arquivos de recurso (C++)

> [!NOTE]
> Como os projetos nas linguagens de programação do .NET não usam arquivos de script de recurso, você deve abrir seus recursos de **Gerenciador de soluções**. Use o [Editor de imagem](../windows/image-editor-for-icons.md) e o [Editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados.
>
> Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

O termo *arquivo de recursos* pode se referir a vários tipos de arquivo, como:

- O arquivo de script de recurso (. rc) de um programa.

- Um arquivo de modelo de recurso (. rct).

- Um recurso individual existente como um arquivo autônomo. Esse tipo inclui um bitmap, ícone ou arquivo de cursor referenciado de um arquivo. rc.

- Um arquivo de cabeçalho gerado pelo ambiente de desenvolvimento. Esse tipo inclui `Resource.h`, que é referenciado a partir de um arquivo. rc.

Os recursos encontrados em outros tipos de arquivo, como. exe,. dll e. res, são chamados de *recursos*.

Você pode trabalhar com *arquivos de recursos* e *recursos* de dentro de seu projeto. Você também pode trabalhar com aqueles que não fazem parte do projeto atual ou que foram criados fora do ambiente de desenvolvimento do Visual Studio. Por exemplo, você pode:

- Trabalhe com arquivos de recurso aninhados e condicionalmente incluídos.

- Atualize os recursos existentes ou Converta- C++os em Visual.

- Importe ou exporte recursos gráficos de ou para o arquivo de recurso atual.

- Incluir identificadores compartilhados ou somente leitura (símbolos) que não podem ser modificados pelo ambiente de desenvolvimento.

- Inclua recursos no arquivo executável (. exe) que não precisam de edição (ou que não devem ser editados), como recursos compartilhados entre vários projetos.

- Inclua tipos de recursos sem suporte no ambiente de desenvolvimento.

Para obter mais informações sobre recursos, consulte como [criar recursos](../windows/how-to-create-a-resource-script-file.md), [gerenciar recursos](../windows/how-to-copy-resources.md)e [incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).

## <a name="editable-resources"></a>Recursos editáveis

Os seguintes tipos de arquivos podem ser abertos para editar os recursos que eles contêm:

| Nome do arquivo | DESCRIÇÃO |
|---|---|
| .rc | Arquivos de script de recurso |
| .rct | Arquivos de modelo de recurso |
| . res | Arquivos de recurso |
| .resx | Arquivos de recursos gerenciados |
| .exe | Arquivos executáveis |
| .dll | Arquivos de biblioteca de vínculo dinâmico |
| .bmp, .ico, .dib, .cur | Arquivos de bitmap, ícone, barra de ferramentas e cursor |

Ao editar recursos, o ambiente do Visual Studio funciona com o e afeta os seguintes arquivos:

| Nome do arquivo | DESCRIÇÃO |
|---|---|
| Resource.h | Arquivo de cabeçalho gerado pelo ambiente de desenvolvimento que contém definições de símbolo.<br/><br/>Incluir este arquivo no controle do código-fonte. |
| Nome de arquivo. APS | Versão binária do arquivo de script de recurso atual usado para carregamento rápido.<br /><br /> Os editores de recursos não lêem diretamente os arquivos. rc ou Resource. h. O compilador de recursos os compila em arquivos. APS consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena somente dados simbólicos.<br/><br/>Assim como ocorre com um processo de compilação normal, as informações que não são simbólicas, como comentários, são descartadas durante o processo de compilação.<br/><br/>Sempre que o arquivo. APS estiver fora de sincronia com o arquivo. rc, o arquivo. rc será regenerado. Por exemplo, quando você **salva**, o editor de recursos substitui o arquivo. rc e o arquivo Resource. h. Todas as alterações nos próprios recursos permanecem incorporadas no arquivo. rc, mas os comentários sempre serão perdidos quando o arquivo. rc for substituído. Para obter informações sobre como preservar comentários, consulte [incluir recursos no momento da compilação](../windows/how-to-include-resources-at-compile-time.md).<br/><br/>Normalmente, você não deve incluir o arquivo. APS no controle do código-fonte. |
| .rc | Arquivo de script de recurso que contém script para os recursos em seu projeto atual. Esse arquivo é substituído pelo arquivo. APS sempre que você salvar.<br/><br/>Incluir este arquivo no controle do código-fonte. |

## <a name="manifest-resources"></a>Recursos de manifesto

Em C++ projetos de área de trabalho, os recursos de manifesto são arquivos XML que descrevem as dependências que um aplicativo usa. Por exemplo, no Visual Studio, este arquivo de manifesto gerado pelo assistente do MFC define qual versão das DLLs de controle comum do Windows o aplicativo deve usar:

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

Para um aplicativo do Windows XP ou do Windows Vista, o recurso de manifesto deve especificar a versão mais atual dos controles comuns do Windows para o aplicativo a ser usado. O exemplo acima usa a versão `6.0.0.0`, que dá suporte ao [controle Syslink](/windows/win32/Controls/syslink-overview).

> [!NOTE]
> Você só pode ter um recurso de manifesto por módulo.

Para exibir as informações de versão e tipo contidas em um recurso de manifesto, abra o arquivo em um visualizador de XML ou no editor de texto do Visual Studio. Se você abrir um recurso de manifesto de [modo de exibição de recursos](../windows/resource-view-window.md), o recurso será aberto em formato binário.

### <a name="to-open-a-manifest-resource"></a>Para abrir um recurso de manifesto

1. Abra seu projeto no Visual Studio e navegue até **Gerenciador de soluções**.

1. Expanda a pasta **arquivos de recursos** e, em seguida:

   - Para abrir no editor de texto, clique duas vezes no arquivo *. manifest* .

   - Para abrir em outro editor, clique com o botão direito do mouse no arquivo *. manifest* e selecione **abrir com**. Especifique o editor a ser usado e selecione **abrir**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Identificadores de recursos (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
