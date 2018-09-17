---
title: Especificando o nome do caminho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- names [C++], compiler output files
- cl.exe compiler, output files
- output files, specifying pathnames
ms.assetid: 7a6595ce-3383-44ae-957a-466bfa29c343
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d86052d6ca6e40926ed8d99990520044cef351d3
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45719310"
---
# <a name="specifying-the-pathname"></a>Especificando o nome de demarcador

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

[Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)
[opções do compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)