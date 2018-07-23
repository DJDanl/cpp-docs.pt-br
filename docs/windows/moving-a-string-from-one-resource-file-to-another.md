---
title: Movendo uma cadeia de caracteres de um arquivo de recurso para outro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], moving between files
- resource script files, moving strings
- string editing, moving strings between resources
- String editor, moving strings between files
ms.assetid: 94f8ee81-9b4c-4788-ba95-68c58db38029
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1481f04b88d6ab63486885d93b971c3023d3e0d2
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879263"
---
# <a name="moving-a-string-from-one-resource-file-to-another"></a>Movendo uma cadeia de caracteres de um arquivo de recurso para outro
### <a name="to-move-a-string-from-one-resource-script-file-to-another"></a>Para mover uma cadeia de caracteres do arquivo de script de um recurso para outro  
  
1.  Abra as tabelas de cadeia de caracteres em ambos os arquivos. rc. (Para obter mais informações, consulte [exibir recursos em um recurso Script arquivo fora de um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).)  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Clique com botão direito a cadeia de caracteres que você deseja mover e escolha **Recortar** no menu de atalho.  
  
3.  Posicione o cursor no destino **Editor de cadeia de caracteres** janela.  
  
4.  No arquivo. RC para o qual você deseja mover a cadeia de caracteres, com o botão direito e escolha **colar** no menu de atalho.  
  
    > [!NOTE]
    >  Se o **ID** ou **valor** dos conflitos movido de cadeia de caracteres com um existente **ID** ou **valor** no arquivo de destino, ou o **ID** ou **valor** das alterações de cadeia de caracteres movido. Se existir uma cadeia de caracteres com o mesmo **ID**, o **ID** das alterações de cadeia de caracteres movido. Se existir uma cadeia de caracteres com o mesmo **valor**, o **valor** das alterações de cadeia de caracteres movido.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que se destinam a common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/en-us/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de cadeia de caracteres](../windows/string-editor.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Personalizando layouts de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio)   

