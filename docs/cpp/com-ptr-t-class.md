---
title: "Classe _com_ptr_t | Microsoft Docs"
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
  - "_com_ptr_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe _com_ptr_t"
ms.assetid: 3753a8a0-03d4-4cfd-8a9a-74872ea53971
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe _com_ptr_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Um objeto `_com_ptr_t` encapsula um ponteiro da interface COM e é chamado de ponteiro “inteligente”.  Essa classe de modelo gerencia a alocação e desalocação de recursos por meio de chamadas de função para funções de membro **IUnknown**: `QueryInterface`, `AddRef` e **Release**.  
  
 Um ponteiro inteligente é geralmente referenciado pela definição typedef fornecida pela macro **\_COM\_SMARTPTR\_TYPEDEF**.  Essa macro usa um nome de interface e o IID e declara uma especialização de `_com_ptr_t` com o nome da interface mais um sufixo de `Ptr`.  Por exemplo:  
  
```  
_COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));  
```  
  
 declara a especialização `_com_ptr_t` **IMyInterfacePtr**.  
  
 Um conjunto de [modelos de função](../cpp/relational-function-templates.md), não membros dessa classe de modelo, oferece suporte a comparações com um ponteiro inteligente à direita do operador de comparação.  
  
### Construção  
  
|||  
|-|-|  
|[\_com\_ptr\_t](../cpp/com-ptr-t-com-ptr-t.md)|Constrói um objeto `_com_ptr_t`.|  
  
### Operações de nível baixo  
  
|||  
|-|-|  
|[AddRef](../cpp/com-ptr-t-addref.md)|Chama a função de membro `AddRef` de **IUnknown** no ponteiro de interface encapsulado.|  
|[Attach](../Topic/_com_ptr_t::Attach.md)|Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.|  
|[CreateInstance](../cpp/com-ptr-t-createinstance.md)|Cria uma nova instância de um objeto dado um **CLSID** ou **ProgID**.|  
|[Detach](../cpp/com-ptr-t-detach.md)|Extrai e retorna o ponteiro de interface encapsulado.|  
|[GetActiveObject](../Topic/_com_ptr_t::GetActiveObject.md)|Anexa a uma instância existente de um objeto dado o **CLSID** ou **ProgID**.|  
|[GetInterfacePtr](../cpp/com-ptr-t-getinterfaceptr.md)|Retorna o ponteiro de interface encapsulado.|  
|[QueryInterface](../cpp/com-ptr-t-queryinterface.md)|Chama a função de membro `QueryInterface` de **IUnknown** no ponteiro de interface encapsulado.|  
|[Release](../cpp/com-ptr-t-release.md)|Chama a função de membro **Release** de **IUnknown** no ponteiro de interface encapsulado.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../cpp/com-ptr-t-operator-equal.md)|Atribui um novo valor a um objeto `_com_ptr_t` existente.|  
|[operadores \=\=, \!\=, \<, \>, \<\=, \>\=](../cpp/com-ptr-t-relational-operators.md)|Comparam o objeto de ponteiro inteligente com outro ponteiro inteligente, um ponteiro de interface bruto ou um **NULL**.|  
|[Extratores](../cpp/com-ptr-t-extractors.md)|Extrai o ponteiro de interface COM encapsulado.|  
  
## FIM de Específico da Microsoft  
  
## Requisitos  
 **Cabeçalho:** comip.h  
  
 **Bib:** comsuppw.lib ou comsuppwd.lib \(consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações\)  
  
## Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)