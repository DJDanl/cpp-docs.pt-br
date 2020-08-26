---
title: Classe CWndClassInfo
ms.date: 11/04/2016
f1_keywords:
- CWndClassInfo
- ATLWIN/ATL::CWndClassInfo
- ATLWIN/ATL::Register
- ATLWIN/ATL::m_atom
- ATLWIN/ATL::m_bSystemCursor
- ATLWIN/ATL::m_lpszCursorID
- ATLWIN/ATL::m_lpszOrigName
- ATLWIN/ATL::m_szAutoName
- ATLWIN/ATL::m_wc
- ATLWIN/ATL::pWndProc
helpviewer_keywords:
- CWndClassInfo class
ms.assetid: c36fe7e1-75f1-4cf5-a06f-9f59c43fe6fb
ms.openlocfilehash: c1b516f6e92f98d660f7757870a3e634dcef4518
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835500"
---
# <a name="cwndclassinfo-class"></a>Classe CWndClassInfo

Essa classe fornece métodos para registrar informações para uma classe de janela.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CWndClassInfo
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[Registrar](#register)|Registra a classe da janela.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|-|-|
|[m_atom](#m_atom)|Identifica exclusivamente a classe de janela registrada.|
|[m_bSystemCursor](#m_bsystemcursor)|Especifica se o recurso de cursor se refere a um cursor do sistema ou a um cursor contido em um recurso de módulo.|
|[m_lpszCursorID](#m_lpszcursorid)|Especifica o nome do recurso de cursor.|
|[m_lpszOrigName](#m_lpszorigname)|Contém o nome de uma classe de janela existente.|
|[m_szAutoName](#m_szautoname)|Mantém um nome gerado pela ATL da classe Window.|
|[m_wc](#m_wc)|Mantém informações de classe de janela em uma `WNDCLASSEX` estrutura.|
|[pWndProc](#pwndproc)|Aponta para o procedimento de janela de uma classe de janela existente.|

## <a name="remarks"></a>Comentários

`CWndClassInfo` gerencia as informações de uma classe de janela. Normalmente, você usa `CWndClassInfo` uma das três macros, DECLARE_WND_CLASS, DECLARE_WND_CLASS_EX ou DECLARE_WND_SUPERCLASS, conforme descrito na tabela a seguir:

|Macro|Descrição|
|-----------|-----------------|
|[DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class)|`CWndClassInfo` registra informações para uma nova classe de janela.|
|[DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex)|`CWndClassInfo` registra informações para uma nova classe de janela, incluindo os parâmetros de classe.|
|[DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass)|`CWndClassInfo` registra informações para uma classe de janela baseada em uma classe existente, mas usa um procedimento de janela diferente. Essa técnica é chamada de superclasse.|

Por padrão, [CWindowImpl](../../atl/reference/cwindowimpl-class.md) inclui a `DECLARE_WND_CLASS` macro para criar uma janela com base em uma nova classe de janela. DECLARE_WND_CLASS fornece estilos padrão e cor do plano de fundo para o controle. Se você quiser especificar o estilo e a cor do plano de fundo, derive sua classe de `CWindowImpl` e inclua a macro DECLARE_WND_CLASS_EX em sua definição de classe.

Se você quiser criar uma janela com base em uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua a macro DECLARE_WND_SUPERCLASS em sua definição de classe. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwndclassinfo-class_1.h)]

Para obter mais informações sobre classes de janela, consulte [classes de janela](/windows/win32/winmsg/window-classes) no SDK do Windows.

Para obter mais informações sobre como usar o Windows na ATL, consulte o artigo [classes de janela do ATL](../../atl/atl-window-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

## <a name="cwndclassinfom_atom"></a><a name="m_atom"></a> CWndClassInfo:: m_atom

Contém o identificador exclusivo para a classe de janela registrada.

```
ATOM m_atom;
```

## <a name="cwndclassinfom_bsystemcursor"></a><a name="m_bsystemcursor"></a> CWndClassInfo:: m_bSystemCursor

Se for TRUE, o recurso de cursor do sistema será carregado quando a classe Window for registrada.

```
BOOL m_bSystemCursor;
```

### <a name="remarks"></a>Comentários

Caso contrário, o recurso de cursor contido em seu módulo será carregado.

`CWndClassInfo` usa `m_bSystemCursor` somente quando a [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou a macro [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) é especificada. Nesse caso, `m_bSystemCursor` é inicializado como true. Para obter mais informações, consulte a visão geral do [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) .

## <a name="cwndclassinfom_lpszcursorid"></a><a name="m_lpszcursorid"></a> CWndClassInfo:: m_lpszCursorID

Especifica o nome do recurso de cursor ou o identificador de recurso na palavra de ordem inferior e zero na palavra de ordem superior.

```
LPCTSTR m_lpszCursorID;
```

### <a name="remarks"></a>Comentários

Quando a classe Window é registrada, o identificador para o cursor identificado por `m_lpszCursorID` é recuperado e armazenado por [m_wc](#m_wc).

`CWndClassInfo` usa `m_lpszCursorID` somente quando a [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou a macro [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) é especificada. Nesse caso, `m_lpszCursorID` é inicializado para IDC_ARROW. Para obter mais informações, consulte a visão geral do [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) .

## <a name="cwndclassinfom_lpszorigname"></a><a name="m_lpszorigname"></a> CWndClassInfo:: m_lpszOrigName

Contém o nome de uma classe de janela existente.

```
LPCTSTR m_lpszOrigName;
```

### <a name="remarks"></a>Comentários

`CWndClassInfo` usa `m_lpszOrigName` somente quando você inclui a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) em sua definição de classe. Nesse caso, o `CWndClassInfo` registra uma classe de janela com base na classe nomeada por `m_lpszOrigName` . Para obter mais informações, consulte a visão geral do [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) .

## <a name="cwndclassinfom_szautoname"></a><a name="m_szautoname"></a> CWndClassInfo:: m_szAutoName

Mantém o nome da classe da janela.

```
TCHAR m_szAutoName[13];
```

### <a name="remarks"></a>Comentários

`CWndClassInfo` usa `m_szAutoName` somente se NULL for passado para o `WndClassName` parâmetro para [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class), o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) ou [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass). A ATL criará um nome quando a classe de janela for registrada.

## <a name="cwndclassinfom_wc"></a><a name="m_wc"></a> CWndClassInfo:: m_wc

Mantém as informações de classe de janela em uma estrutura [WNDCLASSEX](/windows/win32/api/winuser/ns-winuser-wndclassexw) .

```
WNDCLASSEX m_wc;
```

### <a name="remarks"></a>Comentários

Se você tiver especificado o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou a macro [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) , `m_wc` conterá informações sobre uma nova classe de janela.

Se você tiver especificado a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) , `m_wc` conterá informações sobre uma superclasse — uma classe de janela baseada em uma classe existente, mas que usa um procedimento de janela diferente. [m_lpszOrigName](#m_lpszorigname) e [pWndProc](#pwndproc) salvam o nome da classe de janela existente e o procedimento de janela, respectivamente.

## <a name="cwndclassinfopwndproc"></a><a name="pwndproc"></a> CWndClassInfo::p WndProc

Aponta para o procedimento de janela de uma classe de janela existente.

```
WNDPROC pWndProc;
```

### <a name="remarks"></a>Comentários

`CWndClassInfo` usa `pWndProc` somente quando você inclui a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) em sua definição de classe. Nesse caso, o `CWndClassInfo` registra uma classe de janela baseada em uma classe existente, mas usa um procedimento de janela diferente. O procedimento de janela da classe de janela existente é salvo em `pWndProc` . Para obter mais informações, consulte a visão geral do [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) .

## <a name="cwndclassinforegister"></a><a name="register"></a> CWndClassInfo:: Register

Chamado por [CWindowImpl:: Create](../../atl/reference/cwindowimpl-class.md#create) para registrar a classe de janela se ela ainda não tiver sido registrada.

```
ATOM Register(WNDPROC* pProc);
```

### <a name="parameters"></a>parâmetros

*pProc*<br/>
fora Especifica o procedimento de janela original de uma classe de janela existente.

### <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, um Atom que identifica exclusivamente a classe de janela que está sendo registrada. Caso contrário, será 0.

### <a name="remarks"></a>Comentários

Se você tiver especificado o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou a macro [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) , o `Register` registrará uma nova classe de janela. Nesse caso, o parâmetro *pProc* não é usado.

Se você tiver especificado a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) , o `Register` registrará uma superclasse — uma classe de janela baseada em uma classe existente, mas usará um procedimento de janela diferente. O procedimento de janela da classe de janela existente é retornado em *pProc*.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
