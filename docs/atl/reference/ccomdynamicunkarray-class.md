---
title: Classe CComDynamicUnkArray | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComDynamicUnkArray
- ATLCOM/ATL::CComDynamicUnkArray
- ATLCOM/ATL::CComDynamicUnkArray::CComDynamicUnkArray
- ATLCOM/ATL::CComDynamicUnkArray::Add
- ATLCOM/ATL::CComDynamicUnkArray::begin
- ATLCOM/ATL::CComDynamicUnkArray::clear
- ATLCOM/ATL::CComDynamicUnkArray::end
- ATLCOM/ATL::CComDynamicUnkArray::GetAt
- ATLCOM/ATL::CComDynamicUnkArray::GetCookie
- ATLCOM/ATL::CComDynamicUnkArray::GetSize
- ATLCOM/ATL::CComDynamicUnkArray::GetUnknown
- ATLCOM/ATL::CComDynamicUnkArray::Remove
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], managing
- CComDynamicUnkArray class
ms.assetid: 202470d7-9a1b-498f-b96d-659d681acd65
caps.latest.revision: 17
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
ms.openlocfilehash: 69fc2c9dbb86f88c85461e765182fd88050521e9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ccomdynamicunkarray-class"></a>Classe CComDynamicUnkArray
Essa classe armazena uma matriz de **IUnknown** ponteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComDynamicUnkArray
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComDynamicUnkArray::CComDynamicUnkArray](#ccomdynamicunkarray)|Construtor. Inicializa os valores da coleção para **nulo** e o tamanho da coleção como zero.|  
|[CComDynamicUnkArray:: ~ CComDynamicUnkArray](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComDynamicUnkArray::Add](#add)|Chame este método para adicionar um `IUnknown` ponteiro para a matriz.|  
|[CComDynamicUnkArray::begin](#begin)|Retorna um ponteiro para o primeiro `IUnknown` ponteiro na coleção.|  
|[CComDynamicUnkArray::clear](#clear)|Esvazia a matriz.|  
|[CComDynamicUnkArray::end](#end)|Retorna um ponteiro para um após o último **IUnknown** ponteiro na coleção.|  
|[CComDynamicUnkArray::GetAt](#getat)|Recupera o elemento no índice especificado.|  
|[CComDynamicUnkArray::GetCookie](#getcookie)|Chame esse método para obter o cookie associado com um determinado **IUnknown** ponteiro.|  
|[CComDynamicUnkArray::GetSize](#getsize)|Retorna o comprimento de uma matriz.|  
|[CComDynamicUnkArray::GetUnknown](#getunknown)|Chame este método para obter o **IUnknown** ponteiro associado com um cookie determinado.|  
|[CComDynamicUnkArray::Remove](#remove)|Chamar esse método para remover um **IUnknown** ponteiro da matriz.|  
  
## <a name="remarks"></a>Comentários  
 **CComDynamicUnkArray** contém uma matriz alocada dinamicamente do **IUnknown** ponteiros, cada ponto de uma interface em uma conexão. **CComDynamicUnkArray** pode ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo.  
  
 O **CComDynamicUnkArray** métodos [begin](#begin) e [final](#end) pode ser usado para percorrer todos os pontos de conexão (por exemplo, quando um evento é disparado).  
  
 Consulte [adicionando pontos de Conexão para um objeto](../../atl/adding-connection-points-to-an-object.md) para obter detalhes sobre como automatizar a criação de conexão do ponto de proxies.  
  
> [!NOTE]
> **Observação** a classe **CComDynamicUnkArray** é usado pelo **Add Class** assistente ao criar um controle que tem pontos de Conexão. Se você quiser especificar o número de pontos de Conexão manualmente, altere a referência de **CComDynamicUnkArray** para `CComUnkArray<` *n* `>`, onde *n* é o número de pontos de conexão necessários.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="add"></a>CComDynamicUnkArray::Add  
 Chame este método para adicionar um **IUnknown** ponteiro para a matriz.  
  
```
DWORD Add(IUnknown* pUnk);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 O **IUnknown** ponteiro para adicionar à matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o cookie associado com o ponteiro recém-adicionada.  
  
##  <a name="begin"></a>CComDynamicUnkArray::begin  
 Retorna um ponteiro para o início da coleção de **IUnknown** ponteiros de interface.  
  
```
IUnknown**
    begin();
```     
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um **IUnknown** ponteiro de interface.  
  
### <a name="remarks"></a>Comentários  
 A coleção contém ponteiros para interfaces armazenados localmente como **IUnknown**. Você converter cada **IUnknown** interface para o tipo de interface real e, em seguida, chamar através dele. Você não precisa consultar a interface primeiro.  
  
 Antes de usar o **IUnknown** interface, você deve verificar que não é **nulo**.  
  
##  <a name="clear"></a>CComDynamicUnkArray::clear  
 Esvazia a matriz.  
  
```
void clear();
```  
  
##  <a name="ccomdynamicunkarray"></a>CComDynamicUnkArray::CComDynamicUnkArray  
 O construtor.  
  
```
CComDynamicUnkArray();
```  
  
### <a name="remarks"></a>Comentários  
 Define o tamanho da coleção como zero e inicializa os valores para **nulo**. O destruidor libera a coleção, se necessário.  
  
##  <a name="dtor"></a>CComDynamicUnkArray:: ~ CComDynamicUnkArray  
 O destruidor.  
  
```
~CComDynamicUnkArray();
```  
  
### <a name="remarks"></a>Comentários  
 Libera os recursos alocados pelo construtor de classe.  
  
##  <a name="end"></a>CComDynamicUnkArray::end  
 Retorna um ponteiro para um após o último **IUnknown** ponteiro na coleção.  
  
```
IUnknown**
    end();
```     
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um **IUnknown** ponteiro de interface.  
  
##  <a name="getat"></a>CComDynamicUnkArray::GetAt  
 Recupera o elemento no índice especificado.  
  
```
IUnknown* GetAt(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do elemento a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface.  
  
##  <a name="getcookie"></a>CComDynamicUnkArray::GetCookie  
 Chame esse método para obter o cookie associado com um determinado **IUnknown** ponteiro.  
  
```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppFind`  
 O **IUnknown** ponteiro para o qual o cookie associado é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o cookie associado com a **IUnknown** ponteiro, ou zero se nenhuma correspondência **IUnknown** ponteiro for encontrado.  
  
### <a name="remarks"></a>Comentários  
 Se houver mais de uma instância do mesmo **IUnknown** ponteiro, esta função retorna o cookie para primeiro.  
  
##  <a name="getsize"></a>CComDynamicUnkArray::GetSize  
 Retorna o comprimento de uma matriz.  
  
```
int GetSize() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da matriz.  
  
##  <a name="getunknown"></a>CComDynamicUnkArray::GetUnknown  
 Chame este método para obter o **IUnknown** ponteiro associado com um cookie determinado.  
  
```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCookie`  
 O cookie para o qual associado **IUnknown** ponteiro é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o **IUnknown** ponteiro ou NULL se nenhum cookie correspondente for encontrado.  
  
##  <a name="remove"></a>CComDynamicUnkArray::Remove  
 Chamar esse método para remover um **IUnknown** ponteiro da matriz.  
  
```
BOOL Remove(DWORD dwCookie);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCookie`  
 A referência de cookie do **IUnknown** ponteiro a ser removido da matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se o ponteiro for removido; Caso contrário, FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComUnkArray](../../atl/reference/ccomunkarray-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

