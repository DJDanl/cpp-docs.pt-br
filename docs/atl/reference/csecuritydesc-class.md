---
title: "Classe de CSecurityDesc | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL::CSecurityDesc"
  - "ATL.CSecurityDesc"
  - "CSecurityDesc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSecurityDesc"
ms.assetid: 3767a327-378f-4690-ba40-4d9f6a1f5ee4
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSecurityDesc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para a estrutura de **SECURITY\_DESCRIPTOR** .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CSecurityDesc  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSecurityDesc::CSecurityDesc](../Topic/CSecurityDesc::CSecurityDesc.md)|o construtor.|  
|[CSecurityDesc::~CSecurityDesc](../Topic/CSecurityDesc::~CSecurityDesc.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSecurityDesc::FromString](../Topic/CSecurityDesc::FromString.md)|Converte um descritor de segurança cadeia de caracteres de formato em um descritor de segurança válido, funcional.|  
|[CSecurityDesc::GetControl](../Topic/CSecurityDesc::GetControl.md)|Recupera informações de controle de descritor de segurança.|  
|[CSecurityDesc::GetDacl](../Topic/CSecurityDesc::GetDacl.md)|Recupera informações de \(DACL\) da lista de controle de acesso discricionário de descritor de segurança.|  
|[CSecurityDesc::GetGroup](../Topic/CSecurityDesc::GetGroup.md)|Recupera informações principal do grupo de descritor de segurança.|  
|[CSecurityDesc::GetOwner](../Topic/CSecurityDesc::GetOwner.md)|Recupera o informaton do proprietário de descritor de segurança.|  
|[CSecurityDesc::GetPSECURITY\_DESCRIPTOR](../Topic/CSecurityDesc::GetPSECURITY_DESCRIPTOR.md)|Retorna um ponteiro para a estrutura de **SECURITY\_DESCRIPTOR** .|  
|[CSecurityDesc::GetSacl](../Topic/CSecurityDesc::GetSacl.md)|Recupera informações de \(SACL\) da lista de controle de acesso do sistema de descritor de segurança.|  
|[CSecurityDesc::IsDaclAutoInherited](../Topic/CSecurityDesc::IsDaclAutoInherited.md)|Determina se DACL é configurado para oferecer suporte a propagação automático.|  
|[CSecurityDesc::IsDaclDefaulted](../Topic/CSecurityDesc::IsDaclDefaulted.md)|Determina se o descritor de segurança é configurado com DACL padrão.|  
|[CSecurityDesc::IsDaclPresent](../Topic/CSecurityDesc::IsDaclPresent.md)|Determina se o descritor de segurança contém DACL.|  
|[CSecurityDesc::IsDaclProtected](../Topic/CSecurityDesc::IsDaclProtected.md)|Determina se DACL é configurado para evitar alterações.|  
|[CSecurityDesc::IsGroupDefaulted](../Topic/CSecurityDesc::IsGroupDefaulted.md)|Determina se o identificador de segurança \(SID\) do grupo de descritor de segurança foi definido por padrão.|  
|[CSecurityDesc::IsOwnerDefaulted](../Topic/CSecurityDesc::IsOwnerDefaulted.md)|Determina se o proprietário SID de descritor de segurança foi definido por padrão.|  
|[CSecurityDesc::IsSaclAutoInherited](../Topic/CSecurityDesc::IsSaclAutoInherited.md)|Determina se o SACL é configurado para oferecer suporte a propagação automático.|  
|[CSecurityDesc::IsSaclDefaulted](../Topic/CSecurityDesc::IsSaclDefaulted.md)|Determina se o descritor de segurança é configurado com uma opção SACL.|  
|[CSecurityDesc::IsSaclPresent](../Topic/CSecurityDesc::IsSaclPresent.md)|Determina se o descritor de segurança contém um SACL.|  
|[CSecurityDesc::IsSaclProtected](../Topic/CSecurityDesc::IsSaclProtected.md)|Determina se o SACL é configurado para evitar alterações.|  
|[CSecurityDesc::IsSelfRelative](../Topic/CSecurityDesc::IsSelfRelative.md)|Determina se o descritor de segurança está no formato do são relativos.|  
|[CSecurityDesc::MakeAbsolute](../Topic/CSecurityDesc::MakeAbsolute.md)|Chamar esse método para converter o descritor de segurança para o formato absoluto.|  
|[CSecurityDesc::MakeSelfRelative](../Topic/CSecurityDesc::MakeSelfRelative.md)|Chamar esse método para converter o descritor de segurança em formato de são relativos.|  
|[CSecurityDesc::SetControl](../Topic/CSecurityDesc::SetControl.md)|Define os bits de controle de um descritor de segurança.|  
|[CSecurityDesc::SetDacl](../Topic/CSecurityDesc::SetDacl.md)|Define informações em DACL.  Se DACL já está presente no descritor de segurança, ele será substituído.|  
|[CSecurityDesc::SetGroup](../Topic/CSecurityDesc::SetGroup.md)|Define informações principal do grupo de um descritor de segurança absoluto de formato, substituindo todos presentes primária de informações do grupo já.|  
|[CSecurityDesc::SetOwner](../Topic/CSecurityDesc::SetOwner.md)|Define informações do proprietário de um descritor de segurança absoluto de formato, substituindo todos presentes de informações do proprietário mais.|  
|[CSecurityDesc::SetSacl](../Topic/CSecurityDesc::SetSacl.md)|Define informações em um SACL.  Se um SACL já está presente no descritor de segurança, ele será substituído.|  
|[CSecurityDesc::ToString](../Topic/CSecurityDesc::ToString.md)|Converte um descritor de segurança em um formato de cadeia de caracteres.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Const SECURITY\_DESCRIPTOR de CSecurityDesc::operator \*](../Topic/CSecurityDesc::operator%20const%20SECURITY_DESCRIPTOR%20*.md)|Retorna um ponteiro para a estrutura de **SECURITY\_DESCRIPTOR** .|  
|[CSecurityDesc::operator \=](../Topic/CSecurityDesc::operator%20=.md)|Operador de atribuição.|  
  
## Comentários  
 A estrutura de **SECURITY\_DESCRIPTOR** contém informações de segurança associada a um objeto.  Os aplicativos usam essa estrutura para definir e consultar o status de segurança de um objeto.  Consulte também [AtlGetSecurityDescriptor](../Topic/AtlGetSecurityDescriptor.md).  
  
 Aplicativos não devem alterar a estrutura de **SECURITY\_DESCRIPTOR** diretamente, e vez devem usar os métodos da classe fornecidos.  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [Exemplo de segurança](../../top/visual-cpp-samples.md)   
 [SECURITY\_DESCRIPTOR](http://msdn.microsoft.com/library/windows/desktop/aa379561)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Funções de segurança globais](../../atl/reference/security-global-functions.md)