---
title: Criando um novo personalizado ou o recurso de dados (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.binary
dev_langs:
- C++
helpviewer_keywords:
- custom resources [C++]
- data resources [C++]
- resources [C++], creating
ms.assetid: 9918bf96-38fa-43a1-a384-572f95d84950
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2e2939c7f0a68401b4c1a8c43b5c6335a0acfcb3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46403929"
---
# <a name="creating-a-new-custom-or-data-resource-c"></a>Criando um novo personalizado ou o recurso de dados (C++)

Você pode criar um novo recurso personalizado ou dados colocando o recurso em um arquivo separado, usando a sintaxe de arquivo de script (. rc) do recurso normal e, em seguida, incluindo o arquivo clicando com o seu projeto no **Gerenciador de soluções** e clicando em  **Inclui recurso** no menu de atalho.

### <a name="to-create-a-new-custom-or-data-resource"></a>Para criar um novo recurso personalizado ou dados

1. [Crie um arquivo. rc](../windows/how-to-create-a-resource-script-file.md) que contém o recurso personalizado ou dados.

   Você pode digitar os dados personalizados em um arquivo. rc como cadeias de caracteres entre aspas terminada em nulo, ou como números inteiros em formato decimal, hexadecimal ou octal.

2. Na **Gerenciador de soluções**, o arquivo. RC do seu projeto com o botão direito e clique em **recurso inclui** no menu de atalho.

3. No **diretivas de tempo de compilação** , digite um `#include` instrução que fornece o nome do arquivo que contém o recurso personalizado. Por exemplo:

    ```cpp
    #include mydata.rc
    ```

   Verifique se a sintaxe e a ortografia do que você digita estão corretos. O conteúdo a **diretivas de tempo de compilação** caixa são inseridos no arquivo de script de recurso exatamente como você digitou-los.

4. Clique em **Okey** para registrar as alterações.

É outra maneira de criar um recurso personalizado importar um arquivo externo como o recurso personalizado. Para obter mais informações, consulte [importando e exportando recursos](../windows/how-to-import-and-export-resources.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor binário](binary-editor.md)