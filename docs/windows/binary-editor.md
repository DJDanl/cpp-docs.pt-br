---
title: Editor binário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.binary.F1
dev_langs:
- C++
helpviewer_keywords:
- editors, Binary
- resources [Visual Studio], editing
- resource editors, Binary editor
- Binary editor
ms.assetid: 2483c48b-1252-4dbc-826b-82e6c1a0e9cb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: aa381c42f03bcc77575464af8f8c53ca83e0af81
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650060"
---
# <a name="binary-editor"></a>Editor binário
> [!WARNING]
>  O **Editor binário** não está disponível nas edições Express.  
  
 Editor binário permite que você edite qualquer recurso no nível binário em formato hexadecimal ou ASCII. Você também pode usar o [comando Find](/visualstudio/ide/reference/find-command) para pesquisar cadeias de caracteres ASCII ou bytes hexadecimais. Você deve usar o **binário** editor somente quando precisar exibir ou fazer pequenas alterações em recursos personalizados ou tipos de recursos não suportados pelo ambiente do Visual Studio.  
  
 Para abrir o **Editor binário**, primeiro escolha **arquivo** > **novo** > **arquivo** no menu principal, selecione o arquivo que deseja editar e, em seguida, clique na seta suspensa ao lado de **aberto** botão e escolha **abrir com** > **Editor binário**.  
  
> [!CAUTION]
>  Edição de recursos, como caixas de diálogo, imagens ou menus no editor binário é perigoso. A edição incorreta pode corromper o recurso, tornando-a ilegível em seu editor nativo.  
  
> [!TIP]
>  Ao usar o **binário** editor, em muitos casos, pode clicar duas vezes para exibir um menu de atalho de comandos específicos ao recurso. Os comandos disponíveis dependem do que o cursor está apontando. Por exemplo, se você clicar em enquanto estiver apontando para o **binário** o menu de atalho do editor com valores hexadecimais selecionados, mostra as **Recortar**, **cópia**, e **colar**  comandos.  
  
 Com o **binário** editor, você pode:  
  
-   [Abrir um recurso para edição binária](../windows/opening-a-resource-for-binary-editing.md)  
  
-   [Editar dados binários](../windows/editing-binary-data.md)  
  
-   [Localizar dados binários](../windows/finding-binary-data.md)  
  
-   [Criar um novo recurso personalizado ou dados](../windows/creating-a-new-custom-or-data-resource.md)  
  
## <a name="managed-resources"></a>Recursos gerenciados  
 Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o **binário** editor para trabalhar com arquivos de recursos em projetos de gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)