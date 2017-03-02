---
title: Classe IDataObjectImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IDataObjectImpl
dev_langs:
- C++
helpviewer_keywords:
- data transfer [C++]
- data transfer [C++], Uniform Data Transfer
- IDataObjectImpl class
- IDataObject, ATL implementation
ms.assetid: b680f0f7-7795-40a1-a0f6-f48768201c89
caps.latest.revision: 20
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: afd5fe7cf9bbac582e59ed46dc33e99de5fc2876
ms.lasthandoff: 02/25/2017

---
# <a name="idataobjectimpl-class"></a>Classe IDataObjectImpl
Essa classe fornece métodos para transferência uniforme de dados de suporte e gerenciamento de conexões.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class IDataObjectImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IDataObjectImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDataObjectImpl::DAdvise](#dadvise)|Estabelece uma conexão entre o objeto de dados e um coletor advise. Isso permite que o coletor de advise receber notificações de alterações no objeto.|  
|[IDataObjectImpl::DUnadvise](#dunadvise)|Encerra uma conexão estabelecida anteriormente por meio de `DAdvise`.|  
|[IDataObjectImpl::EnumDAdvise](#enumdadvise)|Cria um enumerador para iterar por meio de consultoria conexões atuais.|  
|[IDataObjectImpl::EnumFormatEtc](#enumformatetc)|Cria um enumerador para iterar a **FORMATETC** estruturas com suporte pelo objeto de dados. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::FireDataChange](#firedatachange)|Envia uma notificação de alteração de volta ao coletor cada aviso.|  
|[IDataObjectImpl::GetCanonicalFormatEtc](#getcanonicalformatetc)|Recupera um logicamente equivalente **FORMATETC** estrutura para um que seja mais complexas. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::GetData](#getdata)|Transfere dados do objeto de dados para o cliente. Os dados são descritos em uma **FORMATETC** estrutura e são transferidos por meio de um **STGMEDIUM** estrutura.|  
|[IDataObjectImpl::GetDataHere](#getdatahere)|Semelhante ao `GetData`, exceto que o cliente deve alocar o **STGMEDIUM** estrutura. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::QueryGetData](#querygetdata)|Determina se o objeto de dados oferece suporte a um determinado **FORMATETC** estrutura para transferir dados. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::SetData](#setdata)|Transfere dados do cliente para o objeto de dados. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 O [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) interface fornece métodos para dar suporte à transferência uniforme de dados. `IDataObject`usa as estruturas de formato padrão [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) e [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) para recuperar e armazenar dados.  
  
 `IDataObject`também gerencia conexões para informar coletores para manipular as notificações de alteração de dados. Para o cliente receber notificações de alteração de dados do objeto de dados, o cliente deve implementar o [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) interface em um objeto chamado um coletor advise. Quando o cliente então chama **IDataObject::DAdvise**, uma conexão é estabelecida entre o objeto de dados e o coletor de advise.  
  
 Classe `IDataObjectImpl` fornece uma implementação padrão de `IDataObject` e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IDataObject`  
  
 `IDataObjectImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="a-namedadvisea--idataobjectimpldadvise"></a><a name="dadvise"></a>IDataObjectImpl::DAdvise  
 Estabelece uma conexão entre o objeto de dados e um coletor advise.  
  
```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Isso permite que o coletor de advise receber notificações de alterações no objeto.  
  
 Para encerrar a conexão, chamar [DUnadvise](#dunadvise).  
  
 Consulte [IDataObject::DAdvise](http://msdn.microsoft.com/library/windows/desktop/ms692579) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namedunadvisea--idataobjectimpldunadvise"></a><a name="dunadvise"></a>IDataObjectImpl::DUnadvise  
 Encerra uma conexão estabelecida anteriormente por meio de [DAdvise](#dadvise).  
  
```
HRESULT DUnadvise(DWORD dwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::DUnadvise](http://msdn.microsoft.com/library/windows/desktop/ms692448) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameenumdadvisea--idataobjectimplenumdadvise"></a><a name="enumdadvise"></a>IDataObjectImpl::EnumDAdvise  
 Cria um enumerador para iterar por meio de consultoria conexões atuais.  
  
```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::EnumDAdvise](http://msdn.microsoft.com/library/windows/desktop/ms680127) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameenumformatetca--idataobjectimplenumformatetc"></a><a name="enumformatetc"></a>IDataObjectImpl::EnumFormatEtc  
 Cria um enumerador para iterar a **FORMATETC** estruturas com suporte pelo objeto de dados.  
  
```
HRESULT EnumFormatEtc(  
    DWORD dwDirection,
    IEnumFORMATETC** ppenumFormatEtc);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::EnumFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms683979) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
##  <a name="a-namefiredatachangea--idataobjectimplfiredatachange"></a><a name="firedatachange"></a>IDataObjectImpl::FireDataChange  
 Envia uma notificação de alteração de volta para cada coletor advise que está sendo gerenciado.  
  
```
HRESULT FireDataChange();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namegetcanonicalformatetca--idataobjectimplgetcanonicalformatetc"></a><a name="getcanonicalformatetc"></a>IDataObjectImpl::GetCanonicalFormatEtc  
 Recupera um logicamente equivalente **FORMATETC** estrutura para um que seja mais complexas.  
  
```
HRESULT GetCanonicalFormatEtc(FORMATETC* pformatetcIn, FORMATETC* pformatetcOut);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::GetCanonicalFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms680685) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetdataa--idataobjectimplgetdata"></a><a name="getdata"></a>IDataObjectImpl::GetData  
 Transfere dados do objeto de dados para o cliente.  
  
```
HRESULT GetData(
    FORMATETC* pformatetcIn,
    STGMEDIUM* pmedium);
```  
  
### <a name="remarks"></a>Comentários  
 O *pformatetcIn* parâmetro deve especificar um tipo de mídia de armazenamento de **TYMED_MFPICT**.  
  
 Consulte [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetdataherea--idataobjectimplgetdatahere"></a><a name="getdatahere"></a>IDataObjectImpl::GetDataHere  
 Semelhante ao `GetData`, exceto que o cliente deve alocar o **STGMEDIUM** estrutura.  
  
```
HRESULT GetDataHere(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject:: GetDataHere](http://msdn.microsoft.com/library/windows/desktop/ms687266) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namequerygetdataa--idataobjectimplquerygetdata"></a><a name="querygetdata"></a>IDataObjectImpl::QueryGetData  
 Determina se o objeto de dados oferece suporte a um determinado **FORMATETC** estrutura para transferir dados.  
  
```
HRESULT QueryGetData(FORMATETC* pformatetc);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::QueryGetData](http://msdn.microsoft.com/library/windows/desktop/ms680637) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetdataa--idataobjectimplsetdata"></a><a name="setdata"></a>IDataObjectImpl::SetData  
 Transfere dados do cliente para o objeto de dados.  
  
```
HRESULT SetData(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium,
    BOOL fRelease);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::SetData](http://msdn.microsoft.com/library/windows/desktop/ms686626) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

