---
title: "Especificação de otimização do compilador para um projeto ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.optimization
- vc.appwiz.ATL.vtable
dev_langs:
- C++
helpviewer_keywords:
- ATL_DISABLE_NO_VTABLE macro
- ATL projects, compiler optimization
- ATL_NO_VTABLE macro
ms.assetid: 7f379318-66d5-43dd-a53d-530758d3a228
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: abdad4367e75c1971ba5d11af1a60992d1bb3dd4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="specifying-compiler-optimization-for-an-atl-project"></a>Especificação de otimização do compilador para um projeto do ATL
Por padrão, o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md) gera novas classes com a macro ATL_NO_VTABLE, da seguinte maneira:  
  
```  
class ATL_NO_VTABLE CProjName  
{  
 ...  
};  
```  
  
 Em seguida, ATL define _ATL_NO_VTABLE da seguinte maneira:  
  
```  
#ifdef _ATL_DISABLE_NO_VTABLE  
 #define ATL_NO_VTABLE  
#else  
 #define ATL_NO_VTABLE __declspec(novtable)  
#endif  
```  
  
 Se você não definir _ATL_DISABLE_NO_VTABLE, a macro ATL_NO_VTABLE se expande para `declspec(novtable)`. Usando `declspec(novtable)`em uma classe de declaração impede que o ponteiro vtable que está sendo inicializada no construtor da classe e do destruidor. Quando você compila seu projeto, o vinculador elimina vtable e todas as funções para o qual aponta vtable.  
  
 Você deve usar ATL_NO_VTABLE e consequentemente `declspec(novtable)`, com apenas as classes base que não são diretamente criáveis. Você não deve usar `declspec(novtable)` com a classe mais derivada em seu projeto, porque essa classe (geralmente [CComObject](../../atl/reference/ccomobject-class.md), [CComAggObject](../../atl/reference/ccomaggobject-class.md), ou [CComPolyObject](../../atl/reference/ccompolyobject-class.md)) inicializa o ponteiro vtable para seu projeto.  
  
 Você não deve chamar funções virtuais do construtor de qualquer objeto que usa `declspec(novtable)`. Você deve mover as chamadas para o [FinalConstruct](ccomobjectrootex-class.md#finalconstruct) método.  

  
 Se você não tiver certeza se você deve usar o `declspec(novtable)` modificador, você pode remover a macro ATL_NO_VTABLE de qualquer definição de classe, ou você pode desabilitá-lo globalmente, especificando  
  
```  
#define _ATL_DISABLE_NO_VTABLE  
```  
  
 no Stdafx. h, antes de todas as outra ATL arquivos de cabeçalho são incluídos.  
  
## <a name="see-also"></a>Consulte também  
 [ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de Desktop com assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [novtable](../../cpp/novtable.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


