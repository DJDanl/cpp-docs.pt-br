---
title: Classe CAutoRevertImpersonation | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAutoRevertImpersonation
- ATLSECURITY/ATL::CAutoRevertImpersonation
- ATLSECURITY/ATL::CAutoRevertImpersonation::CAutoRevertImpersonation
- ATLSECURITY/ATL::CAutoRevertImpersonation::Attach
- ATLSECURITY/ATL::CAutoRevertImpersonation::Detach
- ATLSECURITY/ATL::CAutoRevertImpersonation::GetAccessToken
dev_langs:
- C++
helpviewer_keywords:
- CAutoRevertImpersonation class
ms.assetid: 43732849-1940-4bd4-9d52-7a5698bb8838
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0b1982fc3c8b0d46dfd636cab63be82509fa07f0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cautorevertimpersonation-class"></a>Classe CAutoRevertImpersonation
Essa classe é revertida [CAccessToken](../../atl/reference/caccesstoken-class.md) objetos para um estado nonimpersonating quando ele sai do escopo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAutoRevertImpersonation
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoRevertImpersonation::CAutoRevertImpersonation](#cautorevertimpersonation)|Constrói uma `CAutoRevertImpersonation` objeto|  
|[CAutoRevertImpersonation:: ~ CAutoRevertImpersonation](#dtor)|Destrói o objeto e reverte a representação de token de acesso.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoRevertImpersonation::Attach](#attach)|Automatiza a reverter a representação de um token de acesso.|  
|[CAutoRevertImpersonation::Detach](#detach)|Cancela a reverter a representação automática.|  
|[CAutoRevertImpersonation::GetAccessToken](#getaccesstoken)|Recupera o atual token de acesso associado a este objeto.|  
  
## <a name="remarks"></a>Comentários  
 Um [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado em um sistema Windows NT ou Windows 2000. Esses tokens de acesso podem ser representados com o `CAccessToken` classe.  
  
 Às vezes, é necessário representar tokens de acesso. Essa classe é fornecida como uma conveniência, mas não executa a representação de tokens de acesso; ele executa somente a reversão automática para um estado nonimpersonated. Isso ocorre porque a representação de token de acesso pode ser executada várias maneiras diferentes.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no SDK do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
##  <a name="attach"></a>CAutoRevertImpersonation::Attach  
 Automatiza a reverter a representação de um token de acesso.  
  
```
void Attach(const CAccessToken* pAT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAT`  
 O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto a ser revertido automaticamente  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser usado apenas se o [CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) objeto foi criado com um valor nulo `CAccessToken` ponteiro, ou se [desanexar](#detach) foi chamado anteriormente. Para casos simples, não é necessário usar esse método.  
  
##  <a name="cautorevertimpersonation"></a>CAutoRevertImpersonation::CAutoRevertImpersonation  
 Constrói um objeto `CAutoRevertImpersonation`.  
  
```
CAutoRevertImpersonation(const CAccessToken* pAT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAT`  
 O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto a ser revertido automaticamente.  
  
### <a name="remarks"></a>Comentários  
 A representação real do token de acesso deve ser feita separadamente do e, preferencialmente, antes da criação de um `CAutoRevertImpersonation` objeto. Essa representação será revertida automaticamente quando o `CAutoRevertImpersonation` objeto sai do escopo.  
  
##  <a name="dtor"></a>CAutoRevertImpersonation:: ~ CAutoRevertImpersonation  
 Destrói o objeto e reverte a representação de token de acesso.  
  
```
~CAutoRevertImpersonation() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Reverte qualquer representação atualmente em vigor para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto fornecido na construção ou por meio de [anexar](#attach) método. Se nenhum `CAccessToken` está associado, o destruidor não tem nenhum efeito.  
  
##  <a name="detach"></a>CAutoRevertImpersonation::Detach  
 Cancela a reverter a representação automática.  
  
```
const CAccessToken* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do anteriormente associado [CAccessToken](../../atl/reference/caccesstoken-class.md), ou nulo se nenhuma associação existente.  
  
### <a name="remarks"></a>Comentários  
 Chamando **desanexar** impede o `CAutoRevertImpersonation` objeto reverter qualquer representação atualmente em vigor para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto associado a este objeto. `CAutoRevertImpersonation`pode ser destruída com nenhum efeito ou reassociados a mesma ou em outra `CAccessToken` objeto usando [Attach](#attach).  
  
##  <a name="getaccesstoken"></a>CAutoRevertImpersonation::GetAccessToken  
 Recupera o atual token de acesso associado a este objeto.  
  
```
const CAccessToken* GetAccessToken() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do anteriormente associado [CAccessToken](../../atl/reference/caccesstoken-class.md), ou nulo se nenhuma associação existente.  
  
### <a name="remarks"></a>Comentários  
 Se esse método é chamado para fins que incluem a reversão de uma representação do `CAccessToken` objeto, o [desanexar](#detach) método deve ser usado em vez disso.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de ATLSecurity](../../visual-cpp-samples.md)   
 [Tokens de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
