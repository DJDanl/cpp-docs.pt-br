---
title: "Classe HStringReference | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HStringReference"
dev_langs: 
  - "C++"
ms.assetid: 9bf823b1-17eb-4ac4-8c5d-27d27c7a4150
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe HStringReference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um HSTRING que é criada a partir de uma cadeia de caracteres existente.  
  
## Sintaxe  
  
```cpp  
class HStringReference;  
```  
  
## Comentários  
 O tempo de vida do buffer de respaldo no novo HSTRING não é gerenciado pelo [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  O chamador alocar uma cadeia de caracteres de origem no quadro de pilha para evitar uma alocação da heap e eliminar o risco de um vazamento de memória.  Além disso, o chamador deve garantir que a cadeia de caracteres de origem permaneça inalterada durante o tempo de vida do HSTRING anexado.  Para obter mais informações, consulte [WindowsCreateStringReference function](http://msdn.microsoft.com/pt-br/0361bb7e-da49-4289-a93e-de7aab8712ac).  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor HStringReference::HStringReference](../windows/hstringreference-hstringreference-constructor.md)|Inicializa uma nova instância da classe HStringReference.|  
  
### Membros  
  
|Membro|Descrição|  
|------------|---------------|  
|[Método HStringReference::CopyTo](../windows/hstringreference-copyto-method.md)|Copia o objeto HStringReference atual para um objeto HSTRING.|  
|[Método HStringReference::Get](../windows/hstringreference-get-method.md)|Recupera o valor do identificador subjacente de HSTRING.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador HStringReference::Operator\=](../windows/hstringreference-operator-assign-operator.md)|Move o valor de outro objeto HStringReference para o objeto HStringReference atual.|  
|[Operador HStringReference::Operator\=\=](../windows/hstringreference-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|  
|[Operador HStringReference::Operator\!\=](../windows/hstringreference-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|  
  
## Hierarquia de Herança  
 `HStringReference`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../Topic/Microsoft::WRL::Wrappers%20Namespace.md)