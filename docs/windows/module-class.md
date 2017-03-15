---
title: "Classe de m&#243;dulo | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Module"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de módulo"
ms.assetid: dd67e3b8-c2e1-4f53-8c0f-565a140ba649
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de m&#243;dulo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma coleção de objetos relacionados.  
  
## Sintaxe  
  
```  
  
template<  
   ModuleType moduleType  
>  
class Module;  
  
template<>  
class Module<InProc> : public Details::ModuleBase;  
  
template<>  
class Module<OutOfProc> : public Module<InProc>;  
```  
  
#### Parâmetros  
 `moduleType`  
 Uma combinação de um ou mais valores de enumeração de [ModuleType](../Topic/ModuleType%20Enumeration.md) .  
  
## Membros  
  
### Classes protegidas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe Module::GenericReleaseNotifier](../windows/module-genericreleasenotifier-class.md)|Invoca um manipulador de eventos quando o objeto a última vez no módulo atual é liberado.  O manipulador de eventos é especificado por em um lambda, em um funtor, ou em uma ponteiro\-à\- função.|  
|[Classe Module::MethodReleaseNotifier](../Topic/Module::MethodReleaseNotifier%20Class.md)|Invoca um manipulador de eventos quando o objeto a última vez no módulo atual é liberado.  O manipulador de eventos é especificado por um objeto e por seu membro de ponteiro\-à\-um\- método.|  
|[Classe Module::ReleaseNotifier](../Topic/Module::ReleaseNotifier%20Class.md)|Invoca um manipulador de eventos quando o objeto mais recente em um módulo é liberado.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Destruidor Module::~Module](../windows/module-tilde-module-destructor.md)|Deinitializes a instância atual da classe do módulo.|  
  
### Construtores Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor Module::Module](../windows/module-module-constructor.md)|Inicializa uma nova instância da classe do módulo.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método Module::Create](../windows/module-create-method.md)|Cria uma instância de um módulo.|  
|[Método Module::DecrementObjectCount](../windows/module-decrementobjectcount-method.md)|Diminui o número de objetos controladas pelo módulo.|  
|[Método Module::GetActivationFactory](../windows/module-getactivationfactory-method.md)|Obtém uma fábrica de ativação do módulo.|  
|[Método Module::GetClassObject](../windows/module-getclassobject-method.md)|Retreives um cache de fábricas da classe.|  
|[Método Module::GetModule](../Topic/Module::GetModule%20Method.md)|Cria uma instância de um módulo.|  
|[Método Module::GetObjectCount](../windows/module-getobjectcount-method.md)|Recupera o número de objetos gerenciados pelo módulo.|  
|[Método Module::IncrementObjectCount](../windows/module-incrementobjectcount-method.md)|Incrementa o número de objetos controladas pelo módulo.|  
|[Método Module::RegisterCOMObject](../windows/module-registercomobject-method.md)|Registra um ou mais objetos COM para que outros aplicativos podem conectar\-se a eles.|  
|[Método Module::RegisterObjects](../windows/module-registerobjects-method.md)|Os registros COM ou [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] objeto para que outros aplicativos podem conectar\-se a eles.|  
|[Método Module::RegisterWinRTObject](../windows/module-registerwinrtobject-method.md)|Registra um ou mais objetos de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] para que outros aplicativos podem conectar\-se a eles.|  
|[Método Module::Terminate](../windows/module-terminate-method.md)|Faz com que todas as fábricas instanciadas pelo módulo para fechar.|  
|[Método Module::UnregisterCOMObject](../Topic/Module::UnregisterCOMObject%20Method.md)|Cancela um ou mais objetos COM, que impede que outros aplicativos conectem\-se a eles.|  
|[Método Module::UnregisterObjects](../windows/module-unregisterobjects-method.md)|Cancela os objetos no módulo especificado de forma que outros aplicativos não podem conectar\-se a eles.|  
|[Método Module::UnregisterWinRTObject](../windows/module-unregisterwinrtobject-method.md)|Cancela um ou mais objetos de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] de forma que outros aplicativos não podem conectar\-se a eles.|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método Module::Create](../windows/module-create-method.md)|Cria uma instância de um módulo.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados Module::objectCount\_](../windows/module-objectcount-data-member.md)|Controla o quantas classes foram criadas com a função de [Faça](../windows/make-function.md) .|  
|[Membro de dados Module::releaseNotifier\_](../windows/module-releasenotifier-data-member.md)|Contém um ponteiro para um objeto de ReleaseNotifier.|  
  
### Macros  
  
|||  
|-|-|  
|[ActivatableClass](../Topic/ActivatableClass%20Macros.md)|Popula um cache interno que contém uma fábrica que possa criar uma instância da classe especificada.  Esta macro especifica parâmetros padrão da ID da fábrica e de grupo.|  
|[ActivatableClassWithFactory](../Topic/ActivatableClass%20Macros.md)|Popula um cache interno que contém uma fábrica que possa criar uma instância da classe especificada.  Esta macro permite especificar um parâmetro específico de fábrica.|  
|[ActivatableClassWithFactoryEx](../Topic/ActivatableClass%20Macros.md)|Popula um cache interno que contém uma fábrica que possa criar uma instância da classe especificada.  Esta macro permite especificar parâmetros específicos da ID da fábrica e de grupo.|  
  
## Hierarquia de Herança  
 `ModuleBase`  
  
 `Module`  
  
 `Module`  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)