---
title: "synchronize | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.synchronize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "synchronize attribute"
ms.assetid: 15fc8544-955d-4765-b3d5-0f619c8b3f40
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# synchronize
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Sincroniza o acesso para o método de destino.  
  
## Sintaxe  
  
```  
  
[synchronize]  
  
```  
  
## Comentários  
 O  **sincronizar** atributo C\+\+ implementa o suporte para o método de destino de um objeto de sincronização.  Sincronização permite que vários objetos usar um recurso comum \(como um método de uma classe\), controlando o acesso do método de destino.  
  
 O código inserido por esse atributo chama adequada `Lock` método \(determinado pelo modelo de threading\) no início do método de destino.  Quando o método é finalizado, `Unlock` é chamado automaticamente.  Para obter mais informações sobre essas funções, consulte  [CComAutoThreadModule::Lock](../Topic/CComAutoThreadModule::Lock.md)  
  
 Este atributo requer que o  [coclass](../windows/coclass.md),  [progid](../Topic/progid.md), ou  [vi\_progid](../windows/vi-progid.md) atributo \(ou outro atributo implica um deles\) também ser aplicadas ao mesmo elemento.  Se qualquer atributo único for usado, as outras duas são aplicadas automaticamente.  Por exemplo, se  **progid** for aplicada,  **vi\_progid** e  **coclass** também são aplicadas.  
  
## Exemplo  
 O código a seguir fornece sincronização para o `UpdateBalance` método da `CMyClass` objeto.  
  
```  
// cpp_attr_ref_synchronize.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module(name="SYNC")];  
  
[coclass,  
 threading(both),  
 vi_progid("MyProject.MyClass"),  
 progid("MyProject.MyClass.1"),  
 uuid("7a7baa0d-59b8-4576-b754-79d07e1d1cc3")  
]  
class CMyClass {  
   float m_nBalance;  
  
   [synchronize]  
   void UpdateBalance(float nAdjust) {  
      m_nBalance += nAdjust;  
   }  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Método de classe, método|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Um ou mais das seguintes opções:  **coclass**,  **progid**, ou  **vi\_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)