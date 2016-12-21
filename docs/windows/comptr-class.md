---
title: "Classe ComPtr | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ComPtr"
ms.assetid: a6551902-6819-478a-8df7-b6f312ab1fb0
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ComPtr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. ComPtr automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.  
  
## Sintaxe  
  
```  
template <  
   typename T  
>  
class ComPtr;  
  
template<  
   class U  
>  
friend class ComPtr;  
```  
  
#### Parâmetros  
 `T`  
 A interface que representa o ComPtr.  
  
 `U`  
 Uma classe à qual o ComPtr atual é um amigo. \(O modelo que usa esse parâmetro é protegido\).  
  
## Comentários  
 ComPtr \<\> declara um tipo que representa o ponteiro de interface subjacente. Use ComPtr \<\> para declarar uma variável e, em seguida, use o operador de acesso de membro de seta \(`->`\) para acessar uma função de membro de interface.  
  
 Para obter mais informações sobre ponteiros inteligentes, consulte a subseção "Ponteiros inteligentes COM" o [COM Coding Practices](http://msdn.microsoft.com/pt-br/76aca556-b4d6-4e67-a2a3-4439900f0c39) tópico na biblioteca MSDN.  
  
## Membros  
  
### Typedefs públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`InterfaceType`|Um sinônimo para o tipo especificado pelo `T` parâmetro do modelo.|  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor ComPtr::ComPtr](../windows/comptr-comptr-constructor.md)|Inicializa uma nova instância da classe ComPtr. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.|  
|[Destruidor ComPtr::~ComPtr](../windows/comptr-tilde-comptr-destructor.md)|Deinitializes uma instância de ComPtr.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ComPtr::As](../windows/comptr-as-method.md)|Retorna um objeto ComPtr que representa a interface identificada pelo parâmetro do modelo especificado.|  
|[Método ComPtr::AsIID](../windows/comptr-asiid-method.md)|Retorna um objeto ComPtr que representa a interface identificada pela ID da interface especificada.|  
|[Método ComPtr::AsWeak](../windows/comptr-asweak-method.md)|Recupera uma referência fraca ao objeto atual.|  
|[Método ComPtr::Attach](../windows/comptr-attach-method.md)|Associa esse ComPtr com o tipo de interface especificado pelo parâmetro de tipo de modelo atual.|  
|[Método ComPtr::CopyTo](../windows/comptr-copyto-method.md)|Copia a interface atual ou especificada associada com esta ComPtr ponteiro de saída especificado.|  
|[Método ComPtr::Detach](../Topic/ComPtr::Detach%20Method.md)|Desassocia esse ComPtr da interface que representa.|  
|[Método ComPtr::Get](../windows/comptr-get-method.md)|Recupera um ponteiro para a interface que está associado este ComPtr.|  
|[Método ComPtr::GetAddressOf](../Topic/ComPtr::GetAddressOf%20Method.md)|Recupera o endereço de [PTR \_](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface representado por este ComPtr.|  
|[Método ComPtr::ReleaseAndGetAddressOf](../windows/comptr-releaseandgetaddressof-method.md)|Libera a interface associada a este ComPtr e, em seguida, recupera o endereço de [PTR \_](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface que foi lançado.|  
|[ComPtr::Reset](../windows/comptr-reset.md)|Libera todas as referências para o ponteiro de interface que está associado este ComPtr.|  
|[Método ComPtr::Swap](../windows/comptr-swap-method.md)|Troca a interface gerenciada pelo ComPtr atual com a interface gerenciada pelo ComPtr especificado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ComPtr::InternalAddRef](../windows/comptr-internaladdref-method.md)|Incrementa a contagem de referência da interface associada a este ComPtr.|  
|[Método ComPtr::InternalRelease](../windows/comptr-internalrelease-method.md)|Executa uma operação de lançamento COM na interface associado a este ComPtr.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ComPtr::operator Microsoft::WRL::Details::BoolType Operador](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md)|Indica se um ComPtr é gerenciar a vida útil do objeto de uma interface.|  
|[Operador ComPtr::operator&](../windows/comptr-operator-ampersand-operator.md)|Recupera o endereço de ComPtr o atual.|  
|[Operador ComPtr::operator\=](../windows/comptr-operator-assign-operator.md)|Atribui um valor para o ComPtr atual.|  
|[Operador ComPtr::operator\-\>](../windows/comptr-operator-arrow-operator.md)|Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.|  
|[Operador ComPtr::operator\=\=](../windows/comptr-operator-equality-operator.md)|Indica se dois objetos ComPtr são iguais.|  
|[Operador ComPtr::operator\!\=](../windows/comptr-operator-inequality-operator.md)|Indica se dois objetos ComPtr não são iguais.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados ComPtr::ptr\_](../windows/comptr-ptr-data-member.md)|Contém um ponteiro para a interface que está associado e gerenciado por este ComPtr.|  
  
## Hierarquia de herança  
 `ComPtr`  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)