---
title: Criando uma nova caixa de diálogo (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.dialog
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes [C++], creating
- Dialog Editor [C++], creating dialog boxes
ms.assetid: 303de801-c4f8-42e1-b622-353f6423f688
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fae55d0b4ce4a766952afcec7f78ec6b20fbb258
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426634"
---
# <a name="creating-a-new-dialog-box-c"></a>Criando uma nova caixa de diálogo (C++)

### <a name="to-create-a-new-dialog-box"></a>Para criar uma nova caixa de diálogo

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **adicionar recurso** no menu de atalho.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No **adicionar recurso** caixa de diálogo, selecione **caixa de diálogo** no **tipo de recurso** lista e, em seguida, clique em **novo**.

   Se um sinal de adição (**+**) é exibido ao lado de **caixa de diálogo** tipo de recurso, isso significa que os modelos de caixa de diálogo estão disponíveis. Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em **New**.

   A nova caixa de diálogo é aberta na **caixa de diálogo** editor.

   Você também pode [abrir caixas de diálogo existente no editor de caixa de diálogo para edição](../windows/viewing-and-editing-resources-in-a-resource-editor.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Como criar um recurso](../windows/how-to-create-a-resource.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)