---
title: Convenções de iostreams | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- iostream header
- C++ Standard Library, iostreams
ms.assetid: 9fe5ded0-37a1-48d1-9671-c81ffc4760ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 37ba52981f317ff9929a820c42d35cde0506256f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="iostreams-conventions"></a>Convenções iostreams

Os cabeçalhos de iostreams dão suporte a conversões entre texto e formulários codificados, bem como entrada e saída para arquivos externos:

|||
|-|-|
|[\<fstream>](../standard-library/fstream.md)|[\<iomanip>](../standard-library/iomanip.md)|
|[\<ios>](../standard-library/ios.md)|[\<iosfwd>](../standard-library/iosfwd.md)|
|[\<iostream>](../standard-library/iostream.md)|[\<istream>](../standard-library/istream.md)|
|[\<ostream>](../standard-library/ostream.md)|[\<sstream>](../standard-library/sstream.md)|
|[\<streambuf>](../standard-library/streambuf.md)|[\<strstream>](../standard-library/strstream.md)|

O uso mais simples de iostreams requer apenas que você inclua o cabeçalho [\<iostream>](../standard-library/iostream.md). Assim, é possível extrair valores de [cin](../standard-library/iostream.md#cin) ou [wcin](../standard-library/iostream.md#wcin) para ler a entrada padrão. As regras para fazer isso são definidas na descrição da [Classe basic_istream](../standard-library/basic-istream-class.md). Também é possível inserir valores em [cout](../standard-library/iostream.md#cout) ou [wcout](../standard-library/iostream.md#wcout) para gravar a saída padrão. As regras para fazer isso são definidas na descrição da [Classe basic_ostream](../standard-library/basic-ostream-class.md). O controle de formato comum a operadores de extração e inserção é gerenciado pela [Classe basic_ios](../standard-library/basic-ios-class.md). Manipular essas informações de formato na forma de extração e inserção de objetos é o princípio de vários manipuladores.

É possível executar as mesmas operações de iostreams em arquivos que você abre por nome, usando as classes declaradas em [\<fstream>](../standard-library/fstream.md). Para converter entre iostreams e objetos da [Classe basic_string](../standard-library/basic-string-class.md), use as classes declaradas em [ \<sstream>](../standard-library/sstream.md). Para fazer o mesmo com cadeias de caracteres C, use as classes declaradas em [\<strstream>](../standard-library/strstream.md).

Os cabeçalhos restantes fornecem serviços de suporte, normalmente de interesse direto apenas aos usuários mais avançados das classes iostreams.

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
