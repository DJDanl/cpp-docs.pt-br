---
title: Fazer um Noncreatable de objeto ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.objects
dev_langs:
- C++
helpviewer_keywords:
- noncreatable ATL objects
- ATL projects, noncreatable objects
ms.assetid: 80d0bca2-dea0-4801-9a85-6243124437f6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0e37779b081de457782ee59324a00cca5fedaea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="making-an-atl-object-noncreatable"></a>Fazer um Noncreatable de objeto ATL
Você pode alterar os atributos de um objeto COM baseado na ATL para que um cliente diretamente não é possível criar o objeto. Nesse caso, o objeto deve ser retornado por meio de uma chamada de método em outro objeto em vez de criado diretamente.  
  
### <a name="to-make-an-object-noncreatable"></a>Para fazer um objeto noncreatable  
  
1.  Remover o [OBJECT_ENTRY_AUTO](object-map-macros.md#object_entry_auto) para o objeto. Se você deseja que o objeto a ser noncreatable, mas o controle a ser registrado, substitua OBJECT_ENTRY_AUTO com [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](object-map-macros.md#object_entry_non_createable_ex_auto).  
  
2.  Adicionar o [noncreatable](../../windows/noncreatable.md) atributo coclass no arquivo. idl. Por exemplo:  
  
 ```  
 [  
    uuid(A1992E3D-3CF0-11D0-826F-00A0C90F2851), 
    helpstring("MyObject"), 
    noncreatable]  
    coclass MyObject  
 {  
 [default] interface IMyInterface;  
 }  
 ```  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de projeto ATL](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de área de trabalho usando os assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

