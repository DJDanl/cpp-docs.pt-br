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
ms.openlocfilehash: 6d5deb511069830de5ea7aa542bb010f57be5af9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33857851"
---
# <a name="binary-editor"></a>Editor binário
> [!WARNING]
>  O Editor binário não está disponível em edições Express.  
  
 Editor binário permite que você edite qualquer recurso no nível binário em formato hexadecimal ou ASCII. Você também pode usar o [comando localizar](/visualstudio/ide/reference/find-command) para pesquisar cadeias de caracteres ASCII ou bytes hexadecimais. Você deve usar o editor binário somente quando você precisa exibir ou fazer pequenas alterações em recursos personalizados ou tipos de recursos não suportados pelo ambiente do Visual Studio.  
  
 Para abrir o Editor binário, primeiro escolha **arquivo &#124; novo &#124; arquivo** no menu principal, selecione o arquivo que você deseja editar e clique na seta suspensa ao lado de **abrir** botão e, em seguida, escolha **Abrir com &#124; Editor binário**.  
  
> [!CAUTION]
>  É perigoso, edição de recursos, como caixas de diálogo, imagens ou menus no editor binário. A edição incorreta pode corromper o recurso, tornando-a ilegível em seu editor nativo.  
  
> [!TIP]
>  Ao usar o editor binário, em muitos casos, clique para exibir um menu de atalho de comandos específicos do recurso. Os comandos disponíveis dependem de que o cursor está apontando. Por exemplo, se você clicar em ao apontando para editor binário com valores hexadecimais selecionados, o menu de atalho mostra o **Recortar**, **cópia**, e **colar** comandos.  
  
 Com o editor binário, você pode:  
  
-   [Abrir um recurso para edição binária](../windows/opening-a-resource-for-binary-editing.md)  
  
-   [Editar dados binários](../windows/editing-binary-data.md)  
  
-   [Localizar dados binários](../windows/finding-binary-data.md)  
  
-   [Criar um novo recurso personalizados ou de dados](../windows/creating-a-new-custom-or-data-resource.md)  
  
## <a name="managed-resources"></a>Recursos gerenciados  
 Você pode usar o [editor de imagem](../windows/image-editor-for-icons.md) e o editor binário para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)

