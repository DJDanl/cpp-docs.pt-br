---
title: Propriedades do botão de barra de ferramentas (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- size, toolbar buttons
- toolbar buttons [C++], setting properties
- Toolbar editor [C++], toolbar button properties
- status bars [C++], active toolbar button text
- command IDs, toolbar buttons
- width, toolbar buttons
ms.assetid: b2705814-7c5d-4f24-8f77-07559b0cdda2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b23194992d3b2bb4f1e2708f7e57396cb7e94be6
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44318727"
---
# <a name="toolbar-button-properties-c"></a>Propriedades do botão de barra de ferramentas (C++)

As propriedades de um botão de barra de ferramentas são:

|Propriedade|Descrição|
|--------------|-----------------|
|**ID**|Define a ID do botão. A lista suspensa fornece comuns **ID** nomes.|
|**Largura**|Define a largura do botão. é recomendável 16 pixels.|
|**Altura**|Define a altura do botão. Observe que a altura de um botão altera a altura de todos os botões na barra de ferramentas. é recomendável 15 pixels.|
|**Solicitar**|Define a mensagem exibida na barra de status. Adicionar um nome e \n adiciona uma dica de ferramenta a esse botão de barra de ferramentas. Para obter mais informações, consulte [criando uma dica de ferramenta](../windows/creating-a-tool-tip-for-a-toolbar-button.md).|

**Largura** e **altura** se aplicam a todos os botões. Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir a largura do botão como 512, você só pode ter quatro botões e se você definir a largura como 513, você pode ter apenas três botões.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Alterando as propriedades de um botão de barra de ferramentas](../windows/changing-the-properties-of-a-toolbar-button.md)  
[Editor de barra de ferramentas](../windows/toolbar-editor.md)