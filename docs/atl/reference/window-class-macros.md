---
title: Macros de classe de janela
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::DECLARE_WND_CLASS
- atlwin/ATL::DECLARE_WND_SUPERCLASS
- atlwin/ATL::DECLARE_WND_CLASS_EX
ms.assetid: ce18681a-2bab-4453-9895-0f3ea47c2b24
ms.openlocfilehash: c4617a04c199741b97316122456e417a94275e89
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57260992"
---
# <a name="window-class-macros"></a>Macros de classe de janela

Essas macros definem os utilitários de classe de janela.

|||
|-|-|
|[DECLARE_WND_CLASS](#declare_wnd_class)|Permite que você especifique o nome de uma nova classe de janela.|
|[DECLARE_WND_CLASS2](#declare_wnd_class2)|(Visual Studio 2017) Permite que você especifique o nome da classe delimitadora cujo procedimento de janela usará a nova classe e de uma nova classe de janela.|
|[DECLARE_WND_SUPERCLASS](#declare_wnd_superclass)|Permite que você especifique o nome de uma classe de janela existente no qual uma nova classe de janela será baseada.|
|[DECLARE_WND_CLASS_EX](#declare_wnd_class_ex)|Permite que você especifique os parâmetros de uma classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="declare_wnd_class"></a>  DECLARE_WND_CLASS

Permite que você especifique o nome de uma nova classe de janela. Colocar essa macro na classe de controle de um controle ActiveX ATL.

```
DECLARE_WND_CLASS( WndClassName )
```

### <a name="parameters"></a>Parâmetros

*WndClassName*<br/>
[in] O nome da nova classe de janela. Se for NULL, o ATL irá gerar um nome de classe de janela.

### <a name="remarks"></a>Comentários

Se você estiver usando a opção /permissive-compiler, DECLARE_WND_CLASS causará um erro do compilador; Use DECLARE_WND_CLASS2 em vez disso.

DECLARE_WND_CLASS permite que você especifique o nome de uma nova classe de janela cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). DECLARE_WND_CLASS define a nova classe de janela, Implementando a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

DECLARE_WND_CLASS Especifica os estilos para a nova janela a seguir:

- CS_HREDRAW

- CS_VREDRAW

- CS_DBLCLKS

DECLARE_WND_CLASS também especifica a cor do plano de fundo da janela padrão. Use o [DECLARE_WND_CLASS_EX](#declare_wnd_class_ex) macro para fornecer seus próprios estilos e cores de plano de fundo.

[CWindowImpl](cwindowimpl-class.md) usa a macro DECLARE_WND_CLASS para criar uma janela com base em uma nova classe de janela. Para substituir esse comportamento, use o [DECLARE_WND_SUPERCLASS](#declare_wnd_superclass) macro, ou fornecer sua própria implementação da [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) função.

Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).

##  <a name="declare_wnd_class2"></a>  DECLARE_WND_CLASS2

(Visual Studio 2017) Semelhante ao DECLARE_WND_CLASS, mas com um parâmetro extra que evita um erro de nome dependente ao compilar com o /permissive-option.

```
DECLARE_WND_CLASS2( WndClassName, EnclosingClass )
```

### <a name="parameters"></a>Parâmetros

*WndClassName*<br/>
[in] O nome da nova classe de janela. Se for NULL, o ATL irá gerar um nome de classe de janela.

*EnclosingClass*<br/>
[in] O nome da classe de janela que inclui a nova classe de janela. Não pode ser NULL.

### <a name="remarks"></a>Comentários

Se você estiver usando o /permissive-option, DECLARE_WND_CLASS causará um erro de compilação porque ela contém um nome dependente. DECLARE_WND_CLASS2 exige que você nomear explicitamente a classe que essa macro é usada em e não causa o erro sob o /permissive-flag.
Caso contrário, essa macro é idêntica à [DECLARE_WND_CLASS](#declare_wnd_class).

##  <a name="declare_wnd_superclass"></a>  DECLARE_WND_SUPERCLASS

Permite que você especifique os parâmetros de uma classe. Colocar essa macro na classe de controle de um controle ActiveX ATL.

```
DECLARE_WND_SUPERCLASS( WndClassName, OrigWndClassName )
```

### <a name="parameters"></a>Parâmetros

*WndClassName*<br/>
[in] O nome da janela de classe que será superclasse *OrigWndClassName*. Se for NULL, o ATL irá gerar um nome de classe de janela.

*OrigWndClassName*<br/>
[in] O nome de uma classe de janela existente.

### <a name="remarks"></a>Comentários

Essa macro permite que você especifique o nome de uma classe de janela que será a superclasse uma classe de janela existente. [CWndClassInfo](cwndclassinfo-class.md) gerencia as informações de superclasse.

DECLARE_WND_SUPERCLASS implementa a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

Por padrão, [CWindowImpl](cwindowimpl-class.md) usa o [DECLARE_WND_CLASS](#declare_wnd_class) macro para criar uma janela com base em uma nova classe de janela. Especificando a macro DECLARE_WND_SUPERCLASS em um `CWindowImpl`-derivado da classe, a classe de janela se basearão em uma classe existente, mas usará seu procedimento de janela. Essa técnica é chamada superclassing.

Além de usar as macros DECLARE_WND_CLASS e DECLARE_WND_SUPERCLASS, você pode substituir a [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) função com sua própria implementação.

Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).

##  <a name="declare_wnd_class_ex"></a>  DECLARE_WND_CLASS_EX

Permite que você especifique o nome de uma classe de janela existente no qual uma nova classe de janela será baseada. Colocar essa macro na classe de controle de um controle ActiveX ATL.

```
DECLARE_WND_CLASS_EX( WndClassName, style, bkgnd )
```

### <a name="parameters"></a>Parâmetros

*WndClassName*<br/>
[in] O nome da nova classe de janela. Se for NULL, o ATL irá gerar um nome de classe de janela.

*style*<br/>
[in] O estilo da janela.

*bkgnd*<br/>
[in] A cor do plano de fundo da janela.

### <a name="remarks"></a>Comentários

Essa macro permite que você especifique os parâmetros de classe de uma nova classe de janela, cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). DECLARE_WND_CLASS_EX define a nova classe de janela, Implementando a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

Se você quiser usar os estilos padrão e a cor do plano de fundo, use o [DECLARE_WND_CLASS](#declare_wnd_class) macro. Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).

## <a name="see-also"></a>Consulte também

[Macros](atl-macros.md)
