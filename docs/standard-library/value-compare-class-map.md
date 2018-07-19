---
title: Classe value_compare (&lt;map&gt;) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- std::value_compare
- std.value_compare
- map/std::value_compare
- value_compare
dev_langs:
- C++
helpviewer_keywords:
- std::value_compare
ms.assetid: ea97c1d0-04b2-4d42-8d96-23522c04cc41
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 46f8d00877aa4147e4b3e4ec2a6a23b70d8154c8
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38965842"
---
# <a name="valuecompare-class-ltmapgt"></a>Classe value_compare (&lt;map&gt;)

Fornece um objeto de função que pode comparar os elementos de um mapa ao comparar os valores de suas chaves para determinar sua ordem relativa no mapa.

## <a name="syntax"></a>Sintaxe

```cpp
class value_compare : public binary_function<value_type, value_type, bool>
{
public:
    bool operator()(const value_type& left, const value_type& right) const;
    value_compare(key_compare pred) : comp(pred);
protected:
    key_compare comp;
};
```

## <a name="remarks"></a>Comentários

Os critérios de comparação fornecidos pelo `value_compare` entre `value_types` de elementos inteiros contidos por um mapa é induzido de uma comparação entre as chaves dos respectivos elementos pela construção da classe auxiliar. O operador da função membro usa o objeto `comp` do tipo `key_compare` armazenados no objeto de função fornecido por `value_compare` para comparar os componentes da chave de classificação de dois elementos.

Para conjuntos e multiconjuntos, que são contêineres simples nos quais os valores de chave são idênticos aos valores dos elementos, `value_compare` é equivalente a `key_compare`; para mapas e multimapas eles não são, uma vez que o valor dos elementos do tipo `pair` não é idêntico ao valor da chave do elemento.

## <a name="example"></a>Exemplo

Consulte o exemplo de [value_comp](../standard-library/map-class.md#value_comp) para obter um exemplo de como declarar e usar `value_compare`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<map>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct binary_function](../standard-library/binary-function-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
