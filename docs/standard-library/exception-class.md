---
title: Classe exception
ms.date: 11/04/2016
f1_keywords:
- exception/std::exception
helpviewer_keywords:
- exception class
ms.assetid: 4f181f67-5888-4b50-89a6-745091ffb2fe
ms.openlocfilehash: 5bef8190889ae00298760ea395fb524f557c2be2
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446821"
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

O parâmetro **int** permite que você especifique que nenhuma memória deve ser alocada. O valor de **int** é ignorado.

> [!NOTE]
> Os construtores `exception(const char* const &message)` e `exception(const char* const &message, int)` são extensões da Microsoft à biblioteca padrão C++.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter exemplos de uso das classes de exceção padrão que herdam da classe `exception`, consulte uma das classes definidas em [\<stdexcept>](../standard-library/stdexcept.md).
