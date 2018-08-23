---
title: Visualizando recursos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.resvw.resource.previewing
- vs.resvw.resource.previewing
dev_langs:
- C++
helpviewer_keywords:
- resources [Visual Studio], viewing
- resource previews
- code, viewing
ms.assetid: d6abda66-0e2b-4ac3-a59a-a57b8c6fb70b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e6e15a4557d8368596021307ba7045bfb4b08664
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42583826"
---
# <a name="previewing-resources"></a>Visualizando recursos

Visualizando seus recursos permite que você exiba recursos gráficos sem abri-los. Visualização também é útil para executáveis depois que você tenha compilado-los porque os identificadores de recurso Alterar para números. Pois esses identificadores numéricos geralmente não fornecem informações suficientes, visualizando os recursos ajuda a identificar rapidamente-los.

Você pode visualizar o layout visual dos tipos de recursos a seguir:

- Bitmap

- Caixa de diálogo

- Ícone

- Menu

- Cursor

- Barra de ferramentas

A função de visualização do visual não se aplica aos recursos do acelerador, manifesto, tabela de cadeia de caracteres e informações de versão.

### <a name="to-preview-resources"></a>Para visualizar os recursos

1. Na [exibição de recurso](../windows/resource-view-window.md) ou uma janela de documento, selecione o recurso, por exemplo, **IDD_ABOUTBOX**.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No [janela de propriedades](/visualstudio/ide/reference/properties-window), clique no **páginas de propriedade** botão.

   \- ou -

3. Sobre o **modo de exibição** menu, clique em **páginas de propriedade**.

   O **página de propriedades** para o recurso será aberta exibindo uma visualização desse recurso. Em seguida, você pode usar o **para cima** e **para baixo** teclas de direção para navegar na árvore de controle na **exibição de recurso** ou a janela do documento. O **página de propriedades** será permanecer aberta e mostrará a qualquer recurso que tem o foco e é capaz de ser visualizado.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Como abrir um arquivo de script de recurso fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)  
[Editores de recursos](../windows/resource-editors.md)