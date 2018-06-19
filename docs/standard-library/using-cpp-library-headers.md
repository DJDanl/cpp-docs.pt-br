---
title: Usando Cabeçalhos da Biblioteca C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- headers, naming in C++ include directive
- standard header in C++
- headers
- INCLUDE directive
- headers, C++ Standard Library
- library headers
- C++ Standard Library, headers
ms.assetid: a36e889e-1af2-4cd9-a211-bfc7a3fd8e85
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 30d31f30971184356374b3991fedda474ca27465
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33857292"
---
# <a name="using-c-library-headers"></a>Usando cabeçalhos da Biblioteca C++

Você inclui os conteúdos de um cabeçalho padrão ao nomeá-lo em uma diretiva de inclusão.

```cpp
#include <iostream>// include I/O facilities
```

É possível incluir os cabeçalhos padrão em qualquer ordem, um cabeçalho padrão mais de uma vez ou dois ou mais cabeçalhos padrão que definem a mesma macro ou o mesmo tipo. Não inclua um cabeçalho padrão dentro de uma declaração. Não defina macros que têm os mesmos nomes das palavras-chave antes de incluir um cabeçalho padrão.

Um cabeçalho da biblioteca C++ inclui quaisquer outros cabeçalhos da biblioteca C++ necessários para definir tipos necessários. (Sempre inclui explicitamente qualquer cabeçalho da biblioteca C++ necessário em uma unidade de translação, entretanto, deixa que você adivinhe errado suas dependências reais.) Um cabeçalho C padrão nunca inclui outro cabeçalho padrão. Um cabeçalho padrão declara ou define apenas as entidades descritas para ele neste documento.

Cada função na biblioteca é declarada em um cabeçalho padrão. Ao contrário do C Padrão, o cabeçalho padrão nunca fornece uma macro de mascaramento com o mesmo nome que a função que mascara a declaração da função e alcança o mesmo efeito. Para obter mais informações sobre o macros de mascaramento, consulte [Convenções da Biblioteca C++](../standard-library/cpp-library-conventions.md).

Todos os nomes que não sejam `operator delete` e `operator new` nos cabeçalhos da biblioteca C++ são definidos no namespace `std` ou em um namespace aninhado no namespace `std`. Você se refere ao nome `cin`, por exemplo, como `std::cin`. No entanto, observe que os nomes de macro não estão sujeitos à qualificação de namespace, assim, você sempre escreverá `__STD_COMPLEX` sem um qualificador de namespace.

Em alguns ambientes de translação, a inclusão de um cabeçalho de biblioteca C++ pode elevar nomes externos declarados no namespace `std` para o namespace global, com declarações `using` individuais para cada um dos nomes. Caso contrário, o cabeçalho *não* introduzirá quaisquer nomes de biblioteca no namespace atual.

O Padrão C++ requer que os cabeçalhos Padrão C declarem todos os nomes externos no namespace `std` e, em seguida, eleve-os ao namespace global com declarações `using` individuais para cada um dos nomes. Porém, em alguns ambientes de translação, os cabeçalhos Padrão C não incluem declarações de namespace, declarando todos os nomes diretamente no namespace global. Assim, a maneira mais portátil de lidar com os namespaces é seguir duas regras:

- De forma segura, declarar no namespace `std` um nome externo tradicionalmente declarado em \<stdlib.h>, por exemplo, incluindo o cabeçalho \<cstdlib>. Saiba que o nome também pode ser declarado no namespace global.

- De forma segura, declarar no namespace global um nome externo declarado em \<stdlib.h>, incluindo diretamente o cabeçalho \<stdlib.h>. Saiba que o nome também pode ser declarado no namespace `std`.

Portanto, se você deseja chamar `std::abort` para causar um encerramento anormal, inclua \<cstdlib>. Se você deseja chamar `abort`, inclua \<stdlib.h>.

Como alternativa, você pode escrever a declaração:

```cpp
using namespace std;
```

o que leva a todos os nomes de biblioteca para o namespace atual. Se você escrever essa declaração imediatamente após incluir todas as diretivas, elevará os nomes para o namespace global. Posteriormente, você pode ignorar as considerações de namespace no restante da unidade de translação. Você também pode evitar a maioria das diferenças entre ambientes de translação diferentes.

Salvo indicação em contrário, não é possível definir nomes no namespace `std` ou em um namespace aninhado no namespace `std`, dentro do seu programa.

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
