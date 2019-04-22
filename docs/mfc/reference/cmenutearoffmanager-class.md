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
ms.openlocfilehash: 8b92ddad9d3a6de41cf6914dee268f6e54b5d420
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58776057"
---
# <a name="cmenutearoffmanager-class"></a>Classe CMenuTearOffManager

Gerencia menus destacáveis. Um menu destacável é um menu na barra de menus. O usuário pode remover um menu destacável da barra de menus, fazendo com que o menu destacável fique flutuando.

   Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMenuTearOffManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMenuTearOffManager::CMenuTearOffManager](#cmenutearoffmanager)|Constrói um objeto `CMenuTearOffManager`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMenuTearOffManager::Build](#build)||
|[CMenuTearOffManager::GetRegPath](#getregpath)||
|[CMenuTearOffManager::Initialize](#initialize)|Inicializa um `CMenuTearOffManager` objeto.|
|[CMenuTearOffManager::IsDynamicID](#isdynamicid)||
|[CMenuTearOffManager::Parse](#parse)||
|[CMenuTearOffManager::Reset](#reset)||
|[CMenuTearOffManager::SetInUse](#setinuse)||
|[CMenuTearOffManager::SetupTearOffMenus](#setuptearoffmenus)||

## <a name="remarks"></a>Comentários

Para usar os menus destacáveis em seu aplicativo, você deve ter um `CMenuTearOffManager` objeto. Na maioria dos casos, você não criar ou inicializar um `CMenuTearOffManager` diretamente do objeto. Isso é feito para você quando você chama o [CWinAppEx::EnableTearOffMenus](../../mfc/reference/cwinappex-class.md#enabletearoffmenus) função.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar e inicializar uma `CMenuTearOffManager` objeto chamando o `CWinAppEX::EnableTearOffMenus` método. Este trecho de código é parte do [exemplo de Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#12](../../mfc/reference/codesnippet/cpp/cmenutearoffmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMenuTearOffManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenutearoffmanager.h

##  <a name="build"></a>  CMenuTearOffManager::Build

```
void Build(
    UINT uiTearOffBarID,
    CString& strText);
```

### <a name="parameters"></a>Parâmetros

[in] *uiTearOffBarID*<br/>

[in] *strText*<br/>

### <a name="remarks"></a>Comentários

##  <a name="cmenutearoffmanager"></a>  CMenuTearOffManager::CMenuTearOffManager

Constrói uma [CMenuTearOffManager](../../mfc/reference/cmenutearoffmanager-class.md) objeto.

```
CMenuTearOffManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você não deve criar um `CMenuTearOffManager` manualmente. A estrutura do seu aplicativo cria o `CMenuTearOffManager` do objeto quando você chama [CWinAppEx::EnableTearOffMenus](../../mfc/reference/cwinappex-class.md#enabletearoffmenus).

##  <a name="getregpath"></a>  CMenuTearOffManager::GetRegPath

```
LPCTSTR GetRegPath() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="initialize"></a>  CMenuTearOffManager::Initialize

Inicializa uma [CMenuTearOffManager](../../mfc/reference/cmenutearoffmanager-class.md) objeto.

```
BOOL Initialize(
    LPCTSTR lpszRegEntry,
    UINT uiTearOffMenuFirst,
    UINT uiTearOffMenuLast);
```

### <a name="parameters"></a>Parâmetros

*lpszRegEntry*<br/>
[in] Uma cadeia de caracteres que contém o caminho de uma entrada de registro. Seus aplicativos armazena as configurações de barras destacáveis nesta entrada de registro.

*uiTearOffMenuFirst*<br/>
[in] A primeira ID de menu para um menu destacável.

*uiTearOffMenuLast*<br/>
[in] A última ID de menu para um menu destacável.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O intervalo de IDs de menu de *uiTearOffMenuFirst* à *uiTearOffMenuLast* deve ser um intervalo contínuo. O intervalo define o número de menus destacáveis que podem aparecer ao mesmo tempo no aplicativo.

##  <a name="isdynamicid"></a>  CMenuTearOffManager::IsDynamicID

```
BOOL IsDynamicID(UINT uiID) const;
```

### <a name="parameters"></a>Parâmetros

[in] *uiID*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="parse"></a>  CMenuTearOffManager::Parse

```
UINT Parse(CString& str);
```

### <a name="parameters"></a>Parâmetros

[in] *str*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="reset"></a>  CMenuTearOffManager::Reset

```
void Reset(HMENU hmenu);
```

### <a name="parameters"></a>Parâmetros

[in] *hmenu*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setinuse"></a>  CMenuTearOffManager::SetInUse

```
void SetInUse(
    UINT uiCmdId,
    BOOL bUse = TRUE);
```

### <a name="parameters"></a>Parâmetros

[in] *uiCmdId*<br/>

[in] *bUse*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setuptearoffmenus"></a>  CMenuTearOffManager::SetupTearOffMenus

```
void SetupTearOffMenus(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

[in] *hMenu*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)
