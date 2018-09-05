---
title: Editor de tecla aceleradora | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.accelerator.F1
dev_langs:
- C++
helpviewer_keywords:
- accelerator tables [C++], editing
- tables [Visual Studio], accelerator key
- accelerator keys
- resource editors, Accelerator editor
- keyboard shortcuts [C++], Accelerator editor
- Accelerator editor
ms.assetid: 013c30b6-5d61-4f1c-acef-8bd15bed7060
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 04401180cfcd82f3a699f71ba594523cf0f9cb9b
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43681717"
---
# <a name="accelerator-editor"></a>Editor de aceleradores

Uma tabela de Aceleradores é um recurso do Windows que contém uma lista de teclas de aceleração (também conhecido como teclas de atalho) e os identificadores de comando que estão associados eles. Um programa pode ter mais de uma tabela de aceleradores.

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