---
title: Adicionando uma classe do MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.classes.adding.mfc
dev_langs:
- C++
helpviewer_keywords:
- classes [C++], adding MFC
- MFC, adding classes
ms.assetid: 9a96b67f-40bf-43d4-8872-2f8dfc5404f1
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bf285131bf7acd7a6b0a14b564c5e53518a9979a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="adding-an-mfc-class"></a>Adicionando uma classe do MFC
Para adicionar classes derivadas de classes da biblioteca Microsoft Foundation Class (MFC) ao seu projeto, use o **Add Class** disponível no comando [Class View](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925). Especifique o nome da nova classe, selecione a classe base e selecione a ID da caixa de diálogo com a qual ele está associado (se houver). O Assistente de código cria um arquivo de cabeçalho e um arquivo de implementação e os adiciona ao seu projeto.  
  
> [!NOTE]
>  Você pode adicionar classes MFC para um aplicativo COM ATL se você inicialmente [criou o aplicativo com suporte a MFC](../../atl/reference/mfc-support-in-atl-projects.md). Você também pode adicionar classes MFC para projetos do Win32 que têm suporte do MFC.  
  
### <a name="to-add-an-mfc-class-to-your-project"></a>Para adicionar uma classe do MFC para seu projeto  
  
1.  No modo de exibição de classe, clique no nome do projeto. Clique em **adicionar** e, em seguida, clique em **Add Class** para abrir o [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo.  
  
2.  No painel de modelos, selecione **classe do MFC** e pressione a **adicionar** botão.  
  
3.  Definir as configurações para a nova classe de [MFC Class Wizard](../../mfc/reference/mfc-add-class-wizard.md) caixa de diálogo.  
  
4.  Clique em **concluir** para fechar o assistente e exibir a nova classe no modo de exibição de classe. Você também pode exibir os arquivos criados pelo assistente no **Solution Explorer**.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Visão geral da classe](../../mfc/class-library-overview.md)


