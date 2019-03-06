---
title: Especificando o nome de caminho
ms.date: 11/04/2016
helpviewer_keywords:
- names [C++], compiler output files
- cl.exe compiler, output files
- output files, specifying pathnames
ms.assetid: 7a6595ce-3383-44ae-957a-466bfa29c343
ms.openlocfilehash: 07afcd102b2b1839b3925ad1e6905507ea316361
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423320"
---
# <a name="specifying-the-pathname"></a>Especificando o nome de caminho

Cada opção de arquivo de saída aceita uma *pathname* argumento que pode especificar um local e um nome para o arquivo de saída. O argumento pode incluir um nome da unidade, o diretório e o nome do arquivo. Nenhum espaço é permitido entre a opção e argumento.

Se *pathname* inclui um nome de arquivo sem uma extensão, o compilador fornece a saída uma extensão padrão. Se *pathname* inclui um diretório, mas nenhum nome de arquivo, o compilador cria um arquivo com um nome padrão no diretório especificado. O nome padrão é baseado no nome base do arquivo de origem e uma extensão padrão com base no tipo de arquivo de saída. Se você deixar de fora *pathname* totalmente, o compilador cria um arquivo com um nome padrão em um diretório padrão.

Como alternativa, o *pathname* argumento pode ser um nome de dispositivo (AUX, CON, PRN ou NUL) em vez de um nome de arquivo. Não use um espaço entre a opção e o nome do dispositivo ou dois-pontos como parte do nome do dispositivo.

|Nome do dispositivo|Representa|
|-----------------|----------------|
|AUX|Dispositivo auxiliar|
|CON|Console|
|PRN|Impressora|
|NUL|Dispositivo nulo (nenhum arquivo criado)|

## <a name="example"></a>Exemplo

A linha de comando a seguir envia um arquivo de mapa para a impressora:

```
CL /FmPRN HELLO.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
