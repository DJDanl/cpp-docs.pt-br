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
ms.openlocfilehash: 2c2bca249958e4d25ab5377540525da34802ac04
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="custom-controls-in-the-dialog-editor"></a>Controles personalizados no Editor de Caixa de Diálogo
O editor de caixa de diálogo lhe permite usar existente "custom" ou controles de "usuário" em um modelo de caixa de diálogo.  
  
> [!NOTE]
>  Controles personalizados nesse sentido não são deve ser confundido com controles ActiveX. Controles ActiveX foram chamados de controles personalizados OLE. Além disso, não confunda esses controles com os controles desenhados pelo proprietário no Windows.  
  
 Essa funcionalidade destina-se para permitir o uso de controles que não sejam aqueles fornecidos pelo Windows. Em tempo de execução, o controle está associado uma classe de janela (não o mesmo que uma classe C++). Uma maneira mais comum para realizar a mesma tarefa é instalar qualquer controle, como um controle estático, na caixa de diálogo. Em seguida, em tempo de execução, além de [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) funcionar, remova esse controle e substituí-lo com seu próprio controle personalizado.  
  
 Essa é uma técnica antiga. Hoje é recomendável na maioria dos casos para gravar um controle ActiveX ou uma subclasse de um controle comum do Windows.  
  
 Para esses controles personalizados, você está limitado a:  
  
-   Definir o local na caixa de diálogo.  
  
-   Digite uma legenda.  
  
-   Identifica o nome da classe do Windows do controle (código do aplicativo deve registrar o controle com este nome).  
  
-   Digitar um valor hexadecimal de 32 bits que define o estilo do controle.  
  
-   Definindo o estilo estendido.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

