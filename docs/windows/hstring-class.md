---
title: "Classe HString | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HString"
dev_langs: 
  - "C++"
ms.assetid: 6709dd2e-8d72-4675-8ec7-1baa7d71854d
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe HString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece suporte para manipular identificadores de HSTRING.  
  
## Sintaxe  
  
```cpp  
class HString;  
```  
  
## Comentários  
 O [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] fornece acesso às cadeias de caracteres através das alças HSTRING.  A classe de HString fornece funções e operadores de conveniência para simplificar usando as alças de HSTRING.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor HString::HString](../windows/hstring-hstring-constructor.md)|Inicializa uma nova instância da classe HString.|  
|[Destruidor HString::~HString](../windows/hstring-tilde-hstring-destructor.md)|Destrói a instância atual da classe HString.|  
  
### Membros  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método HString::Set](../Topic/HString::Set%20Method.md)|Defina o valor do objeto atual de HString para a cadeia de caracteres largos ou parâmetro HString especificado.|  
|[Método HString::Attach](../windows/hstring-attach-method.md)|Associa o objeto especificado HString ao objeto HString atual.|  
|[Método HString::CopyTo](../windows/hstring-copyto-method.md)|Copia o objeto HString atual para um objeto HSTRING.|  
|[Método HString::Detach](../Topic/HString::Detach%20Method.md)|Dissocia o objeto HString especificado do valor subjacente.|  
|[Método HString::GetAddressOf](../windows/hstring-getaddressof-method.md)|Recupera um ponteiro para o identificador subjacente de HSTRING.|  
|[Método HString::Get](../Topic/HString::Get%20Method.md)|Recupera o valor do identificador subjacente de HSTRING.|  
|[Método HString::Release](../windows/hstring-release-method.md)|Exclui o valor da cadeia de caracteres subjacente e inicializa o objeto atual HString para um valor vazio.|  
|[Método HString::MakeReference](../Topic/HString::MakeReference%20Method.md)|Cria um objeto de HStringReference de um parâmetro especificado de cadeia de caracteres.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador HString::Operator\=](../Topic/HString::Operator=%20Operator.md)|Move o valor de outro objeto HString para o objeto HString atual.|  
|[Operador HString::Operator\=\=](../windows/hstring-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|  
|[Operador HString::Operator\!\=](../windows/hstring-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|  
  
## Hierarquia de Herança  
 `HString`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../Topic/Microsoft::WRL::Wrappers%20Namespace.md)