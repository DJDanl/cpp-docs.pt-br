---
title: Classe IDataObjectImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IDataObjectImpl
- ATLCTL/ATL::IDataObjectImpl
- ATLCTL/ATL::IDataObjectImpl::DAdvise
- ATLCTL/ATL::IDataObjectImpl::DUnadvise
- ATLCTL/ATL::IDataObjectImpl::EnumDAdvise
- ATLCTL/ATL::IDataObjectImpl::EnumFormatEtc
- ATLCTL/ATL::IDataObjectImpl::FireDataChange
- ATLCTL/ATL::IDataObjectImpl::GetCanonicalFormatEtc
- ATLCTL/ATL::IDataObjectImpl::GetData
- ATLCTL/ATL::IDataObjectImpl::GetDataHere
- ATLCTL/ATL::IDataObjectImpl::QueryGetData
- ATLCTL/ATL::IDataObjectImpl::SetData
dev_langs:
- C++
helpviewer_keywords:
- data transfer [C++]
- data transfer [C++], Uniform Data Transfer
- IDataObjectImpl class
- IDataObject, ATL implementation
ms.assetid: b680f0f7-7795-40a1-a0f6-f48768201c89
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a3ffcdd8cc8320b2534d928171fe75619062b300
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32365475"
---
# <a name="idataobjectimpl-class"></a>Classe IDataObjectImpl
Essa classe fornece métodos para suporte uniforme de transferência de dados e gerenciamento de conexões.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class IDataObjectImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IDataObjectImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDataObjectImpl::DAdvise](#dadvise)|Estabelece uma conexão entre o objeto de dados e um coletor de aviso. Isso permite que o coletor de aviso receber notificações de alterações no objeto.|  
|[IDataObjectImpl::DUnadvise](#dunadvise)|Encerra uma conexão estabelecida anteriormente por meio de `DAdvise`.|  
|[IDataObjectImpl::EnumDAdvise](#enumdadvise)|Cria um enumerador para iterar por meio de consultoria conexões atuais.|  
|[IDataObjectImpl::EnumFormatEtc](#enumformatetc)|Cria um enumerador para iterar por meio de **FORMATETC** estruturas com suporte pelo objeto de dados. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::FireDataChange](#firedatachange)|Envia uma notificação de alteração para cada coletor de aviso.|  
|[IDataObjectImpl::GetCanonicalFormatEtc](#getcanonicalformatetc)|Recupera um logicamente equivalente **FORMATETC** estrutura para um que seja mais complexas. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::GetData](#getdata)|Transfere dados do objeto de dados para o cliente. Os dados são descritos em uma **FORMATETC** estrutura e é transferido por meio de um **STGMEDIUM** estrutura.|  
|[IDataObjectImpl::GetDataHere](#getdatahere)|Semelhante ao `GetData`, exceto o cliente deve alocar o **STGMEDIUM** estrutura. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::QueryGetData](#querygetdata)|Determina se o objeto de dados oferece suporte a um determinado **FORMATETC** estrutura para a transferência de dados. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IDataObjectImpl::SetData](#setdata)|Transfere dados do cliente para o objeto de dados. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 O [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) interface fornece métodos para dar suporte à transferência de dados uniforme. `IDataObject` usa as formato padrão estruturas [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) e [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) para recuperar e armazenar dados.  
  
 `IDataObject` também gerencia conexões para informar coletores para lidar com as notificações de alteração de dados. Para o cliente receber notificações de alteração de dados do objeto de dados, o cliente deve implementar o [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) interface em um objeto chamado um coletor de aviso. Quando o cliente, em seguida, chama **IDataObject::DAdvise**, uma conexão é estabelecida entre o objeto de dados e o coletor de aviso.  
  
 Classe `IDataObjectImpl` fornece uma implementação padrão de `IDataObject` e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IDataObject`  
  
 `IDataObjectImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="dadvise"></a>  IDataObjectImpl::DAdvise  
 Estabelece uma conexão entre o objeto de dados e um coletor de aviso.  
  
```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Isso permite que o coletor de aviso receber notificações de alterações no objeto.  
  
 Para encerrar a conexão, chame [DUnadvise](#dunadvise).  
  
 Consulte [IDataObject::DAdvise](http://msdn.microsoft.com/library/windows/desktop/ms692579) no SDK do Windows.  
  
##  <a name="dunadvise"></a>  IDataObjectImpl::DUnadvise  
 Encerra uma conexão estabelecida anteriormente por meio de [DAdvise](#dadvise).  
  
```
HRESULT DUnadvise(DWORD dwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::DUnadvise](http://msdn.microsoft.com/library/windows/desktop/ms692448) no SDK do Windows.  
  
##  <a name="enumdadvise"></a>  IDataObjectImpl::EnumDAdvise  
 Cria um enumerador para iterar por meio de consultoria conexões atuais.  
  
```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::EnumDAdvise](http://msdn.microsoft.com/library/windows/desktop/ms680127) no SDK do Windows.  
  
##  <a name="enumformatetc"></a>  IDataObjectImpl::EnumFormatEtc  
 Cria um enumerador para iterar por meio de **FORMATETC** estruturas com suporte pelo objeto de dados.  
  
```
HRESULT EnumFormatEtc(  
    DWORD dwDirection,
    IEnumFORMATETC** ppenumFormatEtc);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::EnumFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms683979) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
##  <a name="firedatachange"></a>  IDataObjectImpl::FireDataChange  
 Envia uma notificação de alteração para cada coletor de aviso que está sendo gerenciado.  
  
```
HRESULT FireDataChange();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="getcanonicalformatetc"></a>  IDataObjectImpl::GetCanonicalFormatEtc  
 Recupera um logicamente equivalente **FORMATETC** estrutura para um que seja mais complexas.  
  
```
HRESULT GetCanonicalFormatEtc(FORMATETC* pformatetcIn, FORMATETC* pformatetcOut);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::GetCanonicalFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms680685) no SDK do Windows.  
  
##  <a name="getdata"></a>  IDataObjectImpl::GetData  
 Transfere dados do objeto de dados para o cliente.  
  
```
HRESULT GetData(
    FORMATETC* pformatetcIn,
    STGMEDIUM* pmedium);
```  
  
### <a name="remarks"></a>Comentários  
 O *pformatetcIn* parâmetro deve especificar um tipo de mídia de armazenamento de **TYMED_MFPICT**.  
  
 Consulte [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) no SDK do Windows.  
  
##  <a name="getdatahere"></a>  IDataObjectImpl::GetDataHere  
 Semelhante ao `GetData`, exceto o cliente deve alocar o **STGMEDIUM** estrutura.  
  
```
HRESULT GetDataHere(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject:: GetDataHere](http://msdn.microsoft.com/library/windows/desktop/ms687266) no SDK do Windows.  
  
##  <a name="querygetdata"></a>  IDataObjectImpl::QueryGetData  
 Determina se o objeto de dados oferece suporte a um determinado **FORMATETC** estrutura para a transferência de dados.  
  
```
HRESULT QueryGetData(FORMATETC* pformatetc);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDataObject::QueryGetData](http://msdn.microsoft.com/library/windows/desktop/ms680637) no SDK do Windows.  
  
##  <a name="setdata"></a>  IDataObjectImpl::SetData  
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
 Consulte [IDataObject::SetData](http://msdn.microsoft.com/library/windows/desktop/ms686626) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
