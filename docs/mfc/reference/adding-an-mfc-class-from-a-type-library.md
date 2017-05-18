---
title: Adicionando uma classe do MFC de uma biblioteca de tipo | Documentos do Microsoft
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
- classes [C++], adding MFC
- MFC, adding classes from type libraries
- type libraries, adding MFC classes from
ms.assetid: aba40476-3cfb-47af-990e-ae2e9e0d79cf
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
ms.openlocfilehash: 0aec2c2f83dcc5857134f39f6729ce1ca9aa1acf
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="adding-an-mfc-class-from-a-type-library"></a>Adicionando uma classe do MFC de uma biblioteca de tipos
Use este assistente para criar uma classe do MFC de uma interface em uma biblioteca de tipos disponíveis. Você pode adicionar uma classe do MFC para um [aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md), um [DLL MFC](../../mfc/reference/creating-an-mfc-dll-project.md), ou uma [controle ActiveX MFC](../../mfc/reference/creating-an-mfc-activex-control.md).  
  
> [!NOTE]
>  Você não precisa criar seu projeto MFC com automação habilitada para adicionar uma classe de uma biblioteca de tipos.  
  
 Uma biblioteca de tipos contém uma descrição binária das interfaces expostas por um componente, definindo os métodos junto com seus parâmetros e tipos de retorno. Sua biblioteca de tipos deve ser registrada para aparecer no **bibliotecas de tipos disponíveis** lista Adicionar classe de Typelib assistente. Consulte "Dentro distribuído: tipo de bibliotecas e linguagem integração COM" na biblioteca MSDN para obter mais informações.  
  
### <a name="to-add-an-mfc-class-from-a-type-library"></a>Para adicionar uma classe do MFC de uma biblioteca de tipos  
  
1.  No **Solution Explorer** ou [Class View](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto para o qual você deseja adicionar a classe.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar classe**.  
  
3.  No [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo, no painel de modelos, clique em **classe do MFC de Typelib**e, em seguida, clique em **abrir** para exibir o [Adicionar classe de Typelib assistente](../../mfc/reference/add-class-from-typelib-wizard.md).  
  
 No assistente, você pode adicionar mais de uma classe em uma biblioteca de tipos. Da mesma forma, você pode adicionar classes de mais de uma biblioteca de tipos em uma única sessão de assistente.  
  
 O assistente cria uma classe do MFC, derivada de [COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md), para cada interface que você adicione da biblioteca de tipo selecionado. `COleDispatchDriver`implementa o lado do cliente de automação OLE.  
  
## <a name="see-also"></a>Consulte também  
 [Clientes de automação](../../mfc/automation-clients.md)   
 [Clientes de automação: Usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)


