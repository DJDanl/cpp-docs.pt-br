---
title: classe com_ptr_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t
dev_langs:
- C++
helpviewer_keywords:
- _com_ptr_t class
ms.assetid: 3753a8a0-03d4-4cfd-8a9a-74872ea53971
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb343431a52df9fae32bb17f3303738c04385cf5
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942144"
---
# <a name="comptrt-class"></a>Classe _com_ptr_t
**Seção específica da Microsoft**  
  
 Um objeto `_com_ptr_t` encapsula um ponteiro da interface COM e é chamado de ponteiro “inteligente”. Essa classe de modelo gerencia a alocação de recursos e a desalocação por meio de chamadas de função para o `IUnknown` funções de membro: `QueryInterface`, `AddRef`, e `Release`.  
  
 Um ponteiro inteligente é geralmente referenciado pela definição typedef fornecida pela macro com_smartptr_typedef. Essa macro usa um nome de interface e o IID e declara uma especialização de `_com_ptr_t` com o nome da interface mais um sufixo de `Ptr`. Por exemplo:  
  
```cpp 
_COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));  
```  
  
 declara o `_com_ptr_t` especialização `IMyInterfacePtr`.  
  
 Um conjunto de [modelos de função](../cpp/relational-function-templates.md), não os membros desse modelo de classe, oferece suporte a comparações com um ponteiro inteligente à direita do operador de comparação.  
  
### <a name="construction"></a>Construção  
  
|||  
|-|-|  
|[_com_ptr_t](../cpp/com-ptr-t-com-ptr-t.md)|Constrói um objeto `_com_ptr_t`.|  
  
### <a name="low-level-operations"></a>Operações de nível baixo  
  
|||  
|-|-|  
|[AddRef](../cpp/com-ptr-t-addref.md)|Chamadas a `AddRef` função de membro de `IUnknown` no ponteiro de interface encapsulado.|  
|[Anexar](../cpp/com-ptr-t-attach.md)|Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.|  
|[CreateInstance](../cpp/com-ptr-t-createinstance.md)|Cria uma nova instância de um objeto, considerando um `CLSID` ou `ProgID`.|  
|[Desanexar](../cpp/com-ptr-t-detach.md)|Extrai e retorna o ponteiro de interface encapsulado.|  
|[GetActiveObject](../cpp/com-ptr-t-getactiveobject.md)|Anexa a uma instância existente de um objeto, considerando um `CLSID` ou `ProgID`.|  
|[GetInterfacePtr](../cpp/com-ptr-t-getinterfaceptr.md)|Retorna o ponteiro de interface encapsulado.|  
|[QueryInterface](../cpp/com-ptr-t-queryinterface.md)|Chamadas a `QueryInterface` função de membro de `IUnknown` no ponteiro de interface encapsulado.|  
|[Versão](../cpp/com-ptr-t-release.md)|Chamadas a `Release` função de membro de `IUnknown` no ponteiro de interface encapsulado.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../cpp/com-ptr-t-operator-equal.md)|Atribui um novo valor a um objeto `_com_ptr_t` existente.|  
|[operadores = =,! =, \<, >, \<=, > =](../cpp/com-ptr-t-relational-operators.md)|Comparar o objeto de ponteiro inteligente com outro ponteiro inteligente, o ponteiro de interface bruto ou NULL.|  
|[Extratores](../cpp/com-ptr-t-extractors.md)|Extrai o ponteiro de interface COM encapsulado.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<comip. h >  
  
 **Lib:** comsuppw. lib ou comsuppwd (consulte [/ZC: wchar_t (wchar_t Is Native Type)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)