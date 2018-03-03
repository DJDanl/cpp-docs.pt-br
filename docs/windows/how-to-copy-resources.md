---
title: 'Como: copiar recursos | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.resvw.resource.copying
- vs.resvw.resource.copying
dev_langs:
- C++
helpviewer_keywords:
- resources [Visual Studio], moving between files
- resources [Visual Studio], copying
- resource files, copying or moving resources between
- resource files, tiling
- .rc files, copying resources between
- rc files, copying resources between
ms.assetid: 65f523e8-017f-4fc6-82d1-083c56d9131f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4ac30e57c0c833f5d26cf9aa8a9ed4ba43946bb3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-copy-resources"></a>Como copiar recursos
Você pode copiar recursos de um arquivo para outro sem alterá-los ou você pode [alterar o idioma ou a condição de um recurso ao copiá-la](../windows/how-to-change-the-language-or-condition-of-a-resource-while-copying.md).  
  
 Você possa facilmente copiar recursos de um recurso existente ou arquivo executável para o arquivo de recurso atual. Para fazer isso, você abra ambos os arquivos que contenham recursos ao mesmo tempo e arrasta itens de um arquivo para outro ou copie e cole entre os dois arquivos. Esse método funciona para arquivos de script (. rc) do recurso e arquivos de modelo (. rct) de recursos, bem como arquivos executáveis (.exe).  
  
> [!NOTE]
>  O Visual C++ inclui arquivos de recursos de exemplo que você pode usar em seu próprio aplicativo. Para obter mais informações, consulte [clip-art: recursos comuns](http://msdn.microsoft.com/en-us/9bac2891-b6b3-49ec-a287-cec850c707e0).  
  
 Você pode usar o método de arrastar e soltar entre arquivos. rc que estão abertos [fora do projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
### <a name="to-copy-resources-between-files-using-the-drag-and-drop-method"></a>Copiar recursos entre arquivos usando o método de arrastar e soltar  
  
1.  Abra os dois arquivos de recurso autônomos (para obter mais informações, consulte [exibir recursos em um arquivo fora de um projeto. rc](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)). Por exemplo, abra Source1.rc e Source2.rc.  
  
2.  Dentro do primeiro arquivo. RC, clique no recurso que você deseja copiar. Por exemplo, no Source1.rc, clique em IDD_DIALOG1.  
  
3.  Mantenha a tecla CTRL pressionada e arraste o recurso para o segundo arquivo. rc. Por exemplo, arraste IDD_DIALOG1 de Source1.rc para Source2.rc.  
  
    > [!NOTE]
    >  Arrastar o recurso sem manter pressionada a tecla CTRL move o recurso em vez de copiá-lo.  
  
### <a name="to-copy-resources-using-copy-and-paste"></a>Copiar recursos usando copiar e colar  
  
1.  Abra os dois arquivos de recurso autônomos (para obter mais informações, consulte [exibir recursos em um arquivo fora de um projeto. rc](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)). Por exemplo, Source1.rc e Source2.rc.  
  
2.  No arquivo de origem do qual você deseja copiar um recurso (por exemplo, Source1.rc), um recurso de atalho e escolha **cópia** no menu de atalho.  
  
3.  Clique no arquivo de recurso para o qual você deseja colar o recurso (por exemplo, Source2.rc). Escolha **colar** no menu de atalho.  
  
    > [!NOTE]
    >  Você não pode arrastar e soltar, copiar, recortar ou colar entre arquivos de recurso no projeto (modo de exibição de recursos) e arquivos. rc autônomo (aqueles abertos em janelas de documento). Você pode fazer isso em versões anteriores do produto.  
  
    > [!NOTE]
    >  Para evitar conflitos com nomes de símbolos ou valores no arquivo existente, Visual C++ pode alterar o valor de símbolo do recurso transferidos ou o nome de símbolo e o valor quando você os copia para o novo arquivo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Como: abrir um arquivo de Script de recurso fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)