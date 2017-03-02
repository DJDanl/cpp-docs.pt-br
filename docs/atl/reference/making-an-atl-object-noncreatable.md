---
title: Tornando um Noncreatable de objeto ATL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: b812c2d4bfeb0663d62051c05829f25dc7139faf
ms.lasthandoff: 02/25/2017

---
# <a name="making-an-atl-object-noncreatable"></a>Tornando um Noncreatable de objeto do ATL
Você pode alterar os atributos de um objeto COM baseados em ATL para que um cliente não pode criar diretamente o objeto. Nesse caso, o objeto deve ser retornado por uma chamada de método em outro objeto em vez de criado diretamente.  
  
### <a name="to-make-an-object-noncreatable"></a>Para fazer um objeto noncreatable  
  
1.  Remover o [OBJECT_ENTRY_AUTO](http://msdn.microsoft.com/library/5a0f4fa5-0905-43d2-b337-e22f979c9e4c) para o objeto. Se você deseja que o objeto noncreatable, mas o controle a ser registrado, substitua OBJECT_ENTRY_AUTO com [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](http://msdn.microsoft.com/library/abdc093c-6502-42de-8419-b7ebf45299d1).  
  
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
 [ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de Desktop com assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


