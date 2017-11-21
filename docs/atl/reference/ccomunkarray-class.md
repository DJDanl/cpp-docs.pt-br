---
title: Classe CComUnkArray | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComUnkArray
- ATLCOM/ATL::CComUnkArray
- ATLCOM/ATL::CComUnkArray::CComUnkArray
- ATLCOM/ATL::CComUnkArray::Add
- ATLCOM/ATL::CComUnkArray::begin
- ATLCOM/ATL::CComUnkArray::end
- ATLCOM/ATL::CComUnkArray::GetCookie
- ATLCOM/ATL::CComUnkArray::GetUnknown
- ATLCOM/ATL::CComUnkArray::Remove
dev_langs: C++
helpviewer_keywords:
- connection points [C++], managing
- CComUnkArray class
ms.assetid: 5fd4b378-a7b5-4cc1-8866-8ab72a73639e
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 14c2b7e05ed303d8b18ae40619bc63a75f025662
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccomunkarray-class"></a>Classe CComUnkArray
Essa classe armazena **IUnknown** ponteiros e foi projetado para ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<unsigned int nMaxSize>
class CComUnkArray
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nMaxSize*  
 O número máximo de **IUnknown** ponteiros que podem ser mantidos no conjunto estático.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComUnkArray::CComUnkArray](#ccomunkarray)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComUnkArray::Add](#add)|Chame este método para adicionar um **IUnknown** ponteiro para a matriz.|  
|[CComUnkArray::begin](#begin)|Retorna um ponteiro para o primeiro **IUnknown** ponteiro na coleção.|  
|[CComUnkArray::end](#end)|Retorna um ponteiro para após o último **IUnknown** ponteiro na coleção.|  
|[CComUnkArray::GetCookie](#getcookie)|Chame esse método para obter o cookie associado com um determinado **IUnknown** ponteiro.|  
|[CComUnkArray::GetUnknown](#getunknown)|Chame este método para obter o **IUnknown** ponteiro associado com um cookie determinado.|  
|[CComUnkArray::Remove](#remove)|Chame este método para remover um **IUnknown** ponteiro da matriz.|  
  
## <a name="remarks"></a>Comentários  
 **CComUnkArray** contém um número fixo de **IUnknown** ponteiros, cada ponto de uma interface em uma conexão. **CComUnkArray** pode ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo. **CComUnkArray\<1 >** é uma especialização de modelo de **CComUnkArray** que foi otimizado para o ponto de conexão de um.  
  
 O **CComUnkArray** métodos [começar](#begin) e [final](#end) pode ser usado para executar um loop através de todos os pontos de conexão (por exemplo, quando um evento é disparado).  
  
 Consulte [adicionando pontos de Conexão para um objeto](../../atl/adding-connection-points-to-an-object.md) para obter detalhes sobre como automatizar a criação de conexão do ponto de proxies.  
  
> [!NOTE]
> **Observação** a classe [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md) é usado pelo **Adicionar classe** assistente ao criar um controle que tem pontos de Conexão. Se você quiser especificar o número de pontos de Conexão manualmente, altere a referência de **CComDynamicUnkArray** para `CComUnkArray<`  *n*  `>`, onde  *n*  é o número de pontos de conexão necessários.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="add"></a>CComUnkArray::Add  
 Chame este método para adicionar um **IUnknown** ponteiro para a matriz.  
  
```
DWORD Add(IUnknown* pUnk);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 Chame este método para adicionar um **IUnknown** ponteiro para a matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o cookie associado com o ponteiro recém-adicionado ou 0 se a matriz não é grande o suficiente para conter o ponteiro.  
  
##  <a name="begin"></a>CComUnkArray::begin  
 Retorna um ponteiro para o início da coleção de **IUnknown** ponteiros de interface.  
  
```
IUnknown**
    begin();
```     
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um **IUnknown** ponteiro de interface.  
  
### <a name="remarks"></a>Comentários  
 A coleção contém ponteiros para interfaces armazenados localmente como **IUnknown**. Converter cada **IUnknown** interface para o tipo de interface real e, em seguida, chamar por meio dele. Você não precisa consultar a interface primeiro.  
  
 Antes de usar o **IUnknown** interface, você deve verificar que não é **nulo**.  
  
##  <a name="ccomunkarray"></a>CComUnkArray::CComUnkArray  
 O construtor.  
  
```
CComUnkArray();
```  
  
### <a name="remarks"></a>Comentários  
 Define a coleção para manter `nMaxSize` **IUnknown** ponteiros e inicializa os ponteiros para **nulo**.  
  
##  <a name="end"></a>CComUnkArray::end  
 Retorna um ponteiro para após o último **IUnknown** ponteiro na coleção.  
  
```
IUnknown**
    end();
```     
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um **IUnknown** ponteiro de interface.  
  
### <a name="remarks"></a>Comentários  
 O `CComUnkArray` métodos **começar** e **final** pode ser usado para executar um loop através de todos os pontos de conexão, por exemplo, quando um evento é disparado.  
  
 [!code-cpp[NVC_ATL_COM#44](../../atl/codesnippet/cpp/ccomunkarray-class_1.cpp)]  
  
##  <a name="getcookie"></a>CComUnkArray::GetCookie  
 Chame esse método para obter o cookie associado com um determinado **IUnknown** ponteiro.  
  
```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppFind`  
 O **IUnknown** ponteiro para o qual o cookie associado é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o cookie associado a **IUnknown** ponteiro, ou 0 se nenhuma correspondência **IUnknown** ponteiro foi encontrado.  
  
### <a name="remarks"></a>Comentários  
 Se houver mais de uma instância do mesmo **IUnknown** ponteiro, essa função retorna o cookie para o primeiro.  
  
##  <a name="getunknown"></a>CComUnkArray::GetUnknown  
 Chame este método para obter o **IUnknown** ponteiro associado com um cookie determinado.  
  
```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCookie`  
 O cookie para o qual associado **IUnknown** ponteiro é necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o **IUnknown** ponteiro, ou nulo se nenhum cookie correspondente for encontrado.  
  
##  <a name="remove"></a>CComUnkArray::Remove  
 Chame este método para remover um **IUnknown** ponteiro da matriz.  
  
```
BOOL Remove(DWORD dwCookie);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCookie`  
 O cookie referenciando o **IUnknown** ponteiro a ser removido da matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se o ponteiro for removido, **FALSE** caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
