---
title: Classe CMenuTearOffManager
ms.date: 10/18/2018
f1_keywords:
- CMenuTearOffManager
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::CMenuTearOffManager
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::Build
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::GetRegPath
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::Initialize
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::IsDynamicID
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::Parse
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::Reset
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::SetInUse
- AFXMENUTEAROFFMANAGER/CMenuTearOffManager::SetupTearOffMenus
helpviewer_keywords:
- CMenuTearOffManager [MFC], CMenuTearOffManager
- CMenuTearOffManager [MFC], Build
- CMenuTearOffManager [MFC], GetRegPath
- CMenuTearOffManager [MFC], Initialize
- CMenuTearOffManager [MFC], IsDynamicID
- CMenuTearOffManager [MFC], Parse
- CMenuTearOffManager [MFC], Reset
- CMenuTearOffManager [MFC], SetInUse
- CMenuTearOffManager [MFC], SetupTearOffMenus
ms.assetid: ab7ca272-ce42-4678-95f7-6ad75038f5a0
ms.openlocfilehash: f41937179dc055213f3af093e107bcb08c8a8fcc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369968"
---
# <a name="cmenutearoffmanager-class"></a>Classe CMenuTearOffManager

Gerencia menus de tear-off. Um menu tear-off é um menu na barra de menu. O usuário pode remover um menu de tear-off da barra de menu, fazendo com que o menu tear-off flutue.

   Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMenuTearOffManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Cmenutearoffmanager::CmenuTearOffManager](#cmenutearoffmanager)|Constrói um objeto `CMenuTearOffManager`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CmenuTearOffManager::Build](#build)||
|[Cmenutearoffmanager::getRegpath](#getregpath)||
|[CMenuTearOffManager::Initialize](#initialize)|Inicializa um objeto `CMenuTearOffManager`.|
|[Cmenutearoffmanager::isdynamicid](#isdynamicid)||
|[CMenuTearOffManager::Parse](#parse)||
|[CMenuTearOffManager::Redefinir](#reset)||
|[Cmenutearoffmanager::setinuse](#setinuse)||
|[CMenuTearOffManager::ConfiguraçãoTearOffMenus](#setuptearoffmenus)||

## <a name="remarks"></a>Comentários

Para usar menus lacrimais em sua aplicação, `CMenuTearOffManager` você deve ter um objeto. Na maioria dos casos, você não `CMenuTearOffManager` criará ou inicializará um objeto diretamente. Isso é tratado para você quando você chama a função [CWinAppEx::EnableTearOffMenus.](../../mfc/reference/cwinappex-class.md#enabletearoffmenus)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMenuTearOffManager` construir e `CWinAppEX::EnableTearOffMenus` inicializar um objeto chamando o método. Este trecho de código faz parte da amostra do [Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#12](../../mfc/reference/codesnippet/cpp/cmenutearoffmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMenuTearOffManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenutearoffmanager.h

## <a name="cmenutearoffmanagerbuild"></a><a name="build"></a>CmenuTearOffManager::Build

```
void Build(
    UINT uiTearOffBarID,
    CString& strText);
```

### <a name="parameters"></a>Parâmetros

[em] *uiTearOffBarId*<br/>

[em] *strText*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmenutearoffmanagercmenutearoffmanager"></a><a name="cmenutearoffmanager"></a>Cmenutearoffmanager::CmenuTearOffManager

Constrói um objeto [CMenuTearOffManager.](../../mfc/reference/cmenutearoffmanager-class.md)

```
CMenuTearOffManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, `CMenuTearOffManager` você não deve criar uma manualmente. A estrutura do aplicativo `CMenuTearOffManager` cria o objeto quando você chama [CWinAppEx::EnableTearOffMenus](../../mfc/reference/cwinappex-class.md#enabletearoffmenus).

## <a name="cmenutearoffmanagergetregpath"></a><a name="getregpath"></a>Cmenutearoffmanager::getRegpath

```
LPCTSTR GetRegPath() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmenutearoffmanagerinitialize"></a><a name="initialize"></a>CMenuTearOffManager::Initialize

Inicializa um objeto [CMenuTearOffManager.](../../mfc/reference/cmenutearoffmanager-class.md)

```
BOOL Initialize(
    LPCTSTR lpszRegEntry,
    UINT uiTearOffMenuFirst,
    UINT uiTearOffMenuLast);
```

### <a name="parameters"></a>Parâmetros

*lpszRegentry*<br/>
[em] Uma seqüência que contém o caminho de uma entrada de registro. Seus aplicativos armazenam as configurações para barras de ruptura nesta entrada de registro.

*uiTearOffMenuFirst*<br/>
[em] O primeiro id do menu para um menu de tear-off.

*uiTearOffMenuLast*<br/>
[em] O último id do menu para um menu de tear-off.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A gama de IDs do menu de *uiTearOffMenuFirst* a *uiTearOffMenuLast* deve ser um intervalo contínuo. O intervalo define o número de menus de tear-off que podem aparecer ao mesmo tempo no aplicativo.

## <a name="cmenutearoffmanagerisdynamicid"></a><a name="isdynamicid"></a>Cmenutearoffmanager::isdynamicid

```
BOOL IsDynamicID(UINT uiID) const;
```

### <a name="parameters"></a>Parâmetros

[em] *uiID*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmenutearoffmanagerparse"></a><a name="parse"></a>CMenuTearOffManager::Parse

```
UINT Parse(CString& str);
```

### <a name="parameters"></a>Parâmetros

[em] *str*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmenutearoffmanagerreset"></a><a name="reset"></a>CMenuTearOffManager::Redefinir

```
void Reset(HMENU hmenu);
```

### <a name="parameters"></a>Parâmetros

[em] *hmenu*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmenutearoffmanagersetinuse"></a><a name="setinuse"></a>Cmenutearoffmanager::setinuse

```
void SetInUse(
    UINT uiCmdId,
    BOOL bUse = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *uiCmdId*<br/>

[em] *bUse*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmenutearoffmanagersetuptearoffmenus"></a><a name="setuptearoffmenus"></a>CMenuTearOffManager::ConfiguraçãoTearOffMenus

```
void SetupTearOffMenus(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

[em] *hMenu*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)
