---
title: 'Como: Gerenciar recursos (C++)'
ms.date: 02/14/2019
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
ms.openlocfilehash: 28127ea89fdba1b70988ced1d6004c0f914c66e2
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57563037"
---
# <a name="how-to-manage-resources-c"></a>Como: Gerenciar recursos (C++)

## <a name="copy-and-edit-resources"></a>Copiar e editar recursos

Você pode copiar recursos de um arquivo para outro sem alterá-los, ou alterar o idioma ou a condição de um recurso ao copiá-lo.

Você pode facilmente copiar recursos de um recurso existente ou arquivo executável para o arquivo de recurso atual. Para copiar recursos, você abra ambos os arquivos que contêm recursos ao mesmo tempo e arrasta itens de um arquivo para outro ou copia e cola entre os dois arquivos. Esse método funciona para arquivos de script (. rc) do recurso e arquivos de modelo (. rct) de recurso e como arquivos executáveis (.exe).

> [!NOTE]
> O Visual C++ inclui arquivos de recurso de exemplo que você pode usar em seu próprio aplicativo. Para obter mais informações, consulte [clip-art: Recursos comuns](https://github.com/Microsoft/VCSamples).

Não é possível arraste e solte, copiar, recortar ou colar entre os arquivos de recurso no projeto (**exibição de recurso**) e arquivos. rc autônomo abertos em janelas de documento. Você pode fazer isso em versões anteriores do produto. Somente use o método de arrastar e soltar entre arquivos. rc que estão abertos fora do projeto.

### <a name="to-copy-resources"></a>Copiar recursos

1. Abra ambos os arquivos de recurso autônomos (consulte como [para abrir um arquivo de script de recurso](/how-to-create-a-resource-script-file#use-resource-script-files)). Por exemplo, abra *Source1.rc* e *Source2.rc*.

1. Dentro do primeiro arquivo. RC, ou:

   - Use o método de arrastar e soltar

      1. Selecione o recurso que você deseja copiar. Por exemplo, na *Source1.rc*, selecione **IDD_DIALOG1**.

      1. Mantenha pressionada a **Ctrl** da chave e arraste o recurso para o segundo arquivo. rc. Por exemplo, arrastar **IDD_DIALOG1** partir *Source1.rc* para *Source2.rc*.

         > [!TIP]
         > Arrastando o recurso sem manter pressionado a **Ctrl** tecla move o recurso em vez de copiá-lo.

   - Usar o copiar e colar o método

      1. O recurso de atalho com copiar (por exemplo, *Source1.rc*) e escolha **cópia**.

      1. Clique no arquivo de recurso no qual você deseja colar o recurso (por exemplo, *Source2.rc*) e escolha **colar**.

> [!NOTE]
> Para evitar conflitos com nomes de símbolos ou os valores no arquivo existente, Visual C++ pode alterar o valor de símbolo do recurso transferidos ou o nome do símbolo e o valor quando você os copia para o novo arquivo.

Durante a cópia em um recurso, você pode alterar sua propriedade de idioma ou a propriedade de condição ou ambos.

- A linguagem de um recurso Especifica o idioma usado pela [FindResource](/windows/desktop/api/winbase/nf-winbase-findresourcea) para ajudar a identificar o recurso para o qual você está procurando. Os recursos podem ter diferenças para cada idioma que não estão relacionadas a texto, por exemplo, aceleradores que podem funcionar apenas em um teclado japonês ou um bitmap que só podem ser apropriado para chinês localizadas builds.

- A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia particular do recurso deve ser usado.

O idioma e a condição de um recurso são mostrados entre parênteses após o nome do recurso nas **espaço de trabalho** janela. Aqui o recurso nomeado `IDD_AboutBox` está usando `Finnish` como sua linguagem e sua condição é `XX33`:

```cpp
IDD_AboutBox (Finnish - XX33)
```

### <a name="to-copy-an-existing-resource-and-change-its-language-or-condition"></a>Para copiar um recurso existente e alterar seu idioma ou uma condição

No *. rc* arquivo ou nos [exibição de recurso](../windows/resource-view-window.md) janela, com o recurso que você deseja copiar e escolha o botão direito **inserir cópia**. Em seguida, defina o seguinte:

- Para o **linguagem** caixa de listagem, selecione o idioma.

- No **condição** , digite a condição.

### <a name="to-edit-resources"></a>Para editar recursos

Arquivos de recurso gerenciado (. resx) são arquivos XML. Quando você adiciona um arquivo de recurso gerenciado para seu projeto a partir o **Adicionar Novo Item** caixa de diálogo, o **Editor de recursos gerenciados** abre por padrão.

## <a name="import-and-export-resources"></a>Importação e exportação de recursos

Você pode importar recursos gráficos (bitmaps, ícones, cursores e barras de ferramentas), arquivos HTML e recursos personalizados para uso no Visual C++. Você pode exportar os mesmos tipos de arquivos de um projeto do Visual C++ para separar os arquivos que podem ser usados fora do ambiente de desenvolvimento.

> [!NOTE]
> Tipos de recursos como aceleradores, caixas de diálogo e tabelas de cadeia de caracteres não podem ser importados ou exportados porque eles não são tipos de arquivo autônomo.

### <a name="to-import-a-resource-into-the-resource-script-file"></a>Para importar um recurso para o arquivo de script de recurso

1. Na [exibição de recurso](../windows/resource-view-window.md) com o botão direito no nó do arquivo de script (. rc) de recurso ao qual você deseja adicionar um recurso e selecione **importação**.

1. Localize e escolha o nome do arquivo de bitmap (. bmp), o ícone (. ico), cursor (. cur), arquivo html (. htm) ou outro arquivo para importar.

1. Selecione **Okey** para adicionar o recurso para o arquivo de script de recurso.

> [!NOTE]
> O processo de importação funciona da mesma não importa qual tipo de recurso você selecionou. O recurso importado é adicionado automaticamente para o nó correto desse tipo de recurso.

### <a name="to-export-a-resource-for-use-outside-of-visual-c"></a>Para exportar um recurso para uso fora do Visual C++

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito o recurso que você deseja exportar e selecione **exportar**. Você pode aceitar o nome do arquivo atual ou digite um novo.

1. Navegue até a pasta onde deseja salvar o arquivo e selecione **exportar**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: Criar recursos](../windows/how-to-create-a-resource-script-file.md)<br/>
[Como: incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)<br/>