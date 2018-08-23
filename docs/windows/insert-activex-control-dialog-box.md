---
title: Inserir caixa de diálogo de controle ActiveX | Microsoft Docs
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
- Insert ActiveX Control dialog box
- ActiveX controls [C++], adding to dialog boxes
ms.assetid: 06638ea3-0726-40da-a989-9b89292d0e3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6e9f14b696ff67b52c365617682c0cc4c43432cd
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42602810"
---
# <a name="insert-activex-control-dialog-box"></a>Caixa de diálogo Inserir Controle ActiveX

Essa caixa de diálogo permite que você [inserir controles ActiveX em sua caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md) ao usar o [editor de caixa de diálogo](../windows/dialog-editor.md).

### <a name="activex-control"></a>Controle ActiveX

Exibe uma lista de controles Active X. Inserindo um controle nessa caixa de diálogo não gera uma classe wrapper. Se você precisar de uma classe wrapper, use [Class View](http://msdn.microsoft.com/8d7430a9-3e33-454c-a9e1-a85e3d2db925) criá-lo (para obter mais informações, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)). Se um controle Active X não aparecer na caixa de diálogo, tente instalar o controle de acordo com as instruções do fornecedor.

### <a name="path"></a>Caminho

Exibe o arquivo no qual o controle ActiveX é encontrado.

Você pode colocar controles na **caixa de ferramentas** janela para facilitar o acesso. Para obter mais informações, consulte [caixa de diálogo Personalizar caixa de ferramentas](http://msdn.microsoft.com/bd07835f-18a8-433e-bccc-7141f65263bb).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Guia Editor de Caixa de Diálogo, caixa de ferramentas](../windows/dialog-editor-tab-toolbox.md)  
[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)