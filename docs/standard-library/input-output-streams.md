---
title: Fluxos de Entrada/Saída | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- I/O [C++], stream
- stream I/O
ms.assetid: 21a97566-91a7-42d6-b2f8-a4c16bc926f1
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0b38306bbedce82a1060bc0aa375e471838c0474
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="inputoutput-streams"></a>Fluxos de Entrada/Saída

`basic_iostream`, que é definido no arquivo de cabeçalho \<istream>, é o modelo de classe para objetos que manipulam fluxos de E/S baseados em caracteres de entrada e de saída.

Há dois typedefs que definem especializações específicas do caractere de `basic_iostream` e que podem ajudar a facilitar a leitura do código: `iostream` (não deve ser confundido com o arquivo de cabeçalho \<iostream>) é um fluxo de E/S baseado em `basic_iostream<char>`; `wiostream` é um fluxo de E/S baseado em `basic_iostream<wchar_t>`.

Para obter mais informações, consulte [Classe basic_iostream](../standard-library/basic-iostream-class.md), [iostream](../standard-library/basic-iostream-class.md) e [wiostream](../standard-library/basic-iostream-class.md).

Derivado de `basic_iostream`, há o modelo de classe `basic_fstream`, que é usado para transmitir dados de caractere para arquivos e de arquivos.

Também há typedefs que fornecem especializações específicas do caractere de `basic_fstream`. Eles são `fstream`, que é um fluxo de E/S de arquivo baseado em `char`, e `wfstream`, que é um fluxo de E/S de arquivo baseado em `wchar_t`. Para obter mais informações, consulte [Classe basic_fstream](../standard-library/basic-fstream-class.md), [fstream](../standard-library/basic-fstream-class.md) e [wfstream](../standard-library/basic-fstream-class.md). Usar esses typedefs requer a inclusão do arquivo de cabeçalho \<fstream>.

> [!NOTE]
> Quando um objeto `basic_fstream` é usado para realizar E/S de arquivo, embora o buffer subjacente contenha posições designadas separadamente para leitura e gravação, as posições atuais de entrada e saída são vinculadas e, portanto, ler alguns dados move a posição de saída.

O modelo de classe `basic_stringstream` e sua especialização comum, `stringstream`, geralmente são usados para trabalhar com objetos de fluxo de E/S para inserir e extrair dados de caractere. Para obter mais informações, consulte a [Classe basic_stringstream](../standard-library/basic-stringstream-class.md).

## <a name="see-also"></a>Consulte também

[stringstream](../standard-library/basic-stringstream-class.md)<br/>
[Classe basic_stringstream](../standard-library/basic-stringstream-class.md)<br/>
[\<sstream>](../standard-library/sstream.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
