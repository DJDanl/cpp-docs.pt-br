---
title: '&lt;exceção> (comentários de documentação do C++)'
ms.date: 11/04/2016
helpviewer_keywords:
- <exception> C++ XML tag
- exception C++ XML tag
ms.assetid: 24451e79-9b89-4b77-98fb-702c6516b818
ms.openlocfilehash: 7e4b2276ecf5f4f4c4c05b389eb98a0f572f8027
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90042102"
---
# <a name="ltexceptiongt-tag"></a>&lt;marca de exceção &gt;

A \<exception> marca permite especificar quais exceções podem ser geradas. Essa marcação é aplicada a uma definição de método.

## <a name="syntax"></a>Sintaxe

```
<exception cref="member">description</exception>
```

#### <a name="parameters"></a>Parâmetros

*associado*<br/>
Uma referência a uma exceção que está disponível no ambiente de compilação atual. Usando as regras da pesquisa de nome, o compilador verifica se a exceção fornecida existe e converte `member` no nome de elemento canônico no XML de saída.  O compilador emite um aviso se não encontra `member`.

Coloque o nome entre aspas simples ou duplas.

Para obter informações sobre como criar uma referência cref para um tipo genérico, consulte [\<see>](see-visual-cpp.md) .

*descrição*<br/>
Uma descrição.

## <a name="remarks"></a>Comentários

Compile com [/doc](doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

O compilador MSVC tentará resolver referências CREF em um passo entre os comentários da documentação.  Portanto, se você estiver usando as regras de pesquisa do C++ e um símbolo não for encontrado pelo compilador, a referência será marcada como não resolvida. Consulte [\<seealso>](seealso-visual-cpp.md) para obter mais informações.

## <a name="example"></a>Exemplo

```cpp
// xml_exception_tag.cpp
// compile with: /clr /doc /LD
// post-build command: xdcmake xml_exception_tag.dll
using namespace System;

/// Text for class EClass.
public ref class EClass : public Exception {
   // class definition ...
};

/// <exception cref="System.Exception">Thrown when... .</exception>
public ref class TestClass {
   void Test() {
      try {
      }
      catch(EClass^) {
      }
   }
};
```

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
