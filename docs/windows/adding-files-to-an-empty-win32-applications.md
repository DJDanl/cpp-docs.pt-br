---
title: Adicionando arquivos a aplicativos Win32 vazios | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- empty projects, adding files
- projects [C++], adding items
- blank projects
- files [C++], adding to projects
ms.assetid: 070098e8-0396-49fe-a697-3daa2f1be6de
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8b3c5df80b9344b4a37d8296dc57b96cfb4f35c8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-files-to-an-empty-win32-applications"></a>Adicionando arquivos a aplicativos Win32 vazios
### <a name="to-add-your-files-to-an-empty-windows-desktop-application"></a>Para adicionar os arquivos para um aplicativo de área de trabalho do Windows vazio  
  
1.  Selecione o diretório no **Gerenciador de soluções**.  
  
2.  O nome do diretório, clique **adicionar** do menu de atalho e clique **Item existente**.  
  
3.  No **caixa de diálogo Adicionar Item existente**, navegue até os arquivos que você deseja adicionar ao seu projeto.  
  
4.  Clique em **OK**.  
  
 Para adicionar arquivos que não são fonte, cabeçalho ou arquivos de recursos ao seu projeto, clique com botão direito no nó da solução no Gerenciador de soluções e adicione os arquivos ao projeto da mesma maneira. Uma pasta diversos será criada para manter os outros arquivos no seu projeto.  
  
> [!NOTE]
>  Antes de compilar seu projeto, você precisará especificar opções de compilação para esses arquivos para que eles sejam incluídos corretamente em seu aplicativo concluído. Para obter mais informações, consulte [especificando as configurações de projeto com páginas de propriedade](../ide/property-pages-visual-cpp.md) e [Compilando um programa do C/C++](../build/building-c-cpp-programs.md).  
  
## <a name="see-also"></a>Consulte também  
 [Criando um aplicativo de área de trabalho do Windows vazio](../windows/creating-an-empty-windows-desktop-application.md)   
 [Implantando aplicativos](http://msdn.microsoft.com/en-us/4ff8881d-0daf-47e7-bfe7-774c625031b4)