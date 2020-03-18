---
title: 'Bibliotecas seguras: Biblioteca Padrão C++'
ms.date: 11/04/2016
helpviewer_keywords:
- Safe Libraries
- Safe Libraries, C++ Standard Library
- Safe C++ Standard Library
ms.assetid: 3993340f-1f29-4d81-b3f5-52a52bc8e148
ms.openlocfilehash: e352489ca12b5815aab5517defc72571abe177fb
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446088"
---
# <a name="safe-libraries-c-standard-library"></a>Bibliotecas seguras: Biblioteca Padrão C++

Foram feitas várias melhorias nas bibliotecas que acompanham a Microsoft C++, incluindo a C++ biblioteca padrão, para torná-las mais seguras.

Vários métodos na Biblioteca Padrão C++ foram identificados como potencialmente não seguros porque podem causar um estouro de buffer ou outros defeitos de código. Não é recomendado usar esses métodos e métodos mais novos e mais seguros foram criados para substituí-los. Todos esses novos métodos terminam em `_s`.

Também foram feitas várias melhorias para tornar os iteradores e algoritmos mais seguros. Para obter mais informações, consulte [Verificar iteradores](../standard-library/checked-iterators.md), [Suporte a iterador de depuração](../standard-library/debug-iterator-support.md) e [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

## <a name="remarks"></a>Comentários

A tabela a seguir lista os métodos de Biblioteca Padrão C++ que são potencialmente não seguros, bem como seus equivalentes mais seguros:

|Método potencialmente não seguro|Equivalente mais seguro|
|-------------------------------|----------------------|
|[copy](../standard-library/basic-string-class.md#copy)|[basic_string::_Copy_s](../standard-library/basic-string-class.md#copy_s)|
|[copy](../standard-library/char-traits-struct.md#copy)|[char_traits::_Copy_s](../standard-library/char-traits-struct.md#copy_s)|

Se você chamar qualquer um dos métodos potencialmente não seguros acima ou se usar iteradores incorretamente, o compilador gerará o [Aviso do Compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Para obter informações sobre como desabilitar esses avisos, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

## <a name="in-this-section"></a>Nesta seção

[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)

[_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md)

[Iteradores verificados](../standard-library/checked-iterators.md)

[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)
