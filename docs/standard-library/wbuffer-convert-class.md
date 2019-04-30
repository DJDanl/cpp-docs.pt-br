---
title: Classe wbuffer_convert
ms.date: 11/04/2016
f1_keywords:
- xlocmon/stdext::cvt::wbuffer_convert
helpviewer_keywords:
- wbuffer_convert class
ms.assetid: 4a56f9bf-4138-4612-b516-525fea401358
ms.openlocfilehash: d19abf74bd9f794bc39ce04e5ed22e360cde75b4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410870"
---
# <a name="wbufferconvert-class"></a>Classe wbuffer_convert

Descreve um buffer de fluxo que controla a transmissão de elementos de/para um buffer de fluxo de bytes.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Codecvt, class Elem = wchar_t, class Traits = std::char_traits<Elem>>
class wbuffer_convert
    : public std::basic_streambuf<Elem, Traits>
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Codecvt*|A faceta de [locale](../standard-library/locale-class.md) que representa o objeto de conversão.|
|*Elem*|O tipo de elemento de caractere largo.|
|*Características*|As características associadas a *Elem*.|

## <a name="remarks"></a>Comentários

Essa classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `_Elem`, cujas características dos caracteres são descritas pela classe `Traits`, de/para um buffer de fluxo de bytes do tipo `std::streambuf`.

A conversão entre uma sequência de valores `Elem` e as sequências multibyte é executada por um objeto da classe `Codecvt<Elem, char, std::mbstate_t>`, que atende aos requisitos da faceta de conversão de código padrão `std::codecvt<Elem, char, std::mbstate_t>`.

Um objeto desta classe de modelo armazena:

- Um ponteiro para o buffer de fluxo de bytes subjacente

- Um ponteiro para o objeto de conversão alocado (que é liberado quando [wbuffer_convert](../standard-library/wbuffer-convert-class.md)
