---
title: "Classe de COleObjectFactory | Microsoft Docs"
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
  - "COleObjectFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "fábricas de classe, Classe de COleObjectFactory"
  - "Classe de COleObjectFactory"
  - "criação do objeto, objetos OLE"
  - "objetos [C++], criando OLE"
  - "Fábrica OLE de classe"
  - "objetos OLE"
  - "objetos OLE, criando"
  - "O OLE, fábrica de classe"
ms.assetid: ab179c1e-4af2-44aa-a576-37c48149b427
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleObjectFactory
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a fábrica OLE da classe, que cria objetos VELHOS como servidores, objetos de automação, e documentos.  
  
## Sintaxe  
  
```  
class COleObjectFactory : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleObjectFactory::COleObjectFactory](../Topic/COleObjectFactory::COleObjectFactory.md)|Constrói um objeto de `COleObjectFactory` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleObjectFactory::GetClassID](../Topic/COleObjectFactory::GetClassID.md)|Retorna o OLE identificação de classe de objetos que essa fábrica cria.|  
|[COleObjectFactory::IsLicenseValid](../Topic/COleObjectFactory::IsLicenseValid.md)|Determina se a licença do controle é válido.|  
|[COleObjectFactory::IsRegistered](../Topic/COleObjectFactory::IsRegistered.md)|Indica se o factory do objeto é registrada com as dlls VELHOS do sistema.|  
|[COleObjectFactory::Register](../Topic/COleObjectFactory::Register.md)|Registra esta fábrica de objeto com as dlls VELHOS do sistema.|  
|[COleObjectFactory::RegisterAll](../Topic/COleObjectFactory::RegisterAll.md)|Registra fábricas do objeto de qualquer aplicativo com dlls VELHOS do sistema.|  
|[COleObjectFactory::Revoke](../Topic/COleObjectFactory::Revoke.md)|Revoga o registro da fábrica de objeto com as dlls VELHOS do sistema.|  
|[COleObjectFactory::RevokeAll](../Topic/COleObjectFactory::RevokeAll.md)|Revoga os registros de fábricas de objeto de um aplicativo com dlls VELHOS do sistema.|  
|[COleObjectFactory::UnregisterAll](../Topic/COleObjectFactory::UnregisterAll.md)|Desregistre todos de fábricas de objeto de um aplicativo.|  
|[COleObjectFactory::UpdateRegistry](../Topic/COleObjectFactory::UpdateRegistry.md)|Registra esta fábrica de objeto com o Registro do sistema OLE.|  
|[COleObjectFactory::UpdateRegistryAll](../Topic/COleObjectFactory::UpdateRegistryAll.md)|Registra fábricas do objeto de qualquer aplicativo com o Registro do sistema OLE.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleObjectFactory::GetLicenseKey](../Topic/COleObjectFactory::GetLicenseKey.md)|Solicita uma chave exclusiva de DLL do controle.|  
|[COleObjectFactory::OnCreateObject](../Topic/COleObjectFactory::OnCreateObject.md)|Chamado pela estrutura para criar um novo objeto do tipo da fábrica.|  
|[COleObjectFactory::VerifyLicenseKey](../Topic/COleObjectFactory::VerifyLicenseKey.md)|Verifica que a chave inserida no controle corresponde a chave inserida no recipiente.|  
|[COleObjectFactory::VerifyUserLicense](../Topic/COleObjectFactory::VerifyUserLicense.md)|Verifica que o controle é licenciado para uso em tempo de design.|  
  
## Comentários  
 a classe de `COleObjectFactory` tem funções de membro para executar as seguintes funções:  
  
-   Gerenciando o registro de objetos.  
  
-   Atualizando o OLE registro do sistema, bem como o registro de tempo de execução que informa o OLE que objetos estão em execução e prontos para receber mensagens.  
  
-   Impõe licenciamento limitando o uso do controle para desenvolvedores licenciadas em tempo de design e para aplicativos licenciadas em tempo de execução.  
  
-   Registrando fábricas de objeto de controle com o Registro do sistema OLE.  
  
 Para obter mais informações sobre a criação do objeto, consulte os artigos [Objetos de dados e fontes de dados \(OLE\)](../../mfc/data-objects-and-data-sources-ole.md) e [objetos de dados e fontes de dados: Criação e destruindo](../../mfc/data-objects-and-data-sources-creation-and-destruction.md).  Para obter mais informações sobre o registro, consulte o artigo [registro](../../mfc/registration.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `COleObjectFactory`  
  
## Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)