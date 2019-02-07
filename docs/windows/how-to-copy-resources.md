---
title: 'Como: Copiar recursos (C++)'
ms.date: 11/04/2016
f1_keywords:
- vc.resvw.resource.copying
- vs.resvw.resource.copying
- vc.resvw.resource.changing
helpviewer_keywords:
- resources [C++], moving between files
- resources [C++], copying
- resource files [C++], copying or moving resources between
- resource files [C++], tiling
- .rc files [C++], copying resources between
- rc files [C++], copying resources between
- Language property [C++]
ms.assetid: 65f523e8-017f-4fc6-82d1-083c56d9131f
ms.openlocfilehash: 772c9b905d4cb0c4e2ccab9ec51aa02860b2db32
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55849655"
---
# <a name="how-to-copy-resources-c"></a>Como: Copiar recursos (C++)

Você pode copiar recursos de um arquivo para outro sem alterá-los ou você pode alterar o idioma ou a condição de um recurso ao copiá-lo.

Você pode facilmente copiar recursos de um recurso existente ou arquivo executável para o arquivo de recurso atual. Para copiar recursos, você abra ambos os arquivos que contêm recursos ao mesmo tempo e arrasta itens de um arquivo para outro ou copia e cola entre os dois arquivos. Esse método funciona para arquivos de script (. rc) do recurso e arquivos de modelo (. rct) de recurso e como arquivos executáveis (.exe).

> [!NOTE]
> O Visual C++ inclui arquivos de recurso de exemplo que você pode usar em seu próprio aplicativo. Para obter mais informações, consulte [clip-art: Recursos comuns](https://github.com/Microsoft/VCSamples).

Você pode usar o método de arrastar e soltar entre arquivos. rc que estão abertos [fora do projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).

## <a name="to-copy-resources-between-files-using-the-drag-and-drop-method"></a>Copiar recursos entre os arquivos usando o método de arrastar e soltar

1. Abra ambos os arquivos de recurso autônomos (para obter mais informações, consulte [exibir recursos em um arquivo externa de um projeto de. rc](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)). Por exemplo, abra Source1.rc e Source2.rc.

1. Dentro do primeiro arquivo. RC, selecione o recurso que você deseja copiar. Por exemplo, na `Source1.rc`, selecione **IDD_DIALOG1**.

1. Mantenha pressionada a **Ctrl** da chave e arraste o recurso para o segundo arquivo. rc. Por exemplo, arrastar **IDD_DIALOG1** partir `Source1.rc` para `Source2.rc`.

   > [!NOTE]
   > Arrastando o recurso sem manter pressionado a **Ctrl** tecla move o recurso em vez de copiá-lo.

## <a name="to-copy-resources-using-copy-and-paste"></a>Para copiar recursos usando copiar e colar

1. Abra ambos os arquivos de recurso autônomos (para obter mais informações, consulte [exibir recursos em um arquivo externa de um projeto de. rc](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)). Por exemplo, Source1.rc e Source2.rc.

1. No arquivo de origem do qual você deseja copiar um recurso (por exemplo, `Source1.rc`), um recurso com o botão direito e escolha **cópia** no menu de atalho.

1. Clique no arquivo de recurso no qual você deseja colar o recurso (por exemplo, `Source2.rc`). Escolher **colar** no menu de atalho.

   > [!NOTE]
   > Não é possível arraste e solte, copiar, recortar ou colar entre os arquivos de recurso no projeto (**exibição de recurso**) e arquivos. rc autônomo (aquelas abertos em janelas de documento). Você pode fazer isso em versões anteriores do produto.

   > [!NOTE]
   > Para evitar conflitos com nomes de símbolos ou os valores no arquivo existente, Visual C++ pode alterar o valor de símbolo do recurso transferidos ou o nome do símbolo e o valor quando você os copia para o novo arquivo.

## <a name="to-change-the-language-or-condition-of-a-resource-while-copying-c"></a>Para alterar o idioma ou a condição de um recurso durante a cópia (C++)

Durante a cópia em um recurso, você pode alterar sua propriedade de idioma ou a propriedade de condição ou ambos.

- O idioma do recurso identifica exatamente isso, o idioma para o recurso. O idioma é usado pelo [FindResource](/windows/desktop/api/winbase/nf-winbase-findresourcea) para ajudar a identificar o recurso para o qual você está procurando. (No entanto, os recursos podem ter diferenças para cada idioma que não estão relacionadas a texto, por exemplo, os aceleradores que podem funcionar apenas em um teclado japonês ou um bitmap que só podem ser apropriado para chinês localizadas constrói.)

- A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia particular do recurso deve ser usado.

O idioma e a condição de um recurso são mostrados entre parênteses após o nome do recurso na janela do espaço de trabalho. Neste exemplo, o recurso denominado IDD_AboutBox e estiver usando finlandês como sua linguagem de sua condição XX33.

```cpp
IDD_AboutBox (Finnish - XX33)
```

### <a name="to-copy-an-existing-resource-and-change-its-language-or-condition"></a>Para copiar um recurso existente e alterar seu idioma ou uma condição

1. No arquivo. rc ou na [exibição de recurso](../windows/resource-view-window.md) janela, clique com botão direito o recurso que você deseja copiar.

1. Escolher **inserir cópia** no menu de atalho.

1. No **inserir cópia do recurso** caixa de diálogo:

   - Para o **linguagem** caixa de listagem, selecione o idioma.

   - No **condição** , digite a condição.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
[Como: abrir um arquivo de script de recurso fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)<br/>
