---
title: Classe CComGITPtr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComGITPtr
- ATLBASE/ATL::CComGITPtr
- ATLBASE/ATL::CComGITPtr::CComGITPtr
- ATLBASE/ATL::CComGITPtr::Attach
- ATLBASE/ATL::CComGITPtr::CopyTo
- ATLBASE/ATL::CComGITPtr::Detach
- ATLBASE/ATL::CComGITPtr::GetCookie
- ATLBASE/ATL::CComGITPtr::Revoke
- ATLBASE/ATL::CComGITPtr::m_dwCookie
dev_langs: C++
helpviewer_keywords: CComGITPtr class
ms.assetid: af895acb-525a-4555-bb67-b241b7df515b
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c001d0d1ca8e756b24d97051d100e7d71723569c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomgitptr-class"></a>Classe CComGITPtr
Essa classe fornece métodos para lidar com ponteiros de interface e a tabela de interface global (GIT).  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CComGITPtr
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do ponteiro de interface a ser armazenado no GIT.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComGITPtr::CComGITPtr](#ccomgitptr)|O construtor.|  
|[CComGITPtr:: ~ CComGITPtr](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComGITPtr::Attach](#attach)|Chame este método para registrar o ponteiro de interface na tabela de interface global (GIT).|  
|[CComGITPtr::CopyTo](#copyto)|Chame este método para copiar a interface da tabela de interface global (GIT) para o ponteiro transmitido.|  
|[CComGITPtr::Detach](#detach)|Chame esse método para desassociar a interface do `CComGITPtr` objeto.|  
|[CComGITPtr::GetCookie](#getcookie)|Chame este método para retornar o cookie a `CComGITPtr` objeto.|  
|[CComGITPtr::Revoke](#revoke)|Chame esse método para remover a interface da tabela de interface global (GIT).|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComGITPtr::operator DWORD](#operator_dword)|Retorna o cookie a `CComGITPtr` objeto.|  
|[CComGITPtr::operator =](#operator_eq)|Operador de atribuição.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComGITPtr::m_dwCookie](#m_dwcookie)|O cookie.|  
  
## <a name="remarks"></a>Comentários  
 Objetos que o marshaler de threads livres de agregação e precisam usar ponteiros de interface obtidos a partir de outros objetos devem realizar etapas adicionais para garantir que as interfaces são empacotadas corretamente. Normalmente, isso envolve armazenar os ponteiros de interface no GIT e obter o ponteiro do GIT cada vez que ele é usado. A classe `CComGITPtr` é fornecido para ajudá-lo a usar ponteiros de interface armazenados no GIT.  
  
> [!NOTE]
>  O recurso de tabela de interface global só está disponível no Windows 95 com DCOM versão 1.1 e posterior, Windows 98, Windows NT 4.0 com Service Pack 3 e posterior e Windows 2000.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="attach"></a>CComGITPtr::Attach  
 Chame este método para registrar o ponteiro de interface na tabela de interface global (GIT).  
  
```
HRESULT Attach(T* p) throw();

HRESULT Attach(DWORD dwCookie) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 O ponteiro de interface a ser adicionada para o GIT.  
  
 `dwCookie`  
 O cookie usado para identificar o ponteiro de interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Compilações de depuração, um erro de asserção ocorrerá se o GIT não é válido ou se o cookie é igual a NULL.  
  
##  <a name="ccomgitptr"></a>CComGITPtr::CComGITPtr  
 O construtor.  
  
```
CComGITPtr() throw();
CComGITPtr(T* p);
CComGITPtr(const CComGITPtr& git);
explicit CComGITPtr(DWORD dwCookie) throw();
CComGITPtr(CComGITPtr&& rv);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `p`  
 Um ponteiro de interface a ser armazenado na tabela de interface global (GIT).  
  
 [in] `git`  
 Uma referência a um existente `CComGITPtr` objeto.  
  
 [in] `dwCookie`  
 Um cookie usado para identificar o ponteiro de interface.  
  
 [in] `rv`  
 A fonte `CComGITPtr` objeto para mover dados do.  
  
### <a name="remarks"></a>Comentários  
 Cria um novo `CComGITPtr` do objeto, usando opcionalmente uma existente `CComGITPtr` objeto.  
  
 O uso do construtor `rv` é um construtor de movimento. Os dados são movidos da fonte de `rv`e, em seguida, `rv` está desmarcada.  
  
##  <a name="dtor"></a>CComGITPtr:: ~ CComGITPtr  
 O destruidor.  
  
```
~CComGITPtr() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Remove a interface da tabela de interface global (GIT), usando [CComGITPtr::Revoke](#revoke).  
  
##  <a name="copyto"></a>CComGITPtr::CopyTo  
 Chame este método para copiar a interface da tabela de interface global (GIT) para o ponteiro transmitido.  
  
```
HRESULT CopyTo(T** pp) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pp`  
 O ponteiro que recebe a interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 A interface do GIT é copiada para o ponteiro transmitido. O ponteiro deve ser liberado, o chamador quando ele não é mais necessário.  
  
##  <a name="detach"></a>CComGITPtr::Detach  
 Chame esse método para desassociar a interface do `CComGITPtr` objeto.  
  
```
DWORD Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o cookie a `CComGITPtr` objeto.  
  
### <a name="remarks"></a>Comentários  
 Cabe ao chamador para remover a interface do GIT, usando [CComGITPtr::Revoke](#revoke).  
  
##  <a name="getcookie"></a>CComGITPtr::GetCookie  
 Chame este método para retornar o cookie a `CComGITPtr` objeto.  
  
```
DWORD GetCookie() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o cookie.  
  
### <a name="remarks"></a>Comentários  
 O cookie é uma variável usada para identificar uma interface e sua localização.  
  
##  <a name="m_dwcookie"></a>CComGITPtr::m_dwCookie  
 O cookie.  
  
```
DWORD m_dwCookie;
```  
  
### <a name="remarks"></a>Comentários  
 O cookie é usada para identificar uma interface e seu local de uma variável de membro.  
  
##  <a name="operator_eq"></a>CComGITPtr::operator =  
 O operador de atribuição.  
  
```
CComGITPtr& operator= (T* p);
CComGITPtr& operator= (const CComGITPtr& git);
CComGITPtr& operator= (DWORD dwCookie);
CComGITPtr& operator= (CComGITPtr&& rv);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `p`  
 Um ponteiro para uma interface.  
  
 [in] `git`  
 Uma referência a um objeto `CComGITPtr`.  
  
 [in] `dwCookie`  
 Um cookie usado para identificar o ponteiro de interface.  
  
 [in] `rv`  
 O `CComGITPtr` para mover dados do.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CComGITPtr` objeto.  
  
### <a name="remarks"></a>Comentários  
 Atribui um novo valor para uma `CComGITPtr` objeto, a partir de um objeto existente ou uma referência a uma tabela de interface global.  
  
##  <a name="operator_dword"></a>CComGITPtr::operator DWORD  
 Retorna o cookie associado a `CComGITPtr` objeto.  
  
```  
operator DWORD() const;
```  
  
### <a name="remarks"></a>Comentários  
 O cookie é uma variável usada para identificar uma interface e sua localização.  
  
##  <a name="revoke"></a>CComGITPtr::Revoke  
 Chame esse método para remover a interface atual da tabela de interface global (GIT).  
  
```
HRESULT Revoke() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Remove a interface do GIT.  
  
## <a name="see-also"></a>Consulte também  
 [Marshaler de threads livres](../../atl/atl-and-the-free-threaded-marshaler.md)   
 [Acessando Interfaces entre Apartments](http://msdn.microsoft.com/library/windows/desktop/ms682353)   
 [Quando usar a tabela de Interface Global](http://msdn.microsoft.com/library/windows/desktop/ms693729)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
