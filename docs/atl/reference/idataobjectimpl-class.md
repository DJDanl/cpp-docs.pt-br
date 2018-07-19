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
ms.openlocfilehash: ef7db05e8e8eb0a723354bcd6f53fb283aebe0c8
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37880879"
---
# <a name="idataobjectimpl-class"></a>Classe IDataObjectImpl
Essa classe fornece métodos para dar suporte a transferência uniforme de dados e gerenciamento de conexões.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class IDataObjectImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IDataObjectImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDataObjectImpl::DAdvise](#dadvise)|Estabelece uma conexão entre o objeto de dados e um coletor de aviso. Isso permite que o coletor de avisos receber notificações de alterações no objeto.|  
|[IDataObjectImpl::DUnadvise](#dunadvise)|Encerra uma conexão estabelecida anteriormente por meio `DAdvise`.|  
|[IDataObjectImpl::EnumDAdvise](#enumdadvise)|Cria um enumerador para iterar por meio de conexões de consultoria atuais.|  
|[IDataObjectImpl::EnumFormatEtc](#enumformatetc)|Cria um enumerador para iterar por meio de `FORMATETC` estruturas que têm suportadas pelo objeto de dados. A implementação de ATL retornará E_NOTIMPL.|  
|[IDataObjectImpl::FireDataChange](#firedatachange)|Envia uma notificação de alteração para cada coletor de aviso.|  
|[IDataObjectImpl::GetCanonicalFormatEtc](#getcanonicalformatetc)|Recupera um logicamente equivalente `FORMATETC` estrutura para um que é mais complexo. A implementação de ATL retornará E_NOTIMPL.|  
|[IDataObjectImpl::GetData](#getdata)|Transfere dados do objeto de dados para o cliente. Os dados são descritos em um `FORMATETC` estruturar e são transferidos por meio de um `STGMEDIUM` estrutura.|  
|[IDataObjectImpl::GetDataHere](#getdatahere)|Semelhante ao `GetData`, exceto o cliente deve alocar o `STGMEDIUM` estrutura. A implementação de ATL retornará E_NOTIMPL.|  
|[IDataObjectImpl::QueryGetData](#querygetdata)|Determina se o objeto de dados dá suporte a um determinado `FORMATETC` estrutura para a transferência de dados. A implementação de ATL retornará E_NOTIMPL.|  
|[IDataObjectImpl::SetData](#setdata)|Transfere dados do cliente para o objeto de dados. A implementação de ATL retornará E_NOTIMPL.|  
  
## <a name="remarks"></a>Comentários  
 O [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) interface fornece métodos para dar suporte à transferência uniforme de dados. `IDataObject` usa as estruturas de formato padrão [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) e [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) para recuperar e armazenar dados.  
  
 `IDataObject` também gerencia conexões para informar os coletores para lidar com notificações de alteração de dados. O cliente receber notificações de alteração de dados do objeto de dados, o cliente deve implementar o [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) interface em um objeto chamado um coletor de aviso. Quando o cliente, em seguida, chama `IDataObject::DAdvise`, uma conexão é estabelecida entre o objeto de dados e o coletor de avisos.  
  
 Classe `IDataObjectImpl` fornece uma implementação padrão de `IDataObject` e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.  
  
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
 Isso permite que o coletor de avisos receber notificações de alterações no objeto.  
  
 Para encerrar a conexão, chame [DUnadvise](#dunadvise).  
  
 Ver [IDataObject::DAdvise](http://msdn.microsoft.com/library/windows/desktop/ms692579) no Windows SDK.  
  
##  <a name="dunadvise"></a>  IDataObjectImpl::DUnadvise  
 Encerra uma conexão estabelecida anteriormente por meio [DAdvise](#dadvise).  
  
```
HRESULT DUnadvise(DWORD dwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject::DUnadvise](http://msdn.microsoft.com/library/windows/desktop/ms692448) no Windows SDK.  
  
##  <a name="enumdadvise"></a>  IDataObjectImpl::EnumDAdvise  
 Cria um enumerador para iterar por meio de conexões de consultoria atuais.  
  
```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject::EnumDAdvise](http://msdn.microsoft.com/library/windows/desktop/ms680127) no Windows SDK.  
  
##  <a name="enumformatetc"></a>  IDataObjectImpl::EnumFormatEtc  
 Cria um enumerador para iterar por meio de `FORMATETC` estruturas que têm suportadas pelo objeto de dados.  
  
```
HRESULT EnumFormatEtc(  
    DWORD dwDirection,
    IEnumFORMATETC** ppenumFormatEtc);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject::EnumFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms683979) no Windows SDK.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
##  <a name="firedatachange"></a>  IDataObjectImpl::FireDataChange  
 Envia uma notificação de alteração para cada coletor de aviso que está sendo gerenciado.  
  
```
HRESULT FireDataChange();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
##  <a name="getcanonicalformatetc"></a>  IDataObjectImpl::GetCanonicalFormatEtc  
 Recupera um logicamente equivalente `FORMATETC` estrutura para um que é mais complexo.  
  
```
HRESULT GetCanonicalFormatEtc(FORMATETC* pformatetcIn, FORMATETC* pformatetcOut);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject::GetCanonicalFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms680685) no Windows SDK.  
  
##  <a name="getdata"></a>  IDataObjectImpl::GetData  
 Transfere dados do objeto de dados para o cliente.  
  
```
HRESULT GetData(
    FORMATETC* pformatetcIn,
    STGMEDIUM* pmedium);
```  
  
### <a name="remarks"></a>Comentários  
 O *pformatetcIn* parâmetro deve especificar um tipo de média de armazenamento de TYMED_MFPICT.  
  
 Ver [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) no Windows SDK.  
  
##  <a name="getdatahere"></a>  IDataObjectImpl::GetDataHere  
 Semelhante ao `GetData`, exceto o cliente deve alocar o `STGMEDIUM` estrutura.  
  
```
HRESULT GetDataHere(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject:: GetDataHere](http://msdn.microsoft.com/library/windows/desktop/ms687266) no Windows SDK.  
  
##  <a name="querygetdata"></a>  IDataObjectImpl::QueryGetData  
 Determina se o objeto de dados dá suporte a um determinado `FORMATETC` estrutura para a transferência de dados.  
  
```
HRESULT QueryGetData(FORMATETC* pformatetc);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject::QueryGetData](http://msdn.microsoft.com/library/windows/desktop/ms680637) no Windows SDK.  
  
##  <a name="setdata"></a>  IDataObjectImpl::SetData  
 Transfere dados do cliente para o objeto de dados.  
  
```
HRESULT SetData(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium,
    BOOL fRelease);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
### <a name="remarks"></a>Comentários  
 Ver [IDataObject::SetData](http://msdn.microsoft.com/library/windows/desktop/ms686626) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
