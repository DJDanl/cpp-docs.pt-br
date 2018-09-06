---
title: Especificação de otimização do compilador para um projeto ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 95df1e21bee99914d2f20f194d68e5bfae29e203
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763549"
---
# <a name="specifying-compiler-optimization-for-an-atl-project"></a>Especificação de otimização do compilador para um projeto ATL

Por padrão, o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md) gera novas classes com a macro ATL_NO_VTABLE, da seguinte maneira:

```  
class ATL_NO_VTABLE CProjName  
{  
...  
};  
```

ATL, em seguida, define _ATL_NO_VTABLE da seguinte maneira:

```  
#ifdef _ATL_DISABLE_NO_VTABLE  
#define ATL_NO_VTABLE  
#else  
#define ATL_NO_VTABLE __declspec(novtable)  
#endif  
```

Se você não definir _ATL_DISABLE_NO_VTABLE, a macro ATL_NO_VTABLE se expande para `declspec(novtable)`. Usando `declspec(novtable)`em uma classe declaração impede que o ponteiro vtable que está sendo inicializado no construtor de classe e do destruidor. Quando você compila seu projeto, o vinculador elimina vtable e todas as funções para o qual aponta vtable.

Você deve usar ATL_NO_VTABLE e, consequentemente, `declspec(novtable)`, com apenas classes base que não pode ser criadas diretamente. Você não deve usar `declspec(novtable)` com a classe mais derivada em seu projeto, porque essa classe (normalmente [CComObject](../../atl/reference/ccomobject-class.md), [CComAggObject](../../atl/reference/ccomaggobject-class.md), ou [CComPolyObject](../../atl/reference/ccompolyobject-class.md)) inicializa o ponteiro vtable para seu projeto.

Você não deve chamar funções virtuais do construtor de qualquer objeto que usa `declspec(novtable)`. Você deve mover essas chamadas para o [FinalConstruct](ccomobjectrootex-class.md#finalconstruct) método.  

Se você não tiver certeza se você deve usar o `declspec(novtable)` modificador, você pode remover a macro ATL_NO_VTABLE de qualquer definição de classe, ou você pode desabilitá-lo globalmente, especificando

```  
#define _ATL_DISABLE_NO_VTABLE  
```

em Stdafx. h, antes de todos os outra ATL arquivos de cabeçalho estão incluídos.

## <a name="see-also"></a>Consulte também

[ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
[Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
[Criando projetos da área de trabalho com assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
[Programando com código de tempo de execução de C e ATL](../../atl/programming-with-atl-and-c-run-time-code.md)   
[Conceitos básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)   
[novtable](../../cpp/novtable.md)   
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

