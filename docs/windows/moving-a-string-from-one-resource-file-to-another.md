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
ms.openlocfilehash: 194a37bf631ab3226ad88208acfcf86a7a7a2926
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39603258"
---
# <a name="moving-a-string-from-one-resource-file-to-another"></a>Movendo uma cadeia de caracteres de um arquivo de recurso para outro
### <a name="to-move-a-string-from-one-resource-script-file-to-another"></a>Para mover uma cadeia de caracteres do arquivo de script de um recurso para outro  
  
1.  Abra as tabelas de cadeia de caracteres em ambos os arquivos. rc. (Para obter mais informações, consulte [exibir recursos em um recurso Script arquivo externa de um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).)  
  
    > [!NOTE]
    >  Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Com a cadeia de caracteres que você deseja mover e escolha o botão direito **Recortar** no menu de atalho.  
  
3.  Coloque o cursor no destino **Editor de cadeia de caracteres** janela.  
  
4.  No arquivo. RC para o qual você deseja mover a cadeia de caracteres, com o botão direito e escolha **colar** no menu de atalho.  
  
    > [!NOTE]
    >  Se o **ID** ou **valor** dos conflitos com um cadeia de caracteres movidos **ID** ou **valor** no arquivo de destino, ambos os **Identificação** ou o **valor** das alterações de cadeia de caracteres movidos. Se uma cadeia de caracteres existe com o mesmo **identificação**, o **ID** das alterações de cadeia de caracteres movidos. Se uma cadeia de caracteres existe com o mesmo **valor**, o **valor** das alterações de cadeia de caracteres movidos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
## <a name="requirements"></a>Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de cadeia de caracteres](../windows/string-editor.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Personalizando layouts de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio)   