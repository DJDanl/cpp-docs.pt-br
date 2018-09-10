---
title: Alterando a propriedade Caption de vários recursos de cadeia de caracteres (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- String editor [C++], changing properties of multiple strings
- string tables [C++], changing caption of multiple strings
ms.assetid: 82ac4389-fd9c-4794-a18f-c6bf5b253bd7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b2ba75745d769d593549e707a9100a50c40e6f65
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44318818"
---
# <a name="changing-the-caption-property-of-multiple-string-resources-c"></a>Alterando a propriedade Caption de vários recursos de cadeia de caracteres (C++)

O procedimento a seguir mostra como alterar a propriedade de legenda de várias cadeias de caracteres.

### <a name="to-change-the-caption-property-of-multiple-strings"></a>Para alterar a propriedade de legenda de várias cadeias de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Selecione as cadeias de caracteres que você deseja alterar, mantendo pressionada a **Ctrl** da chave que você clicar em cada um deles.

3. No [janela de propriedades](/visualstudio/ide/reference/properties-window), digite um novo valor para a propriedade que você deseja alterar.

4. Pressione **ENTER**.

Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](/previous-versions/visualstudio/visual-studio-2010/y99d1cd3\(v=vs.100\)).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de cadeias de caracteres](../windows/string-editor.md)  