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
ms.openlocfilehash: 01706bf61c3b977c28998325ece68724cfbc7452
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330333"
---
# <a name="cwndclassinfo-class"></a>Classe CWndClassInfo

Esta classe fornece métodos para registrar informações para uma classe de janela.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CWndClassInfo
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|[Registro](#register)|Registra a aula de janelas.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_atom](#m_atom)|Identifica exclusivamente a classe de janela registrada.|
|[m_bSystemCursor](#m_bsystemcursor)|Especifica se o recurso do cursor refere-se a um cursor do sistema ou a um cursor contido em um recurso de módulo.|
|[m_lpszCursorID](#m_lpszcursorid)|Especifica o nome do recurso do cursor.|
|[M_lpszorigname](#m_lpszorigname)|Contém o nome de uma classe de janela existente.|
|[m_szAutoName](#m_szautoname)|Possui um nome gerado pela ATL da classe window.|
|[m_wc](#m_wc)|Mantém informações de `WNDCLASSEX` classe de janela em uma estrutura.|
|[Pwndproc](#pwndproc)|Aponta para o procedimento de janela de uma classe de janela existente.|

## <a name="remarks"></a>Comentários

`CWndClassInfo`gerencia as informações de uma classe de janelas. Você normalmente `CWndClassInfo` usa através de uma das três macros, DECLARE_WND_CLASS, DECLARE_WND_CLASS_EX ou DECLARE_WND_SUPERCLASS, conforme descrito na tabela a seguir:

|Macro|Descrição|
|-----------|-----------------|
|[Declare_wnd_class](window-class-macros.md#declare_wnd_class)|`CWndClassInfo`registra informações para uma nova classe de janela.|
|[Declare_wnd_class_ex](window-class-macros.md#declare_wnd_class_ex)|`CWndClassInfo`registra informações para uma nova classe de janela, incluindo os parâmetros de classe.|
|[Declare_wnd_superclass](window-class-macros.md#declare_wnd_superclass)|`CWndClassInfo`registra informações de uma classe de janela baseada em uma classe existente, mas usa um procedimento de janela diferente. Esta técnica é chamada de superclasse.|

Por padrão, [o CWindowImpl](../../atl/reference/cwindowimpl-class.md) inclui a `DECLARE_WND_CLASS` macro para criar uma janela com base em uma nova classe de janela. DECLARE_WND_CLASS fornece estilos padrão e cor de fundo para o controle. Se você quiser especificar o estilo e a `CWindowImpl` cor de fundo você mesmo, obtenha sua classe e inclua a macro DECLARE_WND_CLASS_EX na definição de classe.

Se você quiser criar uma janela com base em uma `CWindowImpl` classe de janela existente, obtenha sua classe e inclua a DECLARE_WND_SUPERCLASS macro na definição de classe. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwndclassinfo-class_1.h)]

Para obter mais informações sobre classes de janelas, consulte [Classes de janela](/windows/win32/winmsg/window-classes) no SDK do Windows.

Para obter mais informações sobre o uso de janelas no ATL, consulte o artigo [ATL Window Classes](../../atl/atl-window-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cwndclassinfom_atom"></a><a name="m_atom"></a>CWndClassInfo::m_atom

Contém o identificador exclusivo para a classe de janela registrada.

```
ATOM m_atom;
```

## <a name="cwndclassinfom_bsystemcursor"></a><a name="m_bsystemcursor"></a>CWndClassInfo::m_bSystemCursor

Se TRUE, o recurso do cursor do sistema será carregado quando a classe de janela estiver registrada.

```
BOOL m_bSystemCursor;
```

### <a name="remarks"></a>Comentários

Caso contrário, o recurso do cursor contido no módulo será carregado.

`CWndClassInfo`usa `m_bSystemCursor` somente quando o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl)](../../atl/reference/cwindowimpl-class.md)ou a [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro é especificada. Neste caso, `m_bSystemCursor` é inicializado para TRUE. Para obter mais informações, consulte a visão geral do [CWndClassInfo.](../../atl/reference/cwndclassinfo-class.md)

## <a name="cwndclassinfom_lpszcursorid"></a><a name="m_lpszcursorid"></a>CWndClassInfo::m_lpszCursorID

Especifica o nome do recurso do cursor ou o identificador de recursos na palavra de baixa ordem e zero na palavra de alta ordem.

```
LPCTSTR m_lpszCursorID;
```

### <a name="remarks"></a>Comentários

Quando a classe da janela é registrada, a `m_lpszCursorID` alça do cursor identificado por é recuperada e armazenada por [m_wc](#m_wc).

`CWndClassInfo`usa `m_lpszCursorID` somente quando o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl)](../../atl/reference/cwindowimpl-class.md)ou a [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro é especificada. Neste caso, `m_lpszCursorID` é inicializado para IDC_ARROW. Para obter mais informações, consulte a visão geral do [CWndClassInfo.](../../atl/reference/cwndclassinfo-class.md)

## <a name="cwndclassinfom_lpszorigname"></a><a name="m_lpszorigname"></a>CWndClassInfo::m_lpszOrigName

Contém o nome de uma classe de janela existente.

```
LPCTSTR m_lpszOrigName;
```

### <a name="remarks"></a>Comentários

`CWndClassInfo`usa `m_lpszOrigName` somente quando você inclui a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro na sua definição de classe. Neste caso, `CWndClassInfo` registra uma classe de janela `m_lpszOrigName`com base na classe nomeada por . Para obter mais informações, consulte a visão geral do [CWndClassInfo.](../../atl/reference/cwndclassinfo-class.md)

## <a name="cwndclassinfom_szautoname"></a><a name="m_szautoname"></a>CWndClassInfo::m_szAutoName

Tem o nome da turma da janela.

```
TCHAR m_szAutoName[13];
```

### <a name="remarks"></a>Comentários

`CWndClassInfo`usa `m_szAutoName` somente se NULO `WndClassName` for passado para que o parâmetro [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class), o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) ou [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass). A ATL construirá um nome quando a classe de janela estiver registrada.

## <a name="cwndclassinfom_wc"></a><a name="m_wc"></a>CWndClassInfo::m_wc

Mantém as informações da classe de janela em uma estrutura [WNDCLASSEX.](/windows/win32/api/winuser/ns-winuser-wndclassexw)

```
WNDCLASSEX m_wc;
```

### <a name="remarks"></a>Comentários

Se você tiver especificado o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão no [CWindowImpl)](../../atl/reference/cwindowimpl-class.md)ou a [macro DECLARE_WND_CLASS_EX,](window-class-macros.md#declare_wnd_class_ex) `m_wc` contém informações sobre uma nova classe de janela.

Se você especificou a `m_wc` [macro DECLARE_WND_SUPERCLASS,](window-class-macros.md#declare_wnd_superclass) contém informações sobre uma superclasse — uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. [m_lpszOrigName](#m_lpszorigname) e [pWndProc](#pwndproc) salvam o nome e o procedimento de janela da classe de janela existente, respectivamente.

## <a name="cwndclassinfopwndproc"></a><a name="pwndproc"></a>CWndClassInfo::pWndProc

Aponta para o procedimento de janela de uma classe de janela existente.

```
WNDPROC pWndProc;
```

### <a name="remarks"></a>Comentários

`CWndClassInfo`usa `pWndProc` somente quando você inclui a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro na sua definição de classe. Neste caso, `CWndClassInfo` registra uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. O procedimento de janela da classe `pWndProc`de janela existente é salvo em . Para obter mais informações, consulte a visão geral do [CWndClassInfo.](../../atl/reference/cwndclassinfo-class.md)

## <a name="cwndclassinforegister"></a><a name="register"></a>CWndClassInfo::Registro

Chamado por [CWindowImpl::Criar](../../atl/reference/cwindowimpl-class.md#create) para registrar a classe de janela se ela ainda não tiver sido registrada.

```
ATOM Register(WNDPROC* pProc);
```

### <a name="parameters"></a>Parâmetros

*pProc*<br/>
[fora] Especifica o procedimento de janela original de uma classe de janela existente.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, um átomo que identifica exclusivamente a classe de janela sendo registrada. Caso contrário, será 0.

### <a name="remarks"></a>Comentários

Se você tiver especificado o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão no [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou a [macro DECLARE_WND_CLASS_EX,](window-class-macros.md#declare_wnd_class_ex) `Register` registrará uma nova classe de janela. Neste caso, o parâmetro *pProc* não é utilizado.

Se você especificou a `Register` [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro, registra uma superclasse — uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. O procedimento de janela da classe de janela existente é devolvido em *pProc*.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
