---
title: TypeName | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- typename_cpp
dev_langs:
- C++
helpviewer_keywords:
- typename template specifier
ms.assetid: 52e1d901-220d-4f0d-ab43-dae7e05fb491
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 77e3cc6f9691cf071a420ee2659c713f9e28036f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46061585"
---
# <a name="typename"></a>typename

Em definições de modelo fornece uma dica ao compilador que um identificador desconhecido é um tipo. Listas de parâmetros de modelo, é usado para especificar um parâmetro de tipo.

## <a name="syntax"></a>Sintaxe

```
typename identifier;
```

## <a name="remarks"></a>Comentários

Essa palavra-chave deve ser usado se um nome de uma definição de modelo é um nome qualificado que é dependente de um argumento de modelo; é opcional se o nome qualificado não é dependente. Para obter mais informações, consulte [modelos e resolução de nome](../cpp/templates-and-name-resolution.md).

**TypeName** pode ser usado por qualquer tipo em qualquer lugar em uma definição ou declaração de modelo. Não é permitido na lista de classes base, a menos que como um argumento de modelo para uma classe base de modelo.

```cpp
template <class T>
class C1 : typename T::InnerType // Error - typename not allowed.
{};
template <class T>
class C2 : A<typename T::InnerType>  // typename OK.
{};
```

O **typename** palavra-chave também pode ser usado no lugar de **classe** em listas de parâmetros de modelo. Por exemplo, as instruções a seguir são semanticamente equivalentes:

```cpp
template<class T1, class T2>...
template<typename T1, typename T2>...
```

## <a name="example"></a>Exemplo

```cpp
// typename.cpp
template<class T> class X
{
   typename T::Y m_y;   // treat Y as a type
};

int main()
{
}
```

## <a name="see-also"></a>Consulte também

[Modelos](../cpp/templates-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)