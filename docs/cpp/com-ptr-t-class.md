---
title: Classe _com_ptr_t
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t
helpviewer_keywords:
- _com_ptr_t class
ms.assetid: 3753a8a0-03d4-4cfd-8a9a-74872ea53971
ms.openlocfilehash: 2c299ea4a5aaabba847c85500a6023d7b112d492
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838497"
---
# <a name="_com_ptr_t-class"></a>Classe _com_ptr_t

**Específico da Microsoft**

Um objeto **_com_ptr_t** encapsula um ponteiro de interface com e é chamado de ponteiro "inteligente". Essa classe de modelo gerencia a alocação de recursos e a desalocação por meio de chamadas de função para as `IUnknown` funções de membro: `QueryInterface` , `AddRef` e `Release` .

Um ponteiro inteligente é geralmente referenciado pela definição typedef fornecida pela macro _COM_SMARTPTR_TYPEDEF. Essa macro usa um nome de interface e o IID e declara uma especialização de **_com_ptr_t** com o nome da interface mais um sufixo de `Ptr` . Por exemplo:

```cpp
_COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));
```

declara a especialização de **_com_ptr_t** `IMyInterfacePtr` .

Um conjunto de [modelos de função](../cpp/relational-function-templates.md), não membros dessa classe de modelo, dá suporte a comparações com um ponteiro inteligente no lado direito do operador de comparação.

### <a name="construction"></a>Construção

| Nome | Descrição |
|-|-|
|[_com_ptr_t](../cpp/com-ptr-t-com-ptr-t.md)|Constrói um objeto **_com_ptr_t** .|

### <a name="low-level-operations"></a>Operações de nível baixo

| Nome | Descrição |
|-|-|
|[AddRef](../cpp/com-ptr-t-addref.md)|Chama a `AddRef` função de membro de `IUnknown` no ponteiro de interface encapsulada.|
|[Attach](../cpp/com-ptr-t-attach.md)|Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.|
|[CreateInstance](../cpp/com-ptr-t-createinstance.md)|Cria uma nova instância de um objeto dado a um `CLSID` ou `ProgID` .|
|[Desanexar](../cpp/com-ptr-t-detach.md)|Extrai e retorna o ponteiro de interface encapsulado.|
|[GetActiveObject](../cpp/com-ptr-t-getactiveobject.md)|Anexa a uma instância existente de um objeto, dado a `CLSID` ou `ProgID` .|
|[GetInterfacePtr](../cpp/com-ptr-t-getinterfaceptr.md)|Retorna o ponteiro de interface encapsulado.|
|[QueryInterface](../cpp/com-ptr-t-queryinterface.md)|Chama a `QueryInterface` função de membro de `IUnknown` no ponteiro de interface encapsulada.|
|[Versão](../cpp/com-ptr-t-release.md)|Chama a `Release` função de membro de `IUnknown` no ponteiro de interface encapsulada.|

### <a name="operators"></a>Operadores

| Nome | Descrição |
|-|-|
|[operador =](../cpp/com-ptr-t-operator-equal.md)|Atribui um novo valor a um objeto de **_com_ptr_t** existente.|
|[operadores = =,! =, \<, > , \<=, >=](../cpp/com-ptr-t-relational-operators.md)|Comparam o objeto de ponteiro inteligente com outro ponteiro inteligente, um ponteiro de interface bruto ou um NULL.|
|[Extratores](../cpp/com-ptr-t-extractors.md)|Extrai o ponteiro de interface COM encapsulado.|

**FINAL específico da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<comip.h>

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte de COM do compilador](../cpp/compiler-com-support-classes.md)
