---
title: Criando novas barras de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.toolbar
dev_langs:
- C++
helpviewer_keywords:
- toolbars [C++], creating
- Toolbar editor, creating new toolbars
- Insert Resource
ms.assetid: 1b28264b-0718-4df8-9f65-979805d2efef
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c737d048289074bcac948ad5eb5b27fac515b042
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596567"
---
# <a name="creating-new-toolbars"></a>Criando novas barras de ferramentas

### <a name="to-create-a-new-toolbar"></a>Para criar uma nova barra de ferramentas

1. Na **Resource** exibir, clique com botão direito seu arquivo. RC e escolha **adicionar recurso** no menu de atalho. (Se você tiver uma barra de ferramentas em seu arquivo. RC, você pode simplesmente com o botão direito do **barra de ferramentas** pasta e selecione **barra de ferramentas Insert** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No **adicionar recurso** caixa de diálogo, selecione **barra de ferramentas** no **tipo de recurso** lista e, em seguida, clique em **novo**.

   Se um sinal de adição (**+**) é exibido ao lado de **barra de ferramentas** tipo de recurso, isso significa que os modelos de barra de ferramentas estão disponíveis. Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em **New**.

   \- ou -

3. [Converter um bitmap existente em uma barra de ferramentas](../windows/converting-bitmaps-to-toolbars.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Editor de barra de ferramentas](../windows/toolbar-editor.md)