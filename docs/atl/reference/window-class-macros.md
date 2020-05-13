---
title: Macros de classe de janela
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::DECLARE_WND_CLASS
- atlwin/ATL::DECLARE_WND_SUPERCLASS
- atlwin/ATL::DECLARE_WND_CLASS_EX
ms.assetid: ce18681a-2bab-4453-9895-0f3ea47c2b24
ms.openlocfilehash: 18c0912c506bc52421b18d36346204b557c0fc5c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325726"
---
# <a name="window-class-macros"></a>Macros de classe de janela

Essas macros definem utilitários de classe de janela.

|||
|-|-|
|[Declare_wnd_class](#declare_wnd_class)|Permite especificar o nome de uma nova classe de janela.|
|[DECLARE_WND_CLASS2](#declare_wnd_class2)|(Visual Studio 2017) Permite especificar o nome de uma nova classe de janela e a classe de fechamento cujo procedimento de janela a nova classe usará.|
|[Declare_wnd_superclass](#declare_wnd_superclass)|Permite especificar o nome de uma classe de janela existente na qual uma nova classe de janela será baseada.|
|[Declare_wnd_class_ex](#declare_wnd_class_ex)|Permite especificar os parâmetros de uma classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="declare_wnd_class"></a><a name="declare_wnd_class"></a>Declare_wnd_class

Permite especificar o nome de uma nova classe de janela. Coloque esta macro na classe de controle de um controle ATL ActiveX.

```
DECLARE_WND_CLASS( WndClassName )
```

### <a name="parameters"></a>Parâmetros

*Wndclassname*<br/>
[em] O nome da nova turma da janela. Se NULO, atl gerará um nome de classe de janela.

### <a name="remarks"></a>Comentários

Se você estiver usando a opção /permissivo-compilador, então DECLARE_WND_CLASS causará um erro de compilador; use DECLARE_WND_CLASS2 em vez disso.

DECLARE_WND_CLASS permite especificar o nome de uma nova classe de janela cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). DECLARE_WND_CLASS define a nova classe de janela, implementando a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

DECLARE_WND_CLASS especifica os seguintes estilos para a nova janela:

- CS_HREDRAW

- CS_VREDRAW

- CS_DBLCLKS

DECLARE_WND_CLASS também especifica a cor de fundo da janela padrão. Use a [DECLARE_WND_CLASS_EX](#declare_wnd_class_ex) macro para fornecer seus próprios estilos e cor de fundo.

[CWindowImpl](cwindowimpl-class.md) usa a macro DECLARE_WND_CLASS para criar uma janela baseada em uma nova classe de janela. Para substituir esse comportamento, use a [macro DECLARE_WND_SUPERCLASS](#declare_wnd_superclass) ou forneça sua própria implementação da função [GetWndClassInfo.](cwindowimpl-class.md#getwndclassinfo)

Para obter mais informações sobre o uso de janelas no ATL, consulte o artigo [ATL Window Classes](../../atl/atl-window-classes.md).

## <a name="declare_wnd_class2"></a><a name="declare_wnd_class2"></a>DECLARE_WND_CLASS2

(Visual Studio 2017) Semelhante ao DECLARE_WND_CLASS, mas com um parâmetro extra que evita um erro de nome dependente ao compilar com a opção /permissivo.

```
DECLARE_WND_CLASS2( WndClassName, EnclosingClass )
```

### <a name="parameters"></a>Parâmetros

*Wndclassname*<br/>
[em] O nome da nova turma da janela. Se NULO, atl gerará um nome de classe de janela.

*EnclosingClass*<br/>
[em] O nome da classe da janela que inclui a nova classe de janelas. Não pode ser NULL.

### <a name="remarks"></a>Comentários

Se você estiver usando a opção /permissivo, então DECLARE_WND_CLASS causará um erro de compilação porque contém um nome dependente. DECLARE_WND_CLASS2 exige que você nomeie explicitamente a classe em que esta macro é usada e não cause o erro sob a bandeira /permissiva.
Caso contrário, esta macro é idêntica ao [DECLARE_WND_CLASS](#declare_wnd_class).

## <a name="declare_wnd_superclass"></a><a name="declare_wnd_superclass"></a>Declare_wnd_superclass

Permite especificar os parâmetros de uma classe. Coloque esta macro na classe de controle de um controle ATL ActiveX.

```
DECLARE_WND_SUPERCLASS( WndClassName, OrigWndClassName )
```

### <a name="parameters"></a>Parâmetros

*Wndclassname*<br/>
[em] O nome da classe de janela que irá superclasse *OrigWndClassName*. Se NULO, atl gerará um nome de classe de janela.

*OrigWndClassName*<br/>
[em] O nome de uma classe de janelas existente.

### <a name="remarks"></a>Comentários

Essa macro permite que você especifique o nome de uma classe de janela que superclassifique uma classe de janela existente. [O CWndClassInfo](cwndclassinfo-class.md) gerencia as informações da superclasse.

DECLARE_WND_SUPERCLASS implementa a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

Por padrão, [o CWindowImpl](cwindowimpl-class.md) usa a [macro DECLARE_WND_CLASS](#declare_wnd_class) para criar uma janela baseada em uma nova classe de janela. Ao especificar a DECLARE_WND_SUPERCLASS `CWindowImpl`macro em uma classe derivada, a classe janela será baseada em uma classe existente, mas usará o procedimento da janela. Esta técnica é chamada de superclasse.

Além de usar as macros DECLARE_WND_CLASS e DECLARE_WND_SUPERCLASS, você pode substituir a função [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) com sua própria implementação.

Para obter mais informações sobre o uso de janelas no ATL, consulte o artigo [ATL Window Classes](../../atl/atl-window-classes.md).

## <a name="declare_wnd_class_ex"></a><a name="declare_wnd_class_ex"></a>Declare_wnd_class_ex

Permite especificar o nome de uma classe de janela existente na qual uma nova classe de janela será baseada. Coloque esta macro na classe de controle de um controle ATL ActiveX.

```
DECLARE_WND_CLASS_EX( WndClassName, style, bkgnd )
```

### <a name="parameters"></a>Parâmetros

*Wndclassname*<br/>
[em] O nome da nova turma da janela. Se NULO, atl gerará um nome de classe de janela.

*style*<br/>
[em] O estilo da janela.

*bkgnd*<br/>
[em] A cor de fundo da janela.

### <a name="remarks"></a>Comentários

Essa macro permite especificar os parâmetros de classe de uma nova classe de janela, cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). DECLARE_WND_CLASS_EX define a nova classe de janela, implementando a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

Se você quiser usar os estilos padrão e a cor de fundo, use a [DECLARE_WND_CLASS](#declare_wnd_class) macro. Para obter mais informações sobre o uso de janelas no ATL, consulte o artigo [ATL Window Classes](../../atl/atl-window-classes.md).

## <a name="see-also"></a>Confira também

[Macros](atl-macros.md)
