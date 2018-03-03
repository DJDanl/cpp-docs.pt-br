---
title: "Adicionando controles a uma caixa de diálogo faz com que a caixa de diálogo não funcionem | Microsoft Docs"
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
- controls [C++], troubleshooting
- common controls, troubleshooting
- troubleshooting controls
- dialog boxes, troubleshooting
- dialog box controls, troubleshooting
- InitCommonControls
ms.assetid: b2dd4574-ea59-4343-8d65-b387cead5da6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d0ec4825419c7a9d3c9bc35151b84c327a03325b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-controls-to-a-dialog-causes-the-dialog-to-no-longer-function"></a>A adição de controles a uma caixa de diálogo faz a caixa de diálogo deixar de funcionar
Depois de adicionar um controle comum ou um controle de edição para uma caixa de diálogo, ele não será exibido quando você testar a caixa de diálogo ou a própria caixa de diálogo não aparecerá.  
  
 **Exemplo do problema**  
  
1.  Crie um projeto do Win32, modificando as configurações do aplicativo para que você criar um aplicativo do Windows (não um aplicativo de console).  
  
2.  Em [exibição recursos](../windows/resource-view-window.md), clique duas vezes no arquivo. rc.  
  
3.  A opção de caixa de diálogo, clique duas vezes o **sobre** caixa.  
  
4.  Adicionar uma **controle de endereço IP** à caixa de diálogo.  
  
5.  Salvar e **recompilar tudo**.  
  
6.  Execute o programa.  
  
7.  Na caixa de diálogo **ajuda** menu, clique no **sobre** comando; nenhuma caixa de diálogo caixa é exibida.  
  
 **A causa**  
  
 Atualmente, o editor de caixa de diálogo não adiciona automaticamente código ao seu projeto quando você arrasta e solta os seguintes controles comuns ou controles em uma caixa de diálogo de edição avançada. Nem o Visual Studio fornece um erro ou aviso quando ocorrer esse problema. Você deve adicionar manualmente o código para o controle.  
  
||||  
|-|-|-|  
|Controle deslizante|Controle de árvore|Seletor de data e hora|  
|Controle de rotação|Controle de guia|Calendário mensal|  
|Controle de progresso|Controle de animação|Controle de endereço IP|  
|Tecla de acesso|Controle de edição avançada|Caixa de combinação estendidas|  
|Controle de lista|Controle de edição avançada 2.0|Controle personalizado|  
  
## <a name="the-fix-for-common-controls"></a>A correção para controles comuns  
 Para usar controles comuns em uma caixa de diálogo, você precisa chamar [InitCommonControlsEx](http://msdn.microsoft.com/library/windows/desktop/bb775697) ou **AFXInitCommonControls** antes de criar a caixa de diálogo.  
  
## <a name="the-fix-for-richedit-controls"></a>A correção para controles RichEdit  
 Você deve chamar **LoadLibrary** para controles de edição avançada. Para obter mais informações, consulte [usando o controle RichEdit 1.0 com MFC](../windows/using-the-richedit-1-0-control-with-mfc.md), [sobre Rich editar controles](http://msdn.microsoft.com/library/windows/desktop/bb787873) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)], e [visão geral do controle de edição de Rich](../mfc/overview-of-the-rich-edit-control.md).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [O Editor de caixa de diálogo de solução de problemas](../windows/troubleshooting-the-dialog-editor.md)   
 [Editor de caixa de diálogo](../windows/dialog-editor.md)

