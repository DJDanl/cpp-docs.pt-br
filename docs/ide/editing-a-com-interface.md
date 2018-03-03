---
title: Editando uma Interface COM | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.com.editing.interfaces
dev_langs:
- C++
helpviewer_keywords:
- methods [C++], adding to COM interfaces
- COM interfaces, editing
- properties [C++], adding to COM interfaces
ms.assetid: 6c2909e0-af2d-4a37-bb39-ed372e6129cf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b8911f23ce8e28f2da13c3d8305f4f13a861bb60
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="editing-a-com-interface"></a>Editando uma interface COM
Usando comandos do menu de atalho do modo de exibição de classe, você pode definir novos métodos e propriedades para as interfaces COM seus projetos do Visual C++. Além disso, na caixa de ferramentas, você pode definir eventos para controles ActiveX.  
  
 Para classes de objeto ATL e MFC-com base em COM, você pode editar a implementação da classe ao mesmo tempo que você editar a interface.  
  
> [!NOTE]
>  Para interfaces que você tenha definido fora do **Adicionar classe** caixa de diálogo Visual C++ adiciona os métodos ou propriedades para o arquivo. idl e adicionou stubs para as classes que implementam métodos, mesmo quando as interfaces são adicionadas manualmente.  
  
 Os três assistentes a seguir o ajudarão a personalizar interfaces existentes. Estão disponíveis no modo de exibição de classe:  
  
|Wizard|Tipo de projeto|  
|------------|------------------|  
|[Assistente para adicionar propriedade](../ide/names-add-property-wizard.md)|Projetos ATL ou do MFC com suporte ATL. Clique com botão direito a interface para o qual você deseja adicionar a propriedade.<br /><br /> Visual C++ detecta o tipo de projeto e modifica as opções do Assistente para adicionar propriedade adequadamente:<br /><br /> -Para dispinterfaces em projetos criados usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), invocar o Assistente para adicionar propriedade fornece opções específicas a MFC.<br />-Para interfaces de controle ActiveX MFC, o Assistente para adicionar propriedade fornece uma lista de métodos de estoque e propriedades que você pode usar conforme fornecido ou personalizar para seu controle.<br />-Para todas as outras interfaces, os assistentes de propriedade adicionar fornecem opções úteis na maioria das situações.|  
|[Assistente de Adição de Método](../ide/add-method-wizard.md)|Projetos ATL ou do MFC com suporte ATL. Clique com botão direito a interface para o qual você deseja adicionar o método.<br /><br /> Visual C++ detecta o tipo de projeto e modifica as opções do Assistente para adicionar método adequadamente:<br /><br /> -Para dispinterfaces em projetos criados usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), invocar o Assistente para adicionar método fornece opções específicas a MFC.<br />-Para interfaces de controle ActiveX MFC, o Assistente para adicionar método fornece uma lista de métodos de estoque e propriedades que você pode usar conforme fornecido ou personalizar para seu controle.<br />-Para todas as outras interfaces, o **Adicionar método** assistentes fornecem opções úteis na maioria das situações.|  
  
 Além disso, você pode implementar novas interfaces do controle COM classe de controle do objeto no modo de exibição de classe e clicando em [implementar Interface](../ide/implement-interface-wizard.md).  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)