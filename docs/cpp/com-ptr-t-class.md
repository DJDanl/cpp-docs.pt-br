---
title: classe com_ptr_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t
dev_langs:
- C++
helpviewer_keywords:
- _com_ptr_t class
ms.assetid: 3753a8a0-03d4-4cfd-8a9a-74872ea53971
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 3979a33f095092c5cbaac91793c501e31304a6d4
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comptrt-class"></a>Classe _com_ptr_t
**Seção específica da Microsoft**  
  
 Um objeto `_com_ptr_t` encapsula um ponteiro da interface COM e é chamado de ponteiro “inteligente”. Essa classe de modelo gerencia a alocação e desalocação por meio de chamadas de função para o **IUnknown** funções de membro: `QueryInterface`, `AddRef`, e **versão**.  
  
 Um ponteiro inteligente geralmente é referenciado pela definição de typedef fornecida pelo **_COM_SMARTPTR_TYPEDEF** macro. Essa macro usa um nome de interface e o IID e declara uma especialização de `_com_ptr_t` com o nome da interface mais um sufixo de `Ptr`. Por exemplo:  
  
```  
_COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));  
```  
  
 declara o `_com_ptr_t` especialização **IMyInterfacePtr**.  
  
 Um conjunto de [modelos de função](../cpp/relational-function-templates.md), não os membros do modelo de classe, suporte a comparações com um ponteiro inteligente à direita do operador de comparação.  
  
### <a name="construction"></a>Construção  
  
|||  
|-|-|  
|[com_ptr_t](../cpp/com-ptr-t-com-ptr-t.md)|Constrói um objeto `_com_ptr_t`.|  
  
### <a name="low-level-operations"></a>Operações de nível baixo  
  
|||  
|-|-|  
|[AddRef](../cpp/com-ptr-t-addref.md)|Chamadas de `AddRef` função membro de **IUnknown** no ponteiro de interface encapsulado.|  
|[Anexar](../cpp/com-ptr-t-attach.md)|Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.|  
|[CreateInstance](../cpp/com-ptr-t-createinstance.md)|Cria uma nova instância de um objeto, considerando um **CLSID** ou **ProgID**.|  
|[Desanexar](../cpp/com-ptr-t-detach.md)|Extrai e retorna o ponteiro de interface encapsulado.|  
|[GetActiveObject](../cpp/com-ptr-t-getactiveobject.md)|Anexa a uma instância existente de um objeto, considerando um **CLSID** ou **ProgID**.|  
|[GetInterfacePtr](../cpp/com-ptr-t-getinterfaceptr.md)|Retorna o ponteiro de interface encapsulado.|  
|[QueryInterface](../cpp/com-ptr-t-queryinterface.md)|Chamadas de `QueryInterface` função membro de **IUnknown** no ponteiro de interface encapsulado.|  
|[Versão](../cpp/com-ptr-t-release.md)|Chamadas de **versão** função membro de **IUnknown** no ponteiro de interface encapsulado.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../cpp/com-ptr-t-operator-equal.md)|Atribui um novo valor a um objeto `_com_ptr_t` existente.|  
|[operadores = =,! =, \<, >, \<=, > =](../cpp/com-ptr-t-relational-operators.md)|Compare o objeto de ponteiro inteligente para outro ponteiro inteligente, o ponteiro de interface bruto, ou **nulo**.|  
|[Extratores](../cpp/com-ptr-t-extractors.md)|Extrai o ponteiro de interface COM encapsulado.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** comip.h  
  
 **Lib:** comsuppw.lib ou comsuppwd.lib (consulte [/ZC: (wchar_t é do tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)
