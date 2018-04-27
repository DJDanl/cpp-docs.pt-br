---
title: Classe collate_byname | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- locale/std::collate_byname
dev_langs:
- C++
helpviewer_keywords:
- collate_byname class
ms.assetid: 3dc380df-867c-4763-b60e-ba62a8e63ca7
caps.latest.revision: 24
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 41b5be0df93fcc5fcb1c1c18eddb0b051f1da8a8
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="collatebyname-class"></a>Classe collate_byname

Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a convenções de classificação de cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class collate_byname : public collate<CharType> {
public:
    explicit collate_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit collate_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~collate_byname();

};
```

### <a name="parameters"></a>Parâmetros

`_Locname` Uma localidade nomeada.

`_Refs` Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

Uma classe de modelo que descreve um objeto que pode funcionar como uma [faceta de localidade](../standard-library/locale-class.md#facet_class) do tipo [collate](../standard-library/collate-class.md#collate)\<CharType>. Seu comportamento é determinado pela localidade [nomeada](../standard-library/locale-class.md#name) `_Locname`. Cada construtor inicializa seu objeto base com [collate](../standard-library/collate-class.md#collate)\<CharType>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
