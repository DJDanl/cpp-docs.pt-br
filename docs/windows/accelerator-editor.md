---
title: Editor de aceleradores (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.accelerator.F1
helpviewer_keywords:
- accelerator tables [C++], editing
- tables [C++], accelerator key
- accelerator keys [C++]
- resource editors [C++], Accelerator editor
- keyboard shortcuts [C++], Accelerator editor
ms.assetid: 013c30b6-5d61-4f1c-acef-8bd15bed7060
ms.openlocfilehash: fdb2d9cf0954142da990a0a9f995cb482060345d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50621488"
---
# <a name="accelerator-editor-c"></a>Editor de aceleradores (C++)

Uma tabela de Aceleradores é um recurso do Windows C++ que contém uma lista de teclas de aceleração (também conhecido como teclas de atalho) e os identificadores de comando que estão associados eles. Um programa pode ter mais de uma tabela de aceleradores.

Normalmente, os aceleradores são usados como atalhos de teclado para comandos de programa que também estão disponíveis em um menu ou barra de ferramentas. No entanto, você pode usar a tabela de aceleradores para definir as combinações de teclas para comandos que não têm um objeto de interface do usuário associado a eles.

Você pode usar [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code) conectem os comandos do acelerador chave ao código.

Com o **Accelerator** editor, você pode:

- [Definir propriedades do acelerador](../windows/setting-accelerator-properties.md)

- [Associar uma tecla de aceleração um Item de Menu](../windows/associating-an-accelerator-key-with-a-menu-item.md)

- [Editar tabelas de aceleradores](../windows/editing-accelerator-tables.md)

- [Use as teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)

   > [!TIP]
   > Ao usar o **Accelerator** editor, clique para exibir um menu de atalho de comandos usados com frequência. Os comandos disponíveis dependem do que o ponteiro estiver apontando para.

   > [!NOTE]
   > Windows não permitem que você crie tabelas de aceleradores vazio. Se você criar uma tabela de aceleradores sem entradas, ele é excluído automaticamente quando você salva a tabela.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)