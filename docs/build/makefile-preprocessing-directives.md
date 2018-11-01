---
title: Diretivas de pré-processamento de makefile
ms.date: 06/14/2018
f1_keywords:
- '!UNDEF'
- '!INCLUDE'
- '!IFNDEF'
- '!MESSAGE'
helpviewer_keywords:
- ERROR directive
- '!MESSAGE directive'
- IF directive
- '!UNDEF directive'
- IFDEF directive
- '!ELSEIF directive'
- '!IFDEF directive'
- '!IF directive'
- UNDEF directive
- '!CMDSWITCHES directive'
- ENDIF directive
- directives, makefile preprocessing
- INCLUDE directive
- IFNDEF directive
- preprocessing directives, makefiles
- '!IFNDEF directive'
- ELSEIFNDEF directive
- NMAKE program, expressions
- ELSEIF directive
- '!ERROR directive'
- '!ENDIF directive'
- MESSAGE directive
- '!INCLUDE directive'
- '!ELSEIFNDEF directive'
- CMDSWITCHES directive
- '!ELSEIFDEF directive'
- '!ELSE directive'
- NMAKE program, preprocessor directives
- makefiles, preprocessing directives
- ELSE directive
- ELSEIFDEF directive
ms.assetid: bcedeccb-d981-469d-b9e8-ab5d097fd8c2
ms.openlocfilehash: adc81e5c4ea3d0d4a80e7efad4eaab15a5048cd3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50593564"
---
# <a name="makefile-preprocessing-directives"></a>Diretivas de pré-processamento de makefile

Diretivas de pré-processamento não diferenciam maiusculas de minúsculas. O ponto de exclamação (!) inicial deve aparecer no início da linha. Zero ou mais espaços ou tabulações podem aparecer após o ponto de exclamação para recuo.

- **! CMDSWITCHES** {**+** &#124; **-**}*opção* ...

   Transforma cada *opção* listados ativada ou desativada. Espaços ou tabulações devem aparecer antes do + ou - operador; Nenhum podem aparecer entre o operador e o [opção letras](../build/nmake-options.md). Letras não diferenciam maiusculas de minúsculas e são especificadas sem uma barra (/). Para algumas opções no e outras pessoas de fora, use especificações separadas de **! CMDSWITCHES**.

   Somente /D, eu, /N e /S pode ser usada em um makefile. Tools. ini, todas as opções são permitidas, exceto /F, /HELP, /NOLOGO, / X, e /?. As alterações especificadas em um bloco de descrição não terão efeito até que o próximo bloco de descrição. Essa diretiva atualiza **MAKEFLAGS**; as alterações são herdadas durante a recursão se **MAKEFLAGS** for especificado.

- **! Erro***texto* 

   Exibe *texto* erro U1050 e, em seguida, para NMAKE, mesmo se /K, /, **. Ignorar**, **! CMDSWITCHES**, ou o modificador de comando de traço (-) é usado. Espaços ou tabulações antes *texto* são ignorados.

- **! MENSAGEM***texto* 

   Exibe *texto* para a saída padrão. Espaços ou tabulações antes *texto* são ignorados.

- **! INCLUIR** [ **\<** ] *filename* [ **>** ]

   Lê *filename* como um makefile, em seguida, continua com o makefile atual. Procura de NMAKE *filename* pela primeira vez no diretório atual ou especificado, em seguida, recursivamente pelos diretórios de qualquer pai makefiles, em seguida, se *filename* entre colchetes angulares (\<>), nos diretórios especificados pela **INCLUDE** macro, que é inicialmente definida como variável de ambiente INCLUDE. Útil para passar **. SUFIXOS** configurações, **. PRECIOSOS**e as regras de inferência de tipos para makefiles recursiva.

- **! IF** *constant_expression*

   Processa as instruções entre **! IF** e o próximo **! ELSE** ou **! ENDIF** se *constant_expression* é avaliada como um valor diferente de zero.

- **! IFDEF***macroname* 

   Processa as instruções entre **! IFDEF** e o próximo **! ELSE** ou **! ENDIF** se *macroname* está definido. Uma macro null é considerada ser definido.

- **! IFNDEF***macroname* 

   Processa as instruções entre **! IFNDEF** e o próximo **! ELSE** ou **! ENDIF** se *macroname* não está definido.

- **! ELSE** [**IF** *constant_expression* &#124; **IFDEF** *macroname* &#124; **IFNDEF**  *macroname*]

   Processa as instruções entre **! ELSE** e o próximo **! ENDIF** se a prévia **! IF**, **! IFDEF**, ou **! IFNDEF** instrução foi avaliada como zero. As palavras-chave opcional fornecem ainda mais o controle de pré-processamento.

- **! ELSEIF**

   Sinônimo de **! ELSE IF**.

- **! ELSEIFDEF**

   Sinônimo de **! ELSE IFDEF**.

- **! ELSEIFNDEF**

   Sinônimo de **! ELSE IFNDEF**.

- **! ENDIF**

   Marca o fim de um **! IF**, **! IFDEF**, ou **! IFNDEF** bloco. Qualquer texto após **! ENDIF** na mesma linha é ignorado.

- **! UNDEF***macroname* 

   Remoções de definições *macroname*.

## <a name="see-also"></a>Consulte também

- [Pré-processamento de makefile](../build/makefile-preprocessing.md)