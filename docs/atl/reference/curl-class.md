---
title: "Classe de som tipo wave | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CUrl"
  - "CUrl"
  - "ATL::CUrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de som tipo wave"
ms.assetid: b3894d34-47b9-4961-9719-4197153793da
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de som tipo wave
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa uma URL.  Permite que você manipule cada elemento de URL independentemente de se outro analisando uma cadeia de caracteres existente de URL ou de uma cadeia de caracteres a partir do zero.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CUrl  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CUrl::CUrl](../Topic/CUrl::CUrl.md)|o construtor.|  
|[CUrl::~CUrl](../Topic/CUrl::~CUrl.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CUrl::Canonicalize](../Topic/CUrl::Canonicalize.md)|Chamar esse método para converter uma cadeia de caracteres da URL à forma canônica.|  
|[CUrl::Clear](../Topic/CUrl::Clear.md)|Chamar esse método para limpar todos os campos de URL.|  
|[CUrl::CrackUrl](../Topic/CUrl::CrackUrl.md)|Chamar esse método para decodificar e analisar a URL.|  
|[CUrl::CreateUrl](../Topic/CUrl::CreateUrl.md)|Chamar esse método para criar o URL.|  
|[CUrl::GetExtraInfo](../Topic/CUrl::GetExtraInfo.md)|Chamar esse método para obter informações extras \(como ?*texto* ou \#*text*\) de URL.\)|  
|[CUrl::GetExtraInfoLength](../Topic/CUrl::GetExtraInfoLength.md)|Chamar esse método para obter o comprimento de informações extras \(como ?*texto* ou \#*text*\) para recuperar URL.|  
|[CUrl::GetHostName](../Topic/CUrl::GetHostName.md)|Chamar esse método para obter o nome de host de URL.|  
|[CUrl::GetHostNameLength](../Topic/CUrl::GetHostNameLength.md)|Chamar esse método para obter o comprimento do nome de host.|  
|[CUrl::GetPassword](../Topic/CUrl::GetPassword.md)|Chamar esse método para obter a senha da URL.|  
|[CUrl::GetPasswordLength](../Topic/CUrl::GetPasswordLength.md)|Chamar esse método para obter o comprimento da senha.|  
|[CUrl::GetPortNumber](../Topic/CUrl::GetPortNumber.md)|Chamar esse método para obter o número da porta em termos de ATL\_URL\_PORT.|  
|[CUrl::GetScheme](../Topic/CUrl::GetScheme.md)|Chamar esse método para obter o esquema de URL.|  
|[CUrl::GetSchemeName](../Topic/CUrl::GetSchemeName.md)|Chamar esse método para obter o nome do esquema de URL.|  
|[CUrl::GetSchemeNameLength](../Topic/CUrl::GetSchemeNameLength.md)|Chamar esse método para obter o comprimento do nome do esquema de URL.|  
|[CUrl::GetUrlLength](../Topic/CUrl::GetUrlLength.md)|Chamar esse método para obter o comprimento da URL.|  
|[CUrl::GetUrlPath](../Topic/CUrl::GetUrlPath.md)|Chamar esse método para obter o caminho URL.|  
|[CUrl::GetUrlPathLength](../Topic/CUrl::GetUrlPathLength.md)|Chamar esse método para obter o comprimento do caminho URL.|  
|[CUrl::GetUserName](../Topic/CUrl::GetUserName.md)|Chamar esse método para obter o nome de usuário da URL.|  
|[CUrl::GetUserNameLength](../Topic/CUrl::GetUserNameLength.md)|Chamar esse método para obter o comprimento do nome de usuário.|  
|[CUrl::SetExtraInfo](../Topic/CUrl::SetExtraInfo.md)|Chamar esse método para definir informações extras \(como ?*texto* ou \#*text*\) de URL.\)|  
|[CUrl::SetHostName](../Topic/CUrl::SetHostName.md)|Chamar esse método para definir o nome de host.|  
|[CUrl::SetPassword](../Topic/CUrl::SetPassword.md)|Chamar esse método para definir a senha.|  
|[CUrl::SetPortNumber](../Topic/CUrl::SetPortNumber.md)|Chamar esse método para definir o número da porta em termos de ATL\_URL\_PORT.|  
|[CUrl::SetScheme](../Topic/CUrl::SetScheme.md)|Chamar esse método para definir o esquema de URL.|  
|[CUrl::SetSchemeName](../Topic/CUrl::SetSchemeName.md)|Chamar esse método para definir o nome do esquema de URL.|  
|[CUrl::SetUrlPath](../Topic/CUrl::SetUrlPath.md)|Chamar esse método para definir o caminho do URL.|  
|[CUrl::SetUserName](../Topic/CUrl::SetUserName.md)|Chamar esse método para definir o nome de usuário.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CUrl::operator \=](../Topic/CUrl::operator%20=.md)|Atribua o objeto especificado de `CUrl` ao objeto atual de `CUrl` .|  
  
## Comentários  
 `CUrl` permite que você manipule os campos de uma URL, como o caminho ou número de porta.  `CUrl` entende URL da seguinte forma:  
  
 \<Scheme\>: \/\<UserName\>:\<Password\>@\<HostName\>:\<PortNumber\>\/\<UrlPath\>\<ExtraInfo\>  
  
 \(Alguns campos são opcionais.\) Por exemplo, considere este URL:  
  
 http:\/\/someone:secret@www.microsoft.com:80\/visualc\/stuff.htm\#contents  
  
 [CUrl::CrackUrl](../Topic/CUrl::CrackUrl.md) analisa\-o da seguinte maneira:  
  
-   Esquema: “http” ou [ATL\_URL\_SCHEME\_HTTP](../Topic/ATL_URL_SCHEME.md)  
  
-   Nome do Usuário: “someone”  
  
-   Senha: “confidencialidade”  
  
-   Hostname: “www.microsoft.com”  
  
-   PortNumber: 80  
  
-   UrlPath: “visualc\/stuff.htm”  
  
-   ExtraInfo: “\#contents”  
  
 Para manipular o campo de UrlPath \(por exemplo\), você usaria [GetUrlPath](../Topic/CUrl::GetUrlPath.md), [GetUrlPathLength](../Topic/CUrl::GetUrlPathLength.md), e [SetUrlPath](../Topic/CUrl::SetUrlPath.md).  Você usaria [CreateUrl](../Topic/CUrl::CreateUrl.md) para criar a cadeia de caracteres completa de URL.  
  
## Requisitos  
 **Cabeçalho:** atlutil.h  
  
## Consulte também  
 [Classes](../../atl/reference/atl-classes.md)