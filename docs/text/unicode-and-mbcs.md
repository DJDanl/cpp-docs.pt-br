---
title: Unicode e MBCS
ms.date: 11/04/2016
helpviewer_keywords:
- MBCS [C++], Unicode
- MFC [C++], character sets
- character sets [C++], multibyte
- run-time libraries [C++], language portability
- character sets [C++], Unicode
- Unicode [C++], MFC and C run-time functions
- multibyte characters [C++]
- runtime [C++], language portability
ms.assetid: 677baec6-71b4-4579-94df-64f18bc117c4
ms.openlocfilehash: 063c8b39ee0d29403b382b57a236f2a3e8759e3f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375748"
---
# <a name="unicode-and-mbcs"></a>Unicode e MBCS

A biblioteca Microsoft Foundation Classes (MFC), a biblioteca c run-time para Visual C++e o ambiente de desenvolvimento Visual C++ estão habilitados para ajudar sua programação internacional. Elas fornecem:

- Suporte para o padrão Unicode no Windows. Unicode é o padrão atual e deve ser usado sempre que possível.

   Unicode é uma codificação de caracteres de 16 bits, fornecendo codificações suficientes para todas as línguas. Todos os caracteres ASCII estão incluídos no Unicode como caracteres ampliados.

- Suporte para uma forma de conjunto de caracteres multibytes (MBCS) chamado conjunto de caracteres de byte duplo (DBCS) em todas as plataformas.

   Os caracteres DBCS são compostos por 1 ou 2 bytes. Algumas faixas de bytes são reservadas para uso como bytes de chumbo. Um byte de chumbo especifica que ele e o byte de trilha a seguir compreendem um único caractere de 2 bytes de largura. Você deve manter o controle de quais bytes são bytes de chumbo. Em um conjunto de caracteres multibyte, os bytes iniciais ficam dentro de um determinado intervalo, assim como os bytes finais. Quando essas faixas se sobrepõem, pode ser necessário avaliar o contexto para determinar se um determinado byte está funcionando como um byte de chumbo ou um byte de trilha.

- Suporte a ferramentas que simplificam a programação MBCS de aplicações escritas para mercados internacionais.

   Quando executado em uma versão habilitada para MBCS do sistema operacional Windows, o sistema de desenvolvimento Visual C++ — incluindo o editor de código-fonte integrado, o depurador e as ferramentas de linha de comando — é completamente habilitado para MBCS. Para obter mais informações, consulte [o suporte ao MBCS no Visual C++](../text/mbcs-support-in-visual-cpp.md).

> [!NOTE]
> Nesta documentação, o MBCS é usado para descrever todo o suporte não-Unicode para caracteres multibytes. No Visual C++, MBCS sempre significa DBCS. Os conjuntos de caracteres maiores que 2 bytes não são suportados.

Por definição, o conjunto de caracteres ASCII é um subconjunto de todos os conjuntos de caracteres multibytes. Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII. Por exemplo, nas seqüências de caracteres ASCII e MBCS, o caractere NULL de 1 byte ('\0') tem valor 0x00 e indica o caractere nulo terminante.

## <a name="see-also"></a>Confira também

[Texto e Cordas](../text/text-and-strings-in-visual-cpp.md)<br/>
[Habilitação internacional](../text/international-enabling.md)
