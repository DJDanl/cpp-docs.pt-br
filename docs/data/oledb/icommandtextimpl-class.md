---
title: Classe ICommandTextImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ICommandText
- GetCommandText
- ICommandTextImpl.GetCommandText
- ICommandTextImpl::GetCommandText
- ATL::ICommandTextImpl::m_strCommandText
- ICommandTextImpl<T>::m_strCommandText
- m_strCommandText
- ICommandTextImpl.m_strCommandText
- ICommandTextImpl::m_strCommandText
- ATL::ICommandTextImpl<T>::m_strCommandText
- ATL.ICommandTextImpl.m_strCommandText
- ICommandTextImpl.SetCommandText
- ICommandTextImpl::SetCommandText
- SetCommandText
dev_langs:
- C++
helpviewer_keywords:
- ICommandText class
- GetCommandText method
- m_strCommandText
- SetCommandText method
ms.assetid: 9c2715cc-1e55-4468-8327-85341617ed46
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b73111fe05a7c752edda0c95f1289a125828d4a5
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49082547"
---
# <a name="icommandtextimpl-class"></a>Classe ICommandTextImpl

Fornece uma implementação para o [ICommandText](/previous-versions/windows/desktop/ms714914) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T >  
class ATL_NO_VTABLE ICommandTextImpl   
   : public ICommandImpl<T, ICommandText>  
```  
  
### <a name="parameters"></a>Parâmetros  

*T*<br/>
A classe de comando derivada de `ICommandTextImpl`. 

## <a name="requirements"></a>Requisitos  

**Cabeçalho:** altdb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetCommandText](#getcommandtext)|Retorna o comando de texto definido pela última chamada para [SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md).|  
|[SetCommandText](#setcommandtext)|Define o texto de comando, substituindo o texto de comando existente.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_strCommandText](#strcommandtext)|Armazena o texto do comando.|  
  
## <a name="remarks"></a>Comentários  

Uma interface obrigatória em comandos.  
 
## <a name="getcommandtext"></a> Icommandtextimpl:: Getcommandtext

Retorna o comando de texto definido pela última chamada para [SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md).  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetCommandText)(GUID * pguidDialect,   
   LPOLESTR * ppwszCommand);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [ICommandText::GetCommandText](/previous-versions/windows/desktop/ms709825) na *referência do programador do OLE DB*. O *pguidDialect* parâmetro é ignorado por padrão.  

## <a name="setcommandtext"></a> Icommandtextimpl:: SetCommandText

Define o texto de comando, substituindo o texto de comando existente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(SetCommandText)(REFGUID rguidDialect,   
   LPCOLESTR pwszCommand);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [ICommandText:: SetCommandText](/previous-versions/windows/desktop/ms709757) na *referência do programador do OLE DB*. 

## <a name="strcommandtext"></a> Icommandtextimpl:: M_strcommandtext

Armazena a cadeia de caracteres de texto de comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
CComBSTR m_strCommandText;  
```  
  
## <a name="see-also"></a>Consulte também  

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)