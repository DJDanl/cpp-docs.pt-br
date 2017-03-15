---
title: "Classe WeakRef | Microsoft Docs"
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
  - "client/Microsoft::WRL::WeakRef"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe WeakRef"
ms.assetid: 572be703-c641-496c-8af5-ad6164670ba1
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe WeakRef
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma *referência fraca* que podem ser usadas por apenas o Windows Runtime, com não clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.  
  
## Sintaxe  
  
```  
class WeakRef : public ComPtr<IWeakReference>  
```  
  
## Comentários  
 Um objeto WeakRef mantém um *referência forte*, que é associado um objeto e pode ser válido ou é inválido. Chame o método As\(\) ou AsIID\(\) para obter uma referência forte. Quando a referência forte é válida, ele pode acessar o objeto associado. Quando a referência forte é inválida \(`nullptr`\), o objeto associado está inacessível.  
  
 Um objeto WeakRef normalmente é usado para representar um objeto cuja existência é controlada por um thread externo ou um aplicativo. Por exemplo, construa um objeto de WeakRef de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas se o arquivo é fechado, a referência forte se torna inválida.  
  
 Observe que há uma alteração de comportamento na [como](../windows/weakref-as-method.md), [AsIID](../windows/weakref-asiid-method.md) e [CopyTo](../windows/weakref-copyto-method.md) métodos no SDK Windows 10. Anteriormente, depois de chamar qualquer um desses métodos, você pode verificar o WeakRef para `nullptr` para determinar se uma referência forte foi obtida de com êxito, como no seguinte código:  
  
```cpp  
WeakRef wr;  
strongComptrRef.AsWeak(&wr);  
  
// Now suppose that the object strongComPtrRef points to no longer exists  
// and the following code tries to get a strong ref from the weak ref:  
ComPtr<ISomeInterface> strongRef;  
HRESULT hr = wr.As(&strongRef);  
  
// This check won't work with the Windows 10 SDK version of the library.  
// Check the input pointer instead.  
if(wr == nullptr)  
{  
    wprintf(L"Couldn’t get strong ref!");  
}  
  
```  
  
 O código acima não funcionam ao usar o SDK do Windows 10 \(ou posterior\). Em vez disso, verifique o ponteiro foi passado para `nullptr`.  
  
```cpp  
if (strongRef == nullptr)  
{  
    wprintf(L"Couldn't get strong ref!");  
 }  
  
```  
  
## Membros  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor WeakRef::WeakRef](../windows/weakref-weakref-constructor.md)|Inicializa uma nova instância da classe WeakRef.|  
|[Destruidor WeakRef::~WeakRef](../windows/weakref-tilde-weakref-destructor.md)|Deinitializes a instância atual da classe WeakRef.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método WeakRef::As](../windows/weakref-as-method.md)|Define o parâmetro de ponteiro ComPtr especificado para representar a interface especificada.|  
|[Método WeakRef::AsIID](../windows/weakref-asiid-method.md)|Define o parâmetro de ponteiro ComPtr especificado para representar a ID da interface especificada.|  
|[Método WeakRef::CopyTo](../windows/weakref-copyto-method.md)|Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador WeakRef::operator&](../Topic/WeakRef::operator&%20Operator.md)|Retorna um objeto ComPtrRef que representa o objeto WeakRef atual.|  
  
## Hierarquia de herança  
 `ComPtr`  
  
 `WeakRef`  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)