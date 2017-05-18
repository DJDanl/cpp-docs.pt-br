---
title: Classe CSecurityAttributes | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes::CSecurityAttributes
- ATLSECURITY/ATL::CSecurityAttributes::Set
dev_langs:
- C++
helpviewer_keywords:
- CSecurityAttributes class
ms.assetid: a094880c-52e1-4a28-97ff-752d5869908e
caps.latest.revision: 24
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 24dfba8b6125172cc2d4ff7a32b61da412bfe2be
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csecurityattributes-class"></a>Classe CSecurityAttributes
Essa classe é um wrapper estreito para a estrutura de atributos de segurança.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CSecurityAttributes : public SECURITY_ATTRIBUTES
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSecurityAttributes::CSecurityAttributes](#csecurityattributes)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSecurityAttributes::Set](#set)|Chame esse método para definir os atributos do `CSecurityAttributes` objeto.|  
  
## <a name="remarks"></a>Comentários  
 O **SECURITY_ATTRIBUTES** estrutura contém um [descritor de segurança](http://msdn.microsoft.com/library/windows/desktop/aa379561) usada para a criação de um objeto e especifica se o identificador recuperado especificando essa estrutura é herdável.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SECURITY_ATTRIBUTES`  
  
 `CSecurityAttributes`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="csecurityattributes"></a>CSecurityAttributes::CSecurityAttributes  
 O construtor.  
  
```
CSecurityAttributes() throw();
explicit CSecurityAttributes(const CSecurityDesc& rSecurityDescriptor, bool bInheritsHandle = false) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSecurityDescriptor`  
 Referência a um descritor de segurança.  
  
 `bInheritsHandle`  
 Especifica se o identificador retornado é herdado quando um novo processo é criado. Se esse membro for true, o novo processo herda o identificador.  
  
##  <a name="set"></a>CSecurityAttributes::Set  
 Chame esse método para definir os atributos do `CSecurityAttributes` objeto.  
  
```
void Set(const CSecurityDesc& rSecurityDescriptor, bool bInheritHandle = false) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSecurityDescriptor`  
 Referência a um descritor de segurança.  
  
 `bInheritHandle`  
 Especifica se o identificador retornado é herdado quando um novo processo é criado. Se esse membro for true, o novo processo herda o identificador.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado pelo construtor para inicializar o `CSecurityAttributes` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de segurança](../../visual-cpp-samples.md)   
 [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560)   
 [descritor de segurança](http://msdn.microsoft.com/library/windows/desktop/aa379561)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Funções globais de segurança](../../atl/reference/security-global-functions.md)

