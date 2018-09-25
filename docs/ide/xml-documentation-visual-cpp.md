---
title: Documentação XML (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- XML documentation
- XML, documentation comments in source code
- comments, C++ source code files
- /// delimiter for C++ documentation
ms.assetid: a1aec1c5-b2d1-4c74-83ae-1dbbbb76b506
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: de3df01d9e9bf5d63b4445956e4656687d0f4f2c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412282"
---
# <a name="xml-documentation-visual-c"></a>Documentação XML (Visual C++)

No Visual C++, você pode adicionar comentários ao código-fonte que será processado em um arquivo .xml. Em seguida, esse arquivo pode ser a entrada para um processo que cria a documentação para as classes no código.

Em um arquivo de código do Visual C++, os comentários da documentação XML precisam estar localizados diretamente antes de uma definição de método ou de tipo. Os comentários podem ser usados para popular a dica de dados QuickInfo do IntelliSense nos seguintes cenários:

1. quando o código é compilado como um componente do Tempo de Execução do Windows com um arquivo .winmd complementar

1. quando o código-fonte é incluído no projeto atual

1. em uma biblioteca cujas declarações de tipo e implementações estão localizadas no mesmo arquivo de cabeçalho

> [!NOTE]
>  Na versão atual, os comentários sobre código não são processados em modelos ou em qualquer item que contenha um tipo de modelo (por exemplo, uma função que usa um parâmetro como modelo). A adição desses comentários resultará em um comportamento indefinido.

Para obter detalhes sobre como criar um arquivo .xml com comentários da documentação, confira os tópicos a seguir.

|Para obter informações sobre|Consulte|
|---------------------------|---------|
|As opções do compilador a serem usadas|[/doc](../build/reference/doc-process-documentation-comments-c-cpp.md)|
|As marcas que podem ser usadas para fornecer as funcionalidade geralmente usadas na documentação|[Marcas recomendadas para comentários de documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md)|
|As cadeias de identificação produzidas pelo compilador para identificar os constructos no código|[Processando o arquivo .xml](../ide/dot-xml-file-processing.md)|
|Como delimitar as marcas da documentação|[Delimitadores de marcas de documentação para o Visual C++](../ide/delimiters-for-visual-cpp-documentation-tags.md)|
|Gerando um arquivo .xml com base em um ou mais arquivos .xdc.|[Referência XDCMake](../ide/xdcmake-reference.md)|
|Links para informações sobre XML relacionado às áreas de recursos do Visual Studio|[XML no Visual Studio](/visualstudio/xml-tools/xml-tools-in-visual-studio)|

Caso precise colocar caracteres especiais XML no texto de um comentário da documentação, use entidades XML ou uma seção CDATA.

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)