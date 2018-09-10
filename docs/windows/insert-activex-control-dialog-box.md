---
title: Inserir caixa de diálogo de controle ActiveX (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.dialog.insertActiveXControls
dev_langs:
- C++
helpviewer_keywords:
- Insert ActiveX Control dialog box [C++]
- ActiveX controls [C++], adding to dialog boxes
ms.assetid: 06638ea3-0726-40da-a989-9b89292d0e3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 16777dc2354787057e3cfe6afb329268272a16e2
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44317362"
---
# <a name="insert-activex-control-dialog-box-c"></a>Inserir caixa de diálogo de controle ActiveX (C++)

Essa caixa de diálogo permite que você [inserir controles ActiveX em sua caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md) ao usar o [editor de caixa de diálogo](../windows/dialog-editor.md).

### <a name="activex-control"></a>Controle ActiveX

Exibe uma lista de controles Active X. Inserindo um controle nessa caixa de diálogo não gera uma classe wrapper. Se você precisar de uma classe wrapper, use [Class View](/visualstudio/ide/viewing-the-structure-of-code) criá-lo (para obter mais informações, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)). Se um controle Active X não aparecer na caixa de diálogo, tente instalar o controle de acordo com as instruções do fornecedor.

### <a name="path"></a>Caminho

Exibe o arquivo no qual o controle ActiveX é encontrado.

Você pode colocar controles na **caixa de ferramentas** janela para facilitar o acesso. Para saber mais, confira [Caixa de Ferramentas](/visualstudio/ide/reference/).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Guia Editor de Caixa de Diálogo, caixa de ferramentas](../windows/dialog-editor-tab-toolbox.md)  
[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)