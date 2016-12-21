---
title: "Classe FtmBase | Microsoft Docs"
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
  - "ftm/Microsoft::WRL::FtmBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe FtmBase"
ms.assetid: 275f3b71-2975-4f92-89e7-d351e96496df
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe FtmBase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um objeto de rosqueado livre marshaler.  
  
## Sintaxe  
  
```  
  
class FtmBase : public Microsoft::WRL::Implements<  
   Microsoft::WRL::RuntimeClassFlags< WinRtClassicComMix >,   
   Microsoft::WRL::CloakedIid< IMarshal > >;  
```  
  
## Comentários  
 Para obter mais informações, consulte o tópico “IMarshal” “COM interfaces” subtópico de “do tópico de referência COM” na Biblioteca MSDN.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor FtmBase::FtmBase](../windows/ftmbase-ftmbase-constructor.md)|Inicializa uma nova instância da classe de FtmBase.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método FtmBase::CreateGlobalInterfaceTable](../windows/ftmbase-createglobalinterfacetable-method.md)|Cria uma tabela global \(GIT\) da interface.|  
|[Método FtmBase::DisconnectObject](../windows/ftmbase-disconnectobject-method.md)|Libera forçadamente todas as conexões externas a um objeto.  O servidor do objeto chama a implementação do objeto desse método antes de desligar.|  
|[Método FtmBase::GetMarshalSizeMax](../windows/ftmbase-getmarshalsizemax-method.md)|Obter o limite superior no número de bytes necessário para realizar marshaling do ponteiro especificado da interface no objeto especificado.|  
|[Método FtmBase::GetUnmarshalClass](../windows/ftmbase-getunmarshalclass-method.md)|Obtém CLSID que a usa para localizar a DLL que contém código para o proxy correspondente.  Carrega COM este DLL para criar uma instância de não inicializada do proxy.|  
|[Método FtmBase::MarshalInterface](../Topic/FtmBase::MarshalInterface%20Method.md)|Gravações em um fluxo os dados necessários para inicializar um objeto de proxy em algum processo do cliente.|  
|[Método FtmBase::ReleaseMarshalData](../Topic/FtmBase::ReleaseMarshalData%20Method.md)|Destrói um pacote de marshaling de dados.|  
|[Método FtmBase::UnmarshalInterface](../windows/ftmbase-unmarshalinterface-method.md)|Inicializa um proxy padrão e retorna um ponteiro de interface para esse proxy.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados FtmBase::marshaller\_](../windows/ftmbase-marshaller-data-member.md)|Contém uma referência ao rosqueado marshaler livre.|  
  
## Hierarquia de Herança  
 `FtmBase`  
  
## Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)