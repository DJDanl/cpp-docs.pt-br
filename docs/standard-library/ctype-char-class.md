---
title: Classe ctype&lt;char&gt;
ms.date: 11/04/2016
f1_keywords:
- ctype<char>
- locale/std::ctype<char>
helpviewer_keywords:
- ctype<char> class
ms.assetid: ee30acb4-a743-405e-b3d4-13602092da84
ms.openlocfilehash: 08bf2c5c814eaed7b409295fcf50c66577f6a5d9
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688159"
---
# <a name="ctypeltchargt-class"></a>Classe ctype&lt;char&gt;

A classe é uma especialização explícita do modelo de classe `ctype\<CharType>` para digitar **Char**, descrevendo um objeto que pode servir como uma faceta de localidade para caracterizar várias propriedades de um caractere do tipo **Char**.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class ctype<char>
: public ctype_base
{
public:
    typedef char _Elem;
    typedef _Elem char_type;
    bool is(
    mask _Maskval,
    _Elem _Ch) const;

    const _Elem* is(
    const _Elem* first,
    const _Elem* last,
    mask* dest) const;

    const _Elem* scan_is(
    mask _Maskval,
    const _Elem* first,
    const _Elem* last) const;

    const _Elem* scan_not(
    mask _Maskval,
    const _Elem* first,
    const _Elem* last) const;

    _Elem tolower(
    _Elem _Ch) const;

    const _Elem* tolower(
    _Elem* first,
    const _Elem* last) const;

    _Elem toupper(
    _Elem _Ch) const;

    const _Elem* toupper(
    _Elem* first,
    const _Elem* last) const;

    _Elem widen(
    char _Byte) const;

    const _Elem* widen(
    const char* first,
    const char* last,
    _Elem* dest) const;

    const _Elem* _Widen_s(
    const char* first,
    const char* last,
    _Elem* dest,
    size_t dest_size) const;

    _Elem narrow(
    _Elem _Ch,
    char _Dflt = '\0') const;

    const _Elem* narrow(
    const _Elem* first,
    const _Elem* last,
    char _Dflt,
    char* dest) const;

    const _Elem* _Narrow_s(
    const _Elem* first,
    const _Elem* last,
    char _Dflt,
    char* dest,
    size_t dest_size) const;

    static locale::id& id;
    explicit ctype(
    const mask* _Table = 0,
    bool _Deletetable = false,
    size_t _Refs = 0);

protected:
    virtual ~ctype();
//other protected members
};
```

## <a name="remarks"></a>Comentários

A especialização explícita difere do modelo de classe de várias maneiras:

- Um objeto da classe CType < `char` > armazena um ponteiro para o primeiro elemento de uma tabela de máscara de CType, uma matriz de UCHAR_MAX + 1 elementos do tipo `ctype_base::mask`. Ele também armazena um objeto booliano que indica se a matriz deve ser excluída (usando `operator delete[]`) quando o objeto ctype\< **Elem**> é destruído.

- Seu único construtor público permite que você especifique `tab`, a tabela de máscara de CType e `del`, o objeto booliano que será verdadeiro se a matriz tiver que ser excluída quando o objeto de > de `char` de < CType for destruído, bem como o parâmetro de contagem de referência refs.

- A função membro protegido `table` retorna a tabela de máscara CType armazenada.

- O objeto membro estático `table_size` especifica o número mínimo de elementos em uma tabela de máscara de CType.

- A função de membro estático protegido `classic_table` (retorna a tabela de máscara de CType apropriada para a localidade "C".

- Não existem funções de membro virtuais protegidas [do_is](../standard-library/ctype-class.md#do_is), [do_scan_is](../standard-library/ctype-class.md#do_scan_is) ou [do_scan_not](../standard-library/ctype-class.md#do_scan_not). As funções de membro público correspondentes executam as operações equivalentes por conta própria.

As funções de membro [do_narrow](../standard-library/ctype-class.md#do_narrow) e [do_widen](../standard-library/ctype-class.md#do_widen) copiam os elementos inalterados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe facet](locale-class.md#facet_class)\
[Classe ctype_base](../standard-library/ctype-base-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
