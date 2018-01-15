---
title: "Especificação de otimização do compilador para um projeto de ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.optimization
- vc.appwiz.ATL.vtable
dev_langs: C++
helpviewer_keywords:
- ATL_DISABLE_NO_VTABLE macro
- ATL projects, compiler optimization
- ATL_NO_VTABLE macro
ms.assetid: 7f379318-66d5-43dd-a53d-530758d3a228
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c6e60f22b7b91567948dfc2efc90935fce266d7e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="specifying-compiler-optimization-for-an-atl-project"></a>Especificação de otimização do compilador para um projeto de ATL
Por padrão, o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md) gera novas classes com a macro ATL_NO_VTABLE, da seguinte maneira:  
  
```  
class ATL_NO_VTABLE CProjName  
{  
 ...  
};  
```  
  
 ATL define _ATL_NO_VTABLE da seguinte maneira:  
  
```  
#ifdef _ATL_DISABLE_NO_VTABLE  
 #define ATL_NO_VTABLE  
#else  
 #define ATL_NO_VTABLE __declspec(novtable)  
#endif  
```  
  
 Se você não definir _ATL_DISABLE_NO_VTABLE, a macro ATL_NO_VTABLE se expande para `declspec(novtable)`. Usando `declspec(novtable)`em uma classe declaração impede que o ponteiro vtable sendo inicializado no construtor de classe e destruidor. Quando você compila seu projeto, o vinculador elimina o vtable e todas as funções para a qual aponta o vtable.  
  
 Você deve usar ATL_NO_VTABLE e, consequentemente, `declspec(novtable)`, com apenas classes base que não são diretamente instanciável. Você não deve usar `declspec(novtable)` com a classe mais derivado em seu projeto, porque essa classe (geralmente [CComObject](../../atl/reference/ccomobject-class.md), [CComAggObject](../../atl/reference/ccomaggobject-class.md), ou [CComPolyObject](../../atl/reference/ccompolyobject-class.md)) inicializa o ponteiro vtable para seu projeto.  
  
 Você não deve chamar funções virtuais a partir do construtor de qualquer objeto que usa `declspec(novtable)`. Você deve mover essas chamadas para o [FinalConstruct](ccomobjectrootex-class.md#finalconstruct) método.  

  
 Se você não tiver certeza se você deve usar o `declspec(novtable)` modificador, você pode remover a macro ATL_NO_VTABLE de qualquer definição de classe ou você pode desabilitá-lo globalmente, especificando  
  
```  
#define _ATL_DISABLE_NO_VTABLE  
```  
  
 em Stdafx. h, antes de todos os outros ATL arquivos de cabeçalho são incluídos.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de projeto ATL](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de área de trabalho usando os assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [novtable](../../cpp/novtable.md)   
 [Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

