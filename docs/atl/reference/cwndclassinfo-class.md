---
title: Classe CWndClassInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CWndClassInfo class
ms.assetid: c36fe7e1-75f1-4cf5-a06f-9f59c43fe6fb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b07f6b12914e18f3f83abedf59742a8b7c7867b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cwndclassinfo-class"></a>Classe CWndClassInfo
Essa classe fornece métodos para registrar informações para uma classe de janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
|[m_atom](#m_atom)|Identifica exclusivamente a classe de janela registrado.|  
|[m_bSystemCursor](#m_bsystemcursor)|Especifica se o recurso de cursor se refere a um cursor do sistema ou a um cursor contidos em um recurso do módulo.|  
|[m_lpszCursorID](#m_lpszcursorid)|Especifica o nome do recurso do cursor.|  
|[m_lpszOrigName](#m_lpszorigname)|Contém o nome de uma classe de janela existente.|  
|[m_szAutoName](#m_szautoname)|Contém um nome gerado pelo ATL da classe de janela.|  
|[m_wc](#m_wc)|Mantém informações de classe de janela em um **WNDCLASSEX** estrutura.|  
|[pWndProc](#pwndproc)|Aponta para o procedimento de janela de uma classe de janela existente.|  
  
## <a name="remarks"></a>Comentários  
 `CWndClassInfo`gerencia as informações de uma classe de janela. Você normalmente usa `CWndClassInfo` através de um dos três macros, `DECLARE_WND_CLASS`, `DECLARE_WND_CLASS_EX`, ou `DECLARE_WND_SUPERCLASS`, conforme descrito na tabela a seguir:  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class)|`CWndClassInfo`registra informações para uma nova classe de janela.|  
|[DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex)|`CWndClassInfo`registra informações para uma nova classe de janela, incluindo os parâmetros de classe.|  
|[DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass)|`CWndClassInfo`registra informações para uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. Essa técnica é chamada superclassing.|  
  
 Por padrão, [CWindowImpl](../../atl/reference/cwindowimpl-class.md) inclui o `DECLARE_WND_CLASS` macro ao criar uma janela com base em uma nova classe de janela. DECLARE_WND_CLASS fornece estilos padrão e a cor do plano de fundo do controle. Se você quiser especificar o estilo e cor de fundo por conta própria, derive sua classe de `CWindowImpl` e incluir o `DECLARE_WND_CLASS_EX` macro em sua definição de classe.  
  
 Se você quiser criar uma janela com base em uma classe de janela existente, derive a classe de `CWindowImpl` e incluir o `DECLARE_WND_SUPERCLASS` macro em sua definição de classe. Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwndclassinfo-class_1.h)]  
  
 Para obter mais informações sobre classes de janela, consulte [Classes de janela](http://msdn.microsoft.com/library/windows/desktop/ms632596) no SDK do Windows.  
  
 Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="m_atom"></a>CWndClassInfo::m_atom  
 Contém o identificador exclusivo para a classe de janela registrado.  
  
```
ATOM m_atom;
```  
  
##  <a name="m_bsystemcursor"></a>CWndClassInfo::m_bSystemCursor  
 Se **TRUE**, o recurso de cursor do sistema será carregado quando a classe de janela é registrada.  
  
```
BOOL m_bSystemCursor;
```  
  
### <a name="remarks"></a>Comentários  
 Caso contrário, o recurso de cursor contido no módulo será carregado.  
  
 `CWndClassInfo`usa `m_bSystemCursor` somente quando o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro for especificada. Nesse caso, `m_bSystemCursor` é inicializado como **TRUE**. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.  
  
##  <a name="m_lpszcursorid"></a>CWndClassInfo::m_lpszCursorID  
 Especifica o nome do recurso de cursor ou o identificador de recurso na palavra de ordem inferior e zero na palavra de ordem superior.  
  
```
LPCTSTR m_lpszCursorID;
```  
  
### <a name="remarks"></a>Comentários  
 Quando a classe de janela é registrada, o identificador para o cursor identificado por `m_lpszCursorID` é recuperado e armazenados por [m_wc](#m_wc).  
  
 `CWndClassInfo`usa `m_lpszCursorID` somente quando o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro for especificada. Nesse caso, `m_lpszCursorID` é inicializado como **IDC_ARROW**. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.  
  
##  <a name="m_lpszorigname"></a>CWndClassInfo::m_lpszOrigName  
 Contém o nome de uma classe de janela existente.  
  
```
LPCTSTR m_lpszOrigName;
```  
  
### <a name="remarks"></a>Comentários  
 `CWndClassInfo`usa `m_lpszOrigName` somente quando você inclui o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro em sua definição de classe. Nesse caso, `CWndClassInfo` registra uma classe de janela com base na classe chamada pelo `m_lpszOrigName`. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.  
  
##  <a name="m_szautoname"></a>CWndClassInfo::m_szAutoName  
 Contém o nome da classe de janela.  
  
```
TCHAR m_szAutoName[13];
```  
  
### <a name="remarks"></a>Comentários  
 `CWndClassInfo`usa `m_szAutoName` somente se **nulo** é passado o `WndClassName` parâmetro [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class), o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) ou [ DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass). ATL criará um nome quando a classe de janela é registrada.  
  
##  <a name="m_wc"></a>CWndClassInfo::m_wc  
 Mantém as informações de classe de janela em um [WNDCLASSEX](http://msdn.microsoft.com/library/windows/desktop/ms633577) estrutura.  
  
```
WNDCLASSEX m_wc;
```  
  
### <a name="remarks"></a>Comentários  
 Se você tiver especificado o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro `m_wc` contém informações sobre um nova classe de janela.  
  
 Se você tiver especificado o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro `m_wc` contém informações sobre uma superclasse — uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. [m_lpszOrigName](#m_lpszorigname) e [pWndProc](#pwndproc) salvar o nome da classe de janela existente e o procedimento de janela, respectivamente.  
  
##  <a name="pwndproc"></a>CWndClassInfo::pWndProc  
 Aponta para o procedimento de janela de uma classe de janela existente.  
  
```
WNDPROC pWndProc;
```  
  
### <a name="remarks"></a>Comentários  
 `CWndClassInfo`usa `pWndProc` somente quando você inclui o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro em sua definição de classe. Nesse caso, `CWndClassInfo` registra uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. O procedimento de janela da classe de janela existente é salvo em `pWndProc`. Para obter mais informações, consulte o [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md) visão geral.  
  
##  <a name="register"></a>CWndClassInfo::Register  
 Chamado pelo [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create) para registrar a classe de janela se ele ainda não foi registrado.  
  
```
ATOM Register(WNDPROC* pProc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pProc`  
 [out] Especifica o procedimento de janela original de uma classe de janela existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um atom que identifica exclusivamente a classe de janela que está sendo registrada. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você tiver especificado o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) (o padrão em [CWindowImpl](../../atl/reference/cwindowimpl-class.md)) ou o [DECLARE_WND_CLASS_EX](window-class-macros.md#declare_wnd_class_ex) macro `Register` registra uma nova classe de janela. Nesse caso, o `pProc` parâmetro não for usado.  
  
 Se você tiver especificado o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro `Register` registra uma superclasse — uma classe de janela que é baseada em uma classe existente, mas usa um procedimento de janela diferente. O procedimento de janela da classe de janela existente é retornado no `pProc`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)