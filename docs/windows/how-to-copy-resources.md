---
title: 'Como: Gerenciar recursos (C++)'
ms.date: 11/04/2016
f1_keywords:
- vc.resvw.resource.copying
- vs.resvw.resource.copying
- vc.resvw.resource.changing
- vb.xmldesigner.data
- vs.resvw.resource.importing
- vc.resvw.resource.importing
helpviewer_keywords:
- resources [C++], moving between files
- resources [C++], copying
- resource files [C++], copying or moving resources between
- resource files [C++], tiling
- .rc files [C++], copying resources between
- rc files [C++], copying resources between
- Language property [C++]
- .resx files [C++], editing
- resource files [C++], editing
- resx files [C++], editing
- resources [C++], exporting
- graphics [C++], exporting
- graphics [C++], importing
- resources [C++], importing
- bitmaps [C++], importing and exporting
- toolbars [C++], importing
- images [C++], importing
- toolbars [C++], exporting
- cursors [C++], importing and exporting
- images [C++], exporting
ms.assetid: 65f523e8-017f-4fc6-82d1-083c56d9131f
ms.openlocfilehash: e8b976f974e397b8012ebf59ede08ee64f4f7191
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56150786"
---
# <a name="how-to-manage-resources-c"></a>Como: Gerenciar recursos (C++)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-copy-resources"></a>Copiar recursos

Você pode copiar recursos de um arquivo para outro sem alterá-los ou você pode alterar o idioma ou a condição de um recurso ao copiá-lo.

Você pode facilmente copiar recursos de um recurso existente ou arquivo executável para o arquivo de recurso atual. Para copiar recursos, você abra ambos os arquivos que contêm recursos ao mesmo tempo e arrasta itens de um arquivo para outro ou copia e cola entre os dois arquivos. Esse método funciona para arquivos de script (. rc) do recurso e arquivos de modelo (. rct) de recurso e como arquivos executáveis (.exe).

> [!NOTE]
> O Visual C++ inclui arquivos de recurso de exemplo que você pode usar em seu próprio aplicativo. Para obter mais informações, consulte [clip-art: Recursos comuns](https://github.com/Microsoft/VCSamples).

Você pode usar o método de arrastar e soltar entre arquivos. rc que estão abertos [fora do projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).

### <a name="to-copy-resources-between-files-using-the-drag-and-drop-method"></a>Copiar recursos entre os arquivos usando o método de arrastar e soltar

1. Abra ambos os arquivos de recurso autônomos (para obter mais informações, consulte [exibir recursos em um arquivo. rc fora de um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)). Por exemplo, abra *Source1.rc* e *Source2.rc*.

1. Dentro do primeiro arquivo. RC, selecione o recurso que você deseja copiar. Por exemplo, na *Source1.rc*, selecione **IDD_DIALOG1**.

1. Mantenha pressionada a **Ctrl** da chave e arraste o recurso para o segundo arquivo. rc. Por exemplo, arrastar **IDD_DIALOG1** partir *Source1.rc* para *Source2.rc*.

   > [!NOTE]
   > Arrastando o recurso sem manter pressionado a **Ctrl** tecla move o recurso em vez de copiá-lo.

### <a name="to-copy-resources-using-copy-and-paste"></a>Para copiar recursos usando copiar e colar

1. Abra ambos os arquivos de recurso autônomos (para obter mais informações, consulte [exibir recursos em um arquivo. rc fora de um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)). Por exemplo, *Source1.rc* e *Source2.rc*.

1. No arquivo de origem do qual você deseja copiar um recurso (por exemplo, *Source1.rc*), um recurso com o botão direito e escolha **cópia** no menu de atalho.

1. Clique no arquivo de recurso no qual você deseja colar o recurso (por exemplo, *Source2.rc*). Escolher **colar** no menu de atalho.

   > [!NOTE]
   > Não é possível arraste e solte, copiar, recortar ou colar entre os arquivos de recurso no projeto (**exibição de recurso**) e arquivos. rc autônomo (aquelas abertos em janelas de documento). Você pode fazer isso em versões anteriores do produto.

   > [!NOTE]
   > Para evitar conflitos com nomes de símbolos ou os valores no arquivo existente, Visual C++ pode alterar o valor de símbolo do recurso transferidos ou o nome do símbolo e o valor quando você os copia para o novo arquivo.

### <a name="to-change-the-language-or-condition-of-a-resource-while-copying"></a>Para alterar o idioma ou a condição de um recurso durante a cópia

Durante a cópia em um recurso, você pode alterar sua propriedade de idioma ou a propriedade de condição ou ambos.

- O idioma do recurso identifica exatamente isso, o idioma para o recurso. O idioma é usado pelo [FindResource](/windows/desktop/api/winbase/nf-winbase-findresourcea) para ajudar a identificar o recurso para o qual você está procurando. (No entanto, os recursos podem ter diferenças para cada idioma que não estão relacionadas a texto, por exemplo, os aceleradores que podem funcionar apenas em um teclado japonês ou um bitmap que só podem ser apropriado para chinês localizadas constrói.)

- A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia particular do recurso deve ser usado.

O idioma e a condição de um recurso são mostrados entre parênteses após o nome do recurso nas **espaço de trabalho** janela. Neste exemplo, o recurso nomeado `IDD_AboutBox` está usando `Finnish` como sua linguagem e sua condição é `XX33`.

```cpp
IDD_AboutBox (Finnish - XX33)
```

Para copiar um recurso existente e alterar seu idioma ou a condição:

1. No arquivo. rc ou na [exibição de recurso](../windows/resource-view-window.md) janela, clique com botão direito o recurso que você deseja copiar.

1. Escolher **inserir cópia** no menu de atalho.

1. No **inserir cópia do recurso** caixa de diálogo:

   - Para o **linguagem** caixa de listagem, selecione o idioma.

   - No **condição** , digite a condição.

## <a name="to-edit-managed-resource-files"></a>Para editar arquivos de recurso gerenciado

Arquivos de recurso gerenciado (. resx) são arquivos XML. Quando você adiciona um arquivo de recurso gerenciado para seu projeto a partir o **Adicionar Novo Item** caixa de diálogo, o **Editor de recursos gerenciados** abre por padrão.

## <a name="to-import-and-export-resources"></a>Para importar e exportar recursos

Você pode importar recursos gráficos (bitmaps, ícones, cursores e barras de ferramentas), arquivos HTML e recursos personalizados para uso no Visual C++. Você pode exportar os mesmos tipos de arquivos de um projeto do Visual C++ para separar os arquivos que podem ser usados fora do ambiente de desenvolvimento.

> [!NOTE]
> Tipos de recursos como aceleradores, caixas de diálogo e tabelas de cadeia de caracteres não podem ser importados ou exportados porque eles não são tipos de arquivo autônomo.

### <a name="to-import-an-individual-resource-into-your-current-resource-file"></a>Para importar um recurso individual em seu arquivo de recurso atual

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito no nó para o script de recurso (*. rc) ao qual você deseja adicionar um recurso de arquivo.

1. Selecione **importação** no menu de atalho.

1. Localize e selecione o nome do arquivo de bitmap (. bmp), o ícone (. ico), o cursor (. cur), arquivo Html (. htm) ou outro arquivo que você deseja importar.

1. Escolher **Okey** para adicionar o recurso para o arquivo selecionado no **recursos** modo de exibição.

   > [!NOTE]
   > O processo de importação funcionar da mesma maneira, independentemente de qual recurso determinado tipo que você selecionou. O recurso importado é adicionado automaticamente para o nó correto para esse tipo de recurso.

### <a name="to-export-a-bitmap-icon-or-cursor-as-a-separate-file-for-use-outside-of-visual-c"></a>Para exportar um bitmap, ícone ou cursor como um arquivo separado (para uso fora do Visual C++)

1. Na **recurso** exibir, clique no recurso que você deseja exportar.

1. Selecione **exportar** no menu de atalho.

1. No **Exportar recurso** caixa de diálogo caixa, aceite o nome do arquivo atual ou digite um novo.

1. Navegue até a pasta onde você deseja salvar o arquivo e escolha **exportar**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)