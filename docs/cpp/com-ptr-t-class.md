---
title: Classe _com_ptr_t
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t
helpviewer_keywords:
- _com_ptr_t class
ms.assetid: 3753a8a0-03d4-4cfd-8a9a-74872ea53971
ms.openlocfilehash: eeaab22ded537cbbb211a79596b8383251af3ab7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189892"
---
# <a name="_com_ptr_t-class"></a>Classe _com_ptr_t

**Seção específica da Microsoft**

Um objeto **_com_ptr_t** encapsula um ponteiro de interface com e é chamado de ponteiro "inteligente". Essa classe de modelo gerencia a alocação de recursos e a desalocação por meio de chamadas de função para as funções membro `IUnknown`: `QueryInterface`, `AddRef`e `Release`.

Um ponteiro inteligente é geralmente referenciado pela definição typedef fornecida pela macro _COM_SMARTPTR_TYPEDEF. Essa macro usa um nome de interface e o IID e declara uma especialização de **_com_ptr_t** com o nome da interface mais um sufixo de `Ptr`. Por exemplo:

```cpp
_COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));
```

declara o `IMyInterfacePtr`de especialização de **_com_ptr_t** .

Um conjunto de [modelos de função](../cpp/relational-function-templates.md), não membros dessa classe de modelo, dá suporte a comparações com um ponteiro inteligente no lado direito do operador de comparação.

### <a name="construction"></a>Construção

|||
|-|-|
|[_com_ptr_t](../cpp/com-ptr-t-com-ptr-t.md)|Constrói um objeto **_com_ptr_t** .|

### <a name="low-level-operations"></a>Operações de nível baixo

|||
|-|-|
|[AddRef](../cpp/com-ptr-t-addref.md)|Chama a função membro `AddRef` de `IUnknown` no ponteiro de interface encapsulado.|
|[Anexar](../cpp/com-ptr-t-attach.md)|Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.|
|[CreateInstance](../cpp/com-ptr-t-createinstance.md)|Cria uma nova instância de um objeto, de acordo com um `CLSID` ou `ProgID`.|
|[Desanexar](../cpp/com-ptr-t-detach.md)|Extrai e retorna o ponteiro de interface encapsulado.|
|[GetActiveObject](../cpp/com-ptr-t-getactiveobject.md)|Anexa a uma instância existente de um objeto, de acordo com uma `CLSID` ou `ProgID`.|
|[GetInterfacePtr](../cpp/com-ptr-t-getinterfaceptr.md)|Retorna o ponteiro de interface encapsulado.|
|[QueryInterface](../cpp/com-ptr-t-queryinterface.md)|Chama a função membro `QueryInterface` de `IUnknown` no ponteiro de interface encapsulado.|
|[Versão](../cpp/com-ptr-t-release.md)|Chama a função membro `Release` de `IUnknown` no ponteiro de interface encapsulado.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](../cpp/com-ptr-t-operator-equal.md)|Atribui um novo valor a um objeto de **_com_ptr_t** existente.|
|[operadores = =,! =, \<, >, \<=, > =](../cpp/com-ptr-t-relational-operators.md)|Comparam o objeto de ponteiro inteligente com outro ponteiro inteligente, um ponteiro de interface bruto ou um NULL.|
|[Extratores](../cpp/com-ptr-t-extractors.md)|Extrai o ponteiro de interface COM encapsulado.|

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<comip. h >

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)
