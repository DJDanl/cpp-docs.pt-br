---
title: Adicionando uma nova Interface em um projeto do ATL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.interface
dev_langs:
- C++
helpviewer_keywords:
- interfaces, adding to ATL objects
- Implement Interface ATL wizard
- controls [ATL], interfaces
- ATL projects, adding interfaces
ms.assetid: 7d34b023-2c6b-4155-aca3-d47a40968063
caps.latest.revision: 10
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
translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: 8e4916c60310dd8dcbf0bb9e8c1f151309a32621
ms.lasthandoff: 02/25/2017

---
# <a name="adding-a-new-interface-in-an-atl-project"></a>Adicionando uma nova Interface em um projeto do ATL
Quando você adiciona uma interface para o objeto ou controle, você criar funções de fora o stub para cada método na interface. Em seu objeto ou controle, você pode adicionar apenas interfaces atualmente encontradas em uma biblioteca de tipo existente. Além disso, a classe na qual você adiciona a interface deve implementar o [BEGIN_COM_MAP](http://msdn.microsoft.com/library/ead2a1e3-334d-44ad-bb1f-b94bb14c2333) macro ou, se o projeto for atribuído, ele deve ter o `coclass` atributo.  
  
 Você pode adicionar uma nova interface para o controle de uma das duas maneiras: manualmente ou usando os assistentes de código no modo de exibição de classe.  
  
### <a name="to-use-code-wizards-in-class-view-to-add-an-interface-to-an-existing-object-or-control"></a>Usar assistentes de código no modo de exibição de classe para adicionar uma interface para um objeto existente ou controle  
  
1.  Em [Class View](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome da classe de um controle. Por exemplo, um controle total ou controle composto ou qualquer outra classe de controle que implementa uma macro BEGIN_COM_MAP em seu arquivo de cabeçalho.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **implementar Interface**.  
  
3.  Selecione as interfaces para implementar o [implementar Interface assistente](../../ide/implement-interface-wizard.md). Se a interface não existir em qualquer typelib disponível, em seguida, adicione-lo manualmente no arquivo. idl.  
  
### <a name="to-add-a-new-interface-manually"></a>Para adicionar uma nova interface manualmente  
  
1.  Adicione a definição de sua nova interface para o arquivo. idl.  
  
2.  Derive o objeto ou o controle da interface.  
  
3.  Criar um novo [COM_INTERFACE_ENTRY](http://msdn.microsoft.com/library/c5363b8b-a1a2-471e-ad3a-d472f6c356c5) para a interface ou, se o projeto for atribuído, adicione o `coclass` atributo.  
  
4.  Implementar métodos na interface.  
  
## <a name="see-also"></a>Consulte também  
 [ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de Desktop com assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


