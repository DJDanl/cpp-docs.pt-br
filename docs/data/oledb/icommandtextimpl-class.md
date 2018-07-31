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
ms.openlocfilehash: 2b54d0db22181089a8470c540ccd72f85c717fbe
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39340287"
---
# <a name="icommandtextimpl-class"></a>Classe ICommandTextImpl
Fornece uma implementação para o [ICommandText](https://msdn.microsoft.com/library/ms714914.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T >  
class ATL_NO_VTABLE ICommandTextImpl   
   : public ICommandImpl<T, ICommandText>  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
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
 Ver [ICommandText::GetCommandText](https://msdn.microsoft.com/library/ms709825.aspx) na *referência do programador do OLE DB*. O *pguidDialect* parâmetro é ignorado por padrão.  

## <a name="setcommandtext"></a> Icommandtextimpl:: SetCommandText
Define o texto de comando, substituindo o texto de comando existente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(SetCommandText)(REFGUID rguidDialect,   
   LPCOLESTR pwszCommand);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [ICommandText:: SetCommandText](https://msdn.microsoft.com/library/ms709757.aspx) na *referência do programador do OLE DB*. 

## <a name="strcommandtext"></a> Icommandtextimpl:: M_strcommandtext
Armazena a cadeia de caracteres de texto de comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
CComBSTR m_strCommandText;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)