---
title: Editando propriedades de um controle ActiveX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], editing properties
- ActiveX controls [C++], properties
ms.assetid: e5880c62-36c7-4701-bc99-97a82974c22a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e754307c35d10aa36680a42415bd3a5b781321ba
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384839"
---
# <a name="editing-properties-for-an-activex-control"></a>Editando propriedades de um controle ActiveX

Controles ActiveX fornecidos por fornecedores independentes podem vir equipados com suas próprias propriedades e características. Propriedades para controles ActiveX são exibidas na **propriedades** janela. Além disso, as páginas de propriedade criadas pelos gravadores do controle ActiveX são exibidas na **páginas de propriedades** caixa de diálogo (para exibir o **página de propriedades** para um controle ActiveX específico, clique o  **Página de propriedades** botão de [janela propriedades](/visualstudio/ide/reference/properties-window)).

Várias guias são exibidas na página de propriedades para um controle ActiveX, dependendo das folhas de propriedades que são fornecidos como parte do controle ActiveX.

> [!NOTE]
> O procedimento a seguir se aplica a usando a página de propriedades para editar os controles ActiveX. Você também pode procurar e editar propriedades do ActiveX no novo **propriedades** janela.

### <a name="to-edit-properties-for-an-activex-control"></a>Para editar as propriedades de um controle ActiveX

1. Selecione o **ActiveX** controle.

2. Sobre o **modo de exibição** menu, clique em **página de propriedades** e exibir as propriedades.

3. Faça as alterações necessárias na página de propriedades.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Exibindo e adicionando controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)