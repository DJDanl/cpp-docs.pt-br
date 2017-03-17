---
title: Classe IPropertyPageImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IPropertyPageImpl
- ATLCTL/ATL::IPropertyPageImpl
- ATLCTL/ATL::IPropertyPageImpl::IPropertyPageImpl
- ATLCTL/ATL::IPropertyPageImpl::Activate
- ATLCTL/ATL::IPropertyPageImpl::Apply
- ATLCTL/ATL::IPropertyPageImpl::Deactivate
- ATLCTL/ATL::IPropertyPageImpl::GetPageInfo
- ATLCTL/ATL::IPropertyPageImpl::Help
- ATLCTL/ATL::IPropertyPageImpl::IsPageDirty
- ATLCTL/ATL::IPropertyPageImpl::Move
- ATLCTL/ATL::IPropertyPageImpl::SetDirty
- ATLCTL/ATL::IPropertyPageImpl::SetObjects
- ATLCTL/ATL::IPropertyPageImpl::SetPageSite
- ATLCTL/ATL::IPropertyPageImpl::Show
- ATLCTL/ATL::IPropertyPageImpl::TranslateAccelerator
- ATLCTL/ATL::IPropertyPageImpl::m_bDirty
- ATLCTL/ATL::IPropertyPageImpl::m_dwDocString
- ATLCTL/ATL::IPropertyPageImpl::m_dwHelpContext
- ATLCTL/ATL::IPropertyPageImpl::m_dwHelpFile
- ATLCTL/ATL::IPropertyPageImpl::m_dwTitle
- ATLCTL/ATL::IPropertyPageImpl::m_nObjects
- ATLCTL/ATL::IPropertyPageImpl::m_pPageSite
- ATLCTL/ATL::IPropertyPageImpl::m_ppUnk
- ATLCTL/ATL::IPropertyPageImpl::m_size
dev_langs:
- C++
helpviewer_keywords:
- property pages
- IPropertyPage ATL implementation
- IPropertyPageImpl class
ms.assetid: f9b7c8b1-7a04-4eab-aa63-63efddb740fa
caps.latest.revision: 21
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 1179e13eb33f09a363c7a3f4425a9ebf13c73b91
ms.lasthandoff: 02/25/2017

---
# <a name="ipropertypageimpl-class"></a>Classe IPropertyPageImpl
Essa classe implementa **IUnknown** e fornece uma implementação padrão da [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class IPropertyPageImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IPropertyPageImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPropertyPageImpl::IPropertyPageImpl](#ipropertypageimpl)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPropertyPageImpl::Activate](#activate)|Cria a janela da caixa de diálogo da página de propriedades.|  
|[IPropertyPageImpl::Apply](#apply)|Aplica-se a valores atuais de página de propriedade para os objetos subjacentes especificados por meio de `SetObjects`. Retorna a implementação de ATL `S_OK`.|  
|[IPropertyPageImpl::Deactivate](#deactivate)|Destrói a janela criada com **ativar**.|  
|[IPropertyPageImpl::GetPageInfo](#getpageinfo)|Recupera informações sobre a página de propriedades.|  
|[IPropertyPageImpl::Help](#help)|Chama a Ajuda do Windows para a página de propriedades.|  
|[IPropertyPageImpl::IsPageDirty](#ispagedirty)|Indica se a página de propriedades foi alterado desde que ele foi ativado.|  
|[IPropertyPageImpl::Move](#move)|Posiciona e redimensiona a caixa de diálogo da página de propriedade.|  
|[IPropertyPageImpl::SetDirty](#setdirty)|Sinalizadores de estado da página de propriedade alterada ou inalterado.|  
|[IPropertyPageImpl::SetObjects](#setobjects)|Fornece uma matriz de **IUnknown** ponteiros para os objetos associados a página de propriedades. Esses objetos recebem os valores atuais de página de propriedade por meio de uma chamada para **aplicar**.|  
|[IPropertyPageImpl::SetPageSite](#setpagesite)|Fornece a página de propriedade com um `IPropertyPageSite` ponteiro, por meio do qual a página de propriedades se comunica com o quadro de propriedade.|  
|[IPropertyPageImpl::Show](#show)|Torna a caixa de diálogo da página de propriedade visível ou invisível.|  
|[IPropertyPageImpl::TranslateAccelerator](#translateaccelerator)|Processa um pressionamento de tecla especificado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPropertyPageImpl::m_bDirty](#m_bdirty)|Especifica se o estado da página de propriedade foi alterada.|  
|[IPropertyPageImpl::m_dwDocString](#m_dwdocstring)|Armazena o identificador do recurso associado com a cadeia de caracteres de texto que descreve a página de propriedades.|  
|[IPropertyPageImpl::m_dwHelpContext](#m_dwhelpcontext)|Armazena o identificador de contexto para o tópico de ajuda associado à página de propriedade.|  
|[IPropertyPageImpl::m_dwHelpFile](#m_dwhelpfile)|Armazena o identificador do recurso associado com o nome do arquivo de Ajuda que descreve a página de propriedades.|  
|[IPropertyPageImpl::m_dwTitle](#m_dwtitle)|Armazena o identificador do recurso associado com a cadeia de caracteres de texto que aparece na guia da página de propriedades.|  
|[IPropertyPageImpl::m_nObjects](#m_nobjects)|Armazena o número de objetos associados com a página de propriedades.|  
|[IPropertyPageImpl::m_pPageSite](#m_ppagesite)|Aponta para a `IPropertyPageSite` interface através da qual a página de propriedades se comunica com o quadro de propriedade.|  
|[IPropertyPageImpl::m_ppUnk](#m_ppunk)|Aponta para uma matriz de **IUnknown** ponteiros para os objetos associados a página de propriedades.|  
|[IPropertyPageImpl::m_size](#m_size)|Armazena a altura e largura da caixa de diálogo da página de propriedade, em pixels.|  
  
## <a name="remarks"></a>Comentários  
 O [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) interface permite que um objeto gerenciar uma página de propriedade específica em uma folha de propriedades. Classe `IPropertyPageImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPropertyPage`  
  
 `IPropertyPageImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="activate"></a>IPropertyPageImpl::Activate  
 Cria a janela da caixa de diálogo da página de propriedades.  
  
```
HRESULT Activate(  
    HWND hWndParent,
    LPCRECT pRect,
    BOOL bModal);
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a caixa de diálogo sempre é sem janela restrita, independentemente do valor de *bModal* parâmetro.  
  
 Consulte [IPropertyPage::Activate](http://msdn.microsoft.com/library/windows/desktop/ms682250) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="apply"></a>IPropertyPageImpl::Apply  
 Aplica-se a valores atuais de página de propriedade para os objetos subjacentes especificados por meio de `SetObjects`.  
  
```
HRESULT Apply();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::Apply](http://msdn.microsoft.com/library/windows/desktop/ms691284) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="deactivate"></a>IPropertyPageImpl::Deactivate  
 Destrói a janela da caixa de diálogo criada com [ativar](#activate).  
  
```
HRESULT Deactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::Deactivate](http://msdn.microsoft.com/library/windows/desktop/ms682504) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getpageinfo"></a>IPropertyPageImpl::GetPageInfo  
 Preenche o *pPageInfo* estrutura com informações contidas nos membros de dados.  
  
```
HRESULT GetPageInfo(PROPPAGEINFO* pPageInfo);
```  
  
### <a name="remarks"></a>Comentários  
 `GetPageInfo`carrega os recursos de cadeia de caracteres associados [m_dwDocString](#m_dwdocstring), [m_dwHelpFile](#m_dwhelpfile), e [m_dwTitle](#m_dwtitle).  
  
 Consulte [IPropertyPage::GetPageInfo](http://msdn.microsoft.com/library/windows/desktop/ms680714) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="help"></a>IPropertyPageImpl::Help  
 Chama a Ajuda do Windows para a página de propriedades.  
  
```
HRESULT Help(PROPPAGEINFO* pPageInfo);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::Help](http://msdn.microsoft.com/library/windows/desktop/ms691504) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ipropertypageimpl"></a>IPropertyPageImpl::IPropertyPageImpl  
 O construtor.  
  
```
IPropertyPageImpl();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa todos os membros de dados.  
  
##  <a name="ispagedirty"></a>IPropertyPageImpl::IsPageDirty  
 Indica se a página de propriedades foi alterado desde que ele foi ativado.  
  
```
HRESULT IsPageDirty(void);
```  
  
### <a name="remarks"></a>Comentários  
 `IsPageDirty`Retorna `S_OK` se a página tiver sido alterado desde que ele foi ativado.  
  
##  <a name="m_bdirty"></a>IPropertyPageImpl::m_bDirty  
 Especifica se o estado da página de propriedade foi alterada.  
  
```
BOOL m_bDirty;
```  
  
##  <a name="m_nobjects"></a>IPropertyPageImpl::m_nObjects  
 Armazena o número de objetos associados com a página de propriedades.  
  
```
ULONG m_nObjects;
```  
  
##  <a name="m_dwhelpcontext"></a>IPropertyPageImpl::m_dwHelpContext  
 Armazena o identificador de contexto para o tópico de ajuda associado à página de propriedade.  
  
```
DWORD m_dwHelpContext;
```  
  
##  <a name="m_dwdocstring"></a>IPropertyPageImpl::m_dwDocString  
 Armazena o identificador do recurso associado com a cadeia de caracteres de texto que descreve a página de propriedades.  
  
```
UINT m_dwDocString;
```  
  
##  <a name="m_dwhelpfile"></a>IPropertyPageImpl::m_dwHelpFile  
 Armazena o identificador do recurso associado com o nome do arquivo de Ajuda que descreve a página de propriedades.  
  
```
UINT m_dwHelpFile;
```  
  
##  <a name="m_dwtitle"></a>IPropertyPageImpl::m_dwTitle  
 Armazena o identificador do recurso associado com a cadeia de caracteres de texto que aparece na guia da página de propriedades.  
  
```
UINT m_dwTitle;
```  
  
##  <a name="m_ppagesite"></a>IPropertyPageImpl::m_pPageSite  
 Aponta para a [IPropertyPageSite](http://msdn.microsoft.com/library/windows/desktop/ms690583) interface através da qual a página de propriedades se comunica com o quadro de propriedade.  
  
```
IPropertyPageSite* m_pPageSite;
```  
  
##  <a name="m_ppunk"></a>IPropertyPageImpl::m_ppUnk  
 Aponta para uma matriz de **IUnknown** ponteiros para os objetos associados a página de propriedades.  
  
```
IUnknown** m_ppUnk;
```  
  
##  <a name="m_size"></a>IPropertyPageImpl::m_size  
 Armazena a altura e largura da caixa de diálogo da página de propriedade, em pixels.  
  
```
SIZE m_size;
```  
  
##  <a name="move"></a>IPropertyPageImpl::Move  
 Posiciona e redimensiona a caixa de diálogo da página de propriedade.  
  
```
HRESULT Move(LPCRECT pRect);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::Move](http://msdn.microsoft.com/library/windows/desktop/ms680118) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setdirty"></a>IPropertyPageImpl::SetDirty  
 Sinalizadores de estado da página de propriedade alterada ou inalterado, dependendo do valor de `bDirty`.  
  
```
void SetDirty(BOOL bDirty);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDirty`  
 [in] Se **TRUE**, estado da página de propriedade é marcado como alterada. Caso contrário, ele é marcado como inalterado.  
  
### <a name="remarks"></a>Comentários  
 Se necessário, `SetDirty` informa o quadro que a página de propriedade foi alterada.  
  
##  <a name="setobjects"></a>IPropertyPageImpl::SetObjects  
 Fornece uma matriz de **IUnknown** ponteiros para os objetos associados a página de propriedades.  
  
```
HRESULT SetObjects(ULONG nObjects, IUnknown** ppUnk);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::SetObjects](http://msdn.microsoft.com/library/windows/desktop/ms678529) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setpagesite"></a>IPropertyPageImpl::SetPageSite  
 Fornece a página de propriedade com um [IPropertyPageSite](http://msdn.microsoft.com/library/windows/desktop/ms690583) ponteiro, por meio do qual a página de propriedades se comunica com o quadro de propriedade.  
  
```
HRESULT SetPageSite(IPropertyPageSite* pPageSite);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::SetPageSite](http://msdn.microsoft.com/library/windows/desktop/ms690413) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="show"></a>IPropertyPageImpl::Show  
 Torna a caixa de diálogo da página de propriedade visível ou invisível.  
  
```
HRESULT Show(UINT nCmdShow);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::Show](http://msdn.microsoft.com/library/windows/desktop/ms694467) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="translateaccelerator"></a>IPropertyPageImpl::TranslateAccelerator  
 Processa o pressionamento de tecla especificado em `pMsg`.  
  
```
HRESULT TranslateAccelerator(MSG* pMsg);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms686603) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)   
 [Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)   
 [Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

