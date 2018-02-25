---
title: "comentário (C/C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.comment
- comment_CPP
dev_langs:
- C++
helpviewer_keywords:
- annotations [C++]
- comments [C++], compiled files
- pragmas, comment
- comment pragma
ms.assetid: 20f099ff-6303-49b3-9c03-a94b6aa69b85
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d1062923f50470a2238af21676c4137fac241905
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="comment-cc"></a>comment (C/C++)
Coloca um registro de comentário em um arquivo de objeto ou executável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma comment( comment-type [,"commentstring"] )  
```  
  
## <a name="remarks"></a>Comentários  
 O *tipo de comentário* é um dos identificadores predefinidos, descritos abaixo, que especifica o tipo de registro de comentário. O `commentstring` opcional é um literal de cadeia de caracteres que fornece informações adicionais sobre alguns tipos de comentário. Porque `commentstring` é uma cadeia de caracteres literal, ele obedece a todas as regras para literais de cadeia de caracteres em relação a caracteres de escape, as aspas internas (**"**) e concatenação.  
  
 **compiler**  
 Coloque o nome e o número da versão do compilador no arquivo de objeto. Esse registro de comentário é ignorado pelo vinculador. Se você fornecer um parâmetro `commentstring` para esse tipo de registro, o compilador gerará um aviso.  
  
 **exestr**  
 Coloca `commentstring` no arquivo de objeto. No tempo de vinculação, essa cadeia de caracteres é colocada no arquivo executável. A cadeia de caracteres não será carregada na memória quando o arquivo executável for carregado; no entanto, pode ser encontrada com um programa que localiza cadeias de caracteres imprimíveis em arquivos. Um uso para esse tipo de registro de comentário é inserir um número de versão ou informações semelhantes em um arquivo executável.  
  
 `exestr` é preterido e será removido em uma versão futura; o vinculador não processa o registro de comentário.  
  
 **lib**  
 Coloca um registro de pesquisa de biblioteca no arquivo de objeto. Esse tipo de comentário deve ser acompanhado por um parâmetro `commentstring` que contém o nome (e possivelmente o caminho) da biblioteca que você deseja que o vinculador pesquise. O nome da biblioteca segue os registros de pesquisa de biblioteca padrão no arquivo de objeto; o vinculador procura essa biblioteca como se tivesse nomeá-la na linha de comando desde que a biblioteca não for especificada com [/nodefaultlib](../build/reference/nodefaultlib-ignore-libraries.md). Você pode colocar vários registros de pesquisa de biblioteca no mesmo arquivo de origem; cada registro aparece no arquivo de objeto na mesma ordem em que é encontrado no arquivo de origem.  
  
 Se a ordem de biblioteca padrão e uma biblioteca adicional for importante, compilando com o [/Zl](../build/reference/zl-omit-default-library-name.md) opção impedirá que o nome da biblioteca padrão que está sendo colocado no módulo do objeto. Um segundo pragma de comentário em pode ser usado para inserir o nome da biblioteca padrão após a biblioteca adicionada. As bibliotecas listadas com esses pragmas aparecerão no módulo de objeto na mesma ordem que são localizadas no código-fonte.  
  
 **linker**  
 Coloca um [opção de vinculador](../build/reference/linker-options.md) no arquivo de objeto. Você pode usar esse tipo de comentário para especificar uma opção de vinculador em vez de passá-la para a linha de comando ou de especificá-la na ambiente de desenvolvimento. Por exemplo, você pode especificar a opção /include para forçar a inclusão de um símbolo:  
  
```  
#pragma comment(linker, "/include:__mySymbol")  
```  
  
 Somente os seguintes (*tipo de comentário*) opções de vinculador estão disponíveis a serem passados para o identificador do vinculador:  
  
-   [/DEFAULTLIB](../build/reference/defaultlib-specify-default-library.md)  
  
-   [/EXPORT](../build/reference/export-exports-a-function.md)  
  
-   [/INCLUDE](../build/reference/include-force-symbol-references.md)  
  
-   [/MANIFESTDEPENDENCY](../build/reference/manifestdependency-specify-manifest-dependencies.md)  
  
-   [/MERGE](../build/reference/merge-combine-sections.md)  
  
-   [/SECTION](../build/reference/section-specify-section-attributes.md)  
  
 **user**  
 Coloca um comentário geral no arquivo de objeto. O parâmetro `commentstring` contém o texto do comentário. Esse registro de comentário é ignorado pelo vinculador.  
  
 O seguinte pragma faz com que o vinculador procure pela biblioteca EMAPI.LIB na vinculação. O vinculador procura primeiro no diretório de trabalho atual e depois no caminho especificado na variável de ambiente LIB.  
  
```  
#pragma comment( lib, "emapi" )  
```  
  
 O seguinte pragma faz com que o compilador coloque o nome e o número da versão do compilador no arquivo de objeto:  
  
```  
#pragma comment( compiler )  
```  
  
> [!NOTE]
>  Para os comentários que possuem um parâmetro `commentstring`, você pode usar uma macro em qualquer local onde você usaria um literal de cadeia de caracteres, desde que a macro expanda-se para um literal de cadeia de caracteres. Você também pode concatenar qualquer combinação de literais de cadeia de caracteres e macros que se expandem para literais de cadeias de caracteres. Por exemplo, a seguinte instrução é aceitável:  
  
```  
#pragma comment( user, "Compiled on " __DATE__ " at " __TIME__ )   
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)