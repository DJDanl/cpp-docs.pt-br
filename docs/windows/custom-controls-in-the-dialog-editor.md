---
title: Controles personalizados no Editor de caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- Custom Control
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], templates
- custom controls [Visual Studio], dialog boxes
- custom controls [Visual Studio]
- dialog box controls, custom (user) controls
- Dialog editor, custom controls
ms.assetid: f494b314-4000-4bbe-bbd0-4b18fb71ede1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0b197baa61d741452219529e44be0e9ba1a154ce
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39651045"
---
# <a name="custom-controls-in-the-dialog-editor"></a>Controles personalizados no Editor de Caixa de Diálogo
O editor de caixa de diálogo permite usar existente "custom" ou controles de "usuário" em um modelo de caixa de diálogo.  
  
> [!NOTE]
>  Controles personalizados nesse sentido não são deve ser confundido com controles ActiveX. Controles ActiveX foram chamados de controles personalizados do OLE. Além disso, não confunda esses controles com os controles desenhados pelo proprietário no Windows.  
  
 Essa funcionalidade destina-se a permitem que você use controles diferentes daqueles fornecidos pelo Windows. Em tempo de execução, o controle está associado uma classe de janela (não o mesmo que uma classe do C++). Uma maneira mais comum para realizar a mesma tarefa é instalar qualquer controle, como um controle estático, na caixa de diálogo. Em seguida, no tempo de execução, além de [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) de função, remova esse controle e substituí-lo com seu próprio controle personalizado.  
  
 Essa é uma técnica antiga. É recomendável na maioria dos casos para escrever um controle ActiveX ou um controle comum do Windows de subclasse de hoje.  
  
 Para esses controles personalizados, você está limitado a:  
  
-   Definir o local na caixa de diálogo.  
  
-   Digitando uma legenda.  
  
-   Identifica o nome da classe do Windows do controle (o código do aplicativo deve registrar o controle com esse nome).  
  
-   Digitar um valor hexadecimal de 32 bits que define o estilo do controle.  
  
-   Definindo o estilo estendido.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)