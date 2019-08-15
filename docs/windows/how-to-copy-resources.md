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
ms.openlocfilehash: 56cff04d64f2f0a64fc216fbd418954b4c11b0f2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514746"
---
# <a name="how-to-manage-resources-c"></a>Como: Gerenciar recursos (C++)

## <a name="copy-and-edit-resources"></a>Copiar e editar recursos

Você pode copiar recursos de um arquivo para outro sem alterá-los ou alterar o idioma ou a condição de um recurso ao copiá-lo.

Você pode copiar facilmente recursos de um arquivo executável ou recurso existente para o arquivo de recurso atual. Para copiar recursos, abra os dois arquivos que contêm recursos ao mesmo tempo e arraste os itens de um arquivo para outro ou copie e cole entre os dois arquivos. Esse método funciona para arquivos de script de recurso (. rc) e de modelo de recurso (. rct) e como arquivos executáveis (. exe).

> [!NOTE]
> O C++ Visual inclui arquivos de recurso de exemplo que você pode usar em seu próprio aplicativo. Para obter mais informações, [consulte clipart: Recursos](https://github.com/Microsoft/VCSamples)comuns.

Você não pode arrastar e soltar, copiar, recortar ou colar entre arquivos de recursos no projeto (**modo de exibição de recursos**) e arquivos autônomos. rc abertos em janelas de documentos. Você pode fazer isso em versões anteriores do produto. Use apenas o método arrastar e soltar entre arquivos. RC que estão abertos fora do projeto.

### <a name="to-copy-resources"></a>Para copiar recursos

1. Abra ambos os arquivos de recurso autônomos. (Consulte [usar arquivos de script de recurso](how-to-create-a-resource-script-file.md#use-resource-script-files)). Por exemplo, abra *origem1. rc* e *origem2. rc*.

1. Dentro do primeiro arquivo. rc, seja:

   - Usar o método arrastar e soltar

      1. Selecione o recurso que você deseja copiar. Por exemplo, em *origem1. rc*, selecione **IDD_DIALOG1**.

      1. Mantenha pressionada a tecla **Ctrl** e arraste o recurso para o segundo arquivo. rc. Por exemplo, arraste **IDD_DIALOG1** de *origem1. rc* para *origem2. rc*.

         > [!TIP]
         > Arrastar o recurso sem manter pressionada a tecla **Ctrl** move o recurso em vez de copiá-lo.

   - Usar o método copiar e colar

      1. Clique com o botão direito do mouse no recurso que você deseja copiar (por exemplo, *origem1. rc*) e escolha **copiar**.

      1. Clique com o botão direito do mouse no arquivo de recurso no qual você gostaria de colar o recurso (por exemplo, *origem2. rc*) e escolha **colar**.

> [!NOTE]
> Para evitar conflitos com nomes de símbolo ou valores no arquivo existente, o C++ visual pode alterar o valor do símbolo do recurso transferido ou o nome do símbolo e o valor quando você o copia para o novo arquivo.

Ao copiar em um recurso, você pode alterar sua propriedade de linguagem ou propriedade de condição, ou ambos.

- O idioma de um recurso especifica o idioma usado pelo [FindResource](/windows/win32/api/winbase/nf-winbase-findresourcew) para ajudar a identificar o recurso que você está procurando. Os recursos podem ter diferenças para cada idioma que não esteja relacionado ao texto, por exemplo, aceleradores que só podem funcionar em um teclado japonês ou em um bitmap que só seria apropriado para compilações localizadas em chinês.

- A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia específica do recurso deve ser usada.

O idioma e a condição de um recurso são mostrados entre parênteses após o nome do recurso na janela do **espaço de trabalho** . Aqui, o recurso `IDD_AboutBox` nomeado está `Finnish` usando como seu idioma e sua condição `XX33`é:

```cpp
IDD_AboutBox (Finnish - XX33)
```

### <a name="to-copy-an-existing-resource-and-change-its-language-or-condition"></a>Para copiar um recurso existente e alterar seu idioma ou condição

No arquivo *. rc* ou na janela [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources) , clique com o botão direito do mouse no recurso que você deseja copiar e escolha **Inserir cópia**. Em seguida, defina o seguinte:

- Para a caixa de listagem **idioma** , selecione o idioma.

- Na caixa **condição** , digite a condição.

### <a name="to-edit-resources"></a>Para editar recursos

Arquivos de recurso gerenciado (. resx) são arquivos XML. Quando você adiciona um arquivo de recurso gerenciado ao seu projeto na caixa de diálogo **Adicionar novo item** , o **Editor de recursos gerenciados** é aberto por padrão.

## <a name="import-and-export-resources"></a>Importar e exportar recursos

Você pode importar recursos gráficos (bitmaps, ícones, cursores e barras de ferramentas), arquivos HTML e recursos personalizados para uso no Visual C++. Você pode exportar os mesmos tipos de arquivos de um projeto do C++ Visual Studio para separar arquivos que podem ser usados fora do ambiente de desenvolvimento.

> [!NOTE]
> Tipos de recursos como aceleradores, caixas de diálogo e tabelas de cadeia de caracteres não podem ser importados ou exportados porque não são tipos de arquivo autônomos.

### <a name="to-import-a-resource-into-the-resource-script-file"></a>Para importar um recurso para o arquivo de script de recurso

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources) clique com o botão direito do mouse no nó do arquivo de script de recurso (. rc) ao qual você deseja adicionar um recurso e selecione **importar**.

1. Localize e escolha o nome do arquivo do bitmap (. bmp), o ícone (. ico), o cursor (. cur), o arquivo HTML (. htm) ou outro arquivo a ser importado.

1. Selecione **OK** para adicionar o recurso ao arquivo de script do recurso.

> [!NOTE]
> O processo de importação funciona da mesma, não importa qual tipo de recurso você selecionou. O recurso importado é adicionado automaticamente ao nó correto desse tipo de recurso.

### <a name="to-export-a-resource-for-use-outside-of-visual-c"></a>Para exportar um recurso para uso fora do VisualC++

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no recurso que você deseja exportar e selecione **Exportar**. Você pode aceitar o nome do arquivo atual ou digitar um novo.

1. Navegue até a pasta onde você deseja salvar o arquivo e selecione **Exportar**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: Criar recursos](../windows/how-to-create-a-resource-script-file.md)<br/>
[Como: incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)<br/>