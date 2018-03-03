---
title: Classe CHandle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cd58ba8ce15bb26b4e5b768baedbf8ddfe829f2b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chandle-class"></a>Classe CHandle
Essa classe fornece métodos para criar e usar um objeto de identificador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CHandle
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHandle::CHandle](#chandle)|O construtor.|  
|[CHandle:: ~ CHandle](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHandle::Attach](#attach)|Chame este método para anexar o `CHandle` objeto para um identificador existente.|  
|[CHandle::Close](#close)|Chame este método para fechar um `CHandle` objeto.|  
|[CHandle::Detach](#detach)|Chame esse método para desanexar um identificador de um `CHandle` objeto.|  
  
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
 Um `CHandle` objeto pode ser usado sempre que um identificador é necessário: a principal diferença é que o `CHandle` objeto será excluído automaticamente.  
  
> [!NOTE]
>  Algumas funções de API usará NULL como um identificador vazio ou é inválido, enquanto outras usam INVALID_HANDLE_VALUE. `CHandle`usa apenas NULL e será trata INVALID_HANDLE_VALUE como um identificador real. Se você chamar uma API que pode retornar INVALID_HANDLE_VALUE, você deve verificar esse valor antes de chamar [CHandle::Attach](#attach) ou passá-lo para o `CHandle` construtor e em vez disso, passar NULL.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="attach"></a>CHandle::Attach  
 Chame este método para anexar o `CHandle` objeto para um identificador existente.  
  
```
void Attach(HANDLE h) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 `CHandle`será assumir a propriedade do identificador de `h`.  
  
### <a name="remarks"></a>Comentários  
 Atribui o `CHandle` o objeto para o `h` tratar. Em compilações de depurações, será gerado um ATLASSERT se `h` é NULL. É feita nenhuma outra verificação em relação à validade do identificador.  
  
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
 Libera o `CHandle` objeto chamando [CHandle::Close](#close).  
  
##  <a name="close"></a>CHandle::Close  
 Chame este método para fechar um `CHandle` objeto.  
  
```
void Close() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Fecha um identificador de objeto aberto. Se o identificador for NULL, que será o caso se **fechar** já foi chamado, um ATLASSERT será gerado em compilações de depuração.  
  
##  <a name="detach"></a>CHandle::Detach  
 Chame esse método para desanexar um identificador de um `CHandle` objeto.  
  
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
 `CHandle`será assumir a propriedade do identificador de `h`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o novo `CHandle` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o `CHandle` objeto contém um identificador no momento, ela será fechada. O `CHandle` do objeto que está sendo passado terá sua referência de identificador definida como NULL. Isso garante que dois `CHandle` objetos nunca conterá o mesmo identificador de ativo.  
  
##  <a name="operator_handle"></a>Identificador de CHandle::operator  
 Retorna o valor do identificador armazenado.  
  
```  
operator HANDLE() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna o valor armazenado na [CHandle::m_h](#m_h).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
