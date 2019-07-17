---
title: Classe exception
ms.date: 11/04/2016
f1_keywords:
- exception
helpviewer_keywords:
- exception class
ms.assetid: 4f181f67-5888-4b50-89a6-745091ffb2fe
ms.openlocfilehash: 90906469e923d29dd886930bd36944e4292bd9cd
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246077"
---
# <a name="exception-class"></a>Classe exception

A classe atua como a classe base de todas as exceções lançadas por determinadas expressões e pela biblioteca padrão C++.

## <a name="syntax"></a>Sintaxe

```cpp
class exception {
   public:
   exception();
   exception(const char* const &message);
   exception(const char* const &message, int);
   exception(const exception &right);
   exception& operator=(const exception &right);
   virtual ~exception();
   virtual const char *what() const;
};
```

## <a name="remarks"></a>Comentários

Especificamente, essa classe base é a raiz das classes de exceção padrão definidas em [\<stdexcept>](../standard-library/stdexcept.md). O valor da cadeia de caracteres C retornado por `what` é deixado como não especificado pelo construtor padrão, mas pode ser definido por construtores para determinadas classes derivadas como uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.

O **int** parâmetro permite que você especifique que a memória não deve ser alocada. O valor de **int** será ignorado.

> [!NOTE]
> Os construtores `exception(const char* const &message)` e `exception(const char* const &message, int)` são extensões da Microsoft à biblioteca padrão C++.

## <a name="example"></a>Exemplo

Para obter exemplos de uso das classes de exceção padrão que herdam da classe `exception`, consulte uma das classes definidas em [\<stdexcept>](../standard-library/stdexcept.md).
