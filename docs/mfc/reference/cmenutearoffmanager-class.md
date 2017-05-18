---
title: Classe CMenuTearOffManager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CMenuTearOffManager class
ms.assetid: ab7ca272-ce42-4678-95f7-6ad75038f5a0
caps.latest.revision: 31
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 53677bbea54e428e5f080f5c1f73c576abcf99a5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmenutearoffmanager-class"></a>Classe CMenuTearOffManager
Gerencia menus destacável. Um menu destacável é um menu na barra de menus. O usuário pode remover um menu destacável da barra de menus, fazendo com que o menu destacável flutuando.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMenuTearOffManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenuTearOffManager::CMenuTearOffManager](#cmenutearoffmanager)|Constrói um objeto `CMenuTearOffManager`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenuTearOffManager::Build](#build)||  
|[CMenuTearOffManager::GetRegPath](#getregpath)||  
|[CMenuTearOffManager::Initialize](#initialize)|Inicializa uma `CMenuTearOffManager` objeto.|  
|[CMenuTearOffManager::IsDynamicID](#isdynamicid)||  
|[CMenuTearOffManager::Parse](#parse)||  
|[CMenuTearOffManager::Reset](#reset)||  
|[CMenuTearOffManager::SetInUse](#setinuse)||  
|[CMenuTearOffManager::SetupTearOffMenus](#setuptearoffmenus)||  
  
## <a name="remarks"></a>Comentários  
 Para usar os menus destacável em seu aplicativo, você deve ter uma `CMenuTearOffManager` objeto. Na maioria dos casos, você não cria ou inicializar um `CMenuTearOffManager` diretamente do objeto. Isso é manipulado para você quando você chama o [CWinAppEx::EnableTearOffMenus](../../mfc/reference/cwinappex-class.md#enabletearoffmenus) função.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar e inicializar um `CMenuTearOffManager` objeto chamando o `CWinAppEX::EnableTearOffMenus` método. Este trecho de código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad&#12;](../../mfc/reference/codesnippet/cpp/cmenutearoffmanager-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMenuTearOffManager`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmenutearoffmanager.h  
  
##  <a name="build"></a>CMenuTearOffManager::Build  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void Build(
    UINT uiTearOffBarID,  
    CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiTearOffBarID`  
 [in] `strText`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cmenutearoffmanager"></a>CMenuTearOffManager::CMenuTearOffManager  
 Constrói uma [CMenuTearOffManager](../../mfc/reference/cmenutearoffmanager-class.md) objeto.  
  
```  
CMenuTearOffManager();
```  
  
### <a name="remarks"></a>Comentários  
 Na maioria dos casos, você não deve criar um `CMenuTearOffManager` manualmente. A estrutura do seu aplicativo cria o `CMenuTearOffManager` objeto quando você chamar [CWinAppEx::EnableTearOffMenus](../../mfc/reference/cwinappex-class.md#enabletearoffmenus).  
  
##  <a name="getregpath"></a>CMenuTearOffManager::GetRegPath  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
LPCTSTR GetRegPath() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="initialize"></a>CMenuTearOffManager::Initialize  
 Inicializa uma [CMenuTearOffManager](../../mfc/reference/cmenutearoffmanager-class.md) objeto.  
  
```  
BOOL Initialize(
    LPCTSTR lpszRegEntry,  
    UINT uiTearOffMenuFirst,  
    UINT uiTearOffMenuLast);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszRegEntry`  
 Uma cadeia de caracteres que contém o caminho de uma entrada de registro. Os aplicativos armazena as configurações de barras destacável na entrada do registro.  
  
 [in] `uiTearOffMenuFirst`  
 A primeira ID de menu em um menu destacável.  
  
 [in] `uiTearOffMenuLast`  
 A última ID de menu em um menu destacável.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O intervalo de IDs de menu do `uiTearOffMenuFirst` para `uiTearOffMenuLast` deve ser um intervalo contínuo. O intervalo define o número de menus destacável que podem aparecer ao mesmo tempo no aplicativo.  
  
##  <a name="isdynamicid"></a>CMenuTearOffManager::IsDynamicID  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsDynamicID(UINT uiID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="parse"></a>CMenuTearOffManager::Parse  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
UINT Parse(CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `str`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="reset"></a>CMenuTearOffManager::Reset  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void Reset(HMENU hmenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hmenu`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setinuse"></a>CMenuTearOffManager::SetInUse  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetInUse(
    UINT uiCmdId,  
    BOOL bUse = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdId`  
 [in] `bUse`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setuptearoffmenus"></a>CMenuTearOffManager::SetupTearOffMenus  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetupTearOffMenus(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hMenu`  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)

