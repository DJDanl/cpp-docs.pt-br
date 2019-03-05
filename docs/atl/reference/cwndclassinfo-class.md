---
title: Classe de CWndClassInfo
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
ms.openlocfilehash: 4aeac558c28d0ac89707423433e51f348bc35d29
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274109"
---
# <a name="cwndclassinfo-class"></a>Classe de CWndClassInfo

Essa classe fornece métodos para registrar informações de uma classe de janela.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CWndClassInfo
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|[Registro](#register)|Registra a classe de janela.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_atom](#m_atom)|Identifica exclusivamente a classe de janela registrada.|
|[m_bSystemCursor](#m_bsystemcursor)|Especifica se o recurso de cursor se refere a um cursor do sistema ou em um cursor contidos em um recurso de módulo.|
|[m_lpszCursorID](#m_lpszcursorid)|Especifica o nome do recurso de cursor.|
|[m_lpszOrigName](#m_lpszorigname)|Contém o nome de uma classe de janela existente.|
|[m_szAutoName](#m_szautoname)|Contém um nome gerado pelo ATL da classe de janela.|
|[m_wc](#m_wc)|Mantém informações de classe de janela em um `WNDCLASSEX` estrutura.|
|[pWndProc](#pwndproc)|Aponta para o procedimento de janela de uma classe de janela existente.|

## <a name="remarks"></a>Comentários

`CWndClassInfo` gerencia as informações de uma classe de janela. Você normalmente usa `CWndClassInfo` por meio de um dos três macros, DECLARE_WND_CLASS, DECLARE_WND_CLASS_EX ou DECLARE_WND_SUPERCLASS, conforme descrito na tabela a seguir:

|Macro|Descrição|
|-----------|-----------------|
|[DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class)|`CWndClassInfo` registra informações para uma nova classe de janela.|
|[DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex)|`CWndClassInfo` registra informações para uma nova classe de janela, incluindo os parâmetros da classe.|
|[DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass)|`CWndClassInfo` registra informações de uma classe de janela que se baseia em uma classe existente, mas usa um procedimento de janela diferentes. Essa técnica é chamada superclassing.|

Por padrão, [CWindowImpl](../../atl/reference/cwindowimpl-class.md) inclui o `DECLARE_WND_CLASS` macro para criar uma janela com base em uma nova classe de janela. DECLARE_WND_CLASS fornece estilos padrão e a cor de plano de fundo para o controle. Se você quiser especificar o estilo e cor do segundo plano por conta própria, derive sua classe de `CWindowImpl` e inclua a macro DECLARE_WND_CLASS_EX em sua definição de classe.

Se você quiser criar uma janela com base em uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua a macro DECLARE_WND_SUPERCLASS em sua definição de classe. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwndclassinfo-class_1.h)]

Para obter mais informações sobre classes de janela, consulte [Classes de janela](/windows/desktop/winmsg/window-classes) no SDK do Windows.

Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="m_atom"></a>  CWndClassInfo::m_atom

Contém o identificador exclusivo para a classe de janela registrada.

```
ATOM m_atom;
```

##  <a name="m_bsystemcursor"></a>  CWndClassInfo::m_bSystemCursor

Se for TRUE, o recurso de cursor do sistema será carregado quando a classe de janela é registrada.

```
BOOL m_bSystemCursor;
```

### <a name="remarks"></a>Comentários

Caso contrário, o recurso de cursor contido em seu módulo será carregado.

`CWndClassInfo` usa `m_bSystemCursor` somente quando o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão no [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro é especificada. Nesse caso, `m_bSystemCursor` é inicializado como TRUE. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.

##  <a name="m_lpszcursorid"></a>  CWndClassInfo::m_lpszCursorID

Especifica o nome do recurso de cursor ou o identificador de recurso na palavra de ordem inferior e zero a palavra de ordem superior.

```
LPCTSTR m_lpszCursorID;
```

### <a name="remarks"></a>Comentários

Quando a classe de janela é registrada, o identificador para o cursor identificado pelo `m_lpszCursorID` é recuperada e armazenada pelo [m_wc](#m_wc).

`CWndClassInfo` usa `m_lpszCursorID` somente quando o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão no [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro é especificada. Nesse caso, `m_lpszCursorID` é inicializado como IDC_ARROW. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.

##  <a name="m_lpszorigname"></a>  CWndClassInfo::m_lpszOrigName

Contém o nome de uma classe de janela existente.

```
LPCTSTR m_lpszOrigName;
```

### <a name="remarks"></a>Comentários

`CWndClassInfo` usa `m_lpszOrigName` apenas quando você inclui o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro em sua definição de classe. Nesse caso, `CWndClassInfo` registros de uma classe de janela com base na classe nomeada pelo `m_lpszOrigName`. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.

##  <a name="m_szautoname"></a>  CWndClassInfo::m_szAutoName

Contém o nome da classe de janela.

```
TCHAR m_szAutoName[13];
```

### <a name="remarks"></a>Comentários

`CWndClassInfo` usa `m_szAutoName` somente se NULL for passado o `WndClassName` parâmetro [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class), o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) ou [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) . ATL será construir um nome quando a classe de janela é registrada.

##  <a name="m_wc"></a>  CWndClassInfo::m_wc

Mantém as informações de classe de janela em um [WNDCLASSEX](/windows/desktop/api/winuser/ns-winuser-tagwndclassexa) estrutura.

```
WNDCLASSEX m_wc;
```

### <a name="remarks"></a>Comentários

Se você tiver especificado a [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão no [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro, `m_wc` contém informações sobre um nova classe de janela.

Se você tiver especificado a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro, `m_wc` contém informações sobre uma superclasse — uma classe de janela que se baseia em uma classe existente, mas usa um procedimento de janela diferentes. [m_lpszOrigName](#m_lpszorigname) e [pWndProc](#pwndproc) salvar o nome da classe de janela existente e o procedimento de janela, respectivamente.

##  <a name="pwndproc"></a>  CWndClassInfo::pWndProc

Aponta para o procedimento de janela de uma classe de janela existente.

```
WNDPROC pWndProc;
```

### <a name="remarks"></a>Comentários

`CWndClassInfo` usa `pWndProc` apenas quando você inclui o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro em sua definição de classe. Nesse caso, `CWndClassInfo` registra uma classe de janela que se baseia em uma classe existente, mas usa um procedimento de janela diferentes. O procedimento de janela da classe de janela existente é salvo em `pWndProc`. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.

##  <a name="register"></a>  CWndClassInfo::Register

Chamado pelo [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create) para registrar a classe de janela, se ele ainda não tiver sido registrado.

```
ATOM Register(WNDPROC* pProc);
```

### <a name="parameters"></a>Parâmetros

*pProc*<br/>
[out] Especifica o procedimento de janela original de uma classe de janela existente.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um átomo que identifica exclusivamente a classe de janela que está sendo registrada. Otherwise, 0.

### <a name="remarks"></a>Comentários

Se você tiver especificado a [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão no [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro, `Register` registra uma nova classe de janela. Nesse caso, o *pProc* parâmetro não for usado.

Se você tiver especificado a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro, `Register` registra uma superclasse — uma classe de janela que se baseia em uma classe existente, mas usa um procedimento de janela diferentes. O procedimento de janela da classe de janela existente é retornado no *pProc*.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
