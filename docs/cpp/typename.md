---
title: typename
ms.date: 11/04/2016
f1_keywords:
- typename_cpp
helpviewer_keywords:
- typename template specifier
ms.assetid: 52e1d901-220d-4f0d-ab43-dae7e05fb491
ms.openlocfilehash: 62e8a2026babbfea3cd1583def05a03b4bc4a229
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223506"
---
# <a name="typename"></a>typename

Em definições de modelo, fornece uma dica ao compilador de que um identificador desconhecido é um tipo. Em listas de parâmetros de modelo, é usado para especificar um parâmetro de tipo.

## <a name="syntax"></a>Sintaxe

```
typename identifier;
```

## <a name="remarks"></a>Comentários

Essa palavra-chave deve ser usada se um nome em uma definição de modelo for um nome qualificado que dependa de um argumento de modelo; é opcional se o nome qualificado não for dependente. Para obter mais informações, consulte [modelos e resolução de nomes](../cpp/templates-and-name-resolution.md).

**`typename`** pode ser usado por qualquer tipo em qualquer lugar em uma definição ou declaração de modelo. Não é permitido na lista de classes base, a menos que como um argumento de modelo para uma classe base de modelo.

```cpp
template <class T>
class C1 : typename T::InnerType // Error - typename not allowed.
{};
template <class T>
class C2 : A<typename T::InnerType>  // typename OK.
{};
```

A **`typename`** palavra-chave também pode ser usada no lugar de **`class`** listas de parâmetros de modelo. Por exemplo, as instruções a seguir são semanticamente equivalentes:

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

## <a name="see-also"></a>Confira também

[Modelo](../cpp/templates-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
