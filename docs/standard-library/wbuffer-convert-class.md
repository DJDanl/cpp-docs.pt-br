---
title: Classe wbuffer_convert
ms.date: 11/04/2016
f1_keywords:
- xlocmon/stdext::cvt::wbuffer_convert
helpviewer_keywords:
- wbuffer_convert class
ms.assetid: 4a56f9bf-4138-4612-b516-525fea401358
ms.openlocfilehash: ba8c98075741ae6cb8db0ecdfcb1e18cf4f4f89c
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561109"
---
# <a name="wbuffer_convert-class"></a>Classe wbuffer_convert

Descreve um buffer de fluxo que controla a transmissão de elementos de/para um buffer de fluxo de bytes.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Codecvt, class Elem = wchar_t, class Traits = std::char_traits<Elem>>
class wbuffer_convert
    : public std::basic_streambuf<Elem, Traits>
```

### <a name="parameters"></a>Parâmetros

*Codecvt*\
A faceta de [locale](../standard-library/locale-class.md) que representa o objeto de conversão.

*Elem*\
O tipo de elemento de caractere largo.

*Características*\
As características associadas a *Elem*.

## <a name="remarks"></a>Comentários

Esse modelo de classe descreve um buffer de fluxo que controla a transmissão de elementos do tipo `_Elem` , cujas características de caractere são descritas pela classe `Traits` , de e para um buffer de fluxo de bytes do tipo `std::streambuf` .

A conversão entre uma sequência de valores `Elem` e as sequências multibyte é executada por um objeto da classe `Codecvt<Elem, char, std::mbstate_t>`, que atende aos requisitos da faceta de conversão de código padrão `std::codecvt<Elem, char, std::mbstate_t>`.

Um objeto desse modelo de classe armazena:

- Um ponteiro para o buffer de fluxo de bytes subjacente

- Um ponteiro para o objeto de conversão alocado (que é liberado quando [wbuffer_convert](../standard-library/wbuffer-convert-class.md)
