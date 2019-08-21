---
title: Especificando a otimização do compilador para um projeto ATL
ms.date: 08/19/2019
f1_keywords:
- vc.appwiz.ATL.optimization
- vc.appwiz.ATL.vtable
helpviewer_keywords:
- ATL_DISABLE_NO_VTABLE macro
- ATL projects, compiler optimization
- ATL_NO_VTABLE macro
ms.assetid: 7f379318-66d5-43dd-a53d-530758d3a228
ms.openlocfilehash: c3b00823cb33be952451c3cc9e370c99140acc3c
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630607"
---
# <a name="specifying-compiler-optimization-for-an-atl-project"></a>Especificando a otimização do compilador para um projeto ATL

Por padrão, o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md) gera novas classes com a macro ATL_NO_VTABLE, da seguinte maneira:

```
class ATL_NO_VTABLE CProjName
{
...
};
```

Em seguida, o ATL define _ATL_NO_VTABLE da seguinte maneira:

```
#ifdef _ATL_DISABLE_NO_VTABLE
#define ATL_NO_VTABLE
#else
#define ATL_NO_VTABLE __declspec(novtable)
#endif
```

Se você não definir _ATL_DISABLE_NO_VTABLE, a macro ATL_NO_VTABLE se expandirá para `declspec(novtable)`. Usar `declspec(novtable)`em uma declaração de classe impede que o ponteiro vtable seja inicializado no construtor de classe e no destruidor. Quando você cria seu projeto, o vinculador elimina as funções vtable e All às quais os pontos vtable.

Você deve usar ATL_NO_VTABLE e consequentemente `declspec(novtable)`, com apenas classes base que não são diretamente creatable. Você não deve usar `declspec(novtable)` com a classe mais derivada em seu projeto, pois essa classe (geralmente [CComObject](../../atl/reference/ccomobject-class.md), [CComAggObject](../../atl/reference/ccomaggobject-class.md)ou [CComPolyObject](../../atl/reference/ccompolyobject-class.md)) inicializa o ponteiro vtable para seu projeto.

Você não deve chamar funções virtuais do construtor de qualquer objeto que use `declspec(novtable)`o. Você deve mover essas chamadas para o método [FinalConstruct](ccomobjectrootex-class.md#finalconstruct) .

Se você não tiver certeza se deve usar o `declspec(novtable)` modificador, você pode remover a macro ATL_NO_VTABLE de qualquer definição de classe ou pode desabilitá-la globalmente especificando

```
#define _ATL_DISABLE_NO_VTABLE
```

em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior), antes de todos os outros arquivos de cabeçalho ATL serem incluídos.

## <a name="see-also"></a>Consulte também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Tipos de projeto do C++ no Visual Studio](../../build/reference/visual-cpp-project-types.md)<br/>
[Programando com código de tempo de execução C e da ATL](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[novtable](../../cpp/novtable.md)<br/>
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)
