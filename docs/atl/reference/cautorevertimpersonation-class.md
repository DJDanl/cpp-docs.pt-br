---
title: Classe CAutoRevertImpersonation | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
caps.latest.revision: 22
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
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: f86f1e5067583b3c4c615c8ca3095e8b67b3fffe
ms.lasthandoff: 02/25/2017

---
# <a name="cautorevertimpersonation-class"></a>Classe CAutoRevertImpersonation
Essa classe é revertida [CAccessToken](../../atl/reference/caccesstoken-class.md) objetos para um estado nonimpersonating quando ele sai do escopo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAutoRevertImpersonation
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoRevertImpersonation::CAutoRevertImpersonation](#cautorevertimpersonation)|Constrói uma `CAutoRevertImpersonation` objeto|  
|[CAutoRevertImpersonation:: ~ CAutoRevertImpersonation](#dtor)|Destrói o objeto e reverte a representação de token de acesso.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoRevertImpersonation::Attach](#attach)|Automatiza reverter a representação de um token de acesso.|  
|[CAutoRevertImpersonation::Detach](#detach)|Cancela a reverter a representação automática.|  
|[CAutoRevertImpersonation::GetAccessToken](#getaccesstoken)|Recupera o atual token de acesso associado ao objeto.|  
  
## <a name="remarks"></a>Comentários  
 Um [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou thread e alocado para cada usuário conectado em um sistema Windows NT ou Windows 2000. Esses tokens de acesso podem ser representados com o `CAccessToken` classe.  
  
 Às vezes, é necessário representar os tokens de acesso. Essa classe é fornecida como uma conveniência, mas não executa a representação de tokens de acesso; Ele apenas executa a reversão automática em um estado nonimpersonated. Isso ocorre porque a representação de token de acesso pode ser executada várias maneiras diferentes.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="attach"></a>CAutoRevertImpersonation::Attach  
 Automatiza reverter a representação de um token de acesso.  
  
```
void Attach(const CAccessToken* pAT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAT`  
 O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto a ser revertido automaticamente  
  
### <a name="remarks"></a>Comentários  
 Este método só deve ser usado se o [CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) objeto foi criado com um valor nulo `CAccessToken` ponteiro, ou se [desanexar](#detach) foi chamado anteriormente. Para casos simples, não é necessário usar esse método.  
  
##  <a name="cautorevertimpersonation"></a>CAutoRevertImpersonation::CAutoRevertImpersonation  
 Constrói um objeto `CAutoRevertImpersonation`.  
  
```
CAutoRevertImpersonation(const CAccessToken* pAT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAT`  
 O endereço do [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto a ser revertido automaticamente.  
  
### <a name="remarks"></a>Comentários  
 A representação real do token de acesso deve ser executada separadamente do e, preferencialmente, antes da criação de uma `CAutoRevertImpersonation` objeto. Essa representação será revertida automaticamente quando o `CAutoRevertImpersonation` objeto sai do escopo.  
  
##  <a name="dtor"></a>CAutoRevertImpersonation:: ~ CAutoRevertImpersonation  
 Destrói o objeto e reverte a representação de token de acesso.  
  
```
~CAutoRevertImpersonation() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Reverterá qualquer representação em vigor para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto fornecido na construção ou por meio de [Attach](#attach) método. Se nenhum `CAccessToken` está associado, o destruidor não tem nenhum efeito.  
  
##  <a name="detach"></a>CAutoRevertImpersonation::Detach  
 Cancela a reverter a representação automática.  
  
```
const CAccessToken* Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do previamente associado [CAccessToken](../../atl/reference/caccesstoken-class.md), ou nulo se nenhuma associação existia.  
  
### <a name="remarks"></a>Comentários  
 Chamando **desanexar** impede o `CAutoRevertImpersonation` objeto reverter qualquer representação em vigor para o [CAccessToken](../../atl/reference/caccesstoken-class.md) objeto associado a esse objeto. `CAutoRevertImpersonation`pode ser destruída com nenhum efeito ou reassociar o mesmo ou a outro `CAccessToken` objeto usando [Attach](#attach).  
  
##  <a name="getaccesstoken"></a>CAutoRevertImpersonation::GetAccessToken  
 Recupera o atual token de acesso associado ao objeto.  
  
```
const CAccessToken* GetAccessToken() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do previamente associado [CAccessToken](../../atl/reference/caccesstoken-class.md), ou nulo se nenhuma associação existia.  
  
### <a name="remarks"></a>Comentários  
 Se esse método é chamado para fins que incluem a reversão de uma representação do `CAccessToken` objeto, o [desanexar](#detach) método deve ser usado em vez disso.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de ATLSecurity](../../visual-cpp-samples.md)   
 [Tokens de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

