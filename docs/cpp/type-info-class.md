---
title: Classe type_info
ms.date: 11/04/2016
f1_keywords:
- type_info
helpviewer_keywords:
- class type_info
- type_info class
ms.assetid: 894ddda2-7de4-4da3-9404-d2c74e356c16
ms.openlocfilehash: 7a016fe8fee4e5765e6172184bfa9c90eecbc687
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160665"
---
# <a name="type_info-class"></a>Classe type_info

A classe **type_info** descreve informações de tipo geradas dentro do programa pelo compilador. Os objetos dessa classe armazenam efetivamente um ponteiro para um nome do tipo. A classe **type_info** também armazena um valor codificado adequado para comparar dois tipos para a ordem de igualdade ou de agrupamento. As regras e a sequência de agrupamento de codificação para tipos não são especificados e podem ser diferentes entre os programas.

O arquivo de cabeçalho de `<typeinfo>` deve ser incluído para usar a classe **type_info** . A interface para a classe **type_info** é:

```cpp
class type_info {
public:
    type_info(const type_info& rhs) = delete; // cannot be copied
    virtual ~type_info();
    size_t hash_code() const;
    _CRTIMP_PURE bool operator==(const type_info& rhs) const;
    type_info& operator=(const type_info& rhs) = delete; // cannot be copied
    _CRTIMP_PURE bool operator!=(const type_info& rhs) const;
    _CRTIMP_PURE int before(const type_info& rhs) const;
    size_t hash_code() const noexcept;
    _CRTIMP_PURE const char* name() const;
    _CRTIMP_PURE const char* raw_name() const;
};
```

Você não pode instanciar objetos da classe **type_info** diretamente, porque a classe tem apenas um construtor de cópia privada. A única maneira de construir um objeto de **type_info** (temporário) é usar o operador [typeid](../cpp/typeid-operator.md) . Como o operador de atribuição também é privado, não é possível copiar ou atribuir objetos da classe **type_info**.

`type_info::hash_code` define uma função de hash adequada para mapear valores do tipo **TypeInfo** para uma distribuição de valores de índice.

Os operadores `==` e `!=` podem ser usados para comparar a igualdade e desigualdade com outros objetos de **type_info** , respectivamente.

Não há nenhum link entre a ordem de agrupamento de tipos e relações de herança. Use a função de membro `type_info::before` para determinar a sequência de agrupamento dos tipos. Não há nenhuma garantia de que `type_info::before` produzirá o mesmo resultado em programas diferentes ou até mesmo em diferentes execuções do mesmo programa. Dessa maneira, `type_info::before` é semelhante ao operador de endereço de `(&)`.

A função membro `type_info::name` retorna uma `const char*` a uma cadeia de caracteres terminada em nulo que representa o nome legível do tipo. A memória apontada é armazenada em cache e nunca deve ser desalocada diretamente.

A função membro `type_info::raw_name` retorna um `const char*` a uma cadeia de caracteres terminada em nulo que representa o nome decorado do tipo de objeto. O nome é armazenado em sua forma decorada para economizar espaço. Consequentemente, essa função é mais rápida do que `type_info::name` porque não precisa desdecorar o nome. A cadeia de caracteres retornada pela função `type_info::raw_name` é útil em operações de comparação, mas não é legível. Se você precisar de uma cadeia de caracteres legível, use a função `type_info::name` em vez disso.

As informações de tipo serão geradas para classes polimórficas somente se a opção de compilador [/gr (habilitar informações de tipo de tempo de execução)](../build/reference/gr-enable-run-time-type-information.md) for especificada.

## <a name="see-also"></a>Confira também

[Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)
