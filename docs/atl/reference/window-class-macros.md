---
title: Macros de classe de janela
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::DECLARE_WND_CLASS
- atlwin/ATL::DECLARE_WND_SUPERCLASS
- atlwin/ATL::DECLARE_WND_CLASS_EX
ms.assetid: ce18681a-2bab-4453-9895-0f3ea47c2b24
ms.openlocfilehash: c4617a04c199741b97316122456e417a94275e89
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417477"
---
# <a name="window-class-macros"></a>Macros de classe de janela

Essas macros definem utilitários de classe de janela.

|||
|-|-|
|[DECLARE_WND_CLASS](#declare_wnd_class)|Permite que você especifique o nome de uma nova classe de janela.|
|[DECLARE_WND_CLASS2](#declare_wnd_class2)|(Visual Studio 2017) Permite que você especifique o nome de uma nova classe de janela e a classe delimitadora cujo procedimento de janela a nova classe usará.|
|[DECLARE_WND_SUPERCLASS](#declare_wnd_superclass)|Permite que você especifique o nome de uma classe de janela existente na qual uma nova classe de janela será baseada.|
|[DECLARE_WND_CLASS_EX](#declare_wnd_class_ex)|Permite que você especifique os parâmetros de uma classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="declare_wnd_class"></a>DECLARE_WND_CLASS

Permite que você especifique o nome de uma nova classe de janela. Coloque essa macro em uma classe de controle do controle ActiveX do ATL.

```
DECLARE_WND_CLASS( WndClassName )
```

### <a name="parameters"></a>parâmetros

*WndClassName*<br/>
no O nome da nova classe de janela. Se for NULL, a ATL gerará um nome de classe de janela.

### <a name="remarks"></a>Comentários

Se você estiver usando a opção de compilador/permissive-, DECLARE_WND_CLASS causará um erro do compilador; em vez disso, use DECLARE_WND_CLASS2.

DECLARE_WND_CLASS permite que você especifique o nome de uma nova classe de janela cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). DECLARE_WND_CLASS define a nova classe de janela implementando a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

DECLARE_WND_CLASS especifica os seguintes estilos para a nova janela:

- CS_HREDRAW

- CS_VREDRAW

- CS_DBLCLKS

DECLARE_WND_CLASS também especifica a cor de fundo da janela padrão. Use a macro [DECLARE_WND_CLASS_EX](#declare_wnd_class_ex) para fornecer seus próprios estilos e cor do plano de fundo.

[CWindowImpl](cwindowimpl-class.md) usa a macro DECLARE_WND_CLASS para criar uma janela com base em uma nova classe de janela. Para substituir esse comportamento, use a macro [DECLARE_WND_SUPERCLASS](#declare_wnd_superclass) ou forneça sua própria implementação da função [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) .

Para obter mais informações sobre como usar o Windows na ATL, consulte o artigo [classes de janela do ATL](../../atl/atl-window-classes.md).

##  <a name="declare_wnd_class2"></a>DECLARE_WND_CLASS2

(Visual Studio 2017) Semelhante a DECLARE_WND_CLASS, mas com um parâmetro extra que evita um erro de nome dependente ao compilar com a opção/permissive-.

```
DECLARE_WND_CLASS2( WndClassName, EnclosingClass )
```

### <a name="parameters"></a>parâmetros

*WndClassName*<br/>
no O nome da nova classe de janela. Se for NULL, a ATL gerará um nome de classe de janela.

*EnclosingClass*<br/>
no O nome da classe de janela que inclui a nova classe de janela. Não pode ser NULL.

### <a name="remarks"></a>Comentários

Se você estiver usando a opção/permissive-, DECLARE_WND_CLASS causará um erro de compilação porque ele contém um nome dependente. DECLARE_WND_CLASS2 exige que você nomeie explicitamente a classe na qual essa macro é usada e não causa o erro no sinalizador/permissive-.
Caso contrário, essa macro será idêntica à [DECLARE_WND_CLASS](#declare_wnd_class).

##  <a name="declare_wnd_superclass"></a>DECLARE_WND_SUPERCLASS

Permite que você especifique os parâmetros de uma classe. Coloque essa macro em uma classe de controle do controle ActiveX do ATL.

```
DECLARE_WND_SUPERCLASS( WndClassName, OrigWndClassName )
```

### <a name="parameters"></a>parâmetros

*WndClassName*<br/>
no O nome da classe de janela que irá superclasse *OrigWndClassName*. Se for NULL, a ATL gerará um nome de classe de janela.

*OrigWndClassName*<br/>
no O nome de uma classe de janela existente.

### <a name="remarks"></a>Comentários

Essa macro permite que você especifique o nome de uma classe de janela que irá superclassear uma classe de janela existente. O [CWndClassInfo](cwndclassinfo-class.md) gerencia as informações da superclasse.

DECLARE_WND_SUPERCLASS implementa a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

Por padrão, o [CWindowImpl](cwindowimpl-class.md) usa a macro [DECLARE_WND_CLASS](#declare_wnd_class) para criar uma janela com base em uma nova classe de janela. Ao especificar a macro DECLARE_WND_SUPERCLASS em uma classe derivada de `CWindowImpl`, a classe Window será baseada em uma classe existente, mas usará o procedimento de janela. Essa técnica é chamada de superclasse.

Além de usar as macros DECLARE_WND_CLASS e DECLARE_WND_SUPERCLASS, você pode substituir a função [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) por sua própria implementação.

Para obter mais informações sobre como usar o Windows na ATL, consulte o artigo [classes de janela do ATL](../../atl/atl-window-classes.md).

##  <a name="declare_wnd_class_ex"></a>DECLARE_WND_CLASS_EX

Permite que você especifique o nome de uma classe de janela existente na qual uma nova classe de janela será baseada. Coloque essa macro em uma classe de controle do controle ActiveX do ATL.

```
DECLARE_WND_CLASS_EX( WndClassName, style, bkgnd )
```

### <a name="parameters"></a>parâmetros

*WndClassName*<br/>
no O nome da nova classe de janela. Se for NULL, a ATL gerará um nome de classe de janela.

*style*<br/>
no O estilo da janela.

*fundo*<br/>
no A cor do plano de fundo da janela.

### <a name="remarks"></a>Comentários

Essa macro permite que você especifique os parâmetros de classe de uma nova classe de janela, cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). DECLARE_WND_CLASS_EX Define a nova classe de janela implementando a seguinte função estática:

[!code-cpp[NVC_ATL_Windowing#127](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]

Se você quiser usar os estilos padrão e a cor do plano de fundo, use a macro [DECLARE_WND_CLASS](#declare_wnd_class) . Para obter mais informações sobre como usar o Windows na ATL, consulte o artigo [classes de janela do ATL](../../atl/atl-window-classes.md).

## <a name="see-also"></a>Confira também

[Macros](atl-macros.md)
