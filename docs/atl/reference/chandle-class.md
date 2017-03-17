---
title: Classe CHandle | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHandle
- ATLBASE/ATL::CHandle
- ATLBASE/ATL::CHandle::CHandle
- ATLBASE/ATL::CHandle::Attach
- ATLBASE/ATL::CHandle::Close
- ATLBASE/ATL::CHandle::Detach
- ATLBASE/ATL::CHandle::m_h
dev_langs:
- C++
helpviewer_keywords:
- CHandle class
ms.assetid: 883e9db5-40ec-4e29-9c74-4dd2ddd2e35d
caps.latest.revision: 19
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: bbc0703ae5eaab01c0819be7e378509c7dc579ef
ms.lasthandoff: 02/25/2017

---
# <a name="chandle-class"></a>Classe CHandle
Essa classe fornece métodos para criar e usar um objeto de identificador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CHandle
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHandle::CHandle](#chandle)|O construtor.|  
|[CHandle:: ~ CHandle](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHandle::Attach](#attach)|Chame este método para anexar o `CHandle` objeto para um identificador existente.|  
|[CHandle::Close](#close)|Chamar esse método para fechar um `CHandle` objeto.|  
|[CHandle::Detach](#detach)|Chame esse método para desanexar um identificador de uma `CHandle` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Identificador de CHandle::operator](#operator_handle)|Retorna o valor do identificador armazenado.|  
|[CHandle::operator =](#operator_eq)|Operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHandle::m_h](#m_h)|A variável de membro que armazena o identificador.|  
  
## <a name="remarks"></a>Comentários  
 A `CHandle` objeto pode ser usado sempre que um identificador é necessário: a principal diferença é que o `CHandle` objeto será excluído automaticamente.  
  
> [!NOTE]
>  Algumas funções de API usará NULL como um identificador vazio ou é inválido, enquanto outros usam INVALID_HANDLE_VALUE. `CHandle`usa apenas NULL e irá trata INVALID_HANDLE_VALUE como um identificador real. Se você chamar uma API que pode retornar INVALID_HANDLE_VALUE, você deve verificar esse valor antes de chamar [CHandle::Attach](#attach) ou passá-lo para o `CHandle` construtor e em vez disso, passar NULL.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="attach"></a>CHandle::Attach  
 Chame este método para anexar o `CHandle` objeto para um identificador existente.  
  
```
void Attach(HANDLE h) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 `CHandle`será assumir a propriedade do identificador `h`.  
  
### <a name="remarks"></a>Comentários  
 Atribui o `CHandle` o objeto para o `h` tratar. Em compilações de depurações, será gerado um ATLASSERT se `h` é NULL. Nenhuma outra verificação em relação à validade do identificador é feita.  
  
##  <a name="chandle"></a>CHandle::CHandle  
 O construtor.  
  
```
CHandle() throw();
CHandle(CHandle& h) throw();
explicit CHandle(HANDLE h) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 Um identificador existente ou `CHandle`.  
  
### <a name="remarks"></a>Comentários  
 Cria um novo `CHandle` do objeto, opcionalmente usando um identificador existente ou `CHandle` objeto.  
  
##  <a name="dtor"></a>CHandle:: ~ CHandle  
 O destruidor.  
  
```
~CHandle() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o `CHandle` chamando [CHandle::Close](#close).  
  
##  <a name="close"></a>CHandle::Close  
 Chamar esse método para fechar um `CHandle` objeto.  
  
```
void Close() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Fecha um identificador de objeto aberto. Se o identificador for NULL, que será o caso se **fechar** já foi chamado, um ATLASSERT será gerado em compilações de depuração.  
  
##  <a name="detach"></a>CHandle::Detach  
 Chame esse método para desanexar um identificador de uma `CHandle` objeto.  
  
```
HANDLE Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador a ser desanexado.  
  
### <a name="remarks"></a>Comentários  
 Libera a propriedade do identificador.  
  
##  <a name="m_h"></a>CHandle::m_h  
 A variável de membro que armazena o identificador.  
  
```
HANDLE m_h;
```  
  
##  <a name="operator_eq"></a>CHandle::operator =  
 O operador de atribuição.  
  
```
CHandle& operator=(CHandle& h) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 `CHandle`será assumir a propriedade do identificador `h`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o novo `CHandle` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o `CHandle` objeto contém um identificador no momento, ela será fechada. O `CHandle` do objeto que está sendo passado terá sua referência de identificador definida como NULL. Isso garante que duas `CHandle` objetos nunca irá conter o mesmo identificador de ativo.  
  
##  <a name="operator_handle"></a>Identificador de CHandle::operator  
 Retorna o valor do identificador armazenado.  
  
```  
operator HANDLE() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna o valor armazenado em [CHandle::m_h](#m_h).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

