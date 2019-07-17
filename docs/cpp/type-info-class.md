---
title: Classe type_info
ms.date: 11/04/2016
f1_keywords:
- type_info
helpviewer_keywords:
- class type_info
- type_info class
ms.assetid: 894ddda2-7de4-4da3-9404-d2c74e356c16
ms.openlocfilehash: b0cddd2c5cc09e77e8733ca88177c3b2223fc8ce
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68242082"
---
# <a name="typeinfo-class"></a>Classe type_info

O **type_info** classe descreve as informações de tipo geradas no programa pelo compilador. Os objetos dessa classe armazenam efetivamente um ponteiro para um nome do tipo. O **type_info** classe também armazena um valor codificado adequado para comparar dois tipos para igualdade ou ordem de agrupamento. As regras e a sequência de agrupamento de codificação para tipos não são especificados e podem ser diferentes entre os programas.

O `<typeinfo>` arquivo de cabeçalho deve ser incluído para usar o **type_info** classe. A interface para o **type_info** classe é:

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

Você não pode instanciar objetos do **type_info** classe diretamente, pois a classe tem apenas um construtor de cópia particular. A única maneira de construir (temporário) **type_info** objeto é usar o [typeid](../cpp/typeid-operator.md) operador. Como o operador de atribuição também é particular, você não pode copiar ou atribuir objetos da classe **type_info**.

`type_info::hash_code` define uma função de hash adequada para mapear valores do tipo **typeinfo** para uma distribuição de valores de índice.

Os operadores `==` e `!=` pode ser usado para comparar quanto à igualdade e desigualdade com outros **type_info** objetos, respectivamente.

Não há nenhum link entre a ordem de agrupamento de tipos e relações de herança. Use o `type_info::before` a função de membro para determinar a sequência de agrupamento de tipos. Não há nenhuma garantia de que `type_info::before` gerará o mesmo resultado em programas diferentes ou mesmo em execuções diferentes do mesmo programa. Dessa maneira `type_info::before` é semelhante ao endereço de `(&)` operador.

O `type_info::name` função de membro retorna um `const char*` para uma cadeia de caracteres terminada em nulo que representa o nome legível do tipo. A memória apontada é armazenada em cache e nunca deve ser desalocada diretamente.

O `type_info::raw_name` função de membro retorna um `const char*` para uma cadeia de caracteres terminada em nulo que representa o nome decorado do tipo de objeto. O nome é armazenado em sua forma decorada para economizar espaço. Consequentemente, essa função é mais rápida que `type_info::name` porque ele não precisa /Unique o nome. A cadeia de caracteres retornada pelo `type_info::raw_name` função é útil para operações de comparação, mas não é legível. Se você precisar de uma cadeia de caracteres legível por humanos, use o `type_info::name` function em vez disso.

Informações de tipo são geradas para classes polimórficas apenas se o [/GR (Habilitar informações de tipo em tempo de execução)](../build/reference/gr-enable-run-time-type-information.md) for especificada a opção de compilador.

## <a name="see-also"></a>Consulte também

[Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)